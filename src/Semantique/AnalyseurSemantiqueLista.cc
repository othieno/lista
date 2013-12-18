// =========================================================================
//	AnalyseurSemantiqueLista.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "AnalyseurSemantiqueLista.h"

#include "AlgebreBooleenne.h"
#include "Arithmetique.h"
#include "ChainesDeCaracteres.h"
#include "Comparaisons.h"
#include "EntreesSorties.h"
#include "Sequencements.h"
#include "Si.h"
#include "Iterations.h"
#include "Listes.h"

#include "DecodageDOptionsSemantique.h"


// -------------------------------------------------------------------------
//	AnalyseurSemantiqueLista
// -------------------------------------------------------------------------

AnalyseurSemantiqueLista :: AnalyseurSemantiqueLista (
	OptionsStrategiePTR			lesOptionsStrategie,
	OptionsSemantiquePTR			lesOptionsSemantique,
	OptionsEvaluationPTR			lesOptionsEvaluation
#if defined SYNTHESE_PILUM
,	SynthetiseurPilumListaPTR	leSynthetiseurPilumLista
#endif /* SYNTHESE_PILUM */
	)
	{
	gAnalyseurSemantiqueLista = this;
		// pouur acceder directement a toute instance de cet analyseur
		//	ou de l'une de ses sous-classes
		//	depuis les analyseurs FlexBison et PredictifDescenteRecursive

	fOptionsStrategie = lesOptionsStrategie;
	fOptionsSemantique = lesOptionsSemantique;
	fOptionsEvaluation = lesOptionsEvaluation;

#if defined SYNTHESE_PILUM
	fSynthetiseurPilumLista = leSynthetiseurPilumLista;
#endif /* SYNTHESE_PILUM */

	bool		modeVerbeux = fOptionsSemantique -> ModeVerbeux ();

	fTableDesSymboles =
		new TableDesSymboles (
			modeVerbeux,
			fOptionsSemantique -> MontrerLesDictionnaires () );

	fSourceCorrectSemantiquement = true;

	fTableDesSymboles -> Empiler (
		new NiveauDeDeclaration (
			gLANGUE_Semantique ->
				NiveauDesPredefinis () ));

	InsererLesIdentificateursPredefinis ();

	fTableDesSymboles -> Empiler (
		new NiveauDeDeclaration (
			gLANGUE_Semantique ->
				NiveauPrincipal () ));

	if (modeVerbeux)
		{
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatPasageDesParametres (),
				fOptionsStrategie -> StrategieDEvaluation () ->
					SousFormeDeChaine ()
				)  <<
			std::endl;

		if (fOptionsStrategie -> CourtCircuitLogiquesBinaires ())
			std::cout <<
				gLANGUE_Semantique ->
					CourtCircuitDesOperateursBinaires () <<
				std::endl;
		}

	fCompteurFonctions = 0;
	fCompteurEvaluations = 0;
	fCompteurIterations = 0;

	//	On cree une liste cirulaire de 1 parametre

	VariableLogiqueTypePTR
				laVariableLogiqueType =
					new VariableLogiqueType (
						gLANGUE_Semantique ->
							TypeParametreFictifPourRattrapageDErreurs (),
						gTypeInconnu );

	DescrParametrePTR
				parametreInconnu =
					fOptionsStrategie -> StrategieDEvaluation () ->
						CreerDescrParametre (NULL, 0);

	fListeDeParametresFormelsInconnus =
		new ListeDeParametresFormels;
	fListeDeParametresFormelsInconnus ->
		Ajouter (parametreInconnu);

	ParametreFormelPTR
				lIdentParametreInconnu =
					new ParametreFormel (
						gLANGUE_Semantique ->
							NomParametreInconnu (),
						gLANGUE_Semantique ->
							NomQualifieParametreInconnu (),
						laVariableLogiqueType,
						NULL,
						0 );

	//	mise a jour
	parametreInconnu -> ParametreFormel (lIdentParametreInconnu);

	fNiveauStatiqueCourant = 0;
	fNiveauDEvaluationCourant = 0;

	}	//	AnalyseurSemantiqueLista :: AnalyseurSemantiqueLista


AnalyseurSemantiqueLista :: ~ AnalyseurSemantiqueLista ()
	{
	fTableDesSymboles -> Desempiler ();	//	Fonctions Utilisateur
	fTableDesSymboles ->
		MontrerLesDictionnaires (
			fOptionsSemantique -> MontrerLeDictionnaireDesPredefinis () );
	fTableDesSymboles -> Desempiler ();	//	Idents Predefinis

	delete fTableDesSymboles;
	}


void
AnalyseurSemantiqueLista :: InsererLIdentificateurPredefini (
	IdentPredefiniPTR lIdentPredefini )
	{
	bool		dejaPresentAuSommet;
	IdentificateurPTR
				autreDeclarationMasquee = NULL;

	fTableDesSymboles ->
		InsererLIdentificateur (
			lIdentPredefini,
			dejaPresentAuSommet,
			autreDeclarationMasquee );

	if (0 && dejaPresentAuSommet)
		ErreurSemantique (
			MiseEnForme (
				gLANGUE_Semantique ->
					IdentPredefiniDefiniMultiplement (),
				lIdentPredefini -> NomQualifie () ));
	}	// AnalyseurSemantiqueLista :: InsererLIdentificateurPredefini


void
AnalyseurSemantiqueLista :: InsererLesIdentificateursPredefinis ()
	{
	InsererLIdentificateurPredefini (
		new
			VraiPredef (& LanguePredefinis :: Vrai) );
	InsererLIdentificateurPredefini (
		new
			FauxPredef (& LanguePredefinis :: Faux) );

	InsererLIdentificateurPredefini (
		new
			PiPredef (& LanguePredefinis :: Pi) );
	InsererLIdentificateurPredefini (
		new
			EPredef (& LanguePredefinis :: E) );
	InsererLIdentificateurPredefini (
		new
			VidePredef (& LanguePredefinis :: Vide) );

	InsererLIdentificateurPredefini (
		new
			NonPredef (& LanguePredefinis :: Non) );
	InsererLIdentificateurPredefini (
		new
			EtPredef (& LanguePredefinis :: Et) );
	InsererLIdentificateurPredefini (
		new
			OuPredef (& LanguePredefinis :: Ou) );

	InsererLIdentificateurPredefini (
		new
			PairPredef (& LanguePredefinis :: Pair) );

	InsererLIdentificateurPredefini (
		new
			EgalePredef (& LanguePredefinis :: Egale) );
	InsererLIdentificateurPredefini (
		new
			DifferentPredef (& LanguePredefinis :: Different) );
	InsererLIdentificateurPredefini (
		new
			InfPredef (& LanguePredefinis :: Inf) );
	InsererLIdentificateurPredefini (
		new
			SupPredef (& LanguePredefinis :: Sup) );
	InsererLIdentificateurPredefini (
		new
			InfEgalePredef (& LanguePredefinis :: InfEgale) );
	InsererLIdentificateurPredefini (
		new
			SupEgalePredef (& LanguePredefinis :: SupEgale) );

	InsererLIdentificateurPredefini (
		new
			ModuloPredef (& LanguePredefinis :: Modulo) );

	InsererLIdentificateurPredefini (
		new
			HasardPredef (& LanguePredefinis :: Hasard) );

	InsererLIdentificateurPredefini (
		new
			RacinePredef (& LanguePredefinis :: Racine) );
	InsererLIdentificateurPredefini (
		new
			SinPredef (& LanguePredefinis :: Sin) );
	InsererLIdentificateurPredefini (
		new
			CosPredef (& LanguePredefinis :: Cos) );
	InsererLIdentificateurPredefini (
		new
			ArcTanPredef (& LanguePredefinis :: ArcTan) );
	InsererLIdentificateurPredefini (
		new
			LogPredef (& LanguePredefinis :: Log) );
	InsererLIdentificateurPredefini (
		new
			ExpPredef (& LanguePredefinis :: Exp) );

	InsererLIdentificateurPredefini (
		new
			LongueurChainePredef (& LanguePredefinis :: LongueurChaine) );
	InsererLIdentificateurPredefini (
		new
			ChaineVidePredef (& LanguePredefinis :: ChaineVide) );
	InsererLIdentificateurPredefini (
		new
			ContientChainePredef (& LanguePredefinis :: ContientChaine) );
	InsererLIdentificateurPredefini (
		new
			ConcatChainesPredef (& LanguePredefinis :: ConcatChaines) );
	InsererLIdentificateurPredefini (
		new
			RepliquerChainePredef (& LanguePredefinis :: RepliquerChaine) );
	InsererLIdentificateurPredefini (
		new
			RemplacerChainePredef (& LanguePredefinis :: RemplacerChaine) );
	InsererLIdentificateurPredefini (
		new
			FormaterNombrePredef (& LanguePredefinis :: FormaterNombre) );

	InsererLIdentificateurPredefini (
		new
			LireNombrePredef (& LanguePredefinis :: LireNombre) );
	InsererLIdentificateurPredefini (
		new
			LireBooleenPredef (& LanguePredefinis :: LireBooleen) );
	InsererLIdentificateurPredefini (
		new
			LireChainePredef (& LanguePredefinis :: LireChaine) );

	InsererLIdentificateurPredefini (
		new
			EcrireNombrePredef (& LanguePredefinis :: EcrireNombre) );
	InsererLIdentificateurPredefini (
		new
			EcrireBooleenPredef (& LanguePredefinis :: EcrireBooleen) );
	InsererLIdentificateurPredefini (
		new
			EcrireChainePredef (& LanguePredefinis :: EcrireChaine) );
	InsererLIdentificateurPredefini (
		new
			EcrireFinDeLignePredef (& LanguePredefinis :: EcrireFinDeLigne) );

	InsererLIdentificateurPredefini (
		new
			SiPredef (& LanguePredefinis :: Si) );

	InsererLIdentificateurPredefini (
		new
			SeqPredef (& LanguePredefinis :: Seq) );
	InsererLIdentificateurPredefini (
		new
			Seq1Predef (& LanguePredefinis :: Seq1) );

	InsererLIdentificateurPredefini (
		new
			SommePredef (& LanguePredefinis :: Somme) );
	InsererLIdentificateurPredefini (
		new
			ProduitPredef (& LanguePredefinis :: Produit) );
	InsererLIdentificateurPredefini (
		new
			PourPredef (& LanguePredefinis :: Pour) );
   InsererLIdentificateurPredefini (
      new
         CarPredef (& LanguePredefinis :: Car) );
   InsererLIdentificateurPredefini (
      new
         CdrPredef (& LanguePredefinis :: Cdr) );
   InsererLIdentificateurPredefini (
      new
         ConsPredef (& LanguePredefinis :: Cons) );
   InsererLIdentificateurPredefini (
      new
         AppendPredef (& LanguePredefinis :: Append) );
   InsererLIdentificateurPredefini (
      new
         ConcatListesPredef (& LanguePredefinis :: ConcatListes) );
   InsererLIdentificateurPredefini (
      new
         LongueurListePredef (& LanguePredefinis :: LongueurListe) );

	}	//	AnalyseurSemantiqueLista :: InsererLesIdentificateursPredefinis


// -------------------------------------------------------------------------

OptionsSemantiquePTR
AnalyseurSemantiqueLista :: LesOptionsSemantique ()
	{ return fOptionsSemantique; }

TableDesSymbolesPTR
AnalyseurSemantiqueLista :: LaTableDesSymboles ()
	{ return fTableDesSymboles; }


// -------------------------------------------------------------------------

ListeDeParametresFormelsPTR
AnalyseurSemantiqueLista :: ListeDeParametresFormelsInconnus ()
	{ return fListeDeParametresFormelsInconnus; }


// -------------------------------------------------------------------------

void
AnalyseurSemantiqueLista :: ErreurSemantique (Chaine leMessage)
	{
	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatErreurSemantique (),
			DescriptionDeLaPositionCourante (),
			leMessage,
			DescriptionDuTerminalCourant () ) <<
		std::endl;

	fSourceCorrectSemantiquement = false;

	if (fOptionsSemantique -> SortirALaPremiereErreurSyntaxique ())
		SortieSurErreur (leMessage, 1);
	}


// -------------------------------------------------------------------------

void
AnalyseurSemantiqueLista :: AvertissementSemantique (Chaine leMessage)
	{
	if (!  fOptionsSemantique -> Traduire ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatAvertissementSemantique (),
				DescriptionDeLaPositionCourante (),
				leMessage,
				DescriptionDuTerminalCourant () ) <<
			std::endl;
	}


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurSemantiqueLista :: AccepterFacteurIdentificateurInconnu (
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
								FormatIdentNonDeclare (),
							nomIdentCourant ),
						gTypeInconnu );

	if (fOptionsSemantique -> MontrerLInferenceDeType ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatTypeLogiqueDIdentificateurNonDeclare (),
				leTypeLogique -> SousFormeDeChaine (),
				nomIdentCourant
				) <<
			std::endl;

	IdentNonDeclarePTR
				lIdentNonDeclare =
					new IdentNonDeclare (
						nomIdentCourant,
						MiseEnForme (
							gLANGUE_Semantique ->
								FormatNomQualifie (),
							fTableDesSymboles -> Sommet () -> Nom (),
							nomIdentCourant ),
						leTypeLogique );

	bool			dejaPresentAuSommet;
	IdentificateurPTR
					autreDeclarationMasquee = NULL;

	fTableDesSymboles ->
		InsererLIdentificateur (
			lIdentNonDeclare,
			dejaPresentAuSommet,
			autreDeclarationMasquee );

	return
		new ValeurInconnue (leTypeLogique);
			//	pour permettre l'inference du type
			//	de cet identificateur non declare
	}	// AnalyseurSemantiqueLista :: AccepterFacteurIdentificateurInconnu


// -------------------------------------------------------------------------

void
AnalyseurSemantiqueLista :: TesterLeTypeAttendu (
	TypePTR						typeAttendu,
	VariableLogiqueTypePTR	typeLogiqueTrouve,
	Chaine						entite )
	{
	Chaine	descrTypeLogiqueTrouve =
					typeLogiqueTrouve -> SousFormeDeChaine ();

	if (fOptionsSemantique -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatTestDeTypeAttendu (),
				typeAttendu -> SousFormeDeChaine (),
				descrTypeLogiqueTrouve ) <<
			std::endl;

	if (
		typeLogiqueTrouve ->
			UnifierValeur (
				typeAttendu,
				fOptionsSemantique -> MontrerLInferenceDeType () )
		)
		{
		// tout va bien
		}

	else
		{
		if (
			!
				typeAttendu -> ConversionAccepteeDUn (
					typeLogiqueTrouve -> ValeurDeLiaison ()
					)
			)
			{
			ErreurSemantique (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatEchecTestDeTypeAttendu (),
					entite,
					typeAttendu -> SousFormeDeChaine (),
					descrTypeLogiqueTrouve ));
			}
		}
	}	//	AnalyseurSemantiqueLista :: TesterLeTypeAttendu


// -------------------------------------------------------------------------

TypePTR
AnalyseurSemantiqueLista :: RecupererLeType (
	DescrSemantiquePTR	leGrapheSemantique,
	Chaine					genreIdentificateur )
	{
	TypePTR	res;

	if (leGrapheSemantique -> TypeLogique () -> EstLibre ())
		{
		ErreurSemantique (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatLeTypeNAPasPuEtreInfere (),
				genreIdentificateur ) );

		res = gTypeInconnu;
		}
	else
		res =
			leGrapheSemantique -> TypeLogique () -> ValeurDeLiaison ();

	return res;
	}	//	AnalyseurSemantiqueLista :: RecupererLeType


// -------------------------------------------------------------------------

void
AnalyseurSemantiqueLista :: RecupererLesTypesDesParametres (
	ListeDeParametresFormelsPTR
				laListeDeParametresFormels )
	{
	ListeDesDescrParametresPTR
				listeDesDescrParametres =
					laListeDeParametresFormels -> LaListeDesDescrParametres ();

	ListeDesDescrParametres :: iterator
				parametreCourant;

	for (
		parametreCourant = listeDesDescrParametres -> begin ();
		parametreCourant != listeDesDescrParametres -> end ();
		++ parametreCourant )
		{
		ParametreFormelPTR
					leParametreFormel =
						(* parametreCourant) -> ParametreFormel ();

		if (! leParametreFormel -> RecupererLeTypeInfere ())
			ErreurSemantique (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatLeTypeDuParametreFormelNAPasPuEtreInfere (),
					leParametreFormel -> NomQualifie () ));
		}	//	for
	}	//	AnalyseurSemantiqueLista :: RecupererLesTypesDesParametres


// -------------------------------------------------------------------------

void
AnalyseurSemantiqueLista :: IncrementerNiveauStatique ()
	{
	++ fNiveauStatiqueCourant;

	if (fOptionsSemantique -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatNiveauStatiqueIncremente (),
				fNiveauStatiqueCourant ) <<
			std::endl;
	}

void
AnalyseurSemantiqueLista :: DecrementerNiveauStatique ()
	{
	-- fNiveauStatiqueCourant;

	if (fOptionsSemantique -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatNiveauStatiqueDecremente (),
				fNiveauStatiqueCourant ) <<
			std::endl;
	}

int
AnalyseurSemantiqueLista :: NiveauStatiqueCourant ()
	{ return fNiveauStatiqueCourant; }


void
AnalyseurSemantiqueLista :: IncrementerNiveauDEvaluation ()
	{
	++ fNiveauDEvaluationCourant;

	if (fOptionsSemantique -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatNiveauDEvaluationIncremente (),
				fNiveauDEvaluationCourant ) <<
			std::endl;
	}

void
AnalyseurSemantiqueLista :: DecrementerNiveauDEvaluation ()
	{
	-- fNiveauDEvaluationCourant;

	if (fOptionsSemantique -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatNiveauDEvaluationDecremente (),
				fNiveauDEvaluationCourant ) <<
			std::endl;
	}

int
AnalyseurSemantiqueLista :: NiveauDEvaluationCourant ()
	{ return fNiveauDEvaluationCourant; }


// -------------------------------------------------------------------------

bool
AnalyseurSemantiqueLista :: SourceCorrectSemantiquement ()
	{ return fSourceCorrectSemantiquement; }


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

AnalyseurSemantiqueListaPTR	gAnalyseurSemantiqueLista	= NULL;;
