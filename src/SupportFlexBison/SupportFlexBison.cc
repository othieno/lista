// =========================================================================
//	SupportFlexBison.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


// -------------------------------------------------------------------------
//	Librairie de support pour l'emploi combine de Flex et Bison
// -------------------------------------------------------------------------

#include "SupportFlexBison.h"

#include "SupportCPlusPlus.h"	//	pour le type bool

#include "Langues.h"

#include "LanguesLexique.h"
#include "LanguesSyntaxe.h"

#include <iostream>

#include <cstdlib>

#include <cstring>


// -------------------------------------------------------------------------
//	Externes synthetises par Flex
// -------------------------------------------------------------------------

extern int							yylex ();

extern int							yylineno;
extern int							yyleng;
extern char							* yytext;
extern FILE							* yyin;


// -------------------------------------------------------------------------
//	Fonctions et variables globales definies dans la grammaire *.Flex
// -------------------------------------------------------------------------

extern Chaine						DescriptionTerminalCourant ();

extern bool							gTraduire;


// -------------------------------------------------------------------------
//	Externes synthetises par Bison
// -------------------------------------------------------------------------

extern int							yyparse ();


// -------------------------------------------------------------------------
//	Variables privees
// -------------------------------------------------------------------------

static bool							pModeVerbeux;

static CharPTR						* pArguments;
static int							pArgumentsRestants;
static int							pArgumentCourant;


//	on gere les deux lignes precedant la ligne courante
//	la premiere acceptation d'une expression reguliere donne leur vraie
//	valeur initiale aux trois variables suivantes :
CharPTR								pDebutLigneCourante		= NULL;
CharPTR								pDebutLigneCourante_1	= NULL;
											// la precedente
CharPTR								pDebutLigneCourante_2	= NULL;
											// la precedente de la precedente

int									pTailleSourceCumule =
											1024;	// pourra croitre si necessaire
CharPTR								pSourceCumule =
											AllouerUnTampon (pTailleSourceCumule);
CharPTR								pLimiteFinDuSourceCumule =
											pSourceCumule + pTailleSourceCumule - 1;
CharPTR								pFinDuSourceCumule = pSourceCumule;

int									pTailleTamponAuxiliaire =
											1024;	// pourra croitre si necessaire
CharPTR								pTamponAuxiliaire =
											AllouerUnTampon (pTailleTamponAuxiliaire);


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

bool									gPremierTerminalDejaAccepte;

bool									gSortirALaPremiereErreurLexicale;
bool									gSortirALaPremiereErreurSyntaxique;

bool									gSourceCorrectLexicalement;
bool									gSourceCorrectSyntaxiquement;


// -------------------------------------------------------------------------
//	yywrap
// -------------------------------------------------------------------------

int
yywrap (void)
	{
	if ((pArgumentsRestants --) > 0)
		{
		CharPTR
					fichierATraiter = pArguments [pArgumentCourant ++];

		if (
			(yyin = fopen (fichierATraiter, "r"))
				==
			NULL
			)
			{
			perror (fichierATraiter);
			exit (-1);
			}
		else
			return 0;
		}
	else	//	on a epuise la liste de fichiers ˆ analyser
		return 1;
	}	//	yywrap


// -------------------------------------------------------------------------
//	Erreur
// -------------------------------------------------------------------------

static void
Erreur (Chaine genreDAnalyse, Chaine leMessage)
	{
	if (pModeVerbeux)
		std::cout <<
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatLocalisationErreur (),
				genreDAnalyse,
				leMessage,
				DescriptionTerminalCourant (),
				DescriptionPositionCourante () ) <<
			std::endl <<
			std::endl;
	else
		std::cout <<
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatLocalisationErreurAllege (),
				DescriptionPositionCourante (),
				genreDAnalyse,
				leMessage,
				DescriptionTerminalCourant () ) <<
			std::endl <<
			std::endl;
	}	//	Erreur


// -------------------------------------------------------------------------
//	ErreurLexicale
// -------------------------------------------------------------------------

void
ErreurLexicale (Chaine leMessage)
	{
	Erreur (
		gLANGUE_Lexique ->
			ErreurLexicale (),
		leMessage );

	gSourceCorrectLexicalement = false;

	if (gSortirALaPremiereErreurLexicale)
		SortieSurErreur (leMessage, 1);
	}


// -------------------------------------------------------------------------
//	ErreurSyntaxique
// -------------------------------------------------------------------------

void
ErreurSyntaxique (Chaine leMessage)
	{
	Erreur (
		gLANGUE_Syntaxe ->
			ErreurSyntaxique (),
		leMessage );

	gSourceCorrectSyntaxiquement = false;

	if (gSortirALaPremiereErreurLexicale)
		SortieSurErreur (leMessage, 1);
	}


// -------------------------------------------------------------------------
// AppondreAuSourceCumule
// -------------------------------------------------------------------------

void
AppondreAuSourceCumule ()
	// appond yytext ˆ pSourceCumule
	{
	if (pDebutLigneCourante_2 == NULL)
		pDebutLigneCourante_2 =
			pDebutLigneCourante_1 =
				pDebutLigneCourante =
					pSourceCumule;

	if (pFinDuSourceCumule + yyleng >= pLimiteFinDuSourceCumule)
		{
		//	 on etend pSourceCumule

		int		longueurUtilisee =
						pFinDuSourceCumule - pSourceCumule;
						
		int		nouvelleTailleSourceCumule = pTailleSourceCumule * 2;

		CharPTR	nouveauSourceCumule =
						AllouerUnTampon (nouvelleTailleSourceCumule);
		
		memcpy (nouveauSourceCumule, pSourceCumule, longueurUtilisee);
		
		delete [] pSourceCumule;

		pTailleSourceCumule = nouvelleTailleSourceCumule;
		pSourceCumule = nouveauSourceCumule;
		pLimiteFinDuSourceCumule =
			pSourceCumule + pTailleSourceCumule - 1;
		pFinDuSourceCumule =
			pSourceCumule + longueurUtilisee;
		}	// if
	
	memcpy (pFinDuSourceCumule, yytext, yyleng);
	pFinDuSourceCumule += yyleng;
	}	// AppondreAuSourceCumule


// -------------------------------------------------------------------------
// CompterFinDeLigne
// -------------------------------------------------------------------------

void 
CompterFinDeLigne ()
	{
	pDebutLigneCourante_2 = pDebutLigneCourante_1;
	pDebutLigneCourante_1 = pDebutLigneCourante;
	pDebutLigneCourante   = pFinDuSourceCumule;
	}


// -------------------------------------------------------------------------
// DescriptionPositionCourante
// -------------------------------------------------------------------------

Chaine 
DescriptionPositionCourante ()
	{
	CharPTR	positionCourante = pFinDuSourceCumule;

	int		nombreDeCaracteresAAfficher =
					positionCourante - pDebutLigneCourante_2 + 1;

	if (nombreDeCaracteresAAfficher > pTailleTamponAuxiliaire)
		{
		delete [] pTamponAuxiliaire;

		pTailleTamponAuxiliaire = nombreDeCaracteresAAfficher;
		pTamponAuxiliaire =
			AllouerUnTampon (pTailleTamponAuxiliaire);
		}	// if		

	memcpy (
		pTamponAuxiliaire,
		pDebutLigneCourante_2,
		nombreDeCaracteresAAfficher );
	pTamponAuxiliaire [nombreDeCaracteresAAfficher] = L'\0';
	
	Chaine	separateur =
					"-----------------------------------------------------";

	if (pModeVerbeux)
		return
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatPositionLexicaleCourante (),
				yylineno,
				positionCourante - pDebutLigneCourante + 1,
				pFinDuSourceCumule [-1],
				pFinDuSourceCumule [-1],
				separateur.c_str (),
				pTamponAuxiliaire,
				separateur.c_str () );
	else
		return
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatPositionLexicaleCouranteAllege (),
				yylineno,
				positionCourante - pDebutLigneCourante + 1 );
	}	//	DescriptionPositionCourante


// -------------------------------------------------------------------------
//	yyerror
// -------------------------------------------------------------------------

int
yyerror (CharPTR leMessage)
	{
	ErreurSyntaxique (
		leMessage );

	gSourceCorrectSyntaxiquement = false;

	if (gSortirALaPremiereErreurLexicale)
		SortieSurErreur (leMessage, 1);

	return 0;
	}


// -------------------------------------------------------------------------
//	AnalyserFlexBison
// -------------------------------------------------------------------------

bool
AnalyserFlexBison (
	int		argc,
	CharPTR	* argv,
	bool		leModeVerbeux,
	bool		leTraduire )
	{
	pArguments = argv;
	pArgumentsRestants = argc;
	pArgumentCourant = 0;

	gSourceCorrectLexicalement = true;
	gSourceCorrectSyntaxiquement = true;
	
	pDebutLigneCourante   = NULL;
	pDebutLigneCourante_1 = NULL;
	pDebutLigneCourante_2 = NULL;

	gPremierTerminalDejaAccepte = false;
	
	pModeVerbeux = leModeVerbeux;
	
	gTraduire = leTraduire;

	yywrap ();	//	ouverture d'un premier fichier

	bool	res = ! yyparse ();
	
	return res;
	}	//	AnalyserFlexBison
