// =========================================================================
//	DecodageDOptionsPilum.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __DecodageDOptionsPilum__
#define __DecodageDOptionsPilum__


#include "Pilum.h"


// -------------------------------------------------------------------------
//	DecodageDOptionsPilum
// -------------------------------------------------------------------------

class		DecodageDOptionsPilum;
typedef	DecodageDOptionsPilum
										* DecodageDOptionsPilumPTR;

class DecodageDOptionsPilum : virtual public DecodageDOptions
	{
public:
										DecodageDOptionsPilum (
											int			leNbDArguments,
											CharPTR	lesArguments [],
											ChaineOptionsPFM
															laFonctionVersion );

	virtual void					Initialiser ();


	virtual void					Langue (Chaine argument);

	virtual void					Groupees (Chaine argument);

	virtual void					ModeVerbeux (Chaine argument);

	virtual void					MontrerLeCodeParPilum (Chaine argument);
	virtual void					MontrerLAideInteractiveInitialement (Chaine argument);
	virtual void					ModeTracePilum (Chaine argument);
	virtual void					ModeDebugPilum (Chaine argument);

	virtual void					TailleDeLaPile (Chaine argument);


	bool								ModeVerbeux ();

	bool								MontrerLeCodeParPilum ();
	bool								MontrerLAideInteractiveInitialement ();

	long								TailleDeLaPile ();

	GenreDExecution				LeGenreDExecution ();

	virtual void					ArgumentsNonOptions (Chaine argument);


protected:

	bool								fModeVerbeux;

	bool								fMontrerLeCodeParPilum;
	bool								fMontrerLAideInteractiveInitialement;

	GenreDExecution				fGenreDExecution;
	long								fTailleDeLaPile;

	};	// DecodageDOptionsPilum


typedef TemplateAssocInstanceMethodeOptions
										<DecodageDOptionsPilum>
											AssocDecodageDOptionsPilum;


#endif /* __DecodageDOptionsPilum__ */
