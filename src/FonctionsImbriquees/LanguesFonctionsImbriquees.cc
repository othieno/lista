// =========================================================================
//	LanguesFonctionsImbriquees.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "LanguesFonctionsImbriquees.h"

#include "Langues.h"

#include "LanguesPilum.h"
#include "LanguesSynthesePilum.h"

#include "SynthesePilum.h"

#include <iostream>

#include <cstdlib>


// -------------------------------------------------------------------------
//	LangueFonctionsImbriquees
// -------------------------------------------------------------------------

LangueFonctionsImbriquees :: LangueFonctionsImbriquees ()
	{}

LangueFonctionsImbriquees :: ~ LangueFonctionsImbriquees ()
	{}


// -------------------------------------------------------------------------
//	LangueFonctionsImbriqueesFR
// -------------------------------------------------------------------------

LangueFonctionsImbriqueesFR :: LangueFonctionsImbriqueesFR ()
	{}

LangueFonctionsImbriqueesFR :: ~ LangueFonctionsImbriqueesFR ()
	{}


// -------------------------------------------------------------------------
//	LangueFonctionsImbriqueesEN
// -------------------------------------------------------------------------

LangueFonctionsImbriqueesEN :: LangueFonctionsImbriqueesEN ()
	{}

LangueFonctionsImbriqueesEN :: ~ LangueFonctionsImbriqueesEN ()
	{}


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

LangueFonctionsImbriqueesPTR		gLANGUE_FonctionsImbriquees	= NULL;


// -------------------------------------------------------------------------
//	InitialiserLanguesFonctionsImbriquees
// -------------------------------------------------------------------------

void
InitialiserLanguesFonctionsImbriquees (Chaine leMnemonique)
	{
	if (gLANGUE_FonctionsImbriquees != NULL)
		delete gLANGUE_FonctionsImbriquees;

	if (leMnemonique == "fr")
		gLANGUE_FonctionsImbriquees = new LangueFonctionsImbriqueesFR;
	if (leMnemonique == "en")
		gLANGUE_FonctionsImbriquees = new LangueFonctionsImbriqueesEN;
	}
