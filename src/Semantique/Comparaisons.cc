// =========================================================================
//	Comparaisons.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Comparaisons.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
// Comparaisons
// -------------------------------------------------------------------------

EgalePredef :: EgalePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
EgalePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Egale (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

DifferentPredef :: DifferentPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
DifferentPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Different (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

InfPredef :: InfPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
InfPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Inf (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

SupPredef :: SupPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
SupPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Sup (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

InfEgalePredef :: InfEgalePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
InfEgalePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new InfEgale (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

SupEgalePredef :: SupEgalePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
SupEgalePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new SupEgale (fNom, leBlocDArguments [0], leBlocDArguments [1]); }



// -------------------------------------------------------------------------
//	Operateurs de comparaison
// -------------------------------------------------------------------------

Inf :: Inf (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Inf :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		bool (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
			<
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
Inf :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iInfFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Egale :: Egale (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Egale :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		bool (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
			==
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
Egale :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iEgaleFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Sup :: Sup (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Sup :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		bool (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
			>
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
Sup :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iSupFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

InfEgale :: InfEgale (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
InfEgale :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		bool (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
			<=
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
InfEgale :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iInfEgaleFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

SupEgale :: SupEgale (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
SupEgale :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		bool (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
			>=
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
SupEgale :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iSupEgaleFlottant);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Different :: Different (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Different :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return ValeurLista (
		bool (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre ()
			!=
			fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()
		));
	}

#if defined SYNTHESE_PILUM

void 
Different :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iDifferentFlottant);
	}

#endif /* SYNTHESE_PILUM */
