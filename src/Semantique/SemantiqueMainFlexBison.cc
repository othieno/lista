// =========================================================================
//	SemantiqueMainFlexBison.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================



#include "SupportCPlusPlus.h"

#include "Langues.h"
#include "LanguesPredefinis.h"

#include "LanguesLexique.h"
#include "LanguesSyntaxe.h"
#include "LanguesSemantique.h"

#include "SupportFlexBison.h"

#include "SupportFlexBisonLista.h"

#include "AnalyseurListaFlexBison.h"

#include "DecodageDOptionsSemantique.h"

#if defined SYNTHESE_PILUM
	#include "LanguesPilum.h"
	#include "LanguesSynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */

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
	
	InitialiserLanguesPredefinis ();

	InitialiserLanguesSupportCPlusPlus ();

	InitialiserLanguesLexique ();
	InitialiserLanguesSyntaxe ();
	InitialiserLanguesSemantique ();

#if defined SYNTHESE_PILUM
	InitialiserLanguesSynthesePilum ();
	InitialiserLanguesPilum ();
#endif /* SYNTHESE_PILUM */


	//
	//	Initialisation des variables globales dynamiques
	//

	InitialiserSemantique ();

	//
	//	Decodage des options et arguments
	//	---------------------------------
	//
	
	DecodageDOptionsSemantique
				leDecodageDOptionsSemantique (
					nbDArguments,
					lesArguments,
					& Options :: VersionSemantiqueFlexBison );
	
	leDecodageDOptionsSemantique.Initialiser ();

	leDecodageDOptionsSemantique.EnregistrerLAssociation (
		new AssocDecodageDOptionsSemantique (
			& Options :: ArgumentsCompilateurs,
			& leDecodageDOptionsSemantique,
			& DecodageDOptionsSemantique :: ArgumentsNonOptions ));

	int		indicePremierArgumentNonOption =
					leDecodageDOptionsSemantique.DecortiquerLesOptions ();
	
	bool		modeVerbeux =
					leDecodageDOptionsSemantique.ModeVerbeux ();
	bool		modeDebug =
					leDecodageDOptionsSemantique.ModeDebug ();

	bool		montrerLeCodeSource =
					leDecodageDOptionsSemantique.MontrerLeCodeSource ();
	bool		montrerLesTerminaux =
					leDecodageDOptionsSemantique.MontrerLesTerminaux ();

	bool		sortirALaPremiereErreurLexicale =
					leDecodageDOptionsSemantique.SortirALaPremiereErreurLexicale ();
	bool		sortirALaPremiereErreurSyntaxique =
					leDecodageDOptionsSemantique.SortirALaPremiereErreurSyntaxique ();
	bool		sortirALaPremiereErreurSemantique =
					leDecodageDOptionsSemantique.SortirALaPremiereErreurSemantique ();

	bool		traduire =
					leDecodageDOptionsSemantique.Traduire ();

	StrategieDEvaluationPTR
				laStrategie =
					leDecodageDOptionsSemantique.LaStrategieDEvaluation ();
	
	bool		courtCircuitLogiquesBinaires =
					leDecodageDOptionsSemantique.CourtCircuitLogiquesBinaires ();

	bool		montrerLesAppelsImbriques =
					leDecodageDOptionsSemantique.MontrerLesAppelsImbriques ();

	bool		montrerLesDictionnaires =
					leDecodageDOptionsSemantique.MontrerLesDictionnaires ();
	bool		montrerLeDictionnaireDesPredefinis =
					leDecodageDOptionsSemantique.MontrerLeDictionnaireDesPredefinis ();
	bool		montrerLInferenceDeType =
					leDecodageDOptionsSemantique.MontrerLInferenceDeType ();
	bool		montrerLesGraphesSemantiques =
					leDecodageDOptionsSemantique.MontrerLesGraphesSemantiques ();
	bool		montrerLeCodePostfixe =
					leDecodageDOptionsSemantique.MontrerLeCodePostfixe ();
	bool		evaluerDirectement =
					leDecodageDOptionsSemantique.EvaluerDirectement ();
	bool		traceDEvaluationDirecte =
					leDecodageDOptionsSemantique.TraceDEvaluationDirecte ();

#if defined SYNTHESE_PILUM

	bool		commenterLeCode =
					leDecodageDOptionsSemantique.CommenterLeCode ();
	bool		marquerLesBlocsDActivation =
					leDecodageDOptionsSemantique.MarquerLesBlocsDActivation ();
	bool		optimiserLesSauts =
					leDecodageDOptionsSemantique.OptimiserLesSauts ();
	bool		montrerLeCodeParLeSynthetiseur =
					leDecodageDOptionsSemantique.MontrerLeCodeParLeSynthetiseur ();
	bool		modeDebugSynthese =
					leDecodageDOptionsSemantique.ModeDebugSynthese ();

	bool		evaluerParPilum =
					leDecodageDOptionsSemantique.EvaluerParPilum ();
	long		tailleDeLaPile =
					leDecodageDOptionsSemantique.TailleDeLaPile ();

	GenreDExecution
				leGenreDExecution =
					leDecodageDOptionsSemantique.LeGenreDExecution ();

	bool		montrerLeCodeParLaMachinePilum =
					leDecodageDOptionsSemantique.MontrerLeCodeParPilum ();
	bool		montrerLAideInteractiveInitialement =
					leDecodageDOptionsSemantique.MontrerLAideInteractiveInitialement ();

#endif /* SYNTHESE_PILUM */

	
	//
	//	Analyse du nombre d'arguments
	//	-----------------------------
	//
	
	int		nbDArgumentsNonOptions =
					nbDArguments - indicePremierArgumentNonOption;

	Chaine	nomDuFichierSource;
		
	CharPTR
				* lesArgumentsAUtiliser;

	switch (nbDArgumentsNonOptions)
		{
		case 0 :
			lesArgumentsAUtiliser = lesArguments;
			break;

		case 1 :
			nomDuFichierSource =
				lesArguments [indicePremierArgumentNonOption];

			if (montrerLeCodeSource)
				MontrerLeContenuDuFichier (nomDuFichierSource);

			lesArgumentsAUtiliser =
				& lesArguments [indicePremierArgumentNonOption];
			break;

		default:
			std::cerr << leDecodageDOptionsSemantique.Usage ();
			exit (1);
		}	//	switch
		
	int		lesArgumentsRestants = nbDArgumentsNonOptions;


	//
	//	Enregistrement des options
	//	--------------------------
	//
	
	OptionsFlexBison
				lesOptionsFlexBison (
					modeVerbeux,
					montrerLesAppelsImbriques );
											
	OptionsStrategie
				lesOptionsStrategie (
					laStrategie,
					courtCircuitLogiquesBinaires );

	OptionsSemantique
				lesOptionsSemantique (
					sortirALaPremiereErreurSemantique,
					modeVerbeux,
					montrerLesDictionnaires,
					montrerLeDictionnaireDesPredefinis,
					montrerLInferenceDeType,
					montrerLesGraphesSemantiques,
					montrerLeCodePostfixe,
					evaluerDirectement,
					traduire );

	OptionsEvaluation
				lesOptionsEvaluation (
					traceDEvaluationDirecte );


	//
	//	Enregistrement du temps
	//	-----------------------
	//
	
	time_t	tempsAuDebut = time (NULL);


#if defined SYNTHESE_PILUM

	//	Fichier de code binaire
	//	-----------------------
	
	Chaine	nomDuFichierSourceSansExtension;
	Chaine	nomDuFichierBinaire		=
					gLANGUE_SynthesePilum ->
						NomDuFichierBinaireParDefaut ();
	Chaine	suffixeFichierBinaire		=
					MiseEnForme (
						"%s%s",
						lesOptionsStrategie.StrategieDEvaluation () ->
							SuffixeFichiersBinaires (),
						gLANGUE_SynthesePilum ->
							SuffixeFichiersBinairesFlexBison () );

	if (nbDArgumentsNonOptions == 1)
		{
		nomDuFichierSourceSansExtension =
			NomDuFichierSansExtension (nomDuFichierSource);
		nomDuFichierBinaire =
			MiseEnForme (
				"%s%s",
				nomDuFichierSourceSansExtension,
				suffixeFichierBinaire );
		}

	std::ofstream
				fichierBinaire (
					nomDuFichierBinaire.c_str (), std::ios_base :: out );
	
	if (! fichierBinaire)
		{
		std::cerr <<
			MiseEnForme (
				gLANGUE_SynthesePilum ->
					FormatPasPuOuvrirLeFichierBinaireEnEcriture (),
				nomDuFichierBinaire ) <<
			std::endl;
		exit (1);
		}
	
#endif /* SYNTHESE_PILUM */



#if defined SYNTHESE_PILUM

	//	Synthese de code Pilum pour Lista
	//	---------------------------------
	
	OptionsSynthese
				lesOptionsSynthese (
					modeVerbeux,
					modeDebugSynthese,
					montrerLeCodeParLeSynthetiseur,
					commenterLeCode,
					marquerLesBlocsDActivation,
					optimiserLesSauts );

	SynthetiseurPilumListaPTR
				leSynthetiseurPilumLista =
					new SynthetiseurPilumLista (
						gLANGUE_SynthesePilum ->
							NomDuSynthetiseurPilumListaParDefaut (),
						& std::cout,
						& fichierBinaire,
						& lesOptionsSynthese );

#endif /* SYNTHESE_PILUM */


	//	L'analyseur lui-meme
	//	--------------------
	
	extern AnalyseurListaFlexBisonPTR
				gAnalyseurListaFlexBison;
	
	gAnalyseurListaFlexBison =
		new AnalyseurListaFlexBison (
			modeDebug,
			montrerLesTerminaux,
			& lesOptionsStrategie,
			& lesOptionsSemantique,
			& lesOptionsFlexBison,
			& lesOptionsEvaluation
#if defined SYNTHESE_PILUM
			, leSynthetiseurPilumLista
#endif /* SYNTHESE_PILUM */
			);

	
	//	C'est parti !
	//	-----------
	
	extern bool
				gSortirALaPremiereErreurLexicale;
	extern bool
				gSortirALaPremiereErreurSyntaxique;
	
	extern bool
				gSourceCorrectLexicalement;
	extern bool
				gSourceCorrectSyntaxiquement;

	gSortirALaPremiereErreurLexicale = sortirALaPremiereErreurLexicale;
	gSortirALaPremiereErreurSyntaxique = sortirALaPremiereErreurSyntaxique;

	if (
		! AnalyserFlexBison (
			lesArgumentsRestants,
			lesArgumentsAUtiliser,
			modeVerbeux,
			traduire )
		)
		;	//	RIEN

	if (! traduire)
		{
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

		if (gAnalyseurListaFlexBison -> SourceCorrectSemantiquement ())
			std::cout <<
				gLANGUE_Semantique ->
					CodeSemantiquementCorrect () <<
				std::endl;
		else
			std::cout <<
				gLANGUE_Semantique ->
					CodeSemantiquementIncorrect () <<
				std::endl;
		}	// if

#if defined SYNTHESE_PILUM

	leSynthetiseurPilumLista -> SynthetiserLEpilogue ();
	leSynthetiseurPilumLista -> FinaliserLaSyntheseDeCode ();
	leSynthetiseurPilumLista -> EcrireSurLeFichierBinaire ();

#endif /* SYNTHESE_PILUM */

	delete gAnalyseurListaFlexBison;

#if defined SYNTHESE_PILUM

	delete leSynthetiseurPilumLista;

	fichierBinaire.close (); 

	if (! traduire)
		std::cout <<
			MiseEnForme (
				gLANGUE_SynthesePilum ->
					FormatFichierDeCodePilumAEteCree (),
				nomDuFichierBinaire ) <<
			std::endl;

#endif /* SYNTHESE_PILUM */

	time_t	tempsALaFin = time (NULL);

	if (! traduire)
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatTempsEcoule (),
				tempsALaFin - tempsAuDebut ) <<
			std::endl;

#if defined SYNTHESE_PILUM

	//
	//	S'il y a lieu, creation d'un fichier executable autonome
	//	--------------------------------------------------------
	//

	if (nbDArgumentsNonOptions == 1)
		{
		Chaine	nomDuFichierExecutable =
						MiseEnForme (
							"%s.exec%s",
							nomDuFichierSourceSansExtension,
							suffixeFichierBinaire );
		Chaine	commande_creer_executable =
						MiseEnForme (
							"echo Pilum %s > %s; chmod +x %s",
							nomDuFichierBinaire,
							nomDuFichierExecutable,
							nomDuFichierExecutable );
		system (commande_creer_executable.c_str ());
		}


	//
	//	S'il y a lieu, execution par la machine Pilum
	//	---------------------------------------------
	//

	if (evaluerParPilum)
		{
		OptionsPilum
					lesOptionsPilum (
						modeVerbeux,
						montrerLeCodeParLaMachinePilum,
						tailleDeLaPile,
						leGenreDExecution,
						montrerLAideInteractiveInitialement );

		Pilum		laMachine (
						gLANGUE_SynthesePilum ->
							NomDeLaMachinePilumParDefaut (),
						nomDuFichierBinaire,
						& lesOptionsPilum );

		laMachine.Executer ();
		}

#endif /* SYNTHESE_PILUM */

	}	//	main
