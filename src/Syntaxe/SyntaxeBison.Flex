%{

/* déclarations globales */

// =========================================================================
//	SyntaxeBison.Flex
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


/* ---------------------------------------------------------------------- */
/* Inclusions */
/* ---------------------------------------------------------------------- */


//	On doit fournir 'yywrap ()' et 'ErreurLexicale ()'

#include "SupportCPlusPlus.h"

#include "Langues.h"

#include "SupportFlexBison.h"			//	Fournit 'yywrap ()' et 'ErreurLexicale ()'

#include <iostream>

#include <cstdlib>
#include <cstdio>


/* ---------------------------------------------------------------------- */
/* Types */
/* ---------------------------------------------------------------------- */

typedef int							TerminalF;


/* ---------------------------------------------------------------------- */
/* Variables globales */
/* ---------------------------------------------------------------------- */

TerminalF							gTerminalFCourant;

//bool									gModeVerbeux = false;

bool									gTraduire = false;		// pas de traduction


/* ---------------------------------------------------------------------- */
/* Fonctions */
/* ---------------------------------------------------------------------- */

void									AppondreLeFragmentALaChaine (
											CharPTR leFragment );

TerminalF							EnregistrerTerminal (
											TerminalF leTerminalF );

%}


/* ---------------------------------------------------------------------- */
/* Options */
/* ---------------------------------------------------------------------- */

%option	yylineno


/* ---------------------------------------------------------------------- */
/* Expressions régulières */
/* ---------------------------------------------------------------------- */

blancs								[ \t]+
finDeLigne							[\n]

lettre								[A-Za-zéèêàâòôùûî]
chiffre10							[0-9]

ident									{lettre}(_|{lettre}|{chiffre10})*
entier10								{chiffre10}+
exposant								[eE][+-]?{entier10}

guillemet							[\"]
tabulateur							[\t]
backSlash							[\\]


/* modes exclusif, pour que les autres productions ne s'appliquent pas */
%x										ACCEPTATION_D_UNE_CHAINE
%x										COMMENTAIRE_PARENTHESE
%x										COMMENTAIRE_SUR_UNE_LIGNE


%%	/* Les terminaux du langage et les actions correspondantes */


%{
/* Variables locales à "yylex" */
%}


"/*"									{
										AppondreAuSourceCumule ();

										/*
										std::cout <<
											"==> on passe en mode COMMENTAIRE_PARENTHESE" <<
											std::endl;
										*/
										BEGIN COMMENTAIRE_PARENTHESE;
										}

<COMMENTAIRE_PARENTHESE>[^*{finDeLigne}]*	{
										AppondreAuSourceCumule ();

										/* on accepte tout caractere autre que '*' */
										}
<COMMENTAIRE_PARENTHESE>"*"+[^*/{finDeLigne}]*	{
										AppondreAuSourceCumule ();

										/* on accepte toues les '*' non suivies d'un '/' */
										}
<COMMENTAIRE_PARENTHESE>{finDeLigne}	{
										AppondreAuSourceCumule ();

										CompterFinDeLigne ();
										}
<COMMENTAIRE_PARENTHESE>"*"+"/"	{
										AppondreAuSourceCumule ();

										/*
										std::cout <<
											"==> on passe en mode INITIAL" <<
											std::endl;
										*/
										BEGIN INITIAL;
										}
<COMMENTAIRE_PARENTHESE>.		{
										AppondreAuSourceCumule ();
										}


"//"									{
										AppondreAuSourceCumule ();

										/*
										std::cout <<
											"==> on passe en mode COMMENTAIRE_SUR_UNE_LIGNE" <<
											std::endl;
										*/
										BEGIN COMMENTAIRE_SUR_UNE_LIGNE;
										}

<COMMENTAIRE_SUR_UNE_LIGNE>{finDeLigne}	{
										AppondreAuSourceCumule ();

										CompterFinDeLigne ();

										/*
										std::cout <<
											"==> on passe en mode INITIAL" <<
											std::endl;
										*/
										BEGIN INITIAL;
										}
<COMMENTAIRE_SUR_UNE_LIGNE>.	{
										AppondreAuSourceCumule ();

										/*
										on accepte tout caractere qui n'est pas
										une {finDeLigne}
										*/
										}


{guillemet}							{
										AppondreAuSourceCumule ();

										yylval.fChaine = CharPTR ("");
										/*
										std::cout <<
											"==> on passe en mode ACCEPTATION_D_UNE_CHAINE" <<
											std::endl;
										*/
										BEGIN ACCEPTATION_D_UNE_CHAINE;
										}

<ACCEPTATION_D_UNE_CHAINE>{guillemet}	{
										AppondreAuSourceCumule ();

										/*
										std::cout <<
											"==> on passe en mode INITIAL" <<
											std::endl;
										*/
										BEGIN INITIAL;
										/* yylval.fChaine est deja garni */
										return EnregistrerTerminal (t_CHAINE);
										}

<ACCEPTATION_D_UNE_CHAINE>{backSlash}{guillemet}	{
										AppondreAuSourceCumule ();

										AppondreLeFragmentALaChaine (CharPTR ("\""));
										}
<ACCEPTATION_D_UNE_CHAINE>{backSlash}n	{
										AppondreAuSourceCumule ();

										AppondreLeFragmentALaChaine (CharPTR ("\n"));
										}
<ACCEPTATION_D_UNE_CHAINE>{backSlash}t	{
										AppondreAuSourceCumule ();

										AppondreLeFragmentALaChaine (CharPTR ("\t"));
										}
<ACCEPTATION_D_UNE_CHAINE>{backSlash}{backSlash}	{
										AppondreAuSourceCumule ();

										AppondreLeFragmentALaChaine (CharPTR ("\\"));
										}
<ACCEPTATION_D_UNE_CHAINE>{finDeLigne}	{
										AppondreAuSourceCumule ();

										CompterFinDeLigne ();

										AppondreLeFragmentALaChaine (yytext);
										}

<ACCEPTATION_D_UNE_CHAINE>.	{
										AppondreAuSourceCumule ();

										AppondreLeFragmentALaChaine (yytext);
										}


{blancs}								{
										AppondreAuSourceCumule ();

										/* on ignore ces separateurs */
										}

{finDeLigne}						{
										AppondreAuSourceCumule ();

										CompterFinDeLigne ();
										/* on ignore ce separateur */
										}


{entier10}"."{entier10}({exposant})?	|
{entier10}({exposant})?			{
										AppondreAuSourceCumule ();

										yylval.fNombre = atof (yytext);
										return EnregistrerTerminal (t_NOMBRE);
										}

{ident}								{
										AppondreAuSourceCumule ();

										yylval.fIdent = SauvegarderChaine (yytext);
										return EnregistrerTerminal (t_IDENT);
										}


"("									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_PAR_GAUCHE);
										}
")"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_PAR_DROITE);
										}

"="									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_EGALE);
										}
","									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_VIRGULE);
										}

"+"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_PLUS);
										}
"-"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_MOINS);
										}
"*"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_FOIS);
										}
"/"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_DIVISE);
										}
"!!"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_CONCAT);
										}

";"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_POINT_VIRGULE);
										}
"?"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_INTERROGE);
										}
"["									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_CROCHET_GAUCHE);
										}
"]"									{
										AppondreAuSourceCumule ();

										return EnregistrerTerminal (t_CROCHET_DROIT);
										}

.										{
										AppondreAuSourceCumule ();

										ErreurLexicale (
											MiseEnForme (
												gLANGUE_Lexique ->
													FormatCaractereIllegal(),
												yytext [0]) );
										}


%%

/* ---------------------------------------------------------------------- */
/* Le code de service */
/* ---------------------------------------------------------------------- */


/* ---------------------------------------------------------------------- */
/*	TerminalSousFormeTextuelle */
/* ---------------------------------------------------------------------- */

Chaine
TerminalSousFormeTextuelle (TerminalF leTerminalF)
	{
	switch (leTerminalF)
		{
		case t_NOMBRE:
			return MiseEnForme (
				"%-10s %*.*f",
				gLANGUE_Lexique ->
					TerminalFlottant ().c_str (),
				TailleChampEcritureNombres (),
				NombreDecimalesEcritureNombres (),
				yylval.fNombre );

		case t_CHAINE:
			return MiseEnForme (
				"%-10s %s",
				gLANGUE_Lexique ->
					TerminalChaine ().c_str (),
				yylval.fChaine );

		case t_IDENT:
			return MiseEnForme (
				"%-10s %s",
				gLANGUE_Lexique ->
					TerminalIdent ().c_str (),
				yylval.fIdent );

		case t_PAR_GAUCHE:
			return "           (";
		case t_PAR_DROITE:
			return "           )";

		case t_EGALE:
			return "           =";
		case t_VIRGULE:
			return "           ,";

		case t_PLUS:
			return "           +";
		case t_MOINS:
			return "           -";
		case t_FOIS:
			return "           *";
		case t_DIVISE:
			return "           /";
		case t_CONCAT:
			return "           !!";

		case t_POINT_VIRGULE:
			return "           ;";
		case t_INTERROGE:
			return "           ?";

		case t_CROCHET_GAUCHE:
			return "           [";
		case t_CROCHET_DROIT:
			return "           ]";

		default:
			return
				MiseEnForme (
					gLANGUE_Lexique ->
						FormatTerminalInconnu (),
					yytext );

		}	//	switch
	}	//	TerminalSousFormeTextuelle


/* ---------------------------------------------------------------------- */
/*	DescriptionTerminalCourant */
/* ---------------------------------------------------------------------- */

Chaine
DescriptionTerminalCourant ()
	{
	return
		gPremierTerminalDejaAccepte
			?	TerminalSousFormeTextuelle (gTerminalFCourant)
			:	(Chaine) "-- Aucun terminal accepte encore --";
	}


/* ---------------------------------------------------------------------- */
/*	AppondreLeFragmentALaChaine */
/* ---------------------------------------------------------------------- */

void
AppondreLeFragmentALaChaine (CharPTR leFragment)
	{
	yylval.fChaine =
		(CharPTR) FConcatChaines (yylval.fChaine, leFragment);
	}


/* ---------------------------------------------------------------------- */
/*	EnregistrerTerminal */
/* ---------------------------------------------------------------------- */

TerminalF
EnregistrerTerminal (TerminalF leTerminalF)
	{
	if (gMontrerLesTerminaux)
		std::cout << "\t" << TerminalSousFormeTextuelle (leTerminalF) << std::endl;

	gTerminalFCourant = leTerminalF;
	gPremierTerminalDejaAccepte = true;

	return leTerminalF;
	}
