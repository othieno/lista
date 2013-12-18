// =========================================================================
//	Iterations.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __Iterations__
#define __Iterations__


#include "Identificateur.h"

#include "ParametresFormels.h"

#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"


// -------------------------------------------------------------------------
//	IndiceIteration
// -------------------------------------------------------------------------

class		IndiceIteration;
typedef	IndiceIteration		* IndiceIterationPTR;
	
class IndiceIteration : public Identificateur
	{
public:
										IndiceIteration (
											Chaine						leNom,
											Chaine						leNomQualifie,
											VariableLogiqueTypePTR	laVariableLogiqueType );

	virtual Chaine					SousFormeDeChaine ();

	int								NiveauDEvaluation ();
	int								NiveauStatique ();
#if defined SYNTHESE_PILUM
	void								PositionDansLeBloc (long laPosition);
	long								PositionDansLeBloc ();
#endif /* SYNTHESE_PILUM */
	
private:

	int								fNiveauDEvaluation;
	int								fNiveauStatique;
#if defined SYNTHESE_PILUM
	long								fPositionDansLeBloc;
#endif /* SYNTHESE_PILUM */
	};	//	IndiceIteration


// -------------------------------------------------------------------------
//	IterateurPredef
// -------------------------------------------------------------------------

class		IterateurPredef;
typedef	IterateurPredef		* IterateurPredefPTR;
	
class IterateurPredef : public FonctionPredefinie
	{
public:
										IterateurPredef (
											ChaineLanguePredefinisPFM
																			laFonctionNom,
											VariableLogiqueTypePTR	laVariableLogiqueType );

	virtual void					TesterTypeExpressionIteree (
											VariableLogiqueTypePTR	leTypeLogiqueTrouve ) = 0;
											// virtuelle pure

	virtual DescrSemantiquePTR	CreerGrapheIteration (
											IndiceIterationPTR	lIndice,
											DescrSemantiquePTR	* leBlocDArguments ) = 0;
											// virtuelle pure

	virtual Chaine					SousFormeDeChaine ();
	};


// -------------------------------------------------------------------------
//	Les iterateurs predefinis
// -------------------------------------------------------------------------

class SommePredef : public IterateurPredef
	{
public:
										SommePredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );

	virtual void					TesterTypeExpressionIteree (
											VariableLogiqueTypePTR	leTypeLogiqueTrouve );

	virtual DescrSemantiquePTR	CreerGrapheIteration (
											IndiceIterationPTR	lIndice,
											DescrSemantiquePTR	* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class ProduitPredef : public IterateurPredef
	{
public:
										ProduitPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );

	virtual void					TesterTypeExpressionIteree (
											VariableLogiqueTypePTR	leTypeLogiqueTrouve );

	virtual DescrSemantiquePTR	CreerGrapheIteration (
											IndiceIterationPTR	lIndice,
											DescrSemantiquePTR	* leBlocDArguments );
	};

// -------------------------------------------------------------------------

class PourPredef : public IterateurPredef
	{
public:
										PourPredef (
											ChaineLanguePredefinisPFM
													laFonctionNom );

	virtual DescrSemantiquePTR	CreerGrapheDAppelALaFonction (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											DescrSemantiquePTR		* leBlocDArguments );

	virtual void					TesterTypeExpressionIteree (
											VariableLogiqueTypePTR	leTypeLogiqueTrouve );

	virtual DescrSemantiquePTR	CreerGrapheIteration (
											IndiceIterationPTR	lIndice,
											DescrSemantiquePTR	* leBlocDArguments );
	};


// --------------------------------------------------------------------------
//	AssocArgumentParametreIndiceIteration
// --------------------------------------------------------------------------

class		AssocArgumentParametreIndiceIteration;
typedef	AssocArgumentParametreIndiceIteration
										* AssocArgumentParametreIndiceIterationPTR;

class AssocArgumentParametreIndiceIteration : public AssocArgumentParametre
	{
public:

										AssocArgumentParametreIndiceIteration (
											IndiceIterationPTR		lIndiceIteration,
											ContexteDEvaluationPTR	leContexteDEvaluation,
											ValeurLista					laValeurInitiale );

	virtual							~ AssocArgumentParametreIndiceIteration ();

	ValeurLista						ValeurCourante ();
	void								Incrementer ();

	virtual void					Ecrire (int lIndentation);

	virtual ValeurLista			Evaluer (int lIndentation);

protected:

	ValeurLista						fValeurIndice;
	
	};	//	AssocArgumentParametreIndiceIteration


// -------------------------------------------------------------------------
//	EmploiIndiceIteration
// -------------------------------------------------------------------------

class EmploiIndiceIteration : public DescrSemantique
	{
public:

										EmploiIndiceIteration (
											IndiceIterationPTR	lIndiceIteration );
	
	int								NiveauDEvaluation ();

	virtual void					Ecrire (int lIndentation);

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	
protected:

	IndiceIterationPTR			fIndiceIteration;

	int								fNiveauDEvaluation;
	int								fNiveauStatique;
	};	//	EmploiIndiceIteration
	

// -------------------------------------------------------------------------
//	Iteration
// -------------------------------------------------------------------------

enum	GenreIteration
	{ kIterSomme,			kIterProduit,			kIterPour };


class Iteration : public DescrSemantique
	{
public:
										Iteration (
											Chaine						leSousFormeTexte,
											IndiceIterationPTR		lIndice,
											DescrSemantiquePTR		laBorneInf,
											DescrSemantiquePTR		laBorneSup,
											DescrSemantiquePTR		lExpression,
											VariableLogiqueTypePTR	leTypeLogique,
											int							leNiveauDEvaluation );

	virtual void					Ecrire (int lIndentation);
	virtual void					PostFixer ();

	int								NiveauDEvaluation ();

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );

	virtual void					ActionAvantEvaluations () = 0;
											//	virtuelle pure
	virtual void					ActionAChaqueEvaluation (
											ContexteDEvaluationPTR leContexteDEvaluation ) = 0;
											//	virtuelle pure
	virtual void					ActionApresEvaluations () = 0;
											//	virtuelle pure

#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );

	virtual void					ActionAvantSyntheses (
											ContexteDeSynthesePTR leContexteDeSynthese  ) = 0;
											//	virtuelle pure

	virtual void					ActionAvantChaqueSynthese (
											ContexteDeSynthesePTR leContexteDeSynthese  ) = 0;
											//	virtuelle pure
	virtual void					ActionApresChaqueSynthese (
											ContexteDeSynthesePTR leContexteDeSynthese  ) = 0;
											//	virtuelle pure

	virtual void					ActionApresSyntheses (
											ContexteDeSynthesePTR leContexteDeSynthese  ) = 0;
											//	virtuelle pure
#endif /* SYNTHESE_PILUM */

protected:

	Chaine							fSousFormeTexte;

	IndiceIterationPTR			fIndice;
	DescrSemantiquePTR			fBorneInf;
	DescrSemantiquePTR			fBorneSup;
	DescrSemantiquePTR			fExpression;

	int								fNiveauDEvaluation;

	ValeurLista						fResultat;
											//	communication entre methodes d'évaluation

	};	//	Iteration
	

// -------------------------------------------------------------------------
//	Somme
// -------------------------------------------------------------------------

class Somme : public Iteration
	{
public:
										Somme (
											Chaine					leNom,
											IndiceIterationPTR	lIndice,
											DescrSemantiquePTR	laBorneInf,
											DescrSemantiquePTR	laBorneSup,
											DescrSemantiquePTR	lExpression,
											int						leNiveauDEvaluation );

	virtual void					ActionAvantEvaluations ();
	virtual void					ActionAChaqueEvaluation (
											ContexteDEvaluationPTR leContexteDEvaluation );
	virtual void					ActionApresEvaluations ();

#if defined SYNTHESE_PILUM
	virtual void					ActionAvantSyntheses (
											ContexteDeSynthesePTR leContexteDeSynthese  );

	virtual void					ActionAvantChaqueSynthese (
											ContexteDeSynthesePTR leContexteDeSynthese  );
	virtual void					ActionApresChaqueSynthese (
											ContexteDeSynthesePTR leContexteDeSynthese  );

	virtual void					ActionApresSyntheses (
											ContexteDeSynthesePTR leContexteDeSynthese  );
#endif /* SYNTHESE_PILUM */

private:

	Nombre							fSomme;
#if defined SYNTHESE_PILUM
	int								fPositionSomme;
#endif /* SYNTHESE_PILUM */

	};	//	Somme
	

// -------------------------------------------------------------------------
//	Produit
// -------------------------------------------------------------------------

class Produit : public Iteration
	{
public:
										Produit (
											Chaine					leNom,
											IndiceIterationPTR	lIndice,
											DescrSemantiquePTR	laBorneInf,
											DescrSemantiquePTR	laBorneSup,
											DescrSemantiquePTR	lExpression,
											int						leNiveauDEvaluation );

	virtual void					ActionAvantEvaluations ();
	virtual void					ActionAChaqueEvaluation (
											ContexteDEvaluationPTR leContexteDEvaluation );
	virtual void					ActionApresEvaluations ();

#if defined SYNTHESE_PILUM
	virtual void					ActionAvantSyntheses (
											ContexteDeSynthesePTR leContexteDeSynthese  );

	virtual void					ActionAvantChaqueSynthese (
											ContexteDeSynthesePTR leContexteDeSynthese  );
	virtual void					ActionApresChaqueSynthese (
											ContexteDeSynthesePTR leContexteDeSynthese  );

	virtual void					ActionApresSyntheses (
											ContexteDeSynthesePTR leContexteDeSynthese  );
#endif /* SYNTHESE_PILUM */

private:

	Nombre							fProduit;
#if defined SYNTHESE_PILUM
	int								fPositionProduit;
#endif /* SYNTHESE_PILUM */
	
	};	//	Produit
	

// -------------------------------------------------------------------------
//	Pour
// -------------------------------------------------------------------------

class Pour : public Iteration
	{
public:
										Pour (
											Chaine					leNom,
											IndiceIterationPTR	lIndice,
											DescrSemantiquePTR	laBorneInf,
											DescrSemantiquePTR	laBorneSup,
											DescrSemantiquePTR	lExpression,
											int						leNiveauDEvaluation );

	virtual void					ActionAvantEvaluations ();
	virtual void					ActionAChaqueEvaluation (
											ContexteDEvaluationPTR leContexteDEvaluation );
	virtual void					ActionApresEvaluations ();

#if defined SYNTHESE_PILUM
	virtual void					ActionAvantSyntheses (
											ContexteDeSynthesePTR leContexteDeSynthese  );

	virtual void					ActionAvantChaqueSynthese (
											ContexteDeSynthesePTR leContexteDeSynthese  );
	virtual void					ActionApresChaqueSynthese (
											ContexteDeSynthesePTR leContexteDeSynthese  );

	virtual void					ActionApresSyntheses (
											ContexteDeSynthesePTR leContexteDeSynthese  );
#endif /* SYNTHESE_PILUM */
	};	//	Pour


#endif /* __Iterations__ */
