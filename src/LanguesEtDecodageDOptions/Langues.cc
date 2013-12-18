// =========================================================================
//	Langues.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Langues.h"

#include "SupportCPlusPlus.h"

#include <iostream>

#include <cstdlib>


// -------------------------------------------------------------------------
//	DescriptionDeLangue
// -------------------------------------------------------------------------

DescriptionDeLangue :: DescriptionDeLangue (
	LanguePTR	laLangue,
	Chaine		leMnemonique )
	{
	fLangue = laLangue;
	fMnemonique = leMnemonique;
	}

LanguePTR
DescriptionDeLangue :: LaLangue ()
	{ return fLangue; }
Chaine
DescriptionDeLangue :: LeMnemonique ()
	{ return fMnemonique; }


// -------------------------------------------------------------------------
//	Langue
// -------------------------------------------------------------------------

Langue :: Langue (
	Chaine					leNom,
	Chaine					leMnemonique,
	OptionsPTR				lesOptions )
	{
	fNom = leNom;

	fOptions = lesOptions;

	Langue :: EnregistrerLaLangue (this, leMnemonique);
	}

Langue :: ~ Langue ()
	{}


DescriptionsDesLanguesPTR
Langue :: sLanguesConnues = NULL;


// -------------------------------------------------------------------------

Chaine
Langue :: Nom ()
	{ return fNom; }

OptionsPTR
Langue :: LesOptions ()
	{ return fOptions; }


// -------------------------------------------------------------------------
//	EnregistrerLaLangue
// -------------------------------------------------------------------------

void
Langue :: EnregistrerLaLangue (
	LanguePTR	laLangue,
	Chaine		leMnemonique )
	{
	if (sLanguesConnues == NULL)
		sLanguesConnues = new DescriptionsDesLangues;

	sLanguesConnues -> push_back (
		new
			DescriptionDeLangue (laLangue, leMnemonique) );
	
	if (leMnemonique == LANGUE_PAR_DEFAUT)
		{
		gLANGUE = laLangue;
		gOPTIONS = gLANGUE -> LesOptions ();
		}
	}


// -------------------------------------------------------------------------
//	ListerLesLanguesConnues
// -------------------------------------------------------------------------

void
Langue :: ListerLesLanguesConnues ()
	{
	std::cout <<
		std::endl << 
		gLANGUE ->
			LesLanguesConnuesSont () <<
		std::endl;

	DescriptionsDesLangues :: iterator	i;
	
	for (
		i = sLanguesConnues -> begin ();
		i != sLanguesConnues -> end ();
		++ i )
		{
		std::cout <<
			MiseEnForme (
				"\t%s: %s",
				(* i) -> LeMnemonique (),
				(* i) -> LaLangue () -> Nom ()) <<
			std::endl;
		}	// for

	std::cout << std::endl;
	}	// Langue :: ListerLesLanguesConnues ()


// -------------------------------------------------------------------------
//	RechercherLaLangue
// -------------------------------------------------------------------------

LanguePTR
Langue :: RechercherLaLangue (Chaine leMnemonique)
	{
	LanguePTR
				laLangue = NULL;

	DescriptionsDesLangues :: iterator
				i;
	
	for (
		i = sLanguesConnues -> begin ();
		i != sLanguesConnues -> end ();
		++ i )
		{
		if (leMnemonique == (* i) -> LeMnemonique ())
			{
			laLangue =
				(* i) -> LaLangue ();
			break;
			}	// if
		}	// for

	if (laLangue == NULL)
		{
		std::cerr <<
			std::endl <<
			MiseEnForme (
				gLANGUE ->
					FormatLangueInconnue (),
				leMnemonique ) <<
			std::endl;

		Langue :: ListerLesLanguesConnues ();
		}	// if

	return laLangue;
	}	// Langue :: RechercherLaLangue


// -------------------------------------------------------------------------
//	ChoisirLaLangueSource
// -------------------------------------------------------------------------

void
Langue :: ChoisirLaLangueSource (
	Chaine	leMnemonique,
	bool		sortirSiInconnue )
	{
	LanguePTR
				laLangue = RechercherLaLangue (leMnemonique);

	if (laLangue != NULL)
		{
		if (laLangue != gLANGUE)
			{
			gLANGUE = laLangue;

			gOPTIONS =
				gLANGUE -> 
					LesOptions ();
			}
		}

	else
		{
		if (sortirSiInconnue)
			exit (19);
		}
	}	// Langue :: ChoisirLaLangueSource


// -------------------------------------------------------------------------
//	LangueFR
// -------------------------------------------------------------------------

LangueFR :: LangueFR ()
	: Langue (
		"Francais", "fr",
		& gOPTIONS_FR )
	{}


Chaine
LangueFR :: EnteteDUsage ()
	{ return "\n==> Usage: %s [options]\n\n"; }

Chaine
LangueFR :: FormatLangueInconnue ()
	{ return "--> la langue '%s' n'est pas connue!"; }

Chaine
LangueFR :: LesLanguesConnuesSont ()
	{ return "--> Les langues connues sont:"; }


// -------------------------------------------------------------------------
//	LangueEN
// -------------------------------------------------------------------------

LangueEN :: LangueEN ()
	: Langue (
		"English", "en",
		& gOPTIONS_EN )
	{}


Chaine
LangueEN :: EnteteDUsage ()
	{ return "\n==> Usage: %s [options]\n\n"; }

Chaine
LangueEN :: FormatLangueInconnue ()
	{ return "--> '%s' is no known language!"; }

Chaine
LangueEN :: LesLanguesConnuesSont ()
	{ return "--> The known languages are:"; }


// -------------------------------------------------------------------------
//	Ecritures
// -------------------------------------------------------------------------

int
TailleChampEcritureNombres ()
	{ return 16; }

int
NombreDecimalesEcritureNombres ()
	{ return 6; }


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

LanguePTR						gLANGUE = NULL;

LangueFR							gLANGUE_FR;
LangueEN							gLANGUE_EN;
