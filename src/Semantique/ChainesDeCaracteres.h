// =========================================================================
//	ChainesDeCaracteres.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __ChainesDeCaracteres__
#define __ChainesDeCaracteres__


#include "OperateursNAires.h"

#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"


// -------------------------------------------------------------------------
//	Chaines de caracteres
// -------------------------------------------------------------------------

class LongueurChainePredef : public FonctionPredefinie
	{
public:
										LongueurChainePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class ChaineVidePredef : public FonctionPredefinie
	{
public:
										ChaineVidePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class ContientChainePredef : public FonctionPredefinie
	{
public:
										ContientChainePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class ConcatChainesPredef : public FonctionPredefinie
	{
public:
										ConcatChainesPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class RepliquerChainePredef : public FonctionPredefinie
	{
public:
										RepliquerChainePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class RemplacerChainePredef : public FonctionPredefinie
	{
public:
										RemplacerChainePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};


// -------------------------------------------------------------------------

class FormaterNombrePredef : public FonctionPredefinie
	{
public:
										FormaterNombrePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

	

// -------------------------------------------------------------------------

class LongueurChaine : public OperateurUnaire
	{
public:
										LongueurChaine (
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

class ChaineVide : public OperateurUnaire
	{
public:
										ChaineVide (
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
//	Opérateurs binaires sur les chaines
// -------------------------------------------------------------------------

class ContientChaine : public OperateurBinaire
	{
public:
										ContientChaine (
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

class ConcatChaines : public OperateurBinaire
	{
public:
										ConcatChaines (
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

class RepliquerChaine : public OperateurBinaire
	{
public:
										RepliquerChaine (
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

class RemplacerChaine : public OperateurTernaire
	{
public:
										RemplacerChaine (
											Chaine					leNom,
											DescrSemantiquePTR	lOperandeGauche,
											DescrSemantiquePTR	lOperandeMedian,
											DescrSemantiquePTR	lOperandeDroit );

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};


// -------------------------------------------------------------------------

class FormaterNombre : public OperateurTernaire
	{
public:
										FormaterNombre (
											Chaine					leNom,
											DescrSemantiquePTR	lOperandeGauche,
											DescrSemantiquePTR	lOperandeMedian,
											DescrSemantiquePTR	lOperandeDroit );

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};


#endif /* __ChainesDeCaracteres__ */
