// =========================================================================
//	PilumMain.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Pilum.h"

#include "Langues.h"

#include "LanguesPredefinis.h"

#include "LanguesPilum.h"

#include "DecodageDOptionsPilum.h"

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
	
	InitialiserLanguesPredefinis ();
	
	InitialiserLanguesSupportCPlusPlus ();

	InitialiserLanguesPilum ();


	//
	//	Decodage des options et arguments
	//	---------------------------------
	//

	DecodageDOptionsPilum
				leDecodageDOptionsPilum (
					nbDArguments,
					lesArguments,
					& Options :: VersionPilum );
	
	leDecodageDOptionsPilum.Initialiser ();

	int		indicePremierArgumentNonOption =
					leDecodageDOptionsPilum.DecortiquerLesOptions ();

	bool		modeVerbeux =
					leDecodageDOptionsPilum.ModeVerbeux ();

	bool		montrerLeCodeParPilum =
					leDecodageDOptionsPilum.MontrerLeCodeParPilum ();
	bool		montrerLAideInteractiveInitialement =
					leDecodageDOptionsPilum.MontrerLAideInteractiveInitialement ();

	long		tailleDeLaPile =
					leDecodageDOptionsPilum.TailleDeLaPile ();

	GenreDExecution
				leGenreDExecution =
					leDecodageDOptionsPilum.LeGenreDExecution ();


	//
	//	Analyse du nombre d'arguments
	//	-----------------------------
	//
	
	int		nbDArgumentsNonOptions =
					nbDArguments - indicePremierArgumentNonOption;

	Chaine	nomDuFichierBinaire = "Lista.pilum";

	switch (nbDArgumentsNonOptions)
		{
		case 1 :
			nomDuFichierBinaire =
				lesArguments [indicePremierArgumentNonOption];
			break;
		default:
			std::cerr <<
				gLANGUE_Pilum ->
					FichierBinairePilumAttendu () <<
				std::endl;
				leDecodageDOptionsPilum.Usage ();
			exit (1);
		}	//	switch


	//
	//	Execution
	//	---------
	//

	OptionsPilum
				lesOptionsPilum (
					modeVerbeux,
					montrerLeCodeParPilum,
					tailleDeLaPile,
					leGenreDExecution,
					montrerLAideInteractiveInitialement );

	Pilum		laMachine (
					"Pilum",
					nomDuFichierBinaire,
					& lesOptionsPilum );

	laMachine.Executer ();

	}	//	main
