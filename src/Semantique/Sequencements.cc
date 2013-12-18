// =========================================================================
//	Sequencements.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Sequencements.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	SequenceurPredef
// -------------------------------------------------------------------------

SequenceurPredef :: SequenceurPredef (
	ChaineLanguePredefinisPFM
									laFonctionNom,
	VariableLogiqueTypePTR	laVariableLogiqueType )
	: FonctionPredefinie (
		laFonctionNom,
		kSequence, kSequenceurFlexBison,
		laVariableLogiqueType)
	{
	fNombreDeParametres = 0;
	fTypesLogiquesDesParametres = NULL;
	}


// -------------------------------------------------------------------------
//	Les sequenceurs predefinis
// -------------------------------------------------------------------------

SeqPredef :: SeqPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: SequenceurPredef (laFonctionNom, gTypeLogiqueNonPrecise)
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNonPrecise;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNonPrecise;
	}

DescrSemantiquePTR
SeqPredef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Seq (fNom, leBlocDArguments [0], leBlocDArguments [1]); }

// -------------------------------------------------------------------------

Seq1Predef :: Seq1Predef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: SequenceurPredef (laFonctionNom, gTypeLogiqueNonPrecise)
	{
	fNombreDeParametres = 2;
	fTypesLogiquesDesParametres =
		new VariableLogiqueTypePTR [fNombreDeParametres];
	fTypesLogiquesDesParametres [0] = gTypeLogiqueNonPrecise;
	fTypesLogiquesDesParametres [1] = gTypeLogiqueNonPrecise;
	}

DescrSemantiquePTR
Seq1Predef :: CreerGrapheDAppelALaFonction (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	DescrSemantiquePTR		* leBlocDArguments )
	{ return new Seq1 (fNom, leBlocDArguments [0], leBlocDArguments [1]); }


// -------------------------------------------------------------------------
//	Sequencement
// -------------------------------------------------------------------------

Seq :: Seq (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
			leNom,
			lOperandeDroit -> TypeLogique (),
			lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Seq :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	ValeurLista
				valeurGauche =
					fOperandeGauche -> Evaluer (leContexteDEvaluation);

	ValeurLista
				valeurDroite =
					fOperandeDroit -> Evaluer (leContexteDEvaluation);

	return valeurDroite;	// on jette valeurGauche
	}


#if defined SYNTHESE_PILUM

void 
Seq :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	SynthetiseurPilumListaPTR
				synth = leContexteDeSynthese -> LeSynthetiseurPilumLista ();
			
	OptionsSynthesePTR
				optionsSynthese =
					leContexteDeSynthese -> OptionsSynthese ();
	
	if (! optionsSynthese -> OptimiserLesSauts ())
		fOperandeGauche -> Synthetiser (leContexteDeSynthese);

	else
		{
		VariableLogiqueEtiquettePTR
					continOperandeGauche =
						synth -> CreerEtiquette (
							gLANGUE_Semantique ->
								ContinuationApresOperandeGauche () );
	
		ContexteDeSynthese
					leContexteDeSyntheseGauche (
						synth,
						leContexteDeSynthese -> DescrBlocDActivation (),
						optionsSynthese,
						continOperandeGauche);
		
		fOperandeGauche -> Synthetiser (& leContexteDeSyntheseGauche);
		
		synth -> PlacerEtiquette (continOperandeGauche);
		}	// optionsSynthese -> OptimiserLesSauts ()

	TypePTR	leTypeGauche =
					fOperandeGauche -> TypeLogique () -> ValeurDeLiaison ();

	if (! leTypeGauche -> DecritUneAbsenceDeValeur ())
		{
		if (optionsSynthese -> CommenterLeCode ())
			synth ->
				Commentaire (
					gLANGUE_Semantique ->
						OnJetteLOperandeDeGaucheDeSeq () );

		synth -> Desempiler (1);
			//	on jette la valeur gauche pour laisser la valeur droite
			//	comme resultat sur la pile
		}	// if
	
	fOperandeDroit -> Synthetiser (leContexteDeSynthese);

	}	//	Seq :: Synthetiser

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------

Seq1 :: Seq1 (
	Chaine					leNom,
	DescrSemantiquePTR	lOperandeGauche,
	DescrSemantiquePTR	lOperandeDroit )
	: OperateurBinaire (
			leNom,
			lOperandeGauche -> TypeLogique (),
			lOperandeGauche, lOperandeDroit )
	{}

ValeurLista 
Seq1 :: Evaluer (ContexteDEvaluationPTR leContexteDEvaluation)
	{
	ValeurLista
				valeurGauche =
					fOperandeGauche -> Evaluer (leContexteDEvaluation);

	ValeurLista
				valeurDroite =
					fOperandeDroit -> Evaluer (leContexteDEvaluation);

	return valeurGauche;	// on jette valeurDroite
	}

#if defined SYNTHESE_PILUM

void 
Seq1 :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	TypePTR	leTypeDroit =
					fOperandeDroit -> TypeLogique () -> ValeurDeLiaison ();

	SynthetiseurPilumListaPTR
				synth = leContexteDeSynthese -> LeSynthetiseurPilumLista ();
	
	OptionsSynthesePTR
				optionsSynthese =
					leContexteDeSynthese -> OptionsSynthese ();
	
	if (! optionsSynthese -> OptimiserLesSauts ())
		{
		fOperandeGauche -> Synthetiser (leContexteDeSynthese);
		fOperandeDroit -> Synthetiser (leContexteDeSynthese);
		}

	else
		{
		DescrBlocDActivationPTR
					descrBlocDActivation =
						leContexteDeSynthese -> DescrBlocDActivation ();
	
		VariableLogiqueEtiquettePTR
					continOperandeGauche =
						synth -> CreerEtiquette (
							gLANGUE_Semantique ->
								ContinuationApresOperandeGauche () );
	
		ContexteDeSynthese
					leContexteDeSyntheseGauche (
						synth,
						descrBlocDActivation,
						optionsSynthese,
						continOperandeGauche);
	
		fOperandeGauche -> Synthetiser (& leContexteDeSyntheseGauche);
			
		synth -> PlacerEtiquette (continOperandeGauche);
		
	if (! leTypeDroit -> DecritUneAbsenceDeValeur ())
		{
		VariableLogiqueEtiquettePTR
					continOperandeDroit =
						synth -> CreerEtiquette (
							gLANGUE_Semantique ->
								ContinuationApresOperandeDroit () );

		ContexteDeSynthese
					leContexteDeSyntheseDroite (
						synth,
						descrBlocDActivation,
						optionsSynthese,
						continOperandeDroit);

		fOperandeDroit ->
			Synthetiser (& leContexteDeSyntheseDroite);
						
		synth -> PlacerEtiquette (continOperandeDroit);
		}
	else
		fOperandeDroit -> Synthetiser (leContexteDeSynthese);
		}	// optionsSynthese -> OptimiserLesSauts ()

	if (! leTypeDroit -> DecritUneAbsenceDeValeur ())
		{
		if (optionsSynthese -> CommenterLeCode ())
			synth -> 
				Commentaire (
					gLANGUE_Semantique ->
						OnJetteLOperandeDroitDeSeq1 () );

		synth -> Desempiler (1);
			//	on jette la valeur droite pour laisser la valeur gauche
			//	comme resultat sur la pile
		}	// if
	}	//	Seq1 :: Synthetiser

#endif /* SYNTHESE_PILUM */
