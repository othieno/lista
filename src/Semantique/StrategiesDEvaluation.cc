// =========================================================================
//	StrategiesDEvaluation.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "StrategiesDEvaluation.h"

#include "SupportCPlusPlus.h"

#include "LanguesSemantique.h"

#include "ParametresFormels.h"


#if defined SYNTHESE_PILUM
	#include "LanguesSynthesePilum.h"
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	StrategieDEvaluation
// -------------------------------------------------------------------------

StrategieDEvaluation :: StrategieDEvaluation ()
	{}

StrategieDEvaluation :: ~ StrategieDEvaluation ()
	{}


// -------------------------------------------------------------------------
//	StrategieParValeur
// -------------------------------------------------------------------------

StrategieParValeur :: StrategieParValeur ()
	{}

Chaine 
StrategieParValeur :: SousFormeDeChaine ()
	{
	return
		gLANGUE_Semantique ->
			ParValeur ();
	}

bool 
StrategieParValeur :: ABesoinDUnLienStatique ()
	{ return false; }

DescrParametrePTR 
StrategieParValeur :: CreerDescrParametre (
	FonctionUtilisateurPTR	laFonctionUtilisateur,
	int							leNumeroDeParametre )
	{
	return
		new DescrParametreParValeur (leNumeroDeParametre);
	}


EmploiParametrePTR 
StrategieParValeur :: CreerEmploiParametre (
	ParametreFormelPTR 	leParametreFormel )
	{
	return
		new EmploiParametreParValeur (leParametreFormel);
	}


#if defined SYNTHESE_PILUM

Chaine 
StrategieParValeur :: SuffixeFichiersBinaires ()
	{
	return
		gLANGUE_SynthesePilum ->
			SuffixeFichiersBinairesParValeur ();
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	StrategieParNom
// -------------------------------------------------------------------------

StrategieParNom :: StrategieParNom ()
	{}

Chaine 
StrategieParNom :: SousFormeDeChaine ()
	{
	return
		gLANGUE_Semantique ->
			ParNom ();
	}

bool StrategieParNom :: ABesoinDUnLienStatique ()
	{ return true; }

DescrParametrePTR	
StrategieParNom :: CreerDescrParametre (
	FonctionUtilisateurPTR	laFonctionUtilisateur,
	int							leNumeroDeParametre )
	{
	DescrParametrePTR
				laDescrParametre =
					new DescrParametreParNom (leNumeroDeParametre);

#if defined SYNTHESE_PILUM
	if (laFonctionUtilisateur != NULL)
		laFonctionUtilisateur ->
			UnLienStatiqueEstNecessaire ();
#endif /* SYNTHESE_PILUM */

	return laDescrParametre;
	}	// StrategieParNom :: CreerDescrParametre

EmploiParametrePTR 
StrategieParNom :: CreerEmploiParametre (
	ParametreFormelPTR 	leParametreFormel )
	{
	return
		new EmploiParametreParNom (leParametreFormel);
	}


#if defined SYNTHESE_PILUM

Chaine 
StrategieParNom ::SuffixeFichiersBinaires ()
	{
	return
		gLANGUE_SynthesePilum ->
			SuffixeFichiersBinairesParNom ();
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	StrategieParBesoin
// -------------------------------------------------------------------------

StrategieParBesoin :: StrategieParBesoin ()
	{}

Chaine 
StrategieParBesoin :: SousFormeDeChaine ()
	{
	return
		gLANGUE_Semantique ->
			ParBesoin ();
	}

bool 
StrategieParBesoin :: ABesoinDUnLienStatique ()
	{ return true; }

DescrParametrePTR	
StrategieParBesoin :: CreerDescrParametre (
	FonctionUtilisateurPTR	laFonctionUtilisateur,
	int							leNumeroDeParametre )
	{
	DescrParametrePTR
				laDescrParametre =
					new DescrParametreParBesoin (leNumeroDeParametre);

#if defined SYNTHESE_PILUM
	if (laFonctionUtilisateur != NULL)
		laFonctionUtilisateur ->
			UnLienStatiqueEstNecessaire ();
#endif /* SYNTHESE_PILUM */

	return laDescrParametre;
	}	// StrategieParBesoin :: CreerDescrParametre

EmploiParametrePTR 
StrategieParBesoin :: CreerEmploiParametre (
	ParametreFormelPTR 	leParametreFormel )
	{
	return
		new EmploiParametreParBesoin (leParametreFormel);
	}


#if defined SYNTHESE_PILUM

Chaine 
StrategieParBesoin ::SuffixeFichiersBinaires ()
	{
	return
		gLANGUE_SynthesePilum ->
			SuffixeFichiersBinairesParBesoin ();
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	OptionsStrategie
// -------------------------------------------------------------------------

OptionsStrategie :: OptionsStrategie (
	StrategieDEvaluationPTR	laStrategieDEvaluation,
	bool							leCourtCircuitLogiquesBinaires )
	{
	fStrategieDEvaluation = laStrategieDEvaluation;
	fCourtCircuitLogiquesBinaires = leCourtCircuitLogiquesBinaires;
	}


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

StrategieParValeurPTR			gStrategieParValeur	= NULL;
StrategieParNomPTR				gStrategieParNom		= NULL;
StrategieParBesoinPTR			gStrategieParBesoin	= NULL;

StrategieDEvaluationPTR			gStrategieParDefaut	= NULL;


// -------------------------------------------------------------------------
//	Initialisation
// -------------------------------------------------------------------------

void
InitialiserStrategiesDEvaluation ()
	{
	gStrategieParValeur			= new StrategieParValeur ();
	gStrategieParNom				= new StrategieParNom ();
	gStrategieParBesoin			= new StrategieParBesoin ();

	gStrategieParDefaut			=
#if defined PAR_VALEUR
											gStrategieParValeur;
#elif defined PAR_NOM
											gStrategieParNom;
#elif defined PAR_BESOIN
											gStrategieParBesoin;
#endif /* STRATEGIE */

	}	// InitialiserStrategiesDEvaluation

