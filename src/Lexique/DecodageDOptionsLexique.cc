// =========================================================================
//	DecodageDOptionsLexique.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "DecodageDOptionsLexique.h"

#include "LanguesLexique.h"


// --------------------------------------------------------------------------
//	OptionsLexique
// --------------------------------------------------------------------------

OptionsLexique :: OptionsLexique (
	bool	leRenoncerSurErreurLexicale,
	bool	leModeVerbeux,
	bool	leMontrerLesTerminaux,
	bool	leTraduire )
	{
	fRenoncerSurErreurLexicale = leRenoncerSurErreurLexicale;
	
	fModeVerbeux = leModeVerbeux;
	
	fMontrerLesTerminaux = leMontrerLesTerminaux;
	fTraduire = leTraduire;
	}


bool
OptionsLexique :: ModeVerbeux ()
	{ return fModeVerbeux; }


// -------------------------------------------------------------------------
//	DecodageDOptionsLexique
// -------------------------------------------------------------------------

DecodageDOptionsLexique :: DecodageDOptionsLexique (
	int			leNbDArguments,
	CharPTR	lesArguments [],
	ChaineOptionsPFM
					laFonctionVersion,
	bool			lAnalyseLexicalePure )
	:	DecodageDOptions (
			leNbDArguments, lesArguments, laFonctionVersion )
	{
	fAnalyseLexicalePure = lAnalyseLexicalePure;
	
	fMontrerLeCodeSource = false;
	fMontrerLesTerminaux = false;

	fSortirALaPremiereErreurLexicale = false;
	}	// DecodageDOptionsLexique :: DecodageDOptionsLexique


// -------------------------------------------------------------------------

void
DecodageDOptionsLexique :: Initialiser ()
	{
	DecodageDOptions :: Initialiser ();
	
	if (fAnalyseLexicalePure)
		{
		EnregistrerLAssociation (
			new AssocDecodageDOptionsLexique (
				& Options :: OptionsGroupeesLexique,
				this,
				& DecodageDOptionsLexique :: Groupees ));

		EnregistrerLAssociation (sAssocDecodageDOptions);
		}
	
	EnregistrerLAssociation (
		new AssocDecodageDOptionsLexique (
			& Options :: OptionMontrerLeCodeSource,
			this,
			& DecodageDOptionsLexique :: MontrerLeCodeSource ));
	EnregistrerLAssociation (
		new AssocDecodageDOptionsLexique (
			& Options :: OptionMontrerLesTerminaux,
			this,
			& DecodageDOptionsLexique :: MontrerLesTerminaux ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsLexique (
			& Options :: OptionSortirALaPremiereErreurLexicale,
			this,
			& DecodageDOptionsLexique :: SortirALaPremiereErreurLexicale ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	}	// DecodageDOptionsLexique :: Initialiser


// -------------------------------------------------------------------------

void
DecodageDOptionsLexique :: Langue (Chaine argument)
	{
	DecodageDOptions :: Langue (argument);

	InitialiserLanguesLexique (argument);

	this -> Initialiser ();
	}

// -------------------------------------------------------------------------

void
DecodageDOptionsLexique :: MontrerLeCodeSource (Chaine argument)
	{ fMontrerLeCodeSource = true; }

void
DecodageDOptionsLexique :: MontrerLesTerminaux (Chaine argument)
	{ fMontrerLesTerminaux = true; }

void
DecodageDOptionsLexique :: SortirALaPremiereErreurLexicale (Chaine argument)
	{ fSortirALaPremiereErreurLexicale = true; }

void
DecodageDOptionsLexique :: ArgumentsNonOptions (Chaine argument)
	{}

void
DecodageDOptionsLexique :: Groupees (Chaine argument)
	{
	this -> MontrerLeCodeSource (argument);
	this -> MontrerLesTerminaux (argument);
	}


// -------------------------------------------------------------------------

bool
DecodageDOptionsLexique :: MontrerLeCodeSource ()
	{ return fMontrerLeCodeSource; }
bool
DecodageDOptionsLexique :: MontrerLesTerminaux ()
	{ return fMontrerLesTerminaux; }

bool
DecodageDOptionsLexique :: SortirALaPremiereErreurLexicale ()
	{ return fSortirALaPremiereErreurLexicale; }


