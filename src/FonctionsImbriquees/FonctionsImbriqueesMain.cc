// =========================================================================
//	FonctionsImbriqueesMain.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "FonctionsImbriquees.h"

#include "Langues.h"

#include "LanguesFonctionsImbriquees.h"
#include "DecodageDOptionsFonctionsImbriquees.h"

#include "LanguesPilum.h"
#include "LanguesSynthesePilum.h"

#include <iostream>

#include <cstdlib>


int
main (int nbDArguments, CharPTR lesArguments [])
	{

	//
	//	Initialisation
	//	--------------
	//

	InitialiserLanguesSupportCPlusPlus ();

	InitialiserLanguesSynthesePilum ();
	InitialiserLanguesPilum ();


	//
	//	Decodage des options et arguments
	//	---------------------------------
	//

	DecodageDOptionsFonctionsImbriquees
				leDecodageDOptionsFonctionsImbriquees (
					nbDArguments,
					lesArguments,
					& Options :: VersionFonctionsImbriquees );
	
	leDecodageDOptionsFonctionsImbriquees.Initialiser ();

	int		indicePremierArgumentNonOption =
					leDecodageDOptionsFonctionsImbriquees.DecortiquerLesOptions ();
	
	bool		modeVerbeux =
					leDecodageDOptionsFonctionsImbriquees.ModeVerbeux ();
	bool		modeDebugSynthese =
					leDecodageDOptionsFonctionsImbriquees.ModeDebugSynthese ();

	bool		montrerLeCodeSource =
					leDecodageDOptionsFonctionsImbriquees.MontrerLeCodeSource ();

	bool		commenterLeCode =
					leDecodageDOptionsFonctionsImbriquees.CommenterLeCode ();
	bool		marquerLesBlocsDActivation =
					leDecodageDOptionsFonctionsImbriquees.
						MarquerLesBlocsDActivation ();
	bool		optimiserLesSauts =
					leDecodageDOptionsFonctionsImbriquees.OptimiserLesSauts ();
	bool		montrerLeCodeParLeSynthetiseur =
					leDecodageDOptionsFonctionsImbriquees.
						MontrerLeCodeParLeSynthetiseur ();


	bool		montrerLeCodeParPilum =
					leDecodageDOptionsFonctionsImbriquees.MontrerLeCodeParPilum ();

	long		laTailleDeLaPile =
					leDecodageDOptionsFonctionsImbriquees.TailleDeLaPile ();

	GenreDExecution
				leGenreDExecution =
					leDecodageDOptionsFonctionsImbriquees.LeGenreDExecution ();

	bool		montrerLAideInteractiveInitialement =
					leDecodageDOptionsFonctionsImbriquees.
						MontrerLAideInteractiveInitialement ();


	//
	//	Analyse du nombre d'arguments
	//	-----------------------------
	//
	
	int		nbDArgumentsNonOptions =
					nbDArguments - indicePremierArgumentNonOption;

	switch (nbDArgumentsNonOptions)
		{
		case 0 :
			break;
		default:
			std::cerr << leDecodageDOptionsFonctionsImbriquees.Usage ();
			exit (1);
		}	//	switch

	if (montrerLeCodeSource)
		MontrerLeContenuDuFichier ("FonctsImbriquees.pas");


	//
	//	Synthese du code
	//	----------------
	//

	Chaine	nomDuFichierBinaire = "FonctionsImbriquees.valeur";
	std::ofstream
				fichierBinaire (nomDuFichierBinaire.c_str (), std::ios_base :: out);

	if (! fichierBinaire)
		{
		SortieSurErreur (
			MiseEnForme (
				gLANGUE_SynthesePilum ->
					FormatPasPuOuvrirLeFichierBinaireEnEcriture (),
				nomDuFichierBinaire ),
			1 );
		}

	OptionsSynthese
				lesOptionsSynthese (
					modeVerbeux,
					modeDebugSynthese,
					montrerLeCodeParLeSynthetiseur,
					commenterLeCode,
					marquerLesBlocsDActivation,
					optimiserLesSauts );

	SynthFonctionsImpriqueesPTR
				leSynthetiseur =
					new SynthFonctionsImpriquees (
						"Synthetiseur FonctionsImbriquees",
						& std::cout,
						& fichierBinaire,
						& lesOptionsSynthese );

	leSynthetiseur -> SynthetiserLeCode ();

	delete leSynthetiseur;
		//	force l'execution du destructeur,
		//	charge de la terminaison de la synthese

	fichierBinaire.close (); 


	//
	//	Execution
	//	---------
	//

	OptionsPilum
				lesOptionsPilum (
					modeVerbeux,
					montrerLeCodeParPilum,
					laTailleDeLaPile,
					leGenreDExecution,
					montrerLAideInteractiveInitialement );

	Pilum		laMachine (
					"Pilum pour FonctionsImbriquees",
					nomDuFichierBinaire,
					& lesOptionsPilum );

	laMachine.Executer ();

	}	//	main
