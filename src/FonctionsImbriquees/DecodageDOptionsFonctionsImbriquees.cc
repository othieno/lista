// =========================================================================
//	DecodageDOptionsFonctionsImbriquees.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "DecodageDOptionsFonctionsImbriquees.h"

#include "LanguesPredefinis.h"

#include "LanguesPilum.h"
#include "LanguesSynthesePilum.h"

#include "LanguesFonctionsImbriquees.h"

#include <cstdlib>


// -------------------------------------------------------------------------
//	DecodageDOptionsFonctionsImbriquees
// -------------------------------------------------------------------------

DecodageDOptionsFonctionsImbriquees :: DecodageDOptionsFonctionsImbriquees (
	int			leNbDArguments,
	CharPTR		lesArguments [],
	ChaineOptionsPFM
					laFonctionVersion )
	:	DecodageDOptions (
			leNbDArguments, lesArguments, laFonctionVersion )
	{
	fModeVerbeux = false;

	fMontrerLeCodeSource = false;

	fModeDebugSynthese = false;
	fCommenterLeCode = false;
	fMarquerLesBlocsDActivation = false;
	fOptimiserLesSauts = false;
	fMontrerLeCodeParLeSynthetiseur = false;

	fMontrerLeCodeParPilum = false;
	fMontrerLAideInteractiveInitialement = false;

	fGenreDExecution = kEnContinu;
	fTailleDeLaPile = kTailleDeLaPileParDefaut;
	}	// DecodageDOptionsFonctionsImbriquees :: DecodageDOptionsFonctionsImbriquees


// -------------------------------------------------------------------------

void
DecodageDOptionsFonctionsImbriquees :: Initialiser ()
	{
	DecodageDOptions :: Initialiser ();

	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionsGroupeesFonctionsImbriquees,
			this,
			& DecodageDOptionsFonctionsImbriquees :: Groupees ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionModeVerbeux,
			this,
			& DecodageDOptionsFonctionsImbriquees :: ModeVerbeux ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionMontrerLeCodeSource,
			this,
			& DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeSource ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionCommenterLeCode,
			this,
			& DecodageDOptionsFonctionsImbriquees :: CommenterLeCode ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionMarquerLesBlocsDActivation,
			this,
			& DecodageDOptionsFonctionsImbriquees :: MarquerLesBlocsDActivation ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionMontrerLeCodeParLeSynthetiseur,
			this,
			& DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeParLeSynthetiseur ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionModeDebugSynthese,
			this,
			& DecodageDOptionsFonctionsImbriquees :: ModeDebugSynthese ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionMontrerLeCodeParPilum,
			this,
			& DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeParPilum ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionModeTracePilum,
			this,
			& DecodageDOptionsFonctionsImbriquees :: ModeTracePilum ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionModeDebugPilum,
			this,
			& DecodageDOptionsFonctionsImbriquees :: ModeDebugPilum ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsFonctionsImbriquees (
			& Options :: OptionTailleDeLaPile,
			this,
			& DecodageDOptionsFonctionsImbriquees :: TailleDeLaPile ));

	}	// DecodageDOptionsFonctionsImbriquees :: Initialiser


// -------------------------------------------------------------------------

void
DecodageDOptionsFonctionsImbriquees :: Langue (Chaine argument)
	{
	DecodageDOptions :: Langue (argument);

	InitialiserLanguesPredefinis (argument);

	InitialiserLanguesPilum (argument);
	InitialiserLanguesSynthesePilum (argument);

	InitialiserLanguesFonctionsImbriquees (argument);

	this -> Initialiser ();
	}


// -------------------------------------------------------------------------

void
DecodageDOptionsFonctionsImbriquees :: ModeVerbeux (Chaine argument)
	{ fModeVerbeux = true; }

void
DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeSource (Chaine argument)
	{ fMontrerLeCodeSource = true; }

void
DecodageDOptionsFonctionsImbriquees :: ModeDebugSynthese (Chaine argument)
	{ fModeDebugSynthese = true; }
void
DecodageDOptionsFonctionsImbriquees :: CommenterLeCode (Chaine argument)
	{ fCommenterLeCode = true; }
void
DecodageDOptionsFonctionsImbriquees :: MarquerLesBlocsDActivation (
	Chaine argument )
	{ fMarquerLesBlocsDActivation = true; }
void
DecodageDOptionsFonctionsImbriquees :: OptimiserLesSauts (Chaine argument)
	{ fOptimiserLesSauts = true; }
void
DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeParLeSynthetiseur (
	Chaine argument )
	{ fMontrerLeCodeParLeSynthetiseur = true; }

void
DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeParPilum (Chaine argument)
	{ fMontrerLeCodeParPilum = true; }
void
DecodageDOptionsFonctionsImbriquees :: MontrerLAideInteractiveInitialement (
	Chaine argument )
	{ fMontrerLAideInteractiveInitialement = true; }

void
DecodageDOptionsFonctionsImbriquees :: ModeTracePilum (Chaine argument)
	{ fGenreDExecution = kPasAPas; }
void
DecodageDOptionsFonctionsImbriquees :: ModeDebugPilum (Chaine argument)
	{
	fMontrerLAideInteractiveInitialement = true;
	fGenreDExecution = kArretSurAppelOuRetourAvecAffichageDeLaPile;
	}

void
DecodageDOptionsFonctionsImbriquees :: TailleDeLaPile (Chaine argument)
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
DecodageDOptionsFonctionsImbriquees :: Groupees (Chaine argument)
	{
	this -> CommenterLeCode (argument);
	this -> MarquerLesBlocsDActivation (argument);
	this -> MontrerLeCodeParPilum (argument);
	this -> ModeDebugPilum (argument);
	}


// -------------------------------------------------------------------------

bool
DecodageDOptionsFonctionsImbriquees :: ModeVerbeux ()
	{ return fModeVerbeux; }

bool
DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeSource ()
	{ return fMontrerLeCodeSource; }

bool
DecodageDOptionsFonctionsImbriquees :: ModeDebugSynthese ()
	{ return fModeDebugSynthese; }
bool
DecodageDOptionsFonctionsImbriquees :: CommenterLeCode ()
	{ return fCommenterLeCode; }
bool
DecodageDOptionsFonctionsImbriquees :: MarquerLesBlocsDActivation ()
	{ return fMarquerLesBlocsDActivation; }
bool
DecodageDOptionsFonctionsImbriquees :: OptimiserLesSauts ()
	{ return fOptimiserLesSauts; }
bool
DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeParLeSynthetiseur ()
	{ return fMontrerLeCodeParLeSynthetiseur; }


bool
DecodageDOptionsFonctionsImbriquees :: MontrerLeCodeParPilum ()
	{ return fMontrerLeCodeParPilum; }
bool
DecodageDOptionsFonctionsImbriquees :: MontrerLAideInteractiveInitialement ()
	{ return fMontrerLAideInteractiveInitialement; }

long
DecodageDOptionsFonctionsImbriquees :: TailleDeLaPile ()
	{ return fTailleDeLaPile; }

GenreDExecution
DecodageDOptionsFonctionsImbriquees :: LeGenreDExecution ()
	{ return fGenreDExecution; }
