// =========================================================================
//	OperateursNAires.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __OperateursNAires__
#define __OperateursNAires__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "DescrSemantique.h"


// -------------------------------------------------------------------------
//	OperateurZeroaire
// -------------------------------------------------------------------------

class OperateurZeroaire : public DescrSemantique
	{
public:
										OperateurZeroaire (
											Chaine							leNom,
											VariableLogiqueTypePTR		leTypeLogique );

	virtual void					Ecrire (int lIndentation);

#if defined SYNTHESE_PILUM
	void								Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */

protected:

	Chaine							fNom;

	};	//	OperateurZeroaire
	
	
// -------------------------------------------------------------------------
//	OperateurUnaire
// -------------------------------------------------------------------------

class OperateurUnaire : public DescrSemantique
	{
public:

										OperateurUnaire (
											Chaine						leNom,
											VariableLogiqueTypePTR	leTypeLogique,
											DescrSemantiquePTR		lOperande );

	virtual							~ OperateurUnaire ();
	
	DescrSemantiquePTR			Operande ();

	virtual void					Ecrire (int lIndentation);
	virtual void					PostFixer ();

#if defined SYNTHESE_PILUM
	void								Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */

protected:

	Chaine							fNom;
	DescrSemantiquePTR			fOperande;

	};	//	OperateurUnaire
	

inline
DescrSemantiquePTR
OperateurUnaire :: Operande ()
	{ return fOperande; }


// -------------------------------------------------------------------------
//	OperateurBinaire
// -------------------------------------------------------------------------

class		OperateurBinaire;
typedef	OperateurBinaire		* OperateurBinairePTR;

class OperateurBinaire : public DescrSemantique
	{
public:

										OperateurBinaire (
											Chaine						leNom,
											VariableLogiqueTypePTR	leTypeLogique,
											DescrSemantiquePTR		lOperandeGauche,
											DescrSemantiquePTR		lOperandeDroit );

	virtual							~ OperateurBinaire ();
	
	DescrSemantiquePTR				OperandeGauche ();
	DescrSemantiquePTR				OperandeDroit ();

	virtual void					Ecrire (int lIndentation);
	virtual void					PostFixer ();

#if defined SYNTHESE_PILUM
	void								Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */

protected:

	Chaine							fNom;
	DescrSemantiquePTR			fOperandeGauche;
	DescrSemantiquePTR			fOperandeDroit;

	};	//	OperateurBinaire


inline
DescrSemantiquePTR
OperateurBinaire :: OperandeGauche ()
	{ return fOperandeGauche; }

inline
DescrSemantiquePTR
OperateurBinaire :: OperandeDroit ()
	{ return fOperandeDroit; }


// -------------------------------------------------------------------------
//	OperateurTernaire
// -------------------------------------------------------------------------

class		OperateurTernaire;
typedef	OperateurTernaire		* OperateurTernairePTR;

class OperateurTernaire : public DescrSemantique
	{
public:

										OperateurTernaire (
											Chaine						leNom,
											VariableLogiqueTypePTR	leTypeLogique,
											DescrSemantiquePTR		lOperandeGauche,
											DescrSemantiquePTR		lOperandeMedian,
											DescrSemantiquePTR		lOperandeDroit );

	virtual							~ OperateurTernaire ();
	
	DescrSemantiquePTR				OperandeGauche ();
	DescrSemantiquePTR				OperandeMedian ();
	DescrSemantiquePTR				OperandeDroit ();

	virtual void					Ecrire (int lIndentation);
	virtual void					PostFixer ();

#if defined SYNTHESE_PILUM
	void								Synthetiser (
											ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */

protected:

	Chaine							fNom;
	DescrSemantiquePTR			fOperandeGauche;
	DescrSemantiquePTR			fOperandeMedian;
	DescrSemantiquePTR			fOperandeDroit;

	};	//	OperateurTernaire


inline
DescrSemantiquePTR
OperateurTernaire :: OperandeGauche ()
	{ return fOperandeGauche; }

inline
DescrSemantiquePTR
OperateurTernaire :: OperandeMedian ()
	{ return fOperandeMedian; }

inline
DescrSemantiquePTR
OperateurTernaire :: OperandeDroit ()
	{ return fOperandeDroit; }


#endif /* __OperateursNAires__ */
