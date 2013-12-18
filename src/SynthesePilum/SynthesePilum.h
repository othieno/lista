// =========================================================================
//	SynthesePilum.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __SynthesePilum__
#define __SynthesePilum__

#include "Pilum.h"

#include "SupportCPlusPlus.h"

#include <iostream>

#include <list>


// -------------------------------------------------------------------------
//	Pre-declarations
// -------------------------------------------------------------------------

class		SynthetiseurPilum;
typedef	SynthetiseurPilum		* SynthetiseurPilumPTR;


// -------------------------------------------------------------------------
//	InstructionOuEtiquette
// -------------------------------------------------------------------------

class		InstructionOuEtiquette;
typedef	InstructionOuEtiquette	* InstructionOuEtiquettePTR;

class InstructionOuEtiquette
	{
public:
										InstructionOuEtiquette ();

	virtual							~ InstructionOuEtiquette ();


	virtual Chaine					SousFormeDeChaine () = 0;
								 			//	virtuelle pure

	virtual void				 	EcrireBinaire (std::ofstream * leFichier) = 0;
											//	virtuelle pure

	virtual bool					SemantiquementVide ();
											// pour certaines instructions,
											//	en vue de la suppression par Optimiser ()

	virtual void					DeterminerLAdresseAbsolue (
											AdresseDansLeCode
														& lAdresseCourante,
											long		& leNombreDInstructions ) = 0;
								 			//	virtuelle pure
											// pour etiquettes et instructions

	virtual void					PropagerLesLiaisonsNonAdresses ();
											// pour les instructions concernees
	virtual void					PropagerLesLiaisonsAdresses ();
											// pour les instructions concernees

	virtual void					EcrireLesChaines (
											std::ofstream			* leFichier,
											SynthetiseurPilumPTR	leSynthetiseurPilum,
											long						& laPositionCourante );

	};	//	InstructionOuEtiquette


typedef std::list <InstructionOuEtiquettePTR>	ListeDesInstructionOuEtiquette;
typedef ListeDesInstructionOuEtiquette				* ListeDesInstructionOuEtiquettePTR;


// -------------------------------------------------------------------------
//	Etiquette
// -------------------------------------------------------------------------

class		Etiquette;
typedef	Etiquette				* EtiquettePTR;

class Etiquette : public InstructionOuEtiquette
	{
public:
										Etiquette (long leNumeroEtiquette = 0);

	virtual							~ Etiquette ();


	virtual Chaine					SousFormeDeChaine ();

	virtual void					EcrireBinaire (std::ofstream * leFichier);

	virtual bool					SemantiquementVide ();

	virtual void					DeterminerLAdresseAbsolue (
											AdresseDansLeCode
														& lAdresseCourante,
											long		& leNombreDInstructions );
	AdresseDansLeCode				AdresseAbsolue ();


protected:

	long								fNumeroEtiquette;
	AdresseDansLeCode				fAdresseAbsolue;

	};	//	Etiquette


// -------------------------------------------------------------------------
//	VariableLogiqueEtiquette
// -------------------------------------------------------------------------

typedef	VariableLogique <Etiquette>	VariableLogiqueEtiquette;
typedef	VariableLogiqueEtiquette		* VariableLogiqueEtiquettePTR;


// -------------------------------------------------------------------------
//	Instruction
// -------------------------------------------------------------------------

class		Instruction;
typedef	Instruction				* InstructionPTR;

class Instruction : public InstructionOuEtiquette
	{
public:
										Instruction (CodeOpPilum	leCodeOpPilum);

	virtual							~ Instruction ();

	InstructionPilum				LInstructionPilum ();

	virtual int						TailleInstruction ();

	virtual Chaine					SousFormeDeChaine ();

	virtual void					EcrireBinaire (std::ofstream * leFichier);

	virtual bool					SemantiquementVide ();

	virtual void					DeterminerLAdresseAbsolue (
											AdresseDansLeCode
														& lAdresseCourante,
											long		& leNombreDInstructions );

protected:

	InstructionPilum				fInstructionPilum;

	};	//	Instruction


// -------------------------------------------------------------------------
//	InstrAvecChaine
// -------------------------------------------------------------------------

class		InstrAvecChaine;
typedef	InstrAvecChaine		* InstrAvecChainePTR;

class InstrAvecChaine : public Instruction
	{
public:
										InstrAvecChaine (
											CodeOpPilum		leCodeOpPilum,
											Chaine			laChaine );

	virtual							~ InstrAvecChaine ();

	virtual void					EcrireBinaire (std::ofstream * leFichier);

	CharPTR							ArgumentChaine ();
	void								DeplacementDansTable (long leDeplacement);

	virtual void					EcrireLesChaines (
											std::ofstream			* leFichier,
											SynthetiseurPilumPTR	leSynthetiseurPilum,
											long						& laPositionCourante );


protected:
	
	long								fDeplacementDansTable;

	};	//	InstrAvecChaine


// -------------------------------------------------------------------------
//	InstrCommentaire
// -------------------------------------------------------------------------

class		InstrCommentaire;
typedef	InstrCommentaire		* InstrCommentairePTR;

class InstrCommentaire : public InstrAvecChaine
	{
public:
										InstrCommentaire (Chaine leCommentaire);

	virtual							~ InstrCommentaire ();

	};	//	InstrCommentaire


// -------------------------------------------------------------------------
//	InstrAvecVariableLogiqueEntiere
// -------------------------------------------------------------------------

class		InstrAvecVariableLogiqueEntiere;
typedef	InstrAvecVariableLogiqueEntiere	* InstrAvecVariableLogiqueEntierePTR;

class InstrAvecVariableLogiqueEntiere : public Instruction
	{
public:
										InstrAvecVariableLogiqueEntiere (
											CodeOpPilum
														leCodeOpPilum,
											VariableLogiqueEntierePTR
														laVariableLogiqueEntiere );

	virtual							~ InstrAvecVariableLogiqueEntiere ();


	VariableLogiqueEntierePTR	LaVariableLogiqueEntiere ();

	virtual void					FixerArgumentEntier (
											ValeurEntierePTR laValeurEntiere );

	virtual void					PropagerLesLiaisonsNonAdresses ();


protected:

	VariableLogiqueEntierePTR	fVariableLogiqueEntiere;

	};	//	InstrAvecVariableLogiqueEntiere


// -------------------------------------------------------------------------
//	InstrReserver
// -------------------------------------------------------------------------

class		InstrReserver;
typedef	InstrReserver			* InstrReserverPTR;

class InstrReserver : public InstrAvecVariableLogiqueEntiere
	{
public:
										InstrReserver (
											VariableLogiqueEntierePTR
														leNombreLogiqueDeCellules );

	virtual							~ InstrReserver ();


	virtual bool					SemantiquementVide ();

	};	//	InstrReserver


// -------------------------------------------------------------------------
//	InstrDesempiler
// -------------------------------------------------------------------------

class		InstrDesempiler;
typedef	InstrDesempiler		* InstrDesempilerPTR;

class InstrDesempiler : public InstrAvecVariableLogiqueEntiere
	{
public:
										InstrDesempiler (
											VariableLogiqueEntierePTR
														leNombreLogiqueDeCellules );

	virtual							~ InstrDesempiler ();


	virtual bool					SemantiquementVide ();

	};	//	InstrDesempiler


// -------------------------------------------------------------------------
//	InstrAccesCellule
// -------------------------------------------------------------------------

class		InstrAccesCellule;
typedef	InstrAccesCellule		* InstrAccesCellulePTR;

class InstrAccesCellule : public Instruction
	{
public:
										InstrAccesCellule (
											AccesStatique	lAccesStatique,
											CodeOpPilum		leCodeOpPilum );

										InstrAccesCellule (
											int				laDifferenceStatique,
											int				leDeplacement,
											CodeOpPilum		leCodeOpPilum );

	virtual							~ InstrAccesCellule ();
	};


// -------------------------------------------------------------------------

class InstrAccesCellulePourValeur : public InstrAccesCellule
	{
public:
										InstrAccesCellulePourValeur (
											AccesStatique	lAccesStatique );

	virtual							~ InstrAccesCellulePourValeur ();
	};


class InstrAccesCellulePourAdresse : public InstrAccesCellule
	{
public:
										InstrAccesCellulePourAdresse (
											AccesStatique	lAccesStatique );

	virtual							~ InstrAccesCellulePourAdresse ();
	};


class InstrAccesCellulePourLienStatique : public InstrAccesCellule
	{
public:
										InstrAccesCellulePourLienStatique (
											int	laDifferenceStatique );

	virtual							~ InstrAccesCellulePourLienStatique ();
	};


// -------------------------------------------------------------------------
//	InstrEmpilage
// -------------------------------------------------------------------------

class		InstrEmpilage;
typedef	InstrEmpilage			* InstrEmpilagePTR;

class InstrEmpilage : public Instruction
	{
public:
										InstrEmpilage (long lEntier);
										InstrEmpilage (
											CodeOpPilum		leCodeOpPilum,
											long				lEntier );

										InstrEmpilage (double leFlottant);
										InstrEmpilage (bool leBooleen);
										InstrEmpilage (char leCaractere);

										InstrEmpilage ();	//	valeur inconnue

	virtual							~ InstrEmpilage ();

	};	//	InstrEmpilage


// -------------------------------------------------------------------------
//	InstrEmpilageChaine
// -------------------------------------------------------------------------

class		InstrEmpilageChaine;
typedef	InstrEmpilageChaine	* InstrEmpilageChainePTR;

class InstrEmpilageChaine : public InstrAvecChaine
	{
public:
										InstrEmpilageChaine (Chaine laChaine);

	virtual							~ InstrEmpilageChaine ();

	};	//	InstrEmpilageChaine


// -------------------------------------------------------------------------
//	InstrSaut
// -------------------------------------------------------------------------

class		InstrSaut;
typedef	InstrSaut				* InstrSautPTR;

class InstrSaut : public Instruction
	{
public:
										InstrSaut (
											CodeOpPilum
														leCodeOpPilum,
											VariableLogiqueEtiquettePTR
														laDestination );

										InstrSaut (
											VariableLogiqueEtiquettePTR laDestination );

	virtual							~ InstrSaut ();

	VariableLogiqueEtiquettePTR
										Destination ();

	virtual void					FixerAdresseDeSaut (AdresseDansLeCode lAdresse);

	virtual Chaine					SousFormeDeChaine ();

	virtual void					PropagerLesLiaisonsAdresses ();


protected:

	VariableLogiqueEtiquettePTR					fDestination;

	};	//	InstrSaut


// -------------------------------------------------------------------------
//	InstrAppel
// -------------------------------------------------------------------------

class		InstrAppel;
typedef	InstrAppel				* InstrAppelPTR;

class InstrAppel : public Instruction
	{
public:
										InstrAppel (
											VariableLogiqueEtiquettePTR laDestination );

	virtual							~ InstrAppel ();

	VariableLogiqueEtiquettePTR
										Destination ();

	virtual void					FixerAdresseDAppel (AdresseDansLeCode lAdresse);

	virtual Chaine					SousFormeDeChaine ();

	virtual void					PropagerLesLiaisonsAdresses ();


protected:

	VariableLogiqueEtiquettePTR
										fDestination;

	};	//	InstrAppel


// -------------------------------------------------------------------------
//	InstrEmpilerDescripteurDeThunk
// -------------------------------------------------------------------------

class		InstrEmpilerDescripteurDeThunk;
typedef	InstrEmpilerDescripteurDeThunk	* InstrEmpilerDescripteurDeThunkPTR;

class InstrEmpilerDescripteurDeThunk : public Instruction
	//	pour pouvoir empiler l'adresse d'un thunk
	{
public:
										InstrEmpilerDescripteurDeThunk (
											VariableLogiqueEtiquettePTR leCorpsDuThunk );

	virtual							~ InstrEmpilerDescripteurDeThunk ();

	VariableLogiqueEtiquettePTR
										CorpsDuThunk ();

	virtual void					FixerAdresseDuThunk (AdresseDansLeCode lAdresse);

	virtual Chaine					SousFormeDeChaine ();

	virtual void					PropagerLesLiaisonsAdresses ();


protected:

	VariableLogiqueEtiquettePTR
										fCorpsDuThunk;

	};	//	InstrEmpilerDescripteurDeThunk


// --------------------------------------------------------------------------
//	OptionsSynthese
// --------------------------------------------------------------------------

class		OptionsSynthese;
typedef	OptionsSynthese		* OptionsSynthesePTR;

class OptionsSynthese
	{
public:
										OptionsSynthese (
											bool	leModeVerbeux,
											bool	leModeDebug,
											bool	leMontrerLeCode,
											bool	leCommenterLeCode,
											bool	leMarquerLesBlocsDActivation,
											bool	leOptimiserLesSauts );

	bool								ModeVerbeux ();
	bool								ModeDebug ();
	bool								MontrerLeCode ();
	bool								CommenterLeCode ();
	bool								MarquerLesBlocsDActivation ();
	bool								OptimiserLesSauts ();

private:
	
	bool								fModeVerbeux;
	bool								fModeDebug;
	bool								fMontrerLeCode;
	bool								fCommenterLeCode;
	bool								fMarquerLesBlocsDActivation;
	bool								fOptimiserLesSauts;

	};	//	OptionsSynthese


inline
bool
OptionsSynthese :: ModeVerbeux ()
	{ return fModeVerbeux; }

inline
bool
OptionsSynthese :: ModeDebug ()
	{ return fModeDebug; }

inline
bool
OptionsSynthese :: MontrerLeCode ()
	{ return fMontrerLeCode; }

inline
bool
OptionsSynthese :: CommenterLeCode ()
	{ return fCommenterLeCode; }

inline
bool
OptionsSynthese :: MarquerLesBlocsDActivation ()
	{ return fMarquerLesBlocsDActivation; }

inline
bool
OptionsSynthese :: OptimiserLesSauts ()
	{ return fOptimiserLesSauts; }


// -------------------------------------------------------------------------
//	SynthetiseurPilum
// -------------------------------------------------------------------------

class SynthetiseurPilum
	{
public:

										SynthetiseurPilum (
											Chaine					leNom,
											OptionsSynthesePTR	lesOptionsSynthese );

	virtual							~ SynthetiseurPilum ();


	//	Gestion des étiquettes
	//	----------------------
	VariableLogiqueEtiquettePTR
										CreerEtiquette (Chaine leSuffixe);

	void								PlacerEtiquette (
											VariableLogiqueEtiquettePTR
													laVariableLogiqueEtiquettePTR );


	//	Synthèse des instructions
	//	-------------------------

	void								Commentaire (Chaine leCommentaire);

	void								Zeroadique (CodeOpPilum leCodeOpPilum);

	void								Saut (VariableLogiqueEtiquettePTR lEtiquette);

	void								Saut (
											CodeOpPilum							leCodeOpPilum,
											VariableLogiqueEtiquettePTR	lEtiquette );

	void								ReserverCellules (
											VariableLogiqueEntierePTR
													leNombreLogiqueDeCellules );
	void								DetruireCellules (
											VariableLogiqueEntierePTR
													leNombreLogiqueDeCellules );

	void								AccesCellulePourValeur (
											AccesStatique	lAccesStatique );
	void								AccesCellulePourValeur (
											int	laDifferenceStatique,
											int	leDeplacement );

	void								AccesCellulePourAdresse (
											AccesStatique	lAccesStatique );
	void								AccesCellulePourAdresse (
											int	laDifferenceStatique,
											int	leDeplacement );

	void								AccesCellulePourLienStatique (
											int	laDifferenceStatique );
	
	void								Entier (long lEntier);
	void								Entier (
											CodeOpPilum		leCodeOpPilum,
											long				lEntier );
	void								Flottant (double leFlottant);
	void								Logique (bool leLogique);
	void								Caractere (char leCaractere);
	void								Chaine_ (Chaine laChaine);
	void								ValeurInconnue ();
	
	void								Empiler (long leNombreDeCellules);
	void								Desempiler (long leNombreDeCellules);

	void								MarquerBlocDActivation (Chaine nomDeLaFonction);
	void								Appel (VariableLogiqueEtiquettePTR lEtiquette);

	void								LienStatique (
											int		niveauDAppel,
											int		niveauDeDeclaration );

	void								EmpilerDescripteurDeThunk (
											VariableLogiqueEtiquettePTR lEtiquette );
	void								EvaluerThunk (
											Chaine	leNomDuParametre,
											bool		marquerLeBlocDActivation );
	

	//	Finalisation du code
	//	--------------------
	
	virtual void					FinaliserLeCodePilum ();


	//	Production d'une vue "assembleur" du code
	//	-----------------------------------------
	
	virtual void					EcrireLeCodeEnTexte (
											Chaine			leFormatDuTitre,
											std::ostream *	leFlot,
											bool				afficherLesAdressesDeControle );
	virtual void					EcrireLeCodeEnTexte (
											Chaine			leFormatDuTitre,
											Chaine			nomDuFichierTexte,
											bool				afficherLesAdressesDeControle );


	//	Ecriture du code binaire sur un fichier
	//	---------------------------------------

	long								TailleAEcrirePour (Chaine laChaine);

	virtual void					EcrireCodeBinaireSurLeFichier (
											std::ofstream * leFichier) ;
	virtual void					EcrireCodeBinaireSurLeFichier (
											Chaine nomDuFichierBinaire );


protected:

	Chaine							fNom;

	ListeDesInstructionOuEtiquettePTR
										fListeDesInstructionOuEtiquette;

	long								fNombreDInstructions;

	long								fTailleDesChaines;
	long								fCompteurEtiquettes;
	
	void								Inserer (
											InstructionOuEtiquettePTR lInstructionOuEtiquette );

	void								EcrireLesChaines (std::ofstream * leFichier);
	void								EcrireLesInstructions (std::ofstream * leFichier);

	void								PropagerLesLiaisonsDesVariablesLogiquesNonAdresses ();
	void								DeterminerLesAdressesAbsolues ();
	void								PropagerLesLiaisonsDesVariablesLogiquesAdresses ();

	virtual void					OptimiserLeCode ();


	OptionsSynthesePTR			fOptionsSynthese;

	};	//	SynthetiseurPilum


#endif /* __SynthesePilum__ */
