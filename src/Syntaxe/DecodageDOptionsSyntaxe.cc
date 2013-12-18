// =========================================================================
//	DecodageDOptionsSyntaxe.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "DecodageDOptionsSyntaxe.h"

#include "LanguesSyntaxe.h"


// --------------------------------------------------------------------------
//	OptionsSyntaxe
// --------------------------------------------------------------------------

OptionsSyntaxe :: OptionsSyntaxe (
	bool	leRenoncerSurErreurSyntaxique,
	bool	leModeVerbeux,
	bool	leMontrerLesTerminaux )
	{
	fRenoncerSurErreurSyntaxique = leRenoncerSurErreurSyntaxique;
	
	fModeVerbeux = leModeVerbeux;

	fMontrerLesTerminaux = leMontrerLesTerminaux;
	}


// -------------------------------------------------------------------------
//	DecodageDOptionsSyntaxe
// -------------------------------------------------------------------------

DecodageDOptionsSyntaxe :: DecodageDOptionsSyntaxe (
	int			leNbDArguments,
	CharPTR	lesArguments [],
	ChaineOptionsPFM
					laFonctionVersion,
	bool			lAnalyseSyntaxiquePure )
	:	DecodageDOptionsLexique (
		leNbDArguments, lesArguments, laFonctionVersion, false )
	{
	fAnalyseSyntaxiquePure = lAnalyseSyntaxiquePure;
	
	fModeVerbeux = false;
	fSortirALaPremiereErreurSyntaxique = false;
	}	// DecodageDOptionsSyntaxe :: DecodageDOptionsSyntaxe


// -------------------------------------------------------------------------

void
DecodageDOptionsSyntaxe :: Initialiser ()
	{
	DecodageDOptionsLexique :: Initialiser ();

	if (fAnalyseSyntaxiquePure)
		{
		EnregistrerLAssociation (
			new AssocDecodageDOptionsSyntaxe (
				& Options :: OptionsGroupeesSyntaxe,
				this,
				& DecodageDOptionsSyntaxe :: Groupees ));

		EnregistrerLAssociation (sAssocDecodageDOptions);
		}

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSyntaxe (
			& Options :: OptionModeVerbeux,
			this,
			& DecodageDOptionsSyntaxe :: ModeVerbeux ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptionsSyntaxe (
			& Options :: OptionSortirALaPremiereErreurSyntaxique,
			this,
			& DecodageDOptionsSyntaxe :: SortirALaPremiereErreurSyntaxique ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	}	// DecodageDOptionsSyntaxe :: Initialiser


// -------------------------------------------------------------------------

void
DecodageDOptionsSyntaxe :: Langue (Chaine argument)
	{
	DecodageDOptionsLexique :: Langue (argument);

	InitialiserLanguesSyntaxe (argument);

	this -> Initialiser ();
	}

// -------------------------------------------------------------------------

void
DecodageDOptionsSyntaxe :: ModeVerbeux (Chaine argument)
	{ fModeVerbeux = true; }

void
DecodageDOptionsSyntaxe :: SortirALaPremiereErreurSyntaxique (Chaine argument)
	{ fSortirALaPremiereErreurSyntaxique = true; }

void
DecodageDOptionsSyntaxe :: ArgumentsNonOptions (Chaine argument)
	{}

void
DecodageDOptionsSyntaxe :: Groupees (Chaine argument)
	{
	this -> ModeVerbeux (argument);
	this -> MontrerLeCodeSource (argument);
	this -> MontrerLesTerminaux (argument);
	}


// -------------------------------------------------------------------------

bool
DecodageDOptionsSyntaxe :: ModeVerbeux ()
	{ return fModeVerbeux; }

bool
DecodageDOptionsSyntaxe :: SortirALaPremiereErreurSyntaxique ()
	{ return fSortirALaPremiereErreurSyntaxique; }


