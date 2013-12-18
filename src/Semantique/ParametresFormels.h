//	ParametresFormels.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __ParametresFormels__
#define __ParametresFormels__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "ValeurLista.h"

#include "Identificateur.h"

#include "DescrSemantique.h"

#include "StrategiesDEvaluation.h"


// -------------------------------------------------------------------------
//	ParametreFormel
// -------------------------------------------------------------------------

class		ParametreFormel;
typedef	ParametreFormel		* ParametreFormelPTR;
	
class ParametreFormel : public Identificateur
	{
public:
										ParametreFormel (
											Chaine						leNom,
											Chaine						leNomQualifie,
											VariableLogiqueTypePTR	laVariableLogiqueType,
											DescrParametrePTR			laDescrParametre,
											int							leNiveauDEvaluation );

	virtual Chaine					SousFormeDeChaine ();

	DescrParametrePTR				DescrParametre ();

	int								NiveauDEvaluation ();
	
private:

	DescrParametrePTR				fDescrParametre;

	int								fNiveauDEvaluation;
	};	//	ParametreFormel


// -------------------------------------------------------------------------
//	DescrParametre
// -------------------------------------------------------------------------

class DescrParametre
	{
public:
										DescrParametre (
											int							leNumeroDeParametre,
											StrategieDEvaluationPTR	laStrategieDEvaluation );
											//	"fParametreFormel" doit etre mis a jour plus tard
											//	a cause de la dependance mutuelle

	virtual							~ DescrParametre ();

	void								ParametreFormel (
											ParametreFormelPTR leParametreFormel );
											// pour mise a jour de "fParametreFormel" 
											//	apres construction
	ParametreFormelPTR			ParametreFormel ();

	int								NumeroDeParametre ();
	StrategieDEvaluationPTR		StrategieDEvaluation ();

	int								NiveauDEvaluation ();
	int								NiveauStatique ();


	virtual AssocArgumentParametrePTR
										CreerAssocArgumentParametre (
											DescrSemantiquePTR		lArgumentDAppel,
											ContexteDEvaluationPTR	leContexteDEvaluation
											) = 0;
											//	virtuelle pure

#if defined SYNTHESE_PILUM
	virtual int						TailleEnMemoire () = 0;
											//	virtuelle pure

	void								PositionDansLeBloc (long laPosition);
	long								PositionDansLeBloc ();

	virtual void					Synthetiser (
											ContexteDeSynthesePTR	leContexteSynth,
											DescrSemantiquePTR		lArgumentDAppel ) = 0;
											//	virtuelle pure
#endif /* SYNTHESE_PILUM */


protected:

	ParametreFormelPTR			fParametreFormel;
											//	référence croisée, mise à jour après-coup

	int								fNumeroDeParametre;
	StrategieDEvaluationPTR		fStrategieDEvaluation;	

	int								fNiveauDEvaluation;
	int								fNiveauStatique;

#if defined SYNTHESE_PILUM
	long								fPositionDansLeBloc;
#endif /* SYNTHESE_PILUM */

	};	//	DescrParametre


typedef std::vector <DescrParametrePTR>	ListeDesDescrParametres;
typedef ListeDesDescrParametres				* ListeDesDescrParametresPTR;


// ------------------------------------------------------------------------
//	AssocArgumentParametre
// ------------------------------------------------------------------------

class		AssocArgumentParametre;
typedef	AssocArgumentParametre	* AssocArgumentParametrePTR;

class AssocArgumentParametre
	{
public:
										AssocArgumentParametre (
											Chaine						leNom,
											Chaine						leNomQualifie,
											int							leNumeroDeParametre,
											ContexteDEvaluationPTR	leContexteDEvaluation );

	virtual							~ AssocArgumentParametre ();

	Chaine							Nom ();
	int								NumeroDeParametre ();
	ContexteDEvaluationPTR		ContexteDEvaluation ();

	virtual void					Ecrire (int lIndentation) = 0;
											//	virtuelle pure

	virtual ValeurLista			Evaluer (int lIndentation) = 0;
											//	virtuelle pure

protected:

	Chaine							fNom;
	Chaine							fNomQualifie;

	int								fNumeroDeParametre;
	ContexteDEvaluationPTR		fContexteDEvaluation;

	};	//	AssocArgumentParametre


// ------------------------------------------------------------------------
//	AssocArgumentParametreParValeur
// ------------------------------------------------------------------------

class		AssocArgumentParametreParValeur;
typedef	AssocArgumentParametreParValeur	* AssocArgumentParametreParValeurPTR;

class AssocArgumentParametreParValeur : public AssocArgumentParametre
{
public:
										AssocArgumentParametreParValeur (
											Chaine						leNom,
											Chaine						leNomQualifie,
											int							leNumeroDeParametre,
											ContexteDEvaluationPTR	leContexteDEvaluation,
											ValeurLista					laValeur );

	virtual							~ AssocArgumentParametreParValeur ();

	virtual void					Ecrire (int lIndentation);

	virtual ValeurLista			Evaluer (int lIndentation);

protected:

	ValeurLista						fValeur;

	};	//	AssocArgumentParametreParValeur


// ------------------------------------------------------------------------
//	AssocArgumentParametreParNom
// ------------------------------------------------------------------------

class		AssocArgumentParametreParNom;
typedef	AssocArgumentParametreParNom	* AssocArgumentParametreParNomPTR;

class AssocArgumentParametreParNom : public AssocArgumentParametre
	{
public:
										AssocArgumentParametreParNom (
											Chaine							leNom,
											Chaine							leNomQualifie,
											int								leNumeroDeParametre,
											DescrSemantiquePTR			leGrapheSemantique,
											ContexteDEvaluationPTR		leContexteDEvaluation );

	virtual							~ AssocArgumentParametreParNom ();

	virtual void					Ecrire (int lIndentation);

	virtual ValeurLista			Evaluer (int lIndentation);

protected:

	DescrSemantiquePTR			fGrapheSemantique;

	};	//	AssocArgumentParametreParNom


// ------------------------------------------------------------------------
//	AssocArgumentParametreParBesoin
// ------------------------------------------------------------------------

class		AssocArgumentParametreParBesoin;
typedef	AssocArgumentParametreParBesoin	* AssocArgumentParametreParBesoinPTR;

class AssocArgumentParametreParBesoin : public AssocArgumentParametre
	{
public:
										AssocArgumentParametreParBesoin (
											Chaine						leNom,
											Chaine						leNomQualifie,
											int							leNumeroDeParametre,
											DescrSemantiquePTR		leGrapheSemantique,
											ContexteDEvaluationPTR	leContexteDEvaluation );

	virtual							~ AssocArgumentParametreParBesoin ();

	virtual void					Ecrire (int lIndentation);

	virtual ValeurLista			Evaluer (int lIndentation);

protected:

	DescrSemantiquePTR			fGrapheSemantique;
	
	bool								fValeurDisponible;
	ValeurLista						fValeur;

	};	//	AssocArgumentParametreParBesoin


// -------------------------------------------------------------------------
//	DescrParametreParValeur
// -------------------------------------------------------------------------

class		DescrParametreParValeur;
typedef	DescrParametreParValeur		* DescrParametreParValeurPTR;

class DescrParametreParValeur : public DescrParametre
	{
public:
										DescrParametreParValeur (
											int		leNumeroDeParametre );

	virtual							~ DescrParametreParValeur ();

	virtual AssocArgumentParametrePTR
										CreerAssocArgumentParametre (
											DescrSemantiquePTR		lArgumentDAppel,
											ContexteDEvaluationPTR	leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual int						TailleEnMemoire ();

	virtual void					Synthetiser (
											ContexteDeSynthesePTR	leContexteDeSynthese,
											DescrSemantiquePTR		lArgumentDAppel );
#endif /* SYNTHESE_PILUM */
	};	//	DescrParametreParValeur


// -------------------------------------------------------------------------
//	DescrParametreParNom
// -------------------------------------------------------------------------

class		DescrParametreParNom;
typedef	DescrParametreParNom	* DescrParametreParNomPTR;

class DescrParametreParNom : public DescrParametre
	{
	public:
										DescrParametreParNom (
											int		leNumeroDeParametre );

	virtual							~ DescrParametreParNom ();

	virtual AssocArgumentParametrePTR
										CreerAssocArgumentParametre (
											DescrSemantiquePTR		lArgumentDAppel,
											ContexteDEvaluationPTR	leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual int						TailleEnMemoire ();

	virtual void					Synthetiser (
											ContexteDeSynthesePTR	leContexteDeSynthese,
											DescrSemantiquePTR		lArgumentDAppel );
#endif /* SYNTHESE_PILUM */
	};	//	DescrParametreParNom


// -------------------------------------------------------------------------
//	DescrParametreParBesoin
// -------------------------------------------------------------------------

class		DescrParametreParBesoin;
typedef	DescrParametreParBesoin
										* DescrParametreParBesoinPTR;

class DescrParametreParBesoin : public DescrParametre
	{
public:
										DescrParametreParBesoin (
											int		leNumeroDeParametre );

	virtual							~ DescrParametreParBesoin ();

	virtual AssocArgumentParametrePTR
										CreerAssocArgumentParametre (
											DescrSemantiquePTR		lArgumentDAppel,
											ContexteDEvaluationPTR	leContexteDEvaluation );
#if defined SYNTHESE_PILUM
	virtual int						TailleEnMemoire ();

	virtual void					Synthetiser (
											ContexteDeSynthesePTR	leContexteDeSynthese,
											DescrSemantiquePTR		lArgumentDAppel );
#endif /* SYNTHESE_PILUM */
	};	//	DescrParametreParBesoin


// -------------------------------------------------------------------------
//	ListeDeParametresFormels
// -------------------------------------------------------------------------

class		ListeDeParametresFormels;
typedef	ListeDeParametresFormels	* ListeDeParametresFormelsPTR;

class ListeDeParametresFormels
	{
public:
										ListeDeParametresFormels ();
										~ ListeDeParametresFormels ();
	
	ListeDesDescrParametresPTR	LaListeDesDescrParametres ();

	bool								Vide ();

	void								Ajouter (DescrParametrePTR leParametre);
	int								NombreDeParametres ();

	Chaine							NomsDesParametres ();
	Chaine							ProfilDesParametres ();

#if defined SYNTHESE_PILUM

	void								AllouerLesParametres (int positionDeDepart);
	int								TailleDesParametres ();

#endif /* SYNTHESE_PILUM */


private:

	ListeDesDescrParametres		fListeDesDescrParametres;

#if defined SYNTHESE_PILUM

	int								fTailleDesParametres;

	int								EffectuerAllocation (
											ListeDesDescrParametres :: iterator		parametreCourant,
											int												positionDeDepart,
											int												& tailleAccumulee );
#endif /* SYNTHESE_PILUM */

	};	//	ListeDeParametresFormels


// -------------------------------------------------------------------------
//	EmploiParametre
// -------------------------------------------------------------------------

class		EmploiParametre;
typedef	EmploiParametre				* EmploiParametrePTR;

class EmploiParametre : public DescrSemantique
	{
public:
										EmploiParametre (
											ParametreFormelPTR	leParametreFormel );
	
	virtual void					Ecrire (int lIndentation) ;

	virtual ValeurLista			Evaluer (
											ContexteDEvaluationPTR leContexteDEvaluation );

protected:

	ParametreFormelPTR			fParametreFormel;

	int								fNiveauDEvaluation;
	int								fNiveauStatique;
	};	//	EmploiParametre
	

// -------------------------------------------------------------------------

class EmploiParametreParValeur : public EmploiParametre
	{
public:
										EmploiParametreParValeur (
											ParametreFormelPTR 	leParametreFormel );

#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};
	
// -------------------------------------------------------------------------

class EmploiParametreParNom : public EmploiParametre
	{
public:
										EmploiParametreParNom (
											ParametreFormelPTR 	leParametreFormel );

#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};
	
// -------------------------------------------------------------------------

class EmploiParametreParBesoin : public EmploiParametre
	{
public:
										EmploiParametreParBesoin (
											ParametreFormelPTR 	leParametreFormel );

#if defined SYNTHESE_PILUM
	virtual void					Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
	};


#endif /* __ParametresFormels__ */
