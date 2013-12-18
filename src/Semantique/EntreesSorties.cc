// =========================================================================
//	EntreesSorties.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "EntreesSorties.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Lectures
// -------------------------------------------------------------------------

LireNombrePredef :: LireNombrePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueNombre )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueChaine;
	}

DescrSemantiquePTR
LireNombrePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new LireNombre (leGenreLectureAuClavier, fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

LireBooleenPredef :: LireBooleenPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueChaine;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueChaine;
	}

DescrSemantiquePTR
LireBooleenPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{
	return new LireBooleen (
		leGenreLectureAuClavier, fNom, leBlocDArguments [0], leBlocDArguments [1] );
	}

// -------------------------------------------------------------------------

LireChainePredef :: LireChainePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueChaine )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueChaine;
	}

DescrSemantiquePTR
LireChainePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new LireChaine (leGenreLectureAuClavier, fNom, leBlocDArguments [0]); }


// -------------------------------------------------------------------------
//	Ecritures
// -------------------------------------------------------------------------

EcrireNombrePredef :: EcrireNombrePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueVide )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
EcrireNombrePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new EcrireNombre (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

EcrireBooleenPredef :: EcrireBooleenPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueVide )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueBooleen;
	}

DescrSemantiquePTR
EcrireBooleenPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new EcrireBooleen (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

EcrireChainePredef :: EcrireChainePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueVide )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueChaine;
	}

DescrSemantiquePTR
EcrireChainePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new EcrireChaine (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

EcrireFinDeLignePredef :: EcrireFinDeLignePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueVide )
	{
	fNombreDeParametres = 0;
	fTypesLogiquesDesParametres = NULL;
	}

DescrSemantiquePTR
EcrireFinDeLignePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new EcrireFinDeLigne (fNom); }


// -------------------------------------------------------------------------
//	Ecritures
// -------------------------------------------------------------------------

EcrireNombre :: EcrireNombre (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueVide, lOperande )
	{}

ValeurLista 
EcrireNombre :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	ValeurLista
				res;	//	valeur vide, une procédure

	std::cout <<
		MiseEnForme (
			"%*.*f",
			TailleChampEcritureNombres (),
			NombreDecimalesEcritureNombres (),
			fOperande -> Evaluer (leContexteDEvaluation).CommeNombre () );

	return res;
	}

#if defined SYNTHESE_PILUM

void 
EcrireNombre :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () -> 
		Zeroadique (iEcrireFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

EcrireBooleen :: EcrireBooleen (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueVide, lOperande )
	{}

ValeurLista 
EcrireBooleen :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	ValeurLista
				res;	//	valeur vide, une procédure

	std::cout <<
		MiseEnForme (
			"%s",
			fOperande -> Evaluer (leContexteDEvaluation).CommeBooleen ()
				?  gLANGUE_Predefinis ->
						Vrai ()
				:  gLANGUE_Predefinis ->
						Faux () );

	return res;
	}  // EcrireBooleen :: Evaluer


#if defined SYNTHESE_PILUM

void 
EcrireBooleen :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () -> 
		Zeroadique (iEcrireBooleen);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

EcrireChaine :: EcrireChaine (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueVide, lOperande )
	{}

ValeurLista 
EcrireChaine :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	ValeurLista
				res;	//	valeur vide, une procédure

	std::cout <<
		MiseEnForme (
			"%s",
			fOperande -> 
				Evaluer (leContexteDEvaluation).CommeChaine () );

	return res;
	}  // EcrireChaine :: Evaluer


#if defined SYNTHESE_PILUM

void 
EcrireChaine :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () -> 
		Zeroadique (iEcrireChaine);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

EcrireFinDeLigne :: EcrireFinDeLigne (Chaine leNom)
	: OperateurZeroaire ( leNom, gTypeLogiqueVide )
	{}

ValeurLista 
EcrireFinDeLigne :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	ValeurLista
				res;	//	valeur vide, une procédure

	std::cout <<
		std::endl;

	return res;
	}

#if defined SYNTHESE_PILUM

void 
EcrireFinDeLigne :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	leContexteDeSynthese -> LeSynthetiseurPilumLista () -> 
		Zeroadique (iEcrireFinDeLigne);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Lectures
// -------------------------------------------------------------------------

LireNombre :: LireNombre (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	Chaine						leNom,
	DescrSemantiquePTR		lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{ fGenreLectureAuClavier = leGenreLectureAuClavier; }

ValeurLista 
LireNombre :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		FLireFlottant (
			fGenreLectureAuClavier,
			fOperande -> Evaluer (leContexteDEvaluation).CommeChaine () ));
	}

#if defined SYNTHESE_PILUM

void 
LireNombre :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iLireFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

LireBooleen :: LireBooleen (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	Chaine						leNom,
	DescrSemantiquePTR		lOperandeGauche,
	DescrSemantiquePTR		lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{ fGenreLectureAuClavier = leGenreLectureAuClavier; }

ValeurLista
LireBooleen :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		FLireBooleen (
			fGenreLectureAuClavier,
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeChaine (),
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeChaine () ));
	}

#if defined SYNTHESE_PILUM

void
LireBooleen :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iLireBooleen);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

LireChaine :: LireChaine (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	Chaine						leNom,
	DescrSemantiquePTR		lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueChaine, lOperande )
	{ fGenreLectureAuClavier = leGenreLectureAuClavier; }

ValeurLista
LireChaine :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		FLireChaine (
			fGenreLectureAuClavier,
			fOperande -> Evaluer (leContexteDEvaluation).CommeChaine () ));
	}

#if defined SYNTHESE_PILUM

void
LireChaine :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iLireChaine);
	}

#endif /* SYNTHESE_PILUM */
