// =========================================================================
//	Arithmetique.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __Arithmetique__
#define __Arithmetique__


#include "OperateursNAires.h"

#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"


// -------------------------------------------------------------------------
// Mathematiques
// -------------------------------------------------------------------------

class ModuloPredef : public FonctionPredefinie
	{
public:
										ModuloPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class HasardPredef : public FonctionPredefinie
	{
public:
										HasardPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class RacinePredef : public FonctionPredefinie
	{
public:
										RacinePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class SinPredef : public FonctionPredefinie
	{
public:
										SinPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class CosPredef : public FonctionPredefinie
	{
public:
										CosPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class ArcTanPredef : public FonctionPredefinie
	{
public:
										ArcTanPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class LogPredef : public FonctionPredefinie
	{
public:
										LogPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class ExpPredef : public FonctionPredefinie
	{
public:
										ExpPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};


// -------------------------------------------------------------------------

class PairPredef : public FonctionPredefinie
	{
public:
										PairPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};


// -------------------------------------------------------------------------
//	Operateurs zeroaires
// -------------------------------------------------------------------------

class Hasard : public OperateurZeroaire
	{
public:
										Hasard (Chaine leNom);

	virtual ValeurLista			Evaluer (ContexteDEvaluationPTR leContexteDEvaluation);

#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};	//	Hasard


// -------------------------------------------------------------------------
//	Opérateurs arithmetiques unaires
// -------------------------------------------------------------------------

class MoinsUnaire : public OperateurUnaire
	{
public:
										MoinsUnaire (
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

class Racine : public OperateurUnaire
	{
public:
										Racine (
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

class Sin : public OperateurUnaire
	{
public:
										Sin (
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

class Cos : public OperateurUnaire
	{
public:
										Cos (
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

class ArcTan : public OperateurUnaire
	{
public:
										ArcTan (
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

class Log : public OperateurUnaire
	{
public:
										Log (
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

class Exp : public OperateurUnaire
	{
public:
										Exp (
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

class Pair : public OperateurUnaire
	{
public:
										Pair (
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
//	Opérateurs arithmetiques binaires
// -------------------------------------------------------------------------

class Plus : public OperateurBinaire
	{
public:
										Plus (
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

class Moins : public OperateurBinaire
	{
public:
										Moins (
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

class Fois : public OperateurBinaire
	{
public:
										Fois (
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
	

class DivisePar : public OperateurBinaire
	{
public:
										DivisePar (
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

class Modulo : public OperateurBinaire
	{
public:
										Modulo (
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

extern DescrSemantiquePTR				gValeurPi;
extern DescrSemantiquePTR				gValeurE;


// -------------------------------------------------------------------------
//	Initialisation
// -------------------------------------------------------------------------

void
InitialiserArithmetique ();


#endif /* __Arithmetique__ */
