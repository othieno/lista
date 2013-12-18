// =========================================================================
//	LanguesLexique.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "LanguesLexique.h"

#include "Langues.h"

#include <iostream>


// -------------------------------------------------------------------------
//	LangueLexique
// -------------------------------------------------------------------------

LangueLexique :: LangueLexique ()
	{}

LangueLexique :: ~ LangueLexique ()
	{}


// -------------------------------------------------------------------------
//	LangueLexiqueFR
// -------------------------------------------------------------------------

LangueLexiqueFR :: LangueLexiqueFR ()
	{}

LangueLexiqueFR :: ~ LangueLexiqueFR ()
	{}


// -------------------------------------------------------------------------
//	FichierDeCaracteres
// -------------------------------------------------------------------------

Chaine
LangueLexiqueFR :: FormatErreurFichierDeCaracteres ()
	{ return "### Erreur sur le fichier: %s, le fichier = '%s' ###"; }

Chaine
LangueLexiqueFR :: PasPuOuvrirLeFichier ()
	{ return "pas pu ouvrir"; }
Chaine
LangueLexiqueFR :: PasPuFermerLeFichier ()
	{ return "pas pu fermer"; }
Chaine
LangueLexiqueFR :: PasPuObtenirLaTailleDuFichier ()
	{ return "pas pu obtenir la taille"; }
Chaine
LangueLexiqueFR :: PasPuRembobinerLeFichier ()
	{ return "pas pu rembobiner"; }


// -------------------------------------------------------------------------
//	ProducteurDeCaracteres
// -------------------------------------------------------------------------

Chaine
LangueLexiqueFR ::  FormatErreurProductionDeCaracteres ()
	{ return "Erreur de production de caracteres: %s"; }

Chaine
LangueLexiqueFR ::  TropDeRetoursArriereSurCaracteres ()
	{ return "Trop de retours en arriere sur des caracteres"; }
Chaine
LangueLexiqueFR ::  TamponProductionTropPetit ()
	{ return "Le tampon de production est trop petit"; }


// -------------------------------------------------------------------------
//	Lexique
// -------------------------------------------------------------------------

Chaine
LangueLexiqueFR :: FormatLocalisationErreur ()
	{
	return
		"### %s: %s ###\n"
		"--> Terminal courant: %s\n"
		"%s";
	}
Chaine
LangueLexiqueFR :: FormatLocalisationErreurAllege ()
	{
	return
		"### %s %s: %s ###\n"
		"--> Terminal courant: %s";
	}

Chaine
LangueLexiqueFR :: ErreurLexicale ()
	{ return "Erreur lexicale"; }
Chaine
LangueLexiqueFR :: FormatErreurLexicale ()
	{
	return
		"### Erreur lexicale: %s ###\n"
		"--> Terminal courant: %s\n"
		"%s";
	}
Chaine
LangueLexiqueFR :: FormatErreurLexicaleAllege ()
	{
	return
		"### Erreur lexicale %s: %s ###\n"
		"--> Terminal courant: %s";
	}

Chaine
LangueLexiqueFR :: FormatPositionLexicaleCourante ()
	{
	return
		"\tLigne %d, caractere numero %d, code ascii %d, char = %c\n%s\n%s\n%s\n";
	}
Chaine
LangueLexiqueFR :: FormatPositionLexicaleCouranteAllege ()
	{
	return
		"[L%3d:C%3d]";
	}

Chaine
LangueLexiqueFR :: AucunTerminalAccepteEncore ()
	{ return "-- Aucun terminal accepte encore --"; }

Chaine
LangueLexiqueFR :: FormatCaractereIllegal ()
	{ return "Caractere illegal '%c'"; }

Chaine
LangueLexiqueFR :: TerminalEntier ()
	{ return "Entier"; }
Chaine
LangueLexiqueFR :: TerminalFlottant ()
	{ return "Reel"; }

Chaine
LangueLexiqueFR :: TerminalChaine ()
	{ return "Chaine"; }

Chaine
LangueLexiqueFR :: TerminalSequenceur ()
	{ return "Sequenceur"; }

Chaine
LangueLexiqueFR :: TerminalIterateur ()
	{ return "Iterateur"; }

Chaine
LangueLexiqueFR :: TerminalIdent ()
	{ return "Ident"; }

Chaine
LangueLexiqueFR :: FormatTerminalInconnu ()
	{ return "### Terminal inconnu: %d ###"; }

Chaine
LangueLexiqueFR :: FormatChiffreAttendu ()
	{ return "Un chiffre est attendu (%c)"; }

Chaine
LangueLexiqueFR :: FormatChiffreOuSigneAttendu ()
	{ return "Un chiffre ou '+' ou '-' est attendu (%c)"; }

Chaine
LangueLexiqueFR :: FormatCaractereDeChaineSpecialAttendu ()
	{
	return
		"'\"', '\\', 'n' ou 't' est attendu aprs '\\'"
		" dans une chaine de caractres (%c)";
	}

Chaine
LangueLexiqueFR :: FormatCaractereDeFinDeChaineAttendu ()
	{ return "'\"' est attendu comme fin de chaine (%c)"; }
	
Chaine
LangueLexiqueFR :: PseudoTerminalFin ()
	{ return "--- FIN ---"; }


// -------------------------------------------------------------------------

Chaine
LangueLexiqueFR :: CodeLexicalementCorrect ()
	{ return "*** Code Lista lexicalement   correct   ***"; }

Chaine
LangueLexiqueFR :: CodeLexicalementIncorrect ()
	{ return "### Code Lista lexicalement   INCORRECT ###"; }


// -------------------------------------------------------------------------
//	LangueLexiqueEN
// -------------------------------------------------------------------------

LangueLexiqueEN :: LangueLexiqueEN ()
	{}

LangueLexiqueEN :: ~ LangueLexiqueEN ()
	{}


// -------------------------------------------------------------------------
//	FichierDeCaracteres
// -------------------------------------------------------------------------

Chaine
LangueLexiqueEN :: FormatErreurFichierDeCaracteres ()
	{ return "### Error with file: %s, le fichier = '%s' ###"; }

Chaine
LangueLexiqueEN :: PasPuOuvrirLeFichier ()
	{ return "could not open"; }
Chaine
LangueLexiqueEN :: PasPuFermerLeFichier ()
	{ return "could not close"; }
Chaine
LangueLexiqueEN :: PasPuObtenirLaTailleDuFichier ()
	{ return "could not obtain size"; }
Chaine
LangueLexiqueEN :: PasPuRembobinerLeFichier ()
	{ return "could not rewind"; }


// -------------------------------------------------------------------------
//	ProducteurDeCaracteres
// -------------------------------------------------------------------------

Chaine
LangueLexiqueEN ::  FormatErreurProductionDeCaracteres ()
	{ return "Error in character production: %s"; }

Chaine
LangueLexiqueEN ::  TropDeRetoursArriereSurCaracteres ()
	{ return "Too many backtracks on characters"; }
Chaine
LangueLexiqueEN ::  TamponProductionTropPetit ()
	{ return "The production buffer is too small"; }
	

// -------------------------------------------------------------------------
//	Lexique
// -------------------------------------------------------------------------

Chaine
LangueLexiqueEN :: FormatLocalisationErreur ()
	{
	return
		"### %s: %s ###\n"
		"--> Current token: %s\n"
		"%s";
	}
Chaine
LangueLexiqueEN :: FormatLocalisationErreurAllege ()
	{
	return
		"### %s %s: %s ###\n"
		"--> Current token: %s";
	}

Chaine
LangueLexiqueEN :: ErreurLexicale ()
	{ return "Lexical error"; }
Chaine
LangueLexiqueEN :: FormatErreurLexicale ()
	{
	return
		"### Lexical error: %s ###\n"
		"--> Current token: %s\n"
		"%s";
	}
Chaine
LangueLexiqueEN :: FormatErreurLexicaleAllege ()
	{
	return
		"### Lexical error [L%3d:C%3d]: %s ###\n"
		"--> Current token: %s";
	}

Chaine
LangueLexiqueEN :: FormatPositionLexicaleCourante ()
	{
	return
		"\tLine %d, character number %d, ascii code %d, char = %c\n%s\n%s\n%s\n";
	}
Chaine
LangueLexiqueEN :: FormatPositionLexicaleCouranteAllege ()
	{
	return
		"[L%3d:C%3d]";
	}

Chaine
LangueLexiqueEN :: AucunTerminalAccepteEncore ()
	{ return "-- No token accepted yet --"; }

Chaine
LangueLexiqueEN :: FormatCaractereIllegal ()
	{ return "Illegal character '%c'"; }

Chaine
LangueLexiqueEN :: TerminalEntier ()
	{ return "Integer"; }
Chaine
LangueLexiqueEN :: TerminalFlottant ()
	{ return "Float"; }

Chaine
LangueLexiqueEN :: TerminalChaine ()
	{ return "String"; }

Chaine
LangueLexiqueEN :: TerminalSequenceur ()
	{ return "Sequencer"; }

Chaine
LangueLexiqueEN :: TerminalIterateur ()
	{ return "Iterator"; }

Chaine
LangueLexiqueEN :: TerminalIdent ()
	{ return "Ident"; }

Chaine
LangueLexiqueEN :: FormatTerminalInconnu ()
	{ return "Unknown token: %d"; }

Chaine
LangueLexiqueEN :: FormatChiffreAttendu ()
	{ return "A digit is expected (%c)"; }

Chaine
LangueLexiqueEN :: FormatChiffreOuSigneAttendu ()
	{ return "A digit or '+' or '-' is expected (%c)"; }

Chaine
LangueLexiqueEN :: FormatCaractereDeChaineSpecialAttendu ()
	{
	return
		"'\"', '\\', 'n' or 't' is expected after '\\'"
		" in a character string (%c)";
	}

Chaine
LangueLexiqueEN :: FormatCaractereDeFinDeChaineAttendu ()
	{ return "'\"' is expeced as end of character string (%c)"; }
	
Chaine
LangueLexiqueEN :: PseudoTerminalFin ()
	{ return "--- END ---"; }


// -------------------------------------------------------------------------

Chaine
LangueLexiqueEN :: CodeLexicalementCorrect ()
	{ return "*** Lista code lexically     correct   ***"; }

Chaine
LangueLexiqueEN :: CodeLexicalementIncorrect ()
	{ return "### Lista code lexically     INCORRECT ###"; }


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

LangueLexiquePTR				gLANGUE_Lexique				= NULL;


// -------------------------------------------------------------------------
//	InitialiserLanguesLexique
// -------------------------------------------------------------------------

void
InitialiserLanguesLexique (Chaine leMnemonique)
	{
	if (gLANGUE_Lexique != NULL)
		delete gLANGUE_Lexique;

	if (leMnemonique == "fr")
		gLANGUE_Lexique = new LangueLexiqueFR;
	if (leMnemonique == "en")
		gLANGUE_Lexique = new LangueLexiqueEN;
	}
