// =========================================================================
//	AlgebreBooleenne.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "AlgebreBooleenne.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Operateurs logiques
// -------------------------------------------------------------------------

Non :: Non (
	Chaine					leNom,
	DescrSemantiquePTR	lOperande )
	: OperateurUnaire ( leNom, gTypeLogiqueBooleen, lOperande )
	{}

ValeurLista 
Non :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		ValeurLista (
			bool (
				!
					fOperande ->
						Evaluer (leContexteDEvaluation).CommeBooleen ()) );
	}

#if defined SYNTHESE_PILUM

void 
Non :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iNon);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Et :: Et (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Et :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	if (! leContexteDEvaluation -> CourtCircuitLogiquesBinaires ())
		{
		// cas  strict
		bool		valeurOperandeGauche =
						fOperandeGauche -> 
							Evaluer (leContexteDEvaluation).CommeBooleen ();
		bool		valeurOperandeDroit =
						fOperandeDroit -> 
							Evaluer (leContexteDEvaluation).CommeBooleen ();
	
		return
			ValeurLista (
				bool (valeurOperandeGauche && valeurOperandeDroit) );
		}

	else // cas non strict
		return
			ValeurLista (
				bool (
					fOperandeGauche -> 
						Evaluer (leContexteDEvaluation).CommeBooleen ()
						&&
					fOperandeDroit -> 
						Evaluer (leContexteDEvaluation).CommeBooleen () ));

	}	//	Et :: Evaluer

#if defined SYNTHESE_PILUM

void 
Et :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iEt);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Ou :: Ou (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
		leNom, gTypeLogiqueBooleen, lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Ou :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	if (! leContexteDEvaluation -> CourtCircuitLogiquesBinaires ())
		{
		bool		valeurOperandeGauche =
						fOperandeGauche -> 
							Evaluer (leContexteDEvaluation).CommeBooleen ();
		bool		valeurOperandeDroit =
						fOperandeDroit -> 
							Evaluer (leContexteDEvaluation).CommeBooleen ();
	
		return
			ValeurLista (bool (valeurOperandeGauche || valeurOperandeDroit ));
		}

	else
		return
			ValeurLista (
				bool (
					fOperandeGauche -> 
						Evaluer (leContexteDEvaluation).CommeBooleen ()
						||
					fOperandeDroit -> 
						Evaluer (leContexteDEvaluation).CommeBooleen () ));

	}	//	Ou :: Evaluer

#if defined SYNTHESE_PILUM

void 
Ou :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	OperateurBinaire :: Synthetiser (leContexteDeSynthese);

	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iOu);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Logique
// -------------------------------------------------------------------------

NonPredef :: NonPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 1;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueBooleen;
	}

DescrSemantiquePTR
NonPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Non (fNom, leBlocDArguments [0]); }

// -------------------------------------------------------------------------

EtPredef :: EtPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueBooleen;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueBooleen;
	}

DescrSemantiquePTR
EtPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Et (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

OuPredef :: OuPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kAutreFonctionPredefinie, kAutreIdentificateurFlexBison,
		gTypeLogiqueBooleen )
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueBooleen;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueBooleen;
	}

DescrSemantiquePTR
OuPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Ou (fNom, leBlocDArguments [0], leBlocDArguments [1]); }


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

DescrSemantiquePTR				gValeurVrai = NULL;
DescrSemantiquePTR				gValeurFaux = NULL;


// -------------------------------------------------------------------------
//	Initialisation
// -------------------------------------------------------------------------

void
InitialiserAlgebreBooleenne ()
	{
	gValeurVrai						= new ValeurLogique (true);
	gValeurFaux						= new ValeurLogique (false);
	}
