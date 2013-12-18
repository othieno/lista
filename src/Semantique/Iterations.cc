// =========================================================================
//	Iterations.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Iterations.h"

#include "LanguesSemantique.h"

#include "AnalyseurSemantiqueLista.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	IterateurPredef
// -------------------------------------------------------------------------

IterateurPredef :: IterateurPredef (
	ChaineLanguePredefinisPFM
									laFonctionNom,
	VariableLogiqueTypePTR	laVariableLogiqueType )
	: FonctionPredefinie (
		laFonctionNom,
		kIterateur, kIterateurFlexBison,
		laVariableLogiqueType)
	{
	fNombreDeParametres = 0;
	fTypesLogiquesDesParametres = NULL;
	}

Chaine
IterateurPredef :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatIterateurPredefini (),
			fNom,
			gLANGUE_Semantique ->
				IterationPredefinie (),
			DescriptionDesParametres (), 
			TypeIdentificateur () -> SousFormeDeChaine () );
	}	// IterateurPredef :: SousFormeDeChaine


// -------------------------------------------------------------------------
//	Les iterateurs predefinis
// -------------------------------------------------------------------------

SommePredef :: SommePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: IterateurPredef (laFonctionNom, gTypeLogiqueNombre)
	{
	fNombreDeParametres = 3;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [2] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
SommePredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{
	return gDescrSemantiqueInconnue;
		// est en fait cree par CreerGrapheIteration ()
	}

void
SommePredef :: TesterTypeExpressionIteree (
	VariableLogiqueTypePTR	leTypeLogiqueTrouve )
	{
	gAnalyseurSemantiqueLista -> TesterLeTypeAttendu (
		gTypeNombre,
		leTypeLogiqueTrouve,
		gLANGUE_Semantique ->
			ExpressionIteree () );
	}

DescrSemantiquePTR
SommePredef :: CreerGrapheIteration (
	IndiceIterationPTR	lIndice,
	DescrSemantiquePTR	* leBlocDArguments )
	{
	return new Somme (
		fNom,
		lIndice,
		leBlocDArguments [0], leBlocDArguments [1], leBlocDArguments [2],
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant () );
	}

// -------------------------------------------------------------------------

ProduitPredef :: ProduitPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: IterateurPredef (laFonctionNom, gTypeLogiqueNombre)
	{
	fNombreDeParametres = 3;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [2] = gTypeLogiqueNombre;
	}

DescrSemantiquePTR
ProduitPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{
	return gDescrSemantiqueInconnue;
		// est en fait cree par CreerGrapheIteration ()
	}

void
ProduitPredef :: TesterTypeExpressionIteree (
	VariableLogiqueTypePTR	leTypeLogiqueTrouve )
	{
	gAnalyseurSemantiqueLista -> TesterLeTypeAttendu (
		gTypeNombre,
		leTypeLogiqueTrouve, 
		gLANGUE_Semantique ->
			ExpressionIteree () );
	}

DescrSemantiquePTR
ProduitPredef :: CreerGrapheIteration (
	IndiceIterationPTR	lIndice,
	DescrSemantiquePTR	* leBlocDArguments )
	{
	return new Produit (
		fNom,
		lIndice,
		leBlocDArguments [0], leBlocDArguments [1], leBlocDArguments [2],
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant () );
	}

// -------------------------------------------------------------------------

PourPredef :: PourPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: IterateurPredef (laFonctionNom, gTypeLogiqueVide)
	{
	fNombreDeParametres = 3;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNombre;
	fTypesLogiquesDesParametres [2] = gTypeLogiqueNonPrecise;
	}

DescrSemantiquePTR
PourPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{
	return gDescrSemantiqueInconnue;
		// est en fait cree par CreerGrapheIteration ()
	}

void
PourPredef :: TesterTypeExpressionIteree (
	VariableLogiqueTypePTR	leTypeLogiqueTrouve )
	{}

DescrSemantiquePTR
PourPredef :: CreerGrapheIteration (
	IndiceIterationPTR	lIndice,
	DescrSemantiquePTR	* leBlocDArguments )
	{
	return new Pour (
		fNom,
		lIndice,
		leBlocDArguments [0], leBlocDArguments [1], leBlocDArguments [2],
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant () );
	}


// -------------------------------------------------------------------------
//	IndiceIteration
// -------------------------------------------------------------------------

IndiceIteration :: IndiceIteration (
	Chaine						leNom,
	Chaine						leNomQualifie,
	VariableLogiqueTypePTR	laVariableLogiqueType )
	: Identificateur (
		leNom, leNomQualifie, kIdentIndiceIteration, kAutreIdentificateurFlexBison,
		laVariableLogiqueType )
	{
	fNiveauDEvaluation	=
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant ();
	fNiveauStatique		=
		gAnalyseurSemantiqueLista -> NiveauStatiqueCourant ();
	}

Chaine 
IndiceIteration :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatIndiceDIterationSousFormeDeChaine (),
			fNomQualifie,
			fNiveauDEvaluation,
			fNiveauStatique,
			fTypeIdentificateur -> SousFormeDeChaine () );
	}

int 
IndiceIteration :: NiveauStatique ()
	{ return fNiveauStatique; }

int 
IndiceIteration :: NiveauDEvaluation ()
	{ return fNiveauDEvaluation; }

#if defined SYNTHESE_PILUM

void 
IndiceIteration :: PositionDansLeBloc (long laPosition)
	{ fPositionDansLeBloc = laPosition; }

long
IndiceIteration :: PositionDansLeBloc ()
	{ return fPositionDansLeBloc; }

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	AssocArgumentParametreIndiceIteration
// -------------------------------------------------------------------------

AssocArgumentParametreIndiceIteration :: AssocArgumentParametreIndiceIteration (
	IndiceIterationPTR		lIndiceIteration,
	ContexteDEvaluationPTR	leContexteDEvaluation,
	ValeurLista					laValeurInitiale )
	:	AssocArgumentParametre (
			lIndiceIteration -> Nom (), lIndiceIteration -> NomQualifie (),
			1, leContexteDEvaluation )
	{ fValeurIndice = laValeurInitiale; }

AssocArgumentParametreIndiceIteration :: ~ AssocArgumentParametreIndiceIteration ()
	{}

ValeurLista 
AssocArgumentParametreIndiceIteration :: ValeurCourante ()
	{ return fValeurIndice; }

void 
AssocArgumentParametreIndiceIteration :: Incrementer ()
	{ fValeurIndice.fNombre += 1; }

void 
AssocArgumentParametreIndiceIteration :: Ecrire (int lIndentation)
	{
	Indenter (lIndentation);
	std::cout <<
		gLANGUE_Semantique ->
			IndiceDIteration ();
	fValeurIndice.Ecrire (lIndentation);
	}

ValeurLista	AssocArgumentParametreIndiceIteration :: Evaluer (int lIndentation)
	{
	if (fContexteDEvaluation -> TraceDEvaluation ())
		{
		Indenter (lIndentation);
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatConsultationIndiceDIteration (),
				fNomQualifie,
				fContexteDEvaluation -> NumeroContexteDEvaluation ()) <<
			std::endl;

		Indenter (lIndentation);
		std::cout <<
			gLANGUE_Semantique ->
				ResultatEvaluation ();
		fValeurIndice.Ecrire (lIndentation);
		std::cout <<
			std::endl;
		}

	return fValeurIndice;
	}	// AssocArgumentParametreIndiceIteration :: Evaluer


// -------------------------------------------------------------------------
//	EmploiIndiceIteration
// -------------------------------------------------------------------------

EmploiIndiceIteration :: EmploiIndiceIteration (
	IndiceIterationPTR	lIndiceIteration )
	:	DescrSemantique (lIndiceIteration -> VariableLogiqueType ())
	{
	fIndiceIteration = lIndiceIteration;

	fNiveauDEvaluation	=
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant ();
	fNiveauStatique		=
		gAnalyseurSemantiqueLista -> NiveauStatiqueCourant ();
	}

int 
EmploiIndiceIteration :: NiveauDEvaluation ()
	{ return fNiveauDEvaluation; }

void 
EmploiIndiceIteration :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);
	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatEmploiIndiceDIteration (),
			fIndiceIteration -> NomQualifie (),
			fNiveauDEvaluation,
			fNiveauStatique ) <<
		std::endl;
	}

ValeurLista 
EmploiIndiceIteration :: Evaluer (
	ContexteDEvaluationPTR leContexteDEvaluation )
	{
	int			differenceDeNiveauDEvaluation =
						fNiveauDEvaluation - fIndiceIteration -> NiveauDEvaluation ();

	//	on cherche le contexte de definition de cet indice

	ContexteDEvaluationPTR
				curseur = leContexteDEvaluation;

	for (int i = 1; i <= differenceDeNiveauDEvaluation; ++ i)
		{
		if (curseur == NULL)
			SortieSurErreur (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatEmploiIndiceDIterationDifferenceDEvaluationTropGrande (),
					differenceDeNiveauDEvaluation ),
				1 );

		curseur = curseur -> LienStatique ();
		}	// for

	return
		curseur ->
			BlocDAssociations () [0] ->
				Evaluer (leContexteDEvaluation -> Indentation ());
	}	//	EmploiIndiceIteration :: Evaluer

#if defined SYNTHESE_PILUM

void 
EmploiIndiceIteration :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	//	tous les indices sont au niveau local

	//	on fait charger la valeur de l'indice:

	int			differenceDeNiveauStatique =
					fNiveauStatique - fIndiceIteration -> NiveauStatique ();

	synth -> AccesCellulePourValeur (
		differenceDeNiveauStatique,
		fIndiceIteration -> PositionDansLeBloc () );
	if (leContexteDeSynthese -> OptionsSynthese () -> CommenterLeCode ())
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatEmploiIndiceDIterationDansSynthese (),
				fIndiceIteration -> NomQualifie (),
				fNiveauDEvaluation,
				fNiveauStatique ));

	}	//	EmploiIndiceIteration :: Synthetiser

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Iteration
// -------------------------------------------------------------------------

Iteration :: Iteration (
	Chaine						leSousFormeTexte,
	IndiceIterationPTR		lIndice,
	DescrSemantiquePTR		laBorneInf,
	DescrSemantiquePTR		laBorneSup,
	DescrSemantiquePTR		lExpression,
	VariableLogiqueTypePTR	leTypeLogique,
	int						leNiveauDEvaluation )
	:	DescrSemantique (leTypeLogique)
	{
	fSousFormeTexte = leSousFormeTexte;
	fIndice = lIndice;
	fBorneInf = laBorneInf;
	fBorneSup = laBorneSup;
	fExpression = lExpression;
	fNiveauDEvaluation = leNiveauDEvaluation;
	}


void 
Iteration :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);

	std::cout <<
		fSousFormeTexte <<
		std::endl;

	Indenter (lIndentation + 1);
	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatIndiceDIteration (),
			fIndice -> NomQualifie (),
			fIndice -> NiveauDEvaluation (),
			fIndice -> NiveauStatique () ) <<
		std::endl;

	fBorneInf -> Ecrire (lIndentation + 1);
	fBorneSup -> Ecrire (lIndentation + 1);
	fExpression -> Ecrire (lIndentation + 1);
	}

void 
Iteration :: PostFixer ()
	{
	fBorneInf -> PostFixer ();
	fBorneSup -> PostFixer ();

	std::cout << 
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatIndiceDIterationPostFixe (),
			fIndice -> NomQualifie () ) <<
		std::endl;

	fExpression -> PostFixer ();

	std::cout <<
		"\t" <<
		fSousFormeTexte <<
		std::endl;
	}

int 
Iteration :: NiveauDEvaluation ()
	{ return fNiveauDEvaluation; }


ValeurLista 
Iteration :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	AssocArgumentParametrePTR
				* blocDAssociations =
					new AssocArgumentParametrePTR [1];

	int		differenceDeNiveauDEvaluation =
					gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant ()
						-
					fNiveauDEvaluation;

	ContexteDEvaluationPTR
				leContexteDEvaluationDeLIteration =
					new ContexteDEvaluation (
						blocDAssociations,
						1,
						leContexteDEvaluation -> TraceDEvaluation (),
						leContexteDEvaluation -> CourtCircuitLogiquesBinaires (),
						leContexteDEvaluation -> Indentation () + 1,
						leContexteDEvaluation -> RemonteeStatique (
							differenceDeNiveauDEvaluation ),
						leContexteDEvaluation );

	AssocArgumentParametreIndiceIterationPTR
				lAssocArgumentParametreIndiceIteration =
					new AssocArgumentParametreIndiceIteration (
						fIndice,
						leContexteDEvaluationDeLIteration,
						fBorneInf -> Evaluer (leContexteDEvaluation) );

	blocDAssociations [0] =
		lAssocArgumentParametreIndiceIteration;

	ValeurLista			
				borneSup =
					fBorneSup -> Evaluer (leContexteDEvaluation);

	ActionAvantEvaluations ();

	while (
		lAssocArgumentParametreIndiceIteration -> ValeurCourante ().fNombre
		<=
		borneSup.fNombre
		)
		{
		ActionAChaqueEvaluation (leContexteDEvaluationDeLIteration);
		lAssocArgumentParametreIndiceIteration -> Incrementer ();
		}

	ActionApresEvaluations ();

	delete leContexteDEvaluationDeLIteration;
	delete [] blocDAssociations;

	return fResultat;
	}	//	Iteration :: Evaluer


#if defined SYNTHESE_PILUM

void 
Iteration :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	//	tous les indices sont au niveau local
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	Chaine	leNom = fIndice -> Nom ();

	DescrBlocDActivationPTR
				laDescrBlocDActivation =
					leContexteDeSynthese -> DescrBlocDActivation ();

	VariableLogiqueEtiquettePTR
				etiquetteDebut =
					synth -> CreerEtiquette (
						gLANGUE_Semantique ->
							EtiquetteDebutDIteration () );
	VariableLogiqueEtiquettePTR
				etiquetteSuite =
					synth -> CreerEtiquette (
						gLANGUE_Semantique ->
							EtiquetteSuiteDIteration () );

	ActionAvantSyntheses (leContexteDeSynthese);

	int		positionIndice =
					laDescrBlocDActivation -> AllouerTemporaire ();
	int		positionBorne =
					laDescrBlocDActivation -> AllouerTemporaire ();

	bool		commenterLeCode =
					leContexteDeSynthese -> 
						OptionsSynthese () -> CommenterLeCode ();

	fIndice -> PositionDansLeBloc (positionIndice);


	//	on affecte la borne inferieure a l'indice

	synth -> AccesCellulePourAdresse (0, positionIndice);
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatAdresseIndiceDIteration (),
				leNom ));

	fBorneInf -> Synthetiser (leContexteDeSynthese);

	synth -> Zeroadique (iStocker);
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatValeurInitialeIndiceDIteration (),
				leNom ));


	//	on stocke la borne superieure de l'indice

	synth -> AccesCellulePourAdresse (0, positionBorne);
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatAdresseBorneDeLIndiceDIteration (),
				leNom ));

	fBorneSup -> Synthetiser (leContexteDeSynthese);

	synth -> Zeroadique (iStocker);
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatValeurInitialeDeLaBorneDIteration (),
				leNom ));


	//	debut de la boucle
	
	synth -> PlacerEtiquette (etiquetteDebut);

	synth -> AccesCellulePourValeur (0, positionIndice);
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatValeurIndiceDIteration (),
				leNom ));

	synth -> AccesCellulePourValeur (0, positionBorne);
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatValeurBorneDeLIndiceDIteration (),
				leNom ));


	synth -> Zeroadique (iInfEgaleFlottant);
	synth -> Saut (iSauterSiFaux, etiquetteSuite);
	
	ActionAvantChaqueSynthese (leContexteDeSynthese);

	fExpression -> Synthetiser (leContexteDeSynthese);
	
	ActionApresChaqueSynthese (leContexteDeSynthese);

	synth -> AccesCellulePourAdresse (0, positionIndice);
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatAdresseIndiceDIteration (),
				leNom ));

	synth -> Zeroadique (iIncrFlottant);
	if (commenterLeCode)
		synth -> Commentaire (
			MiseEnForme (
				gLANGUE_Semantique ->
					FormaIncrementationIndiceDIteration (),
				leNom ));

	synth -> Saut (iSauter, etiquetteDebut);
	

	synth -> PlacerEtiquette (etiquetteSuite);

	laDescrBlocDActivation -> LibererTemporaire ();	//	indice
	laDescrBlocDActivation -> LibererTemporaire ();	//	borne

	ActionApresSyntheses (leContexteDeSynthese);

	}	//	Iteration :: Synthetiser	

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Somme
// -------------------------------------------------------------------------

Somme :: Somme (
	Chaine					leNom,
	IndiceIterationPTR	lIndice,
	DescrSemantiquePTR	laBorneInf,
	DescrSemantiquePTR	laBorneSup,
	DescrSemantiquePTR	lExpression,
	int						leNiveauDEvaluation )
	:	Iteration (
			leNom,
			lIndice, laBorneInf, laBorneSup, lExpression,
			gTypeLogiqueNombre,
			leNiveauDEvaluation )
	{}

void 
Somme :: ActionAvantEvaluations ()
	{ fSomme = 0; }

void 
Somme :: ActionAChaqueEvaluation (ContexteDEvaluationPTR leContexteDEvaluation)
	{ fSomme += fExpression -> Evaluer (leContexteDEvaluation).fNombre; }

void 
Somme :: ActionApresEvaluations ()
	{ fResultat = ValeurLista (fSomme); }

#if defined SYNTHESE_PILUM

//	toutes les sommes sont au niveau local

void 
Somme :: ActionAvantSyntheses (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fPositionSomme =
		leContexteDeSynthese -> DescrBlocDActivation () -> AllouerTemporaire ();

	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	synth -> AccesCellulePourAdresse (0, fPositionSomme);
	if (leContexteDeSynthese -> OptionsSynthese () -> CommenterLeCode ())
		synth -> Commentaire (
			gLANGUE_Semantique ->
				AdresseDeLaSomme () );
	synth -> Flottant (0);
	synth -> Zeroadique (iStocker);
	}

void 
Somme :: ActionAvantChaqueSynthese (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	bool		commenterLeCode = leContexteDeSynthese -> 
					OptionsSynthese () -> CommenterLeCode ();

	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				DebutDeSomme () );

	synth -> AccesCellulePourAdresse (0, fPositionSomme);
	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				AdresseDeLaSomme () );
	}

void 
Somme :: ActionApresChaqueSynthese (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();
	bool		commenterLeCode =
					leContexteDeSynthese -> 
						OptionsSynthese () -> CommenterLeCode ();

	synth -> AccesCellulePourValeur (0, fPositionSomme);
	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				ValeurDeLaSomme () );
	synth -> Zeroadique (iPlusFlottant);
	synth -> Zeroadique (iStocker);
	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				CumulDansLaSomme () );
	}

void 
Somme :: ActionApresSyntheses (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();
	bool		commenterLeCode =
					leContexteDeSynthese -> OptionsSynthese () ->
						CommenterLeCode ();

	synth -> AccesCellulePourValeur (0, fPositionSomme);
	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				ValeurDeLaSommeResultante () );

	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				FinDeSomme () );

	leContexteDeSynthese ->
		DescrBlocDActivation () -> LibererTemporaire ();
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Produit
// -------------------------------------------------------------------------

Produit :: Produit (
	Chaine					leNom,
	IndiceIterationPTR	lIndice,
	DescrSemantiquePTR	laBorneInf,
	DescrSemantiquePTR	laBorneSup,
	DescrSemantiquePTR	lExpression,
	int						leNiveauDEvaluation )
	:	Iteration (
			leNom,
			lIndice, laBorneInf, laBorneSup, lExpression,
			gTypeLogiqueNombre,
			leNiveauDEvaluation )
	{}

void 
Produit :: ActionAvantEvaluations ()
	{ fProduit = 1; }

void 
Produit :: ActionAChaqueEvaluation (ContexteDEvaluationPTR leContexteDEvaluation)
	{ fProduit *= fExpression -> Evaluer (leContexteDEvaluation).fNombre; }

void 
Produit :: ActionApresEvaluations ()
	{ fResultat = ValeurLista (fProduit); }

#if defined SYNTHESE_PILUM

//	tous les produits sont au niveau local

void 
Produit :: ActionAvantSyntheses (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fPositionProduit =
		leContexteDeSynthese -> DescrBlocDActivation () -> AllouerTemporaire ();

	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	synth -> AccesCellulePourAdresse (0, fPositionProduit);
	if (leContexteDeSynthese -> OptionsSynthese () -> CommenterLeCode ())
		synth -> Commentaire (
			gLANGUE_Semantique ->
				AdresseDuProduit () );
	synth -> Flottant (1);
	synth -> Zeroadique (iStocker);
	}

void 
Produit :: ActionAvantChaqueSynthese (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();
	bool		commenterLeCode =
					leContexteDeSynthese -> OptionsSynthese () ->
						CommenterLeCode ();

	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				DebutDeProduit () );

	synth -> AccesCellulePourAdresse (0, fPositionProduit);
	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				AdresseDuProduit () );
	}

void 
Produit :: ActionApresChaqueSynthese (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();
	bool		commenterLeCode =
					leContexteDeSynthese -> OptionsSynthese () ->
						CommenterLeCode ();


	synth -> AccesCellulePourValeur (0, fPositionProduit);
	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				ValeurDuProduit () );
	synth -> Zeroadique (iFoisFlottant);
	synth -> Zeroadique (iStocker);
	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				CumulDansLeProduit () );
	}

void 
Produit :: ActionApresSyntheses (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();
	bool		commenterLeCode =
					leContexteDeSynthese -> OptionsSynthese () ->
						CommenterLeCode ();


	synth -> AccesCellulePourValeur (0, fPositionProduit);
	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				ValeurDuProduit () );

	if (commenterLeCode)
		synth -> Commentaire (
			gLANGUE_Semantique ->
				FinDeProduit () );

	leContexteDeSynthese ->
		DescrBlocDActivation () -> LibererTemporaire ();
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	Pour
// -------------------------------------------------------------------------

Pour :: Pour (
	Chaine					leNom,
	IndiceIterationPTR	lIndice,
	DescrSemantiquePTR	laBorneInf,
	DescrSemantiquePTR	laBorneSup,
	DescrSemantiquePTR	lExpression,
	int						leNiveauDEvaluation )
	:	Iteration (
			leNom,
			lIndice, laBorneInf, laBorneSup, lExpression,
			gTypeLogiqueVide,
			leNiveauDEvaluation )
	{}

void 
Pour :: ActionAvantEvaluations ()
	{}

void 
Pour :: ActionAChaqueEvaluation (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	fExpression -> Evaluer (leContexteDEvaluation);
		//	on jette la valeur resultante
	}

void 
Pour :: ActionApresEvaluations ()
	{}

#if defined SYNTHESE_PILUM

void 
Pour :: ActionAvantSyntheses (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	if (leContexteDeSynthese -> OptionsSynthese () -> CommenterLeCode ())
		leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
			Commentaire (
				gLANGUE_Semantique ->
					DebutDePour () );
	}

void 
Pour :: ActionAvantChaqueSynthese (ContexteDeSynthesePTR leContexteDeSynthese)
	{}

void 
Pour :: ActionApresChaqueSynthese (ContexteDeSynthesePTR leContexteDeSynthese)
	{}

void 
Pour :: ActionApresSyntheses (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	if (leContexteDeSynthese -> OptionsSynthese () -> CommenterLeCode ())
		leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
			Commentaire (
				gLANGUE_Semantique ->
					FinDePour () );
	}

#endif /* SYNTHESE_PILUM */
