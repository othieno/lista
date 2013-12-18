// =========================================================================
//	ProducteurDeCaracteres.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "ProducteurDeCaracteres.h"

#include "FichierDeCaracteres.h"

#include "Langues.h"

#include "AnalyseurLexicalLista.h"

#include <iostream>

#include <cstdlib>

#include <cstring>


// -------------------------------------------------------------------------
//	ProducteurDeCaracteres
// -------------------------------------------------------------------------

ProducteurDeCaracteres :: ~ ProducteurDeCaracteres () {}

void
ProducteurDeCaracteres :: ErreurProduction (Chaine message)
	{
	std::cout <<
		MiseEnForme (
			gLANGUE_Lexique ->
				FormatErreurProductionDeCaracteres (),
			message ) <<
		std::endl;
	exit (1);
	}

void
ProducteurDeCaracteres :: RevenirDUnCaractereEnArriere ()
	{
	if (-- fPosCaractereCourant < fPosDebutTampon)
		ErreurProduction (
			gLANGUE_Lexique ->
				TropDeRetoursArriereSurCaracteres () );
	}

int
ProducteurDeCaracteres :: PositionCourante ()
	{ return fPosCaractereCourant - fPosDebutTampon; }

CharPTR
ProducteurDeCaracteres :: ExtraireLaChaine (
	int	positionDeDepart,
	int	nombreDeCaracteres )
	{
	CharPTR
				res = AllouerUnTampon (nombreDeCaracteres + 1);

	memcpy (
		res,
		fPosDebutTampon + positionDeDepart,
		nombreDeCaracteres );
	res [nombreDeCaracteres] = L'\0';

//	std::cout << "res = " << res << std::endl << std::endl;

	return res;
	}

void
ProducteurDeCaracteres :: CopierLaChaine (
	int			positionDeDepart,
	int			nombreDeCaracteres,
	CharPTR	destination )
	{
	memcpy (
		destination,
		fPosDebutTampon + positionDeDepart,
		nombreDeCaracteres );
	destination [nombreDeCaracteres] = L'\0';
	}


// -------------------------------------------------------------------------
//	ProducteurDeCaracteresFichier
// -------------------------------------------------------------------------

ProducteurDeCaracteresFichier :: ProducteurDeCaracteresFichier (
	CharPTR	tampon,
	long			longueurTampon )
	{
	fPosDebutTampon = tampon;
	fPosFinTampon = tampon + longueurTampon - 1;
	
	fPosCaractereCourant = fPosDebutTampon - 1;
		//	on se place avant le premier caractère effectif
	}

ProducteurDeCaracteresFichier :: ~ ProducteurDeCaracteresFichier () {}

char
ProducteurDeCaracteresFichier :: LireUnCaractere ()
	{
	return
		(++ fPosCaractereCourant) < fPosFinTampon
			?	(* fPosCaractereCourant)
			: (* fPosFinTampon);
	}

bool
ProducteurDeCaracteresFichier :: FinAtteinte ()
	{ return fPosCaractereCourant >= fPosFinTampon; }


ProducteurDeCaracteresFichier * LireLeFichier (
	Chaine	nomDuFichier,
	char		laSentinelle )
	{
	CharPTR
				leTampon;
	long		longueurDuTampon;
	
	FichierDeCaracteres
				leFichierDeCaracteres (nomDuFichier);

	leFichierDeCaracteres.Ouvrir ();
	leFichierDeCaracteres.LireDansTampon (
		leTampon, longueurDuTampon, laSentinelle );
	leFichierDeCaracteres.Fermer ();
	
	return
		new ProducteurDeCaracteresFichier (leTampon, longueurDuTampon);
	}	//	LireLeFichier


// -------------------------------------------------------------------------
//	ProducteurDeCaracteresFlot
// -------------------------------------------------------------------------

ProducteurDeCaracteresFlot :: ProducteurDeCaracteresFlot (
	std::istream	* leFlotDEntree,
	char				laSentinelle,
	long				laTailleDuTampon )
	{
	fFlotDEntree = leFlotDEntree;

	fSentinelle = laSentinelle;
	fSentinelleRencontree = false;
	
	fTampon = AllouerUnTampon (laTailleDuTampon);
	
	fPosDebutTampon = fTampon;
	fPosFinTampon = fTampon + laTailleDuTampon - 1;
	
	fPosCaractereCourant = fPosDebutTampon - 1;
		//	on se place avant le premier caractère effectif
	fPosDernierCaractereLu = fPosCaractereCourant;
	}	//	ProducteurDeCaracteresFlot :: ProducteurDeCaracteresFlot

ProducteurDeCaracteresFlot :: ~ ProducteurDeCaracteresFlot () {}

char
ProducteurDeCaracteresFlot :: LireUnCaractere ()
	{
	//	le dernier caractère du tampon est réservé
	//	pour pouvoir y placerla sentinelle le moment venu
	++ fPosCaractereCourant;
	if (fPosCaractereCourant > fPosDernierCaractereLu)
		//	on doit lire un nouveau caractère
		{
		if (fPosCaractereCourant >= fPosFinTampon)
			ErreurProduction (
				gLANGUE_Lexique ->
					TamponProductionTropPetit () );
		fFlotDEntree -> get (* fPosCaractereCourant);
		fPosDernierCaractereLu = fPosCaractereCourant;
		}
	return (* fPosCaractereCourant);
	}	//	ProducteurDeCaracteresFlot :: LireUnCaractere

bool
ProducteurDeCaracteresFlot :: FinAtteinte ()
	{
	if ((* fPosCaractereCourant) == fSentinelle)
		{
		if (fSentinelleRencontree)
			return true;

		fSentinelleRencontree = true;
		
		//	on place la sentinelle comme dernier caractère lu
		fPosDernierCaractereLu += 1;
		(* fPosDernierCaractereLu) = fSentinelle;
		}
	return false;
	}	//	ProducteurDeCaracteresFlot :: FinAtteinte


ProducteurDeCaracteresFlot	*
LireLeFlot (
	std::istream	* leFlotDEntree,
	char				laSentinelle )
	{
	return
		new ProducteurDeCaracteresFlot (leFlotDEntree, laSentinelle);
	}
