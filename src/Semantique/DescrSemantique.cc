// =========================================================================
// DescrSemantique.cc
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#include "DescrSemantique.h"

#include "LanguesSemantique.h"

#include "FonctionsUtilisateur.h"

#include "Listes.h"

#include "Types.h"



#if defined SYNTHESE_PILUM
   #include "SynthesePilum.h"
   #include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
// DescrSemantique
// -------------------------------------------------------------------------

DescrSemantique :: DescrSemantique (
   VariableLogiqueTypePTR leTypeLogique )
   { fTypeLogique = leTypeLogique; }

DescrSemantique :: ~ DescrSemantique ()
   {}


VariableLogiqueTypePTR
DescrSemantique :: TypeLogique ()
   { return fTypeLogique; }

bool
DescrSemantique :: ProduitUneValeur ()
   {
   return
      ! fTypeLogique -> ValeurDeLiaison () -> DecritUneAbsenceDeValeur ();
   }

void
DescrSemantique :: Ecrire (int lIndentation)
   { Indenter (lIndentation); }

void
DescrSemantique :: PostFixer ()
   { this -> Ecrire (1); }


// -------------------------------------------------------------------------

void
DescrSemantique :: FaireLEvaluationDirecte (
   ContexteDEvaluationPTR leContexteDEvaluation )
   {
   bool     produitUneValeur = this -> ProduitUneValeur ();

   std::cout <<
      gLANGUE_Semantique ->
         DebutEvaluationDirecte () <<
      std::endl;

   if (produitUneValeur)
      std::cout <<
         gLANGUE_Semantique ->
            EnteteEvalFonction ();
   else
      std::cout <<
         gLANGUE_Semantique ->
            EnteteEvalProcedure ();
   std::cout <<
      std::endl;

   time_t   tempsAuDebut = time (NULL);

   ValeurLista
            laValeur =
               this ->
                  Evaluer (leContexteDEvaluation);

   if (produitUneValeur)
      {
      laValeur.Ecrire (0);

      std::cout <<
         std::endl <<
         "-----------------";
      }
   else
      std::cout <<
         std::endl <<
            gLANGUE_Semantique ->
               FinEvalProcedure ();
   std::cout <<
      std::endl;

   time_t   tempsALaFin = time (NULL);

   std::cout <<
      MiseEnForme (
         gLANGUE_Semantique ->
            FormatTempsDEvaluationDirecte (),
         tempsALaFin - tempsAuDebut ) <<
      std::endl;

   }  // DescrSemantique :: FaireLEvaluationDirecte


VariableLogiqueTypePTR
DescrSemantique::TypeLogiqueDuPremierElementDeListe ()
{
   ListeDescrSemantique listeDescr = this->TraverserLeGrapheSemantique();
   if (listeDescr.size() > 0)
      return listeDescr.front()->TypeLogique();
   else
      return gTypeLogiqueInconnu;
}


// Traverser le graphe semantique pour trouver des descriptions semantique d'une liste.
ListeDescrSemantique
DescrSemantique :: TraverserLeGrapheSemantique ()
{
   ValeurListe* liste = dynamic_cast< ValeurListe* >( this );
   if ( liste )
   {
      return liste -> ListeDeDescriptionsSemantique();
   }
   else
   {
      // Les seuls operateurs unaire predefinies qui manipulent des listes et peuvent retourner des
      // valeurs de type liste sont Car et Cdr.
      OperateurUnaire* lOperateurUnaire = dynamic_cast< OperateurUnaire* >( this );
      if ( lOperateurUnaire )
      {
         if (dynamic_cast< Car* >( lOperateurUnaire ) != NULL)
         {
            // Si l'operateur s'agit du Car, on ne s'interesse qu'au premier element de la liste.
            // On remarque que cet element n'est pas toujours une liste, mais que l'on renvoit quand
            // meme une liste de descriptions semantique contenant que cet element.
            ListeDescrSemantique resultat =
                                    lOperateurUnaire -> Operande() -> TraverserLeGrapheSemantique();

            // On supprime tout sauf le premier element.
            ListeDescrSemantique::iterator it = resultat.begin();
            resultat.erase( ++it, resultat.end() );

            // Maintenant qu'on a l'element qu'on veut, il faut verifier qu'il s'agit d'une liste,
            // dans quel cas on retourne les descriptions semantique de cette liste meme,
            // sinon des appels au Car dans les pas recursifs ulterieurs ne marcheront pas (lorsque
            // on remonte dans la recursion).
            if (resultat.front() -> TypeLogique() != gTypeLogiqueListe)
               return resultat;
            else
               return resultat.front() -> TraverserLeGrapheSemantique();
         }
         else if (dynamic_cast< Cdr* >( lOperateurUnaire ) != NULL)
         {
            // Si l'operateur s'agit du Cdr, on ne s'interesse qu'a la queue de la liste. On efface
            // donc le premier element de la liste.
            ListeDescrSemantique resultat =
                                    lOperateurUnaire -> Operande() -> TraverserLeGrapheSemantique();

            resultat.pop_front();
            return resultat;
         }
      }

      // Les seuls operateurs unaire predefinies qui manipulent des listes sont Cons, Append et
      // ConcatListes.
      OperateurBinaire* lOperateurBinaire = dynamic_cast< OperateurBinaire* >( this );
      if ( lOperateurBinaire )
      {
         ListeDescrSemantique resultat =
                              lOperateurBinaire -> OperandeDroit() -> TraverserLeGrapheSemantique();

         // Dans le cas du Cons, on met l'operande de gauche en tete de la liste.
         if (dynamic_cast< Cons* >( lOperateurBinaire ) != NULL)
            resultat.push_front( lOperateurBinaire -> OperandeDroit() );

         // Dans le cas du Append, on met l'operande de gauche a la fin de la liste.
         else if (dynamic_cast< Append* >( lOperateurBinaire ) != NULL)
            resultat.push_back( lOperateurBinaire -> OperandeDroit() );

         else if (dynamic_cast< ConcatListes* >( lOperateurBinaire ) != NULL)
         {
            ListeDescrSemantique lOperandeGauche =
                           lOperateurBinaire -> OperandeGauche() -> TraverserLeGrapheSemantique();

            // Placer les elements de lOperandeGauche dans la liste resultat, en commencant de la
            // fin.
            for ( ListeDescrSemantique::reverse_iterator it = lOperandeGauche.rbegin();
                  it != lOperandeGauche.rend();
                  it ++ )
                     resultat.push_front( *it );
         }

         // Retourner le resultat.
         return resultat;
      }

      // Pour des situations tel que "L = [1, 2, 3]; X = Car(L);", il faut d'abord obtenir le
      // graphe semantique de L, puis le parcourir pour trouver le type logique voulu.
      AppelDeFonctionUtilisateur *lAppelDeFonctionUtil =
                                              dynamic_cast< AppelDeFonctionUtilisateur* >( this );
      if ( lAppelDeFonctionUtil )
         return lAppelDeFonctionUtil -> GrapheSemantiqueDuCorps() -> TraverserLeGrapheSemantique();

      // Pour des constructions comme "f(L) = Car(L);", le premier element de la liste L est inconnu
      // a priori. On ne fait rien ... (PS. La condition est ajoutee purement comme un rappel)
      if (dynamic_cast< EmploiParametrePTR >( this )) ;

      // Retourner une liste de descriptions semantique vide.
      return ListeDescrSemantique();
   }
}

// -------------------------------------------------------------------------
// Valeurs simples
// -------------------------------------------------------------------------

ValeurInconnue :: ValeurInconnue (VariableLogiqueTypePTR leTypeLogique)
   :  DescrSemantique (leTypeLogique)
   {}

void
ValeurInconnue :: Ecrire (int lIndentation)
   {
   DescrSemantique :: Ecrire (lIndentation);
   std::cout <<
      gLANGUE_Semantique ->
         ValeurInconnue () <<
      std::endl;
   }

ValeurLista
ValeurInconnue :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
   {
   SortieSurErreur (
      gLANGUE_Semantique ->
         ValeurInconnueNEstPasEvaluable (),
      18 );
   return ValeurLista (Nombre (0)); // superflu
   }

#if defined SYNTHESE_PILUM

void
ValeurInconnue :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
   {
   leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
      ValeurInconnue ();
   }

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ValeurNombre :: ValeurNombre (double laValeurNombre)
   :  DescrSemantique (gTypeLogiqueNombre)
   { fValeurNombre = laValeurNombre; }

void
ValeurNombre :: Ecrire (int lIndentation)
   {
   DescrSemantique :: Ecrire (lIndentation);
   std::cout <<
      MiseEnForme (
         "%-*.*f",
         TailleChampEcritureNombres (),
         NombreDecimalesEcritureNombres (),
         fValeurNombre ) <<
      std::endl;
   }

ValeurLista
ValeurNombre :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
   { return ValeurLista (fValeurNombre); }

#if defined SYNTHESE_PILUM

void
ValeurNombre :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
   {
   leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
      Flottant (fValeurNombre);
   }

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ValeurLogique :: ValeurLogique (bool laValeurLogique)
   :  DescrSemantique (gTypeLogiqueBooleen)
   { fValeurLogique = laValeurLogique; }

void
ValeurLogique :: Ecrire (int lIndentation)
   {
   DescrSemantique :: Ecrire (lIndentation);
   std::cout <<
      MiseEnForme (
         "%s",
         fValeurLogique
            ?  gLANGUE_Predefinis ->
                  Vrai ()
            :  gLANGUE_Predefinis ->
                  Faux () ) <<
      std::endl;
   }

ValeurLista
ValeurLogique :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
   { return ValeurLista (fValeurLogique); }

#if defined SYNTHESE_PILUM

void
ValeurLogique :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
   {
   leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
      Logique (fValeurLogique);
   }

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ValeurChaine :: ValeurChaine (Chaine laValeurChaine)
   :  DescrSemantique (gTypeLogiqueChaine)
   { fValeurChaine = laValeurChaine; }

void
ValeurChaine :: Ecrire (int lIndentation)
   {
   DescrSemantique :: Ecrire (lIndentation);
   std::cout <<
      "\"" <<
      fValeurChaine <<
      "\"" <<
      std::endl;
   }

ValeurLista
ValeurChaine :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
   { return ValeurLista (fValeurChaine); }

#if defined SYNTHESE_PILUM

void
ValeurChaine :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
   {
   leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
      Chaine_ (fValeurChaine);
   }

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ValeurVide :: ValeurVide ()
   :  DescrSemantique (gTypeLogiqueVide)
   {}

void
ValeurVide :: Ecrire (int lIndentation)
   {
   DescrSemantique :: Ecrire (lIndentation);
   std::cout <<
      gLANGUE_Semantique ->
         ValeurVide () <<
      std::endl;
   }

ValeurLista
ValeurVide :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
   {
   // rien a faire !
   return ValeurLista (Nombre (0)); // superflu
   }

#if defined SYNTHESE_PILUM

void
ValeurVide :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
   {
   leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
      Commentaire (
         gLANGUE_Semantique ->
            ValeurVide () );
   }

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ValeurListe::ValeurListe (ListeDescrSemantique descr)
   :  DescrSemantique (gTypeLogiqueListe)
   {
   fListeDeDescriptionsSemantique = descr;
   }

void
ValeurListe :: Ecrire (int lIndentation)
   {
   DescrSemantique::Ecrire( lIndentation );

   if (fListeDeDescriptionsSemantique.size() == 0)
      std::cout << "[ ]" << std::endl;
   else if (fListeDeDescriptionsSemantique.size() > 0)
      {
      std::cout << "[" << std::endl;

      ListeDescrSemantique::iterator it = fListeDeDescriptionsSemantique.begin();

      // Afficher le graphe semantique de tous les elements de la liste.
      ++ lIndentation;

      for (; it != fListeDeDescriptionsSemantique.end();  it++)
         (*it) -> Ecrire( lIndentation );

      -- lIndentation;

      DescrSemantique::Ecrire( lIndentation );
      std::cout << "]" << std::endl;
      }
   }

ValeurLista
ValeurListe :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
   {
   ValeurLista          leResultatDeLEvaluation;
   Liste                laListeEvaluee;
   Liste                listeResultat;
   std::list<DescrSemantiquePTR>::iterator it = fListeDeDescriptionsSemantique.begin();

   for (; it != fListeDeDescriptionsSemantique.end(); ++ it)
      {
      // Evaluer le graphe semantique.
      leResultatDeLEvaluation = (*it) -> Evaluer( leContexteDEvaluation );
      TypePTR leType = leResultatDeLEvaluation.Type();

      // Stocker le resultat de l'evaluation dans une liste de valeurs.
      if (leType == gTypeNombre)
         {
         Nombre leNombre = leResultatDeLEvaluation.CommeNombre();
         listeResultat.append( leNombre );
         }
      else if (leType == gTypeBooleen)
         {
         bool leBooleen = leResultatDeLEvaluation.CommeBooleen();
         listeResultat.append( leBooleen );
         }
      else if (leType == gTypeChaine)
         {
         Chaine laChaine = leResultatDeLEvaluation.CommeChaine();
         listeResultat.append( laChaine );
         }
      else if (leType == gTypeListe)
         {
         Liste laListe = leResultatDeLEvaluation.CommeListe();
         listeResultat.append( laListe );
         }
      }
   return ValeurLista( listeResultat );
   }

#if defined SYNTHESE_PILUM

void
ValeurListe::Synthetiser( ContexteDeSynthesePTR leContexteDeSynthese )
{
   ListeDescrSemantique::iterator it = fListeDeDescriptionsSemantique.begin();

   // Synthetiser chacun des elements de la liste dans le context donne. Chaque element sera empile
   // sur la pile de donnees.
   for (; it != fListeDeDescriptionsSemantique.end(); it++)
      (*it)->Synthetiser( leContexteDeSynthese );

   // Ensuite empiler le nombre d'elements de la liste sur la pile.
   long laTaille = fListeDeDescriptionsSemantique.size();
   leContexteDeSynthese->LeSynthetiseurPilumLista()->Entier( laTaille );

   // Une fois que les donnees sont empilees, l'instruction qui reconstruit la liste est empilee a
   // son tour dans la pile d'execution.
   leContexteDeSynthese->LeSynthetiseurPilumLista()->Zeroadique( iGenererListe );
}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

DescrSemantiquePTR            gValeurVide = NULL;

DescrSemantiquePTR            gDescrSemantiqueInconnue = NULL;


// -------------------------------------------------------------------------
// Initialisation
// -------------------------------------------------------------------------

void
InitialiserDescrSemantique ()
   {
   gValeurVide                = new ValeurVide ();

   gDescrSemantiqueInconnue   = new ValeurInconnue ();
   }  // InitialiserDescrSemantique
