// =========================================================================
//	AnalyseurSemantiqueLista.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __AnalyseurSemantiqueLista__
#define __AnalyseurSemantiqueLista__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "FonctionsUtilisateur.h"

#if defined SYNTHESE_PILUM
//	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	AnalyseurSemantiqueLista
// -------------------------------------------------------------------------

class		AnalyseurSemantiqueLista;
typedef	AnalyseurSemantiqueLista	* AnalyseurSemantiqueListaPTR;

class AnalyseurSemantiqueLista
	{
public:
										AnalyseurSemantiqueLista (
											OptionsStrategiePTR			lesOptionsStrategie,
											OptionsSemantiquePTR			lesOptionsSemantique,
											OptionsEvaluationPTR			lesOptionsEvaluation
#if defined SYNTHESE_PILUM
										,	SynthetiseurPilumListaPTR	leSynthetiseurPilumLista
#endif /* SYNTHESE_PILUM */
											);
												
	virtual							~ AnalyseurSemantiqueLista ();


	//	Methodes pour l'analyse semantique
	//	----------------------------------
	
	OptionsSemantiquePTR			LesOptionsSemantique ();

	TableDesSymbolesPTR			LaTableDesSymboles ();

	ListeDeParametresFormelsPTR
										ListeDeParametresFormelsInconnus ();

	void								ErreurSemantique (Chaine leMessage);
	void								AvertissementSemantique (Chaine leMessage);

	DescrSemantiquePTR			AccepterFacteurIdentificateurInconnu (
											Chaine nomIdentCourant );

	void								TesterLeTypeAttendu (
											TypePTR						typeAttendu,
											VariableLogiqueTypePTR	typeLogiqueTrouve,
											Chaine						entite );

	TypePTR							RecupererLeType (
											DescrSemantiquePTR	leGrapheSemantique,
											Chaine					genreIdentificateur );

	void								RecupererLesTypesDesParametres (
											ListeDeParametresFormelsPTR
														laListeDeParametresFormels );

	void								IncrementerNiveauDEvaluation ();
	void								DecrementerNiveauDEvaluation ();
	int								NiveauDEvaluationCourant ();

	void								IncrementerNiveauStatique ();
	void								DecrementerNiveauStatique ();
	int								NiveauStatiqueCourant ();

	bool								SourceCorrectSemantiquement ();


	//	Methodes pour messages d'erreur et d'avertissement
	//	--------------------------------------------------

	virtual Chaine					DescriptionDuTerminalCourant () = 0;
											//	virtuelle pure
	virtual Chaine					DescriptionDeLaPositionCourante () = 0;
											//	virtuelle pure


protected:

	//	Analyse sémantique
	//	------------------

	OptionsStrategiePTR			fOptionsStrategie;
	OptionsSemantiquePTR			fOptionsSemantique;
	OptionsEvaluationPTR			fOptionsEvaluation;

	bool 								fSourceCorrectSemantiquement;

	void								InsererLesIdentificateursPredefinis ();

	void								InsererLIdentificateurPredefini (
											IdentPredefiniPTR lIdentPredefini );

	TableDesSymbolesPTR			fTableDesSymboles;
	
	ListeDeParametresFormelsPTR
										fListeDeParametresFormelsInconnus;

	int								fCompteurFonctions;
	int								fCompteurEvaluations;
	int								fCompteurIterations;

	int								fNiveauDEvaluationCourant;
	int								fNiveauStatiqueCourant;


	//	Synthese de code Pilum
	//	----------------------
	
#if defined SYNTHESE_PILUM
	SynthetiseurPilumListaPTR	fSynthetiseurPilumLista;
#endif /* SYNTHESE_PILUM */
	
	};	//	AnalyseurSemantiqueLista


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

extern AnalyseurSemantiqueListaPTR	gAnalyseurSemantiqueLista;
													// la partie commune aux analyseurs
													//	FlexBison et PredictifDescenteRecursive


#endif /* __AnalyseurSemantiqueLista__ */
