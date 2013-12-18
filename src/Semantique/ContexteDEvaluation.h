// =========================================================================
//	ContexteDEvaluation.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __ContexteDEvaluation__
#define __ContexteDEvaluation__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "Types.h"

#include "ParametresFormels.h"



// ------------------------------------------------------------------------
//	ContexteDEvaluation
// ------------------------------------------------------------------------

class		ContexteDEvaluation;
typedef	ContexteDEvaluation	* ContexteDEvaluationPTR;

class ContexteDEvaluation
	{
public:
										ContexteDEvaluation (
											AssocArgumentParametrePTR	* leBlocDAssociations,
											int								leNbDAssociations,
											bool								laTraceDEvaluation,
											bool								leCourtCircuitLogiquesBinaires,
											int								lIndentation,
											ContexteDEvaluationPTR		leLienStatique,
											ContexteDEvaluationPTR		leLienDynamique );

	AssocArgumentParametrePTR	* BlocDAssociations ();
	int								NbDAssociations ();
	
	bool								TraceDEvaluation ();
	bool								CourtCircuitLogiquesBinaires ();

	int								Indentation ();
	long								NumeroContexteDEvaluation ();

	ContexteDEvaluationPTR		LienDynamique ();
	ContexteDEvaluationPTR		LienStatique ();

	void								Ecrire (int lIndentation);

	ContexteDEvaluationPTR		RemonteeStatique (
											int differenceDeNiveauDEvaluation );

protected:

	AssocArgumentParametrePTR	* fBlocDAssociations;
											//	un tableau dynamique
	int								fNbDAssociations;
											//  sa taille

	bool								fTraceDEvaluation;
	bool								fCourtCircuitLogiquesBinaires;

	int								fIndentation;
											//	pour la trace d'exécution
	long								fNumeroContexteDEvaluation;
											//	pour la trace d'exécution
private:
	
	ContexteDEvaluationPTR		fLienStatique;		// lien au contexte d'evaluation
																// contenant la declaration
	ContexteDEvaluationPTR		fLienDynamique;	// lien au pere (chainage de la pile)

	};	//	ContexteDEvaluation


#endif /* __ContexteDEvaluation__ */

