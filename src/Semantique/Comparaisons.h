// =========================================================================
//	Comparaisons.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __Comparaisons__
#define __Comparaisons__


#include "OperateursNAires.h"

#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"


// -------------------------------------------------------------------------
// Comparaisons
// -------------------------------------------------------------------------

class EgalePredef : public FonctionPredefinie
	{
public:
										EgalePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class DifferentPredef : public FonctionPredefinie
	{
public:
										DifferentPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class InfPredef : public FonctionPredefinie
	{
public:
										InfPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class SupPredef : public FonctionPredefinie
	{
public:
										SupPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class InfEgalePredef : public FonctionPredefinie
	{
public:
										InfEgalePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class SupEgalePredef : public FonctionPredefinie
	{
public:
										SupEgalePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};


// -------------------------------------------------------------------------
//	Opérateurs de comparaison
// -------------------------------------------------------------------------

class Inf : public OperateurBinaire
	{
public:
										Inf (
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

class Egale : public OperateurBinaire
	{
public:
										Egale (
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

class Sup : public OperateurBinaire
	{
public:
										Sup (
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

class InfEgale : public OperateurBinaire
	{
public:
										InfEgale (
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

class SupEgale : public OperateurBinaire
	{
public:
										SupEgale (
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

class Different : public OperateurBinaire
	{
public:
										Different (
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


#endif /* __Comparaisons__ */

