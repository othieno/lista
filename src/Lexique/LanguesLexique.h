// =========================================================================
//	LanguesLexique.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __LanguesLexique__
#define __LanguesLexique__


#include "Langues.h"


// -------------------------------------------------------------------------
//	LangueLexique
// -------------------------------------------------------------------------

class		LangueLexique;
typedef	LangueLexique			* LangueLexiquePTR;

class LangueLexique
	{
public:
										LangueLexique ();

	virtual							~ LangueLexique ();

	//	FichierDeCaracteres
	// -------------------------------------------------------------------------

	virtual Chaine					FormatErreurFichierDeCaracteres () = 0;
											// virtuelle pure

	virtual Chaine					PasPuOuvrirLeFichier () = 0;
											// virtuelle pure
	virtual Chaine					PasPuFermerLeFichier () = 0;
											// virtuelle pure
	virtual Chaine					PasPuObtenirLaTailleDuFichier () = 0;
											// virtuelle pure
	virtual Chaine					PasPuRembobinerLeFichier () = 0;
											// virtuelle pure


	//	ProducteurDeCaracteres
	// -------------------------------------------------------------------------


	virtual Chaine					FormatErreurProductionDeCaracteres () = 0;
											// virtuelle pure

	virtual Chaine					TropDeRetoursArriereSurCaracteres () = 0;
											// virtuelle pure
	virtual Chaine					TamponProductionTropPetit () = 0;
											// virtuelle pure


	//	Lexique
	// -------------------------------------------------------------------------


	virtual Chaine					FormatLocalisationErreur () = 0;
											// virtuelle pure
	virtual Chaine					FormatLocalisationErreurAllege () = 0;
											// virtuelle pure
											
	virtual Chaine					ErreurLexicale () = 0;
											// virtuelle pure
	virtual Chaine					FormatErreurLexicale () = 0;
											// virtuelle pure
	virtual Chaine					FormatErreurLexicaleAllege () = 0;
											// virtuelle pure
											
	virtual Chaine					FormatPositionLexicaleCourante () = 0;
											// virtuelle pure
	virtual Chaine					FormatPositionLexicaleCouranteAllege () = 0;
											// virtuelle pure									
											
	virtual Chaine					AucunTerminalAccepteEncore () = 0;
											// virtuelle pure

	virtual Chaine					FormatCaractereIllegal () = 0;
											// virtuelle pure

	virtual Chaine					TerminalEntier () = 0;
											// virtuelle pure
	virtual Chaine					TerminalFlottant () = 0;
											// virtuelle pure
	virtual Chaine					TerminalChaine () = 0;
											// virtuelle pure

	virtual Chaine					TerminalSequenceur () = 0;
											// virtuelle pure
	virtual Chaine					TerminalIterateur () = 0;
											// virtuelle pure
	virtual Chaine					TerminalIdent () = 0;
											// virtuelle pure

	virtual Chaine					FormatTerminalInconnu () = 0;
											// virtuelle pure
	virtual Chaine					FormatChiffreAttendu () = 0;
											// virtuelle pure
	virtual Chaine					FormatChiffreOuSigneAttendu () = 0;
											// virtuelle pure
	virtual Chaine					FormatCaractereDeChaineSpecialAttendu () = 0;
											// virtuelle pure
	virtual Chaine					FormatCaractereDeFinDeChaineAttendu () = 0;
											// virtuelle pure

	virtual Chaine					PseudoTerminalFin () = 0;
											// virtuelle pure

	virtual Chaine					CodeLexicalementCorrect () = 0;
											// virtuelle pure
	virtual Chaine					CodeLexicalementIncorrect () = 0;
											// virtuelle pure

	};	//	LangueLexique


// -------------------------------------------------------------------------
//	LangueLexiqueFR
// -------------------------------------------------------------------------

class		LangueLexiqueFR;
typedef	LangueLexiqueFR		* LangueLexiqueFRPTR;

class LangueLexiqueFR : public LangueLexique
	{
public:
										LangueLexiqueFR ();

	virtual							~ LangueLexiqueFR ();


	//	FichierDeCaracteres
	// -------------------------------------------------------------------------

	Chaine							FormatErreurFichierDeCaracteres ();

	Chaine							PasPuOuvrirLeFichier ();
	Chaine							PasPuFermerLeFichier ();
	Chaine							PasPuObtenirLaTailleDuFichier ();
	Chaine							PasPuRembobinerLeFichier ();


	//	ProducteurDeCaracteres
	// -------------------------------------------------------------------------

	Chaine							FormatErreurProductionDeCaracteres ();
	
	Chaine							TropDeRetoursArriereSurCaracteres ();
	Chaine							TamponProductionTropPetit ();


	//	Lexique
	// -------------------------------------------------------------------------

	Chaine							FormatLocalisationErreur ();
	Chaine							FormatLocalisationErreurAllege ();

	Chaine							ErreurLexicale ();
	Chaine							FormatErreurLexicale ();
	Chaine							FormatErreurLexicaleAllege ();
	
	Chaine							FormatPositionLexicaleCourante ();
	Chaine							FormatPositionLexicaleCouranteAllege ();
	
	Chaine							AucunTerminalAccepteEncore ();

	Chaine							FormatCaractereIllegal ();

	Chaine							TerminalEntier ();
	Chaine							TerminalFlottant ();
	Chaine							TerminalChaine ();

	Chaine							TerminalSequenceur ();
	Chaine							TerminalIterateur ();
	Chaine							TerminalIdent ();
	
	Chaine							FormatTerminalInconnu ();
	Chaine							FormatChiffreAttendu ();
	Chaine							FormatChiffreOuSigneAttendu ();
	Chaine							FormatCaractereDeChaineSpecialAttendu ();
	Chaine							FormatCaractereDeFinDeChaineAttendu ();

	Chaine							PseudoTerminalFin ();

	Chaine							CodeLexicalementCorrect ();
	Chaine							CodeLexicalementIncorrect ();

	};	//	LangueLexiqueFR


// -------------------------------------------------------------------------
//	LangueLexiqueEN
// -------------------------------------------------------------------------

class		LangueLexiqueEN;
typedef	LangueLexiqueEN		* LangueLexiqueENPTR;

class LangueLexiqueEN : public LangueLexique
	{
public:
										LangueLexiqueEN ();

	virtual							~ LangueLexiqueEN ();


	//	FichierDeCaracteres
	// -------------------------------------------------------------------------

	Chaine							FormatErreurFichierDeCaracteres ();

	Chaine							PasPuOuvrirLeFichier ();
	Chaine							PasPuFermerLeFichier ();
	Chaine							PasPuObtenirLaTailleDuFichier ();
	Chaine							PasPuRembobinerLeFichier ();


	//	ProducteurDeCaracteres
	// -------------------------------------------------------------------------

	Chaine							FormatErreurProductionDeCaracteres ();
	
	Chaine							TropDeRetoursArriereSurCaracteres ();
	Chaine							TamponProductionTropPetit ();


	//	Lexique
	// -------------------------------------------------------------------------

	Chaine							FormatLocalisationErreur ();
	Chaine							FormatLocalisationErreurAllege ();

	Chaine							ErreurLexicale ();
	Chaine							FormatErreurLexicale ();
	Chaine							FormatErreurLexicaleAllege ();
	
	Chaine							FormatPositionLexicaleCourante ();
	Chaine							FormatPositionLexicaleCouranteAllege ();

	Chaine							AucunTerminalAccepteEncore ();

	Chaine							FormatCaractereIllegal ();

	Chaine							TerminalEntier ();
	Chaine							TerminalFlottant ();
	Chaine							TerminalChaine ();

	Chaine							TerminalSequenceur ();
	Chaine							TerminalIterateur ();
	Chaine							TerminalIdent ();
	
	Chaine							FormatTerminalInconnu ();
	Chaine							FormatChiffreAttendu ();
	Chaine							FormatChiffreOuSigneAttendu ();
	Chaine							FormatCaractereDeChaineSpecialAttendu ();
	Chaine							FormatCaractereDeFinDeChaineAttendu ();

	Chaine							PseudoTerminalFin ();

	Chaine							CodeLexicalementCorrect ();
	Chaine							CodeLexicalementIncorrect ();

	};	//	LangueLexiqueEN


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

extern LangueLexiquePTR			gLANGUE_Lexique;


// -------------------------------------------------------------------------
//	InitialiserLanguesLexique
// -------------------------------------------------------------------------

void									InitialiserLanguesLexique (
											Chaine leMnemonique = LANGUE_PAR_DEFAUT );


#endif /* __LanguesLexique__ */
