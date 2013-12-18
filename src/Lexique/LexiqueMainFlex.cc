// =========================================================================
//	SyntaxeMainFlex.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Langues.h"

#include "SupportCPlusPlus.h"

#include "SupportFlex.h"

#include "LanguesLexique.h"

#include "DecodageDOptionsLexique.h"

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


	//
	//	Decodage des options et arguments
	//	---------------------------------
	//
	
	DecodageDOptionsLexique
				leDecodageDOptionsLexique (
					nbDArguments,
					lesArguments,
					& Options :: VersionLexiqueF,
					true );
	
	leDecodageDOptionsLexique.Initialiser ();

	leDecodageDOptionsLexique.EnregistrerLAssociation (
		new AssocDecodageDOptionsLexique (
			& Options :: ArgumentsCompilateurs,
			& leDecodageDOptionsLexique,
			& DecodageDOptionsLexique :: ArgumentsNonOptions ));

	int		indicePremierArgumentNonOption =
					leDecodageDOptionsLexique.DecortiquerLesOptions ();

	bool		montrerLeCodeSource =
					leDecodageDOptionsLexique.MontrerLeCodeSource ();
	bool		montrerLesTerminaux =
					leDecodageDOptionsLexique.MontrerLesTerminaux ();

	bool		sortirALaPremiereErreurLexicale =
					leDecodageDOptionsLexique.SortirALaPremiereErreurLexicale ();

	
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

		default :
			std::cerr << leDecodageDOptionsLexique.Usage ();
			exit (1);
		}	//	switch

	int		lesArgumentsRestants = nbDArgumentsNonOptions;


	//
	//	Analyse lexicale
	//	----------------
	//
	
	extern bool
				gMontrerLesTerminaux;

	extern bool
				gSortirALaPremiereErreurLexicale;

	extern bool
				gSourceCorrectLexicalement;

	gSortirALaPremiereErreurLexicale =
		sortirALaPremiereErreurLexicale;
	
	gSourceCorrectLexicalement = true;
	gMontrerLesTerminaux = montrerLesTerminaux;

	AnalyserF (
		lesArgumentsRestants,
		lesArgumentsAUtiliser,
		true );	// verbeux par defaut
 
	if (montrerLesTerminaux)
		std::cout <<
			gLANGUE_Lexique ->
				PseudoTerminalFin () <<
			std::endl;
	
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

	}	//	main
