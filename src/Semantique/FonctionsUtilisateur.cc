// =========================================================================
//	FonctionsUtilisateur.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "FonctionsUtilisateur.h"

#include "AnalyseurSemantiqueLista.h"


#if defined SYNTHESE_PILUM
	#include "DecodageDOptionsSemantique.h"
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	FonctionUtilisateur
// -------------------------------------------------------------------------

FonctionUtilisateur :: FonctionUtilisateur (
	Chaine						leNom,
	Chaine						leNomQualifie,
	VariableLogiqueTypePTR	laVarLogiqueType,
	DictionnairePTR			leDictionnaire )
	: Identificateur (
		leNom, leNomQualifie,
		kIdentFonctionUtilisateur, kAutreIdentificateurFlexBison,
		laVarLogiqueType )
	{
	fDictionnaireLocal = leDictionnaire;

	fNiveauDEvaluation	=
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant ();
	fNiveauStatique		=
		gAnalyseurSemantiqueLista -> NiveauStatiqueCourant ();

	fListeDeParametresFormels = new ListeDeParametresFormels;

	fGrapheSemantiqueDuCorps = NULL;

#if defined SYNTHESE_PILUM
	fEtiquetteDuCorps = NULL;
	fLienStatiqueNecessaire = false;
#endif /* SYNTHESE_PILUM */

	}	//	FonctionUtilisateur :: FonctionUtilisateur


Chaine
FonctionUtilisateur :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatFonctionUtilisateur (),
			fNomQualifie,
			fNiveauStatique,
			fListeDeParametresFormels -> ProfilDesParametres (),
			fTypeIdentificateur -> SousFormeDeChaine () );
	}


DictionnairePTR
FonctionUtilisateur :: DictionnaireLocal ()
	{ return fDictionnaireLocal; }

ListeDeParametresFormelsPTR
FonctionUtilisateur :: LaListeDeParametresFormels ()
	{ return fListeDeParametresFormels; }


void
FonctionUtilisateur :: GrapheSemantiqueDuCorps (
	DescrSemantiquePTR leGrapheSemantiqueDuCorps )
	{ fGrapheSemantiqueDuCorps = leGrapheSemantiqueDuCorps; }

DescrSemantiquePTR
FonctionUtilisateur :: GrapheSemantiqueDuCorps ()
	{ return fGrapheSemantiqueDuCorps; }

int
FonctionUtilisateur :: NiveauDEvaluation ()
	{ return fNiveauDEvaluation; }
int
FonctionUtilisateur :: NiveauStatique ()
	{ return fNiveauStatique; }


void
FonctionUtilisateur :: PurgerIdent (
	int		lIdentation,
	bool		leModeVerbeux,
	bool		leMontrerLesDictionnaires )
	{
	this -> Identificateur :: PurgerIdent (
		lIdentation, leModeVerbeux, leMontrerLesDictionnaires );

	delete fListeDeParametresFormels;
		//	seulement maintenant
	}	// FonctionUtilisateur :: PurgerIdent

// -------------------------------------------------------------------------

#if defined SYNTHESE_PILUM

void
FonctionUtilisateur :: EtiquetteDuCorps (
	VariableLogiqueEtiquettePTR lEtiquDuCorps )
	{ fEtiquetteDuCorps = lEtiquDuCorps; }

VariableLogiqueEtiquettePTR
FonctionUtilisateur :: EtiquetteDuCorps ()
	{ return fEtiquetteDuCorps; }

void
FonctionUtilisateur :: UnLienStatiqueEstNecessaire ()
	{
	fLienStatiqueNecessaire = true;
	if (gAnalyseurSemantiqueLista -> LesOptionsSemantique () -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatBesoinDUnLienStatique (),
				fNomQualifie ) <<
			std::endl;
	}

bool
FonctionUtilisateur :: LienStatiqueNecessaire ()
	{ return fLienStatiqueNecessaire; }

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	EmploiParametre
// -------------------------------------------------------------------------

EmploiParametre :: EmploiParametre (
	ParametreFormelPTR 	leParametreFormel )
	:	DescrSemantique (leParametreFormel -> VariableLogiqueType ())
	{
	fParametreFormel = leParametreFormel;

	fNiveauDEvaluation	=
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant ();
	fNiveauStatique		=
		gAnalyseurSemantiqueLista -> NiveauStatiqueCourant ();
	}


void
EmploiParametre :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);

	DescrParametrePTR
				leDescrParametre = fParametreFormel -> DescrParametre ();

	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatEcritureEmploiParametre (),
			leDescrParametre ->
				StrategieDEvaluation () -> SousFormeDeChaine (),
			leDescrParametre ->
				ParametreFormel () -> NomQualifie (),
			leDescrParametre -> NiveauDEvaluation (),
			leDescrParametre -> NiveauStatique (),
			fNiveauDEvaluation,
			fNiveauStatique ) <<
		std::endl;
	}

ValeurLista
EmploiParametre :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	int		differenceDeNiveauDEvaluation =
					fNiveauDEvaluation
						-
					fParametreFormel -> NiveauDEvaluation ();

	//	on cherche le contexte de definition de cet indice

	ContexteDEvaluationPTR
				curseur = leContexteDEvaluation;

	for (int i = 1; i <= differenceDeNiveauDEvaluation; ++ i)
		{
		if (curseur == NULL)
			SortieSurErreur (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatEmploiParametreDifferenceStatiqueTropGrande (),
					differenceDeNiveauDEvaluation ),
				1 );

		curseur = curseur -> LienStatique ();
		}	// for

	return
		curseur -> BlocDAssociations ()
			[ fParametreFormel -> DescrParametre () -> NumeroDeParametre () - 1 ]
				-> Evaluer (leContexteDEvaluation -> Indentation ());

	}	// EmploiParametre :: Evaluer


// -------------------------------------------------------------------------

EmploiParametreParValeur :: EmploiParametreParValeur (
	ParametreFormelPTR 	leParametreFormel )
	:	EmploiParametre (leParametreFormel)
	{}

#if defined SYNTHESE_PILUM

void
EmploiParametreParValeur :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	DescrParametrePTR
				laDescrParametre =
					fParametreFormel -> DescrParametre ();
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	//	on fait charger la valeur du parametre:

	int		differenceDeNiveauStatique =
					fNiveauStatique - laDescrParametre -> NiveauStatique ();

	synth -> AccesCellulePourValeur (
		differenceDeNiveauStatique,
		laDescrParametre -> PositionDansLeBloc () );
	if (leContexteDeSynthese -> OptionsSynthese () -> CommenterLeCode ())
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatEcritureEmploiParametre (),
				laDescrParametre ->
					StrategieDEvaluation () -> SousFormeDeChaine (),
				laDescrParametre ->
					ParametreFormel () -> NomQualifie (),
				laDescrParametre -> NumeroDeParametre (),
				laDescrParametre -> NiveauDEvaluation (),
				laDescrParametre -> NiveauStatique (),
				fNiveauDEvaluation,
				fNiveauStatique ));

	}	//	EmploiParametreParValeur :: Synthetiser

#endif /* SYNTHESE_PILUM */

// -------------------------------------------------------------------------

EmploiParametreParNom :: EmploiParametreParNom (
	ParametreFormelPTR 	leParametreFormel )
	:	EmploiParametre (leParametreFormel)
	{}

#if defined SYNTHESE_PILUM

void
EmploiParametreParNom :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	DescrParametrePTR
				laDescrParametre = fParametreFormel -> DescrParametre ();
	Chaine	leNomQualifieDuParametre =
					laDescrParametre -> ParametreFormel () -> NomQualifie ();
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	//	on fait charger l'adresse du thunk:

	int		differenceDeNiveauStatique =
					fNiveauStatique - laDescrParametre -> NiveauStatique ();

	synth -> AccesCellulePourAdresse (
		differenceDeNiveauStatique,
		laDescrParametre -> PositionDansLeBloc () );
	if (leContexteDeSynthese -> OptionsSynthese () -> CommenterLeCode ())
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatDescripteurDuParametreParNom (),
				leNomQualifieDuParametre,
				laDescrParametre -> NumeroDeParametre () ));

	//	puis on le fait evaluer:

	synth -> EvaluerThunk (
		leNomQualifieDuParametre,
		leContexteDeSynthese ->
			OptionsSynthese () -> MarquerLesBlocsDActivation () );

	}	//	EmploiParametreParNom :: Synthetiser

#endif /* SYNTHESE_PILUM */

// -------------------------------------------------------------------------

EmploiParametreParBesoin :: EmploiParametreParBesoin (
	ParametreFormelPTR 	leParametreFormel )
	:	EmploiParametre (leParametreFormel)
	{}

#if defined SYNTHESE_PILUM

void
EmploiParametreParBesoin :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	DescrParametrePTR
				laDescrParametre = fParametreFormel -> DescrParametre ();
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	Chaine	leNomQualifieDuParametre =
					laDescrParametre -> ParametreFormel () -> NomQualifie ();
	int		leNumeroDeParametre =
					laDescrParametre -> NumeroDeParametre ();

	int		positionDeBase =
					laDescrParametre -> PositionDansLeBloc ();

	int		positionBooleenControle = positionDeBase;
	int		positionResultat = positionDeBase + 1;
	int		positionThunk = positionDeBase + 2;

	int		differenceDeNiveauStatique =
					fNiveauStatique - laDescrParametre -> NiveauStatique ();

	bool		commenterLeCode = leContexteDeSynthese ->
					OptionsSynthese () -> CommenterLeCode ();


	//	le thunk doit-il etre encore etre evalue?

	synth -> AccesCellulePourValeur (
		differenceDeNiveauStatique, positionBooleenControle );
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatValeurDuBooleenDeControleParBesoin (),
				leNomQualifieDuParametre,
				leNumeroDeParametre) );

	VariableLogiqueEtiquettePTR
				interParBesoin =
					synth -> CreerEtiquette (
						gLANGUE_Semantique ->
							EtiquetteIntermediaireParBesoin () );

	synth -> Saut (iSauterSiFaux, interParBesoin);


	//	si oui: on fait charger l'adresse du resultat

	synth -> AccesCellulePourAdresse (
		differenceDeNiveauStatique, positionResultat );
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatAdresseDuResultatDe (),
				leNomQualifieDuParametre,
				leNumeroDeParametre ));

	//	puis on fait charger l'adresse du thunk:

	synth -> AccesCellulePourAdresse (
		differenceDeNiveauStatique, positionThunk );
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatDescripteurDuParametreParBesoin (),
				leNomQualifieDuParametre,
				leNumeroDeParametre ));


	//	puis on le fait evaluer:

	synth -> EvaluerThunk (
		leNomQualifieDuParametre,
		leContexteDeSynthese -> OptionsSynthese () ->
			MarquerLesBlocsDActivation () );


	//	puis on sauvegarde la valeur resultante:

	synth -> Zeroadique (iStocker);

	//	on fait charger l'adresse du booleen de controle:

	synth -> AccesCellulePourAdresse (
		differenceDeNiveauStatique, positionBooleenControle );
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatAdresseDuBooleenDeControleParBesoin (),
				leNomQualifieDuParametre,
				leNumeroDeParametre ));

	//	puis on lui affecte la valeur 'faux':

	synth -> Logique (false);
	synth -> Zeroadique (iStocker);

	//	dans tous les cas, on fait empiler la valeur de l'argument:

	synth -> PlacerEtiquette (interParBesoin);

	synth -> AccesCellulePourValeur (
		differenceDeNiveauStatique, positionResultat );
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatValeurParBesoin (),
				leNomQualifieDuParametre,
				leNumeroDeParametre) );

	}	//	EmploiParametreParBesoin :: Synthetiser

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	AppelDeFonctionUtilisateur
// -------------------------------------------------------------------------

AppelDeFonctionUtilisateur :: AppelDeFonctionUtilisateur (
	FonctionUtilisateurPTR 	laFonctionUtilisateur,
	DescrSemantiquePTR		* lesArgumentsDAppel )
	:	DescrSemantique (
			laFonctionUtilisateur -> VariableLogiqueType () )
	{
	fFonctionUtilisateur = laFonctionUtilisateur;
	fArgumentsDAppel = lesArgumentsDAppel;

	fNiveauDEvaluation	=
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant ();
	fNiveauStatique		=
		gAnalyseurSemantiqueLista -> NiveauStatiqueCourant ();
	}

// -------------------------------------------------------------------------

void
AppelDeFonctionUtilisateur :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);
	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatEcritureAppelDeFonction (),
			fFonctionUtilisateur -> Nom (),
			fFonctionUtilisateur -> NiveauDEvaluation (),
			fFonctionUtilisateur -> NiveauStatique (),
			fNiveauDEvaluation,
			fNiveauStatique ) <<
		std::endl;

	int		indentationArguments = lIndentation + 1;
	int		nombreDeParametres =
					fFonctionUtilisateur ->
						LaListeDeParametresFormels () -> NombreDeParametres ();

	for (int i = 0; i < nombreDeParametres; ++ i)
		fArgumentsDAppel [i] ->
			Ecrire (indentationArguments);
	}	//	AppelDeFonctionUtilisateur :: Ecrire

// -------------------------------------------------------------------------

void
AppelDeFonctionUtilisateur :: PostFixer ()
	{
	int		nombreDeParametres =
					fFonctionUtilisateur ->
						LaListeDeParametresFormels () -> NombreDeParametres ();

	for (int i = 0; i < nombreDeParametres; ++ i)
		fArgumentsDAppel [i] -> PostFixer ();

	std::cout <<
		"\t" <<
		fFonctionUtilisateur -> Nom () <<
		std::endl;
	}

// -------------------------------------------------------------------------

DescrSemantiquePTR
AppelDeFonctionUtilisateur::GrapheSemantiqueDuCorps ()
	{
	return fFonctionUtilisateur->GrapheSemantiqueDuCorps();
	}

// -------------------------------------------------------------------------

ValeurLista
AppelDeFonctionUtilisateur :: Evaluer (
	ContexteDEvaluationPTR leContexteDEvaluation )
	{
	Chaine	nomDeLaFonction =
					fFonctionUtilisateur -> Nom ();
	ListeDeParametresFormelsPTR
				listeDesParametresFormels =
					fFonctionUtilisateur -> LaListeDeParametresFormels ();

	int			nombreDeParametres =
					listeDesParametresFormels -> NombreDeParametres ();

	ListeDesDescrParametresPTR
				listeDesDescrParametres =
					listeDesParametresFormels -> LaListeDesDescrParametres ();

	int			lIndentation =
					leContexteDEvaluation -> Indentation ();

	ValeurLista
				res;

	bool		traceDEvaluation =
					leContexteDEvaluation -> TraceDEvaluation ();

	DescrSemantiquePTR
				leGrapheSemantiqueDuCorps =
					fFonctionUtilisateur -> GrapheSemantiqueDuCorps ();

	bool		produitUneValeur =
					leGrapheSemantiqueDuCorps -> ProduitUneValeur ();

	if (nombreDeParametres == 0)
		{
		if (traceDEvaluation)
			{
			Indenter (lIndentation);

			std::cout <<
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatAppelALaFonctionSansArguments (),
					nomDeLaFonction,
					leContexteDEvaluation ->
						NumeroContexteDEvaluation () ) <<
				std::endl;
			}	// traceDEvaluation

		res =
			leGrapheSemantiqueDuCorps -> Evaluer (leContexteDEvaluation);

		if (traceDEvaluation)
			{
			std::cout <<
				std::endl;
			Indenter (lIndentation);

			if (produitUneValeur)
				{
				std::cout <<
					MiseEnForme (
						gLANGUE_Semantique ->
							FormatResultatDeLAppelALaFonction (),
						nomDeLaFonction,
						leContexteDEvaluation ->
							NumeroContexteDEvaluation () );
				res.Ecrire (lIndentation);
				}
			else
				std::cout <<
					MiseEnForme (
						gLANGUE_Semantique ->
							FormatSortieDeLAppelALaFonction (),
						nomDeLaFonction,
						leContexteDEvaluation ->
							NumeroContexteDEvaluation () );
			std::cout <<
				std::endl;
			}	// traceDEvaluation

		}	//	// nombreDeParametres == 0

	else
		{
		AssocArgumentParametrePTR
					* blocDAssociations =
						new AssocArgumentParametrePTR [nombreDeParametres];

		int		differenceDeNiveauDEvaluation =
						fNiveauDEvaluation
							-
						fFonctionUtilisateur -> NiveauDEvaluation ();

		ContexteDEvaluationPTR
					leContexteDEvaluationDuCorps =
						new ContexteDEvaluation (
							blocDAssociations,
							nombreDeParametres,
							traceDEvaluation,
							leContexteDEvaluation ->
								CourtCircuitLogiquesBinaires (),
							lIndentation + 1,
							leContexteDEvaluation -> RemonteeStatique (
								differenceDeNiveauDEvaluation ),
							leContexteDEvaluation );

		ListeDesDescrParametres :: iterator
					parametreCourant;
		int		i	= 0;

		for (
			parametreCourant = listeDesDescrParametres -> begin ();
			parametreCourant != listeDesDescrParametres -> end ();
			++ parametreCourant )
			{
			blocDAssociations [i] =
				(* parametreCourant) ->
					CreerAssocArgumentParametre (
						fArgumentsDAppel [i], leContexteDEvaluation );
			i ++;
			}	// for

		if (traceDEvaluation)
			{
			std::cout <<
				std::endl;
			Indenter (lIndentation);

			std::cout <<
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatAppelALaFonctionAvecArguments (),
					nomDeLaFonction,
					leContexteDEvaluationDuCorps ->
						NumeroContexteDEvaluation () ) <<
				std::endl;

			for (int j = 0; j < nombreDeParametres; ++ j)
				{
				Indenter (lIndentation + 1);
				std::cout <<
					MiseEnForme ("*** %d: ", j + 1);
				blocDAssociations [j] ->
					Ecrire (lIndentation + 1);
				}	//	for
			}	// if

		res =
			leGrapheSemantiqueDuCorps ->
				Evaluer (leContexteDEvaluationDuCorps);

		if (traceDEvaluation)
			{
			std::cout <<
				std::endl;
			Indenter (lIndentation);

			if (produitUneValeur)
				{
				std::cout <<
					MiseEnForme (
						gLANGUE_Semantique ->
							FormatResultatDeLAppelALaFonction (),
						nomDeLaFonction,
						leContexteDEvaluationDuCorps ->
							NumeroContexteDEvaluation () ) <<
					std::endl;
				res.Ecrire (lIndentation);
				}
			else
				std::cout <<
					MiseEnForme (
						gLANGUE_Semantique ->
							FormatSortieDeLAppelALaFonction (),
						nomDeLaFonction,
						leContexteDEvaluationDuCorps ->
							NumeroContexteDEvaluation () );
			std::cout <<
				std::endl;
			}	// traceDEvaluation

		delete leContexteDEvaluationDuCorps;
		delete [] blocDAssociations;

		}	// nombreDeParametres != 0

	return res;

	}	//	AppelDeFonctionUtilisateur :: Evaluer

// -------------------------------------------------------------------------

#if defined SYNTHESE_PILUM

void
AppelDeFonctionUtilisateur :: Synthetiser (
	ContexteDeSynthesePTR leContexteDeSynthese )
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	Chaine	nomDeLaFonction =
					fFonctionUtilisateur -> Nom ();

	ListeDeParametresFormelsPTR
				listeDesParametresFormels =
					fFonctionUtilisateur -> LaListeDeParametresFormels ();
	int			nombreDeParametres =
					listeDesParametresFormels -> NombreDeParametres ();

	ListeDesDescrParametresPTR
				listeDesDescrParametres =
					listeDesParametresFormels -> LaListeDesDescrParametres ();

	bool		commenterLeCode =
					leContexteDeSynthese ->
						OptionsSynthese () -> CommenterLeCode ();

	bool		marquerLesBlocsDActivation =
					leContexteDeSynthese ->
						OptionsSynthese () -> MarquerLesBlocsDActivation ();

	if (marquerLesBlocsDActivation)
		synth -> MarquerBlocDActivation (nomDeLaFonction);

	if (nombreDeParametres != 0)
		{
		//	on empile les arguments

		ListeDesDescrParametres :: iterator
					parametreCourant;
		int			i	= 0;

/*
		La solution:

		for (int i = 0; i < nombreDeParametres; ++ i)
			fArgumentsDAppel [i] ->
				Synthetiser (leContexteDeSynthese);

		suffirait pour le passage par valeur

		Pour gérer les différentes stratégies, on délègue a la description
		du parametre formel, qui est spécifique selon la strategie,
		le soin de faire la synthese de code adequate
*/

		for (
			parametreCourant = listeDesDescrParametres -> begin ();
			parametreCourant != listeDesDescrParametres -> end ();
			++ parametreCourant )
			{
			(* parametreCourant) ->
				Synthetiser (leContexteDeSynthese, fArgumentsDAppel [i ++]);
			}	// for

		if (fFonctionUtilisateur -> LienStatiqueNecessaire ())
			{
			//	il faut empiler le LIEN STATIQUE de la fonction APPELEE
			//	toutes les fonctions sont declarees
			//	GLOBALEMENT en Lista

		int		differenceDeNiveauStatique =
						fNiveauStatique - fFonctionUtilisateur -> NiveauStatique ();

		synth -> LienStatique (differenceDeNiveauStatique, 0);
		if (commenterLeCode)
			synth -> Commentaire (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatLienStatiquePourAppelALaFonction (),
					nomDeLaFonction ));
			}
		}	//	if

	synth -> Appel (fFonctionUtilisateur -> EtiquetteDuCorps ());
	if (commenterLeCode)
		synth -> Commentaire (nomDeLaFonction);

	}	//	AppelDeFonctionUtilisateur :: Synthetiser

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	OptionsEvaluation
// -------------------------------------------------------------------------

OptionsEvaluation :: OptionsEvaluation (
	bool						leModeTrace )
	{
	fModeTrace = leModeTrace;
	}
