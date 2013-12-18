#include "Listes.h"
#include "AnalyseurSemantiqueLista.h"

#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


CarPredef::CarPredef( ChaineLanguePredefinisPFM laFonctionNom )
: FonctionPredefinie
( laFonctionNom, kAutreFonctionPredefinie, kAutreIdentificateurFlexBison, gTypeLogiqueNonPrecise )
{
   fNombreDeParametres              = 1;
   fTypesLogiquesDesParametres      = new VariableLogiqueTypePTR[ fNombreDeParametres ];
   fTypesLogiquesDesParametres[0]   = gTypeLogiqueListe;
}

DescrSemantiquePTR
CarPredef::CreerGrapheDAppelALaFonction (
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments )
{
	VariableLogiqueTypePTR leTypeLogique = leBlocDArguments[0]->TypeLogiqueDuPremierElementDeListe();

	// Si le type logique du premier element est inconnue, cela veut dire qu'il n'existe pas, et par
	// consequent, il s'agit d'une liste vide. Par contre il y a un cas ou la liste peut etre vide,
	// et qu'elle ne doit pas etre ignoree: lorsqu'on definit une fonction utilisateur.
	if (!dynamic_cast<EmploiParametre*>(leBlocDArguments[0]) && leTypeLogique == gTypeLogiqueInconnu)
	{
		gAnalyseurSemantiqueLista->
			ErreurSemantique("Une liste non-vide est attendue comme argument de 'Car'!");
		return gDescrSemantiqueInconnue;
	}
	else
      return new Car( fNom, leBlocDArguments[0], leTypeLogique );
}


// -------------------------------------------------------------------------


CdrPredef :: CdrPredef( ChaineLanguePredefinisPFM laFonctionNom ) :
FonctionPredefinie
(
   laFonctionNom, kAutreFonctionPredefinie, kAutreIdentificateurFlexBison, gTypeLogiqueListe
)
{
   fNombreDeParametres              = 1;
   fTypesLogiquesDesParametres      = new VariableLogiqueTypePTR[ fNombreDeParametres ];
   fTypesLogiquesDesParametres[0]   = gTypeLogiqueListe;
}

DescrSemantiquePTR
CdrPredef :: CreerGrapheDAppelALaFonction(
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments )
{
	bool nEstPasUnParametreFormel = (dynamic_cast<EmploiParametre*>(leBlocDArguments[0]) == NULL);
	int nbElementsListe = leBlocDArguments[0]->TraverserLeGrapheSemantique().size();

	if (nEstPasUnParametreFormel && !nbElementsListe)
	{
		gAnalyseurSemantiqueLista->
			ErreurSemantique("Une liste non-vide est attendue comme argument de 'Cdr'!");
		return gDescrSemantiqueInconnue;
	}
	else
	   return new Cdr( fNom, leBlocDArguments[0] );
}


// -------------------------------------------------------------------------


ConsPredef :: ConsPredef( ChaineLanguePredefinisPFM laFonctionNom ) : FonctionPredefinie
(
   laFonctionNom, kFonctionListe, kAutreIdentificateurFlexBison, gTypeLogiqueListe
)
{
   fNombreDeParametres              = 2;
   fTypesLogiquesDesParametres      = new VariableLogiqueTypePTR[ fNombreDeParametres ];

   fTypesLogiquesDesParametres[0]   = gTypeLogiqueNonPrecise;
   fTypesLogiquesDesParametres[1]   = gTypeLogiqueListe;
}

DescrSemantiquePTR
ConsPredef::CreerGrapheDAppelALaFonction( GenreLectureAuClavier genre, DescrSemantiquePTR* args )
{
	return new Cons( fNom, args[0], args[1] );
}


// -------------------------------------------------------------------------


AppendPredef::AppendPredef( ChaineLanguePredefinisPFM laFonctionNom ) : FonctionPredefinie
(
   laFonctionNom, kFonctionListe, kAutreIdentificateurFlexBison, gTypeLogiqueListe
)
{
   fNombreDeParametres              = 2;
   fTypesLogiquesDesParametres      = new VariableLogiqueTypePTR[ fNombreDeParametres ];
   fTypesLogiquesDesParametres[0]   = gTypeLogiqueNonPrecise;
   fTypesLogiquesDesParametres[1]   = gTypeLogiqueListe;
}

DescrSemantiquePTR
AppendPredef::CreerGrapheDAppelALaFonction( GenreLectureAuClavier genre, DescrSemantiquePTR* args )
{
	return new Append( fNom, args[0], args[1] );
}


// -------------------------------------------------------------------------


ConcatListesPredef::ConcatListesPredef( ChaineLanguePredefinisPFM laFonctionNom )
: FonctionPredefinie
(
   laFonctionNom, kAutreFonctionPredefinie, kAutreIdentificateurFlexBison, gTypeLogiqueListe
)
{
   fNombreDeParametres              = 2;
   fTypesLogiquesDesParametres      = new VariableLogiqueTypePTR[ fNombreDeParametres ];
   fTypesLogiquesDesParametres[0]   = gTypeLogiqueListe;
   fTypesLogiquesDesParametres[1]   = gTypeLogiqueListe;
}

DescrSemantiquePTR
ConcatListesPredef::CreerGrapheDAppelALaFonction(
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments )
{
	return new ConcatListes( fNom, leBlocDArguments[0], leBlocDArguments[1] );
}


// -------------------------------------------------------------------------


LongueurListePredef :: LongueurListePredef( ChaineLanguePredefinisPFM laFonctionNom ) :
FonctionPredefinie
(
   laFonctionNom, kAutreFonctionPredefinie, kAutreIdentificateurFlexBison, gTypeLogiqueNombre
)
{
   fNombreDeParametres              = 1;
   fTypesLogiquesDesParametres      = new VariableLogiqueTypePTR[ fNombreDeParametres ];
   fTypesLogiquesDesParametres[0]   = gTypeLogiqueListe;
}

DescrSemantiquePTR
LongueurListePredef :: CreerGrapheDAppelALaFonction(
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR      * leBlocDArguments )
{
   return new LongueurListe( fNom, leBlocDArguments[0] );
}



// -------------------------------------------------------------------------
// Noeuds semantiques
// -------------------------------------------------------------------------

Car::Car( Chaine leNom, DescrSemantiquePTR lOperande, VariableLogiqueTypePTR leTypeLogique )
: OperateurUnaire( leNom, leTypeLogique, lOperande ){ }


ValeurLista
Car::Evaluer( ContexteDEvaluationPTR leContexteDEvaluation )
{
   // Evaluer l'operande dans une contexte donnee.
   Element lElement = fOperande->Evaluer( leContexteDEvaluation ).CommeListe().car();

   // Retourner le premier element de la liste.
   switch (lElement.fType)
   {
      case kTypeNombre:
         return ValeurLista( Nombre( lElement.fNombre ) );
      case kTypeBooleen:
         return ValeurLista( lElement.fBooleen );
      case kTypeChaine:
         return ValeurLista( *lElement.fChaine );
      case kTypeListe:
         return ValeurLista( *lElement.fListe );
      default:
         return ValeurLista();
         break;
   }
}


#if defined SYNTHESE_PILUM
void
Car::Synthetiser( ContexteDeSynthesePTR leContexteDeSynthese )
{
   // Synthetiser l'operande dans le contexte donne et ajouter le code operatoire 'iCar'.
   fOperande->Synthetiser( leContexteDeSynthese );
   leContexteDeSynthese->LeSynthetiseurPilumLista()->Zeroadique( iCar );
}
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------


Cdr::Cdr( Chaine leNom, DescrSemantiquePTR lOperande )
: OperateurUnaire( leNom, gTypeLogiqueListe, lOperande ){ }


ValeurLista
Cdr::Evaluer( ContexteDEvaluationPTR leContexteDEvaluation )
{
   // Evaluer l'operande dans un contexte donne et retourner le resultat (la liste sans son
   // premier element).
   return ValeurLista( fOperande->Evaluer( leContexteDEvaluation ).CommeListe().cdr() );
}


#if defined SYNTHESE_PILUM
void
Cdr::Synthetiser( ContexteDeSynthesePTR leContexteDeSynthese )
{
   // Synthetiser l'operande dans le contexte donne et ajouter le code operatoire 'iCdr'.
   fOperande->Synthetiser( leContexteDeSynthese );
   leContexteDeSynthese->LeSynthetiseurPilumLista()->Zeroadique( iCdr );
}
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------


Cons::Cons( Chaine leNom, DescrSemantiquePTR lOperandeGauche, DescrSemantiquePTR lOperandeDroit )
: OperateurBinaire( leNom, gTypeLogiqueListe, lOperandeGauche, lOperandeDroit ){ }


ValeurLista
Cons::Evaluer( ContexteDEvaluationPTR leContexte )
{
   // L'element qui sera ajoute a la liste.
   Element  lElement;

   // Evaluer les operandes dans un contexte donne.
   ValeurLista fOperandeGaucheEvalue   = fOperandeGauche -> Evaluer( leContexte );
   Liste laListe                       = fOperandeDroit  -> Evaluer( leContexte ).CommeListe();
   TypePTR leTypeOperandeGauche			= fOperandeGaucheEvalue.Type();

   if (leTypeOperandeGauche == gTypeNombre)
   {
      lElement.fNombre  = fOperandeGaucheEvalue.CommeNombre();
      lElement.fType    = kTypeNombre;
   }
   else if (leTypeOperandeGauche == gTypeBooleen)
   {
      lElement.fBooleen = fOperandeGaucheEvalue.CommeBooleen();
      lElement.fType    = kTypeBooleen;
   }
   else if (leTypeOperandeGauche == gTypeChaine)
   {
      lElement.fChaine  = new Chaine( fOperandeGaucheEvalue.CommeChaine() );
      lElement.fType    = kTypeChaine;
   }
   else if (leTypeOperandeGauche == gTypeListe)
   {
      lElement.fListe      = new Liste();
      *(lElement.fListe)   = fOperandeGaucheEvalue.CommeListe();
      lElement.fType       = kTypeListe;
   }

   // Ajouter l'element en tete de la liste.
   laListe.cons( lElement );

   return ValeurLista( laListe );
}


#if defined SYNTHESE_PILUM
void
Cons::Synthetiser( ContexteDeSynthesePTR leContexteDeSynthese )
{
   // Synthetiser les operandes dans le contexte donne et ajouter le code operatoire 'iCons'.
   OperateurBinaire::Synthetiser( leContexteDeSynthese );
   leContexteDeSynthese->LeSynthetiseurPilumLista()->Zeroadique( iCons );
}
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------


Append::Append(Chaine leNom, DescrSemantiquePTR lOperandeGauche, DescrSemantiquePTR lOperandeDroit )
: OperateurBinaire( leNom, gTypeLogiqueListe, lOperandeGauche, lOperandeDroit ){ }


ValeurLista
Append::Evaluer( ContexteDEvaluationPTR leContexte )
{
   // L'element qui sera ajoute a la liste.
   Element  lElement;

   // Evaluer les operandes dans un contexte donne.
   ValeurLista fOperandeGaucheEvalue   = fOperandeGauche -> Evaluer( leContexte );
   Liste laListe                       = fOperandeDroit  -> Evaluer( leContexte ).CommeListe();
	TypePTR leTypeOperandeGauche			= fOperandeGaucheEvalue.Type();


   if (leTypeOperandeGauche == gTypeNombre)
   {
      lElement.fNombre  = fOperandeGaucheEvalue.CommeNombre();
      lElement.fType    = kTypeNombre;
   }
   else if (leTypeOperandeGauche == gTypeBooleen)
   {
      lElement.fBooleen = fOperandeGaucheEvalue.CommeBooleen();
      lElement.fType    = kTypeBooleen;
   }
   else if (leTypeOperandeGauche == gTypeChaine)
   {
      lElement.fChaine  = new Chaine( fOperandeGaucheEvalue.CommeChaine() );
      lElement.fType    = kTypeChaine;
   }
   else if (leTypeOperandeGauche == gTypeListe)
   {
      lElement.fListe      = new Liste();
      *(lElement.fListe)   = fOperandeGaucheEvalue.CommeListe();
      lElement.fType       = kTypeListe;
   }

   // Ajouter l'element en derniere position.
   laListe.append( lElement );

   return ValeurLista( laListe );
}


#if defined SYNTHESE_PILUM
void
Append::Synthetiser( ContexteDeSynthesePTR leContexteDeSynthese )
{
   // Synthetiser les operandes dans le contexte donne et ajouter le code operatoire 'iAppend'.
   OperateurBinaire::Synthetiser( leContexteDeSynthese );
   leContexteDeSynthese->LeSynthetiseurPilumLista()->Zeroadique( iAppend );
}
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------


ConcatListes::
ConcatListes(	Chaine leNom, DescrSemantiquePTR lOperandeGauche, DescrSemantiquePTR lOperandeDroit )
: OperateurBinaire( leNom, gTypeLogiqueListe, lOperandeGauche, lOperandeDroit ){ }


ValeurLista
ConcatListes::Evaluer( ContexteDEvaluationPTR leContexteDEvaluation )
{
   // Evaluer les operandes dans un contexte d'evaluation donne.
   Liste fOperandeGaucheEvalue   = fOperandeGauche -> Evaluer( leContexteDEvaluation ).CommeListe();
   Liste fOperandeDroitEvalue    = fOperandeDroit ->  Evaluer( leContexteDEvaluation ).CommeListe();

   // Concatener la liste 'droit' a la liste 'gauche'.
   fOperandeGaucheEvalue.concat( fOperandeDroitEvalue );

   return ValeurLista( fOperandeGaucheEvalue );
}


#if defined SYNTHESE_PILUM
void
ConcatListes::Synthetiser( ContexteDeSynthesePTR leContexteDeSynthese )
{
   // Synthetiser les operandes dans le contexte donne et ajouter le code operatoire 'iConcatListes'.
   OperateurBinaire::Synthetiser( leContexteDeSynthese );
   leContexteDeSynthese->LeSynthetiseurPilumLista()->Zeroadique( iConcatListes );
}
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------


LongueurListe::LongueurListe( Chaine leNom, DescrSemantiquePTR lOperande )
: OperateurUnaire( leNom, gTypeLogiqueNombre, lOperande ){ }


ValeurLista
LongueurListe::Evaluer( ContexteDEvaluationPTR leContexteDEvaluation )
{
   // Evaluer l'operande dans une contexte donnee et retourner la longueur de la liste.
   Liste fOperandeEvalue = fOperande -> Evaluer( leContexteDEvaluation ).CommeListe();
   return ValeurLista( fOperandeEvalue.taille() );
}


#if defined SYNTHESE_PILUM
void
LongueurListe::Synthetiser( ContexteDeSynthesePTR leContexteDeSynthese )
{
   // Synthetiser l'operande dans le contexte donne et ajouter le code operatoire 'iLongueurListe'.
   fOperande->Synthetiser( leContexteDeSynthese );
   leContexteDeSynthese->LeSynthetiseurPilumLista()->Zeroadique( iLongueurListe );
}
#endif /* SYNTHESE_PILUM */
