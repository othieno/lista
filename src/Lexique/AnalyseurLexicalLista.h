// =========================================================================
//	AnalyseurLexicalLista.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __AnalyseurLexicalLista__
#define __AnalyseurLexicalLista__


#include "ProducteurDeCaracteres.h"

#include "DecodageDOptionsLexique.h"


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista
// --------------------------------------------------------------------------

class AnalyseurLexicalLista
	{
public:
										AnalyseurLexicalLista (
											ProducteurDeCaracteres	* leProducteur,
											OptionsLexiquePTR			lesOptionsLexique );
											
	virtual							~ AnalyseurLexicalLista ();

	Chaine							DescriptionPositionCourante ();

	TerminalP						AccepterUnTerminal ();

	TerminalP						AccepterUneChaine ();
	TerminalP						AccepterUnIdent ();
	TerminalP						AccepterUnNombre ();

	void								CompterFinDeLigne ();

	void								EchoDesCaracteresAcceptes ();
	
	double							DernierNombreAccepte ();
	Chaine							DernierIdentAccepte ();
	Chaine							DerniereChaineAcceptee ();

	Chaine							DescriptionTerminalCourant ();

	virtual void					ErreurLexicale (Chaine leFormat);

	Chaine							TerminalSousFormeTextuelle (
											TerminalP leTerminalP );

	void								Analyser ();

	bool								SourceCorrectLexicalement ();


private:

	ProducteurDeCaracteres		* fProducteurDeCaracteres;
	OptionsLexiquePTR				fOptionsLexique;
	
	char								fCaractereCourant;
	int								fNumLigneCourante;

	//	on gere les deux lignes precedant la ligne courante
	int								fDebutLigneCourante;
	int								fDebutLigneCourante_1;
											// la precedente
	int								fDebutLigneCourante_2;
											// la precedente de la precedente

	int								fPositionDebutDuTerminal;
	int								fTailleTamponAuxiliaire;
	CharPTR							fTamponAuxiliaire;
	
	bool								fPremierTerminalDejaAccepte;
	TerminalP						fTerminalPCourant;

	double							fNombre;

	CharPTR							fIdent;
	int								fLongueurIdent;

	Chaine							fChaine;
	
	void								Avancer ();
	void								Reculer ();
	int								PositionDuCaractere ();

	void								AccepterUnExposant ();

	void								AppondreLeFragmentALaChaine (Chaine leFragment);

	bool								fSourceCorrectLexicalement;
	};	//	AnalyseurLexicalLista


inline
void
AnalyseurLexicalLista :: Avancer ()
	{
	fCaractereCourant =
		fProducteurDeCaracteres -> LireUnCaractere ();
	}

inline
void
AnalyseurLexicalLista :: Reculer ()
	{
	fProducteurDeCaracteres -> RevenirDUnCaractereEnArriere ();
	}

inline
int
AnalyseurLexicalLista :: PositionDuCaractere ()
	{
	return fProducteurDeCaracteres -> PositionCourante ();
	}


inline
void 
AnalyseurLexicalLista :: AppondreLeFragmentALaChaine (Chaine leFragment)
	{
	fChaine += leFragment;
	}


// --------------------------------------------------------------------------
//	Derniers terminaux acceptes
// --------------------------------------------------------------------------

inline
double
AnalyseurLexicalLista:: DernierNombreAccepte ()
	{ return fNombre; }

inline
Chaine
AnalyseurLexicalLista :: DernierIdentAccepte ()
	{ return fIdent; }

inline
Chaine
AnalyseurLexicalLista :: DerniereChaineAcceptee ()
	{ return fChaine; }


#endif /* __AnalyseurLexicalLista__ */
