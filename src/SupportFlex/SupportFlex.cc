// =========================================================================
//	SupportFlex.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


// -------------------------------------------------------------------------
//	Librairie de support pour l'emploi de Flex
// -------------------------------------------------------------------------

#include "SupportFlex.h"

#include "Langues.h"

#include "SupportCPlusPlus.h"

#include "LanguesLexique.h"

#include <iostream>

#include <cstdlib>

#include <cstring>


// -------------------------------------------------------------------------
//	Externes synthetises par Flex
// -------------------------------------------------------------------------

extern int							yylex ();

extern int 							yylineno;
extern int							yyleng;
extern char							* yytext;
extern FILE							* yyin;


// -------------------------------------------------------------------------
//	Fonctions et variables globales definies dans la grammaire *.Flex
// -------------------------------------------------------------------------

extern Chaine						DescriptionTerminalCourant ();


// -------------------------------------------------------------------------
//	Variables privees
// -------------------------------------------------------------------------

static CharPTR						* pArguments;
static int							pArgumentsRestants;
static int							pArgumentCourant;

static bool							pModeVerbeux;

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

bool									gSourceCorrectLexicalement;


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
//	ErreurLexicale
// -------------------------------------------------------------------------

void
ErreurLexicale (Chaine leFormat)
	{
	Chaine	leMessage =
					MiseEnForme (leFormat, yytext [0]);
	
	if (pModeVerbeux)
		std::cout <<
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatErreurLexicale (),
				leMessage,
				DescriptionTerminalCourant (),
				DescriptionPositionCourante () ) <<
			std::endl;
	else
		std::cout <<
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatErreurLexicaleAllege (),
				DescriptionPositionCourante (),
				leMessage,
				DescriptionTerminalCourant () ) <<
			std::endl;
	
	gSourceCorrectLexicalement = false;

	if (gSortirALaPremiereErreurLexicale)
		SortieSurErreur (leMessage, 1);
	}	//	ErreurLexicale


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
				"[L%3d:C%3d]",
				yylineno,
				positionCourante - pDebutLigneCourante + 1 );
	}	//	DescriptionPositionCourante


// -------------------------------------------------------------------------
//	AnalyserF
// -------------------------------------------------------------------------

void
AnalyserF (
	int		argc,
	CharPTR	* argv,
	bool		leModeVerbeux )
	{
	pArguments = argv;
	pArgumentsRestants = argc;
	pArgumentCourant = 0;

	pModeVerbeux = leModeVerbeux;
	
	gSourceCorrectLexicalement = true;
	
	pDebutLigneCourante   = NULL;
	pDebutLigneCourante_1 = NULL;
	pDebutLigneCourante_2 = NULL;

	gPremierTerminalDejaAccepte = false;

	yywrap ();	//	ouverture d'un premier fichier

	while (yylex () != 0)	//	jusqu'a la fin du fichier
		;	//	rien
	
	}	//	AnalyserF
