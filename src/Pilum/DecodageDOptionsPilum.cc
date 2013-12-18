// =========================================================================
//	DecodageDOptionsPilum.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "DecodageDOptionsPilum.h"

#include "LanguesPredefinis.h"

#include "LanguesPilum.h"

#include <cstdlib>


// -------------------------------------------------------------------------
//	DecodageDOptionsPilum
// -------------------------------------------------------------------------

DecodageDOptionsPilum :: DecodageDOptionsPilum (
	int			leNbDArguments,
	CharPTR	lesArguments [],
	ChaineOptionsPFM
					laFonctionVersion )
	:	DecodageDOptions (
			leNbDArguments, lesArguments, laFonctionVersion)
	{
	fModeVerbeux = false;

	fMontrerLeCodeParPilum = false;
	fMontrerLAideInteractiveInitialement = false;

	fGenreDExecution = kEnContinu;
	fTailleDeLaPile = kTailleDeLaPileParDefaut;
	}	// DecodageDOptionsPilum :: DecodageDOptionsPilum


// -------------------------------------------------------------------------

void
DecodageDOptionsPilum :: Initialiser ()
	{
	DecodageDOptions :: Initialiser ();

	EnregistrerLAssociation (
		new AssocDecodageDOptionsPilum (
			& Options :: OptionsGroupeesPilum,
			this, & DecodageDOptionsPilum :: Groupees ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsPilum (
			& Options :: OptionModeVerbeux,
			this, & DecodageDOptionsPilum :: ModeVerbeux ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsPilum (
			& Options :: OptionMontrerLeCodeParPilum,
			this, & DecodageDOptionsPilum :: MontrerLeCodeParPilum ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsPilum (
			& Options :: OptionModeTracePilum,
			this, & DecodageDOptionsPilum :: ModeTracePilum ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsPilum (
			& Options :: OptionModeDebugPilum,
			this, & DecodageDOptionsPilum :: ModeDebugPilum ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsPilum (
			& Options :: OptionTailleDeLaPile,
			this, & DecodageDOptionsPilum :: TailleDeLaPile ));

	}	// DecodageDOptionsPilum :: Initialiser


// -------------------------------------------------------------------------

void
DecodageDOptionsPilum :: Langue (Chaine argument)
	{
	DecodageDOptions :: Langue (argument);

	InitialiserLanguesPredefinis (argument);
	InitialiserLanguesSupportCPlusPlus (argument);

	InitialiserLanguesPilum (argument);
	}

// -------------------------------------------------------------------------

void
DecodageDOptionsPilum :: ModeVerbeux (Chaine argument)
	{ fModeVerbeux = true; }

void
DecodageDOptionsPilum :: MontrerLeCodeParPilum (Chaine argument)
	{ fMontrerLeCodeParPilum = true; }
void
DecodageDOptionsPilum :: MontrerLAideInteractiveInitialement (
	Chaine argument )
	{ fMontrerLAideInteractiveInitialement = true; }

void
DecodageDOptionsPilum :: ModeTracePilum (Chaine argument)
	{ fGenreDExecution = kPasAPas; }
void
DecodageDOptionsPilum :: ModeDebugPilum (Chaine argument)
	{
	fMontrerLAideInteractiveInitialement = true;
	fGenreDExecution = kArretSurAppelOuRetourAvecAffichageDeLaPile;
	}

void
DecodageDOptionsPilum :: TailleDeLaPile (Chaine argument)
	{
	fTailleDeLaPile = atoi (argument.c_str ());
	if (fTailleDeLaPile <= 0)
		{
		std::cerr <<
			MiseEnForme (
				gLANGUE_Pilum ->
					FormatTailleDeLaPilePasEntiere (),
				argument ) << std::endl;
		std::cout << Usage ();
		exit (1);
		}
	}


void
DecodageDOptionsPilum :: ArgumentsNonOptions (Chaine argument)
	{}

void
DecodageDOptionsPilum :: Groupees (Chaine argument)
	{
	this -> MontrerLeCodeParPilum (argument);
	this -> ModeTracePilum (argument);
	}


// -------------------------------------------------------------------------

bool
DecodageDOptionsPilum :: ModeVerbeux ()
	{ return fModeVerbeux; }

bool
DecodageDOptionsPilum :: MontrerLeCodeParPilum ()
	{ return fMontrerLeCodeParPilum; }
bool
DecodageDOptionsPilum :: MontrerLAideInteractiveInitialement ()
	{ return fMontrerLAideInteractiveInitialement; }

long
DecodageDOptionsPilum :: TailleDeLaPile ()
	{ return fTailleDeLaPile; }

GenreDExecution
DecodageDOptionsPilum :: LeGenreDExecution ()
	{ return fGenreDExecution; }


