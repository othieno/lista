// =========================================================================
//	FichierDeCaracteres.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "FichierDeCaracteres.h"

#include "SupportCPlusPlus.h"

#include "Langues.h"

#include "AnalyseurLexicalLista.h"

#include <fcntl.h>	// pour open, O_RDONLY
#include <unistd.h>	// pour read, close, lseek

#include <iostream>

#include <cstdlib>


// -------------------------------------------------------------------------
//	FichierDeCaracteres
// -------------------------------------------------------------------------

FichierDeCaracteres :: FichierDeCaracteres (Chaine nomDuFichier)
	{ fNomDuFichier = nomDuFichier; }

FichierDeCaracteres :: ~ FichierDeCaracteres () {}

void
FichierDeCaracteres :: ErreurFichier (Chaine message)
	{
	std::cout <<
		MiseEnForme (
			gLANGUE_Lexique ->
				FormatErreurFichierDeCaracteres (),
			message,
			fNomDuFichier ) <<
		std::endl;
	exit (1);
	}

void
FichierDeCaracteres :: Ouvrir ()
	{
	fDescripteur = open (
		(CharPTR) fNomDuFichier.c_str (), O_RDONLY );
	
	if (fDescripteur == -1)
		ErreurFichier (
			gLANGUE_Lexique -> 
				PasPuOuvrirLeFichier () );
	}

void
FichierDeCaracteres :: Fermer ()
	{
	if (close (fDescripteur) != 0)
		ErreurFichier (
			gLANGUE_Lexique -> 
				PasPuFermerLeFichier () );
	}

long
FichierDeCaracteres :: Taille ()
	{
	long		tailleDuFichier = lseek (fDescripteur, 0, SEEK_END);
	
	if (tailleDuFichier == -1)
		ErreurFichier (
			gLANGUE_Lexique -> 
				PasPuObtenirLaTailleDuFichier () );
	return tailleDuFichier;
	}

void
FichierDeCaracteres :: Rembobiner ()
	{
	if (lseek (fDescripteur, 0, SEEK_SET) == -1)
		ErreurFichier (
			gLANGUE_Lexique -> 
				PasPuRembobinerLeFichier () );
	}

void
FichierDeCaracteres :: LireDansTampon (
	CharPTR			& leTampon,
	long				& longueurDuTampon,
	char				laSentinelle )
	{
	long		tailleDuFichier = Taille ();

	longueurDuTampon = tailleDuFichier + 1;
			//	on prévoit la place pour la sentinelle
	
	leTampon = AllouerUnTampon (longueurDuTampon);
	
	Rembobiner ();
	
	//	int		nombreCaracteres =
	read (fDescripteur, leTampon, tailleDuFichier);
	
	//	on place la sentinelle en fin de tampon
	leTampon [longueurDuTampon - 1] = laSentinelle;
	}	//	FichierDeCaracteres :: LireDansTampon
