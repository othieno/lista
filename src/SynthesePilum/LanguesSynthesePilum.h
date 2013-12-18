// =========================================================================
//	LanguesSynthesePilum.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __LanguesSynthesePilum__
#define __LanguesSynthesePilum__


#include "Types.h"


// -------------------------------------------------------------------------
//	LangueSynthesePilum
// -------------------------------------------------------------------------

class		LangueSynthesePilum;
typedef	LangueSynthesePilum	* LangueSynthesePilumPTR;

class LangueSynthesePilum
	{
public:
										LangueSynthesePilum ();

	virtual							~ LangueSynthesePilum ();


	//	Synthese de code Pilum
	// -------------------------------------------------------------------------

	virtual Chaine					FormatDescriptionEtiquette () = 0;
											// virtuelle pure
	virtual Chaine					PlacerEtiquetteEchecDUnification () = 0;
											// virtuelle pure
	virtual Chaine					InstructionDAppelInstructionLibre () = 0;
											// virtuelle pure

	virtual Chaine					TailleDesChaines () = 0;
											// virtuelle pure
	virtual Chaine					NombreDInstructions () = 0;
											// virtuelle pure

	virtual Chaine					VariableLogiqueEntiereEstLibre () = 0;
											// virtuelle pure
	virtual Chaine					DestinationDeSautEstLibre () = 0;
											// virtuelle pure
	virtual Chaine					DestinationDeThunkEstLibre () = 0;
											// virtuelle pure

	virtual Chaine					FormatCodeSansLiaisonsNonAdresses () = 0;
											// virtuelle pure
	virtual Chaine					FormatCodeSansOptimisation () = 0;
											// virtuelle pure
	virtual Chaine					FormatCodeSansAdressesAbsolues () = 0;
											// virtuelle pure
	virtual Chaine					FormatCodeSansLiaisonsAdresses () = 0;
											// virtuelle pure
	virtual Chaine					FormatCodeApresFinalisation () = 0;
											// virtuelle pure

	virtual Chaine					FormatCodeSynthetise () = 0;
											// virtuelle pure
	virtual Chaine					FormatCodeSynthetiseSurFichier () = 0;
											// virtuelle pure
	virtual Chaine					FormatPasPuOuvrirLeFichierTexteEnEcriture () = 0;
											// virtuelle pure

	virtual Chaine					FormatPasPuOuvrirLeFichierBinaireEnEcriture () = 0;
											// virtuelle pure
	virtual Chaine					FormatFichierDeCodePilumAEteCree () = 0;
											// virtuelle pure

	virtual Chaine					SuffixeFichiersBinairesParValeur () = 0;
											// virtuelle pure
	virtual Chaine					SuffixeFichiersBinairesParNom () = 0;
											// virtuelle pure
	virtual Chaine					SuffixeFichiersBinairesParBesoin () = 0;
											// virtuelle pure

	virtual Chaine					SuffixeFichiersBinairesPredictifDescenteRecursive () = 0;
											// virtuelle pure
	virtual Chaine					SuffixeFichiersBinairesFlexBison () = 0;
											// virtuelle pure

	virtual Chaine					NomDuFichierBinaireParDefaut () = 0;
											// virtuelle pure
	virtual Chaine					NomDuSynthetiseurPilumListaParDefaut () = 0;
											// virtuelle pure
	virtual Chaine					NomDeLaMachinePilumParDefaut () = 0;
											// virtuelle pure

	};	//	LangueSynthesePilum


// -------------------------------------------------------------------------
//	LangueSynthesePilumFR
// -------------------------------------------------------------------------

class		LangueSynthesePilumFR;
typedef	LangueSynthesePilumFR
										* LangueSynthesePilumFRPTR;

class LangueSynthesePilumFR : public LangueSynthesePilum
	{
public:
										LangueSynthesePilumFR ();


	//	Synthese de code Pilum
	// -------------------------------------------------------------------------

	Chaine							FormatDescriptionEtiquette ();
	Chaine							PlacerEtiquetteEchecDUnification ();
	Chaine							InstructionDAppelInstructionLibre ();

	Chaine							TailleDesChaines ();
	Chaine							NombreDInstructions ();

	Chaine							VariableLogiqueEntiereEstLibre ();
	Chaine							DestinationDeSautEstLibre ();
	Chaine							DestinationDeThunkEstLibre ();

	Chaine							FormatCodeSansLiaisonsNonAdresses ();
	Chaine							FormatCodeSansOptimisation ();
	Chaine							FormatCodeSansAdressesAbsolues ();
	Chaine							FormatCodeSansLiaisonsAdresses ();
	Chaine							FormatCodeApresFinalisation ();

	Chaine							FormatCodeSynthetise ();
	Chaine							FormatCodeSynthetiseSurFichier ();
	Chaine							FormatPasPuOuvrirLeFichierTexteEnEcriture ();

	Chaine							FormatPasPuOuvrirLeFichierBinaireEnEcriture ();
	Chaine							FormatFichierDeCodePilumAEteCree ();

	Chaine							SuffixeFichiersBinairesParValeur ();
	Chaine							SuffixeFichiersBinairesParNom ();
	Chaine							SuffixeFichiersBinairesParBesoin ();

	Chaine							SuffixeFichiersBinairesPredictifDescenteRecursive ();
	Chaine							SuffixeFichiersBinairesFlexBison ();

	Chaine							NomDuFichierBinaireParDefaut ();
	Chaine							NomDuSynthetiseurPilumListaParDefaut ();
	Chaine							NomDeLaMachinePilumParDefaut ();

	};	//	LangueSynthesePilumFR


// -------------------------------------------------------------------------
//	LangueSynthesePilumEN
// -------------------------------------------------------------------------

class		LangueSynthesePilumEN;
typedef	LangueSynthesePilumEN
										* LangueSynthesePilumENPTR;

class LangueSynthesePilumEN : public LangueSynthesePilum
	{
public:
										LangueSynthesePilumEN ();


	//	Synthese de code Pilum
	// -------------------------------------------------------------------------

	Chaine							FormatDescriptionEtiquette ();
	Chaine							PlacerEtiquetteEchecDUnification ();
	Chaine							InstructionDAppelInstructionLibre ();

	Chaine							TailleDesChaines ();
	Chaine							NombreDInstructions ();

	Chaine							VariableLogiqueEntiereEstLibre ();
	Chaine							DestinationDeSautEstLibre ();
	Chaine							DestinationDeThunkEstLibre ();

	Chaine							FormatCodeSansLiaisonsNonAdresses ();
	Chaine							FormatCodeSansOptimisation ();
	Chaine							FormatCodeSansAdressesAbsolues ();
	Chaine							FormatCodeSansLiaisonsAdresses ();
	Chaine							FormatCodeApresFinalisation ();

	Chaine							FormatCodeSynthetise ();
	Chaine							FormatCodeSynthetiseSurFichier ();
	Chaine							FormatPasPuOuvrirLeFichierTexteEnEcriture ();

	Chaine							FormatPasPuOuvrirLeFichierBinaireEnEcriture ();
	Chaine							FormatFichierDeCodePilumAEteCree ();

	Chaine							SuffixeFichiersBinairesParValeur ();
	Chaine							SuffixeFichiersBinairesParNom ();
	Chaine							SuffixeFichiersBinairesParBesoin ();

	Chaine							SuffixeFichiersBinairesPredictifDescenteRecursive ();
	Chaine							SuffixeFichiersBinairesFlexBison ();

	Chaine							NomDuFichierBinaireParDefaut ();
	Chaine							NomDuSynthetiseurPilumListaParDefaut ();
	Chaine							NomDeLaMachinePilumParDefaut ();

	};	//	LangueSynthesePilumEN


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

extern LangueSynthesePilumPTR	gLANGUE_SynthesePilum;


// -------------------------------------------------------------------------
//	InitialiserLanguesSynthesePilum
// -------------------------------------------------------------------------

void									InitialiserLanguesSynthesePilum (
											Chaine leMnemonique = LANGUE_PAR_DEFAUT );


#endif /* __LanguesSynthesePilum__ */

