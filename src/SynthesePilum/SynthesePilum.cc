// ========================================================================file://localhost/Users/menu/Documents/CUI/Cours_Lista/ListaSourceDeReference/PilumMain.cc=
//	SynthesePilum.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Langues.h"

#include "LanguesSynthesePilum.h"
#include "SynthesePilum.h"

#include <ostream>
	
#include <cstdlib>

#include <cstring>


// -------------------------------------------------------------------------
//	InstructionOuEtiquette
// -------------------------------------------------------------------------

InstructionOuEtiquette :: InstructionOuEtiquette ()
	{}

InstructionOuEtiquette :: ~ InstructionOuEtiquette ()
	{}


bool
InstructionOuEtiquette :: SemantiquementVide ()
	{ return false; }


void					
InstructionOuEtiquette :: PropagerLesLiaisonsNonAdresses ()
	{}
void					
InstructionOuEtiquette :: PropagerLesLiaisonsAdresses ()
	{}

void
InstructionOuEtiquette :: EcrireLesChaines (
	std::ofstream			* leFichier,
	SynthetiseurPilumPTR	leSynthetiseurPilum,
	long						& laPositionCourante )
	{}


// -------------------------------------------------------------------------
//	Etiquette
// -------------------------------------------------------------------------

Etiquette :: Etiquette (long leNumeroEtiquette)
	: InstructionOuEtiquette ()
	{
	fNumeroEtiquette = leNumeroEtiquette;
	fAdresseAbsolue = -1;
	}

Etiquette :: ~ Etiquette ()
	{}


void
Etiquette :: EcrireBinaire (std::ofstream * leFichier)
	{
	//	RIEN A FAIRE!
	}

bool
Etiquette :: SemantiquementVide ()
	{
	return false;
		//	sans cela, elle serait ecremee par l'optimisation
	}


void
Etiquette :: DeterminerLAdresseAbsolue (
	AdresseDansLeCode
				& lAdresseCourante,
	long		& leNombreDInstructions )
	{ fAdresseAbsolue = lAdresseCourante; }

AdresseDansLeCode
Etiquette :: AdresseAbsolue ()
	{ return fAdresseAbsolue; }



Chaine
Etiquette :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			"%4d:    // -- %s --",
			AdresseAbsolue (),
			MiseEnForme (
				gLANGUE_SynthesePilum ->
					FormatDescriptionEtiquette (),
				fNumeroEtiquette ) );
	}


// -------------------------------------------------------------------------
//	Instruction
// -------------------------------------------------------------------------

Instruction :: Instruction (CodeOpPilum	leCodeOpPilum)
	: InstructionOuEtiquette ()
	{ fInstructionPilum.fCodeOpPilum = leCodeOpPilum; }

Instruction :: ~ Instruction ()
	{}


InstructionPilum
Instruction :: LInstructionPilum ()
	{ return fInstructionPilum; }

int
Instruction :: TailleInstruction ()
	{ return 1; }


void
Instruction :: EcrireBinaire (std::ofstream * leFichier)
	{
	leFichier -> write (
		(CharPTR) & fInstructionPilum, kTailleInstructionPilum );
	}

bool
Instruction :: SemantiquementVide ()
	{ return false; }

void
Instruction :: DeterminerLAdresseAbsolue (
	AdresseDansLeCode
				& lAdresseCourante,
	long		& leNombreDInstructions )
	{
	++ leNombreDInstructions;
	lAdresseCourante += TailleInstruction ();

/*	JMI
	std::cout <<
		MiseEnForme (
			"leNombreDInstructions = %d, lAdresseCourante = %d",
			leNombreDInstructions, lAdresseCourante ) <<
			this -> SousFormeDeChaine ();
*/
	}

Chaine
Instruction :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			"         %s",
			fInstructionPilum.SousFormeDeChaine () );
	}


// -------------------------------------------------------------------------
//	InstrAvecChaine
// -------------------------------------------------------------------------

InstrAvecChaine :: InstrAvecChaine (
	CodeOpPilum		leCodeOpPilum,
	Chaine			laChaine )
	: Instruction (leCodeOpPilum)
	{
	fInstructionPilum.fChaine = strdup (laChaine.c_str ());
	fDeplacementDansTable = 0;
	}

InstrAvecChaine :: ~ InstrAvecChaine ()
	{}


void
InstrAvecChaine :: EcrireBinaire (std::ofstream * leFichier)
	{
	CharPTR
				ancienneChaine = fInstructionPilum.fChaine;
					//	sera ecrase car on a une union!

	//	avant de l'ecrire, on remplace la chaine argument
	//	par un deplacement dans la table des chaines
	fInstructionPilum.fEntier = fDeplacementDansTable;

	Instruction :: EcrireBinaire (leFichier);

	//	on restaure la valeur de fChaine
	fInstructionPilum.fChaine = ancienneChaine;
	}

CharPTR
InstrAvecChaine :: ArgumentChaine ()
	{ return fInstructionPilum.fChaine; }

void
InstrAvecChaine :: DeplacementDansTable (long leDeplacement)
	{ fDeplacementDansTable = leDeplacement; }

void
InstrAvecChaine :: EcrireLesChaines (
	std::ofstream			* leFichier,
	SynthetiseurPilumPTR	leSynthetiseurPilum,
	long						& laPositionCourante )
	{
	CharPTR
				laChaine = ArgumentChaine ();

	DeplacementDansTable (laPositionCourante);

	long		laTaille =
					leSynthetiseurPilum -> TailleAEcrirePour (laChaine);

	leFichier -> write (laChaine, laTaille);

	laPositionCourante += laTaille;
	}	// InstrAvecChaine :: EcrireLesChaines


// -------------------------------------------------------------------------
//	InstrCommentaire
// -------------------------------------------------------------------------

InstrCommentaire :: InstrCommentaire (Chaine leCommentaire)
	: InstrAvecChaine (iCommentaire, leCommentaire)
	{}

InstrCommentaire :: ~ InstrCommentaire ()
	{}


// -------------------------------------------------------------------------
//	InstrAvecVariableLogiqueEntiere
// -------------------------------------------------------------------------

InstrAvecVariableLogiqueEntiere :: InstrAvecVariableLogiqueEntiere (
	CodeOpPilum
				leCodeOpPilum,
	VariableLogiqueEntierePTR
				laVariableLogiqueEntiere )
	: Instruction (leCodeOpPilum)
	{
	fVariableLogiqueEntiere = laVariableLogiqueEntiere;
	}

InstrAvecVariableLogiqueEntiere :: ~ InstrAvecVariableLogiqueEntiere ()
	{}


VariableLogiqueEntierePTR
InstrAvecVariableLogiqueEntiere :: LaVariableLogiqueEntiere ()
	{ return fVariableLogiqueEntiere; }

void
InstrAvecVariableLogiqueEntiere :: FixerArgumentEntier (
	ValeurEntierePTR laValeurEntiere )
	{
	fInstructionPilum.fEntier = laValeurEntiere -> Valeur ();
	}

void					
InstrAvecVariableLogiqueEntiere :: PropagerLesLiaisonsNonAdresses ()
	{
	if (fVariableLogiqueEntiere -> EstLibre ())
		SortieSurErreur (
			gLANGUE_SynthesePilum ->
				VariableLogiqueEntiereEstLibre (),
			39 );
	else
		FixerArgumentEntier (
			fVariableLogiqueEntiere -> ValeurDeLiaison () );
	}


// -------------------------------------------------------------------------
//	InstrReserver
// -------------------------------------------------------------------------

InstrReserver :: InstrReserver (
	VariableLogiqueEntierePTR
				leNombreLogiqueDeCellules )
	: InstrAvecVariableLogiqueEntiere (
		iReserver,
		leNombreLogiqueDeCellules )
	{}

InstrReserver :: ~ InstrReserver ()
	{}


bool
InstrReserver :: SemantiquementVide ()
	{
	return fInstructionPilum.fEntier == 0;
	}


// -------------------------------------------------------------------------
//	InstrDesempiler
// -------------------------------------------------------------------------

InstrDesempiler :: InstrDesempiler (
	VariableLogiqueEntierePTR
				leNombreLogiqueDeCellules )
	: InstrAvecVariableLogiqueEntiere (
		iDesempiler,
		leNombreLogiqueDeCellules )
	{}

InstrDesempiler :: ~ InstrDesempiler ()
	{}


bool
InstrDesempiler :: SemantiquementVide ()
	{
	return fInstructionPilum.fEntier == 0;
	}


// -------------------------------------------------------------------------
//	InstrAccesCellule
// -------------------------------------------------------------------------

InstrAccesCellule :: InstrAccesCellule (
	AccesStatique	lAccesStatique,
	CodeOpPilum		leCodeOpPilum )
	: Instruction (leCodeOpPilum)
	{ fInstructionPilum.fAccesStatique = lAccesStatique; }

InstrAccesCellule :: InstrAccesCellule (
	int				laDifferenceStatique,
	int				leDeplacement,
	CodeOpPilum		leCodeOpPilum )
	: Instruction (leCodeOpPilum)
	{
	AccesStatique		lAccesStatique;
	
	lAccesStatique.fDifferenceStatique = laDifferenceStatique;
	lAccesStatique.fDeplacement = leDeplacement;
	
	fInstructionPilum.fAccesStatique = lAccesStatique;
	}

InstrAccesCellule :: ~ InstrAccesCellule ()
	{}


// -------------------------------------------------------------------------

InstrAccesCellulePourValeur :: InstrAccesCellulePourValeur (
	AccesStatique	lAccesStatique )
	: InstrAccesCellule (lAccesStatique, iEmpilerValeur)
	{}

InstrAccesCellulePourValeur :: ~ InstrAccesCellulePourValeur ()
	{}


// -------------------------------------------------------------------------

InstrAccesCellulePourAdresse :: InstrAccesCellulePourAdresse (
	AccesStatique	lAccesStatique )
	: InstrAccesCellule (lAccesStatique, iEmpilerAdresse)
	{}

InstrAccesCellulePourAdresse :: ~ InstrAccesCellulePourAdresse ()
	{}

// -------------------------------------------------------------------------

InstrAccesCellulePourLienStatique :: InstrAccesCellulePourLienStatique (
	int	laDifferenceStatique )
	: InstrAccesCellule (laDifferenceStatique, 0, iEmpilerLienStatique)
	{}

InstrAccesCellulePourLienStatique :: ~ InstrAccesCellulePourLienStatique ()
	{}


// -------------------------------------------------------------------------
//	InstrEmpilage
// -------------------------------------------------------------------------

InstrEmpilage :: InstrEmpilage (long lEntier)
	: Instruction (iEmpilerEntier)
	{ fInstructionPilum.fEntier = lEntier; }
	
InstrEmpilage :: InstrEmpilage (
	CodeOpPilum		leCodeOpPilum,
	long				lEntier )
	: Instruction (leCodeOpPilum)
	{ fInstructionPilum.fEntier = lEntier; }


InstrEmpilage :: InstrEmpilage (double leFlottant)
	: Instruction (iEmpilerFlottant)
	{ fInstructionPilum.fFlottant = leFlottant; }

InstrEmpilage :: InstrEmpilage (bool leBooleen)
	: Instruction (iEmpilerBooleen)
	{ fInstructionPilum.fBooleen = leBooleen; }

InstrEmpilage :: InstrEmpilage (char leCaractere)
	: Instruction (iEmpilerCaractere)
	{ fInstructionPilum.fCaractere = leCaractere; }


InstrEmpilage :: InstrEmpilage ()
	//	valeur inconnue
	: Instruction (iEmpilerValInconnue)
	{}


InstrEmpilage :: ~ InstrEmpilage ()
	{}


// -------------------------------------------------------------------------
//	InstrEmpilageChaine
// -------------------------------------------------------------------------

InstrEmpilageChaine :: InstrEmpilageChaine (Chaine laChaine)
	: InstrAvecChaine (iEmpilerChaine, laChaine)
	{}

InstrEmpilageChaine :: ~ InstrEmpilageChaine ()
	{}


// -------------------------------------------------------------------------
//	InstrSaut
// -------------------------------------------------------------------------

InstrSaut :: InstrSaut (
	CodeOpPilum			leCodeOpPilum,
	VariableLogiqueEtiquettePTR		laDestination )
	:	Instruction (leCodeOpPilum)
	{ fDestination = laDestination; }

InstrSaut :: InstrSaut (VariableLogiqueEtiquettePTR laDestination)
	:	Instruction (iSauter)
	{ fDestination = laDestination; }

InstrSaut :: ~ InstrSaut ()
	{}


VariableLogiqueEtiquettePTR
InstrSaut :: Destination ()
	{ return fDestination; }

void
InstrSaut :: FixerAdresseDeSaut (AdresseDansLeCode lAdresse)
	{ fInstructionPilum.fAdresseDansLeCode = lAdresse; }

Chaine
InstrSaut :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			"         %s\t// %s",
		fInstructionPilum.SousFormeDeChaine (),
		Destination () -> SousFormeDeChaine () );
	}

void					
InstrSaut :: PropagerLesLiaisonsAdresses ()
	{
	if (fDestination -> EstLibre ())
		SortieSurErreur (
			gLANGUE_SynthesePilum ->
				DestinationDeSautEstLibre (),
			40 );
	else
		FixerAdresseDeSaut (
			fDestination -> ValeurDeLiaison () -> AdresseAbsolue () );
	}


// -------------------------------------------------------------------------
//	InstrAppel
// -------------------------------------------------------------------------

InstrAppel :: InstrAppel (VariableLogiqueEtiquettePTR laDestination)
	:	Instruction (iAppel)
	{ fDestination = laDestination; }

InstrAppel :: ~ InstrAppel ()
		{}


VariableLogiqueEtiquettePTR
InstrAppel :: Destination ()
	{ return fDestination; }

void
InstrAppel :: FixerAdresseDAppel (AdresseDansLeCode lAdresse)
	{ fInstructionPilum.fAdresseDansLeCode = lAdresse; }


Chaine
InstrAppel :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			"         %s\t// %s",
		fInstructionPilum.SousFormeDeChaine (),
		Destination () -> SousFormeDeChaine () );
	}

void					
InstrAppel :: PropagerLesLiaisonsAdresses ()
	{
	if (fDestination -> EstLibre ())
		SortieSurErreur (
			gLANGUE_SynthesePilum ->
				InstructionDAppelInstructionLibre (),
			40 );
	else
		FixerAdresseDAppel (
			fDestination -> ValeurDeLiaison () -> AdresseAbsolue () );
	}


// -------------------------------------------------------------------------
//	InstrEmpilerDescripteurDeThunk
// -------------------------------------------------------------------------

InstrEmpilerDescripteurDeThunk :: InstrEmpilerDescripteurDeThunk (
	VariableLogiqueEtiquettePTR leCorpsDuThunk )
	:	Instruction (iEmpilerDescripteurDeThunk)
	{ fCorpsDuThunk = leCorpsDuThunk; }

InstrEmpilerDescripteurDeThunk :: ~ InstrEmpilerDescripteurDeThunk ()
	{}


VariableLogiqueEtiquettePTR
InstrEmpilerDescripteurDeThunk :: CorpsDuThunk ()
	{ return fCorpsDuThunk; }

void
InstrEmpilerDescripteurDeThunk :: FixerAdresseDuThunk (
	AdresseDansLeCode lAdresse )
	{ fInstructionPilum.fAdresseDansLeCode = lAdresse; }


Chaine
InstrEmpilerDescripteurDeThunk :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			"         %s\n\t\t// %s",
		fInstructionPilum.SousFormeDeChaine (),
		CorpsDuThunk () -> SousFormeDeChaine () );
	}

void					
InstrEmpilerDescripteurDeThunk :: PropagerLesLiaisonsAdresses ()
	{
	if (fCorpsDuThunk -> EstLibre ())
		SortieSurErreur (
			gLANGUE_SynthesePilum -> 
				DestinationDeThunkEstLibre (),
			1 );
	else
		FixerAdresseDuThunk (
			fCorpsDuThunk -> ValeurDeLiaison () -> AdresseAbsolue () );
	}


// --------------------------------------------------------------------------
//	OptionsSynthese
// --------------------------------------------------------------------------

OptionsSynthese :: OptionsSynthese (
	bool	leModeVerbeux,
	bool	leModeDebug,
	bool	leMontrerLeCode,
	bool	leCommenterLeCode,
	bool	leMarquerLesBlocsDActivation,
	bool	leOptimiserLesSauts )
	{
	fModeVerbeux = leModeVerbeux;
	fModeDebug = leModeDebug;
	fMontrerLeCode = leMontrerLeCode;
	fCommenterLeCode = leCommenterLeCode;
	fMarquerLesBlocsDActivation = leMarquerLesBlocsDActivation;
	fOptimiserLesSauts = leOptimiserLesSauts;
	}


// -------------------------------------------------------------------------
//	SynthetiseurPilum
// -------------------------------------------------------------------------

SynthetiseurPilum :: SynthetiseurPilum (
	Chaine					leNom,
	OptionsSynthesePTR	lesOptionsSynthese )
	{
	fNom = leNom;
	
	fListeDesInstructionOuEtiquette =
		new ListeDesInstructionOuEtiquette;

	fTailleDesChaines = 0;
	fCompteurEtiquettes = 0;

	fOptionsSynthese = lesOptionsSynthese;
	}

SynthetiseurPilum :: ~ SynthetiseurPilum ()
	{
	ListeDesInstructionOuEtiquette :: iterator
				i;
	
	for (
		i = fListeDesInstructionOuEtiquette -> begin ();
		i != fListeDesInstructionOuEtiquette -> end ();
		++ i )
		{
		delete (* i);		
		}	//	for
	}


// -------------------------------------------------------------------------

VariableLogiqueEtiquettePTR
SynthetiseurPilum :: CreerEtiquette (
	Chaine leSuffixe )
	{ return new VariableLogiqueEtiquette (leSuffixe); }

void
SynthetiseurPilum :: PlacerEtiquette (
	VariableLogiqueEtiquettePTR laVariableLogiqueEtiquettePTR )
	{
	if (
		!	laVariableLogiqueEtiquettePTR -> UnifierValeur (
				new Etiquette (++ fCompteurEtiquettes), false )
		)
		SortieSurErreur (
			gLANGUE_SynthesePilum ->
				PlacerEtiquetteEchecDUnification (),
			1 );

	Inserer (laVariableLogiqueEtiquettePTR -> ValeurDeLiaison ());
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: Inserer (
	InstructionOuEtiquettePTR lInstructionOuEtiquette )
	{
	fListeDesInstructionOuEtiquette -> 
		push_back (lInstructionOuEtiquette);
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: Commentaire (Chaine leCommentaire)
	{
	Inserer (new InstrCommentaire (leCommentaire));

	fTailleDesChaines +=
		TailleAEcrirePour (leCommentaire);
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: Zeroadique (CodeOpPilum leCodeOpPilum)
	{
	Inserer (new Instruction (leCodeOpPilum));
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: Saut (VariableLogiqueEtiquettePTR lEtiquette)
	{ Inserer (new InstrSaut (iSauter, lEtiquette)); }

void
SynthetiseurPilum :: Saut (
	CodeOpPilum
				leCodeOpPilum,
	VariableLogiqueEtiquettePTR
				laDestination )
	{
	Inserer (new InstrSaut (leCodeOpPilum, laDestination));
	}



// -------------------------------------------------------------------------

void
SynthetiseurPilum :: ReserverCellules (
	VariableLogiqueEntierePTR leNombreLogiqueDeCellules )
	{
	Inserer (
		new InstrReserver (leNombreLogiqueDeCellules) );
	}
														 
void
SynthetiseurPilum :: DetruireCellules (
	VariableLogiqueEntierePTR leNombreLogiqueDeCellules )
	{
	Inserer (
		new InstrDesempiler (leNombreLogiqueDeCellules) );
	}
														 

// -------------------------------------------------------------------------

void
SynthetiseurPilum :: AccesCellulePourValeur (
	AccesStatique			lAccesStatique )
	{
	Inserer (new InstrAccesCellulePourValeur (lAccesStatique));
	}

void
SynthetiseurPilum :: AccesCellulePourValeur (
	int						laDifferenceStatique,
	int						leDeplacement )
	{
	AccesStatique
				lAccesStatique;
	
	lAccesStatique.fDifferenceStatique = laDifferenceStatique;
	lAccesStatique.fDeplacement = leDeplacement;
	
	this -> AccesCellulePourValeur (lAccesStatique);
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: AccesCellulePourAdresse (
	AccesStatique			lAccesStatique )
	{
	Inserer (
		new InstrAccesCellulePourAdresse (lAccesStatique) );
	}

void
SynthetiseurPilum :: AccesCellulePourAdresse (
	int						laDifferenceStatique,
	int						leDeplacement )
	{
	AccesStatique
				lAccesStatique;
	
	lAccesStatique.fDifferenceStatique = laDifferenceStatique;
	lAccesStatique.fDeplacement = leDeplacement;
	
	this -> AccesCellulePourAdresse (lAccesStatique);
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: AccesCellulePourLienStatique (
	int	laDifferenceStatique )
	{
	Inserer (
		new InstrAccesCellulePourLienStatique (laDifferenceStatique) );
		// addresse de base du bloc d'activation, sans deplacement
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: Entier (long lEntier)
	{ Inserer (new InstrEmpilage (lEntier)); }

void
SynthetiseurPilum :: Entier (
	CodeOpPilum		leCodeOpPilum,
	long				lEntier )
	{ Inserer (new InstrEmpilage (leCodeOpPilum, lEntier)); }


void
SynthetiseurPilum :: Flottant (double leFlottant)
	{ Inserer (new InstrEmpilage (leFlottant)); }

void
SynthetiseurPilum :: Logique (bool leLogique)
	{ Inserer (new InstrEmpilage (leLogique)); }

void
SynthetiseurPilum :: Caractere (char leCaractere)
	{ Inserer (new InstrEmpilage (leCaractere)); }

void
SynthetiseurPilum :: Chaine_ (Chaine laChaine)
	{
	Inserer (new InstrEmpilageChaine (laChaine));

	fTailleDesChaines +=
		TailleAEcrirePour (laChaine);
	}


void
SynthetiseurPilum :: ValeurInconnue ()
	{ Inserer (new InstrEmpilage ()); }


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: Empiler (long leNombreDeCellules)
	{ Entier (iReserver, leNombreDeCellules); }

void
SynthetiseurPilum :: Desempiler (long leNombreDeCellules)
	{ Entier (iDesempiler, leNombreDeCellules); }


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: MarquerBlocDActivation (Chaine nomDeLaFonction)
	{
	Inserer (
		new InstrAvecChaine (
			iEmpilerMarqueBlocDActivation, nomDeLaFonction ));

	fTailleDesChaines +=
		TailleAEcrirePour (nomDeLaFonction);
	}
	

// -------------------------------------------------------------------------

void
SynthetiseurPilum :: Appel (VariableLogiqueEtiquettePTR lEtiquette)
	{ Inserer (new InstrAppel (lEtiquette)); }


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: LienStatique (
	int		niveauDAppel,
	int		niveauDeDeclaration )
	{
	this -> AccesCellulePourLienStatique (
		niveauDAppel - niveauDeDeclaration );
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: EmpilerDescripteurDeThunk (
	VariableLogiqueEtiquettePTR lEtiquette )
	{ Inserer (new InstrEmpilerDescripteurDeThunk (lEtiquette)); }


void
SynthetiseurPilum :: EvaluerThunk (
	Chaine	leNomQualifieDuParametre,
	bool		marquerLeBlocDActivation )
	{
	if (marquerLeBlocDActivation)
		{
		Inserer (
			new InstrAvecChaine (
				iEvaluerThunkAvecMarqueBlocDActivation,
				leNomQualifieDuParametre ));
		
		fTailleDesChaines +=
			TailleAEcrirePour (leNomQualifieDuParametre);
		}
	else
		Zeroadique (iEvaluerThunk);
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: FinaliserLeCodePilum ()
	{
	bool		modeDebugSynthese =
					fOptionsSynthese -> ModeDebug ();
	
	if (modeDebugSynthese)
		EcrireLeCodeEnTexte (
			gLANGUE_SynthesePilum ->
				FormatCodeSansLiaisonsNonAdresses (),
			& std::cout,
			true );

	PropagerLesLiaisonsDesVariablesLogiquesNonAdresses ();
		// peut rendre certaines instructions semantiquement vides

	if (modeDebugSynthese)
		EcrireLeCodeEnTexte (
			gLANGUE_SynthesePilum ->
				FormatCodeSansOptimisation (),
			& std::cout,
			true );

	OptimiserLeCode ();
		// enleve les instructions semantiquement vides

	if (modeDebugSynthese)
		EcrireLeCodeEnTexte (
			gLANGUE_SynthesePilum ->
				FormatCodeSansAdressesAbsolues (),
			& std::cout,
			true );

	DeterminerLesAdressesAbsolues ();

	if (modeDebugSynthese)
		EcrireLeCodeEnTexte (
			gLANGUE_SynthesePilum ->
				FormatCodeSansLiaisonsAdresses (),
			& std::cout,
			true );

	PropagerLesLiaisonsDesVariablesLogiquesAdresses ();
		// apres que les adresses absolues ont ete determinees

	if (modeDebugSynthese)
		EcrireLeCodeEnTexte (
			gLANGUE_SynthesePilum ->
				FormatCodeApresFinalisation (),
			& std::cout,
			true );

	}	// SynthetiseurPilum :: FinaliserLeCodePilum


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: EcrireLeCodeEnTexte (
	Chaine			leFormatDuTitre,
	std::ostream *	leFlot,
	bool				afficherLesAdressesDeControle )
	{
	Chaine	titre =
					MiseEnForme (
						leFormatDuTitre,
						fNombreDInstructions );

	Chaine	separateur =
					Chaine (titre.length (), '-');

	std::cout <<
		std::endl <<
		titre <<
		std::endl <<
		separateur <<
		std::endl << std::endl;

	ListeDesInstructionOuEtiquette :: iterator
				i;

	AdresseDansLeCode
				adresseDeControle = 0;
	
	for (
		i = fListeDesInstructionOuEtiquette -> begin ();
		i != fListeDesInstructionOuEtiquette -> end ();
		++ i )
		{
		if (afficherLesAdressesDeControle)
			{
			* leFlot <<
				MiseEnForme (
					"%4d:  ",
					adresseDeControle ++ );
			}	// if
		
		* leFlot <<
			((* i) ->
				SousFormeDeChaine ()) <<
			std::endl;

		if (afficherLesAdressesDeControle)
			{
			if (
				(* i)-> SemantiquementVide ()
				||
				dynamic_cast <EtiquettePTR> (* i) != NULL
				)
				adresseDeControle --;
			}	// if
		}	//	for

	std::cout <<
		separateur <<
		std::endl;
	}	//	SynthetiseurPilum :: EcrireLeCodeEnTexte


void
SynthetiseurPilum :: EcrireLeCodeEnTexte (
	Chaine			leFormatDuTitre,
	Chaine			nomDuFichierTexte,
	bool				afficherLesAdressesDeControle )
	{
	std::cout <<
		std::endl <<
		MiseEnForme (
			gLANGUE_SynthesePilum ->
				FormatCodeSynthetiseSurFichier (),
			nomDuFichierTexte ) <<
		std::endl;

	// On ouvre le fichier "nomDuFichierTexte"

	std::ofstream
				fichierTexte (
					nomDuFichierTexte.c_str (), std::ios_base :: out );

	if (! fichierTexte)
		{
		std::cerr <<
			MiseEnForme (
				gLANGUE_SynthesePilum ->
					FormatPasPuOuvrirLeFichierTexteEnEcriture (),
				nomDuFichierTexte ) <<
			std::endl;
		exit (1);
		}

	EcrireLeCodeEnTexte (
		leFormatDuTitre,
		& fichierTexte,
		afficherLesAdressesDeControle );

	fichierTexte.close (); 

	std::cout << "-----------------" << std::endl;
	}	//	SynthetiseurPilum :: EcrireLeCodeEnTexte


// -------------------------------------------------------------------------

long
SynthetiseurPilum :: TailleAEcrirePour (Chaine laChaine)
	{
	long		res = laChaine.length () + 1;
						//	'+ 1' pour le '\0' final

	if (res % 2 == 1)
		++ res;	//	alignement sur une taille paire
	
	return res;
	}


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: EcrireCodeBinaireSurLeFichier (std::ofstream * leFichier)
	{
	EcrireLesChaines (leFichier);
	EcrireLesInstructions (leFichier);
	}


void
SynthetiseurPilum :: EcrireCodeBinaireSurLeFichier (Chaine nomDuFichierBinaire)
	{
	//	On ouvre le fichier "nomDuFichierBinaire"

	std::ofstream
				fichierBinaire (
					nomDuFichierBinaire.c_str (), std::ios_base :: out );

	if (! fichierBinaire)
		{
		std::cerr <<
			MiseEnForme (
				gLANGUE_SynthesePilum ->
					FormatPasPuOuvrirLeFichierBinaireEnEcriture (),
				nomDuFichierBinaire ) <<
			std::endl;
		exit (1);
		}

	EcrireCodeBinaireSurLeFichier (& fichierBinaire);

	fichierBinaire.close (); 
	}	//	SynthetiseurPilum :: EcrireCodeBinaireSurLeFichier


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: EcrireLesChaines (std::ofstream * leFichier)
	{
	leFichier -> write (
		(CharPTR) & fTailleDesChaines, sizeof (long) );

	if (fOptionsSynthese -> ModeVerbeux ())
		std::cout <<
			gLANGUE_SynthesePilum ->
				TailleDesChaines () <<
			fTailleDesChaines <<
			std::endl;

	long		positionCourante = 0;

	ListeDesInstructionOuEtiquette :: iterator
				i;
	
	for (
		i = fListeDesInstructionOuEtiquette -> begin ();
		i != fListeDesInstructionOuEtiquette -> end ();
		++ i )
		{
		(* i) ->
			EcrireLesChaines (leFichier, this, positionCourante);
		}	//	for
	}	//	SynthetiseurPilum :: EcrireLesChaines


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: EcrireLesInstructions (std::ofstream * leFichier)
	{
	/*
	On n'utilise pas:
		long		leNombreDInstructions =
						fListeDesInstructionOuEtiquette -> size ();
	car cette liste contient aussi les etiquettes
	*/

	if (fOptionsSynthese -> ModeVerbeux ())
		std::cout <<
			gLANGUE_SynthesePilum ->
				NombreDInstructions () <<
			fNombreDInstructions <<
			std::endl;
	
	leFichier -> write (
		(CharPTR) & fNombreDInstructions, sizeof (long) );

	ListeDesInstructionOuEtiquette :: iterator
				i;
	
	for (
		i = fListeDesInstructionOuEtiquette -> begin ();
		i != fListeDesInstructionOuEtiquette -> end ();
		++ i )
		{
		(* i) ->
			EcrireBinaire (leFichier);
		}
	}	//	SynthetiseurPilum :: EcrireLesInstructions


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: DeterminerLesAdressesAbsolues ()
	//	a pour effet de bord de compter les instructions
	{
	AdresseDansLeCode
				lAdresseCourante = 0;

	fNombreDInstructions = 0;

	ListeDesInstructionOuEtiquette :: iterator
				i;
	
	for (
		i = fListeDesInstructionOuEtiquette -> begin ();
		i != fListeDesInstructionOuEtiquette -> end ();
		++ i )
		{
		(* i) ->
			DeterminerLAdresseAbsolue (
				lAdresseCourante, fNombreDInstructions );
		}	//	for
	}	//	SynthetiseurPilum :: DeterminerLesAdressesAbsolues ()


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: PropagerLesLiaisonsDesVariablesLogiquesNonAdresses ()
	{
	ListeDesInstructionOuEtiquette :: iterator
				i;
	
	for (
		i = fListeDesInstructionOuEtiquette -> begin ();
		i != fListeDesInstructionOuEtiquette -> end ();
		++ i )
		{
		(* i) -> 
			PropagerLesLiaisonsNonAdresses ();
		}	//	for
	}	//	SynthetiseurPilum :: PropagerLesLiaisonsDesVariablesLogiquesNonAdresses


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: PropagerLesLiaisonsDesVariablesLogiquesAdresses ()
	{
	ListeDesInstructionOuEtiquette :: iterator
				i;
	
	for (
		i = fListeDesInstructionOuEtiquette -> begin ();
		i != fListeDesInstructionOuEtiquette -> end ();
		++ i )
		{
		(* i) -> 
			PropagerLesLiaisonsAdresses ();
		}	//	for
	}	//	SynthetiseurPilum :: PropagerLesLiaisonsDesVariablesLogiquesAdresses


// -------------------------------------------------------------------------

void
SynthetiseurPilum :: OptimiserLeCode ()
	//	OPTIMISATION PEEPHOLE
	{
	ListeDesInstructionOuEtiquette :: iterator
				i;
	
	for (
		i = fListeDesInstructionOuEtiquette -> begin ();
		i != fListeDesInstructionOuEtiquette -> end ();
		++ i )
		{
		if ((* i) -> SemantiquementVide ())
			{
			//	les etiquettes ne sont pas concernees
			
			//	la semantique de erase () et remove () semble varier 
			//	un peu selon les versions de GCC...
			
			ListeDesInstructionOuEtiquette :: iterator
						iSuivant = ++i;

			i --;

			fListeDesInstructionOuEtiquette ->
				erase (i);
			fNombreDInstructions --;
			
			i = iSuivant;
			
			continue;
			}	// if
		}	//	for
	}	//	SynthetiseurPilum :: OptimiserLeCode
