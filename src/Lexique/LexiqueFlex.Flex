%{

/* déclarations globales */

// =========================================================================
//	LexiqueF.Flex
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


/* ---------------------------------------------------------------------- */
/* Inclusions */
/* ---------------------------------------------------------------------- */


#include "SupportCPlusPlus.h"

#include "Langues.h"

#include "TerminauxFlexLista.h"		//	Fournit la description des terminaux

#include "SupportFlex.h"				//	Fournit 'yywrap ()' et 'ErreurLexicale ()'

#include "LanguesLexique.h"

#include <iostream>

#include <cstdlib>
#include <cstdio>


/* ---------------------------------------------------------------------- */
/* Variables globales */
/* ---------------------------------------------------------------------- */

bool									gMontrerLesTerminaux;

TerminalFlexLista					gTerminalFlexListaCourant;


/* ---------------------------------------------------------------------- */
/* Fonctions */
/* ---------------------------------------------------------------------- */

void									AppondreLeFragmentALaChaine (
											CharPTR leFragment );

TerminalFlexLista					EnregistrerTerminal (
											TerminalFlexLista leTerminalFlexLista );

%}


/* ---------------------------------------------------------------------- */
/* Options */
/* ---------------------------------------------------------------------- */

%option	yylineno


/* ---------------------------------------------------------------------- */
/* Expressions régulières */
/* ---------------------------------------------------------------------- */

caractere							.

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
											"==> mode COMMENTAIRE_PARENTHESE" <<
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

										/* on accepte toutes les '*' non suivies d'un '/' */
										}
<COMMENTAIRE_PARENTHESE>{finDeLigne}	{
										AppondreAuSourceCumule ();

										CompterFinDeLigne ();
										}
<COMMENTAIRE_PARENTHESE>"*"+"/"	{
										AppondreAuSourceCumule ();

										/*
										std::cout <<
											"==> mode INITIAL" <<
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
											"==> mode COMMENTAIRE_SUR_UNE_LIGNE" <<
											std::endl;
										*/
										BEGIN COMMENTAIRE_SUR_UNE_LIGNE;
										}

<COMMENTAIRE_SUR_UNE_LIGNE>{finDeLigne}	{
										AppondreAuSourceCumule ();

										CompterFinDeLigne ();

										/*
										std::cout << "==> mode INITIAL" << std::endl;
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
											"==> mode ACCEPTATION_D_UNE_CHAINE" <<
											std::endl;
										*/
										BEGIN ACCEPTATION_D_UNE_CHAINE;
										}

<ACCEPTATION_D_UNE_CHAINE>{guillemet}	{
										AppondreAuSourceCumule ();

										/*
										std::cout <<
											"==> mode INITIAL" <<
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
{entier10}{exposant}?			{
										AppondreAuSourceCumule ();

										yylval.fNombre = atof (yytext);
										return EnregistrerTerminal (t_NOMBRE);
										}

{ident}								{
										AppondreAuSourceCumule ();

										yylval.fIdent =
											SauvegarderChaine (yytext);
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


%%	/* Le code de service */
	/* ------------------ */


/* ---------------------------------------------------------------------- */
/* TerminalSousFormeTextuelle */
/* ---------------------------------------------------------------------- */

Chaine
TerminalSousFormeTextuelle (TerminalFlexLista leTerminalFlexLista)
	{
	switch (leTerminalFlexLista)
		{
		case t_NOMBRE:
			return
				MiseEnForme (
					"%-10s %*.*f",
					gLANGUE_Lexique ->
						TerminalFlottant ().c_str (),
					TailleChampEcritureNombres (),
					NombreDecimalesEcritureNombres (),
					yylval.fNombre );
		case t_CHAINE:
			return
				MiseEnForme (
					"%-10s %s",
					gLANGUE_Lexique ->
						TerminalChaine ().c_str (),
					yylval.fChaine );

		case t_IDENT:
			return
				MiseEnForme (
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
					leTerminalFlexLista );

		}	//	switch
	}	//	TerminalSousFormeTextuelle


/* ---------------------------------------------------------------------- */
/* DescriptionTerminalCourant */
/* ---------------------------------------------------------------------- */

Chaine
DescriptionTerminalCourant ()
	{
	return
		gPremierTerminalDejaAccepte
			?	TerminalSousFormeTextuelle (gTerminalFlexListaCourant)
			:	gLANGUE_Lexique ->
					AucunTerminalAccepteEncore ();
	}


/* ---------------------------------------------------------------------- */
/* AppondreLeFragmentALaChaine */
/* ---------------------------------------------------------------------- */

void
AppondreLeFragmentALaChaine (CharPTR leFragment)
	{
	yylval.fChaine =
		(CharPTR) FConcatChaines (yylval.fChaine, leFragment);

//	std::cout << "yylval.fChaine = " << yylval.fChaine << std::endl << std::endl;
	}


/* ---------------------------------------------------------------------- */
/* EnregistrerTerminal */
/* ---------------------------------------------------------------------- */

TerminalFlexLista
EnregistrerTerminal (TerminalFlexLista leTerminalFlexLista)
	{
	if (gMontrerLesTerminaux)
		std::cout <<
			"\t" <<
			TerminalSousFormeTextuelle (leTerminalFlexLista) <<
			std::endl;

	gTerminalFlexListaCourant = leTerminalFlexLista;
	gPremierTerminalDejaAccepte = true;

	return leTerminalFlexLista;
	}
