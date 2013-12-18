// =========================================================================
//	Si.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __Si__
#define __Si__


#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"


// -------------------------------------------------------------------------
//	SiPredef
// -------------------------------------------------------------------------

class SiPredef : public FonctionPredefinie
	{
public:
										SiPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};


// -------------------------------------------------------------------------
//	Si
// -------------------------------------------------------------------------

class Si : public DescrSemantique
	{
public:
										Si (
											Chaine						leNom,
											DescrSemantiquePTR		laCondition,
											DescrSemantiquePTR		laValeurSiVrai,
											DescrSemantiquePTR		laValeurSiFaux,
											VariableLogiqueTypePTR	leTypeLogique );
	
	virtual void					Ecrire (int lIndentation);
	virtual void					PostFixer ();

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	
private:

	DescrSemantiquePTR			fCondition;
	DescrSemantiquePTR			fValeurSiVrai;
	DescrSemantiquePTR			fValeurSiFaux;

	};	//	Si


#endif /* __Si__ */
