// =========================================================================
//	SemantiqueMainPredictifDescenteRecursive.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Langues.h"

#include "SupportCPlusPlus.h"

#include "AnalyseurPredictifDescenteRecursiveLista.h"

#include "LanguesPredefinis.h"

#include "LanguesLexique.h"
#include "LanguesSyntaxe.h"
#include "LanguesSemantique.h"
#include "LanguesSynthesePilum.h"

#if defined SYNTHESE_PILUM
	#include "LanguesPilum.h"
#endif /* SYNTHESE_PILUM */

#include "InitialiserSemantique.h"

#include "DecodageDOptionsSemantique.h"

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

	InitialiserSemantique ();


	//
	//	Decodage des options et arguments
	//	---------------------------------
	//
	
	DecodageDOptionsSemantique
				leDecodageDOptionsSemantique (
					nbDArguments,
					lesArguments,
					& Options :: VersionSemantiquePredictifDescenteRecursive );
	
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

	GenreLectureAuClavier
				leGenreLectureAuClavier;

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

	ProducteurDeCaracteres
				* leProducteurDeCaracteres;

	switch (nbDArgumentsNonOptions)
		{
		case 0 :
			leProducteurDeCaracteres = LireLeFlot (& std::cin, '\0');
			leGenreLectureAuClavier = kLectureIgnorantLePremierCaractere;
			break;

		case 1 :
			{
			nomDuFichierSource =
				lesArguments [indicePremierArgumentNonOption];

			leProducteurDeCaracteres =
				LireLeFichier (nomDuFichierSource, SENTINELLE);
			leGenreLectureAuClavier = kLectureSansAutre;
			
			if (montrerLeCodeSource)
				MontrerLeContenuDuFichier (nomDuFichierSource);
			}
			break;

		default:
			std::cerr << leDecodageDOptionsSemantique.Usage ();
			exit (1);
		}	//	switch
		

	//
	//	Enregistrement des options
	//	--------------------------
	//
	
	OptionsLexique
				lesOptionsLexique (
					sortirALaPremiereErreurLexicale,
					modeVerbeux,
					montrerLesTerminaux,
					traduire );

	AnalyseurLexicalLista
				lAnalyseurLexical (
					leProducteurDeCaracteres,
					& lesOptionsLexique );

	OptionsSyntaxe
				lesOptionsSyntaxe (
					sortirALaPremiereErreurSyntaxique,
					modeVerbeux,
					montrerLesTerminaux );
										
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


	//
	//	Compilation
	//	-----------
	//
	
	Chaine	nomDuFichierSourceSansExtension;
	Chaine	nomDuFichierBinaire =
					gLANGUE_SynthesePilum ->
						NomDuFichierBinaireParDefaut ();
	Chaine	suffixeFichierBinaire =
					MiseEnForme (
						"%s%s",
						lesOptionsStrategie.StrategieDEvaluation () ->
							SuffixeFichiersBinaires (),
						gLANGUE_SynthesePilum ->
							SuffixeFichiersBinairesPredictifDescenteRecursive () );

	if (nbDArgumentsNonOptions == 1)
		{
		nomDuFichierSourceSansExtension =
			NomDuFichierSansExtension (nomDuFichierSource);
		nomDuFichierBinaire =
			nomDuFichierSourceSansExtension + suffixeFichierBinaire;
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
	

	OptionsSynthese
				lesOptionsSynthese (
					modeVerbeux,
					modeDebugSynthese,
					montrerLeCodeParLeSynthetiseur,
					commenterLeCode,
					marquerLesBlocsDActivation,
					optimiserLesSauts );
																													 
	CompilateurPilumListaPredictifDescenteRecursivePTR
				leCompilateurPilumListaPredictifDescenteRecursive =
					new CompilateurPilumListaPredictifDescenteRecursive (
						& lAnalyseurLexical,
						leGenreLectureAuClavier,
						& lesOptionsSyntaxe,
						& lesOptionsStrategie,
						& lesOptionsSemantique,
						& lesOptionsEvaluation,
						& std::cout,
						& fichierBinaire,
						& lesOptionsSynthese );
	
	leCompilateurPilumListaPredictifDescenteRecursive -> Analyser ();

	delete leCompilateurPilumListaPredictifDescenteRecursive;

	fichierBinaire.close (); 

	if (! traduire)
		std::cout <<
			MiseEnForme (
				gLANGUE_SynthesePilum ->
					FormatFichierDeCodePilumAEteCree (),
				nomDuFichierBinaire ) <<
			std::endl;

	time_t	tempsALaFin = time (NULL);

	if (! traduire)
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatTempsEcoule (),
				tempsALaFin - tempsAuDebut ) <<
			std::endl;


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
								
		Pilum
					laMachine (
						gLANGUE_SynthesePilum ->
							NomDeLaMachinePilumParDefaut (),
						nomDuFichierBinaire,
						& lesOptionsPilum );

		laMachine.Executer ();
		}

#else /* SYNTHESE_PILUM */

	//
	//	Analyse lexico-syntaxo-semantique
	//	---------------------------------
	//
	
	AnalyseurListaPredictifDescenteRecursive
				lAnalyseurListaPredictifDescenteRecursive (
					& lAnalyseurLexical,
					leGenreLectureAuClavier,
					& lesOptionsSyntaxe,
					& lesOptionsStrategie,
					& lesOptionsSemantique,
					& lesOptionsEvaluation );

	lAnalyseurListaPredictifDescenteRecursive.Analyser ();

	time_t	tempsALaFin = time (NULL);

	if (! traduire)
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatTempsEcoule (),
				tempsALaFin - tempsAuDebut ) <<
			std::endl;

#endif /* SYNTHESE_PILUM */

	}	//	main
