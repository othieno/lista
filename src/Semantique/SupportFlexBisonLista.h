// =========================================================================
//	SupportFlexBisonLista.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __SupportFlexBisonLista__
#define __SupportFlexBisonLista__


#include "TableDesSymboles.h"

#include "FonctionsUtilisateur.h"

#include "Iterations.h"

#include "AnalyseurSemantiqueLista.h"

#include "InitialiserSemantique.h"

#include <deque>


/* ---------------------------------------------------------------------- */
/* Types */
/* ---------------------------------------------------------------------- */

typedef int							TerminalFlexBison;


/* ---------------------------------------------------------------------- */
//	DescriptionTerminalCourant
/* ---------------------------------------------------------------------- */

Chaine								DescriptionTerminalCourant ();


Chaine 								TerminalSousFormeTextuelle (
											TerminalFlexBison leTerminalFlexBison );


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


/* ---------------------------------------------------------------------- */
/* Variables globales */
/* ---------------------------------------------------------------------- */
	
extern
TerminalFlexBison					gTerminalCourantFlexBison;

extern
bool									gTraduire;


#endif /* SupportFlexBisonLista */
