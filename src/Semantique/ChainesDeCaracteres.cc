// =========================================================================
//	ChainesDeCaracteres.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "ChainesDeCaracteres.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Chaines de caracteres
// -------------------------------------------------------------------------

LongueurChainePredef :: LongueurChainePredef (
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
LongueurChainePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new LongueurChaine (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

ChaineVidePredef :: ChaineVidePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueChaine;
	}

DescrSemantiquePTR
ChaineVidePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new ChaineVide (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

ContientChainePredef :: ContientChainePredef (
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
ContientChainePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{
	return
		new ContientChaine (fNom, leBlocDArguments [0], leBlocDArguments [1]);
	}

// -------------------------------------------------------------------------

ConcatChainesPredef :: ConcatChainesPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueChaine )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueChaine;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueChaine;
	}

DescrSemantiquePTR
ConcatChainesPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new ConcatChaines (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

RepliquerChainePredef :: RepliquerChainePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueChaine )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueChaine;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
RepliquerChainePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new RepliquerChaine (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

RemplacerChainePredef :: RemplacerChainePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueChaine )
	{
	fNombreDeParametres = 3;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueChaine;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueChaine;
	fTypesLogiquesDesParametres [2] = gTypeLogiqueChaine;
	}

DescrSemantiquePTR
RemplacerChainePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{
	return new RemplacerChaine (
		fNom, leBlocDArguments [0], leBlocDArguments [1], leBlocDArguments [2]);
	}


// -------------------------------------------------------------------------

FormaterNombrePredef :: FormaterNombrePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueChaine )
	{
	fNombreDeParametres = 3;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [2] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
FormaterNombrePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{
	return new FormaterNombre (
		fNom, leBlocDArguments [0], leBlocDArguments [1], leBlocDArguments [2]);
	}


// -------------------------------------------------------------------------
//	Operateurs sur les chaines
// -------------------------------------------------------------------------

LongueurChaine :: LongueurChaine (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueNombre, lOperande )
	{}

ValeurLista 
LongueurChaine :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			Nombre (
				fOperande ->
					Evaluer (leContexteDEvaluation).CommeChaine ().length ()
			));
	}

#if defined SYNTHESE_PILUM

void 
LongueurChaine :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iLongueurChaine);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ChaineVide :: ChaineVide (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueBooleen, lOperande )
	{}

ValeurLista 
ChaineVide :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			fOperande -> Evaluer (leContexteDEvaluation).CommeChaine ().empty ()
			);
	}

#if defined SYNTHESE_PILUM

void 
ChaineVide :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iChaineVide);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ContientChaine :: ContientChaine (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
ContientChaine :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeChaine ().
				find (
					fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeChaine (),
					0 )
				!=
			std::string::npos
		);
	}

#if defined SYNTHESE_PILUM

void 
ContientChaine :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iContientChaine);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

ConcatChaines :: ConcatChaines (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueChaine, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
ConcatChaines :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			FConcatChaines (
				fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeChaine (),
				fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeChaine () )
			);
	}

#if defined SYNTHESE_PILUM

void 
ConcatChaines :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iConcatChaines);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

RepliquerChaine :: RepliquerChaine (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueChaine, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
RepliquerChaine :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			FRepliquerChaine (
				fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeChaine (),
				int (
					fOperandeDroit -> 
						Evaluer (leContexteDEvaluation).CommeNombre ()) )
			);
	}

#if defined SYNTHESE_PILUM

void 
RepliquerChaine :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	synth ->
		Zeroadique (iTronquerFlottantEnEntier);
	synth ->
		Zeroadique (iRepliquerChaine);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

RemplacerChaine :: RemplacerChaine (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeMedian,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurTernaire (
		leNom, gTypeLogiqueChaine,
		lOperandeGauche, lOperandeMedian, lOperandeDroit )
	{}

ValeurLista 
RemplacerChaine :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			FRemplacerChaine (
				fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeChaine (),
				fOperandeMedian -> Evaluer (leContexteDEvaluation).CommeChaine (),
				fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeChaine () )
			);
	}

#if defined SYNTHESE_PILUM

void 
RemplacerChaine :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurTernaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iRemplacerChaine);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

FormaterNombre :: FormaterNombre (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeMedian,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurTernaire (
		leNom, gTypeLogiqueChaine, lOperandeGauche, lOperandeMedian, lOperandeDroit )
	{}

ValeurLista 
FormaterNombre :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			FFormaterFlottant (
				fOperandeGauche -> Evaluer (leContexteDEvaluation).CommeNombre (),
				int (fOperandeMedian -> Evaluer (leContexteDEvaluation).CommeNombre ()),
				int (fOperandeDroit -> Evaluer (leContexteDEvaluation).CommeNombre ()) )
			);
	}

#if defined SYNTHESE_PILUM

void 
FormaterNombre :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	fOperandeGauche -> Synthetiser (leContexteDeSynthese);

	fOperandeMedian -> Synthetiser (leContexteDeSynthese);
	synth ->
		Zeroadique (iTronquerFlottantEnEntier);

	fOperandeDroit -> Synthetiser (leContexteDeSynthese);
	synth ->
		Zeroadique (iTronquerFlottantEnEntier);

	synth ->
		Zeroadique (iFormaterFlottant);
	}

#endif /* SYNTHESE_PILUM */
