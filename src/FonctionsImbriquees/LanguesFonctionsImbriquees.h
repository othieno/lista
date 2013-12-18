// =========================================================================
//	LanguesFonctionsImbriquees.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __LanguesFonctionsImbriquees__
#define __LanguesFonctionsImbriquees__


#include "Langues.h"

#include "Pilum.h"


// -------------------------------------------------------------------------
//	LangueFonctionsImbriquees
// -------------------------------------------------------------------------

class		LangueFonctionsImbriquees;
typedef	LangueFonctionsImbriquees
										* LangueFonctionsImbriqueesPTR;

class LangueFonctionsImbriquees
	{
public:
										LangueFonctionsImbriquees ();

	virtual							~ LangueFonctionsImbriquees ();


	//	FonctionsImbriquees
	// -------------------------------------------------------------------------


	};	//	LangueFonctionsImbriquees


// -------------------------------------------------------------------------
//	LangueFonctionsImbriqueesFR
// -------------------------------------------------------------------------

class		LangueFonctionsImbriqueesFR;
typedef	LangueFonctionsImbriqueesFR	* LangueFonctionsImbriqueesFRPTR;

class LangueFonctionsImbriqueesFR : public LangueFonctionsImbriquees
	{
public:
										LangueFonctionsImbriqueesFR ();

	virtual							~ LangueFonctionsImbriqueesFR ();


	};	//	LangueFonctionsImbriqueesFR


// -------------------------------------------------------------------------
//	LangueFonctionsImbriqueesEN
// -------------------------------------------------------------------------

class		LangueFonctionsImbriqueesEN;
typedef	LangueFonctionsImbriqueesEN	* LangueFonctionsImbriqueesENPTR;

class LangueFonctionsImbriqueesEN : public LangueFonctionsImbriquees
	{
public:
										LangueFonctionsImbriqueesEN ();

	virtual							~ LangueFonctionsImbriqueesEN ();


	};	//	LangueFonctionsImbriqueesEN


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

extern LangueFonctionsImbriqueesPTR
										gLANGUE_FonctionsImbriquees;


// -------------------------------------------------------------------------
//	InitialiserGlobalesSyntaxe
// -------------------------------------------------------------------------

void									InitialiserLanguesFonctionsImbriquees (
											Chaine leMnemonique = LANGUE_PAR_DEFAUT );


#endif /* __LanguesFonctionsImbriquees__ */
