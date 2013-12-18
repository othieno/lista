// =========================================================================
//	DecodageDOptions.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "DecodageDOptions.h"

#include "Version.h"

#include <cstdlib>

// -------------------------------------------------------------------------
//	OptionLigneDeCommande
// -------------------------------------------------------------------------

OptionLigneDeCommande :: OptionLigneDeCommande (
	Chaine						leNomCourt,
	Chaine						leNomLong,
	GenreDArgumentEventuel	leGenreDArgumentEventuel,
	Chaine						laDescrArgumentEventuel,
	Chaine						leCommentaire )
	{
	fNomCourt = leNomCourt;
	fNomLong = leNomLong;
	fGenreDArgumentEventuel = leGenreDArgumentEventuel;
	fDescrArgumentEventuel = laDescrArgumentEventuel;
	fCommentaire = leCommentaire;
	}

OptionLigneDeCommande :: OptionLigneDeCommande ()
	{
	fNomCourt = "";
	fNomLong = "";
	fGenreDArgumentEventuel = kAucun;
	fDescrArgumentEventuel = "";
	fCommentaire = "";
	}


// -------------------------------------------------------------------------

Chaine
OptionLigneDeCommande :: NomCourt ()
	{ return fNomCourt; }
Chaine
OptionLigneDeCommande :: NomLong ()
	{ return fNomLong; }
GenreDArgumentEventuel
OptionLigneDeCommande :: LeGenreDArgumentEventuel ()
	{ return fGenreDArgumentEventuel; }
Chaine
OptionLigneDeCommande :: DescrArgumentEventuel ()
	{ return fDescrArgumentEventuel; }
Chaine
OptionLigneDeCommande :: Commentaire ()
	{ return fCommentaire; }


// -------------------------------------------------------------------------
//	Options
// -------------------------------------------------------------------------

Options :: Options ()
	{}

Options :: ~ Options ()
	{}


// -------------------------------------------------------------------------
//	Versions des executables
// -------------------------------------------------------------------------

OptionsFR :: OptionsFR ()
	{}


Chaine
OptionsFR :: VersionLexiqueP ()
	{
	return
		"\tAnalyse lexicale Lista\n"
		"\tVersion prédictive, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionLexiqueF ()
	{
	return
		"\tAnalyse lexicale Lista\n"
		"\tVersion basée sur Flex, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionSyntaxePredictifDescenteRecursive ()
	{
	return
		"\tAnalyse lexicale/syntaxique Lista\n"
		"\tVersion prédictive/descente récursive, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionSyntaxeFlexBison ()
	{
	return
		"\tAnalyse lexicale/syntaxique Lista\n"
		"\tVersion basée sur Flex/Bison, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionSemantiquePredictifDescenteRecursive ()
	{
	return
		"\tAnalyse lexicale/syntaxique/sémantique Lista,\n"
		"\t    traduction et évaluation directe\n"
		"\tVersion prédictive/descente récursive, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionSemantiqueFlexBison ()
	{
	return
		"\tAnalyse lexicale/syntaxique/sémantique Lista,\n"
		"\t    traduction et évaluation directe\n"
		"\tVersion basée sur Flex/Bison, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionPredictifDescenteRecursive ()
	{
	return
		"\tAnalyse lexicale/syntaxique/sémantique Lista,\n"
		"\t    traduction et évaluation directe,\n"
		"\t    avec synthèse de code binaire Pilum\n"
		"\tVersion prédictive/descente récursive, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionFlexBison ()
	{
	return
		"\tAnalyse lexicale/syntaxique/sémantique Lista,\n"
		"\t    traduction et évaluation directe\n"
		"\t    avec synthèse de code binaire Pilum\n"
		"\tVersion basée sur Flex/Bison, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionPilum ()
	{
	return
		"\tImplantation Pilum, version "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsFR :: VersionFonctionsImbriquees ()
	{
	return
		"\tUn programme illustrant l'implantation des fonctions imbriquées 'à la Pascal',\n"
		"\t    avec synthèse de code binaire Pilum, version "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}


// -------------------------------------------------------------------------
//	Options des executables
// -------------------------------------------------------------------------

OptionLigneDeCommandePTR
OptionsFR :: OptionLigneDeCommandeVide ()
	{ return new OptionLigneDeCommande (); }

OptionLigneDeCommandePTR
OptionsFR :: OptionAide ()
	{
	return
		new OptionLigneDeCommande (
			"h",		"aide",							kAucun,			"",
			"affiche la presente aide"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionVersion ()
	{
	return
		new OptionLigneDeCommande (
			"v",		"version",						kAucun,			"",
			"affiche la version de ce logiciel"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionLangue ()
	{
	return
		new OptionLigneDeCommande (
			"l",		"langue",						kObligatoire,	"fr | en",
			"choix de la langue des identificateurs predefinis"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionModeVerbeux ()
	{
	return
		new OptionLigneDeCommande (
			"w",		"verbeux",						kAucun,			"",
			"mode verbeux donnant un peu plus d'information"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionModeDebug ()
	{
	return
		new OptionLigneDeCommande (
			"dd",		"debug-analyseurs",		kAucun,			"",
			"fait utiliser les analyseurs synthétisés par Flex et Bison en mode debug"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLeCodeSource ()
	{
	return
		new OptionLigneDeCommande (
			"ms",		"source",			kAucun,			"",
			"montrer le code source Lista"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLesTerminaux ()
	{
	return
		new OptionLigneDeCommande (
			"mt",		"terminaux",	kAucun,			"",
			"montrer les terminaux"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionSortirALaPremiereErreurLexicale ()
	{
	return
		new OptionLigneDeCommande (
			"rlex",	"erreur-lexicale",				kAucun,			"",
			"sortir a la premiere erreur lexicale"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionSortirALaPremiereErreurSyntaxique ()
	{
	return
		new OptionLigneDeCommande (
			"rsynt",	"erreur-syntaxique",				kAucun,			"",
			"sortir a la premiere erreur syntaxique"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionSortirALaPremiereErreurSemantique ()
	{
	return
		new OptionLigneDeCommande (
			"rsem",	"erreur-sémantique",				kAucun,			"",
			"sortir a la premiere erreur sémantique"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLesDictionnaires ()
	{
	return
		new OptionLigneDeCommande (
			"md",		"dictionnaires",	kAucun,			"",
			"montrer les dictionnaires"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLeDictionnaireDesPredefinis ()
	{
	return
		new OptionLigneDeCommande (
			"mq",		"predefinis",	kAucun,			"",
			"montrer le dictionnaire des identificateurs predefinis"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLesAppelsImbriques ()
	{
	return
		new OptionLigneDeCommande (
			"mf",		"imbriques",	kAucun,			"",
			"montrer les appels de fonctions imbriques lors de l'analyse par Bison"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLInferenceDeType ()
	{
	return
		new OptionLigneDeCommande (
			"mi",		"inference",	kAucun,			"",
			"montrer l'inference de type"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLesGraphesSemantiques ()
	{
	return
		new OptionLigneDeCommande (
			"mg",		"graphes",	kAucun,			"",
			"montrer les graphes sémantiques"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLeCodePostfixe ()
	{
	return
		new OptionLigneDeCommande (
			"mp",		"postfixe",	kAucun,			"",
			"montrer le code postfixe"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionLangueDestination ()
	{
	return
		new OptionLigneDeCommande (
			"lt",		"traduction",	kObligatoire,	"fr | en",
			"choix de la langue en laquelle traduire les identificateurs predefinis"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionStrategieParValeur ()
	{
	return
		new OptionLigneDeCommande (
			"sv",		"par-valeur",	kAucun,			"",
			"strategie d'évaluation 'appel par valeur'"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionStrategieParNom ()
	{
	return
		new OptionLigneDeCommande (
			"sn",		"par-nom",	kAucun,			"",
			"strategie d'évaluation 'appel par nom'"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionStrategieParBesoin ()
	{
	return
		new OptionLigneDeCommande (
			"sb",		"par-besoin",	kAucun,			"",
			"strategie d'évaluation (paresseuse) 'appel par besoin'"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionEvaluationDirecteSansTrace ()
	{
	return
		new OptionLigneDeCommande (
			"es",		"sans-trace",	kAucun,			"",
			"évaluation directe sans trace"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionEvaluationDirecteAvecTrace ()
	{
	return
		new OptionLigneDeCommande (
			"et",		"avec-trace",	kAucun,			"",
			"évaluation directe avec trace"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionCourtCircuitLogiquesBinaires ()
	{
	return
		new OptionLigneDeCommande (
			"cc",		"court-circuit",	kAucun,			"",
			"utiliser la sémantique avec court-circuit des opérateurs logique binaires"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionModeDebugSynthese ()
	{
	return
		new OptionLigneDeCommande (
			"ds",		"debug-synthèse",		kAucun,			"",
			"afficher le code Pilum synthétisé en mode debug"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionCommenterLeCode ()
	{
	return
		new OptionLigneDeCommande (
			"oc",		"commenter",		kAucun,			"",
			"ajoute des commentaires detaillant le rôle des instructions Pilum"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionMarquerLesBlocsDActivation ()
	{
	return
		new OptionLigneDeCommande (
			"ob",		"blocs",		kAucun,			"",
			"fait empiler une marque visuelle separant les blocs d'activation dans la pile"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionOptimiserLesSauts ()
	{
	return
		new OptionLigneDeCommande (
			"os",		"sauts",		kAucun,			"",
			"fait optimiser les sauts sur des sauts"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLeCodeParLeSynthetiseur ()
	{
	return
		new OptionLigneDeCommande (
			"mc",		"synthétiséur",	kAucun,			"",
			"montrer le code cree par le synthétiséur, avec les variables logiques"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionMontrerLeCodeParPilum ()
	{
	return
		new OptionLigneDeCommande (
			"pc",		"Pilum",		kAucun,			"",
			"fait afficher le contenu de la memoire du code par Pilum avant son execution"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionModeTracePilum ()
	{
	return
		new OptionLigneDeCommande (
			"pt",		"trace",		kAucun,			"",
			"fait utiliser Pilum en mode pas a pas"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionModeDebugPilum ()
	{
	return
		new OptionLigneDeCommande (
			"pd",		"debug-pilum",		kAucun,			"",
			"fait utiliser Pilum en mode debug"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionTailleDeLaPile ()
	{
	return
		new OptionLigneDeCommande (
			"pp",		"pile",		kObligatoire,			"unEntierPositif",
			"taille de la pile d'execution de Pilum\n"
			"\t\t// par defaut, 2000"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: OptionsGroupeesLexique ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"groupees",						kAucun,			"",
			"options groupees ('-ms -mt' d'un coup)"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionsGroupeesSyntaxe ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"groupees",						kAucun,			"",
			"options groupees ('-ms -mt' d'un coup)"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionsGroupeesSemantique ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"groupees",						kAucun,			"",
			"options groupees ('-ms' d'un coup)"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionsGroupeesSemantique_SYNTHESE_PILUM ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"groupees",						kAucun,			"",
			"options groupees ('-ms -oc -ob' d'un coup)"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionsGroupeesPilum ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"groupees",						kAucun,			"",
			"options groupees ('-pc -pt' d'un coup)"
			);
	}
OptionLigneDeCommandePTR
OptionsFR :: OptionsGroupeesFonctionsImbriquees ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"groupees",						kAucun,			"",
			"options groupees ('-oc -ob -pc -pd' d'un coup)"
			);
	}


// -------------------------------------------------------------------------
//	Options
// -------------------------------------------------------------------------

Chaine
OptionsFR :: FormatOptionInconnue ()
	{ return "l'option '%s' est inconnue\n%s"; }

Chaine
OptionsFR :: FormatOptionAUnArgumentObligatoire ()
	{ return "l'option '%s' a un argument obligatoire '%s'\n%s"; }

Chaine
OptionsFR :: FormatOptionCourteDejaEnregistree ()
	{ return "l'option courte '%s' a deja ete enregistree"; }
Chaine
OptionsFR :: FormatOptionLongueDejaEnregistree ()
	{ return "l'option longue '%s' a deja ete enregistree"; }


// -------------------------------------------------------------------------
//	Arguments des executables
// -------------------------------------------------------------------------

OptionLigneDeCommandePTR
OptionsFR :: ArgumentsCompilateurs ()
	{
	return
		new OptionLigneDeCommande (
			"",		"",					kOptionnel,			"fichierSourceLista",
			"// l'entree standard est lue si aucun nom de fichier n'est fourni"
			);
	}

OptionLigneDeCommandePTR
OptionsFR :: ArgumentsPilum ()
	{
	return
		new OptionLigneDeCommande (
			"",		"",		kObligatoire,			"fichierDeCodeBinairePilum",
			"// doit etre cree par ListaPredictifDescenteRecursive ou ListaFlexBison"
			);
	}


// -------------------------------------------------------------------------
//	Versions des executables
// -------------------------------------------------------------------------

OptionsEN :: OptionsEN ()
	{}


Chaine
OptionsEN :: VersionLexiqueP ()
	{
	return
		"\tLista lexical analysis\n"
		"\tPredictive version, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionLexiqueF ()
	{
	return
		"\tLista lexical analysis\n"
		"\tFlex based version, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionSyntaxePredictifDescenteRecursive ()
	{
	return
		"\tLista lexical/syntactic analysis\n"
		"\tPredictive/recursive descent version, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionSyntaxeFlexBison ()
	{
	return
		"\tLista lexical/syntactic analysis\n"
		"\tFlex/Bison based version, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionSemantiquePredictifDescenteRecursive ()
	{
	return
		"\tLista lexical/syntactic/semantic analysis,\n"
		"\t    translation and direct évaluation\n"
		"\tPredictive/recursive descent version, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionSemantiqueFlexBison ()
	{
	return
		"\tLista lexical/syntactic/semantic analysis,\n"
		"\t    translation and direct evaluation\n"
		"\tFlex/Bison based version, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionPredictifDescenteRecursive ()
	{
	return
		"\tLista lexical/syntactic/semantic analysis,\n"
		"\t    translation and direct evaluation,\n"
		"\t    with Pilum binary code generation\n"
		"\tPredictive/recursive descent version, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionFlexBison ()
	{
	return
		"\tLista lexical/syntactic/semantic analysis,\n"
		"\t    translation and direct evaluation\n"
		"\t    with Pilum binary code generation\n"
		"\tFlex/Bison based version, "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionPilum ()
	{
	return
		"\tPilum implementation, version "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}

Chaine
OptionsEN :: VersionFonctionsImbriquees ()
	{
	return
		"\tA program showing the implementation of 'à la Pascal' embedded functions,\n"
		"\t    with Pilum binary object code generation, version "NUMERO_DE_VERSION"\n"
		"\tJ. Menu - http://cui.unige.ch/DI/cours/CompInterpretes\n"; 
	}


// -------------------------------------------------------------------------
//	Options des executables
// -------------------------------------------------------------------------

OptionLigneDeCommandePTR
OptionsEN :: OptionLigneDeCommandeVide ()
	{ return new OptionLigneDeCommande (); }

OptionLigneDeCommandePTR
OptionsEN :: OptionAide ()
	{
	return
		new OptionLigneDeCommande (
			"h",		"help",							kAucun,			"",
			"displays this help"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionVersion ()
	{
	return
		new OptionLigneDeCommande (
			"v",		"version",						kAucun,			"",
			"displays this software's version"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionLangue ()
	{
	return
		new OptionLigneDeCommande (
			"l",		"language",						kObligatoire,	"fr | en",
			"choice of builtin identifiers' language"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionModeVerbeux ()
	{
	return
		new OptionLigneDeCommande (
			"w",		"verbose",						kAucun,			"",
			"verbose mode producing a little more information"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionModeDebug ()
	{
	return
		new OptionLigneDeCommande (
			"da",		"debug-analyzers",		kAucun,			"",
			"forces the use of the lexcial analyzers synthesized by Flex and Bison in debug mode"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLeCodeSource ()
	{
	return
		new OptionLigneDeCommande (
			"ss",		"source",			kAucun,			"",
			"show the Lista source code"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLesTerminaux ()
	{
	return
		new OptionLigneDeCommande (
			"st",		"terminals",	kAucun,			"",
			"show the terminals"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionSortirALaPremiereErreurLexicale ()
	{
	return
		new OptionLigneDeCommande (
			"rlex",	"lexical-error",				kAucun,			"",
			"exit at first lexical error"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionSortirALaPremiereErreurSyntaxique ()
	{
	return
		new OptionLigneDeCommande (
			"rsynt",	"syntactical-error",				kAucun,			"",
			"exit at first syntactical error"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionSortirALaPremiereErreurSemantique ()
	{
	return
		new OptionLigneDeCommande (
			"rsem",	"semantic-error",				kAucun,			"",
			"exit at first semantic error"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLesDictionnaires ()
	{
	return
		new OptionLigneDeCommande (
			"sd",		"dictionnaires",	kAucun,			"",
			"show the dictionaries"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLeDictionnaireDesPredefinis ()
	{
	return
		new OptionLigneDeCommande (
			"sq",		"builtin",	kAucun,			"",
			"show the dictionary of builtin identifiers"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLesAppelsImbriques ()
	{
	return
		new OptionLigneDeCommande (
			"se",		"embedded",	kAucun,			"",
			"show the embedded funtion calls when using a Bison-synthesized analyzer"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLInferenceDeType ()
	{
	return
		new OptionLigneDeCommande (
			"si",		"inference",	kAucun,			"",
			"show type inference"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLesGraphesSemantiques ()
	{
	return
		new OptionLigneDeCommande (
			"sg",		"graphs",	kAucun,			"",
			"show the semantic graphs"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLeCodePostfixe ()
	{
	return
		new OptionLigneDeCommande (
			"sp",		"postfixed",	kAucun,			"",
			"show the postfixed code"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionLangueDestination ()
	{
	return
		new OptionLigneDeCommande (
			"tl",		"translation",	kObligatoire,	"fr | en",
			"choice of language in which to translate builtin identifiers"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionStrategieParValeur ()
	{
	return
		new OptionLigneDeCommande (
			"bv",		"by-value",	kAucun,			"",
			"'call by value' evaluation strategy"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionStrategieParNom ()
	{
	return
		new OptionLigneDeCommande (
			"bn",		"by-name",	kAucun,			"",
			"'call by name' evaluation strategy"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionStrategieParBesoin ()
	{
	return
		new OptionLigneDeCommande (
			"bl",		"by-need",	kAucun,			"",
			"'call by need' (lazy) evaluation strategy"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionEvaluationDirecteSansTrace ()
	{
	return
		new OptionLigneDeCommande (
			"nt",		"without-trace",	kAucun,			"",
			"évaluation directe sans trace"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionEvaluationDirecteAvecTrace ()
	{
	return
		new OptionLigneDeCommande (
			"wt",		"with-trace",	kAucun,			"",
			"évaluation directe avec trace"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionCourtCircuitLogiquesBinaires ()
	{
	return
		new OptionLigneDeCommande (
			"sc",		"short-cut",	kAucun,			"",
			"use short-cut semantics for binary logical operators"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionModeDebugSynthese ()
	{
	return
		new OptionLigneDeCommande (
			"ds",		"debug-synthesis",		kAucun,			"",
			"display the Pilum synthesized code in debug mode"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionCommenterLeCode ()
	{
	return
		new OptionLigneDeCommande (
			"oc",		"comment",		kAucun,			"",
			"adds comments detailing Pilum instructions' rôle"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionMarquerLesBlocsDActivation ()
	{
	return
		new OptionLigneDeCommande (
			"ob",		"blocs",		kAucun,			"",
			"has a visual mark separating activation records pushed on the stack"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionOptimiserLesSauts ()
	{
	return
		new OptionLigneDeCommande (
			"os",		"sauts",		kAucun,			"",
			"causes jumps to jumps to be optimized"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLeCodeParLeSynthetiseur ()
	{
	return
		new OptionLigneDeCommande (
			"sc",		"synthesizer",	kAucun,			"",
			"shows the code generated by the synthetizer, with the logical variables"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionMontrerLeCodeParPilum ()
	{
	return
		new OptionLigneDeCommande (
			"pc",		"Pilum",		kAucun,			"",
			"has the contents of memory code displayed by Pilum before it is executed"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionModeTracePilum ()
	{
	return
		new OptionLigneDeCommande (
			"pt",		"trace",		kAucun,			"",
			"has Pilum used in step-by-step mode"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionModeDebugPilum ()
	{
	return
		new OptionLigneDeCommande (
			"pd",		"debug-pilum",		kAucun,			"",
			"has Pilum used in debug mode"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionTailleDeLaPile ()
	{
	return
		new OptionLigneDeCommande (
			"pp",		"stack",		kObligatoire,			"aPositiveInteger",
			"Pilums's runtime stack size\n"
			"\t\t// by default, 2000"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: OptionsGroupeesLexique ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"grouped",						kAucun,			"",
			"grouped options ('-ms -mt' as a whole)"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionsGroupeesSyntaxe ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"grouped",						kAucun,			"",
			"grouped options ('-ms -mt' as a whole)"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionsGroupeesSemantique ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"grouped",						kAucun,			"",
			"grouped options ('-ms' as a whole)"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionsGroupeesSemantique_SYNTHESE_PILUM ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"grouped",						kAucun,			"",
			"grouped options ('-ms -oc -ob' as a whole)"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionsGroupeesPilum ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"grouped",						kAucun,			"",
			"grouped options ('-pc -pt' as a whole)"
			);
	}
OptionLigneDeCommandePTR
OptionsEN :: OptionsGroupeesFonctionsImbriquees ()
	{
	return
		new OptionLigneDeCommande (
			"g",		"grouped",						kAucun,			"",
			"grouped options ('-oc -ob -pc -pd' as a whole)"
			);
	}


// -------------------------------------------------------------------------
//	Options
// -------------------------------------------------------------------------

Chaine
OptionsEN :: FormatOptionInconnue ()
	{ return "option `%s' is unknown\n%s"; }

Chaine
OptionsEN :: FormatOptionAUnArgumentObligatoire ()
	{ return "option '%s' has a mandatory argument '%s'\n%s"; }

Chaine
OptionsEN :: FormatOptionCourteDejaEnregistree ()
	{ return "short option '%s' has already been registered"; }
Chaine
OptionsEN :: FormatOptionLongueDejaEnregistree ()
	{ return "long option '%s' has already been registered"; }


// -------------------------------------------------------------------------
//	Arguments des executables
// -------------------------------------------------------------------------

OptionLigneDeCommandePTR
OptionsEN :: ArgumentsCompilateurs ()
	{
	return
		new OptionLigneDeCommande (
			"",		"",					kOptionnel,			"ListaSourceFile",
			"// stdin is read if no file name is supplied"
			);
	}

OptionLigneDeCommandePTR
OptionsEN :: ArgumentsPilum ()
	{
	return
		new OptionLigneDeCommande (
			"",		"",					kObligatoire,			"PilumObjectCodeFile",
			"// should be created by either ListaPredictifDescenteRecursive or ListaFlexBison"
			);
	}


// -------------------------------------------------------------------------
//	BaseAssocInstanceMethodeOptions
// -------------------------------------------------------------------------

BaseAssocInstanceMethodeOptions :: BaseAssocInstanceMethodeOptions (
	OptionLigneDeCommandeOptionsPFM leOptionLigneDeCommandeOptionsPFM )
	{
	fOptionLigneDeCommandeOptionsPFM =
		leOptionLigneDeCommandeOptionsPFM;
	}


BaseAssocInstanceMethodeOptions :: ~ BaseAssocInstanceMethodeOptions ()
	{}

OptionLigneDeCommandeOptionsPFM
BaseAssocInstanceMethodeOptions :: LeOptionLigneDeCommandeOptionsPFM ()
	{ return fOptionLigneDeCommandeOptionsPFM; }


// -------------------------------------------------------------------------
//	DecodageDOptions
// -------------------------------------------------------------------------

DecodageDOptions :: DecodageDOptions (
	int			leNbDArguments,
	CharPTR	lesArguments [],
	ChaineOptionsPFM
					laFonctionVersion )
	{
	fNbDArguments = leNbDArguments;
	fLesArguments = lesArguments;
	fFonctionVersion = laFonctionVersion;	
	
	fTableauDeBaseAssocInstanceMethodeOptions =
		NULL;
	}	// DecodageDOptions :: DecodageDOptions


DecodageDOptions :: ~ DecodageDOptions ()
	{}


// -------------------------------------------------------------------------

void
DecodageDOptions :: Initialiser ()
	{
	sAssocDecodageDOptions =
		new AssocDecodageDOptions (
			& Options :: OptionLigneDeCommandeVide,
			NULL,
			& DecodageDOptions :: OptionVide );

	if (fTableauDeBaseAssocInstanceMethodeOptions != NULL)
		delete fTableauDeBaseAssocInstanceMethodeOptions;

	fTableauDeBaseAssocInstanceMethodeOptions =
		new TableauDeBaseAssocInstanceMethodeOptions;

	EnregistrerLAssociation (
		new AssocDecodageDOptions (
			& Options :: OptionAide,
			this,
			& DecodageDOptions :: Aide ));

	EnregistrerLAssociation (
		new AssocDecodageDOptions (
			& Options :: OptionVersion,
			this,
			& DecodageDOptions :: Version ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	EnregistrerLAssociation (
		new AssocDecodageDOptions (
			& Options :: OptionLangue,
			this,
			& DecodageDOptions :: Langue ));

	EnregistrerLAssociation (sAssocDecodageDOptions);

	}	// DecodageDOptions :: Initialiser


// -------------------------------------------------------------------------

void
DecodageDOptions :: EnregistrerLAssociation (
	BaseAssocInstanceMethodeOptionsPTR leFunctor )
	{
	OptionLigneDeCommandeOptionsPFM
				leOptionLigneDeCommandeOptionsPFMAEnregistrer =
					leFunctor -> LeOptionLigneDeCommandeOptionsPFM ();
	
	Chaine	nomCourtAEnregistrer =
					(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFMAEnregistrer) () ->
						NomCourt ();
	Chaine	nomLongAEnregistrer	=
					(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFMAEnregistrer) () ->
						NomLong ();

	if (
		! nomCourtAEnregistrer.empty ()
			||
		! nomLongAEnregistrer.empty ()
		)
		{
		TableauDeBaseAssocInstanceMethodeOptions :: iterator
					i;
		
		for (
			i = fTableauDeBaseAssocInstanceMethodeOptions -> begin ();
			i != fTableauDeBaseAssocInstanceMethodeOptions -> end ();
			++ i )
			{
			OptionLigneDeCommandeOptionsPFM
						leOptionLigneDeCommandeOptionsPFMTrouve =
							(* i) -> LeOptionLigneDeCommandeOptionsPFM ();
			
			Chaine	nomCourtTrouve =
							(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFMTrouve) () ->
								NomCourt ();
			Chaine	nomLongTrouve	=
							(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFMTrouve) () ->
								NomLong ();

			if (
				nomCourtAEnregistrer == nomCourtTrouve
					||
				nomCourtAEnregistrer == nomLongTrouve
				)
				{
				std::cout <<
					Usage () <<
					std::endl;
				SortieSurErreur (
					MiseEnForme (
						gOPTIONS ->
							FormatOptionCourteDejaEnregistree (),
						nomCourtAEnregistrer ),
						17 );
				}

			if (
				nomLongAEnregistrer == nomCourtTrouve
					||
				nomLongAEnregistrer == nomLongTrouve
				)
				{
				std::cout <<
					Usage () <<
					std::endl;
				SortieSurErreur (
					MiseEnForme (
						gOPTIONS ->
							FormatOptionLongueDejaEnregistree (),
						nomLongAEnregistrer ),
						17 );
				}
			}	// for
		}	// if

	fTableauDeBaseAssocInstanceMethodeOptions -> 
		push_back (leFunctor);
	}	// DecodageDOptions :: EnregistrerLAssociation


// -------------------------------------------------------------------------

Chaine
DecodageDOptions :: DecodageDOptions :: Usage ()
	{
	Chaine	res =
					MiseEnForme (
						gLANGUE ->
							EnteteDUsage (),
						fLesArguments [0] );

	TableauDeBaseAssocInstanceMethodeOptions :: iterator
				i;
	
	for (
		i = fTableauDeBaseAssocInstanceMethodeOptions -> begin ();
		i != fTableauDeBaseAssocInstanceMethodeOptions -> end ();
		++ i )
		{
		Chaine	descrArgument;

		OptionLigneDeCommandeOptionsPFM
					leOptionLigneDeCommandeOptionsPFM =
						(* i) -> LeOptionLigneDeCommandeOptionsPFM ();

		if (leOptionLigneDeCommandeOptionsPFM == NULL)
			SortieSurErreur (
				"DecodageDOptions :: Usage (): "
				"leOptionLigneDeCommandeOptionsPFM == NULL",
				77 );
			
		switch (
			(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> 
				LeGenreDArgumentEventuel ()
			)
			{
			case kAucun:
				 descrArgument= "";

			case kObligatoire:
				descrArgument =
					(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () ->
						DescrArgumentEventuel ();
				break;

			case kOptionnel:
				descrArgument =
					MiseEnForme (
						"[%s]",
						(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> 
							DescrArgumentEventuel ());
				break;
			}	// switch

		if ((* i) == sAssocDecodageDOptions)
			res = FConcatChaines (res, "\n");

		else if (
			(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) ()
				-> NomCourt ().empty ()
				&&
			(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) ()
				-> NomLong () .empty ()
			)
			// les arguments de l'executabble
			{
			res =
				FConcatChaines (
					res,
					MiseEnForme (
						"\t%s\n\t\t%s\n",
						descrArgument,
						(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () ->
							Commentaire ()
						));
			}

		else
			{
			Chaine	format = "\t-%s, --%s %s\n\t\t%s\n";

			res =
				FConcatChaines (
					res,
					MiseEnForme (
						format,
						(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () ->
							NomCourt (),
						(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) ()
							-> NomLong (),
						descrArgument,
						(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) ()
							-> Commentaire ()
						));
			}

//	JMI	std::cout << "==> res  = " << res << std::endl << std::flush;
		}	// for

	return res;
	}	// DecodageDOptions :: Usage


// -------------------------------------------------------------------------

int
DecodageDOptions :: DecortiquerLesOptions ()
	{
	//	retourne le numero du premier argument suivant les options
		
	int		numArgumentCourant		= 1;
	bool		argumentNonOptionTrouve	= false;
	
	while (numArgumentCourant < fNbDArguments)
		{
		DecortiquerLOption (numArgumentCourant, argumentNonOptionTrouve);

		if (argumentNonOptionTrouve)
			return numArgumentCourant;

		numArgumentCourant ++;
		}	// while
	
	return numArgumentCourant;

	}	//	DecortiquerLesOptions


// -------------------------------------------------------------------------

void
DecodageDOptions :: DecortiquerLOption (
	int	& leNumArgumentCourant,
	bool	& lArgumentNonOptionTrouve )
	{		
	Chaine	argumentCourant =
					fLesArguments [leNumArgumentCourant];
	GenreDOption
				leGenreDOption = LeGenreDOption (argumentCourant);
	Chaine	chaineAComparer;

	switch (leGenreDOption)
		{
		case kPasUneOption:
			lArgumentNonOptionTrouve = true;
			return;	// leNumArgumentCourant contient l'information adequate
			break;

		case kOptionCourte:
			chaineAComparer =
				argumentCourant.substr (1);	// on ignore "-"
			break;

		case kOptionLongue:
			chaineAComparer =
				argumentCourant.substr (2);	// on ignore "--"
			break;
		}	// switch

//		std::cout << "==> leGenreDOption  = " << leGenreDOption << std::endl << std::flush;
//		std::cout << "==> chaineAComparer  = " << chaineAComparer << std::endl << std::flush;

	bool		optionReconnue = false;
		
	TableauDeBaseAssocInstanceMethodeOptions :: iterator
				i;
	
	for (
		i = fTableauDeBaseAssocInstanceMethodeOptions -> begin ();
		i != fTableauDeBaseAssocInstanceMethodeOptions -> end ();
		++ i )
		{
		OptionLigneDeCommandeOptionsPFM
					leOptionLigneDeCommandeOptionsPFM =
						(* i) -> LeOptionLigneDeCommandeOptionsPFM ();

		switch (leGenreDOption)
			{
			case kPasUneOption:
				// ne se produira pas
				break;

			case kOptionCourte:					
//		JMI			std::cout << "==> (gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomCourt ()  = " << (gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomCourt () << std::endl << std::flush;
				optionReconnue =
					chaineAComparer
						==
					((gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) ()) -> NomCourt ();
				break;

			case kOptionLongue:
//					std::cout << "==> (gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomLong ()  = " << (gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomLong () << std::endl << std::flush;
				optionReconnue =
					chaineAComparer
						==
					(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomLong ();
				break;
			}	// switch

//			std::cout << "==> optionReconnue  = " << optionReconnue << std::endl << std::flush;

		if (optionReconnue)
			{
			Chaine	lArgumentDeLOption	= "";
			
			switch (
				(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () ->
					LeGenreDArgumentEventuel ()
				)
				{
				case kAucun:
					break;

				case kOptionnel:
					{
					if (leNumArgumentCourant < fNbDArguments - 1)
						{
						//	on a un argument pour cette option
						leNumArgumentCourant ++;
						lArgumentDeLOption = fLesArguments [leNumArgumentCourant];
//							std::cout << 
//								"==> argument optionnel d'option reconnu " 
//								<< lArgumentDeLOption << std::endl << std::flush;
						}	// if
					}
					break;

				case kObligatoire:
					{
					if (leNumArgumentCourant < fNbDArguments - 1)
						{
						//	on a un argument pour cette option
						leNumArgumentCourant ++;
						lArgumentDeLOption = fLesArguments [leNumArgumentCourant];
//							std::cout << "==> argument obligatoire d'option reconnu " << lArgumentDeLOption << std::endl << std::flush;
						}
					else
						SortieSurErreur (
							MiseEnForme (
								gOPTIONS ->
									FormatOptionAUnArgumentObligatoire (),
								argumentCourant,
								(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) ()
									-> DescrArgumentEventuel (),
								Usage () ),
							77 );
					}
					break;
				}	// switch

			(* i) -> Declencher (lArgumentDeLOption);
				// la valeur produite est ignoree

			switch (leGenreDOption)
				{
				case kPasUneOption:
					break;

				case kOptionCourte:
/*
					std::cout <<
						MiseEnForme (
							"==> option courte reconnue: -%s, --%s) %s",
							(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomCourt (),
							(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomLong (),
							lArgumentDeLOption ) <<
						std::endl << std::flush;
*/
					break;

				case kOptionLongue:
/*
					std::cout <<
						MiseEnForme (
							"==> option longue reconnue: -%s, --%s) %s",
							(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomCourt (),
							(gOPTIONS ->* leOptionLigneDeCommandeOptionsPFM) () -> NomLong (),
							lArgumentDeLOption ) <<
						std::endl << std::flush;
*/
					break;
				}	// switch

			break;
			}	// if
		}	// for

	if (! optionReconnue)
		SortieSurErreur (
			MiseEnForme (
				gOPTIONS ->
					FormatOptionInconnue (),
				argumentCourant,
				Usage () ),
			77 );

	}	// DecodageDOptions :: DecortiquerLOption


// -------------------------------------------------------------------------

void
DecodageDOptions :: OptionVide (Chaine argument)
	{}

void
DecodageDOptions :: Version (Chaine argument)
	{
	std::cout <<
		std::endl <<
		(gOPTIONS ->* fFonctionVersion) () <<
		std::endl;
	exit (0);
	}

void
DecodageDOptions :: Aide (Chaine argument)
	{
//	Version (argument);
	std::cout <<
		Usage () <<
		std::endl;

	exit (0);
	}

void
DecodageDOptions :: Langue (Chaine argument)
	{
	Langue :: ChoisirLaLangueSource (argument, true);
	
	InitialiserLanguesSupportCPlusPlus (argument);
	}


// -------------------------------------------------------------------------

AssocDecodageDOptionsPTR
DecodageDOptions :: sAssocDecodageDOptions = NULL;


// -------------------------------------------------------------------------
//	GenreDOption
// -------------------------------------------------------------------------

GenreDOption 
LeGenreDOption (Chaine laChaine)
	{
	int		longueurChaine	= laChaine.length ();
		
	if (
		longueurChaine > 2
			&&
		laChaine [0] == '-'
			&&
		laChaine [1] == '-'
		)
		return kOptionLongue;
	else if (
		longueurChaine > 1
			&&
		laChaine [0] == '-'
		)
		return kOptionCourte;
	else
		return kPasUneOption;
	}	//	LeGenreDOption


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

OptionsPTR						gOPTIONS = NULL;

OptionsFR						gOPTIONS_FR;
OptionsEN						gOPTIONS_EN;
