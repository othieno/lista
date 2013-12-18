// =========================================================================
//	ContexteDEvaluation.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "ContexteDEvaluation.h"

#include "AnalyseurSemantiqueLista.h"


// -------------------------------------------------------------------------
//	ContexteDEvaluation
// -------------------------------------------------------------------------

ContexteDEvaluation :: ContexteDEvaluation (
	AssocArgumentParametrePTR	* leBlocDAssociations,
	int								leNbDAssociations,
	bool								laTraceDEvaluation,
	bool								leCourtCircuitLogiquesBinaires,
	int								lIndentation,
	ContexteDEvaluationPTR		leLienStatique,
	ContexteDEvaluationPTR		leLienDynamique )
	{
	fBlocDAssociations = leBlocDAssociations;
	fNbDAssociations = leNbDAssociations;
	
	fTraceDEvaluation = laTraceDEvaluation;
	fCourtCircuitLogiquesBinaires = leCourtCircuitLogiquesBinaires;

	fIndentation = lIndentation;

	fLienStatique			= leLienStatique;
	fLienDynamique			= leLienDynamique;

	fNumeroContexteDEvaluation =
		fLienDynamique
			?	fLienDynamique -> fNumeroContexteDEvaluation + 1
			:	0 ;
	}	// ContexteDEvaluation :: ContexteDEvaluation


AssocArgumentParametrePTR * 
ContexteDEvaluation :: BlocDAssociations ()
	{ return fBlocDAssociations; }

int 
ContexteDEvaluation :: NbDAssociations ()
	{ return fNbDAssociations; }

bool 
ContexteDEvaluation :: TraceDEvaluation ()
	{ return fTraceDEvaluation; }

bool 
ContexteDEvaluation :: CourtCircuitLogiquesBinaires ()
	{ return fCourtCircuitLogiquesBinaires; }

int 
ContexteDEvaluation :: Indentation ()
	{ return fIndentation; }

long 
ContexteDEvaluation :: NumeroContexteDEvaluation ()
	{ return fNumeroContexteDEvaluation; }

ContexteDEvaluationPTR 
ContexteDEvaluation :: LienDynamique ()
	{ return fLienDynamique; }
ContexteDEvaluationPTR 
ContexteDEvaluation :: LienStatique ()
	{ return fLienStatique; }

void 
ContexteDEvaluation :: Ecrire (int lIndentation)
	{
	ContexteDEvaluationPTR
				curseur = this;

	while (curseur != NULL)
		{
		Indenter (lIndentation);
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatContexteDEvaluation (),
				curseur -> fNumeroContexteDEvaluation,
				curseur -> fNbDAssociations ) <<
			std::endl;
		
		for (int i = 0; i < curseur -> fNbDAssociations; i ++)
			curseur -> fBlocDAssociations [i] -> Ecrire (lIndentation + 1);

//		curseur -> Ecrire (lIndentation); JMI
		curseur = curseur -> fLienDynamique;
		}   // while
	}   // ContexteDEvaluation :: Ecrire


ContexteDEvaluationPTR 
ContexteDEvaluation :: RemonteeStatique (
	int differenceDeNiveauDEvaluation)
	{
	if (fTraceDEvaluation)
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatRemonteeStatique (),
				gAnalyseurSemantiqueLista ->
					NiveauDEvaluationCourant (),
				differenceDeNiveauDEvaluation ) << 
			std::endl;

	ContexteDEvaluationPTR
				leContexteDEvaluation = this;

	while (differenceDeNiveauDEvaluation > 0)
		{
		leContexteDEvaluation =
			leContexteDEvaluation -> fLienStatique;
		--	differenceDeNiveauDEvaluation;
		}

	return leContexteDEvaluation;
	}	// ContexteDEvaluation :: RemonteeStatique
