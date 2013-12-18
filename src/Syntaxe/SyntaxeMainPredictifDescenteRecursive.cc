// =========================================================================
//	SyntaxeMainPredictifDescenteRecursive.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "SupportCPlusPlus.h"

#include "Langues.h"

#include "LanguesSyntaxe.h"
#include "DecodageDOptionsSyntaxe.h"

#include "ProducteurDeCaracteres.h"
#include "AnalyseurLexicalLista.h"

#include "AnalyseurDescendantLista.h"

#include <iostream>

#include <cstdlib>


// -------------------------------------------------------------------------
//	main
// -------------------------------------------------------------------------

int
main (int nbDArguments, CharPTR lesArguments [])
	{

	//
	//	Initialisation
	//	--------------
	//
	
	InitialiserLanguesSupportCPlusPlus ();

	InitialiserLanguesLexique ();
	InitialiserLanguesSyntaxe ();


	//
	//	Decodage des options et arguments
	//	---------------------------------
	//
	
	DecodageDOptionsSyntaxe
				leDecodageDOptionsSyntaxe (
					nbDArguments,
					lesArguments,
					& Options :: VersionSyntaxePredictifDescenteRecursive,
					true );
	
	leDecodageDOptionsSyntaxe.Initialiser ();

	leDecodageDOptionsSyntaxe.EnregistrerLAssociation (
		new AssocDecodageDOptionsSyntaxe (
			& Options :: ArgumentsCompilateurs,
			& leDecodageDOptionsSyntaxe,
			& DecodageDOptionsSyntaxe :: ArgumentsNonOptions ));

	int		indicePremierArgumentNonOption =
					leDecodageDOptionsSyntaxe.DecortiquerLesOptions ();

	bool		modeVerbeux =
					leDecodageDOptionsSyntaxe.ModeVerbeux ();

	bool		montrerLeCodeSource =
					leDecodageDOptionsSyntaxe.MontrerLeCodeSource ();
	bool		montrerLesTerminaux =
					leDecodageDOptionsSyntaxe.MontrerLesTerminaux ();

	bool		sortirALaPremiereErreurLexicale =
					leDecodageDOptionsSyntaxe.SortirALaPremiereErreurLexicale ();
	bool		sortirALaPremiereErreurSyntaxique =
					leDecodageDOptionsSyntaxe.SortirALaPremiereErreurSyntaxique ();


	//
	//	Analyse du nombre d'arguments
	//	-----------------------------
	//
	
	int		nbDArgumentsNonOptions =
					nbDArguments - indicePremierArgumentNonOption;
	
	ProducteurDeCaracteres	* leProducteurDeCaracteres;

	switch (nbDArgumentsNonOptions)
		{
		case 0 :
			leProducteurDeCaracteres = LireLeFlot (& std::cin, '\0');
			break;

		case 1 :
			{
			Chaine	nomDuFichierSource =
							lesArguments [indicePremierArgumentNonOption];

			leProducteurDeCaracteres =
				LireLeFichier (nomDuFichierSource, SENTINELLE);
			
			if (montrerLeCodeSource)
				MontrerLeContenuDuFichier (nomDuFichierSource);
			}
			break;

		default :
			std::cerr << leDecodageDOptionsSyntaxe.Usage ();
			exit (1);
		}	//	switch


	//
	//	Analyse lexico-syntaxique
	//	-------------------------
	//
	
	OptionsLexique
				lesOptionsLexique (
					sortirALaPremiereErreurLexicale,
					modeVerbeux,
					montrerLesTerminaux,
					false );	// pas de traduction

	AnalyseurLexicalLista
				lAnalyseurLexical (
					leProducteurDeCaracteres,
					& lesOptionsLexique );

	OptionsSyntaxe
				lesOptionsSyntaxe (
					sortirALaPremiereErreurSyntaxique,
					modeVerbeux,
					montrerLesTerminaux );

	AnalyseurDescendantLista
				lAnalyseurSyntaxique (
					& lAnalyseurLexical,
					& lesOptionsSyntaxe );

	lAnalyseurSyntaxique.Analyser ();

	}	//	main
