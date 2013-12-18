// =========================================================================
//	OperateursNAires.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "OperateursNAires.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	OperateurZeroaire
// -------------------------------------------------------------------------

OperateurZeroaire :: OperateurZeroaire (
	Chaine						leNom,
	VariableLogiqueTypePTR	leTypeLogique )
	:	DescrSemantique (leTypeLogique)
	{ fNom = leNom; }

void 
OperateurZeroaire :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);
	std::cout <<
		fNom <<
		std::endl;
	}

#if defined SYNTHESE_PILUM

void 
OperateurZeroaire :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iNon);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	OperateurUnaire
// -------------------------------------------------------------------------

OperateurUnaire :: OperateurUnaire (
	Chaine						leNom,
	VariableLogiqueTypePTR	leTypeLogique,
	DescrSemantiquePTR  lOperande )
	:	DescrSemantique (leTypeLogique)
	{
	fNom = leNom;
	fOperande = lOperande;
	}

OperateurUnaire :: ~ OperateurUnaire ()
	{
	delete fOperande;
	}

void 
OperateurUnaire :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);
	std::cout <<
		fNom <<
		std::endl;
	fOperande -> Ecrire (lIndentation + 1);
	}

void 
OperateurUnaire :: PostFixer ()
	{
	fOperande -> PostFixer ();
	std::cout <<
		"\t" <<
		fNom <<
		std::endl;
	}

#if defined SYNTHESE_PILUM

void 
OperateurUnaire :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperande -> Synthetiser (leContexteDeSynthese);
	leContexteDeSynthese -> LeSynthetiseurPilumLista () ->
		Zeroadique (iNon);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	OperateurBinaire
// -------------------------------------------------------------------------

OperateurBinaire :: OperateurBinaire (
	Chaine						leNom,
	VariableLogiqueTypePTR	leTypeLogique,
	DescrSemantiquePTR		lOperandeGauche,
	DescrSemantiquePTR		lOperandeDroit )
	:	DescrSemantique (leTypeLogique)
	{
	fNom = leNom;
	fOperandeGauche = lOperandeGauche;
	fOperandeDroit = lOperandeDroit;
	}

OperateurBinaire :: ~ OperateurBinaire ()
	{
	delete fOperandeGauche;
	delete fOperandeDroit;
	}

void 
OperateurBinaire :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);
	std::cout <<
		fNom <<
		std::endl;
	fOperandeGauche -> Ecrire (lIndentation + 1);
	fOperandeDroit -> Ecrire (lIndentation + 1);
	}

void 
OperateurBinaire :: PostFixer ()
	{
	fOperandeGauche -> PostFixer ();
	fOperandeDroit -> PostFixer ();
	std::cout <<
		"\t" <<
			fNom <<
			std::endl;
	}

#if defined SYNTHESE_PILUM

void 
OperateurBinaire :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperandeGauche -> Synthetiser (leContexteDeSynthese);
	fOperandeDroit -> Synthetiser (leContexteDeSynthese);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	OperateurTernaire
// -------------------------------------------------------------------------

OperateurTernaire :: OperateurTernaire (
	Chaine						leNom,
	VariableLogiqueTypePTR	leTypeLogique,
	DescrSemantiquePTR		lOperandeGauche,
	DescrSemantiquePTR		lOperandeMedian,
	DescrSemantiquePTR		lOperandeDroit )
	:	DescrSemantique (leTypeLogique)
	{
	fNom = leNom;
	fOperandeGauche = lOperandeGauche;
	fOperandeMedian = lOperandeMedian;
	fOperandeDroit = lOperandeDroit;
	}

OperateurTernaire :: ~ OperateurTernaire ()
	{
	delete fOperandeGauche;
	delete fOperandeMedian;
	delete fOperandeDroit;
	}

void 
OperateurTernaire :: Ecrire (int lIndentation)
	{
	DescrSemantique :: Ecrire (lIndentation);
	std::cout <<
		fNom <<
		std::endl;
	fOperandeGauche -> Ecrire (lIndentation + 1);
	fOperandeMedian -> Ecrire (lIndentation + 1);
	fOperandeDroit -> Ecrire (lIndentation + 1);
	}

void 
OperateurTernaire :: PostFixer ()
	{
	fOperandeGauche -> PostFixer ();
	fOperandeMedian -> PostFixer ();
	fOperandeDroit -> PostFixer ();
	std::cout <<
		"\t" <<
		fNom <<
		std::endl;
	}

#if defined SYNTHESE_PILUM

void 
OperateurTernaire :: Synthetiser (ContexteDeSynthesePTR leContexteDeSynthese)
	{
	fOperandeGauche -> Synthetiser (leContexteDeSynthese);
	fOperandeMedian -> Synthetiser (leContexteDeSynthese);
	fOperandeDroit -> Synthetiser (leContexteDeSynthese);
	}

#endif /* SYNTHESE_PILUM */
