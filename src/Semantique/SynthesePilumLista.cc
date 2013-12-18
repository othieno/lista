// =========================================================================
// SynthesePilumLista.cc
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#include "SynthesePilumLista.h"

#include "LanguesSynthesePilum.h"


// -------------------------------------------------------------------------
// DescrBlocDActivation
// -------------------------------------------------------------------------

DescrBlocDActivation :: DescrBlocDActivation (Chaine leNom)
   {
   fNom = leNom;

   fNombreLogTemporaires =
      new VariableLogiqueEntiere ("fNombreLogTemporaires");

   fDernierTemporaireAlloue = 0;
   fNombreTemporairesSimultanes = 0;
   }

DescrBlocDActivation :: ~ DescrBlocDActivation ()
   {
   // ne PAS faire 'delete fNombreLogTemporaires' :
   // doit subsister jsuqu'à la fin de la compilation
   }


Chaine
DescrBlocDActivation :: Nom ()
   { return fNom; }

VariableLogiqueEntierePTR
DescrBlocDActivation :: NombreLogTemporaires ()
   { return fNombreLogTemporaires; }

// -------------------------------------------------------------------------

int
DescrBlocDActivation :: AllouerTemporaire ()
   {
   int      res = ++ fDernierTemporaireAlloue;

   if (fDernierTemporaireAlloue > fNombreTemporairesSimultanes)
      fNombreTemporairesSimultanes = fDernierTemporaireAlloue;

   return res;
   }

void
DescrBlocDActivation :: LibererTemporaire ()
   { -- fDernierTemporaireAlloue; }

void
DescrBlocDActivation :: LierNombreLogTemporaires ()
   {
   fNombreLogTemporaires ->
      UnifierValeur (
         new ValeurEntiere (fNombreTemporairesSimultanes), 0 );
   }


// -------------------------------------------------------------------------
// ContexteDeSynthese
// -------------------------------------------------------------------------

ContexteDeSynthese :: ContexteDeSynthese (
   SynthetiseurPilumListaPTR     leSynthetiseurPilumLista,
   DescrBlocDActivationPTR       laDescrBlocDActivation,
   OptionsSynthesePTR            lesOptionsSynthese,
   VariableLogiqueEtiquettePTR   laContinuation )
   {
   fSynthetiseurPilumLista = leSynthetiseurPilumLista;

   fDescrBlocDActivation = laDescrBlocDActivation;

   fOptionsSynthese = lesOptionsSynthese;

   fContinuation = laContinuation;
   }  // ContexteDeSynthese :: ContexteDeSynthese


// -------------------------------------------------------------------------
// SynthetiseurPilumLista
// -------------------------------------------------------------------------

SynthetiseurPilumLista :: SynthetiseurPilumLista (
   Chaine               leNom,
   std::ostream         * leFlotTexte,
   std::ofstream        * leFichierBinaire,
   OptionsSynthesePTR   lesOptionsSynthese )
   :  SynthetiseurPilum (leNom, lesOptionsSynthese)
   {
   fFlotTexte = leFlotTexte;
   fFichierBinaire = leFichierBinaire;

   fOptionsSynthese = lesOptionsSynthese;

   fDelimiteurDeFonctionsEtEvaluations =
      gLANGUE_Semantique ->
         DelimiteurDeFonctionsEtEvaluations ();

   bool     optimiserLesSauts =
               fOptionsSynthese -> OptimiserLesSauts ();

   if (fOptionsSynthese -> ModeVerbeux () && optimiserLesSauts)
      std::cout <<
         gLANGUE_Semantique ->
            LesSautSurDesSautsSontOptimises () <<
         std::endl;

   fDescrBlocDActivationPrincipal =
      new DescrBlocDActivation (
         gLANGUE_Semantique ->
            BlocDActivationPrincipal () );

   fContexteDeSynthesePrincipal =
      new ContexteDeSynthese (
         this,
         fDescrBlocDActivationPrincipal,
         fOptionsSynthese,
         NULL );

   VariableLogiqueEntierePTR
            leNombreLogTemporaires =
               fDescrBlocDActivationPrincipal -> NombreLogTemporaires ();

   // le programme principal est consitué de la concaténation de
   // toutes les évaluations, qui n'ont pas de block d'activation propre

   ReserverCellules (leNombreLogTemporaires);
   }  // SynthetiseurPilumLista :: SynthetiseurPilumLista


SynthetiseurPilumLista :: ~ SynthetiseurPilumLista ()
   {
   delete fDescrBlocDActivationPrincipal;
   }


// -------------------------------------------------------------------------

void
SynthetiseurPilumLista :: SynthetiserDefinitionDeFonction (
   FonctionUtilisateurPTR  lIdentFonction,
   DescrSemantiquePTR      leGrapheSemantiqueDuCorps )
   {
   bool     lienStatiqueNecessaire =
               lIdentFonction -> LienStatiqueNecessaire ();

   int      positionDeDepart =
               lienStatiqueNecessaire
                  ?  - (kTailleDesLiensObligatoires + 1)
                     // 1 pour le lien statique
                  : - kTailleDesLiensObligatoires;

   ListeDeParametresFormelsPTR
            listeDesParametresFormels =
               lIdentFonction -> LaListeDeParametresFormels ();

   listeDesParametresFormels ->
      AllouerLesParametres (positionDeDepart);

   int      tailleParametres =
               listeDesParametresFormels -> TailleDesParametres ();

   if (fOptionsSynthese -> MarquerLesBlocsDActivation ())
      tailleParametres ++;

   int      tailleADesempiler =
               lienStatiqueNecessaire
                  ?  tailleParametres + 1
                     // 1 pour le lien statique
                  : tailleParametres;

   Chaine   leNom = lIdentFonction -> Nom ();

   DescrBlocDActivationPTR
            descrBlocDActivationFonction =
               new DescrBlocDActivation (leNom);
   VariableLogiqueEntierePTR
            leNombreLogTemporaires =
               descrBlocDActivationFonction -> NombreLogTemporaires ();

   VariableLogiqueEtiquettePTR
            etiquDuCorps = CreerEtiquette (
               gLANGUE_Semantique ->
                  EtiquetteCorpsDeFonction () );
   VariableLogiqueEtiquettePTR
            etiquetteSuiteDuCorps = CreerEtiquette (
               gLANGUE_Semantique ->
                  EtiquetteSuiteDeCorpsDeFonction () );

   bool     commenterLeCode =
               fOptionsSynthese -> CommenterLeCode ();

   lIdentFonction -> EtiquetteDuCorps (etiquDuCorps);

   Saut (iSauter, etiquetteSuiteDuCorps);
   if (commenterLeCode)
      Commentaire (fDelimiteurDeFonctionsEtEvaluations);

   PlacerEtiquette (etiquDuCorps);

   if (commenterLeCode)
      Commentaire (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatDebutDuCorpsDeFonction (),
            leNom,
            lIdentFonction -> NiveauDEvaluation () + 1,
            lIdentFonction -> NiveauStatique () + 1 ));

   ReserverCellules (leNombreLogTemporaires);

   bool     optimiserLesSauts =
               fOptionsSynthese -> OptimiserLesSauts ();

   if (! optimiserLesSauts)
      {
      ContexteDeSynthese
               leContexteCorps (
                  this,
                  descrBlocDActivationFonction,
                  fOptionsSynthese,
                  NULL );

      leGrapheSemantiqueDuCorps ->
         Synthetiser (& leContexteCorps);
      }
   else
      {
      VariableLogiqueEtiquettePTR
               continationApresCorps = CreerEtiquette (
                  gLANGUE_Semantique ->
                     EtiquetteContinuationDuCorpsDeFonction () );

      ContexteDeSynthese
               leContexteCorps (
                  this,
                  descrBlocDActivationFonction,
                  fOptionsSynthese,
                  continationApresCorps );

      leGrapheSemantiqueDuCorps ->
         Synthetiser (& leContexteCorps);

      PlacerEtiquette (continationApresCorps);
      } // optimiserLesSauts

   descrBlocDActivationFonction -> LierNombreLogTemporaires ();
   delete descrBlocDActivationFonction;

   TypePTR  leType =
               leGrapheSemantiqueDuCorps ->
                  TypeLogique () -> ValeurDeLiaison ();

   Entier (
      leType == gTypeVide
         ?  iRetourDeProcedure
         :  iRetourDeFonction,
      tailleADesempiler );

   if (commenterLeCode)
      {
      if (lienStatiqueNecessaire)
         Commentaire (
            gLANGUE_Semantique ->
               FormatLienStatiqueNecessairePourFonction () );

      Commentaire (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatFinDuCorpsDeFonction (),
            leNom ));
      Commentaire (fDelimiteurDeFonctionsEtEvaluations);
      }

   PlacerEtiquette (etiquetteSuiteDuCorps);

   }  // SynthetiseurPilumLista :: SynthetiserDefinitionDeFonction


// -------------------------------------------------------------------------

void
SynthetiseurPilumLista :: SynthetiserEvaluation (
   DescrSemantiquePTR      lExpression )
   {
   bool     commenterLeCode = fOptionsSynthese -> CommenterLeCode ();

   bool     produitUneValeur = lExpression -> ProduitUneValeur ();

   if (commenterLeCode)
      Commentaire (
         gLANGUE_Semantique ->
            DebutDUneEvaluation () );

   Zeroadique (iEcrireFinDeLigne);

   if (produitUneValeur)
      Chaine_ (
         gLANGUE_Semantique ->
            EnteteEvalFonction () );
   else
      Chaine_ (
         gLANGUE_Semantique ->
            EnteteEvalProcedure () );
   Zeroadique (iEcrireChaine);
   Zeroadique (iEcrireFinDeLigne);

   bool     optimiserLesSauts =
               fOptionsSynthese -> OptimiserLesSauts ();

   if (! optimiserLesSauts)
      lExpression -> Synthetiser (fContexteDeSynthesePrincipal);
   else
      {
      VariableLogiqueEtiquettePTR
               continuationEvaluation = CreerEtiquette (
                  gLANGUE_Semantique ->
                     EtiquetteContinuationDUneEvaluation () );

      ContexteDeSynthese
               leContexteDeSynthese (
                  this,
                  fDescrBlocDActivationPrincipal,
                  fOptionsSynthese,
                  continuationEvaluation );

      lExpression -> Synthetiser (& leContexteDeSynthese);

      PlacerEtiquette (continuationEvaluation);
      } // optimiserLesSauts


   TypePTR  leType =
               lExpression -> TypeLogique () -> ValeurDeLiaison ();

   if (dynamic_cast <TypeNombre *> (leType) != NULL)
      Zeroadique (iEcrireFlottant);

   else if (dynamic_cast <TypeBooleen *> (leType) != NULL)
      Zeroadique (iEcrireBooleen);

   else if (dynamic_cast <TypeChaine *> (leType) != NULL)
      Zeroadique (iEcrireChaine);

   else if (dynamic_cast <TypeListe *> (leType) != NULL)
      Zeroadique (iEcrireListe);

   else
      {
      // RIEN A FAIRE
      }

   if (produitUneValeur)
      {
      Zeroadique (iEcrireFinDeLigne);
      Chaine_ ("=================");
      Zeroadique (iEcrireChaine);
      }
   else
      {
      Chaine_ (
         gLANGUE_Semantique ->
            FinEvalProcedure () );
      Zeroadique (iEcrireChaine);
      }
   Zeroadique (iEcrireFinDeLigne);

   if (commenterLeCode)
      {
      Commentaire (
         gLANGUE_Semantique ->
            FinDUneEvaluation () );
      Commentaire (fDelimiteurDeFonctionsEtEvaluations);
      }

   }  // SynthetiseurPilumLista :: SynthetiserEvaluation


// -------------------------------------------------------------------------

VariableLogiqueEtiquettePTR
SynthetiseurPilumLista :: SynthetiserCorpsDeThunk (
   ContexteDeSynthesePTR   leContexteDeSynthese,
   DescrParametrePTR       laDescrParametre,
   DescrSemantiquePTR      lArgumentDAppel )
   {
   ParametreFormelPTR
            leParametreFormel =
               laDescrParametre -> ParametreFormel ();

   Chaine   leNomQualifieDuParametre   =
               leParametreFormel -> NomQualifie ();

   VariableLogiqueEtiquettePTR
            etiquDuThunk      =
               CreerEtiquette (
                  gLANGUE_Semantique ->
                     EtiquetteDeCorpsDeThunk () );

   VariableLogiqueEtiquettePTR
            etiquetteSuiteDuThunk   =
               CreerEtiquette (
                  gLANGUE_Semantique ->
                     EtiquetteSuiteDeCorpsDeThunk () );

   bool     commenterLeCode   =
               fOptionsSynthese -> CommenterLeCode ();

   Saut (iSauter, etiquetteSuiteDuThunk);
   if (commenterLeCode)
      Commentaire (fDelimiteurDeFonctionsEtEvaluations);

   PlacerEtiquette (etiquDuThunk);

   if (commenterLeCode)
      Commentaire (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatDebutDuCorpsDeThunk (),
            leNomQualifieDuParametre ));

   DescrBlocDActivationPTR
            laDescrBlocDActivation =
               new DescrBlocDActivation (leNomQualifieDuParametre);
   VariableLogiqueEntierePTR
            leNombreLogTemporaires =
               laDescrBlocDActivation -> NombreLogTemporaires ();

   ContexteDeSynthese
            contexteDeSyntheseDuCorps (
               this,
               laDescrBlocDActivation,
               leContexteDeSynthese -> OptionsSynthese (),
               NULL );

   ReserverCellules (leNombreLogTemporaires);

   lArgumentDAppel -> Synthetiser (& contexteDeSyntheseDuCorps);

   laDescrBlocDActivation -> LierNombreLogTemporaires ();
   delete laDescrBlocDActivation;

   bool     marquerLesBlocsDActivation =
               fOptionsSynthese -> MarquerLesBlocsDActivation ();

   int      tailleParametres =
               marquerLesBlocsDActivation
                  ? 2
                  : 1;

   Entier (iRetourDeFonction, tailleParametres);

   if (commenterLeCode)
      {
      Commentaire (
         gLANGUE_Semantique ->
            FormatLienStatiqueNecessairePourThunk () );
      if (marquerLesBlocsDActivation)
         Commentaire (
            gLANGUE_Semantique ->
               FormatLienMarqueDeBlocDActivation () );
      Commentaire (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatFinDuCorpsDeThunk (),
            leNomQualifieDuParametre ));
      Commentaire (fDelimiteurDeFonctionsEtEvaluations);
      }

   PlacerEtiquette (etiquetteSuiteDuThunk);

   return etiquDuThunk;
   }  // SynthetiseurPilumLista :: SynthetiserCorpsDeThunk


// -------------------------------------------------------------------------

void
SynthetiseurPilumLista :: SynthetiserLEpilogue ()
   {
   VariableLogiqueEntierePTR
            leNombreLogTemporaires =
               fDescrBlocDActivationPrincipal -> NombreLogTemporaires ();

   // le programme principal est consitué de la concaténation de
   // toutes les évaluations, qui n'ont pas de block d'activation propre

   DetruireCellules (leNombreLogTemporaires);

   Zeroadique (iHalte);
   }


// -------------------------------------------------------------------------

void
SynthetiseurPilumLista :: FinaliserLaSyntheseDeCode ()
   {
   fDescrBlocDActivationPrincipal ->
      LierNombreLogTemporaires ();

   FinaliserLeCodePilum ();
   }


// -------------------------------------------------------------------------

void
SynthetiseurPilumLista :: EcrireSurLeFichierBinaire ()
   {
   if (fOptionsSynthese -> MontrerLeCode ())
      EcrireLeCodeEnTexte (
         gLANGUE_SynthesePilum ->
            FormatCodeSynthetise (),
         fFlotTexte,
         true );

   EcrireCodeBinaireSurLeFichier (fFichierBinaire);
   }
