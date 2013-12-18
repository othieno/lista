// =========================================================================
//	Sequencements.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __Sequencements__
#define __Sequencements__


#include "OperateursNAires.h"

#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"


// -------------------------------------------------------------------------
//	SequenceurPredef
// -------------------------------------------------------------------------

class		SequenceurPredef;
typedef	SequenceurPredef		* SequenceurPredefPTR;
	
class SequenceurPredef : public FonctionPredefinie
	{
public:
										SequenceurPredef (
											ChaineLanguePredefinisPFM
																			laFonctionNom,
											VariableLogiqueTypePTR	laVariableLogiqueType );
	};


// -------------------------------------------------------------------------
//	Les sequenceurs predefinis
// -------------------------------------------------------------------------

class SeqPredef : public SequenceurPredef
	{
public:
										SeqPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class Seq1Predef : public SequenceurPredef
	{
public:
										Seq1Predef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};
// -------------------------------------------------------------------------
//	Sequencement
// -------------------------------------------------------------------------

class Seq : public OperateurBinaire
	{
public:
										Seq (
											Chaine					leNom,
											DescrSemantiquePTR	lOperandeGauche,
											DescrSemantiquePTR	lOperandeDroit );

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};

// -------------------------------------------------------------------------

class Seq1 : public OperateurBinaire
	{
public:
										Seq1 (
											Chaine					leNom,
											DescrSemantiquePTR	lOperandeGauche,
											DescrSemantiquePTR	lOperandeDroit );

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};


#endif /* __Sequencements__ */
