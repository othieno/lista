// =========================================================================
//	LanguesSupportCPlusPlus.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "LanguesSupportCPlusPlus.h"


// -------------------------------------------------------------------------
//	LangueSupportCPlusPlus
// -------------------------------------------------------------------------

LangueSupportCPlusPlus :: LangueSupportCPlusPlus ()
	{}

LangueSupportCPlusPlus :: ~ LangueSupportCPlusPlus ()
	{}


// -------------------------------------------------------------------------
//	LangueSupportCPlusPlusFR
// -------------------------------------------------------------------------

LangueSupportCPlusPlusFR :: LangueSupportCPlusPlusFR ()
	{}

LangueSupportCPlusPlusFR :: ~ LangueSupportCPlusPlusFR ()
	{}


// -------------------------------------------------------------------------

Chaine 
LangueSupportCPlusPlusFR :: DebordementDuTas ()
	{ return "### Debordement de la zone dynamique (tas) ###"; }
Chaine 
LangueSupportCPlusPlusFR :: FormatDebordementDuTamponDeFLireChaine ()
	{ return "### FLireChaine: Debordement du tampon de %d caracteres ###"; }

Chaine
LangueSupportCPlusPlusFR :: FormatContenuDuFichierSource ()
	{ return "Contenu du fichier source '%s':\n"; }

Chaine
LangueSupportCPlusPlusFR :: FormatPasPuEcrireSurLeFichier ()
	{ return "Pas pu ecrire sur le fichier '%s'"; }
Chaine
LangueSupportCPlusPlusFR :: FormatPasPuLireDuFichier ()
	{ return "Pas pu lire du fichier '%s' (%s)"; }

Chaine
LangueSupportCPlusPlusFR :: FormatSortieSurErreur ()
	{ return "### SortieSurErreur: %s ###"; }


// -------------------------------------------------------------------------

Chaine
LangueSupportCPlusPlusFR :: FormatVariableLogique ()
	{ return "[VariableLogique_%d \"%s\" -> %s]"; }
Chaine
LangueSupportCPlusPlusFR :: FormatLiaisonVariableLogique ()
	{ return "\n--> On lie la variable logique libre %s a la valeur %s\n"; }
Chaine
LangueSupportCPlusPlusFR :: FormatVariableLogiqueDejaLiee ()
	{ return "--> La variable logique %s est deja liee a la valeur %s"; }


// -------------------------------------------------------------------------
//	LangueSupportCPlusPlusEN
// -------------------------------------------------------------------------

LangueSupportCPlusPlusEN :: LangueSupportCPlusPlusEN ()
	{}

LangueSupportCPlusPlusEN :: ~ LangueSupportCPlusPlusEN ()
	{}


// -------------------------------------------------------------------------

Chaine 
LangueSupportCPlusPlusEN :: DebordementDuTas ()
	{ return "### Dynmic zone (heap) overvflow ###"; }
Chaine 
LangueSupportCPlusPlusEN :: FormatDebordementDuTamponDeFLireChaine ()
	{ return "### FLireChaine: Overflow of %d character buffer ###"; }

Chaine
LangueSupportCPlusPlusEN :: FormatContenuDuFichierSource ()
	{ return "Contens of source file '%s':\n"; }

Chaine
LangueSupportCPlusPlusEN :: FormatPasPuEcrireSurLeFichier ()
	{ return "Could not write to file '%s'"; }
Chaine
LangueSupportCPlusPlusEN :: FormatPasPuLireDuFichier ()
	{ return "Could not read from file '%s' (%s)"; }

Chaine
LangueSupportCPlusPlusEN :: FormatSortieSurErreur ()
	{ return "### SortieSurErreur: %s ###"; }


// -------------------------------------------------------------------------

Chaine
LangueSupportCPlusPlusEN :: FormatVariableLogique ()
	{ return "[LogicalVariable_%d \"%s\" -> %s]"; }
Chaine
LangueSupportCPlusPlusEN :: FormatLiaisonVariableLogique ()
	{ return "\n--> Binding free logical variable %s to value %s\n"; }
Chaine
LangueSupportCPlusPlusEN :: FormatVariableLogiqueDejaLiee ()
	{ return "--> Logical variable %s is already bound to value %s"; }


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

LangueSupportCPlusPlusPTR			gLANGUE_SupportCPlusPlus = NULL;


// -------------------------------------------------------------------------
//	InitialiserLanguesSupportCPlusPlus
// -------------------------------------------------------------------------

void
InitialiserLanguesSupportCPlusPlus (Chaine leMnemonique)
	{
	if (gLANGUE_SupportCPlusPlus != NULL)
		delete gLANGUE_SupportCPlusPlus;

	if (leMnemonique == "fr")
		gLANGUE_SupportCPlusPlus = new LangueSupportCPlusPlusFR;
	if (leMnemonique == "en")
		gLANGUE_SupportCPlusPlus = new LangueSupportCPlusPlusEN;
	}
