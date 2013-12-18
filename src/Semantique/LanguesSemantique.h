// =========================================================================
//	LanguesSemantique.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __LanguesSemantique__
#define __LanguesSemantique__


#include "Types.h"

#include "LanguesPredefinis.h"

#include "LanguesSyntaxe.h"


// -------------------------------------------------------------------------
//	LangueSemantique
// -------------------------------------------------------------------------

class		LangueSemantique;
typedef	LangueSemantique		* LangueSemantiquePTR;

class LangueSemantique
	{
public:
										LangueSemantique ();

	virtual							~ LangueSemantique ();


	//	Semantique
	// -------------------------------------------------------------------------

	virtual Chaine					FormatNomQualifie () = 0;
											// virtuelle pure

	virtual Chaine					ConstantePredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FonctionPredefinie () = 0;
											// virtuelle pure
	virtual Chaine					IterationPredefinie () = 0;
											// virtuelle pure

	virtual Chaine					NonUtilise () = 0;
											// virtuelle pure

	virtual Chaine					FormatContenuDuDictionnaire () = 0;
											// virtuelle pure
	virtual Chaine					FormatPurgeDuDictionnaireVide () = 0;
											// virtuelle pure
	virtual Chaine					FormatPurgeDuDictionnaire () = 0;
	
											// virtuelle pure
	virtual Chaine					FormatEmpilageNiveauDeDeclaration () = 0;
											// virtuelle pure
	virtual Chaine					FormatDesempilageNiveauDeDeclaration () = 0;
											// virtuelle pure
											
	virtual Chaine					TableDesSymbolesVide () = 0;
											// virtuelle pure
	virtual Chaine					FormatTableDesSymboles () = 0;
											// virtuelle pure

	virtual Chaine					FormatIdentNonDeclare () = 0;
											// virtuelle pure
	virtual Chaine					FormatIdentNonDeclareSousFormeDeChaine () = 0;
											// virtuelle pure
	virtual Chaine					FacteurIdentificateurMalForme () = 0;
											// virtuelle pure
	virtual Chaine					FormatIdentDeFonctionNonDeclare () = 0;
											// virtuelle pure

	virtual Chaine					FormatConstantePredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FormatFonctionPredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FormatIterateurPredefini () = 0;
											// virtuelle pure

	virtual Chaine					FormatParametreFormel () = 0;
											// virtuelle pure

	virtual Chaine					FormatErreurCommeNombre () = 0;
											// virtuelle pure
	virtual Chaine					FormatErreurCommeBooleen () = 0;
											// virtuelle pure
	virtual Chaine					FormatErreurCommeChaine () = 0;
											// virtuelle pure
	virtual Chaine					FormatErreurTypeValeurLista () = 0;
											// virtuelle pure

	virtual Chaine					ParValeur () = 0;
											// virtuelle pure
	virtual Chaine					ParNom () = 0;
											// virtuelle pure
	virtual Chaine					ParBesoin () = 0;
											// virtuelle pure

	virtual Chaine					DelimiteurDeFonctionsEtEvaluations () = 0;
											// virtuelle pure
	virtual Chaine					SeparationDernierParametre () = 0;
											// virtuelle pure

	virtual Chaine					FormatFonctionUtilisateur () = 0;
											// virtuelle pure
	virtual Chaine					FormatBesoinDUnLienStatique () = 0;
											// virtuelle pure


	virtual Chaine					FormatParametreParValeur () = 0;
											// virtuelle pure
	virtual Chaine					FormatConsultationParametreParValeur () = 0;
											// virtuelle pure

	virtual Chaine					FormatParametreParNom () = 0;
											// virtuelle pure
	virtual Chaine					FormatEvaluationParametreParNom () = 0;
											// virtuelle pure

	virtual Chaine					ResultatEvaluation () = 0;
											// virtuelle pure

	virtual Chaine					FormatParametreParBesoinNonEvalue () = 0;
											// virtuelle pure
	virtual Chaine					ParametreParBesoinDejaEvalue () = 0;
											// virtuelle pure
	virtual Chaine					FormatEvaluationParametreParBesoin () = 0;
											// virtuelle pure
	virtual Chaine					FormatConsultationParametreParBesoin () = 0;
											// virtuelle pure

	virtual Chaine					FormatContexteDEvaluation () = 0;
											// virtuelle pure

	virtual Chaine					FormatRemonteeStatique () = 0;
											// virtuelle pure

	virtual Chaine					FormatTempsDEvaluationDirecte () = 0;
											// virtuelle pure

	virtual Chaine					ContinuationApresOperandeGauche () = 0;
											// virtuelle pure
	virtual Chaine					ContinuationApresOperandeDroit () = 0;
											// virtuelle pure
	virtual Chaine					OnJetteLOperandeDroitDeSeq1 () = 0;
											// virtuelle pure
	virtual Chaine					SeqImplicite () = 0;
											// virtuelle pure

	virtual Chaine					ValeurInconnue () = 0;
											// virtuelle pure
	virtual Chaine					ValeurVide () = 0;
											// virtuelle pure

	virtual Chaine					ArgumentDAppel () = 0;
											// virtuelle pure

	virtual Chaine					FormatTropDArgumentsDansAppelAPredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FormatTropPeuDArgumentsDansAppelAPredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FormatTropDArgumentsDansAppelAFonctionParametree () = 0;
											// virtuelle pure
	virtual Chaine					FormatTropPeuDArgumentsDansAppelAFonctionParametree () = 0;
											// virtuelle pure

	virtual Chaine					FormatNomDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatNumeroDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatNomDeParametre () = 0;
											// virtuelle pure
	virtual Chaine					FormatNumeroDeParametre () = 0;
											// virtuelle pure
	virtual Chaine					FormatNumeroDEvaluation () = 0;
											// virtuelle pure

	virtual Chaine					FormatTypeLogiqueDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatTypeLogiqueDeParametre () = 0;
											// virtuelle pure
	virtual Chaine					FormatTypeLogiqueDIdentificateurNonDeclare () = 0;
											// virtuelle pure
	virtual Chaine					FormatTypeLogiqueDeFonctionNonDeclaree () = 0;
											// virtuelle pure

	virtual Chaine					FormatRedefinitionDeFonctionUtilisateur () = 0;
											// virtuelle pure
	virtual Chaine					FormatDefinitionDeFonctionUtilisateurMasque () = 0;
											// virtuelle pure

	virtual Chaine					FormatRedefinitionDeParametre () = 0;
											// virtuelle pure
	virtual Chaine					FormatDefinitionDeParametreMasque () = 0;
											// virtuelle pure

	virtual Chaine					FormatAucuneDeclarationAccessible () = 0;
											// virtuelle pure

	virtual Chaine					ConditionDUnSi () = 0;
											// virtuelle pure
	virtual Chaine					FormatAlternativesDUnSiPasDuMemeType () = 0;
											// virtuelle pure

	virtual Chaine					GrapheSemantiqueDeLaSequenceDExpressionsAEvaluer () = 0;
											// virtuelle pure
	virtual Chaine					FormePostfixeeDeLaSequenceDExpressionsAEvaluer () = 0;
											// virtuelle pure

	virtual Chaine					FormatIteration () = 0;
											// virtuelle pure
	virtual Chaine					BorneInferieure () = 0;
											// virtuelle pure
	virtual Chaine					BorneSuperieure () = 0;
											// virtuelle pure
	virtual Chaine					ExpressionIteree () = 0;
											// virtuelle pure

	virtual Chaine					IndiceInconnu () = 0;
											// virtuelle pure
	virtual Chaine					IdentAttenduCommeIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatVirguleAttendueApresLIndice () = 0;
											// virtuelle pure
	virtual Chaine					FormatVirguleAttendueApresLaBorneInferieure () = 0;
											// virtuelle pure
	virtual Chaine					FormatVirguleAttendueApresLaBorneSuperieure () = 0;
											// virtuelle pure
	virtual Chaine					FormatRedefinitionDeLIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatDefinitionDeLIndiceDIterationMasque () = 0;
											// virtuelle pure
	virtual Chaine					FormatParentheseInattendueDansAppelAFonctionNonParametree () = 0;
											// virtuelle pure
	virtual Chaine					FormatEmpilageDescrAppelDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatDesempilageDescrAppelDeFonction () = 0;
											// virtuelle pure

	virtual Chaine					FormatCreationDescrAppelDeFonctionPredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FormatEnregistrementArgumentDeFonctionPredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FormatVerifierSiPasTropDArgumentsPourFonctionPredefinie () = 0;
											// virtuelle pure
	virtual Chaine					FormatVerifierSiAssezDArgumentsPourFonctionPredefinie () = 0;
											// virtuelle pure

	virtual Chaine					FormatCreationDescrAppelIteration () = 0;
											// virtuelle pure

	virtual Chaine					FormatCreationDescrAppelFonctionUtilisateur () = 0;
											// virtuelle pure
	virtual Chaine					FormatVerifierSiPasTropDArgumentsPourFonctionUtilisateur () = 0;
											// virtuelle pure
	virtual Chaine					FormatVerifierSiAssezDArgumentsPourFonctionUtilisateur () = 0;
											// virtuelle pure

	virtual Chaine					FormatCreationDescrAppelFonctionErronee () = 0;
											// virtuelle pure

	virtual Chaine					ValeurInconnueNEstPasEvaluable () = 0;
											// virtuelle pure

	virtual Chaine					OnJetteLOperandeDeGaucheDeSeq () = 0;
											// virtuelle pure

	virtual Chaine					FormatEcritureAppelDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatEcritureEmploiParametre () = 0;
											// virtuelle pure

	virtual Chaine					FormatEmploiParametreDifferenceStatiqueTropGrande () = 0;
											// virtuelle pure
	virtual Chaine					FormatDescripteurDuParametreParNom () = 0;
											// virtuelle pure
	virtual Chaine					FormatDescripteurDuParametreParBesoin () = 0;
											// virtuelle pure
	virtual Chaine					FormatAdresseDuResultatDe () = 0;
											// virtuelle pure
	virtual Chaine					EtiquetteIntermediaireParBesoin () = 0;
											// virtuelle pure
	virtual Chaine					FormatAdresseDuBooleenDeControleParBesoin () = 0;
											// virtuelle pure
	virtual Chaine					FormatValeurDuBooleenDeControleParBesoin () = 0;
											// virtuelle pure
	virtual Chaine					FormatValeurParBesoin () = 0;
											// virtuelle pure

	virtual Chaine					FormatAppelALaFonctionSansArguments () = 0;
											// virtuelle pure
	virtual Chaine					FormatAppelALaFonctionAvecArguments () = 0;
											// virtuelle pure
	virtual Chaine					FormatResultatDeLAppelALaFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatSortieDeLAppelALaFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatLienStatiquePourAppelALaFonction () = 0;
											// virtuelle pure

	virtual Chaine					EtiquetteSiFaux () = 0;
											// virtuelle pure
	virtual Chaine					EtiquetteSuiteDuSi () = 0;
											// virtuelle pure
	virtual Chaine					EtiquetteContinuationDeLaContinuationDuSi () = 0;
											// virtuelle pure

	virtual Chaine					FormatDebutDuCorpsDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatLienStatiqueNecessairePourFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatFinDuCorpsDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatGrapheSemantiqueDuCoprsDUneFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatFormePostfixeeDuCoprsDUneFonction () = 0;
											// virtuelle pure

	virtual Chaine					EtiquetteCorpsDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					EtiquetteSuiteDeCorpsDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					EtiquetteContinuationDuCorpsDeFonction () = 0;
											// virtuelle pure

	virtual Chaine					DebutDUneEvaluation () = 0;
											// virtuelle pure
	virtual Chaine					EtiquetteContinuationDUneEvaluation () = 0;
											// virtuelle pure
	virtual Chaine					FinDUneEvaluation () = 0;
											// virtuelle pure

	virtual Chaine					EtiquetteDeCorpsDeThunk () = 0;
											// virtuelle pure
	virtual Chaine					FormatDebutDuCorpsDeThunk () = 0;
											// virtuelle pure
	virtual Chaine					FormatLienStatiqueNecessairePourThunk () = 0;
											// virtuelle pure
	virtual Chaine					FormatLienMarqueDeBlocDActivation () = 0;
											// virtuelle pure
	virtual Chaine					FormatFinDuCorpsDeThunk () = 0;
											// virtuelle pure

	virtual Chaine					EtiquetteSuiteDeCorpsDeThunk () = 0;
											// virtuelle pure
	virtual Chaine					EtiquetteContinuationDuCorpsDeThunk () = 0;
											// virtuelle pure

	virtual Chaine					FormatIndiceDIterationSousFormeDeChaine () = 0;
											// virtuelle pure
	virtual Chaine					IndiceDIteration () = 0;
											// virtuelle pure

	virtual Chaine					FormatConsultationIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatEmploiIndiceDIteration () = 0;
											// virtuelle pure

	virtual Chaine					FormatEmploiIndiceDIterationDifferenceDEvaluationTropGrande () = 0;
											// virtuelle pure
	virtual Chaine					FormatEmploiIndiceDIterationDansSynthese () = 0;
											// virtuelle pure

	virtual Chaine					FormatIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatIndiceDIterationPostFixe () = 0;
											// virtuelle pure

	virtual Chaine					EtiquetteDebutDIteration () = 0;
											// virtuelle pure
	virtual Chaine					EtiquetteSuiteDIteration () = 0;
											// virtuelle pure

	virtual Chaine					FormatAdresseIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatValeurIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatValeurInitialeIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatAdresseBorneDeLIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatValeurBorneDeLIndiceDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormatValeurInitialeDeLaBorneDIteration () = 0;
											// virtuelle pure
	virtual Chaine					FormaIncrementationIndiceDIteration () = 0;
											// virtuelle pure

	virtual Chaine					AdresseDeLaSomme () = 0;
											// virtuelle pure
	virtual Chaine					ValeurDeLaSomme () = 0;
											// virtuelle pure
	virtual Chaine					CumulDansLaSomme () = 0;
											// virtuelle pure
	virtual Chaine					ValeurDeLaSommeResultante () = 0;
											// virtuelle pure
	virtual Chaine					DebutDeSomme () = 0;
											// virtuelle pure
	virtual Chaine					FinDeSomme () = 0;
											// virtuelle pure

	virtual Chaine					AdresseDuProduit () = 0;
											// virtuelle pure
	virtual Chaine					ValeurDuProduit () = 0;
											// virtuelle pure
	virtual Chaine					CumulDansLeProduit () = 0;
											// virtuelle pure
	virtual Chaine					ValeurDuProduitResultant () = 0;
											// virtuelle pure
	virtual Chaine					DebutDeProduit () = 0;
											// virtuelle pure
	virtual Chaine					FinDeProduit () = 0;
											// virtuelle pure

	virtual Chaine					DebutDePour () = 0;
											// virtuelle pure
	virtual Chaine					FinDePour () = 0;
											// virtuelle pure


	virtual Chaine					NiveauDesPredefinis () = 0;
											// virtuelle pure
	virtual Chaine					NiveauPrincipal () = 0;
											// virtuelle pure

	virtual Chaine					FormatPasageDesParametres () = 0;
											// virtuelle pure

	virtual Chaine					CourtCircuitDesOperateursBinaires () = 0;
											// virtuelle pure

	virtual Chaine					TypeParametreFictifPourRattrapageDErreurs () = 0;
											// virtuelle pure

	virtual Chaine					NomParametreInconnu () = 0;
											// virtuelle pure
	virtual Chaine					NomQualifieParametreInconnu () = 0;
											// virtuelle pure

	virtual Chaine					IdentPredefiniDefiniMultiplement () = 0;
											// virtuelle pure

	virtual Chaine					FormatErreurSemantique () = 0;
											// virtuelle pure
	virtual Chaine					FormatAvertissementSemantique () = 0;
											// virtuelle pure
	virtual Chaine					FormatTestDeTypeAttendu () = 0;
											// virtuelle pure
	virtual Chaine					FormatEchecTestDeTypeAttendu () = 0;
											// virtuelle pure
	virtual Chaine					FormatLeTypeNAPasPuEtreInfere () = 0;
											// virtuelle pure
	virtual Chaine					FormatLeTypeDuParametreFormelNAPasPuEtreInfere () = 0;
											// virtuelle pure

	virtual Chaine					FormatNiveauDEvaluationIncremente () = 0;
											// virtuelle pure
	virtual Chaine					FormatNiveauDEvaluationDecremente () = 0;
											// virtuelle pure

	virtual Chaine					FormatNiveauStatiqueIncremente () = 0;
											// virtuelle pure
	virtual Chaine					FormatNiveauStatiqueDecremente () = 0;
											// virtuelle pure

	virtual Chaine					LesSautSurDesSautsSontOptimises () = 0;
											// virtuelle pure

	virtual Chaine					BlocDActivationPrincipal () = 0;
											// virtuelle pure

	virtual Chaine					EnteteEvalFonction () = 0;
											// virtuelle pure
	virtual Chaine					EnteteEvalProcedure () = 0;
											// virtuelle pure

	virtual Chaine					DebutEvaluationDirecte () = 0;
											// virtuelle pure

	virtual Chaine					FinEvalProcedure () = 0;
											// virtuelle pure

	virtual Chaine					CodeSemantiquementCorrect () = 0;
											// virtuelle pure
	virtual Chaine					CodeSemantiquementIncorrect () = 0;
											// virtuelle pure

	virtual Chaine					FormatTempsEcoule () = 0;
											// virtuelle pure

	};	//	LangueSemantique


// -------------------------------------------------------------------------
//	LangueSemantiqueFR
// -------------------------------------------------------------------------

class		LangueSemantiqueFR;
typedef	LangueSemantiqueFR	* LangueSemantiqueFRPTR;

class LangueSemantiqueFR : public LangueSemantique
	{
public:
										LangueSemantiqueFR ();

	virtual							~ LangueSemantiqueFR ();


	//	Semantique
	// -------------------------------------------------------------------------

	Chaine							FormatNomQualifie ();

	Chaine							ConstantePredefinie ();
	Chaine							FonctionPredefinie ();
	Chaine							IterationPredefinie ();

	Chaine							NonUtilise ();

	Chaine							FormatContenuDuDictionnaire ();
	Chaine							FormatPurgeDuDictionnaireVide ();
	Chaine							FormatPurgeDuDictionnaire ();

	Chaine							FormatEmpilageNiveauDeDeclaration ();
	Chaine							FormatDesempilageNiveauDeDeclaration ();

	Chaine							TableDesSymbolesVide ();
	Chaine							FormatTableDesSymboles ();

	Chaine							FormatIdentNonDeclare ();
	Chaine							FormatIdentNonDeclareSousFormeDeChaine ();
	Chaine							FacteurIdentificateurMalForme ();
	Chaine							FormatIdentDeFonctionNonDeclare ();

	Chaine							FormatConstantePredefinie ();
	Chaine							FormatFonctionPredefinie ();
	Chaine							FormatIterateurPredefini ();

	Chaine							FormatParametreFormel ();


	Chaine							FormatErreurCommeNombre ();
	Chaine							FormatErreurCommeBooleen ();
	Chaine							FormatErreurCommeChaine ();
	Chaine							FormatErreurTypeValeurLista ();

	Chaine							ParValeur ();
	Chaine							ParNom ();
	Chaine							ParBesoin ();

	Chaine							DelimiteurDeFonctionsEtEvaluations ();
	Chaine							SeparationDernierParametre ();

	Chaine							FormatFonctionUtilisateur ();
	Chaine							FormatBesoinDUnLienStatique ();


	Chaine							FormatParametreParValeur ();
	Chaine							FormatConsultationParametreParValeur ();

	Chaine							FormatParametreParNom ();
	Chaine							FormatEvaluationParametreParNom ();

	Chaine							ResultatEvaluation ();

	Chaine							FormatParametreParBesoinNonEvalue ();
	Chaine							ParametreParBesoinDejaEvalue ();
	Chaine							FormatEvaluationParametreParBesoin ();
	Chaine							FormatConsultationParametreParBesoin ();

	Chaine							FormatContexteDEvaluation ();

	Chaine							FormatRemonteeStatique ();

	Chaine							FormatTempsDEvaluationDirecte ();

	Chaine							ContinuationApresOperandeGauche ();
	Chaine							ContinuationApresOperandeDroit ();
	Chaine							OnJetteLOperandeDroitDeSeq1 ();
	Chaine							SeqImplicite ();

	Chaine							ValeurInconnue ();
	Chaine							ValeurVide ();

	Chaine							ArgumentDAppel ();

	Chaine							FormatTropDArgumentsDansAppelAPredefinie ();
	Chaine							FormatTropPeuDArgumentsDansAppelAPredefinie ();
	Chaine							FormatTropDArgumentsDansAppelAFonctionParametree ();
	Chaine							FormatTropPeuDArgumentsDansAppelAFonctionParametree ();

	Chaine							FormatNomDeFonction ();
	Chaine							FormatNumeroDeFonction ();
	Chaine							FormatNomDeParametre ();
	Chaine							FormatNumeroDeParametre ();
	Chaine							FormatNumeroDEvaluation ();

	Chaine							FormatTypeLogiqueDeFonction ();
	Chaine							FormatTypeLogiqueDeParametre ();
	Chaine							FormatTypeLogiqueDIdentificateurNonDeclare ();
	Chaine							FormatTypeLogiqueDeFonctionNonDeclaree ();

	Chaine							FormatRedefinitionDeFonctionUtilisateur ();
	Chaine							FormatDefinitionDeFonctionUtilisateurMasque ();

	Chaine							FormatRedefinitionDeParametre ();
	Chaine							FormatDefinitionDeParametreMasque ();

	Chaine							FormatAucuneDeclarationAccessible ();

	Chaine							ConditionDUnSi ();
	Chaine							FormatAlternativesDUnSiPasDuMemeType ();

	Chaine							GrapheSemantiqueDeLaSequenceDExpressionsAEvaluer ();
	Chaine							FormePostfixeeDeLaSequenceDExpressionsAEvaluer ();

	Chaine							FormatIteration ();
	Chaine							BorneInferieure ();
	Chaine							BorneSuperieure ();
	Chaine							ExpressionIteree ();

	Chaine							IndiceInconnu ();
	Chaine							IdentAttenduCommeIndiceDIteration ();
	Chaine							FormatVirguleAttendueApresLIndice ();
	Chaine							FormatVirguleAttendueApresLaBorneInferieure ();
	Chaine							FormatVirguleAttendueApresLaBorneSuperieure ();	
	Chaine							FormatRedefinitionDeLIndiceDIteration ();
	Chaine							FormatDefinitionDeLIndiceDIterationMasque ();
	Chaine							FormatParentheseInattendueDansAppelAFonctionNonParametree ();
	Chaine							FormatEmpilageDescrAppelDeFonction ();
	Chaine							FormatDesempilageDescrAppelDeFonction ();

	Chaine							FormatCreationDescrAppelDeFonctionPredefinie ();
	Chaine							FormatEnregistrementArgumentDeFonctionPredefinie ();
	Chaine							FormatVerifierSiPasTropDArgumentsPourFonctionPredefinie ();
	Chaine							FormatVerifierSiAssezDArgumentsPourFonctionPredefinie ();

	Chaine							FormatCreationDescrAppelIteration ();

	Chaine							FormatCreationDescrAppelFonctionUtilisateur ();
	Chaine							FormatVerifierSiPasTropDArgumentsPourFonctionUtilisateur ();
	Chaine							FormatVerifierSiAssezDArgumentsPourFonctionUtilisateur ();

	Chaine							FormatCreationDescrAppelFonctionErronee ();

	Chaine							ValeurInconnueNEstPasEvaluable ();

	Chaine							OnJetteLOperandeDeGaucheDeSeq ();

	Chaine							FormatEcritureAppelDeFonction ();
	Chaine							FormatEcritureEmploiParametre ();

	Chaine							FormatEmploiParametreDifferenceStatiqueTropGrande ();
	Chaine							FormatDescripteurDuParametreParNom ();
	Chaine							FormatDescripteurDuParametreParBesoin ();
	Chaine							FormatAdresseDuResultatDe ();
	Chaine							EtiquetteIntermediaireParBesoin ();
	Chaine							FormatAdresseDuBooleenDeControleParBesoin ();
	Chaine							FormatValeurDuBooleenDeControleParBesoin ();
	Chaine							FormatValeurParBesoin ();

	Chaine							FormatAppelALaFonctionSansArguments ();
	Chaine							FormatAppelALaFonctionAvecArguments ();
	Chaine							FormatResultatDeLAppelALaFonction ();
	Chaine							FormatSortieDeLAppelALaFonction ();
	Chaine							FormatLienStatiquePourAppelALaFonction ();

	Chaine							EtiquetteSiFaux ();
	Chaine							EtiquetteSuiteDuSi ();
	Chaine							EtiquetteContinuationDeLaContinuationDuSi ();

	Chaine							FormatDebutDuCorpsDeFonction ();
	Chaine							FormatLienStatiqueNecessairePourFonction ();
	Chaine							FormatFinDuCorpsDeFonction ();
	Chaine							FormatGrapheSemantiqueDuCoprsDUneFonction ();
	Chaine							FormatFormePostfixeeDuCoprsDUneFonction ();

	Chaine							EtiquetteCorpsDeFonction ();
	Chaine							EtiquetteSuiteDeCorpsDeFonction ();
	Chaine							EtiquetteContinuationDuCorpsDeFonction ();

	Chaine							DebutDUneEvaluation ();
	Chaine							EtiquetteContinuationDUneEvaluation ();
	Chaine							FinDUneEvaluation ();

	Chaine							EtiquetteDeCorpsDeThunk ();
	Chaine							FormatDebutDuCorpsDeThunk ();
	Chaine							FormatLienStatiqueNecessairePourThunk ();
	Chaine							FormatLienMarqueDeBlocDActivation ();
	Chaine							FormatFinDuCorpsDeThunk ();

	Chaine							EtiquetteSuiteDeCorpsDeThunk ();
	Chaine							EtiquetteContinuationDuCorpsDeThunk ();

	Chaine							FormatIndiceDIterationSousFormeDeChaine ();
	Chaine							IndiceDIteration ();

	Chaine							FormatConsultationIndiceDIteration ();
	Chaine							FormatEmploiIndiceDIteration ();

	Chaine							FormatEmploiIndiceDIterationDifferenceDEvaluationTropGrande ();
	Chaine							FormatEmploiIndiceDIterationDansSynthese ();

	Chaine							FormatIndiceDIteration ();
	Chaine							FormatIndiceDIterationPostFixe ();

	Chaine							EtiquetteDebutDIteration ();
	Chaine							EtiquetteSuiteDIteration ();

	Chaine							FormatAdresseIndiceDIteration ();
	Chaine							FormatValeurIndiceDIteration ();
	Chaine							FormatValeurInitialeIndiceDIteration ();
	Chaine							FormatAdresseBorneDeLIndiceDIteration ();
	Chaine							FormatValeurBorneDeLIndiceDIteration ();
	Chaine							FormatValeurInitialeDeLaBorneDIteration ();
	Chaine							FormaIncrementationIndiceDIteration ();

	Chaine							AdresseDeLaSomme ();
	Chaine							ValeurDeLaSomme ();
	Chaine							CumulDansLaSomme ();
	Chaine							ValeurDeLaSommeResultante ();
	Chaine							DebutDeSomme ();
	Chaine							FinDeSomme ();

	Chaine							AdresseDuProduit ();
	Chaine							ValeurDuProduit ();
	Chaine							CumulDansLeProduit ();
	Chaine							ValeurDuProduitResultant ();
	Chaine							DebutDeProduit ();
	Chaine							FinDeProduit ();

	Chaine							DebutDePour ();
	Chaine							FinDePour ();


	Chaine							NiveauDesPredefinis ();
	Chaine							NiveauPrincipal ();

	Chaine							FormatPasageDesParametres ();

	Chaine							CourtCircuitDesOperateursBinaires ();

	Chaine							TypeParametreFictifPourRattrapageDErreurs ();

	Chaine							NomParametreInconnu ();
	Chaine							NomQualifieParametreInconnu ();

	Chaine							IdentPredefiniDefiniMultiplement ();

	Chaine							FormatErreurSemantique ();
	Chaine							FormatAvertissementSemantique ();
	Chaine							FormatTestDeTypeAttendu ();
	Chaine							FormatEchecTestDeTypeAttendu ();
	Chaine							FormatLeTypeNAPasPuEtreInfere ();
	Chaine							FormatLeTypeDuParametreFormelNAPasPuEtreInfere ();

	Chaine							FormatNiveauDEvaluationIncremente ();
	Chaine							FormatNiveauDEvaluationDecremente ();

	Chaine							FormatNiveauStatiqueIncremente ();
	Chaine							FormatNiveauStatiqueDecremente ();

	Chaine							LesSautSurDesSautsSontOptimises ();

	Chaine							BlocDActivationPrincipal ();

	Chaine							EnteteEvalFonction ();
	Chaine							EnteteEvalProcedure ();

	Chaine							DebutEvaluationDirecte ();

	Chaine							FinEvalProcedure ();

	Chaine							CodeSemantiquementCorrect ();
	Chaine							CodeSemantiquementIncorrect ();

	Chaine							FormatTempsEcoule ();

	};	//	LangueSemantiqueFR


// -------------------------------------------------------------------------
//	LangueSemantiqueEN
// -------------------------------------------------------------------------

class		LangueSemantiqueEN;
typedef	LangueSemantiqueEN	* LangueSemantiqueENPTR;

class LangueSemantiqueEN : public LangueSemantique
	{
public:
										LangueSemantiqueEN ();

	virtual							~ LangueSemantiqueEN ();


	//	Semantique
	// -------------------------------------------------------------------------

	Chaine							FormatNomQualifie ();

	Chaine							ConstantePredefinie ();
	Chaine							FonctionPredefinie ();
	Chaine							IterationPredefinie ();

	Chaine							NonUtilise ();

	Chaine							FormatContenuDuDictionnaire ();
	Chaine							FormatPurgeDuDictionnaireVide ();
	Chaine							FormatPurgeDuDictionnaire ();

	Chaine							FormatEmpilageNiveauDeDeclaration ();
	Chaine							FormatDesempilageNiveauDeDeclaration ();

	Chaine							TableDesSymbolesVide ();
	Chaine							FormatTableDesSymboles ();

	Chaine							FormatIdentNonDeclare ();
	Chaine							FormatIdentNonDeclareSousFormeDeChaine ();
	Chaine							FacteurIdentificateurMalForme ();
	Chaine							FormatIdentDeFonctionNonDeclare ();

	Chaine							FormatConstantePredefinie ();
	Chaine							FormatFonctionPredefinie ();
	Chaine							FormatIterateurPredefini ();

	Chaine							FormatParametreFormel ();


	Chaine							FormatErreurCommeNombre ();
	Chaine							FormatErreurCommeBooleen ();
	Chaine							FormatErreurCommeChaine ();
	Chaine							FormatErreurTypeValeurLista ();

	Chaine							ParValeur ();
	Chaine							ParNom ();
	Chaine							ParBesoin ();

	Chaine							DelimiteurDeFonctionsEtEvaluations ();
	Chaine							SeparationDernierParametre ();

	Chaine							FormatFonctionUtilisateur ();
	Chaine							FormatBesoinDUnLienStatique ();


	Chaine							FormatParametreParValeur ();
	Chaine							FormatConsultationParametreParValeur ();

	Chaine							FormatParametreParNom ();
	Chaine							FormatEvaluationParametreParNom ();

	Chaine							ResultatEvaluation ();

	Chaine							FormatParametreParBesoinNonEvalue ();
	Chaine							ParametreParBesoinDejaEvalue ();
	Chaine							FormatEvaluationParametreParBesoin ();
	Chaine							FormatConsultationParametreParBesoin ();

	Chaine							FormatContexteDEvaluation ();

	Chaine							FormatRemonteeStatique ();

	Chaine							FormatTempsDEvaluationDirecte ();

	Chaine							ContinuationApresOperandeGauche ();
	Chaine							ContinuationApresOperandeDroit ();
	Chaine							OnJetteLOperandeDroitDeSeq1 ();
	Chaine							SeqImplicite ();

	Chaine							ValeurInconnue ();
	Chaine							ValeurVide ();

	Chaine							ArgumentDAppel ();

	Chaine							FormatTropDArgumentsDansAppelAPredefinie ();
	Chaine							FormatTropPeuDArgumentsDansAppelAPredefinie ();
	Chaine							FormatTropDArgumentsDansAppelAFonctionParametree ();
	Chaine							FormatTropPeuDArgumentsDansAppelAFonctionParametree ();

	Chaine							FormatNomDeFonction ();
	Chaine							FormatNumeroDeFonction ();
	Chaine							FormatNomDeParametre ();
	Chaine							FormatNumeroDeParametre ();
	Chaine							FormatNumeroDEvaluation ();

	Chaine							FormatTypeLogiqueDeFonction ();
	Chaine							FormatTypeLogiqueDeParametre ();
	Chaine							FormatTypeLogiqueDIdentificateurNonDeclare ();
	Chaine							FormatTypeLogiqueDeFonctionNonDeclaree ();

	Chaine							FormatRedefinitionDeFonctionUtilisateur ();
	Chaine							FormatDefinitionDeFonctionUtilisateurMasque ();

	Chaine							FormatRedefinitionDeParametre ();
	Chaine							FormatDefinitionDeParametreMasque ();

	Chaine							FormatAucuneDeclarationAccessible ();

	Chaine							ConditionDUnSi ();
	Chaine							FormatAlternativesDUnSiPasDuMemeType ();

	Chaine							GrapheSemantiqueDeLaSequenceDExpressionsAEvaluer ();
	Chaine							FormePostfixeeDeLaSequenceDExpressionsAEvaluer ();

	Chaine							FormatIteration ();
	Chaine							BorneInferieure ();
	Chaine							BorneSuperieure ();
	Chaine							ExpressionIteree ();

	Chaine							IndiceInconnu ();
	Chaine							IdentAttenduCommeIndiceDIteration ();
	Chaine							FormatVirguleAttendueApresLIndice ();
	Chaine							FormatVirguleAttendueApresLaBorneInferieure ();
	Chaine							FormatVirguleAttendueApresLaBorneSuperieure ();	
	Chaine							FormatRedefinitionDeLIndiceDIteration ();
	Chaine							FormatDefinitionDeLIndiceDIterationMasque ();
	Chaine							FormatParentheseInattendueDansAppelAFonctionNonParametree ();
	Chaine							FormatEmpilageDescrAppelDeFonction ();
	Chaine							FormatDesempilageDescrAppelDeFonction ();

	Chaine							FormatCreationDescrAppelDeFonctionPredefinie ();
	Chaine							FormatEnregistrementArgumentDeFonctionPredefinie ();
	Chaine							FormatVerifierSiPasTropDArgumentsPourFonctionPredefinie ();
	Chaine							FormatVerifierSiAssezDArgumentsPourFonctionPredefinie ();

	Chaine							FormatCreationDescrAppelIteration ();

	Chaine							FormatCreationDescrAppelFonctionUtilisateur ();
	Chaine							FormatVerifierSiPasTropDArgumentsPourFonctionUtilisateur ();
	Chaine							FormatVerifierSiAssezDArgumentsPourFonctionUtilisateur ();

	Chaine							FormatCreationDescrAppelFonctionErronee ();

	Chaine							ValeurInconnueNEstPasEvaluable ();

	Chaine							OnJetteLOperandeDeGaucheDeSeq ();

	Chaine							FormatEcritureAppelDeFonction ();
	Chaine							FormatEcritureEmploiParametre ();

	Chaine							FormatEmploiParametreDifferenceStatiqueTropGrande ();
	Chaine							FormatDescripteurDuParametreParNom ();
	Chaine							FormatDescripteurDuParametreParBesoin ();
	Chaine							FormatAdresseDuResultatDe ();
	Chaine							EtiquetteIntermediaireParBesoin ();
	Chaine							FormatAdresseDuBooleenDeControleParBesoin ();
	Chaine							FormatValeurDuBooleenDeControleParBesoin ();
	Chaine							FormatValeurParBesoin ();

	Chaine							FormatAppelALaFonctionSansArguments ();
	Chaine							FormatAppelALaFonctionAvecArguments ();
	Chaine							FormatResultatDeLAppelALaFonction ();
	Chaine							FormatSortieDeLAppelALaFonction ();
	Chaine							FormatLienStatiquePourAppelALaFonction ();

	Chaine							EtiquetteSiFaux ();
	Chaine							EtiquetteSuiteDuSi ();
	Chaine							EtiquetteContinuationDeLaContinuationDuSi ();

	Chaine							FormatDebutDuCorpsDeFonction ();
	Chaine							FormatLienStatiqueNecessairePourFonction ();
	Chaine							FormatFinDuCorpsDeFonction ();
	Chaine							FormatGrapheSemantiqueDuCoprsDUneFonction ();
	Chaine							FormatFormePostfixeeDuCoprsDUneFonction ();

	Chaine							EtiquetteCorpsDeFonction ();
	Chaine							EtiquetteSuiteDeCorpsDeFonction ();
	Chaine							EtiquetteContinuationDuCorpsDeFonction ();

	Chaine							DebutDUneEvaluation ();
	Chaine							EtiquetteContinuationDUneEvaluation ();
	Chaine							FinDUneEvaluation ();

	Chaine							EtiquetteDeCorpsDeThunk ();
	Chaine							FormatDebutDuCorpsDeThunk ();
	Chaine							FormatLienStatiqueNecessairePourThunk ();
	Chaine							FormatLienMarqueDeBlocDActivation ();
	Chaine							FormatFinDuCorpsDeThunk ();

	Chaine							EtiquetteSuiteDeCorpsDeThunk ();
	Chaine							EtiquetteContinuationDuCorpsDeThunk ();

	Chaine							FormatIndiceDIterationSousFormeDeChaine ();
	Chaine							IndiceDIteration ();

	Chaine							FormatConsultationIndiceDIteration ();
	Chaine							FormatEmploiIndiceDIteration ();

	Chaine							FormatEmploiIndiceDIterationDifferenceDEvaluationTropGrande ();
	Chaine							FormatEmploiIndiceDIterationDansSynthese ();

	Chaine							FormatIndiceDIteration ();
	Chaine							FormatIndiceDIterationPostFixe ();

	Chaine							EtiquetteDebutDIteration ();
	Chaine							EtiquetteSuiteDIteration ();

	Chaine							FormatAdresseIndiceDIteration ();
	Chaine							FormatValeurIndiceDIteration ();
	Chaine							FormatValeurInitialeIndiceDIteration ();
	Chaine							FormatAdresseBorneDeLIndiceDIteration ();
	Chaine							FormatValeurBorneDeLIndiceDIteration ();
	Chaine							FormatValeurInitialeDeLaBorneDIteration ();
	Chaine							FormaIncrementationIndiceDIteration ();

	Chaine							AdresseDeLaSomme ();
	Chaine							ValeurDeLaSomme ();
	Chaine							CumulDansLaSomme ();
	Chaine							ValeurDeLaSommeResultante ();
	Chaine							DebutDeSomme ();
	Chaine							FinDeSomme ();

	Chaine							AdresseDuProduit ();
	Chaine							ValeurDuProduit ();
	Chaine							CumulDansLeProduit ();
	Chaine							ValeurDuProduitResultant ();
	Chaine							DebutDeProduit ();
	Chaine							FinDeProduit ();

	Chaine							DebutDePour ();
	Chaine							FinDePour ();


	Chaine							NiveauDesPredefinis ();
	Chaine							NiveauPrincipal ();

	Chaine							FormatPasageDesParametres ();

	Chaine							CourtCircuitDesOperateursBinaires ();

	Chaine							TypeParametreFictifPourRattrapageDErreurs ();

	Chaine							NomParametreInconnu ();
	Chaine							NomQualifieParametreInconnu ();

	Chaine							IdentPredefiniDefiniMultiplement ();

	Chaine							FormatErreurSemantique ();
	Chaine							FormatAvertissementSemantique ();
	Chaine							FormatTestDeTypeAttendu ();
	Chaine							FormatEchecTestDeTypeAttendu ();
	Chaine							FormatLeTypeNAPasPuEtreInfere ();
	Chaine							FormatLeTypeDuParametreFormelNAPasPuEtreInfere ();

	Chaine							FormatNiveauDEvaluationIncremente ();
	Chaine							FormatNiveauDEvaluationDecremente ();

	Chaine							FormatNiveauStatiqueIncremente ();
	Chaine							FormatNiveauStatiqueDecremente ();

	Chaine							LesSautSurDesSautsSontOptimises ();

	Chaine							BlocDActivationPrincipal ();

	Chaine							EnteteEvalFonction ();
	Chaine							EnteteEvalProcedure ();

	Chaine							DebutEvaluationDirecte ();

	Chaine							FinEvalProcedure ();

	Chaine							CodeSemantiquementCorrect ();
	Chaine							CodeSemantiquementIncorrect ();

	Chaine							FormatTempsEcoule ();

	};	//	LangueSemantiqueEN


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

extern LangueSemantiquePTR		gLANGUE_Semantique;

extern LanguePredefinisPTR		gLANGUE_Traduction;
											//	celle dans laquelle on traduit,
											//	si cette option est choisie


// -------------------------------------------------------------------------
//	ChoisirLaLangueDeTraduction
// -------------------------------------------------------------------------

void									ChoisirLaLangueDeTraduction (
											Chaine leMnemonique );


// -------------------------------------------------------------------------
//	InitialiserLanguesSemantique
// -------------------------------------------------------------------------

void									InitialiserLanguesSemantique (
											Chaine leMnemonique = LANGUE_PAR_DEFAUT );


#endif /* __LanguesSemantique__ */
