// =========================================================================
//	LanguesSynthesePilum.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "LanguesSynthesePilum.h"


// -------------------------------------------------------------------------
//	LangueSynthesePilum
// -------------------------------------------------------------------------

LangueSynthesePilum :: LangueSynthesePilum ()
	{}

LangueSynthesePilum :: ~ LangueSynthesePilum ()
	{}


// -------------------------------------------------------------------------
//	LangueSynthesePilumFR
// -------------------------------------------------------------------------

LangueSynthesePilumFR :: LangueSynthesePilumFR ()
	{}


// -------------------------------------------------------------------------

Chaine
LangueSynthesePilumFR :: FormatDescriptionEtiquette ()
	{ return "Etiquette_%d"; }

Chaine							
LangueSynthesePilumFR :: PlacerEtiquetteEchecDUnification ()
	{ return "PlacerEtiquette: echec d'unification"; }

Chaine							
LangueSynthesePilumFR :: InstructionDAppelInstructionLibre ()
	{ return "kInstructionDAppel: laDestination est libre"; }

Chaine							
LangueSynthesePilumFR :: TailleDesChaines ()
	{ return "Taille des chaines = "; }
Chaine							
LangueSynthesePilumFR :: NombreDInstructions ()
	{ return "Nombre d'instructions = "; }

Chaine							
LangueSynthesePilumFR :: VariableLogiqueEntiereEstLibre ()
	{ return "Erreur interne: la variable logique entière est libre dans une instruction"; }
Chaine							
LangueSynthesePilumFR :: DestinationDeSautEstLibre ()
	{ return "kInstructionDeSaut : laDestination est libre"; }
Chaine							
LangueSynthesePilumFR :: DestinationDeThunkEstLibre ()
	{ return "kInstructionDeThunk : laDestination est libre"; }

Chaine							
LangueSynthesePilumFR :: FormatCodeSansLiaisonsNonAdresses ()
	{ return "Code Pilum synthetisé FormatCodeSansLiaisonsNonAdresses (%d instructions):"; }
Chaine							
LangueSynthesePilumFR :: FormatCodeSansOptimisation ()
	{ return "Code Pilum synthetisé FormatCodeSansOptimisation (%d instructions):"; }
Chaine							
LangueSynthesePilumFR :: FormatCodeSansAdressesAbsolues ()
	{ return "Code Pilum synthetisé FormatCodeSansAdressesAbsolues (%d instructions):"; }
Chaine							
LangueSynthesePilumFR :: FormatCodeSansLiaisonsAdresses ()
	{ return "Code Pilum synthetisé FormatCodeSansLiaisonsAdresses (%d instructions):"; }
Chaine							
LangueSynthesePilumFR :: FormatCodeApresFinalisation ()
	{ return "Code Pilum synthetisé FormatCodeApresFinalisation (%d instructions):"; }

Chaine							
LangueSynthesePilumFR :: FormatCodeSynthetise ()
	{ return "Code Pilum synthetisé (%d instructions):"; }
Chaine							
LangueSynthesePilumFR :: FormatCodeSynthetiseSurFichier ()
	{ return "Code Pilum synthetisé sur %s:"; }
Chaine							
LangueSynthesePilumFR :: FormatPasPuOuvrirLeFichierTexteEnEcriture ()
	{ return "Pas pu ouvrir le fichier texte \"%s\" en écriture"; }

Chaine							
LangueSynthesePilumFR :: FormatPasPuOuvrirLeFichierBinaireEnEcriture ()
	{ return "Pas pu ouvrir le fichier binaire \"%s\" en écriture"; }

Chaine							
LangueSynthesePilumFR :: FormatFichierDeCodePilumAEteCree ()
	{ return "\n*** Le fichier de code objet Pilum \"%s\" a ete créé ***"; }


// -------------------------------------------------------------------------

Chaine							
LangueSynthesePilumFR :: SuffixeFichiersBinairesParValeur ()
	{ return ".valeur_"; }
Chaine							
LangueSynthesePilumFR :: SuffixeFichiersBinairesParNom ()
	{ return ".nom_"; }
Chaine							
LangueSynthesePilumFR :: SuffixeFichiersBinairesParBesoin ()
	{ return ".besoin_"; }

Chaine							
LangueSynthesePilumFR :: SuffixeFichiersBinairesPredictifDescenteRecursive ()
	{ return "PDR"; }
Chaine							
LangueSynthesePilumFR :: SuffixeFichiersBinairesFlexBison ()
	{ return "FB"; }

Chaine							
LangueSynthesePilumFR :: NomDuFichierBinaireParDefaut ()
	{ return "Lista.pilum"; }
Chaine							
LangueSynthesePilumFR :: NomDuSynthetiseurPilumListaParDefaut ()
	{ return "Synthétiseur de code Pilum pour Lista"; }
Chaine							
LangueSynthesePilumFR :: NomDeLaMachinePilumParDefaut ()
	{ return "Pilum pour exécution Lista"; }


// -------------------------------------------------------------------------
//	LangueSynthesePilumEN
// -------------------------------------------------------------------------

LangueSynthesePilumEN :: LangueSynthesePilumEN ()
	{}


// -------------------------------------------------------------------------

Chaine							
LangueSynthesePilumEN :: FormatDescriptionEtiquette ()
	{ return "Label_%d"; }

Chaine							
LangueSynthesePilumEN :: PlacerEtiquetteEchecDUnification ()
	{ return "PlacerEtiquette: echec d'unification"; }

Chaine							
LangueSynthesePilumEN :: InstructionDAppelInstructionLibre ()
	{ return "kInstructionDAppel: laDestination est libre"; }

Chaine							
LangueSynthesePilumEN :: TailleDesChaines ()
	{ return "Strings size = "; }
Chaine							
LangueSynthesePilumEN :: NombreDInstructions ()
	{ return "Number of instructions = "; }

Chaine							
LangueSynthesePilumEN :: VariableLogiqueEntiereEstLibre ()
	{ return "Internal error: the logical variable is free in an instruction"; }
Chaine							
LangueSynthesePilumEN :: DestinationDeSautEstLibre ()
	{ return "kInstructionDeSaut : laDestination est libre"; }
Chaine							
LangueSynthesePilumEN :: DestinationDeThunkEstLibre ()
	{ return "kInstructionDeThunk : laDestination est libre"; }

Chaine							
LangueSynthesePilumEN :: FormatCodeSansLiaisonsNonAdresses ()
	{ return "Pilum code synthetised FormatCodeSansLiaisonsNonAdresses (%d instructions):"; }
Chaine							
LangueSynthesePilumEN :: FormatCodeSansOptimisation ()
	{ return "Pilum code synthetised FormatCodeSansOptimisation (%d instructions):"; }
Chaine							
LangueSynthesePilumEN :: FormatCodeSansAdressesAbsolues ()
	{ return "Pilum code synthetised FormatCodeSansAdressesAbsolues (%d instructions):"; }
Chaine							
LangueSynthesePilumEN :: FormatCodeSansLiaisonsAdresses ()
	{ return "Pilum code synthetised FormatCodeSansLiaisonsAdresses (%d instructions):"; }
Chaine							
LangueSynthesePilumEN :: FormatCodeApresFinalisation ()
	{ return "Pilum code synthetised FormatCodeApresFinalisation (%d instructions):"; }

Chaine							
LangueSynthesePilumEN :: FormatCodeSynthetise ()
	{ return "Pilum code synthetised (%d instructions):"; }
Chaine							
LangueSynthesePilumEN :: FormatCodeSynthetiseSurFichier ()
	{ return "Pilum code synthetised on %s:"; }
Chaine							
LangueSynthesePilumEN :: FormatPasPuOuvrirLeFichierTexteEnEcriture ()
	{ return "Couldn't open text file \"%s\" for writing"; }
 
Chaine							
LangueSynthesePilumEN :: FormatPasPuOuvrirLeFichierBinaireEnEcriture ()
	{ return "Could not open binary file \"%s\" for writing"; }

Chaine							
LangueSynthesePilumEN :: FormatFichierDeCodePilumAEteCree ()
	{ return "\n*** Pilum object code \"%s\" has been created ***"; }


// -------------------------------------------------------------------------

Chaine							
LangueSynthesePilumEN :: SuffixeFichiersBinairesParValeur ()
	{ return ".value_"; }
Chaine							
LangueSynthesePilumEN :: SuffixeFichiersBinairesParNom ()
	{ return ".name_"; }
Chaine							
LangueSynthesePilumEN :: SuffixeFichiersBinairesParBesoin ()
	{ return ".need_"; }

Chaine							
LangueSynthesePilumEN :: SuffixeFichiersBinairesPredictifDescenteRecursive ()
	{ return "PRD"; }
Chaine							
LangueSynthesePilumEN :: SuffixeFichiersBinairesFlexBison ()
	{ return "FB"; }

Chaine							
LangueSynthesePilumEN :: NomDuFichierBinaireParDefaut ()
	{ return "Lista.pilum"; }
Chaine							
LangueSynthesePilumEN :: NomDuSynthetiseurPilumListaParDefaut ()
	{ return "Pilum code synthesizer for Lista"; }
Chaine							
LangueSynthesePilumEN :: NomDeLaMachinePilumParDefaut ()
	{ return "Pilum for Lista execution"; }


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

LangueSynthesePilumPTR		gLANGUE_SynthesePilum = NULL;


// -------------------------------------------------------------------------
//	InitialiserLanguesSynthesePilum
// -------------------------------------------------------------------------

void
InitialiserLanguesSynthesePilum (Chaine leMnemonique)
	{
	if (gLANGUE_SynthesePilum != NULL)
		delete gLANGUE_SynthesePilum;

	if (leMnemonique == "fr")
		gLANGUE_SynthesePilum = new LangueSynthesePilumFR;
	if (leMnemonique == "en")
		gLANGUE_SynthesePilum = new LangueSynthesePilumEN;
	}
