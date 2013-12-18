// =========================================================================
//	Arithmetique.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Arithmetique.h"

#include <math.h>


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
// Mathematiques
// -------------------------------------------------------------------------

ModuloPredef :: ModuloPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
ModuloPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Modulo (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

HasardPredef :: HasardPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 0;
	fTypesLogiquesDesParametres = NULL;
	}

DescrSemantiquePTR
HasardPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Hasard (fNom); }

// -------------------------------------------------------------------------

RacinePredef :: RacinePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
RacinePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Racine (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

SinPredef :: SinPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
SinPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Sin (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

CosPredef :: CosPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
CosPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Cos (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

ArcTanPredef :: ArcTanPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
ArcTanPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new ArcTan (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

LogPredef :: LogPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
LogPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Log (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

ExpPredef :: ExpPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
ExpPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Exp (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

PairPredef :: PairPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
PairPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Pair (fNom, leBlocDArguments [0]); }


// -------------------------------------------------------------------------
//	Operateurs zeroaires
// -------------------------------------------------------------------------

Hasard :: Hasard (Chaine leNom)
	: OperateurZeroaire ( leNom, gTypeLogiqueNombre )
	{}

ValeurLista 
Hasard :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{ return ValeurLista (FHasard ()); }

#if defined SYNTHESE_PILUM

void 
Hasard :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iHasard);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Operateurs arithmetiques
// -------------------------------------------------------------------------

MoinsUnaire :: MoinsUnaire (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{}

ValeurLista 
MoinsUnaire :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			Nombre (
				- fOperande -> Evaluer (leContexteDEvaluation).CommeNombre () ));
	}

#if defined SYNTHESE_PILUM

void 
MoinsUnaire :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iMoins1Flottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Plus :: Plus (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueNombre, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Plus :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		Nombre (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
				+
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
Plus :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iPlusFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Moins :: Moins (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueNombre, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Moins :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		Nombre (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
				-
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
Moins :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iMoinsFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Fois :: Fois (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueNombre, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Fois :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		Nombre (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
				*
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
Fois :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iFoisFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

DivisePar :: DivisePar (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueNombre, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
DivisePar :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	Nombre	valeurOperandeDroit =
					fOperandeDroit -> 
						Evaluer (leContexteDEvaluation).CommeNombre ();

	return ValeurLista (
		Nombre (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
				/
			valeurOperandeDroit
		));
	}

#if defined SYNTHESE_PILUM

void 
DivisePar :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iDiviseFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Modulo :: Modulo (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueNombre, lOperandeGauche, lOperandeDroit )
	{}

 ValeurLista Modulo :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	 Nombre	valeurOperandeDroit =
					fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ();

	return ValeurLista (
		Nombre (
			int (fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ())
				%
			int (valeurOperandeDroit)
		 ));
	}

#if defined SYNTHESE_PILUM

void 
Modulo :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iModuloEntier);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Racine :: Racine (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{}

ValeurLista 
Racine :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			Nombre (
				sqrt (fOperande -> Evaluer (leContexteDEvaluation).CommeNombre ())) );
	}

#if defined SYNTHESE_PILUM

void 
Racine :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iRacine);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Sin :: Sin (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{}

ValeurLista 
Sin :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			Nombre (
				sin (fOperande -> Evaluer (leContexteDEvaluation).CommeNombre ())) );
	}

#if defined SYNTHESE_PILUM

void 
Sin :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iSin);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Cos :: Cos (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{}

ValeurLista 
Cos :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			Nombre (
				cos (fOperande -> Evaluer (leContexteDEvaluation).CommeNombre ())) );
	}

#if defined SYNTHESE_PILUM

void 
Cos :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iCos);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ArcTan :: ArcTan (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{}

ValeurLista 
ArcTan :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			Nombre (
				atan (fOperande -> Evaluer (leContexteDEvaluation).CommeNombre ())) );
	}

#if defined SYNTHESE_PILUM

void 
ArcTan :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iArcTan);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Log :: Log (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{}

ValeurLista 
Log :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			Nombre (
				log (fOperande -> Evaluer (leContexteDEvaluation).CommeNombre ())) );
	}

#if defined SYNTHESE_PILUM

void 
Log :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iLog);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Exp :: Exp (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{}

ValeurLista 
Exp :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			Nombre (
				exp (fOperande -> Evaluer (leContexteDEvaluation).CommeNombre ())) );
	}

#if defined SYNTHESE_PILUM

void 
Exp :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iExp);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Pair :: Pair (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueBooleen, lOperande )
	{}

ValeurLista 
Pair :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			bool (
				int (
					fOperande -> 
						Evaluer (leContexteDEvaluation).CommeNombre ()) % 2 == 0) );
	}

#if defined SYNTHESE_PILUM

void 
Pair :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	fOperande -> Synthetiser (leContexteDeSynthese);
	synth ->
		Zeroadique (iTronquerFlottantEnEntier);
	synth ->
		Zeroadique (iPair);
	}


#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

DescrSemantiquePTR				gValeurPi   = NULL;
DescrSemantiquePTR				gValeurE    = NULL;


// -------------------------------------------------------------------------
//	Initialisation
// -------------------------------------------------------------------------

void
InitialiserArithmetique ()
	{
	gValeurPi						= new ValeurNombre (3.141592);
	gValeurE							= new ValeurNombre (2.718281);
	}
