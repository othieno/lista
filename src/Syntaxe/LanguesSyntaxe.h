// =========================================================================
//	LanguesSyntaxe.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __LanguesSyntaxe__
#define __LanguesSyntaxe__


#include "LanguesLexique.h"


// -------------------------------------------------------------------------
//	LangueSyntaxe
// -------------------------------------------------------------------------

class		LangueSyntaxe;
typedef	LangueSyntaxe			* LangueSyntaxePTR;

class LangueSyntaxe
	{
public:
										LangueSyntaxe ();

	virtual							~ LangueSyntaxe ();


	//	Syntaxe
	// -------------------------------------------------------------------------

	virtual Chaine					ErreurSyntaxique () = 0;
											// virtuelle pure

	virtual Chaine					FormatTerminalAttendu () = 0;
											// virtuelle pure

	virtual Chaine					Expression () = 0;
											// virtuelle pure
	virtual Chaine					Terme () = 0;
											// virtuelle pure
	virtual Chaine					Facteur () = 0;
											// virtuelle pure
	virtual Chaine					FacteurMalForme () = 0;
											// virtuelle pure

	virtual Chaine					VirguleAttendueApresConditionDUnSi () = 0;
											// virtuelle pure
	virtual Chaine					VirguleAttendueApresPartieAlorsDUnSi () = 0;
											// virtuelle pure
	virtual Chaine					FormatVirguleAttendueDansUneSequence () = 0;
											// virtuelle pure

	virtual Chaine					IdentOuInterrogeAttendu () = 0;
											// virtuelle pure
	virtual Chaine					IdentAttenduCommeNomDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					EgaleAttenduApresEnteteDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					IdentAttenduCommeParametreDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					PointVirguleAttenduApresUneDefinitionDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatPointVirguleAttenduApresUneDefinitionDeFonction () = 0;
											// virtuelle pure

	virtual Chaine					TraceDUneDefinitionDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatTraceDUneDefinitionDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatTraceDUneEvaluation () = 0;
											// virtuelle pure

	virtual Chaine					ParentheseAttendueApresDesParametres () = 0;
											// virtuelle pure
	virtual Chaine					ArgumentsSuperflusPourUneNonFonction () = 0;
											// virtuelle pure
	virtual Chaine					ListeDeParametresInconnus () = 0;
											// virtuelle pure
	virtual Chaine					ApresUneListeDArgumentsSuperflus () = 0;
											// virtuelle pure

	virtual Chaine					PointVirguleAttenduApresUneEvaluation () = 0;
											// virtuelle pure
	virtual Chaine					TraceDUneEvaluation () = 0;
											// virtuelle pure
	virtual Chaine					ParentheseAttendueApresExpressionParenthesee () = 0;
											// virtuelle pure

	virtual Chaine					VirguleAttendueDansUneIteration () = 0;
											// virtuelle pure
	virtual Chaine					ParentheseAttendueApresUneIteration () = 0;
											// virtuelle pure

	virtual Chaine					ParentheseInattendueDansAppelDeFonctionNonParametree () = 0;
											// virtuelle pure

	virtual Chaine					FormatParentheseAttendueAvantUnAppelDeFonctionPredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FormatArgumentsAttendusDansAppelDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					ParentheseAttendueApresUnAppelDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatParentheseAttendueApresUnAppelDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatVirguleAttendueApresUnArgumentDAppel () = 0;
											// virtuelle pure

	virtual Chaine					ParentheseAttendueApresUneSequence () = 0;
											// virtuelle pure
											
	virtual Chaine					SequenceDExpressionsAEvaluer () = 0;
											// virtuelle pure

	virtual Chaine					CodeSyntaxiquementCorrect () = 0;
											// virtuelle pure
	virtual Chaine					CodeSyntaxiquementIncorrect () = 0;
											// virtuelle pure

	};	//	LangueSyntaxe


// -------------------------------------------------------------------------
//	LangueSyntaxeFR
// -------------------------------------------------------------------------

class		LangueSyntaxeFR;
typedef	LangueSyntaxeFR		* LangueSyntaxeFRPTR;

class LangueSyntaxeFR : public LangueSyntaxe
	{
public:
										LangueSyntaxeFR ();

	virtual							~ LangueSyntaxeFR ();


	//	Syntaxe
	// -------------------------------------------------------------------------

	Chaine							ErreurSyntaxique ();

	Chaine							FormatTerminalAttendu ();

	Chaine							Expression ();
	Chaine							Terme ();
	Chaine							Facteur ();
	Chaine							FacteurMalForme ();

	Chaine							VirguleAttendueApresConditionDUnSi ();
	Chaine							VirguleAttendueApresPartieAlorsDUnSi ();
	Chaine							FormatVirguleAttendueDansUneSequence ();

	Chaine							IdentOuInterrogeAttendu ();
	Chaine							IdentAttenduCommeNomDeFonction ();
	Chaine							EgaleAttenduApresEnteteDeFonction ();
	Chaine							IdentAttenduCommeParametreDeFonction ();
	Chaine							PointVirguleAttenduApresUneDefinitionDeFonction ();
	Chaine							FormatPointVirguleAttenduApresUneDefinitionDeFonction ();

	Chaine							TraceDUneDefinitionDeFonction ();
	Chaine							FormatTraceDUneDefinitionDeFonction ();
	Chaine							FormatTraceDUneEvaluation ();

	Chaine							ParentheseAttendueApresDesParametres ();
	Chaine							ArgumentsSuperflusPourUneNonFonction ();
	Chaine							ListeDeParametresInconnus ();
	Chaine							ApresUneListeDArgumentsSuperflus ();

	Chaine							PointVirguleAttenduApresUneEvaluation ();
	Chaine							TraceDUneEvaluation ();
	Chaine							ParentheseAttendueApresExpressionParenthesee ();

	Chaine							VirguleAttendueDansUneIteration ();
	Chaine							ParentheseAttendueApresUneIteration ();

	Chaine							ParentheseInattendueDansAppelDeFonctionNonParametree ();
	Chaine							FormatParentheseAttendueAvantUnAppelDeFonctionPredefinie ();
	Chaine							FormatArgumentsAttendusDansAppelDeFonction ();
	Chaine							ParentheseAttendueApresUnAppelDeFonction ();
	Chaine							FormatParentheseAttendueApresUnAppelDeFonction ();
	Chaine							FormatVirguleAttendueApresUnArgumentDAppel ();

	Chaine							ParentheseAttendueApresUneSequence ();

	Chaine							SequenceDExpressionsAEvaluer ();

	Chaine							CodeSyntaxiquementCorrect ();
	Chaine							CodeSyntaxiquementIncorrect ();

	};	//	LangueSyntaxeFR


// -------------------------------------------------------------------------
//	LangueSyntaxeEN
// -------------------------------------------------------------------------

class		LangueSyntaxeEN;
typedef	LangueSyntaxeEN		* LangueSyntaxeENPTR;

class LangueSyntaxeEN : public LangueSyntaxe
	{
public:
										LangueSyntaxeEN ();

	virtual							~ LangueSyntaxeEN ();


	//	Syntaxe
	// -------------------------------------------------------------------------

	Chaine							ErreurSyntaxique ();

	Chaine							FormatTerminalAttendu ();

	Chaine							Expression ();
	Chaine							Terme ();
	Chaine							Facteur ();
	Chaine							FacteurMalForme ();

	Chaine							VirguleAttendueApresConditionDUnSi ();
	Chaine							VirguleAttendueApresPartieAlorsDUnSi ();
	Chaine							FormatVirguleAttendueDansUneSequence ();

	Chaine							IdentOuInterrogeAttendu ();
	Chaine							IdentAttenduCommeNomDeFonction ();
	Chaine							EgaleAttenduApresEnteteDeFonction ();
	Chaine							IdentAttenduCommeParametreDeFonction ();
	Chaine							PointVirguleAttenduApresUneDefinitionDeFonction ();
	Chaine							FormatPointVirguleAttenduApresUneDefinitionDeFonction ();

	Chaine							TraceDUneDefinitionDeFonction ();
	Chaine							FormatTraceDUneDefinitionDeFonction ();
	Chaine							FormatGrapheSemantiqueDuCoprsDUneFonction ();
	Chaine							FormatFormePostfixeeDuCoprsDUneFonction ();
	Chaine							FormatTraceDUneEvaluation ();
	Chaine							GrapheSemantiqueDeLaSequenceDExpressionsAEvaluer ();
	Chaine							FormePostfixeeDeLaSequenceDExpressionsAEvaluer ();

	Chaine							ParentheseAttendueApresDesParametres ();
	Chaine							ArgumentsSuperflusPourUneNonFonction ();
	Chaine							ListeDeParametresInconnus ();
	Chaine							ApresUneListeDArgumentsSuperflus ();

	Chaine							PointVirguleAttenduApresUneEvaluation ();
	Chaine							TraceDUneEvaluation ();
	Chaine							ParentheseAttendueApresExpressionParenthesee ();

	Chaine							VirguleAttendueDansUneIteration ();
	Chaine							ParentheseAttendueApresUneIteration ();

	Chaine							ParentheseInattendueDansAppelDeFonctionNonParametree ();
	Chaine							FormatParentheseAttendueAvantUnAppelDeFonctionPredefinie ();
	Chaine							FormatArgumentsAttendusDansAppelDeFonction ();
	Chaine							ParentheseAttendueApresUnAppelDeFonction ();
	Chaine							FormatParentheseAttendueApresUnAppelDeFonction ();
	Chaine							FormatVirguleAttendueApresUnArgumentDAppel ();

	Chaine							ParentheseAttendueApresUneSequence ();

	Chaine							SequenceDExpressionsAEvaluer ();

	Chaine							CodeSyntaxiquementCorrect ();
	Chaine							CodeSyntaxiquementIncorrect ();

	};	//	LangueSyntaxeEN


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

extern LangueSyntaxePTR			gLANGUE_Syntaxe;


// -------------------------------------------------------------------------
//	InitialiserLanguesSyntaxe
// -------------------------------------------------------------------------

void									InitialiserLanguesSyntaxe (
											Chaine leMnemonique = LANGUE_PAR_DEFAUT );


#endif /* __LanguesSyntaxe__ */
