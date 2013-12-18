// =========================================================================
//	AnalyseurDescendantLista.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __AnalyseurDescendantLista__
#define __AnalyseurDescendantLista__


#include "AnalyseurLexicalLista.h"

#include "DecodageDOptionsSyntaxe.h"


// --------------------------------------------------------------------------
//	DescriptionTerminal
// --------------------------------------------------------------------------

struct DescriptionTerminal
	// pas une union, qui ne pourrait contenir des objets
	{
	double							fNombre;
	Chaine							fIdent;
	Chaine							fChaine;
	};


// --------------------------------------------------------------------------
//	AnalyseurDescendantLista
// --------------------------------------------------------------------------

class AnalyseurDescendantLista
	{
public:

										AnalyseurDescendantLista (
											AnalyseurLexicalLista	* lAnalyseurLexical,
											OptionsSyntaxePTR			lesOptionsSyntaxe );

	void								Analyser ();

private:

	AnalyseurLexicalLista		* fAnalyseurLexical;

	OptionsSyntaxePTR				fOptionsSyntaxe;

	bool								fSourceCorrectSyntaxiquement;

	TerminalP						fTerminalPCourant;
	void								Avancer ();

	void								Programme ();

	void								DefinitionDeFonction ();
	void								EnteteDeFonction ();
	void								Parametres ();

	void								Evaluation ();

	void								SequenceDExpressions ();

	void								Expression ();
	void								Terme ();
	void								Facteur ();

	void								Liste ();

	void								AppelDeFonction ();
	void								Arguments ();

	void								ErreurSyntaxique (Chaine leMessage);

	};	//	AnalyseurDescendantLista


inline
void
AnalyseurDescendantLista :: Avancer ()
	{
	fTerminalPCourant = fAnalyseurLexical -> AccepterUnTerminal ();
	}


#endif /* __AnalyseurDescendantLista__ */
