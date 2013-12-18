// =========================================================================
//	TerminauxFlesBisonLista.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$
// =========================================================================


#ifndef __TerminauxFlesBisonLista__
#define __TerminauxFlesBisonLista__


#include "Semantique.h"


// -------------------------------------------------------------------------
//	DescrIdentificateurFlexBison
// -------------------------------------------------------------------------

struct DescrIdentificateurFlexBison
	{
	CharPTR							fNom;
	IdentificateurPTR				fIdentificateurPTR;
	};


// -------------------------------------------------------------------------
//	DescrParametrePredef
// -------------------------------------------------------------------------

class		DescrParametrePredef;
typedef	DescrParametrePredef
										* DescrParametrePredefPTR;

class DescrParametrePredef : public DescrParametre
	{
public:
										DescrParametrePredef (
											int							leNumeroDeParametre );

	virtual AssocArgumentParametrePTR
										CommentEvaluer (
											long							leNumeroContexte,
											DescrSemantiquePTR		laValeur,
											ContexteDEvaluationPTR	leContexteDEvaluation );

	virtual int						TailleEnMemoire ();

#if defined SYNTHESE_PILUM

	virtual void					Synthetiser (
											ContexteDeSynthesePTR	leContexteDeSynthese,
											DescrSemantiquePTR		lArgumentDAppel );

#endif /* SYNTHESE_PILUM */

	};	//	DescrParametrePredef


// -------------------------------------------------------------------------
//	DescrAppelFonction
// -------------------------------------------------------------------------

class		DescrAppelFonction;
typedef	DescrAppelFonction	* DescrAppelFonctionPTR;

class DescrAppelFonction
	{
public:
										DescrAppelFonction (
											Chaine	leNom,
											int		leNombreDeParametres );

	virtual							~ DescrAppelFonction ();
	

	Chaine							Nom ();
	int								NombreDeParametres ();

	virtual void					EnregistrerArgument (
											DescrSemantiquePTR lArgument ) = 0;
											//	virtuelle pure
	virtual void					VerifierSiPasTropDArguments () = 0;
											//	virtuelle pure
	virtual void					VerifierSiAssezDArguments () = 0;
											//	virtuelle pure

	virtual
	void								DebutRattrappage () = 0;
											//	virtuelle pure

	virtual
	DescrSemantiquePTR			CreerGrapheSemantique () = 0;
											//	virtuelle pure

protected:

	Chaine							fNom;
	int								fNombreDeParametres;

	DescrSemantiquePTR			* fBlocDArguments;
											//	un tableau dynamique

	int								fNumeroDArgument;
	
	bool								fEnCoursDeRattrapage;

	};	//	DescrAppelFonction


typedef std::deque <DescrAppelFonctionPTR>
										PileDesDescrAppelFonction;
typedef PileDesDescrAppelFonction
										* PileDesDescrAppelFonctionPTR;


// -------------------------------------------------------------------------
//	DescrAppelFonctionPredefinie
// -------------------------------------------------------------------------

class		DescrAppelFonctionPredefinie;
typedef	DescrAppelFonctionPredefinie
										* DescrAppelFonctionPredefiniePTR;

class DescrAppelFonctionPredefinie : public DescrAppelFonction
	{
public:

										DescrAppelFonctionPredefinie (
											FonctionPredefiniePTR laFonctionPredefinie );

	virtual							~ DescrAppelFonctionPredefinie ();

	FonctionPredefiniePTR		FonctionPredefinie ();

	virtual void					EnregistrerArgument (DescrSemantiquePTR lArgument);
	virtual void					VerifierSiPasTropDArguments ();
	virtual void					VerifierSiAssezDArguments ();

	void								DebutRattrappage ();

	virtual
	DescrSemantiquePTR			CreerGrapheSemantique ();

protected:

	FonctionPredefiniePTR		fFonctionPredefinie;

	};	//	DescrAppelFonctionPredefinie


// -------------------------------------------------------------------------
//	DescrAppelIteration
// -------------------------------------------------------------------------

class		DescrAppelIteration;
typedef	DescrAppelIteration	* DescrAppelIterationPTR;

class DescrAppelIteration : public DescrAppelFonctionPredefinie
	{
public:

										DescrAppelIteration (
											FonctionPredefiniePTR 	laFonctionPredefinie );

	virtual							~ DescrAppelIteration ();

	IndiceIterationPTR			EnregistrerIndice (IndiceIterationPTR lIndice);
	void								EnregistrerBorneInf (DescrSemantiquePTR laBorneInf);
	void								EnregistrerBorneSup (DescrSemantiquePTR laBorneSup);
	void								EnregistrerExprIteree (DescrSemantiquePTR lExpression);

	virtual
	DescrSemantiquePTR			CreerGrapheSemantique ();

private:

	IndiceIterationPTR			fIndice;

	};	//	DescrAppelIteration


// -------------------------------------------------------------------------
//	DescrAppelFonctionUtilisateur
// -------------------------------------------------------------------------

class		DescrAppelFonctionUtilisateur;
typedef	DescrAppelFonctionUtilisateur
										* DescrAppelFonctionUtilisateurPTR;

class DescrAppelFonctionUtilisateur : public DescrAppelFonction
	{
public:

										DescrAppelFonctionUtilisateur (
											FonctionUtilisateurPTR laFonctionUtilisateur );

	virtual							~ DescrAppelFonctionUtilisateur ();

	FonctionUtilisateurPTR		LaFonctionUtilisateur ();

	virtual void					EnregistrerArgument (DescrSemantiquePTR lArgument);
	virtual void					VerifierSiPasTropDArguments ();
	virtual void					VerifierSiAssezDArguments ();

	void								DebutRattrappage ();

	virtual
	DescrSemantiquePTR			CreerGrapheSemantique ();

private:

	FonctionUtilisateurPTR		fFonctionUtilisateur;

	//	communication entre methodes
	ListeDesDescrParametresPTR
										fListeDesDescrParametres;
	ListeDesDescrParametres :: iterator
										fParametreCourant;

	};	//	DescrAppelFonctionUtilisateur


// -------------------------------------------------------------------------
//	DescrAppelFonctionErronee
// -------------------------------------------------------------------------

class		DescrAppelFonctionErronee;
typedef	DescrAppelFonctionErronee
										* DescrAppelFonctionErroneePTR;

class DescrAppelFonctionErronee : public DescrAppelFonction
	{
public:

										DescrAppelFonctionErronee (
											IdentificateurPTR lIdentificateur );

	virtual							~ DescrAppelFonctionErronee ();

	virtual void					EnregistrerArgument (DescrSemantiquePTR lArgument);
	virtual void					VerifierSiPasTropDArguments ();
	virtual void					VerifierSiAssezDArguments ();

	void								DebutRattrappage ();

	virtual
	DescrSemantiquePTR			CreerGrapheSemantique ();

private:

	IdentificateurPTR				fIdentificateur;

	};	//	DescrAppelFonctionErronee


// -------------------------------------------------------------------------
//	PileDesAppels
// -------------------------------------------------------------------------

class   PileDesAppels;
typedef PileDesAppels			* PileDesAppelsPTR;

class PileDesAppels
	{

public:

										PileDesAppels ();
										
										~ PileDesAppels ();

	void								Empiler (DescrAppelFonctionPTR leDescrAppelFonction);

	DescrAppelFonctionPTR		Sommet ();

	DescrAppelFonctionPTR		Desempiler ();

private:

	PileDesDescrAppelFonctionPTR
										fPileDesDescrAppelFonction;

	};	//	PileDesAppels


// -------------------------------------------------------------------------
//	OptionsFlexBison
// -------------------------------------------------------------------------

class		OptionsFlexBison;
typedef	OptionsFlexBison				* OptionsFlexBisonPTR;

class OptionsFlexBison
	{
public:
										OptionsFlexBison (
											bool		modeVerbeux,
											bool		leMontrerLesAppelsImbriques );

	bool								ModeVerbeux ();

	bool								MontrerLesAppelsImbriques ();


private:
	
	bool								fModeVerbeux;
	
	bool								fMontrerLesAppelsImbriques;

	};	//	OptionsFlexBison


// -------------------------------------------------------------------------
//	AnalyseurListaFlexBison
// -------------------------------------------------------------------------

class		AnalyseurListaFlexBison;
typedef	AnalyseurListaFlexBison		* AnalyseurListaFlexBisonPTR;

class AnalyseurListaFlexBison : public AnalyseurSemantiqueLista
	{
public:

										AnalyseurListaFlexBison (
											bool								leModeDebug,
											bool								leMontrerLesTerminaux,
											OptionsStrategiePTR			lesOptionsStrategie,
											OptionsSemantiquePTR			lesOptionsSemantique,
											OptionsFlexBisonPTR					lesOptionsFlexBison,
											OptionsEvaluationPTR			lesOptionsEvaluation
#if defined SYNTHESE_PILUM
										,	SynthetiseurPilumListaPTR	leSynthetiseurPilumLista
#endif /* SYNTHESE_PILUM */
											);

	virtual							~ AnalyseurListaFlexBison ();


	Chaine							DescriptionDuTerminalCourant ();
	Chaine							DescriptionDeLaPositionCourante ();

	bool								ModeDebug ();
	bool								MontrerLesTerminaux ();

	OptionsFlexBisonPTR					OptionsFlexBison ();

	FonctionUtilisateurPTR 		IdentFonction ();


	//	Methodes pour les actions semantiques
	//	-------------------------------------
	
	void								TraiterIdentFonction (
											DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );

	void								TraiterDebutParametres ();
	void								TraiterParametre (
											DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );

	void								TraiterCorpsDefinitionDeFonction (
											FonctionUtilisateurPTR	lIdentFonction,
											DescrSemantiquePTR		leCorps );
	void								TraiterFinDefinitionDeFonction (
											FonctionUtilisateurPTR	lIdentFonction,
											DescrSemantiquePTR		leCorps );

	void								TraiterDebutEvaluation ();
	void								TraiterFinEvaluation (DescrSemantiquePTR laSequence);

	DescrSemantiquePTR			TraiterFacteurIdentSimple (
											DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );

	DescrAppelFonctionPTR		AccepterFacteurAppelDeFonctionInconnue (
											Chaine nomIdentCourant );
	void								TraiterDebutAppelFonction (
											DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );
	DescrSemantiquePTR			TraiterFinAppelFonction ();

	void								TraiterDebutIteration (
											DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );
	void								TraiterIndiceIteration (
											DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );
	void								TraiterBorneInf (DescrSemantiquePTR laBorneInf);
	void								TraiterBorneSup (DescrSemantiquePTR laBorneSup);
	void								TraiterExprIteree (DescrSemantiquePTR lExpression);
	DescrSemantiquePTR			TraiterFinIteration ();

	DescrSemantiquePTR			TraiterSequence (
											DescrIdentificateurFlexBison	laDescrIdentificateurFlexBison,
											DescrSemantiquePTR		lExpression,
											DescrSemantiquePTR		laFinExpressionsSequencees );

	void								TraiterDebutArgument ();
	void								TraiterFinArgument (DescrSemantiquePTR lArgument);


	//	Interaction entre Analyse Lexicale et Analyse Semantique
	//	--------------------------------------------------------

	GenreIdentificateurFlexBison		InteractionLexiqueSemantique (
											DescrIdentificateurFlexBison & laDescrIdentificateurFlexBison );


private:

	bool								fModeDebug;
	bool								fMontrerLesTerminaux;
	
	OptionsFlexBisonPTR					fOptionsFlexBison;

	PileDesAppelsPTR				fPileDesAppels;


	//	Variables de communication entre actions semantiques
	//	----------------------------------------------------

	FonctionUtilisateurPTR		fIdentFonction;
											//	pour EnteteDeFonction et TraiterParametre
	int								fNumeroDeParametre;
											//	pour Parametres et TraiterParametre

	};	//	AnalyseurListaFlexBison


#endif /* TerminauxFlesBisonLista */
