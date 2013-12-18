// =========================================================================
//	DecodageDOptionsSemantique.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __DecodageDOptionsSemantique__
#define __DecodageDOptionsSemantique__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "DecodageDOptionsSyntaxe.h"

#include "LanguesSemantique.h"

#include "StrategiesDEvaluation.h"

#if defined SYNTHESE_PILUM
	#include "Pilum.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	OptionsSemantique
// -------------------------------------------------------------------------

class		OptionsSemantique;
typedef	OptionsSemantique		* OptionsSemantiquePTR;

class OptionsSemantique
	{
public:
										OptionsSemantique (
											bool						leSortirALaPremiereErreurSyntaxique,
											bool						leModeVerbeux,
											bool						leMontrerLesDictionnaires,
											bool						leMontrerLeDictionnaireDesPredefinis,
											bool						leMontrerLInferenceDeType,
											bool						leMontrerLesGraphes,
											bool						leMontrerLePostfixe,
											bool						lEvaluerDirectement,
											bool						leTraduire );

	bool								SortirALaPremiereErreurSyntaxique ();

	bool								ModeVerbeux ();

	bool								MontrerLesDictionnaires ();
	bool								MontrerLeDictionnaireDesPredefinis ();
	bool								MontrerLInferenceDeType ();

	bool								MontrerLesGraphes ();
	bool								MontrerLePostfixe ();

	bool								EvaluerDirectement ();

	bool								Traduire ();


private:
	
	bool								fSortirALaPremiereErreurSyntaxique;

	bool								fModeVerbeux;

	bool								fMontrerLesDictionnaires;
	bool								fMontrerLeDictionnaireDesPredefinis;
	bool								fMontrerLInferenceDeType;
	
	bool								fMontrerLesGraphes;
	bool								fMontrerLePostfixe;
	
	bool								fEvaluerDirectement;

	bool								fTraduire;
	};	//	OptionsSemantique


inline
bool
OptionsSemantique :: SortirALaPremiereErreurSyntaxique ()
	{ return fSortirALaPremiereErreurSyntaxique; }

inline
bool
OptionsSemantique :: ModeVerbeux ()
	{ return fModeVerbeux; }

inline
bool
OptionsSemantique :: MontrerLesDictionnaires ()
	{ return fMontrerLesDictionnaires; }

inline
bool
OptionsSemantique :: MontrerLeDictionnaireDesPredefinis ()
	{ return fMontrerLeDictionnaireDesPredefinis; }

inline
bool
OptionsSemantique :: MontrerLInferenceDeType ()
	{ return fMontrerLInferenceDeType; }

inline
bool
OptionsSemantique :: MontrerLesGraphes ()
	{ return fMontrerLesGraphes; }

inline
bool
OptionsSemantique :: MontrerLePostfixe ()
	{ return fMontrerLePostfixe; }

inline
bool
OptionsSemantique :: EvaluerDirectement ()
	{ return fEvaluerDirectement; }

inline
bool
OptionsSemantique :: Traduire ()
	{ return fTraduire; }


// -------------------------------------------------------------------------
//	DecodageDOptionsSemantique
// -------------------------------------------------------------------------

class		DecodageDOptionsSemantique;
typedef	DecodageDOptionsSemantique		* DecodageDOptionsSemantiquePTR;

class DecodageDOptionsSemantique : public DecodageDOptionsSyntaxe
	{
public:
										DecodageDOptionsSemantique (
											int			leNbDArguments,
											CharPTR		lesArguments [],
											ChaineOptionsPFM
															laFonctionVersion );


	virtual void					Initialiser ();

	virtual void					Langue (Chaine argument);

	virtual void					Groupees (Chaine argument);

	virtual void					ModeDebug (Chaine argument);
	virtual void					SortirALaPremiereErreurSemantique (
											Chaine argument );

	virtual void					LangueDestination (Chaine argument);

	virtual void					StrategieParValeur (Chaine argument);
	virtual void					StrategieParNom (Chaine argument);
	virtual void					StrategieParBesoin (Chaine argument);

	virtual void					CourtCircuitLogiquesBinaires (Chaine argument);

	virtual void					MontrerLesAppelsImbriques (Chaine argument);

	virtual void					MontrerLesDictionnaires (Chaine argument);
	virtual void					MontrerLeDictionnaireDesPredefinis (
											Chaine argument );
	virtual void					MontrerLInferenceDeType (Chaine argument);
	virtual void					MontrerLesGraphesSemantiques (Chaine argument);
	virtual void					MontrerLeCodePostfixe (Chaine argument);

	virtual void					EvaluationDirecteSansTrace (Chaine argument);
	virtual void					EvaluationDirecteAvecTrace (Chaine argument);

#if defined SYNTHESE_PILUM

	virtual void					CommenterLeCode (Chaine argument);
	virtual void					MarquerLesBlocsDActivation (Chaine argument);
	virtual void					OptimiserLesSauts (Chaine argument);
	virtual void					MontrerLeCodeParLeSynthetiseur (Chaine argument);
	virtual void					ModeDebugSynthese (Chaine argument);

	virtual void					EvaluerParPilum (Chaine argument);
	virtual void					TailleDeLaPile (Chaine argument);

	virtual void					MontrerLeCodeParPilum (Chaine argument);
	virtual void					MontrerLAideInteractiveInitialement (
											Chaine argument );
	virtual void					ModeTracePilum (Chaine argument);
	virtual void					ModeDebugPilum (Chaine argument);

#endif /* SYNTHESE_PILUM */


	bool								ModeDebug ();
	bool								SortirALaPremiereErreurSemantique ();

	bool								Traduire ();

	StrategieDEvaluationPTR		LaStrategieDEvaluation ();

	bool								CourtCircuitLogiquesBinaires ();

	bool								MontrerLesAppelsImbriques ();

	bool								MontrerLesDictionnaires ();
	bool								MontrerLeDictionnaireDesPredefinis ();
	bool								MontrerLInferenceDeType ();
	bool								MontrerLesGraphesSemantiques ();
	bool								MontrerLeCodePostfixe ();

	bool								EvaluerDirectement ();
	bool								TraceDEvaluationDirecte ();

#if defined SYNTHESE_PILUM

	bool								CommenterLeCode ();
	bool								MarquerLesBlocsDActivation ();
	bool								OptimiserLesSauts ();
	bool								MontrerLeCodeParLeSynthetiseur ();
	bool								ModeDebugSynthese ();

	bool								EvaluerParPilum ();
	long								TailleDeLaPile ();

	GenreDExecution				LeGenreDExecution ();

	bool								MontrerLeCodeParPilum ();
	bool								MontrerLAideInteractiveInitialement ();

#endif /* SYNTHESE_PILUM */

	virtual void					ArgumentsNonOptions (Chaine argument);


protected:

	bool								fModeDebug;
	bool								fSortirALaPremiereErreurSemantique;

	bool								fTraduire;

	StrategieDEvaluationPTR		fStrategieDEvaluation;

	bool								fCourtCircuitLogiquesBinaires;

	bool								fMontrerLesAppelsImbriques;
	
	bool								fMontrerLesDictionnaires;
	bool								fMontrerLeDictionnaireDesPredefinis;
	bool								fMontrerLInferenceDeType;
	bool								fMontrerLesGraphesSemantiques;
	bool								fMontrerLeCodePostfixe;

	bool								fEvaluerDirectement;
	bool								fTraceDEvaluationDirecte;

#if defined SYNTHESE_PILUM

	bool								fCommenterLeCode;
	bool								fMarquerLesBlocsDActivation;
	bool								fOptimiserLesSauts;
	bool								fMontrerLeCodeParLeSynthetiseur;
	bool								fModeDebugSynthese;

	bool								fEvaluerParPilum;
	long								fTailleDeLaPile;

	GenreDExecution				fGenreDExecution;

	bool								fMontrerLeCodeParPilum;
	bool								fMontrerLAideInteractiveInitialement;

#endif /* SYNTHESE_PILUM */
	};	// DecodageDOptionsSemantique


typedef TemplateAssocInstanceMethodeOptions
										<DecodageDOptionsSemantique>
											AssocDecodageDOptionsSemantique;


#endif /* __DecodageDOptionsSemantique__ */
