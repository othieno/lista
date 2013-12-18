// =========================================================================
//	LanguesSyntaxe.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "LanguesSyntaxe.h"

#include "Langues.h"

#include <iostream>


// -------------------------------------------------------------------------
//	LangueSyntaxe
// -------------------------------------------------------------------------

LangueSyntaxe :: LangueSyntaxe ()
	{}

LangueSyntaxe :: ~ LangueSyntaxe ()
	{}


// -------------------------------------------------------------------------
//	LangueSyntaxeFR
// -------------------------------------------------------------------------

LangueSyntaxeFR :: LangueSyntaxeFR ()
	{}

LangueSyntaxeFR :: ~ LangueSyntaxeFR ()
	{}


// -------------------------------------------------------------------------

Chaine
LangueSyntaxeFR :: ErreurSyntaxique ()
	{ return "ERREUR syntaxique"; }

Chaine
LangueSyntaxeFR :: FormatTerminalAttendu ()
	{ return "Terminal '%s' attendu %s"; }

Chaine
LangueSyntaxeFR :: Expression ()
	{ return "expression"; }
Chaine
LangueSyntaxeFR :: Terme ()
	{ return "terme"; }
Chaine
LangueSyntaxeFR :: Facteur ()
	{ return "facteur"; }
Chaine
LangueSyntaxeFR :: FacteurMalForme ()
	{
	return
		"NOMBRE, CHAINE, IDENT ou EXPRESSION parenthesee "
		"attendu comme facteur";
	}

Chaine
LangueSyntaxeFR :: VirguleAttendueApresConditionDUnSi ()
	{ return "',' attendu apres la condition d'un 'Si'"; }
Chaine
LangueSyntaxeFR :: VirguleAttendueApresPartieAlorsDUnSi ()
	{ return "',' attendu apres la partie 'alors' d'un 'Si'"; }
Chaine
LangueSyntaxeFR :: FormatVirguleAttendueDansUneSequence ()
	{ return "',' attendu entre les deux arguments d'un '%s'"; }

Chaine
LangueSyntaxeFR :: IdentOuInterrogeAttendu ()
	{ return "'?' ou IDENT attendu dans un programme Lista"; }
Chaine
LangueSyntaxeFR :: IdentAttenduCommeNomDeFonction ()
	{ return "IDENT attendu comme nom de fonction"; }
Chaine
LangueSyntaxeFR :: EgaleAttenduApresEnteteDeFonction ()
	{ return "'=' attendu apres une entete de fonction"; }
Chaine
LangueSyntaxeFR :: IdentAttenduCommeParametreDeFonction ()
	{ return "IDENT attendu comme parametre de fonction"; }
Chaine
LangueSyntaxeFR :: PointVirguleAttenduApresUneDefinitionDeFonction ()
	{ return "';' attendu apres une definition de fonction"; }
Chaine
LangueSyntaxeFR :: FormatPointVirguleAttenduApresUneDefinitionDeFonction ()
	{ return "';' attendu apres la definition de la fonction '%s'"; }

Chaine
LangueSyntaxeFR :: TraceDUneDefinitionDeFonction ()
	{ return "\n--> Definition de fonction\n"; }
Chaine
LangueSyntaxeFR :: FormatTraceDUneDefinitionDeFonction ()
	{ return "--> Definition de la fonction:\n\t'%s'"; }
Chaine
LangueSyntaxeFR :: FormatTraceDUneEvaluation ()
	{ return "\n--> Evaluation: expression -> %s"; }

Chaine
LangueSyntaxeFR :: ParentheseAttendueApresDesParametres ()
	{ return "')' attendue apres des parametres"; }
Chaine
LangueSyntaxeFR :: ArgumentsSuperflusPourUneNonFonction ()
	{ return "Liste d'arguments superflus utilises pour une non-fonction"; }
Chaine
LangueSyntaxeFR :: ListeDeParametresInconnus ()
	{ return "ListeDeParametresInconnus"; }
Chaine
LangueSyntaxeFR :: ApresUneListeDArgumentsSuperflus ()
	{ return "apres une liste d'arguments superflus"; }

Chaine
LangueSyntaxeFR :: PointVirguleAttenduApresUneEvaluation ()
	{ return "';' attendu apres une evaluation"; }
Chaine
LangueSyntaxeFR :: TraceDUneEvaluation ()
	{ return "\n--> Evaluation\n"; }
Chaine
LangueSyntaxeFR :: ParentheseAttendueApresExpressionParenthesee ()
	{ return "')' attendue apres une expression parenthesee"; }

Chaine
LangueSyntaxeFR :: VirguleAttendueDansUneIteration ()
	{ return "',' attendue dans une iteration"; }
Chaine
LangueSyntaxeFR :: ParentheseAttendueApresUneIteration ()
	{ return "')' attendue apres une iteration"; }

Chaine
LangueSyntaxeFR :: ParentheseInattendueDansAppelDeFonctionNonParametree ()
	{
	return
		"'(' inattendu dans "
		"un appel de fonction utilisateur non-parametree";
	}
Chaine
LangueSyntaxeFR :: FormatParentheseAttendueAvantUnAppelDeFonctionPredefinie ()
	{
	return
		"'(' attendu avant les arguments d'un appel a la fonction prefefinie '%s'";
	}
Chaine
LangueSyntaxeFR :: FormatArgumentsAttendusDansAppelDeFonction ()
	{
	return
		"'( arguments )' attendu dans "
		"un appel a la fonction utilisateur parametree '%s'";
	}

Chaine
LangueSyntaxeFR :: ParentheseAttendueApresUnAppelDeFonction ()
	{ return "')' attendue apres les arguments d'un appel de fonction"; }
Chaine
LangueSyntaxeFR :: FormatParentheseAttendueApresUnAppelDeFonction ()
	{ return "')' attendue apres les arguments d'un appel a la fonction '%s'"; }
Chaine
LangueSyntaxeFR :: FormatVirguleAttendueApresUnArgumentDAppel ()
	{ return "apres l'argument numero %d d'un appel a '%s'"; }
Chaine
LangueSyntaxeFR :: ParentheseAttendueApresUneSequence ()
	{ return "')' attendue apres une sequence"; }

Chaine
LangueSyntaxeFR :: SequenceDExpressionsAEvaluer ()
	{ return "sequence d'expressions a evaluer"; }


// -------------------------------------------------------------------------

Chaine
LangueSyntaxeFR :: CodeSyntaxiquementCorrect ()
	{ return "*** Code Lista syntaxiquement correct   ***"; }

Chaine
LangueSyntaxeFR :: CodeSyntaxiquementIncorrect ()
	{ return "### Code Lista syntaxiquement INCORRECT ###"; }


// -------------------------------------------------------------------------
//	LangueSyntaxeEN
// -------------------------------------------------------------------------

LangueSyntaxeEN :: LangueSyntaxeEN ()
	{}

LangueSyntaxeEN :: ~ LangueSyntaxeEN ()
	{}


// -------------------------------------------------------------------------

Chaine
LangueSyntaxeEN :: ErreurSyntaxique ()
	{ return "Syntactic ERROR"; }

Chaine
LangueSyntaxeEN :: FormatTerminalAttendu ()
	{ return "Token '%s' expected %s"; }

Chaine
LangueSyntaxeEN :: Expression ()
	{ return "expression"; }
Chaine
LangueSyntaxeEN :: Terme ()
	{ return "term"; }
Chaine
LangueSyntaxeEN :: Facteur ()
	{ return "factor"; }
Chaine
LangueSyntaxeEN :: FacteurMalForme ()
	{
	return
		"NUMBER, STRING, IDENT or parenthesized EXPRESSION "
		"expected as factor";
	}

Chaine
LangueSyntaxeEN :: VirguleAttendueApresConditionDUnSi ()
	{ return "',' expected after the condition of an 'If'"; }
Chaine
LangueSyntaxeEN :: VirguleAttendueApresPartieAlorsDUnSi ()
	{ return "','  expected after the 'then' part of an 'If'"; }
Chaine
LangueSyntaxeEN :: FormatVirguleAttendueDansUneSequence ()
	{ return "','  expected between the arguments of a '%s'"; }

Chaine
LangueSyntaxeEN :: IdentOuInterrogeAttendu ()
	{ return "'?' or IDENT expected in a Lista program"; }
Chaine
LangueSyntaxeEN :: IdentAttenduCommeNomDeFonction ()
	{ return "IDENT expected as function name"; }
Chaine
LangueSyntaxeEN :: EgaleAttenduApresEnteteDeFonction ()
	{ return "'=' expected after function header"; }
Chaine
LangueSyntaxeEN :: IdentAttenduCommeParametreDeFonction ()
	{ return "IDENT expected as a function parameter name"; }
Chaine
LangueSyntaxeEN :: PointVirguleAttenduApresUneDefinitionDeFonction ()
	{ return "';' expected after a function definition"; }
Chaine
LangueSyntaxeEN :: FormatPointVirguleAttenduApresUneDefinitionDeFonction ()
	{ return "';' expected after the definition of function '%s'"; }

Chaine
LangueSyntaxeEN :: TraceDUneDefinitionDeFonction ()
	{ return "\n--> Function definition\n"; }
Chaine
LangueSyntaxeEN :: FormatTraceDUneDefinitionDeFonction ()
	{ return "--> Definition of function:\n\t'%s'"; }
Chaine
LangueSyntaxeEN :: FormatTraceDUneEvaluation ()
	{ return "\n--> Evaluation: expression -> %s"; }

Chaine
LangueSyntaxeEN :: ParentheseAttendueApresDesParametres ()
	{ return "')' expected after parameters"; }
Chaine
LangueSyntaxeEN :: ArgumentsSuperflusPourUneNonFonction ()
	{ return "Liste d'arguments superflus utilises pour une non-fonction"; }
Chaine
LangueSyntaxeEN :: ListeDeParametresInconnus ()
	{ return "ListeDeParametresInconnus"; }
Chaine
LangueSyntaxeEN :: ApresUneListeDArgumentsSuperflus ()
	{ return "after une liste d'arguments superflus"; }

Chaine
LangueSyntaxeEN :: PointVirguleAttenduApresUneEvaluation ()
	{ return "';' expected after an evaluation"; }
Chaine
LangueSyntaxeEN :: TraceDUneEvaluation ()
	{ return "\n--> Evaluation\n"; }
Chaine
LangueSyntaxeEN :: ParentheseAttendueApresExpressionParenthesee ()
	{ return "')' expected after a parenthesized expression"; }

Chaine
LangueSyntaxeEN :: VirguleAttendueDansUneIteration ()
	{ return "',' expected in an iteration"; }
Chaine
LangueSyntaxeEN :: ParentheseAttendueApresUneIteration ()
	{ return "')' expected after an iteration"; }
Chaine
LangueSyntaxeEN :: ParentheseInattendueDansAppelDeFonctionNonParametree ()
	{
	return
		"'(' inattendu dans "
		"un appel de user function non-parametree";
	}
Chaine
LangueSyntaxeEN :: FormatParentheseAttendueAvantUnAppelDeFonctionPredefinie ()
	{
	return
		"'(' attendu avant les arguments d'un appel a la fonction prefefinie '%s'";
	}
Chaine
LangueSyntaxeEN :: FormatArgumentsAttendusDansAppelDeFonction ()
	{
	return
		"'( arguments )' expected dans "
		"un appel a la parametered user function '%s'";
	}

Chaine
LangueSyntaxeEN :: ParentheseAttendueApresUnAppelDeFonction ()
	{ return "')' expected after the arguments of a function call"; }
Chaine
LangueSyntaxeEN :: FormatParentheseAttendueApresUnAppelDeFonction ()
	{ return "')' expected after the arguments of a call to function '%s'"; }
Chaine
LangueSyntaxeEN :: FormatVirguleAttendueApresUnArgumentDAppel ()
	{ return "after l'argument numero %d d'un appel a '%s'"; }
Chaine
LangueSyntaxeEN :: ParentheseAttendueApresUneSequence ()
	{ return "')' expected after a sequence"; }

Chaine
LangueSyntaxeEN :: SequenceDExpressionsAEvaluer ()
	{ return "expression sequence to be evaluated"; }


// -------------------------------------------------------------------------

Chaine
LangueSyntaxeEN :: CodeSyntaxiquementCorrect ()
	{ return "*** Lista code syntactically correct   ***"; }

Chaine
LangueSyntaxeEN :: CodeSyntaxiquementIncorrect ()
	{ return "### Lista code syntactically INCORRECT ###"; }


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

LangueSyntaxePTR				gLANGUE_Syntaxe				= NULL;


// -------------------------------------------------------------------------
//	InitialiserLanguesSyntaxe
// -------------------------------------------------------------------------

void
InitialiserLanguesSyntaxe (Chaine leMnemonique)
	{
	if (gLANGUE_Syntaxe != NULL)
		delete gLANGUE_Syntaxe;

	if (leMnemonique == "fr")
		gLANGUE_Syntaxe = new LangueSyntaxeFR;
	if (leMnemonique == "en")
		gLANGUE_Syntaxe = new LangueSyntaxeEN;
	}
