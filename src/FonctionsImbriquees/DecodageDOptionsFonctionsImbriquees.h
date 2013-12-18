// =========================================================================
//	DecodageDOptionsFonctionsImbriquees.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __DecodageDOptionsFonctionsImbriquees__
#define __DecodageDOptionsFonctionsImbriquees__


#include "DecodageDOptions.h"

#include "Pilum.h"


// -------------------------------------------------------------------------
//	DecodageDOptionsFonctionsImbriquees
// -------------------------------------------------------------------------

class		DecodageDOptionsFonctionsImbriquees;
typedef	DecodageDOptionsFonctionsImbriquees
										* DecodageDOptionsFonctionsImbriqueesPTR;

class DecodageDOptionsFonctionsImbriquees : public DecodageDOptions
	{
public:
										DecodageDOptionsFonctionsImbriquees (
											int			leNbDArguments,
											CharPTR	lesArguments [],
											ChaineOptionsPFM
															laFonctionVersion );

	virtual void					Initialiser ();


	virtual void					Langue (Chaine argument);

	virtual void					Groupees (Chaine argument);

	virtual void					ModeVerbeux (Chaine argument);

	virtual void					MontrerLeCodeSource (Chaine argument);

	virtual void					ModeDebugSynthese (Chaine argument);
	virtual void					CommenterLeCode (Chaine argument);
	virtual void					MarquerLesBlocsDActivation (Chaine argument);
	virtual void					OptimiserLesSauts (Chaine argument);
	virtual void					MontrerLeCodeParLeSynthetiseur (Chaine argument);

	virtual void					MontrerLeCodeParPilum (Chaine argument);
	virtual void					MontrerLAideInteractiveInitialement (Chaine argument);
	virtual void					ModeTracePilum (Chaine argument);
	virtual void					ModeDebugPilum (Chaine argument);

	virtual void					TailleDeLaPile (Chaine argument);


	bool								ModeVerbeux ();

	bool								MontrerLeCodeSource ();

	bool								ModeDebugSynthese ();
	bool								CommenterLeCode ();
	bool								MarquerLesBlocsDActivation ();
	bool								OptimiserLesSauts ();
	bool								MontrerLeCodeParLeSynthetiseur ();

	bool								MontrerLeCodeParPilum ();
	bool								MontrerLAideInteractiveInitialement ();

	long								TailleDeLaPile ();

	GenreDExecution				LeGenreDExecution ();


protected:

	bool								fModeVerbeux;
	bool								fMontrerLeCodeSource;

	bool								fModeDebugSynthese;
	bool								fCommenterLeCode;
	bool								fMarquerLesBlocsDActivation;
	bool								fOptimiserLesSauts;
	bool								fMontrerLeCodeParLeSynthetiseur;

	bool								fMontrerLeCodeParPilum;
	bool								fMontrerLAideInteractiveInitialement;

	GenreDExecution				fGenreDExecution;
	long								fTailleDeLaPile;

	};	// DecodageDOptionsFonctionsImbriquees


typedef TemplateAssocInstanceMethodeOptions
										<DecodageDOptionsFonctionsImbriquees>
											AssocDecodageDOptionsFonctionsImbriquees;

#endif /* __DecodageDOptionsFonctionsImbriquees__ */
