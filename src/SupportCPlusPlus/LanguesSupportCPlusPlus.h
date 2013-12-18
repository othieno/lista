// =========================================================================
//	LanguesSupportCPlusPlus.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __LanguesSupportCPlusPlus__
#define __LanguesSupportCPlusPlus__


#include "Types.h"


// -------------------------------------------------------------------------
//	LangueSupportCPlusPlus
// -------------------------------------------------------------------------

class		LangueSupportCPlusPlus;
typedef	LangueSupportCPlusPlus		* LangueSupportCPlusPlusPTR;

class LangueSupportCPlusPlus
	{
public:
										LangueSupportCPlusPlus ();

	virtual							~ LangueSupportCPlusPlus ();


	virtual Chaine					DebordementDuTas () = 0;
											// virtuelle pure
	virtual Chaine					FormatDebordementDuTamponDeFLireChaine () = 0;
											// virtuelle pure

	virtual Chaine					FormatContenuDuFichierSource () = 0;
											// virtuelle pure

	virtual Chaine					FormatPasPuEcrireSurLeFichier () = 0;
											// virtuelle pure
	virtual Chaine					FormatPasPuLireDuFichier () = 0;
											// virtuelle pure

	virtual Chaine					FormatSortieSurErreur () = 0;
											// virtuelle pure

	virtual Chaine					FormatVariableLogique () = 0;
											// virtuelle pure
	virtual Chaine					FormatLiaisonVariableLogique () = 0;
											// virtuelle pure
	virtual Chaine					FormatVariableLogiqueDejaLiee () = 0;
											// virtuelle pure

	};	//	LangueSupportCPlusPlus


// -------------------------------------------------------------------------
//	LangueSupportCPlusPlusFR
// -------------------------------------------------------------------------

class		LangueSupportCPlusPlusFR;
typedef	LangueSupportCPlusPlusFR	* LangueSupportCPlusPlusFRPTR;

class LangueSupportCPlusPlusFR : public LangueSupportCPlusPlus
	{
public:
										LangueSupportCPlusPlusFR ();

	virtual							~ LangueSupportCPlusPlusFR ();


	Chaine							DebordementDuTas ();
	Chaine							FormatDebordementDuTamponDeFLireChaine ();

	Chaine							FormatContenuDuFichierSource ();

	Chaine							FormatPasPuEcrireSurLeFichier ();
	Chaine							FormatPasPuLireDuFichier ();

	Chaine							FormatSortieSurErreur ();

	Chaine							FormatVariableLogique ();
	Chaine							FormatLiaisonVariableLogique ();
	Chaine							FormatVariableLogiqueDejaLiee ();

	};	//	LangueSupportCPlusPlusFR


// -------------------------------------------------------------------------
//	LangueSupportCPlusPlusEN
// -------------------------------------------------------------------------

class		LangueSupportCPlusPlusEN;
typedef	LangueSupportCPlusPlusEN	* LangueSupportCPlusPlusENPTR;

class LangueSupportCPlusPlusEN : public LangueSupportCPlusPlus
	{
public:
										LangueSupportCPlusPlusEN ();

	virtual							~ LangueSupportCPlusPlusEN ();


	Chaine							DebordementDuTas ();
	Chaine							FormatDebordementDuTamponDeFLireChaine ();

	Chaine							FormatContenuDuFichierSource ();

	Chaine							FormatPasPuEcrireSurLeFichier ();
	Chaine							FormatPasPuLireDuFichier ();

	Chaine							FormatSortieSurErreur ();

	Chaine							FormatVariableLogique ();
	Chaine							FormatLiaisonVariableLogique ();
	Chaine							FormatVariableLogiqueDejaLiee ();

	};	//	LangueSupportCPlusPlusEN


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

extern LangueSupportCPlusPlusPTR		gLANGUE_SupportCPlusPlus;


// -------------------------------------------------------------------------
//	InitialiserLanguesSupportCPlusPlus
// -------------------------------------------------------------------------

void									InitialiserLanguesSupportCPlusPlus (
											Chaine leMnemonique = LANGUE_PAR_DEFAUT );


#endif /* __LanguesSupportCPlusPlus__ */

