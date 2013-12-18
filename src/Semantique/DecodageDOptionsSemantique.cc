// =========================================================================
//	DecodageDOptionsSemantique.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "DecodageDOptionsSemantique.h"

#include <cstdlib>


#if defined SYNTHESE_PILUM
	#include "LanguesPilum.h"
	#include "LanguesSynthesePilum.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	OptionsSemantique
// -------------------------------------------------------------------------

OptionsSemantique :: OptionsSemantique (
	bool						leSortirALaPremiereErreurSyntaxique,
	bool						leModeVerbeux,
	bool						leMontrerLesDictionnaires,
	bool						leMontrerLeDictionnaireDesPredefinis,
	bool						leMontrerLInferenceDeType,
	bool						leMontrerLesGraphes,
	bool						leMontrerLePostfixe,
	bool						lEvaluerDirectement,
	bool						leTraduire )
	{
	fSortirALaPremiereErreurSyntaxique =
		leSortirALaPremiereErreurSyntaxique;

	fModeVerbeux = leModeVerbeux;

	fMontrerLesDictionnaires = leMontrerLesDictionnaires;
	fMontrerLeDictionnaireDesPredefinis =
		leMontrerLeDictionnaireDesPredefinis;
	fMontrerLInferenceDeType = leMontrerLInferenceDeType;

	fMontrerLesGraphes = leMontrerLesGraphes;
	fMontrerLePostfixe = leMontrerLePostfixe;

	fEvaluerDirectement = lEvaluerDirectement;

	fTraduire = leTraduire;
	}	// OptionsSemantique :: OptionsSemantique


// -------------------------------------------------------------------------
//	DecodageDOptionsSemantique
// -------------------------------------------------------------------------

DecodageDOptionsSemantique :: DecodageDOptionsSemantique (
	int			leNbDArguments,
	CharPTR		lesArguments [],
	ChaineOptionsPFM
					laFonctionVersion )
	:	DecodageDOptionsSyntaxe (
		leNbDArguments, lesArguments, laFonctionVersion, false )
	{
	fModeDebug = false;
	fSortirALaPremiereErreurSemantique = false;

	fTraduire = false;

	fStrategieDEvaluation = gStrategieParDefaut;

	fCourtCircuitLogiquesBinaires = false;

	fMontrerLesAppelsImbriques = false;
	
	fMontrerLesDictionnaires = false;
	fMontrerLeDictionnaireDesPredefinis = false;
	fMontrerLInferenceDeType = false;
	fMontrerLesGraphesSemantiques = false;
	fMontrerLeCodePostfixe = false;

	fEvaluerDirectement = false;
	fTraceDEvaluationDirecte = false;

#if defined SYNTHESE_PILUM

	fCommenterLeCode = false;
	fMarquerLesBlocsDActivation = false;
	fOptimiserLesSauts = false;
	fMontrerLeCodeParLeSynthetiseur = false;
	fModeDebugSynthese = false;

	fEvaluerParPilum = false;	
	fTailleDeLaPile = kTailleDeLaPileParDefaut;

	fGenreDExecution = kEnContinu;

	fMontrerLeCodeParPilum = false;
	fMontrerLAideInteractiveInitialement = false;

#endif /* SYNTHESE_PILUM */

	}	// DecodageDOptionsSemantique :: DecodageDOptionsSemantique


// -------------------------------------------------------------------------

void
DecodageDOptionsSemantique :: Initialiser ()
	{
	DecodageDOptionsSyntaxe :: Initialiser ();


#if defined SYNTHESE_PILUM
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionsGroupeesSemantique_SYNTHESE_PILUM,
			this,
			& DecodageDOptionsSemantique :: Groupees ));
#else /* SYNTHESE_PILUM */
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionsGroupeesSemantique,
			this,
			& DecodageDOptionsSemantique :: Groupees ));
#endif /* SYNTHESE_PILUM */

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionModeDebug,
			this,
			& DecodageDOptionsSemantique :: ModeDebug ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionSortirALaPremiereErreurSemantique,
			this,
			& DecodageDOptionsSemantique :: SortirALaPremiereErreurSemantique ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMontrerLesAppelsImbriques,
			this,
			& DecodageDOptionsSemantique :: MontrerLesAppelsImbriques ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMontrerLesDictionnaires,
			this,
			& DecodageDOptionsSemantique :: MontrerLesDictionnaires ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMontrerLeDictionnaireDesPredefinis,
			this,
			& DecodageDOptionsSemantique :: MontrerLeDictionnaireDesPredefinis ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMontrerLInferenceDeType,
			this,
			& DecodageDOptionsSemantique :: MontrerLInferenceDeType ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMontrerLesGraphesSemantiques,
			this,
			& DecodageDOptionsSemantique :: MontrerLesGraphesSemantiques ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMontrerLeCodePostfixe,
			this,
			& DecodageDOptionsSemantique :: MontrerLeCodePostfixe ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionLangueDestination,
			this,
			& DecodageDOptionsSemantique :: LangueDestination ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionStrategieParValeur,
			this,
			& DecodageDOptionsSemantique :: StrategieParValeur ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionStrategieParNom,
			this,
			& DecodageDOptionsSemantique :: StrategieParNom ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionStrategieParBesoin,
			this,
			& DecodageDOptionsSemantique :: StrategieParBesoin ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionEvaluationDirecteSansTrace,
			this,
			& DecodageDOptionsSemantique :: EvaluationDirecteSansTrace ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionEvaluationDirecteAvecTrace,
			this,
			& DecodageDOptionsSemantique :: EvaluationDirecteAvecTrace ));

#if defined SYNTHESE_PILUM

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionCommenterLeCode,
			this,
			& DecodageDOptionsSemantique :: CommenterLeCode ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMarquerLesBlocsDActivation,
			this,
			& DecodageDOptionsSemantique :: MarquerLesBlocsDActivation ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionOptimiserLesSauts,
			this,
			& DecodageDOptionsSemantique :: OptimiserLesSauts ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMontrerLeCodeParLeSynthetiseur,
			this,
			& DecodageDOptionsSemantique :: MontrerLeCodeParLeSynthetiseur ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionModeDebugSynthese,
			this,
			& DecodageDOptionsSemantique :: ModeDebugSynthese ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionMontrerLeCodeParPilum,
			this,
			& DecodageDOptionsSemantique :: MontrerLeCodeParPilum ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionModeTracePilum,
			this,
			& DecodageDOptionsSemantique :: ModeTracePilum ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionModeDebugPilum,
			this,
			& DecodageDOptionsSemantique :: ModeDebugPilum ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: OptionTailleDeLaPile,
			this,
			& DecodageDOptionsSemantique :: TailleDeLaPile ));

#endif /* SYNTHESE_PILUM */

	EnregistrerLAssociation (sAssocDecodageDOptions);

	}	// DecodageDOptionsSemantique :: Initialiser


// -------------------------------------------------------------------------

void
DecodageDOptionsSemantique :: Langue (Chaine argument)
	{
	DecodageDOptionsSyntaxe :: Langue (argument);

	InitialiserLanguesPredefinis (argument);

	InitialiserLanguesSemantique (argument);

#if defined SYNTHESE_PILUM
	InitialiserLanguesSynthesePilum (argument);
#endif /* SYNTHESE_PILUM */

	this -> Initialiser ();
	}


// -------------------------------------------------------------------------

void
DecodageDOptionsSemantique :: ModeDebug (Chaine argument)
	{ fModeDebug = true; }
void
DecodageDOptionsSemantique :: SortirALaPremiereErreurSemantique (Chaine argument)
	{ fSortirALaPremiereErreurSemantique = true; }

void
DecodageDOptionsSemantique :: LangueDestination (Chaine argument)
	{
	fTraduire = true;
	ChoisirLaLangueDeTraduction (argument);
	}

void
DecodageDOptionsSemantique :: StrategieParValeur (Chaine argument)
	{ fStrategieDEvaluation = gStrategieParValeur;}
void
DecodageDOptionsSemantique :: StrategieParNom (Chaine argument)
	{ fStrategieDEvaluation = gStrategieParNom;}
void
DecodageDOptionsSemantique :: StrategieParBesoin (Chaine argument)
	{ fStrategieDEvaluation = gStrategieParBesoin;}

void
DecodageDOptionsSemantique :: CourtCircuitLogiquesBinaires (Chaine argument)
	{ fCourtCircuitLogiquesBinaires = true; }

void
DecodageDOptionsSemantique :: MontrerLesAppelsImbriques (Chaine argument)
	{ fMontrerLesAppelsImbriques = true; }

void
DecodageDOptionsSemantique :: MontrerLesDictionnaires (Chaine argument)
	{ fMontrerLesDictionnaires = true; }
void
DecodageDOptionsSemantique :: MontrerLeDictionnaireDesPredefinis (Chaine argument)
	{ fMontrerLeDictionnaireDesPredefinis = true; }
void
DecodageDOptionsSemantique :: MontrerLInferenceDeType (Chaine argument)
	{ fMontrerLInferenceDeType = true; }
void
DecodageDOptionsSemantique :: MontrerLesGraphesSemantiques (Chaine argument)
	{ fMontrerLesGraphesSemantiques = true; }
void
DecodageDOptionsSemantique :: MontrerLeCodePostfixe (Chaine argument)
	{ fMontrerLeCodePostfixe = true; }
void
DecodageDOptionsSemantique :: EvaluationDirecteSansTrace (Chaine argument)
	{
	fEvaluerDirectement = true;
	fTraceDEvaluationDirecte = false;
	}
void
DecodageDOptionsSemantique :: EvaluationDirecteAvecTrace (Chaine argument)
	{
	fEvaluerDirectement = true;
	fTraceDEvaluationDirecte = true;
	}

#if defined SYNTHESE_PILUM

void
DecodageDOptionsSemantique :: CommenterLeCode (Chaine argument)
	{ fCommenterLeCode = true; }
void
DecodageDOptionsSemantique :: MarquerLesBlocsDActivation (Chaine argument)
	{ fMarquerLesBlocsDActivation = true; }
void
DecodageDOptionsSemantique :: OptimiserLesSauts (Chaine argument)
	{ fOptimiserLesSauts = true; }
void
DecodageDOptionsSemantique :: MontrerLeCodeParLeSynthetiseur (Chaine argument)
	{ fMontrerLeCodeParLeSynthetiseur = true; }
void
DecodageDOptionsSemantique :: ModeDebugSynthese (Chaine argument)
	{ fModeDebugSynthese = true; }

void
DecodageDOptionsSemantique :: EvaluerParPilum (Chaine argument)
	{ fEvaluerParPilum = true; }

void
DecodageDOptionsSemantique :: TailleDeLaPile (Chaine argument)
	{
	fTailleDeLaPile = atoi (argument.c_str ());
	if (fTailleDeLaPile <= 0)
		{
		std::cerr <<
			MiseEnForme (
				gLANGUE_Pilum ->
					FormatTailleDeLaPilePasEntiere (),
				argument ) <<
			std::endl;
		std::cout << Usage ();
		exit (1);
		}
	}

void
DecodageDOptionsSemantique :: MontrerLeCodeParPilum (Chaine argument)
	{ fMontrerLesAppelsImbriques = true; }
void
DecodageDOptionsSemantique :: ModeTracePilum (Chaine argument)
	{ fGenreDExecution = kPasAPas; }
void
DecodageDOptionsSemantique :: ModeDebugPilum (Chaine argument)
	{
	fMontrerLAideInteractiveInitialement = true;
	fGenreDExecution = kArretSurAppelOuRetourAvecAffichageDeLaPile;
	}
void
DecodageDOptionsSemantique :: MontrerLAideInteractiveInitialement (Chaine argument)
	{ fMontrerLAideInteractiveInitialement = true; }

#endif /* SYNTHESE_PILUM */


void
DecodageDOptionsSemantique :: ArgumentsNonOptions (Chaine argument)
	{}

void
DecodageDOptionsSemantique :: Groupees (Chaine argument)
	{
	this -> MontrerLeCodeSource (argument);
#if defined SYNTHESE_PILUM
	this -> CommenterLeCode (argument);
	this -> MarquerLesBlocsDActivation (argument);
#endif /* SYNTHESE_PILUM */
	}


// -------------------------------------------------------------------------

bool
DecodageDOptionsSemantique :: ModeDebug ()
	{ return fModeDebug; }
bool
DecodageDOptionsSemantique :: SortirALaPremiereErreurSemantique ()
	{ return fSortirALaPremiereErreurSemantique; }

bool
DecodageDOptionsSemantique :: Traduire ()
	{ return fTraduire; }

StrategieDEvaluationPTR
DecodageDOptionsSemantique :: LaStrategieDEvaluation ()
	{ return fStrategieDEvaluation; }

bool
DecodageDOptionsSemantique :: CourtCircuitLogiquesBinaires ()
	{ return fCourtCircuitLogiquesBinaires; }

bool
DecodageDOptionsSemantique :: MontrerLesAppelsImbriques ()
	{ return fMontrerLesAppelsImbriques; }

bool
DecodageDOptionsSemantique :: MontrerLesDictionnaires ()
	{ return fMontrerLesDictionnaires; }
bool
DecodageDOptionsSemantique :: MontrerLeDictionnaireDesPredefinis ()
	{ return fMontrerLeDictionnaireDesPredefinis; }
bool
DecodageDOptionsSemantique :: MontrerLInferenceDeType ()
	{ return fMontrerLInferenceDeType; }
bool
DecodageDOptionsSemantique :: MontrerLesGraphesSemantiques ()
	{ return fMontrerLesGraphesSemantiques; }
bool
DecodageDOptionsSemantique :: MontrerLeCodePostfixe ()
	{ return fMontrerLeCodePostfixe; }

bool
DecodageDOptionsSemantique :: EvaluerDirectement ()
	{ return fEvaluerDirectement; }
bool
DecodageDOptionsSemantique :: TraceDEvaluationDirecte ()
	{ return fTraceDEvaluationDirecte; }

#if defined SYNTHESE_PILUM

bool
DecodageDOptionsSemantique :: CommenterLeCode ()
	{ return fCommenterLeCode; }
bool
DecodageDOptionsSemantique :: MarquerLesBlocsDActivation ()
	{ return fMarquerLesBlocsDActivation; }
bool
DecodageDOptionsSemantique :: OptimiserLesSauts ()
	{ return fOptimiserLesSauts; }
bool
DecodageDOptionsSemantique :: MontrerLeCodeParLeSynthetiseur ()
	{ return fMontrerLeCodeParLeSynthetiseur; }
bool
DecodageDOptionsSemantique :: ModeDebugSynthese ()
	{ return fModeDebugSynthese; }

bool
DecodageDOptionsSemantique :: EvaluerParPilum ()
	{ return fEvaluerParPilum; }
long
DecodageDOptionsSemantique :: TailleDeLaPile ()
	{ return fTailleDeLaPile; }

GenreDExecution
DecodageDOptionsSemantique :: LeGenreDExecution ()
	{ return fGenreDExecution; }

bool
DecodageDOptionsSemantique :: MontrerLeCodeParPilum ()
	{ return fMontrerLeCodeParPilum; }
bool
DecodageDOptionsSemantique :: MontrerLAideInteractiveInitialement ()
	{ return fMontrerLAideInteractiveInitialement; }

#endif /* SYNTHESE_PILUM */
