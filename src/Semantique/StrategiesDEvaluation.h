// =========================================================================
//	StrategiesDEvaluation.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __StrategiesDEvaluation__
#define __StrategiesDEvaluation__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "Types.h"


// -------------------------------------------------------------------------
//	StrategieDEvaluation
// -------------------------------------------------------------------------

class		StrategieDEvaluation;
typedef	StrategieDEvaluation	* StrategieDEvaluationPTR;

class StrategieDEvaluation
	{
public:
										StrategieDEvaluation ();

	virtual							~ StrategieDEvaluation ();

	virtual Chaine					SousFormeDeChaine () = 0;
											//	virtuelle pure

	virtual bool					ABesoinDUnLienStatique () = 0;
											//	virtuelle pure

	virtual DescrParametrePTR	CreerDescrParametre (
											FonctionUtilisateurPTR	laFonctionUtilisateur,
											int							leNumeroDeParametre ) = 0;
												//	virtuelle pure

	virtual EmploiParametrePTR CreerEmploiParametre (
											ParametreFormelPTR 	leParametreFormel ) = 0;
												//	virtuelle pure

#if defined SYNTHESE_PILUM
	virtual Chaine					SuffixeFichiersBinaires () = 0;
#endif /* SYNTHESE_PILUM */

	};	//	StrategieDEvaluation


// -------------------------------------------------------------------------
//	StrategieParValeur
// -------------------------------------------------------------------------

class		StrategieParValeur;
typedef	StrategieParValeur	* StrategieParValeurPTR;

class StrategieParValeur : public StrategieDEvaluation
	{
public:
										StrategieParValeur ();

	Chaine							SousFormeDeChaine ();

	bool								ABesoinDUnLienStatique ();

	DescrParametrePTR				CreerDescrParametre (
											FonctionUtilisateurPTR	laFonctionUtilisateur,
											int							leNumeroDeParametre );

	EmploiParametrePTR			CreerEmploiParametre (
											ParametreFormelPTR 	leParametreFormel );

#if defined SYNTHESE_PILUM
	Chaine							SuffixeFichiersBinaires ();
#endif /* SYNTHESE_PILUM */

	};	//	StrategieParValeur


// -------------------------------------------------------------------------
//	StrategieParNom
// -------------------------------------------------------------------------

class		StrategieParNom;
typedef	StrategieParNom		* StrategieParNomPTR;

class StrategieParNom : public StrategieDEvaluation
	{
public:
										StrategieParNom ();

	Chaine							SousFormeDeChaine ();

	bool								ABesoinDUnLienStatique ();

	DescrParametrePTR				CreerDescrParametre (
											FonctionUtilisateurPTR	laFonctionUtilisateur,
											int							leNumeroDeParametre );

	EmploiParametrePTR			CreerEmploiParametre (
											ParametreFormelPTR 	leParametreFormel );

#if defined SYNTHESE_PILUM
	Chaine							SuffixeFichiersBinaires ();
#endif /* SYNTHESE_PILUM */

	};	//	StrategieParNom


// -------------------------------------------------------------------------
//	StrategieParBesoin
// -------------------------------------------------------------------------

class		StrategieParBesoin;
typedef	StrategieParBesoin	* StrategieParBesoinPTR;

class StrategieParBesoin : public StrategieDEvaluation
	{
public:
										StrategieParBesoin ();

	Chaine							SousFormeDeChaine ();

	bool								ABesoinDUnLienStatique ();

	DescrParametrePTR				CreerDescrParametre (
											FonctionUtilisateurPTR	laFonctionUtilisateur,
											int							leNumeroDeParametre );

	EmploiParametrePTR			CreerEmploiParametre (
											ParametreFormelPTR 	leParametreFormel );

	Chaine							SuffixeFichiersBinaires ();

	};	//	StrategieParBesoin


// -------------------------------------------------------------------------
//	OptionsStrategie
// -------------------------------------------------------------------------

class		OptionsStrategie;
typedef	OptionsStrategie		* OptionsStrategiePTR;

class OptionsStrategie
	{
public:
										OptionsStrategie (
											StrategieDEvaluationPTR	laStrategieDEvaluation,
											bool							leCourtCircuitLogiquesBinaires );

	StrategieDEvaluationPTR		StrategieDEvaluation ();
	bool								CourtCircuitLogiquesBinaires ();

private:
	
	StrategieDEvaluationPTR		fStrategieDEvaluation;
	bool								fCourtCircuitLogiquesBinaires;

	};	//	OptionsStrategie


inline
StrategieDEvaluationPTR
OptionsStrategie :: StrategieDEvaluation ()
	{ return fStrategieDEvaluation; }

inline
bool
OptionsStrategie :: CourtCircuitLogiquesBinaires ()
	{ return fCourtCircuitLogiquesBinaires; }


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

extern StrategieParValeurPTR			gStrategieParValeur;
extern StrategieParNomPTR				gStrategieParNom;
extern StrategieParBesoinPTR			gStrategieParBesoin;

extern StrategieDEvaluationPTR		gStrategieParDefaut;


// -------------------------------------------------------------------------
//	Initialisation
// -------------------------------------------------------------------------

void
InitialiserStrategiesDEvaluation ();


#endif /* __StrategiesDEvaluation__ */
