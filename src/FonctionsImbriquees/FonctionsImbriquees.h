// =========================================================================
//	FonctionsImbriquees.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "SynthesePilum.h"
   
#include <ostream>


// ------------------------------------------------------------------------
//	SynthFonctionsImpriquees
// ------------------------------------------------------------------------

class		SynthFonctionsImpriquees;
typedef	SynthFonctionsImpriquees	* SynthFonctionsImpriqueesPTR;

class SynthFonctionsImpriquees : public SynthetiseurPilum
	{
public:
										SynthFonctionsImpriquees (
											Chaine					leNom,
											std::ostream			* leFlotTexte,
											std::ofstream			* leFichierBinaire,
											OptionsSynthesePTR	lesOptionsSynthese );

										~ SynthFonctionsImpriquees ();

	void								SynthetiserLeCode ();
												
	void								SynthetiserLaProcedure (
											VariableLogiqueEtiquettePTR etiquetteDuCorps );
												
	void								SynthetiserImbriquee (
											VariableLogiqueEtiquettePTR etiquetteDuCorps );
												
	void								SynthetiserProgramme ();
												

protected:

	OptionsSynthesePTR			fOptionsSynthese;

	std::ostream					* fFlotTexte;
	std::ofstream					* fFichierBinaire;

	VariableLogiqueEtiquettePTR
										fEtiquetteDeImbriquee;
	VariableLogiqueEtiquettePTR
										fEtiquetteDeLaProcedure;

	};	//	SynthFonctionsImpriquees
