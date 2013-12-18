// =========================================================================
//	Si.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Si.h"

#include "LanguesSemantique.h"

#include "FonctionsUtilisateur.h"

#include "AnalyseurSemantiqueLista.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	SiPredef
// -------------------------------------------------------------------------

SiPredef :: SiPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: FonctionPredefinie (
		laFonctionNom,
		kSi, kAutreIdentificateurFlexBison,
		gTypeLogiqueNonPrecise )
	{
	fNombreDeParametres = 3;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueBooleen;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNonPrecise;
	fTypesLogiquesDesParametres [2] = gTypeLogiqueNonPrecise;
	}

DescrSemantiquePTR
SiPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{
	DescrSemantiquePTR
				condition    = leBlocDArguments [0];
	DescrSemantiquePTR
				valeurSiVrai = leBlocDArguments [1];
	DescrSemantiquePTR
				valeurSiFaux = leBlocDArguments [2];

	VariableLogiqueTypePTR
				typeSiVrai = valeurSiVrai -> TypeLogique ();
	VariableLogiqueTypePTR
				typeSiFaux = valeurSiFaux -> TypeLogique ();

	if (
		! typeSiFaux -> UnifierAutreVariable (typeSiVrai)
			&&
		typeSiVrai != gTypeLogiqueInconnu
			&&
		typeSiFaux != gTypeLogiqueInconnu
		)
		{
		gAnalyseurSemantiqueLista ->
			ErreurSemantique (
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatAlternativesDUnSiPasDuMemeType (),
					typeSiVrai -> SousFormeDeChaine (),
					typeSiFaux -> SousFormeDeChaine () ));

		return gDescrSemantiqueInconnue;
		}

	else
		return new Si (
			fNom, condition, valeurSiVrai, valeurSiFaux, typeSiFaux );
	}	// SiPredef :: CreerGrapheDAppelALaFonction


// -------------------------------------------------------------------------
//	Si
// -------------------------------------------------------------------------

Si :: Si (
	Chaine						leNom,
	DescrSemantiquePTR		laCondition,
	DescrSemantiquePTR		laValeurSiVrai,
	DescrSemantiquePTR		laValeurSiFaux,
	VariableLogiqueTypePTR	leTypeLogique )
	:	DescrSemantique (leTypeLogique)
	{
	fCondition = laCondition;
	fValeurSiVrai = laValeurSiVrai;
	fValeurSiFaux = laValeurSiFaux;
	}

void 
Si :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);
	std::cout <<
		gLANGUE_Predefinis ->
			Si () <<
		std::endl;
	fCondition -> Ecrire (lIndentation + 1);
	fValeurSiVrai -> Ecrire (lIndentation + 1);
	fValeurSiFaux -> Ecrire (lIndentation + 1);
	}

void 
Si :: PostFixer ()
	{
	fCondition -> PostFixer ();
	fValeurSiVrai -> PostFixer ();
	fValeurSiFaux -> PostFixer ();
	std::cout <<
		"\t" <<
		gLANGUE_Predefinis ->
			Si () <<
		std::endl;
	}

ValeurLista 
Si :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	return
		(fCondition -> Evaluer (leContexteDEvaluation).CommeBooleen ())
			?	fValeurSiVrai -> Evaluer (leContexteDEvaluation)
			:	fValeurSiFaux -> Evaluer (leContexteDEvaluation);
	}

#if defined SYNTHESE_PILUM

void 
Si :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{

	SynthetiseurPilumListaPTR
				synth =
					leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	VariableLogiqueEtiquettePTR
				etiquetteSiFaux =
					synth -> 
						CreerEtiquette (
							gLANGUE_Semantique ->
								EtiquetteSiFaux () );

	OptionsSynthesePTR
				optionsSynthese =
					leContexteDeSynthese -> OptionsSynthese ();
	
	if (! optionsSynthese -> OptimiserLesSauts ())
		{
		VariableLogiqueEtiquettePTR
					etiquetteSuite =
						synth ->
							CreerEtiquette (
								gLANGUE_Semantique ->
									EtiquetteSuiteDuSi () );
	
		fCondition -> Synthetiser (leContexteDeSynthese);
	
		synth -> Saut (iSauterSiFaux, etiquetteSiFaux);
		
		fValeurSiVrai -> Synthetiser (leContexteDeSynthese);
		
		synth -> Saut (iSauter, etiquetteSuite);
		
		synth -> PlacerEtiquette (etiquetteSiFaux);
	
		fValeurSiFaux -> Synthetiser (leContexteDeSynthese);
	
		synth -> PlacerEtiquette (etiquetteSuite);
		}

	else
		{	
		VariableLogiqueEtiquettePTR
					continuationCondition =
						synth -> CreerEtiquette (
							gLANGUE_Semantique ->
								EtiquetteContinuationDeLaContinuationDuSi () );
	
		ContexteDeSynthese
					leContexteCondition (
						synth,
						leContexteDeSynthese -> DescrBlocDActivation (),
						optionsSynthese,
						continuationCondition );
									
		fCondition -> Synthetiser (& leContexteCondition);
				
		synth -> PlacerEtiquette (continuationCondition);
	
		synth -> Saut (iSauterSiFaux, etiquetteSiFaux);
		
		fValeurSiVrai -> Synthetiser (leContexteDeSynthese);
				
		synth -> Saut (iSauter, leContexteDeSynthese -> Continuation ());
		
		synth -> PlacerEtiquette (etiquetteSiFaux);
	
		fValeurSiFaux -> Synthetiser (leContexteDeSynthese);
		}	// optionsSynthese -> OptimiserLesSauts () ()
	}	//	Si :: Synthetiser

#endif /* SYNTHESE_PILUM */
