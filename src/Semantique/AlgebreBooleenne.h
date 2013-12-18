// =========================================================================
//	AlgebreBooleenne.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __AlgebreBooleenne__
#define __AlgebreBooleenne__


#include "OperateursNAires.h"

#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"


// -------------------------------------------------------------------------
//	Logique
// -------------------------------------------------------------------------

class NonPredef : public FonctionPredefinie
	{
public:
										NonPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class EtPredef : public FonctionPredefinie
	{
public:
										EtPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class OuPredef : public FonctionPredefinie
	{
public:
										OuPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};


// -------------------------------------------------------------------------
//	Opérateurs logiques unaires
// -------------------------------------------------------------------------

class Non : public OperateurUnaire
	{
public:
										Non (
											Chaine					leNom,
											DescrSemantiquePTR	lOperande );

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};
	

// -------------------------------------------------------------------------
//	Opérateurs logiques binaires
// -------------------------------------------------------------------------

class Et : public OperateurBinaire
	{
public:
										Et (
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

class Ou : public OperateurBinaire
	{
public:
										Ou (
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
//	Variables globales
// -------------------------------------------------------------------------

extern DescrSemantiquePTR				gValeurVrai;
extern DescrSemantiquePTR				gValeurFaux;


// -------------------------------------------------------------------------
//	Initialisation
// -------------------------------------------------------------------------

void
InitialiserAlgebreBooleenne ();


#endif /* __AlgebreBooleenne__ */

