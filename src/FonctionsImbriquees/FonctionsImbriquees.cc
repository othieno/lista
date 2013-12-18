// =========================================================================
//	FonctionsImbriquees.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "FonctionsImbriquees.h"

#include "LanguesSynthesePilum.h"


//	------------------------------------------------------------------------
//	Constantes
//	------------------------------------------------------------------------

//	Les niveaux statiques sont ceux ou sont declares les identificateurs
//	Par convention, celui du programme principal est 1
//	Les parametres formels et variables sont declares un niveaux au-dessus
//	de la fonction ou procedure qui contient leur declaration

/*
Rappel :

	const int		kPosLienStatique	= -2;

	struct AccesStatique
		//	sans constructeur: utilise dans une union dans "InstrPilum"
		{
		int									fDifferenceStatique;
		int									fDeplacement;
		};

	void										LienStatique (
													int		niveauDAppel,
													int		niveauDeDeclaration );

	void										AccesCellule (
													AccesStatique			lAccesStatique,
													GenreAccesCellule		leGenreAcces );

	AdressePile								RemonteeStatique (AccesStatique lAccesStatique);
*/

const int		kNiveauCorpsProgramme		=  1;
const int		kNiveauCorpsLaProcedure		=  2;
const int		kNiveauCorpsImbriquee		=  3;

const int		kNiveauDeclarationAppelsCoexistants		= kNiveauCorpsProgramme;
const int		kNiveauDeclarationI							= kNiveauCorpsLaProcedure;
const int		kNiveauDeclarationInteressante			= kNiveauCorpsLaProcedure;

const int		kDeplI							= -3;
const int		kDeplAppelsCoexistants		=  1;
const int		kDeplInteressante				=  1;

const int		kIndentation					=  5;


//	------------------------------------------------------------------------
//	SynthFonctionsImpriquees
//	------------------------------------------------------------------------

SynthFonctionsImpriquees :: SynthFonctionsImpriquees (
	Chaine					leNom,
	std::ostream			* leFlotTexte,
	std::ofstream			* leFichierBinaire,
	OptionsSynthesePTR	lesOptionsSynthese )
	:	SynthetiseurPilum (leNom, lesOptionsSynthese)
	{
	fOptionsSynthese = lesOptionsSynthese;
	
	fFlotTexte = leFlotTexte;
	fFichierBinaire = leFichierBinaire;

	fEtiquetteDeImbriquee = CreerEtiquette ("imbriquee");
	fEtiquetteDeLaProcedure = CreerEtiquette ("laProcedure");

	}	//	SynthFonctionsImpriquees :: SynthFonctionsImpriquees


SynthFonctionsImpriquees :: ~ SynthFonctionsImpriquees ()
	{
	FinaliserLeCodePilum ();

	if (fOptionsSynthese -> MontrerLeCode ())
		EcrireLeCodeEnTexte (
			gLANGUE_SynthesePilum ->
				FormatCodeSynthetise (),
			fFlotTexte,
			true );

	EcrireCodeBinaireSurLeFichier (fFichierBinaire);	
	}	//	SynthFonctionsImpriquees :: ~ SynthFonctionsImpriquees


//	------------------------------------------------------------------------
//	SynthetiserLeCode
//	------------------------------------------------------------------------

void SynthFonctionsImpriquees :: SynthetiserLeCode ()
	{
	Zeroadique (iEcrireFinDeLigne);
	Chaine_ ("On y va...");
	Zeroadique (iEcrireChaine);
	Zeroadique (iEcrireFinDeLigne);

	SynthetiserImbriquee (fEtiquetteDeImbriquee);
	SynthetiserLaProcedure (fEtiquetteDeLaProcedure);
	SynthetiserProgramme ();

	Chaine_ ("...c'est fini!");
	Zeroadique (iEcrireChaine);
	Zeroadique (iEcrireFinDeLigne);

	Zeroadique (iHalte);
	}	//	SynthFonctionsImpriquees :: SynthetiserLeCode


//	------------------------------------------------------------------------
//	SynthetiserImbriquee
//	------------------------------------------------------------------------

void SynthFonctionsImpriquees :: SynthetiserImbriquee (
	VariableLogiqueEtiquettePTR etiquetteDuCorps )
	{
	AccesStatique
				accesA_appelsCoexistants =
					{
					kNiveauCorpsImbriquee - kNiveauDeclarationAppelsCoexistants,
					kDeplAppelsCoexistants
					},
				accesA_Interessante =
					{
					kNiveauCorpsImbriquee - kNiveauDeclarationInteressante,
					kDeplInteressante
					};

	VariableLogiqueEtiquettePTR
				etiquetteApresLeCorps = CreerEtiquette ("apres_imbriquee");

	Saut (iSauter, etiquetteApresLeCorps);
	PlacerEtiquette (etiquetteDuCorps);
	Commentaire ("Debut du corps de 'imbriquee'");

	Chaine_ (" ");
	AccesCellulePourValeur (accesA_appelsCoexistants);
	Entier (kIndentation);
	Zeroadique (iFoisEntier);
	Zeroadique (iRepliquerChaine);
	Zeroadique (iEcrireChaine);
	Commentaire ("writeln (' ': appels_coexistants * indentation)");

	Chaine_ ("--> Entree dans 'imbriquee'");
	Zeroadique (iEcrireChaine);
	Zeroadique (iEcrireFinDeLigne);

	AccesCellulePourValeur (accesA_appelsCoexistants);
	Zeroadique (iEcrireEntier);
	Zeroadique (iEcrireFinDeLigne);
	Commentaire ("writeln (appelsCoexistants)");

	AccesCellulePourValeur (accesA_Interessante);
	Zeroadique (iEcrireEntier);
	Zeroadique (iEcrireFinDeLigne);
	Commentaire ("writeln (interessante)");

	Chaine_ (" ");
	AccesCellulePourValeur (accesA_appelsCoexistants);
	Entier (kIndentation);
	Zeroadique (iFoisEntier);
	Zeroadique (iRepliquerChaine);
	Zeroadique (iEcrireChaine);
	Commentaire ("writeln (' ': appels_coexistants * indentation)");

	Chaine_ ("--> Sortie de 'imbriquee'");
	Zeroadique (iEcrireChaine);
	Zeroadique (iEcrireFinDeLigne);

	bool		marquerLesBlocsDActivation =
					fOptionsSynthese -> MarquerLesBlocsDActivation ();
	int		tailleParametres = 1;	// le lien statique
	int		tailleADesempiler =
					marquerLesBlocsDActivation
						?	tailleParametres + 1
							//	1 pour la marque du block
						: tailleParametres;

	Entier (iRetourDeProcedure, tailleADesempiler);
	Commentaire ("soit 1 pour le Lien Statique (pas d'argument d'appel)");
	if (marquerLesBlocsDActivation)
		Commentaire ("et 1 pour la marque separant les blocs d'activation");

	Commentaire ("Fin du corps de 'imbriquee'");
	PlacerEtiquette (etiquetteApresLeCorps);
	}	//	SynthFonctionsImpriquees :: SynthetiserImbriquee


//	------------------------------------------------------------------------
//	SynthetiserLaProcedure
//	------------------------------------------------------------------------

void SynthFonctionsImpriquees :: SynthetiserLaProcedure (
	VariableLogiqueEtiquettePTR etiquetteDuCorps )
	{
	bool		marquerLesBlocsDActivation =
					fOptionsSynthese -> MarquerLesBlocsDActivation ();
	AccesStatique
				accesA_I =
					{kNiveauCorpsLaProcedure - kNiveauDeclarationI, kDeplI},
				accesA_appelsCoexistants =
					{
					kNiveauCorpsLaProcedure - kNiveauDeclarationAppelsCoexistants,
					kDeplAppelsCoexistants
					},
				accesA_Interessante =
					{
					kNiveauCorpsLaProcedure - kNiveauDeclarationInteressante,
					kDeplInteressante
					};

	VariableLogiqueEtiquettePTR
				etiquetteApresLeCorps = CreerEtiquette ("apres_laProcedure");

	VariableLogiqueEntierePTR
				leNombreLogTemporaires =
					new VariableLogiqueEntiere ("leNombreLogTemporaires");
	int		nbTemporaires = 1;	//	pour le seul 'interessante'

	leNombreLogTemporaires -> UnifierValeur (
		new ValeurEntiere (nbTemporaires), false );

	Saut (iSauter, etiquetteApresLeCorps);
	PlacerEtiquette (etiquetteDuCorps);
	Commentaire ("Debut du corps de 'laProcedure'");

	ReserverCellules (leNombreLogTemporaires);
	Commentaire ("interessante");

	AccesCellulePourAdresse (accesA_appelsCoexistants);
	Zeroadique (iIncrEntier);
	Commentaire ("appelsCoexistants := appelsCoexistants + 1");

	Chaine_ (" ");
	AccesCellulePourValeur (accesA_appelsCoexistants);
	Entier (kIndentation);
	Zeroadique (iFoisEntier);
	Zeroadique (iRepliquerChaine);
	Zeroadique (iEcrireChaine);
	Commentaire ("writeln (' ': appels_coexistants * indentation)");

	Chaine_ ("--> Entree dans laProcedure : i = ");
	Zeroadique (iEcrireChaine);
	AccesCellulePourValeur (accesA_I);
	Zeroadique (iEcrireEntier);
	Zeroadique (iEcrireFinDeLigne);
	Commentaire ("writeln ('--> Entree dans laProcedure : i = ', i)");

	AccesCellulePourAdresse (accesA_Interessante);
	AccesCellulePourValeur (accesA_I);
	Entier (7);
	Zeroadique (iPlusEntier);
	Zeroadique (iDupliquer);
	Zeroadique (iFoisEntier);
	Zeroadique (iStocker);
	Commentaire ("interessante := sqr (i + 7)");

		{			//	synthese du test et des appels de fonctions
		
		VariableLogiqueEtiquettePTR
					etiquetteSiFaux = CreerEtiquette ("siFaux"),
					etiquetteSuite  = CreerEtiquette ("suiteSi");
		
		AccesCellulePourValeur (accesA_I);
		Entier (0);
		Zeroadique (iSupEntier);
		Saut (iSauterSiFaux, etiquetteSiFaux);
		
		if (marquerLesBlocsDActivation)
			MarquerBlocDActivation ("laProcedure");
		AccesCellulePourValeur (accesA_I);
		Entier (1);
		Zeroadique (iMoinsEntier);
		Commentaire ("argument d'appel a 'laProcedure'");
		LienStatique (kNiveauCorpsLaProcedure, kNiveauCorpsProgramme);
		Commentaire ("Lien Statique pour l'appel de 'laProcedure'");
		Appel (fEtiquetteDeLaProcedure);
		Commentaire ("laProcedure");
		
		Saut (iSauter, etiquetteSuite);
		PlacerEtiquette (etiquetteSiFaux);
		
		if (marquerLesBlocsDActivation)
			MarquerBlocDActivation (("imbriquee"));
		LienStatique (kNiveauCorpsLaProcedure, kNiveauCorpsLaProcedure);
		Commentaire ("Lien Statique pour l'appel de 'imbriquee'");
		Appel (fEtiquetteDeImbriquee);
		Commentaire ("imbriquee");
		
		PlacerEtiquette (etiquetteSuite);
		}

	Chaine_ (" ");
	AccesCellulePourValeur (accesA_appelsCoexistants);
	Entier (kIndentation);
	Zeroadique (iFoisEntier);
	Zeroadique (iRepliquerChaine);
	Zeroadique (iEcrireChaine);
	Commentaire ("writeln (' ': appels_coexistants * indentation)");

	Chaine_ ("<-- Sortie de laProcedure : i = ");
	Zeroadique (iEcrireChaine);
	AccesCellulePourValeur (accesA_I);
	Zeroadique (iEcrireEntier);
	Zeroadique (iEcrireFinDeLigne);
	Commentaire ("writeln ('--> Sortie de laProcedure : i = ', i)");

	AccesCellulePourAdresse (accesA_appelsCoexistants);
	Zeroadique (iDecrEntier);
	Commentaire ("appelsCoexistants := appelsCoexistants - 1");

	Desempiler (nbTemporaires);
	Commentaire ("interessante");

	int		tailleParametres = 2;	// l'argument d'appel et le lien statique
	int		tailleADesempiler =
					marquerLesBlocsDActivation
						?	tailleParametres + 1
							//	1 pour la marque du block
						: tailleParametres;

	Entier (iRetourDeProcedure, tailleADesempiler);
	Commentaire ("soit 1 pour le Lien Statique et 1 pour l'argument d'appel");
	if (marquerLesBlocsDActivation)
		Commentaire ("et 1 pour la marque separant les blocs d'activation");

	Commentaire ("Fin du corps de 'laProcedure'");
	PlacerEtiquette (etiquetteApresLeCorps);
	}	//	SynthFonctionsImpriquees :: SynthetiserLaProcedure


//	------------------------------------------------------------------------
//	SynthetiserProgramme
//	------------------------------------------------------------------------

void SynthFonctionsImpriquees :: SynthetiserProgramme ()
	{
	AccesStatique
				accesA_appelsCoexistants =
					{
					kNiveauCorpsProgramme - kNiveauDeclarationAppelsCoexistants,
					kDeplAppelsCoexistants
					};
	
	VariableLogiqueEntierePTR
				leNombreLogTemporaires =
					new VariableLogiqueEntiere ("leNombreLogTemporaires");
		
	int		nbTemporaires = 1;	//	pour le seul 'appelsCoexistants'

	leNombreLogTemporaires ->
		UnifierValeur (
			new ValeurEntiere (nbTemporaires), false );

	Commentaire ("Debut du corps du programme");

	ReserverCellules (leNombreLogTemporaires);
	Commentaire ("appelsCoexistants");

	AccesCellulePourAdresse (accesA_appelsCoexistants);
	Entier (0);
	Zeroadique (iStocker);
	Commentaire ("appelsCoexistants := 0");

	if (fOptionsSynthese -> MarquerLesBlocsDActivation ())
		MarquerBlocDActivation ("laProcedure");

	Entier (3);
	Commentaire ("argument d'appel a 'laProcedure'");
	LienStatique (kNiveauCorpsProgramme, kNiveauCorpsProgramme);
	Commentaire ("Lien Statique pour l'appel de 'laProcedure'");
	Appel (fEtiquetteDeLaProcedure);
	Commentaire ("laProcedure");

	DetruireCellules (leNombreLogTemporaires);
	Commentaire ("appelsCoexistants");

	Commentaire ("Fin du corps du programme");
	}	//	SynthFonctionsImpriquees :: SynthetiserProgramme
