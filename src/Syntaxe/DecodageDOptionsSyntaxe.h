// =========================================================================
//	DecodageDOptionsSyntaxe.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __DecodageDOptionsSyntaxe__
#define __DecodageDOptionsSyntaxe__


#include "DecodageDOptionsLexique.h"


// --------------------------------------------------------------------------
//	OptionsSyntaxe
// --------------------------------------------------------------------------

class		OptionsSyntaxe;
typedef	OptionsSyntaxe			* OptionsSyntaxePTR;

class OptionsSyntaxe
	{
public:
										OptionsSyntaxe (
											bool	leRenoncerSurErreurSyntaxique,
											bool	leModeVerbeux,
											bool	leMontrerLesTerminaux );

	bool								RenoncerSurErreurSyntaxique ();

	bool								ModeVerbeux ();

	bool								MontrerLesTerminaux ();

private:
	
	bool								fRenoncerSurErreurSyntaxique;

	bool								fModeVerbeux;
	bool								fMontrerLesTerminaux;

	};	//	OptionsSyntaxe


inline
bool
OptionsSyntaxe :: RenoncerSurErreurSyntaxique ()
	{ return fRenoncerSurErreurSyntaxique; }

inline
bool
OptionsSyntaxe :: ModeVerbeux ()
	{ return fModeVerbeux; }

inline
bool
OptionsSyntaxe :: MontrerLesTerminaux ()
	{ return fMontrerLesTerminaux; }


// -------------------------------------------------------------------------
//	DecodageDOptionsSyntaxe
// -------------------------------------------------------------------------

class		DecodageDOptionsSyntaxe;
typedef	DecodageDOptionsSyntaxe
										* DecodageDOptionsSyntaxePTR;

class DecodageDOptionsSyntaxe : public DecodageDOptionsLexique
	{
public:
										DecodageDOptionsSyntaxe (
											int			leNbDArguments,
											CharPTR	lesArguments [],
											ChaineOptionsPFM
															laFonctionVersion,
											bool			lAnalyseSyntaxiquePure );
												// il y une sous-classe pour
												// la semantique


	virtual void					Initialiser ();

	virtual void					Langue (Chaine argument);

	virtual void					Groupees (Chaine argument);

	virtual void					ModeVerbeux (Chaine argument);

	virtual void					SortirALaPremiereErreurSyntaxique (
											Chaine argument );


	bool								ModeVerbeux ();

	bool								SortirALaPremiereErreurSyntaxique ();

	virtual void					ArgumentsNonOptions (Chaine argument);


protected:

	bool								fAnalyseSyntaxiquePure;
	
	bool								fModeVerbeux;

	bool								fSortirALaPremiereErreurSyntaxique;

	};	// DecodageDOptionsSyntaxe


typedef TemplateAssocInstanceMethodeOptions
										<DecodageDOptionsSyntaxe>
											AssocDecodageDOptionsSyntaxe;


#endif /* __DecodageDOptionsSyntaxe__ */
