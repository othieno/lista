// =========================================================================
//	LexiqueMainP.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "SupportCPlusPlus.h"

#include "LanguesLexique.h"

#include "AnalyseurLexicalLista.h"

#include "DecodageDOptionsLexique.h"

#include "Langues.h"

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


	//
	//	Decodage des options et arguments
	//	---------------------------------
	//

	DecodageDOptionsLexique
				leDecodageDOptionsLexique (
					nbDArguments,
					lesArguments,
					& Options :: VersionLexiqueP,
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

	ProducteurDeCaracteres
				* leProducteurDeCaracteres;

	switch (nbDArgumentsNonOptions)
		{
		case 0 :
			leProducteurDeCaracteres =
				LireLeFlot (& std::cin, '\0' );
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
			std::cerr << leDecodageDOptionsLexique.Usage ();
			exit (1);
		}	//	switch


	//
	//	Analyse lexicale
	//	----------------
	//
	
	OptionsLexique
				lesOptionsLexique (
					sortirALaPremiereErreurLexicale,
					true,		// mode verbeux par defaut
					montrerLesTerminaux,
					false );	// pas de traduction

	AnalyseurLexicalLista
				lAnalyseurLexical (
					leProducteurDeCaracteres,
					& lesOptionsLexique );

	lAnalyseurLexical.Analyser ();
	
	}	//	main
