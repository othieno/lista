// =========================================================================
//	PutzerVersionDeTravailMain.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "SupportF.h"

#include <iostream>


// -------------------------------------------------------------------------
//	Externes synthetises par Flex
// -------------------------------------------------------------------------

extern int							yylex ();

extern int 							yylineno;
extern int							yyleng;
extern char							yytext [];	//	et non pas 'extern char * yytext;' !!!
extern FILE							* yyin;


// -------------------------------------------------------------------------
//	Variables privees
// -------------------------------------------------------------------------

static char *						* pArguments;
static int							pArgumentsRestants;
static int							pArgumentCourant;


// -------------------------------------------------------------------------
//	yywrap
// -------------------------------------------------------------------------

int
yywrap (void)
	{
	if ((pArgumentsRestants --) > 0)
		{
		char *
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
//	main
// -------------------------------------------------------------------------

int
main (int nbDArguments, char * lesArguments [])
	{
	//
	//	Analyse du nombre d'arguments
	//	-----------------------------
	//
	
	char *	* lesArgumentsAUtiliser;
	int		lesArgumentsRestants;

	switch (nbDArguments)
		{
		case 1 :
			lesArgumentsAUtiliser = lesArguments;
			lesArgumentsRestants = 0;
			break;

		case 2 :
			{
			lesArgumentsAUtiliser = & lesArguments [1];
			lesArgumentsRestants = 1;
			}
			break;

		default :
			std::cerr <<
				lesArguments [0] << " prend 0 ou 1 argument" << std::endl;
			exit (1);
		}	//	switch



	//
	//	Analyse lexicale
	//	----------------
	//

	pArguments = lesArgumentsAUtiliser;
	pArgumentsRestants = lesArgumentsRestants;
	pArgumentCourant = 0;

	yywrap ();	//	ouverture d'un premier fichier

	while (yylex () != 0)	//	jusqu'a la fin du fichier
		;	//	rien
 
	}	//	main
