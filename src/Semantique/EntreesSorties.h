// =========================================================================
//	EntreesSorties.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __EntreesSorties__
#define __EntreesSorties__


#include "OperateursNAires.h"

#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"


// -------------------------------------------------------------------------
//	Lectures
// -------------------------------------------------------------------------

class LireNombrePredef : public FonctionPredefinie
	{
public:
										LireNombrePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class LireBooleenPredef : public FonctionPredefinie
	{
public:
										LireBooleenPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class LireChainePredef : public FonctionPredefinie
	{
public:
										LireChainePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};


// -------------------------------------------------------------------------
//	Ecritures
// -------------------------------------------------------------------------

class EcrireNombrePredef : public FonctionPredefinie
	{
public:
										EcrireNombrePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class EcrireBooleenPredef : public FonctionPredefinie
	{
public:
										EcrireBooleenPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class EcrireChainePredef : public FonctionPredefinie
	{
public:
										EcrireChainePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class EcrireFinDeLignePredef : public FonctionPredefinie
	{
public:
										EcrireFinDeLignePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );
	};


// -------------------------------------------------------------------------
//	Lectures
// -------------------------------------------------------------------------

class LireNombre : public OperateurUnaire
	{
public:
										LireNombre (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											Chaine						leNom,
											DescrSemantiquePTR		lOperande );

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	GenreLectureAuClavier		fGenreLectureAuClavier;
	};	//	LireNombre
	
// -------------------------------------------------------------------------

class LireBooleen : public OperateurBinaire
	{
public:
										LireBooleen (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											Chaine						leNom,
											DescrSemantiquePTR		lOperandeGauche,
											DescrSemantiquePTR		lOperandeDroit );

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	GenreLectureAuClavier		fGenreLectureAuClavier;
	};	//	LireBooleen

// -------------------------------------------------------------------------

class LireChaine : public OperateurUnaire
	{
public:
										LireChaine (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											Chaine						leNom,
											DescrSemantiquePTR		lOperande );

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	GenreLectureAuClavier		fGenreLectureAuClavier;
	};	//	LireChaine



// -------------------------------------------------------------------------
//	Ecritures
// -------------------------------------------------------------------------

class EcrireNombre : public OperateurUnaire
	{
public:
										EcrireNombre (
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

class EcrireBooleen : public OperateurUnaire
	{
public:
										EcrireBooleen (
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

class EcrireChaine : public OperateurUnaire
	{
public:
										EcrireChaine (
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

class EcrireFinDeLigne : public OperateurZeroaire
	{
public:
										EcrireFinDeLigne (Chaine leNom);

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};	//	EcrireFinDeLigne


#endif /* __EntreesSorties__ */

