// =========================================================================
//	TerminauxFlesBisonLista.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$
// =========================================================================

#include "TerminauxFlesBisonLista.h"

#include "SupportCPlusPlus.h"

#include "Langues.h"

#include "LanguesSyntaxe.h"
#include "LanguesSemantique.h"

#include <iostream>


// -------------------------------------------------------------------------
//	Externes synthetises par Flex
// -------------------------------------------------------------------------

extern char							yytext [];	//	pour "ErreurSemantique ()"


// -------------------------------------------------------------------------
//	Fonctions et variables globales definies dans la grammaire *.Flex
// -------------------------------------------------------------------------

extern void							CompterFinDeLigne ();

extern Chaine						DescriptionPositionCourante ();
extern Chaine						DescriptionTerminalCourant ();


// -------------------------------------------------------------------------
// L'analyseur Lista */
// -------------------------------------------------------------------------

extern AnalyseurListaFlexBisonPTR		gAnalyseurListaFlexBison;


// -------------------------------------------------------------------------
//	DescrParametrePredef
// -------------------------------------------------------------------------

DescrParametrePredef :: DescrParametrePredef (
	int							leNumeroDeParametre )
	:	DescrParametre (leNumeroDeParametre, gStrategieParValeur)
	{}

AssocArgumentParametrePTR
DescrParametrePredef :: CommentEvaluer (
	long							leNumeroContexte,
	DescrSemantiquePTR		laValeur,
	ContexteDEvaluationPTR	leContexteDEvaluation )
	{
	SortieSurErreur (
		"DescrParametrePredef :: CommentEvaluer ()",
		15 );
	return NULL;	// superflu
	}
	
int
DescrParametrePredef :: TailleEnMemoire ()
	{
	SortieSurErreur (
		"DescrParametrePredef :: TailleEnMemoire ()",
		16 );
	return 0;	// superflu
	}


#if defined SYNTHESE_PILUM

void
DescrParametrePredef :: Synthetiser (
	ContexteDeSynthesePTR	leContexteDeSynthese,
	DescrSemantiquePTR		lArgumentDAppel )
	{
	SortieSurErreur (
		"DescrParametrePredef :: Synthetiser ()",
		17);
	}

#endif /* SYNTHESE_PILUM */

// -------------------------------------------------------------------------
//	DescrAppelFonction
// -------------------------------------------------------------------------

DescrAppelFonction :: DescrAppelFonction (
	Chaine	leNom,
	int		leNombreDeParametres )
	{
	fNom = leNom;
	fNombreDeParametres = leNombreDeParametres;

	fBlocDArguments =	//	on les initialise a "gDescrSemantiqueInconnue"
		new DescrSemantiquePTR [fNombreDeParametres];
	
	for (int i = 0; i < fNombreDeParametres; i ++)
		fBlocDArguments [i] = gDescrSemantiqueInconnue;

	fNumeroDArgument = 0;

	fEnCoursDeRattrapage = false;
	}	//	DescrAppelFonction :: DescrAppelFonction

DescrAppelFonction :: ~ DescrAppelFonction ()
	{}


Chaine
DescrAppelFonction :: Nom ()
	{ return fNom; }

int
DescrAppelFonction :: NombreDeParametres ()
	{ return fNombreDeParametres; }


// -------------------------------------------------------------------------
//	DescrAppelFonctionPredefinie
// -------------------------------------------------------------------------

DescrAppelFonctionPredefinie :: DescrAppelFonctionPredefinie (
	FonctionPredefiniePTR laFonctionPredefinie )
	: DescrAppelFonction (
		laFonctionPredefinie -> Nom (),
		laFonctionPredefinie -> NombreDeParametres ()
		)
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatCreationDescrAppelDeFonctionPredefinie (),
				laFonctionPredefinie -> Nom (),
				laFonctionPredefinie -> NombreDeParametres () ) <<
			std::endl;

	fFonctionPredefinie = laFonctionPredefinie;
	}

DescrAppelFonctionPredefinie :: ~ DescrAppelFonctionPredefinie ()
	{}


FonctionPredefiniePTR
DescrAppelFonctionPredefinie :: FonctionPredefinie ()
	{ return fFonctionPredefinie; }


void
DescrAppelFonctionPredefinie :: EnregistrerArgument (
	DescrSemantiquePTR lArgument )
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatEnregistrementArgumentDeFonctionPredefinie (),
				fNumeroDArgument,
				fFonctionPredefinie -> Nom () ) <<
			std::endl;
	
	if (! fEnCoursDeRattrapage)
		{
		VariableLogiqueTypePTR
					laVariableLogiqueType = fFonctionPredefinie ->
						TypesLogiquesDesParametres () [fNumeroDArgument];

		fBlocDArguments [fNumeroDArgument ++] = lArgument;
	
		if (laVariableLogiqueType != gTypeLogiqueNonPrecise)
			gAnalyseurSemantiqueLista ->
				TesterLeTypeAttendu (
					laVariableLogiqueType -> ValeurDeLiaison (),
					lArgument -> TypeLogique (),
					gLANGUE_Semantique -> 
						ArgumentDAppel () );
		//	Pour "Si", le controle sera fait dans CreerGrapheSemantique ()

		}	//	if
	}	//	DescrAppelFonctionPredefinie :: EnregistrerArgument


void
DescrAppelFonctionPredefinie :: VerifierSiPasTropDArguments ()
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatVerifierSiPasTropDArgumentsPourFonctionPredefinie (),
				fNumeroDArgument,
				fFonctionPredefinie -> Nom ()) <<
			std::endl;
	
	if (fNumeroDArgument >= fNombreDeParametres)
		{
		gAnalyseurSemantiqueLista ->
			ErreurSemantique (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatTropDArgumentsDansAppelAPredefinie (),
					fFonctionPredefinie -> Nom () ));

		DebutRattrappage ();
		}	//	if
	}	//	DescrAppelFonctionPredefinie :: VerifierSiPasTropDArguments


void
DescrAppelFonctionPredefinie :: VerifierSiAssezDArguments ()
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatVerifierSiAssezDArgumentsPourFonctionPredefinie (),
				fNumeroDArgument,
				fFonctionPredefinie -> Nom () ) <<
			std::endl;

	Chaine	leNomDeLaFonction =
					fFonctionPredefinie -> Nom ();
	
	if (
		fNumeroDArgument < fNombreDeParametres
			&&
		! fEnCoursDeRattrapage
		)
		gAnalyseurSemantiqueLista ->
			ErreurSemantique (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatTropPeuDArgumentsDansAppelAPredefinie (),
					leNomDeLaFonction ));

	while (fNumeroDArgument < fNombreDeParametres)
		//	on complte le bloc d'arguments tout de mme!
		fBlocDArguments [fNumeroDArgument ++] = gDescrSemantiqueInconnue;

	}	//	DescrAppelFonctionPredefinie :: VerifierSiAssezDArguments


void
DescrAppelFonctionPredefinie :: DebutRattrappage ()
	{ 	fEnCoursDeRattrapage = true; }


DescrSemantiquePTR
DescrAppelFonctionPredefinie :: CreerGrapheSemantique ()
	{
	return
		fFonctionPredefinie ->
			CreerGrapheDAppelALaFonction (
				kLectureSansAutre, fBlocDArguments );
	}	//	DescrAppelFonctionPredefinie :: CreerGrapheSemantique


// -------------------------------------------------------------------------
//	DescrAppelIteration
// -------------------------------------------------------------------------

DescrAppelIteration :: DescrAppelIteration (
	FonctionPredefiniePTR 	laFonctionPredefinie )
	: DescrAppelFonctionPredefinie (laFonctionPredefinie)
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatCreationDescrAppelIteration (),
				laFonctionPredefinie -> Nom () ) <<
			std::endl;

	fIndice = NULL;
	}	// DescrAppelIteration :: DescrAppelIteration

DescrAppelIteration :: ~ DescrAppelIteration ()
	{}


IndiceIterationPTR
DescrAppelIteration :: EnregistrerIndice (
	IndiceIterationPTR lIndice )
	{
	fIndice = lIndice;
	return NULL;	// superflu
	}


void
DescrAppelIteration :: EnregistrerBorneInf (
	DescrSemantiquePTR laBorneInf )
	{
	gAnalyseurSemantiqueLista ->
		TesterLeTypeAttendu (
			gTypeNombre,
			laBorneInf -> TypeLogique (),
			gLANGUE_Semantique ->
				BorneInferieure () );
	fBlocDArguments [0] = laBorneInf;
	}


void
DescrAppelIteration :: EnregistrerBorneSup (
	DescrSemantiquePTR laBorneSup )
	{
	gAnalyseurSemantiqueLista ->
		TesterLeTypeAttendu (
			gTypeNombre,
			laBorneSup -> TypeLogique (),
			gLANGUE_Semantique ->
				BorneSuperieure () );
	fBlocDArguments [1] = laBorneSup;
	}


void
DescrAppelIteration :: EnregistrerExprIteree (
	DescrSemantiquePTR lExpression )
	{
	IterateurPredefPTR (fFonctionPredefinie) ->
		TesterTypeExpressionIteree (lExpression -> TypeLogique ());

	fBlocDArguments [2] = lExpression;
	}	//	DescrAppelIteration :: EnregistrerExprIteree


DescrSemantiquePTR
DescrAppelIteration :: CreerGrapheSemantique ()
	{
	return
		IterateurPredefPTR (fFonctionPredefinie) ->
			CreerGrapheIteration (fIndice, fBlocDArguments);
	}	//	DescrAppelIteration :: CreerGrapheSemantique


// -------------------------------------------------------------------------
//	DescrAppelFonctionUtilisateur
// -------------------------------------------------------------------------

DescrAppelFonctionUtilisateur :: DescrAppelFonctionUtilisateur (
	FonctionUtilisateurPTR laFonctionUtilisateur )
	: DescrAppelFonction (
		laFonctionUtilisateur -> Nom (),
		laFonctionUtilisateur -> 
			LaListeDeParametresFormels () -> NombreDeParametres () )
	{
	fFonctionUtilisateur = laFonctionUtilisateur; 

	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatCreationDescrAppelFonctionUtilisateur (),
				fFonctionUtilisateur -> Nom () ) <<
			std::endl;

	ListeDeParametresFormelsPTR
				laListeDeParametresFormels =
					fFonctionUtilisateur -> LaListeDeParametresFormels ();

	fListeDesDescrParametres =
		laListeDeParametresFormels -> LaListeDesDescrParametres ();
	fParametreCourant =
		fListeDesDescrParametres -> begin ();

	fEnCoursDeRattrapage =
		laListeDeParametresFormels
			==
		gAnalyseurSemantiqueLista -> ListeDeParametresFormelsInconnus ();
	}

DescrAppelFonctionUtilisateur :: ~ DescrAppelFonctionUtilisateur ()
	{}


FonctionUtilisateurPTR
DescrAppelFonctionUtilisateur :: LaFonctionUtilisateur ()
	{ return fFonctionUtilisateur; }


void
DescrAppelFonctionUtilisateur :: EnregistrerArgument (
	DescrSemantiquePTR lArgument )
	{
	if (! fEnCoursDeRattrapage)
		{
		fBlocDArguments [fNumeroDArgument ++] = lArgument;
	
		ParametreFormelPTR
					leParametreFormel =
						(* fParametreCourant) -> ParametreFormel ();
	
		VariableLogiqueTypePTR
					laVariableLogiqueType =
						leParametreFormel -> VariableLogiqueType ();
	
		gAnalyseurSemantiqueLista ->
			TesterLeTypeAttendu (
				laVariableLogiqueType -> ValeurDeLiaison (),
				lArgument -> TypeLogique (),
				gLANGUE_Semantique ->
					ArgumentDAppel () );
		}	//	if
	
	if (! fEnCoursDeRattrapage)
		fParametreCourant ++;
		//	sinon, on reste sur l'inconnu
	}	//	DescrAppelFonctionUtilisateur :: EnregistrerArgument


void
DescrAppelFonctionUtilisateur :: VerifierSiPasTropDArguments ()
	{
	Chaine	nomDeLaFonction	= fFonctionUtilisateur -> Nom ();
	
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatVerifierSiPasTropDArgumentsPourFonctionUtilisateur (),
				fNumeroDArgument,
				nomDeLaFonction ) <<
			std::endl;

	ListeDeParametresFormelsPTR
				laListeDeParametresFormels =
					fFonctionUtilisateur -> LaListeDeParametresFormels ();

	if (
		fParametreCourant
			==
		laListeDeParametresFormels -> LaListeDesDescrParametres () -> end ()
		)
		{
		gAnalyseurSemantiqueLista ->
			ErreurSemantique (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatTropDArgumentsDansAppelAFonctionParametree (),
					nomDeLaFonction ));

		//	on rattrape l'erreur en se raccordant sur
		//	la liste circulaire de parametres inconnus

		DebutRattrappage ();
		}	//	if
	}	//	DescrAppelFonctionUtilisateur :: VerifierSiPasTropDArguments

void
DescrAppelFonctionUtilisateur :: VerifierSiAssezDArguments ()
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatVerifierSiAssezDArgumentsPourFonctionUtilisateur (),
				fNumeroDArgument,
				fFonctionUtilisateur -> Nom () ) <<
			std::endl;

	ListeDeParametresFormelsPTR
				laListeDeParametresFormels =
					fFonctionUtilisateur -> LaListeDeParametresFormels ();
	int		nombreDeParametres =
					laListeDeParametresFormels -> NombreDeParametres ();

	if (
		! fEnCoursDeRattrapage
			&&
		nombreDeParametres > 0
			&&
		(
		(* fParametreCourant)
			==
		laListeDeParametresFormels -> 
			LaListeDesDescrParametres () -> at (nombreDeParametres - 1)
		)
		)
		gAnalyseurSemantiqueLista ->
			ErreurSemantique (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatTropPeuDArgumentsDansAppelAFonctionParametree (),
					fFonctionUtilisateur -> Nom (),
					fFonctionUtilisateur ->
						LaListeDeParametresFormels () ->
							NomsDesParametres () ));

	while (fNumeroDArgument < fNombreDeParametres)
		//	on complte le bloc d'arguments tout de mme!
		fBlocDArguments [fNumeroDArgument ++] =
			gDescrSemantiqueInconnue;

	}	//	DescrAppelFonctionUtilisateur :: VerifierSiAssezDArguments


void
DescrAppelFonctionUtilisateur :: DebutRattrappage ()
	{
	fListeDesDescrParametres =
		gAnalyseurSemantiqueLista -> 
			ListeDeParametresFormelsInconnus () ->
				LaListeDesDescrParametres ();
	fParametreCourant =
		fListeDesDescrParametres -> begin ();			

	fEnCoursDeRattrapage = true;
	}


DescrSemantiquePTR
DescrAppelFonctionUtilisateur :: CreerGrapheSemantique ()
	{
	return
		new AppelDeFonctionUtilisateur (
			fFonctionUtilisateur, fBlocDArguments );
	}


// -------------------------------------------------------------------------
//	DescrAppelFonctionErronee
// -------------------------------------------------------------------------

DescrAppelFonctionErronee :: DescrAppelFonctionErronee (
	IdentificateurPTR lIdentificateur )
	: DescrAppelFonction (lIdentificateur -> Nom (), 1)
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatCreationDescrAppelFonctionErronee (),
				lIdentificateur -> Nom () ) <<
			std::endl;

	fIdentificateur = lIdentificateur;
	}

DescrAppelFonctionErronee :: ~ DescrAppelFonctionErronee ()
	{}


void
DescrAppelFonctionErronee :: EnregistrerArgument (
	DescrSemantiquePTR lArgument )
	{}


void
DescrAppelFonctionErronee :: VerifierSiPasTropDArguments ()
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			"DescrAppelFonctionErronee :: VerifierSiPasTropDArguments" <<
			std::endl;
	}

void
DescrAppelFonctionErronee :: VerifierSiAssezDArguments ()
	{
	if (gAnalyseurListaFlexBison -> ModeDebug ())
		std::cout <<
			"DescrAppelFonctionErronee :: VerifierSiAssezDArguments" <<
			std::endl;
	}

void
DescrAppelFonctionErronee :: DebutRattrappage ()
	{}

DescrSemantiquePTR
DescrAppelFonctionErronee :: CreerGrapheSemantique ()
	{
	return
		new ValeurInconnue (fIdentificateur -> VariableLogiqueType ());
		//	pour permettre l'inference du type
		//	de cet identificateur non declare
	}


// -------------------------------------------------------------------------
//	PileDesAppels
// -------------------------------------------------------------------------

PileDesAppels :: PileDesAppels ()
	{
	fPileDesDescrAppelFonction = new PileDesDescrAppelFonction;
	}

PileDesAppels :: ~ PileDesAppels ()
	{}

void
PileDesAppels :: Empiler (DescrAppelFonctionPTR leDescrAppelFonction)
	{
	if (gAnalyseurListaFlexBison -> OptionsFlexBison () -> MontrerLesAppelsImbriques ())
		std::cout << 
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatEmpilageDescrAppelDeFonction (),
				leDescrAppelFonction -> Nom () ) <<
			std::endl;

	fPileDesDescrAppelFonction -> push_front (leDescrAppelFonction);
	}

DescrAppelFonctionPTR
PileDesAppels :: Sommet ()
	{ return fPileDesDescrAppelFonction -> front (); }

DescrAppelFonctionPTR
PileDesAppels :: Desempiler ()
	{
	DescrAppelFonctionPTR
				res = fPileDesDescrAppelFonction -> front ();
	
	if (gAnalyseurListaFlexBison -> OptionsFlexBison () -> MontrerLesAppelsImbriques ())
		std::cout << 
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatDesempilageDescrAppelDeFonction (),
				res -> Nom () ) <<
			std::endl;

	fPileDesDescrAppelFonction -> pop_front ();
	
	return res;
	}


// -------------------------------------------------------------------------
//	OptionsFlexBison
// -------------------------------------------------------------------------

OptionsFlexBison :: OptionsFlexBison (
	bool		modeVerbeux,
	bool		leMontrerLesAppelsImbriques )
	{
	fModeVerbeux = modeVerbeux;
	
	fMontrerLesAppelsImbriques = leMontrerLesAppelsImbriques;
	}

bool
OptionsFlexBison :: ModeVerbeux ()
	{ return fModeVerbeux; }

bool
OptionsFlexBison :: MontrerLesAppelsImbriques ()
	{ return fMontrerLesAppelsImbriques; }


// -------------------------------------------------------------------------
//	AnalyseurListaFlexBison
// -------------------------------------------------------------------------

AnalyseurListaFlexBison :: AnalyseurListaFlexBison (
	bool								leModeDebug,
	bool								leMontrerLesTerminaux,
	OptionsStrategiePTR			lesOptionsStrategie,
	OptionsSemantiquePTR			lesOptionsSemantique,
	OptionsFlexBisonPTR					lesOptionsFlexBison,
	OptionsEvaluationPTR			lesOptionsEvaluation
#if defined SYNTHESE_PILUM
,	SynthetiseurPilumListaPTR	leSynthetiseurPilumLista
#endif /* SYNTHESE_PILUM */
	)
	: AnalyseurSemantiqueLista (
		lesOptionsStrategie,
		lesOptionsSemantique,
		lesOptionsEvaluation
#if defined SYNTHESE_PILUM
	,	leSynthetiseurPilumLista
#endif /* SYNTHESE_PILUM */
		)
	{
	fModeDebug = leModeDebug;
	fMontrerLesTerminaux = leMontrerLesTerminaux;
	fOptionsFlexBison = lesOptionsFlexBison;

	fPileDesAppels =
		new PileDesAppels ();

	}	//	AnalyseurListaFlexBison :: AnalyseurListaFlexBison

AnalyseurListaFlexBison :: ~ AnalyseurListaFlexBison ()
	{}


// -------------------------------------------------------------------------

Chaine
AnalyseurListaFlexBison :: DescriptionDuTerminalCourant ()
	{ return DescriptionTerminalCourant (); }

Chaine
AnalyseurListaFlexBison :: DescriptionDeLaPositionCourante ()
	{ return DescriptionPositionCourante ();}


// -------------------------------------------------------------------------

bool
AnalyseurListaFlexBison :: ModeDebug ()
	{ return fModeDebug; }

bool
AnalyseurListaFlexBison :: MontrerLesTerminaux ()
	{ return fMontrerLesTerminaux; }

OptionsFlexBisonPTR
AnalyseurListaFlexBison :: OptionsFlexBison ()
	{ return fOptionsFlexBison; }


// -------------------------------------------------------------------------

FonctionUtilisateurPTR
AnalyseurListaFlexBison :: IdentFonction ()
	{ return fIdentFonction; }


// -------------------------------------------------------------------------
//	Interaction entre Analyse Lexicale et Analyse Semantique
//	Necessaire pour les iterateurs predefinis et la traduction
// -------------------------------------------------------------------------

GenreIdentificateurFlexBison
AnalyseurListaFlexBison :: InteractionLexiqueSemantique (
	DescrIdentificateurFlexBison & laDescrIdentificateurFlexBison )
	{
	DictionnairePTR
				leDictionnaire;

	laDescrIdentificateurFlexBison.fIdentificateurPTR =
		fTableDesSymboles -> 
			RechercherLeNom (laDescrIdentificateurFlexBison.fNom, leDictionnaire, false);

	if (fOptionsSemantique -> Traduire ())
		{
		//	seuls les emplois d'identificateurs predefinis peuvent avoir une
		//	traduction qui differe de l'original

		if (laDescrIdentificateurFlexBison.fIdentificateurPTR != NULL)
			std::cout <<
				laDescrIdentificateurFlexBison.fIdentificateurPTR -> Traduction ();
		else
			std::cout << laDescrIdentificateurFlexBison.fNom;
		}	// if

	if (laDescrIdentificateurFlexBison.fIdentificateurPTR != NULL)
		return
			laDescrIdentificateurFlexBison.fIdentificateurPTR ->
				LeGenreIdentificateurFlexBison ();
	else
		return kAutreIdentificateurFlexBison;
	}	//	AnalyseurListaFlexBison :: InteractionLexiqueSemantique


// -------------------------------------------------------------------------
//	Methodes pour les actions semantiques
// -------------------------------------------------------------------------
	
void
AnalyseurListaFlexBison :: TraiterIdentFonction (
	DescrIdentificateurFlexBison laDescrIdentificateurFlexBison )
	{
	Chaine	nomDeLaFonction = laDescrIdentificateurFlexBison.fNom;

	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterIdentFonction %s",
				nomDeLaFonction ) <<
			std::endl;

	++ fCompteurFonctions;

	DictionnairePTR
				dictionnaireFonction =
					new Dictionnaire (nomDeLaFonction);

	NiveauDeDeclarationPTR
				leNiveauDeDeclaration =
					new NiveauDeDeclaration (dictionnaireFonction);
					//	pour les paramtres et idents non declares eventuels

	VariableLogiqueTypePTR
				leTypeLogiqueFonction =
					new VariableLogiqueType (
						MiseEnForme (
							gLANGUE_Semantique ->
								FormatNomDeFonction (),
							nomDeLaFonction ));

	if (fOptionsSemantique -> MontrerLInferenceDeType ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatTypeLogiqueDeFonction (),
				leTypeLogiqueFonction -> SousFormeDeChaine (),
				nomDeLaFonction ) <<
			std::endl;

	fIdentFonction = 
		new
			FonctionUtilisateur (
				nomDeLaFonction,
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatNomQualifie (),
					fTableDesSymboles -> Sommet () -> Nom (),
					nomDeLaFonction ),
				leTypeLogiqueFonction,
				dictionnaireFonction );

	bool		dejaPresentAuSommet;
	IdentificateurPTR
				autreDeclarationMasquee = NULL;

	fTableDesSymboles ->
		InsererLIdentificateur (
			fIdentFonction,
			dejaPresentAuSommet,
			autreDeclarationMasquee );

	if (dejaPresentAuSommet)
		ErreurSemantique (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatRedefinitionDeFonctionUtilisateur (),
				nomDeLaFonction ));

	if (autreDeclarationMasquee != NULL)
		AvertissementSemantique (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatDefinitionDeFonctionUtilisateurMasque (),
				fIdentFonction -> NomQualifie (),
				autreDeclarationMasquee ->
					SousFormeDeChaine () ));

	fTableDesSymboles -> Empiler (leNiveauDeDeclaration);
		// sera desempile par "TraiterFinDefinitionDeFonction ())"

	IncrementerNiveauDEvaluation ();
		//	sera decremente par "TraiterFinDefinitionDeFonction ()"

	IncrementerNiveauStatique ();
		//	sera decremente par "TraiterFinDefinitionDeFonction ()"
	
	}	//	AnalyseurListaFlexBison :: TraiterIdentFonction


// -------------------------------------------------------------------------

void
AnalyseurListaFlexBison :: TraiterCorpsDefinitionDeFonction (
	FonctionUtilisateurPTR	lIdentFonction,
	DescrSemantiquePTR		leGrapheSemantiqueDuCorps )
	{
	if (fModeDebug)
		std::cout <<
			"TraiterCorpsDefinition" <<
			std::endl;
	
	Chaine	nomDeLaFonction = lIdentFonction -> Nom ();
	
	VariableLogiqueTypePTR
				laVariableLogiqueType =
					lIdentFonction -> VariableLogiqueType ();

	Chaine	leMessage =
					MiseEnForme (
						gLANGUE_Semantique ->
							FormatNomDeFonction (),
						nomDeLaFonction );

	TypePTR	typeFonction =
					RecupererLeType (
						leGrapheSemantiqueDuCorps, leMessage );

	lIdentFonction -> TypeIdentificateur (typeFonction);
	laVariableLogiqueType ->
		UnifierValeur (
			typeFonction,
			fOptionsSemantique ->
				MontrerLInferenceDeType () );

	ListeDeParametresFormelsPTR
				laListeDeParametresFormels =
					lIdentFonction -> LaListeDeParametresFormels ();

	RecupererLesTypesDesParametres (
		laListeDeParametresFormels );
	}	//	AnalyseurListaFlexBison :: TraiterCorpsDefinitionDeFonction


// -------------------------------------------------------------------------

void
AnalyseurListaFlexBison :: TraiterFinDefinitionDeFonction (
	FonctionUtilisateurPTR	lIdentFonction,
	DescrSemantiquePTR		leGrapheSemantiqueDuCorps )
	{
	Chaine	leNomDeLaFonction = lIdentFonction -> Nom ();

	if (fModeDebug)
		std::cout <<
			"TraiterFinDefinition" <<
			std::endl;

	fTableDesSymboles -> Desempiler ();
		//	avait ete empile par "TraiterIdentFonction ()"

	DecrementerNiveauDEvaluation ();
		//	avait ete incremente par "TraiterIdentFonction ()"

	DecrementerNiveauStatique ();
		//	avait ete incremente par "TraiterIdentFonction ()"

	lIdentFonction ->
		GrapheSemantiqueDuCorps (leGrapheSemantiqueDuCorps);

	if (fOptionsSemantique -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Syntaxe ->
					FormatTraceDUneDefinitionDeFonction (),
				lIdentFonction -> SousFormeDeChaine () ) << 
			std::endl <<
			std::endl;
	
	if (fOptionsSemantique -> MontrerLesGraphes ())
		{
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatGrapheSemantiqueDuCoprsDUneFonction (),
				leNomDeLaFonction );
		leGrapheSemantiqueDuCorps -> Ecrire (1);
		std::cout <<
			"-----------------" <<
			std::endl;
		}
	
	if (fOptionsSemantique -> MontrerLePostfixe ())
		{
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatFormePostfixeeDuCoprsDUneFonction (),
				leNomDeLaFonction );
		leGrapheSemantiqueDuCorps -> PostFixer ();
		std::cout <<
			"-----------------" <<
			std::endl;
		}

#if defined SYNTHESE_PILUM
		fSynthetiseurPilumLista ->
			SynthetiserDefinitionDeFonction (
				lIdentFonction, leGrapheSemantiqueDuCorps );
#endif /* SYNTHESE_PILUM */
	}	//	AnalyseurListaFlexBison :: TraiterFinDefinitionDeFonction


// -------------------------------------------------------------------------

void
AnalyseurListaFlexBison :: TraiterDebutParametres ()
	{
	fNumeroDeParametre = 0;
	}


void
AnalyseurListaFlexBison :: TraiterParametre (
	DescrIdentificateurFlexBison laDescrIdentificateurFlexBison )
	{
	Chaine	nomDuParametre = laDescrIdentificateurFlexBison.fNom;

	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterParametre %s",
				nomDuParametre ) <<
			std::endl;

	VariableLogiqueTypePTR
				leTypeLogiqueParametre =
					new VariableLogiqueType (
						MiseEnForme (
							gLANGUE_Semantique ->
								FormatNomDeParametre (),
							nomDuParametre ));
	
	if (fOptionsSemantique -> MontrerLInferenceDeType ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatTypeLogiqueDeParametre (),
				leTypeLogiqueParametre -> SousFormeDeChaine (),
				nomDuParametre ) <<
			std::endl;

	++ fNumeroDeParametre;

	DescrParametrePTR
				laDescrParametre =
					fOptionsStrategie -> StrategieDEvaluation () ->
						CreerDescrParametre (
							fIdentFonction, fNumeroDeParametre );
	
	ParametreFormelPTR
				lIdentParametre =
					new ParametreFormel (
						nomDuParametre,
						MiseEnForme (
							gLANGUE_Semantique ->
								FormatNomQualifie (),
							fTableDesSymboles -> Sommet () -> Nom (),
							nomDuParametre ),
						leTypeLogiqueParametre,
						laDescrParametre,
						fNiveauDEvaluationCourant );
	
	//	mise a jour
	laDescrParametre -> ParametreFormel (lIdentParametre);
	
	DictionnairePTR
				dictionnaireFonction =
					fIdentFonction -> DictionnaireLocal ();
	if (
		! dictionnaireFonction ->
			InsererLIdentificateur (lIdentParametre)
		)
		ErreurSemantique (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatRedefinitionDeParametre (),
				nomDuParametre ));
	
	DictionnairePTR
				leDictionnaire;
	IdentificateurPTR
				lIdentMasque =
					fTableDesSymboles -> 
						RechercherLeNom (
							nomDuParametre, leDictionnaire, true );
	
	if (lIdentMasque != NULL)
		AvertissementSemantique (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatDefinitionDeParametreMasque (),
				lIdentParametre -> NomQualifie (),
				lIdentMasque -> SousFormeDeChaine () ));
	
	fIdentFonction ->
		LaListeDeParametresFormels () ->
			Ajouter (laDescrParametre);

	}	//	AnalyseurListaFlexBison :: TraiterParametre


// -------------------------------------------------------------------------

void
AnalyseurListaFlexBison :: TraiterDebutEvaluation ()
	{
	if (fModeDebug)
		std::cout <<
			"TraiterDebutEvaluation" <<
			std::endl;

	++ fCompteurEvaluations;

	NiveauDeDeclarationPTR
				leNiveauDeDeclaration =
					new NiveauDeDeclaration (
						MiseEnForme (
							gLANGUE_Semantique ->
								FormatNumeroDEvaluation (),
							fCompteurEvaluations ));
					//	pour les idents non declares eventuels

	fTableDesSymboles -> Empiler (leNiveauDeDeclaration);
		// sera desempile par "TraiterFinEvaluation ()"

	}	// AnalyseurListaFlexBison :: TraiterDebutEvaluation


void
AnalyseurListaFlexBison :: TraiterFinEvaluation (
	DescrSemantiquePTR laSequence )
	{
	TypePTR	typeExpression =
					RecupererLeType (
						laSequence,
						gLANGUE_Syntaxe ->
							SequenceDExpressionsAEvaluer () );

	if (fOptionsSemantique -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Syntaxe ->
					FormatTraceDUneEvaluation (),
				typeExpression-> SousFormeDeChaine () ) <<
			std::endl;

	if (fOptionsSemantique -> MontrerLesGraphes ())
		{
		std::cout <<
			gLANGUE_Semantique ->
				GrapheSemantiqueDeLaSequenceDExpressionsAEvaluer ();
		laSequence -> Ecrire (1);
		std::cout <<
			"-----------------" <<
			std::endl;
		}

	if (fOptionsSemantique -> MontrerLePostfixe ())
		{
		std::cout <<
			gLANGUE_Semantique ->
				FormePostfixeeDeLaSequenceDExpressionsAEvaluer ();
		laSequence -> PostFixer ();
		std::cout <<
			"-----------------" <<
			std::endl;
		}

	if (fOptionsSemantique -> EvaluerDirectement ())
		{
		ContexteDEvaluation
					unContexteDEvaluationVide (
						NULL,
						0,
						fOptionsEvaluation -> ModeTrace (),
						fOptionsStrategie -> CourtCircuitLogiquesBinaires (),
						0,
						NULL,
						NULL );
		
		laSequence ->
			FaireLEvaluationDirecte (& unContexteDEvaluationVide);
		}

#if defined SYNTHESE_PILUM
	fSynthetiseurPilumLista -> SynthetiserEvaluation (laSequence);
#endif /* SYNTHESE_PILUM */

	fTableDesSymboles -> Desempiler ();
		//	avait ete empile par "TraiterDebutEvaluation ()"

	}	//	AnalyseurListaFlexBison :: TraiterFinEvaluation


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaFlexBison :: TraiterFacteurIdentSimple (
	DescrIdentificateurFlexBison laDescrIdentificateurFlexBison )
	{
	Chaine	nomIdentCourant = laDescrIdentificateurFlexBison.fNom;
	
	IdentificateurPTR
				lIdentificateurCourant	=
					laDescrIdentificateurFlexBison.fIdentificateurPTR;
					//	laDescrIdentificateurFlexBison.fIdentificateurPTR a ete
					//	garni par LeGenreIdentificateurFlexBison (),
					// appelle depuis la grammaire Flex	
	
	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterFacteurIdentSimple: lIdentificateurCourant = %s",
				lIdentificateurCourant -> SousFormeDeChaine () ) <<
			std::endl;

	if (lIdentificateurCourant == NULL)
		return
			AccepterFacteurIdentificateurInconnu (nomIdentCourant);

	else
		{
		IdentNonDeclarePTR
					lIdentNonDeclare =
						dynamic_cast <IdentNonDeclarePTR> (lIdentificateurCourant);

		if (lIdentNonDeclare != NULL)
			{
			return new ValeurInconnue (
				lIdentNonDeclare -> VariableLogiqueType () );
				//	pour permettre l'inference du type
				//	de cet identificateur non declare
			}	// if


		ConstantePredefiniePTR
					laConstantePredefinie =
						dynamic_cast <ConstantePredefiniePTR> (lIdentificateurCourant);

		if (laConstantePredefinie != NULL)
			{
			return
				laConstantePredefinie -> CreerGrapheConstante ();
			}	// if


		FonctionUtilisateurPTR
					laFonctionUtilisateur =
						dynamic_cast <FonctionUtilisateurPTR> (lIdentificateurCourant);

		if (laFonctionUtilisateur != NULL)
			{
			ListeDeParametresFormelsPTR
						laListeDeParametresFormels =
							laFonctionUtilisateur -> LaListeDeParametresFormels ();
		
			bool		fonctionParametree =
							! laListeDeParametresFormels -> Vide ();
		
			if (fonctionParametree)
				{
				ErreurSemantique (
					MiseEnForme (
						gLANGUE_Syntaxe ->
							FormatArgumentsAttendusDansAppelDeFonction (),
						laFonctionUtilisateur -> Nom () ));
				return gDescrSemantiqueInconnue;
				}

			else
				return
					new AppelDeFonctionUtilisateur (
						laFonctionUtilisateur,
						new DescrSemantiquePTR [0] );
			}	// if


		ParametreFormelPTR
					leParametreFormel =
						dynamic_cast <ParametreFormelPTR> (lIdentificateurCourant);

		if (leParametreFormel != NULL)
			{
			return
				fOptionsStrategie ->
					StrategieDEvaluation () ->
						CreerEmploiParametre (leParametreFormel);
			}	// if


		IndiceIterationPTR
					lIndiceIteration =
						dynamic_cast <IndiceIterationPTR> (lIdentificateurCourant);

		if (lIndiceIteration != NULL)
			{
			return
				new
					EmploiIndiceIteration (lIndiceIteration);
			}	// if

		ErreurSemantique (
			gLANGUE_Semantique ->
				FacteurIdentificateurMalForme ());

		return gDescrSemantiqueInconnue;

		}	//	lIdentificateurCourant != NULL

	return gDescrSemantiqueInconnue;	// superflu

	}	//	TraiterFacteurIdentSimple


// -------------------------------------------------------------------------

DescrAppelFonctionPTR
AnalyseurListaFlexBison :: AccepterFacteurAppelDeFonctionInconnue (
	Chaine nomIdentCourant )
	{
	ErreurSemantique (
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatAucuneDeclarationAccessible (),
			nomIdentCourant ));

	//	a titre de rattrapage d'erreur semantique,
	//	on enregistre cet identificateur dans la table
	//	avec un type logique libre

	VariableLogiqueTypePTR
				leTypeLogique =
					new VariableLogiqueType (
						MiseEnForme (
							gLANGUE_Semantique ->
								FormatIdentDeFonctionNonDeclare (),
							nomIdentCourant ) );

	if (fOptionsSemantique -> MontrerLInferenceDeType ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatTypeLogiqueDeFonctionNonDeclaree (),
				leTypeLogique -> SousFormeDeChaine (),
				nomIdentCourant ) <<
			std::endl;

	IdentNonDeclarePTR
				lIdentificateurNonDeclare =
					new IdentNonDeclare (
						nomIdentCourant,
						MiseEnForme (
							gLANGUE_Semantique ->
								FormatNomQualifie (),
							fTableDesSymboles -> Sommet () -> Nom (),
							nomIdentCourant ),
						leTypeLogique );

	bool		dejaPresentAuSommet;
	IdentificateurPTR
				autreDeclarationMasquee = NULL;

	fTableDesSymboles -> 
		InsererLIdentificateur (
			lIdentificateurNonDeclare,
			dejaPresentAuSommet,
			autreDeclarationMasquee );

	return
		new DescrAppelFonctionErronee (lIdentificateurNonDeclare);
	}	// AnalyseurSemantiqueLista :: AccepterFacteurAppelDeFonctionInconnue


// -------------------------------------------------------------------------

void
AnalyseurListaFlexBison :: TraiterDebutAppelFonction (
	DescrIdentificateurFlexBison laDescrIdentificateurFlexBison )
	{
	Chaine	nomIdentCourant = laDescrIdentificateurFlexBison.fNom;

	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterDebutAppelFonction %s",
				nomIdentCourant ) <<
			std::endl;

	IdentificateurPTR
				lIdentificateurCourant =
					laDescrIdentificateurFlexBison.fIdentificateurPTR;

	DescrAppelFonctionPTR
				laDescrAppelFonction;

	if (lIdentificateurCourant == NULL)
		laDescrAppelFonction =
			AccepterFacteurAppelDeFonctionInconnue (nomIdentCourant);

	else
		{
		bool		appelBienForme = false;

		IdentNonDeclarePTR
					lIdentNonDeclare =
						dynamic_cast <IdentNonDeclarePTR> (lIdentificateurCourant);

		if (lIdentNonDeclare != NULL)
			{
			appelBienForme = true;
				// pour ne pas avoir de message superflu
				// (politesse du compilateur!)

			laDescrAppelFonction =
				new
					DescrAppelFonctionErronee (
						IdentNonDeclarePTR (lIdentificateurCourant) );
			}	// if


		FonctionPredefiniePTR
					laFonctionPredefinie =
						dynamic_cast <FonctionPredefiniePTR> (lIdentificateurCourant);

		if (laFonctionPredefinie != NULL)
			{
			appelBienForme = true;

			laDescrAppelFonction =
				new DescrAppelFonctionPredefinie (
					FonctionPredefiniePTR (lIdentificateurCourant) );
			}	// if


		FonctionUtilisateurPTR
					laFonctionUtilisateur =
						dynamic_cast <FonctionUtilisateurPTR> (lIdentificateurCourant);

		if (laFonctionUtilisateur != NULL)
			{
			appelBienForme = true;

			if (laFonctionUtilisateur -> LaListeDeParametresFormels () -> Vide ())
				ErreurSemantique (
					gLANGUE_Syntaxe ->
						ParentheseInattendueDansAppelDeFonctionNonParametree () );

			laDescrAppelFonction =
				new DescrAppelFonctionUtilisateur (laFonctionUtilisateur);
			}	// if

		
		if (! appelBienForme)
			{
			ErreurSemantique (
				gLANGUE_Semantique ->
					FacteurIdentificateurMalForme ());

			laDescrAppelFonction =
				new
					DescrAppelFonctionErronee (lIdentificateurCourant);
			}	// if

		}	//	lIdentificateurCourant != NULL	

	fPileDesAppels -> Empiler (laDescrAppelFonction);
		// sera desempile par "TraiterFinAppelFonction ()"

	}	//	AnalyseurListaFlexBison :: TraiterDebutAppelFonction


DescrSemantiquePTR
AnalyseurListaFlexBison :: TraiterFinAppelFonction ()
	{
	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterFinAppelFonction %s",
				fPileDesAppels -> Sommet () -> Nom () ) <<
			std::endl;

	DescrAppelFonctionPTR
				lAppel = fPileDesAppels -> Desempiler ();
		//	avait ete empile par "TraiterDebutAppelFonction ()"

	lAppel -> VerifierSiAssezDArguments (); 

	return lAppel -> CreerGrapheSemantique ();
	}


// -------------------------------------------------------------------------

void
AnalyseurListaFlexBison :: TraiterDebutIteration (
	DescrIdentificateurFlexBison laDescrIdentificateurFlexBison )
	{
	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterDebutIteration %s",
				laDescrIdentificateurFlexBison.fNom ) <<
			std::endl;

	FonctionPredefiniePTR
				laFonctionPredefinie =
					FonctionPredefiniePTR (
						laDescrIdentificateurFlexBison.fIdentificateurPTR );

	fPileDesAppels -> 
		Empiler (new DescrAppelIteration (laFonctionPredefinie));
		// sera desempile par "TraiterFinIteration ()"

	}	//	AnalyseurListaFlexBison :: TraiterDebutIteration


void
AnalyseurListaFlexBison :: TraiterIndiceIteration (
	DescrIdentificateurFlexBison laDescrIdentificateurFlexBison )
	{
	++ fCompteurIterations;
		
	Chaine	nomDeLIndice = laDescrIdentificateurFlexBison.fNom;

	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterIndiceIteration %s",
				nomDeLIndice ) <<
			std::endl;

	//	on a atteint le point de definition de l'indice
	
	IncrementerNiveauDEvaluation ();
		// sera decremente par "TraiterFinIteration ()"

	NiveauDeDeclarationPTR
				leNiveauDeDeclaration =
					new NiveauDeDeclaration (
						MiseEnForme (
							gLANGUE_Semantique -> 
								FormatIteration (),
								fCompteurIterations ));
					//	pour l'indice et les idents non declares eventuels

	fTableDesSymboles -> Empiler (leNiveauDeDeclaration);
		// sera desempile par "TraiterFinIteration ()"

	Chaine	nomQualifieDeLIndice	=
					MiseEnForme (
						gLANGUE_Semantique ->
							FormatNomQualifie (),
						fTableDesSymboles -> Sommet () -> Nom (),
						nomDeLIndice );
	
	IndiceIterationPTR
				lIndice =
					new IndiceIteration (
						nomDeLIndice,
						nomQualifieDeLIndice,
						gTypeLogiqueNombre );

	bool			dejaPresentAuSommet;
	IdentificateurPTR
					autreDeclarationMasquee = NULL;

	fTableDesSymboles ->
		InsererLIdentificateur (
			lIndice,
			dejaPresentAuSommet,
			autreDeclarationMasquee );

	if (dejaPresentAuSommet)
		ErreurSemantique (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatRedefinitionDeLIndiceDIteration (),
				nomDeLIndice ));

	if (autreDeclarationMasquee != NULL)
		AvertissementSemantique (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatDefinitionDeLIndiceDIterationMasque (),
				nomQualifieDeLIndice,
				autreDeclarationMasquee -> SousFormeDeChaine () )
			);

	DescrAppelIterationPTR
				lAppel =
					DescrAppelIterationPTR ( fPileDesAppels -> Sommet ());

	lAppel -> EnregistrerIndice (lIndice);
	}	//	AnalyseurListaFlexBison :: TraiterIndiceIteration


void
AnalyseurListaFlexBison :: TraiterBorneInf (DescrSemantiquePTR laBorneInf)
	{
	if (fModeDebug)
		std::cout <<
			"TraiterBorneInf" <<
			std::endl;

	DescrAppelIterationPTR
				lAppel =
					DescrAppelIterationPTR (fPileDesAppels -> Sommet ());

	lAppel -> EnregistrerBorneInf (laBorneInf);
	}	

void
AnalyseurListaFlexBison :: TraiterBorneSup (DescrSemantiquePTR laBorneSup)
	{
	if (fModeDebug)
		std::cout <<
			"TraiterBorneSup" <<
			std::endl;

	DescrAppelIterationPTR
				lAppel =
					DescrAppelIterationPTR (fPileDesAppels -> Sommet ());

	lAppel -> EnregistrerBorneSup (laBorneSup);
	}	

void
AnalyseurListaFlexBison :: TraiterExprIteree (DescrSemantiquePTR lExpression)
	{
	if (fModeDebug)
		std::cout <<
			"TraiterExprIteree" <<
			std::endl;

	DescrAppelIterationPTR
				lAppel =
					DescrAppelIterationPTR (fPileDesAppels -> Sommet ());

	lAppel -> EnregistrerExprIteree (lExpression);
	}	


DescrSemantiquePTR
AnalyseurListaFlexBison :: TraiterFinIteration ()
	{
	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterFinIteration %s",
				fPileDesAppels -> Sommet () -> Nom () ) <<
			std::endl;

	DescrAppelFonctionPTR
				lAppel = fPileDesAppels -> Desempiler ();
		//	avait ete empile par "TraiterDebutIteration ()"

	DescrSemantiquePTR
				res = lAppel -> CreerGrapheSemantique ();

	DecrementerNiveauDEvaluation ();
		// avait ete incremente par "TraiterIndiceIteration ()"
		
	fTableDesSymboles -> Desempiler ();	//	Iteration
		//	avait ete empile par "TraiterIndiceIteration ()"

	return res;
	}	//	AnalyseurListaFlexBison :: TraiterFinIteration


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaFlexBison :: TraiterSequence (
	DescrIdentificateurFlexBison	laDescrIdentificateurFlexBison,
	DescrSemantiquePTR		lExpression,
	DescrSemantiquePTR		laFinExpressionsSequencees )
	{
	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterSequence %s",
				laDescrIdentificateurFlexBison.fNom ) <<
			std::endl;

	FonctionPredefiniePTR
				laFonctionPredefinie =
					FonctionPredefiniePTR (
						laDescrIdentificateurFlexBison.fIdentificateurPTR );

	DescrSemantiquePTR
				* leBlocDArguments =
					//	on les initialise a "gDescrSemantiqueInconnue"
					new DescrSemantiquePTR [
						laFonctionPredefinie -> NombreDeParametres () ];
	
	leBlocDArguments [0] = lExpression;
	leBlocDArguments [1] = laFinExpressionsSequencees;
	
	return laFonctionPredefinie -> CreerGrapheDAppelALaFonction (
		kLectureSansAutre, leBlocDArguments );
	}	//	AnalyseurListaFlexBison :: TraiterSequence


// -------------------------------------------------------------------------

void
AnalyseurListaFlexBison :: TraiterDebutArgument ()
	{
	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterDebutArgument %s",
				fPileDesAppels -> Sommet () -> Nom () ) <<
			std::endl;

	DescrAppelFonctionPTR
				lAppel = fPileDesAppels -> Sommet ();

	lAppel -> VerifierSiPasTropDArguments ();

	DescrAppelFonctionUtilisateurPTR
				leDescrAppelFonctionUtilisateur =
					dynamic_cast <DescrAppelFonctionUtilisateurPTR> (lAppel);

	if (
		leDescrAppelFonctionUtilisateur != NULL
			&&
		fOptionsStrategie -> StrategieDEvaluation () -> ABesoinDUnLienStatique ()			
		)
		IncrementerNiveauStatique ();
			//	sera decremente par "TraiterFinArgument"
	}	//  AnalyseurListaFlexBison :: TraiterDebutArgument


void
AnalyseurListaFlexBison :: TraiterFinArgument (DescrSemantiquePTR lArgument)
	{
	if (fModeDebug)
		std::cout <<
			MiseEnForme (
				"TraiterFinArgument %s",
				fPileDesAppels -> Sommet () -> Nom () ) <<
			std::endl;

	DescrAppelFonctionPTR
				lAppel = fPileDesAppels -> Sommet ();

	lAppel -> EnregistrerArgument (lArgument);

	DescrAppelFonctionUtilisateurPTR
				leDescrAppelFonctionUtilisateur =
					dynamic_cast <DescrAppelFonctionUtilisateurPTR> (lAppel);

	if (
		leDescrAppelFonctionUtilisateur != NULL
			&&
		fOptionsStrategie -> StrategieDEvaluation () -> ABesoinDUnLienStatique ()			
		)
		DecrementerNiveauStatique ();
			//	avait ete incremente par "TraiterDebutArgument"
	}	// AnalyseurListaFlexBison :: TraiterFinArgument
