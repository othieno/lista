// =========================================================================
//	SynthesePilumLista.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __SynthesePilumLista__
#define __SynthesePilumLista__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "FonctionsUtilisateur.h"

#include "SynthesePilum.h"


// -------------------------------------------------------------------------
//	DescrBlocDActivation
// -------------------------------------------------------------------------

class		DescrBlocDActivation;
typedef	DescrBlocDActivation	* DescrBlocDActivationPTR;

class DescrBlocDActivation
	{
public:
										DescrBlocDActivation (Chaine leNNom);

	virtual							~ DescrBlocDActivation ();

	Chaine							Nom ();
	
	VariableLogiqueEntierePTR	NombreLogTemporaires ();

	int								AllouerTemporaire ();
	void								LibererTemporaire ();

	void								LierNombreLogTemporaires ();

private:

	Chaine							fNom;

	VariableLogiqueEntierePTR	fNombreLogTemporaires;

	int								fDernierTemporaireAlloue;
	int								fNombreTemporairesSimultanes;

	};	//	DescrBlocDActivation


// --------------------------------------------------------------------------
//	ContexteDeSynthese
// --------------------------------------------------------------------------

class		ContexteDeSynthese;
typedef	ContexteDeSynthese	* ContexteDeSynthesePTR;

class ContexteDeSynthese
	{
public:
										ContexteDeSynthese (
											SynthetiseurPilumListaPTR		leSynthetiseurPilumLista,
											DescrBlocDActivationPTR			laDescrBlocDActivation,
											OptionsSynthesePTR				lesOptionsSynthese,
											VariableLogiqueEtiquettePTR	laContinuation );

	SynthetiseurPilumListaPTR	LeSynthetiseurPilumLista ();

	DescrBlocDActivationPTR		DescrBlocDActivation ();

	OptionsSynthesePTR			OptionsSynthese ();

	VariableLogiqueEtiquettePTR
										Continuation ();

private:

	SynthetiseurPilumListaPTR	fSynthetiseurPilumLista;

	DescrBlocDActivationPTR		fDescrBlocDActivation;

	OptionsSynthesePTR			fOptionsSynthese;
	
	VariableLogiqueEtiquettePTR
										fContinuation;

	};	//	ContexteDeSynthese


inline
SynthetiseurPilumListaPTR
ContexteDeSynthese :: LeSynthetiseurPilumLista ()
	{ return fSynthetiseurPilumLista; }

inline
DescrBlocDActivationPTR
ContexteDeSynthese :: DescrBlocDActivation ()
	{ return fDescrBlocDActivation; }

inline
OptionsSynthesePTR
ContexteDeSynthese :: OptionsSynthese ()
	{ return fOptionsSynthese; }

inline
VariableLogiqueEtiquettePTR
ContexteDeSynthese :: Continuation ()
	{ return fContinuation; }


// --------------------------------------------------------------------------
//	SynthetiseurPilumLista
// --------------------------------------------------------------------------

class		SynthetiseurPilumLista;
typedef	SynthetiseurPilumLista	* SynthetiseurPilumListaPTR;

class SynthetiseurPilumLista : public SynthetiseurPilum
	{
public:
										SynthetiseurPilumLista (
											Chaine					leNom,
											std::ostream			* leFlotTexte,
											std::ofstream			* leFichierBinaire,
											OptionsSynthesePTR	lesOptionsSynthese );

	virtual							~ SynthetiseurPilumLista ();


	void								SynthetiserDefinitionDeFonction (
											FonctionUtilisateurPTR
														lIdFonction,
											DescrSemantiquePTR
														leGrapheSemantiqueDuCorps );

	void								SynthetiserEvaluation (
											DescrSemantiquePTR	lExpression );
	
	VariableLogiqueEtiquettePTR
										SynthetiserCorpsDeThunk (
											ContexteDeSynthesePTR	leContexteDeSynthese,
											DescrParametrePTR			laDescrParametre,
											DescrSemantiquePTR		lArgumentDAppel );

	void								SynthetiserLEpilogue ();

	void								FinaliserLaSyntheseDeCode ();

	void								EcrireSurLeFichierBinaire ();

protected:

	std::ostream					* fFlotTexte;
	std::ofstream					* fFichierBinaire;

	DescrBlocDActivationPTR		fDescrBlocDActivationPrincipal;
	ContexteDeSynthesePTR		fContexteDeSynthesePrincipal;
	
	OptionsSynthesePTR			fOptionsSynthese;

	Chaine							fDelimiteurDeFonctionsEtEvaluations;

	};	//	SynthetiseurPilumLista


#endif /* __SynthesePilumLista__ */
