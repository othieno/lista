//	PreDeclarationsSemantique.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __PreDeclarationsSemantique__
#define __PreDeclarationsSemantique__

#include <list>

// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

class		DescrSemantique;
typedef	DescrSemantique				* DescrSemantiquePTR;

class		DescrParametre;
typedef	DescrParametre					* DescrParametrePTR;

class		EmploiParametre;
typedef	EmploiParametre				* EmploiParametrePTR;

class		FonctionUtilisateur;
typedef	FonctionUtilisateur			* FonctionUtilisateurPTR;

class		ParametreFormel;
typedef	ParametreFormel				* ParametreFormelPTR;

class		AssocArgumentParametre;
typedef	AssocArgumentParametre		* AssocArgumentParametrePTR;

class		ContexteDEvaluation;
typedef	ContexteDEvaluation			* ContexteDEvaluationPTR;

class		OptionsSemantique;
typedef	OptionsSemantique				* OptionsSemantiquePTR;


typedef std::list<DescrSemantiquePTR>	ListeDescrSemantique;


#if defined SYNTHESE_PILUM

class		ContexteDeSynthese;
typedef	ContexteDeSynthese			* ContexteDeSynthesePTR;

class		SynthetiseurPilumLista;
typedef	SynthetiseurPilumLista		* SynthetiseurPilumListaPTR;


#endif /* SYNTHESE_PILUM */


#endif /* __PreDeclarationsSemantique__ */
