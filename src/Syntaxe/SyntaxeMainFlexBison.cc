// =========================================================================
//	SyntaxeMainFlexBison.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Langues.h"

#include "SupportCPlusPlus.h"

#include "SupportFlexBison.h"

#include "LanguesSyntaxe.h"

#include "DecodageDOptionsSyntaxe.h"

#include <iostream>

#include <cstdlib>


// -------------------------------------------------------------------------
//	main
// -------------------------------------------------------------------------

int main (int nbDArguments, CharPTR lesArguments [])
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
					& Options :: VersionSyntaxeFlexBison,
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
		
	CharPTR
				* lesArgumentsAUtiliser;

	switch (nbDArgumentsNonOptions)
		{
		case 0 :
			lesArgumentsAUtiliser = lesArguments;
			break;

		case 1 :
			{
			Chaine	nomDuFichierSource =
							lesArguments [indicePremierArgumentNonOption];

			if (montrerLeCodeSource)
				MontrerLeContenuDuFichier (nomDuFichierSource);

			lesArgumentsAUtiliser =
				& lesArguments [indicePremierArgumentNonOption];
			}
			break;

		default:
			std::cerr << leDecodageDOptionsSyntaxe.Usage ();
			exit (1);
		}	//	switch
		
	int		lesArgumentsRestants = nbDArgumentsNonOptions;


	//
	//	Analyse lexico-syntaxique
	//	-------------------------
	//
	
	extern bool
				gSortirALaPremiereErreurLexicale;
	extern bool
				gSortirALaPremiereErreurSyntaxique;
	
	extern bool
				gModeVerbeux;
	extern bool
				gMontrerLesTerminaux;

	extern bool
				gSourceCorrectLexicalement;
	extern bool
				gSourceCorrectSyntaxiquement;
	
	gSortirALaPremiereErreurLexicale =
		sortirALaPremiereErreurLexicale;

	gSortirALaPremiereErreurSyntaxique =
		sortirALaPremiereErreurSyntaxique;
	
	gModeVerbeux = modeVerbeux;
	gMontrerLesTerminaux = montrerLesTerminaux;

	if (
		! AnalyserFlexBison (
			lesArgumentsRestants,
			lesArgumentsAUtiliser,
			gModeVerbeux,
			false	// pas de traduction
			)
		)
		;	//	RIEN

	if (gSourceCorrectLexicalement)
		std::cout <<
			gLANGUE_Lexique ->
				CodeLexicalementCorrect () <<
			std::endl;
	else
		std::cout <<
			gLANGUE_Lexique ->
				CodeLexicalementIncorrect () <<
			std::endl;

	if (gSourceCorrectSyntaxiquement)
		std::cout <<
			gLANGUE_Syntaxe ->
				CodeSyntaxiquementCorrect () <<
			std::endl;
	else
		std::cout <<
			gLANGUE_Syntaxe ->
				CodeSyntaxiquementIncorrect () <<
			std::endl;
	}	//	main
