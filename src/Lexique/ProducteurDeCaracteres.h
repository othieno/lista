// =========================================================================
//	ProducteurDeCaracteres.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __ProducteurDeCaracteres__
#define __ProducteurDeCaracteres__

#include "SupportCPlusPlus.h"

#include "LanguesLexique.h"

#include <iostream>


// -------------------------------------------------------------------------
//	ProducteurDeCaracteres
// -------------------------------------------------------------------------

class ProducteurDeCaracteres
	{
public:											
	virtual							~ ProducteurDeCaracteres ();

	virtual char					LireUnCaractere () = 0;
											//	virtuelle pure
	void								RevenirDUnCaractereEnArriere ();
	
	int								PositionCourante ();

	CharPTR							ExtraireLaChaine (
											int	positionDeDepart,
											int	nombreDeCaracteres );

	void								CopierLaChaine (
											int			positionDeDepart,
											int			nombreDeCaracteres,
											CharPTR		destination );

	virtual bool					FinAtteinte () = 0;
											//	virtuelle pure

	virtual void					ErreurProduction (Chaine message);


protected:

	CharPTR							fPosCaractereCourant;
	CharPTR							fPosDebutTampon;
	CharPTR							fPosFinTampon;
	
	};	//	ProducteurDeCaracteres


// -------------------------------------------------------------------------
//	ProducteurDeCaracteresFichier
// -------------------------------------------------------------------------

class ProducteurDeCaracteresFichier : public ProducteurDeCaracteres
	{
public:
										ProducteurDeCaracteresFichier (
											CharPTR		tampon,
											long			longueurTampon );
											
	virtual							~ ProducteurDeCaracteresFichier ();
	
	char								LireUnCaractere ();
	
	bool								FinAtteinte ();

	};	//	ProducteurDeCaracteresFichier


ProducteurDeCaracteresFichier	* LireLeFichier (
										Chaine	nomDuFichier,
										char		laSentinelle );


// -------------------------------------------------------------------------
//	ProducteurDeCaracteresFlot
// -------------------------------------------------------------------------

const int							kTailleTamponFlot			= 1024;

class ProducteurDeCaracteresFlot : public ProducteurDeCaracteres
	{
public:
										ProducteurDeCaracteresFlot (
											std::istream	* leFlotDEntree = & std::cin,
											char				laSentinelle = '\n',
											long				laTailleDuTampon = kTailleTamponFlot );

	virtual							~ ProducteurDeCaracteresFlot ();

	char								LireUnCaractere ();
	
	bool								FinAtteinte ();


private:

	std::istream					* fFlotDEntree;
	
	CharPTR							fTampon;

	CharPTR							fPosDernierCaractereLu;
	char								fSentinelle;
	bool								fSentinelleRencontree;

	};	//	ProducteurDeCaracteresFlot


ProducteurDeCaracteresFlot	* LireLeFlot (
	std::istream	* leFlotDEntree,
	char				laSentinelle );


#endif /* __ProducteurDeCaracteres__ */
