// =========================================================================
//	Langues.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __Langues__
#define __Langues__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsLanguesEtDecodageDOptions.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "Types.h"

#include "DecodageDOptions.h"

#include <vector>


// -------------------------------------------------------------------------
//	DescriptionDeLangue
// -------------------------------------------------------------------------

class		Langue;
typedef	Langue					* LanguePTR;

class		DescriptionDeLangue;
typedef	DescriptionDeLangue	* DescriptionDeLanguePTR;


class DescriptionDeLangue
	{
public:
										DescriptionDeLangue (
											LanguePTR	laLangue,
											Chaine		 leMnemonique );

	LanguePTR						LaLangue ();
	Chaine							LeMnemonique ();


private:

	LanguePTR						fLangue;
	Chaine							fMnemonique;
	};


typedef std::vector <DescriptionDeLanguePTR>
										DescriptionsDesLangues;
typedef	DescriptionsDesLangues
										* DescriptionsDesLanguesPTR;


// -------------------------------------------------------------------------
//	Langue
// -------------------------------------------------------------------------

class Langue
	{
public:
										Langue (
											Chaine					leNom,
											Chaine					leMnemonique,
											OptionsPTR				lesOptions );

	virtual							~ Langue ();

	Chaine							Nom ();

	OptionsPTR						LesOptions ();


	//	Gestion des langues
	// -------------------------------------------------------------------------

	static void						EnregistrerLaLangue (
											LanguePTR	laLangue,
											Chaine		leMnemonique );

	static void						ListerLesLanguesConnues ();
	
	static LanguePTR				RechercherLaLangue (Chaine leMnemonique);
	
	static void						ChoisirLaLangueSource (
											Chaine	leMnemonique,
											bool		sortirSiInconnue );


	virtual Chaine					EnteteDUsage () = 0;
											// virtuelle pure

	virtual Chaine					FormatLangueInconnue () = 0;
											// virtuelle pure
	virtual Chaine					LesLanguesConnuesSont () = 0;
											// virtuelle pure

private:
	
	Chaine							fNom;

	OptionsPTR						fOptions;

	static DescriptionsDesLanguesPTR
										sLanguesConnues;

	};	//	Langue


// -------------------------------------------------------------------------
//	LangueFR
// -------------------------------------------------------------------------

class		LangueFR;
typedef	LangueFR					* LangueFRPTR;

class LangueFR : public Langue
	{
public:
										LangueFR ();

	virtual Chaine					EnteteDUsage ();

	Chaine							FormatLangueInconnue ();
	Chaine							LesLanguesConnuesSont ();

	};	//	LangueFR


// -------------------------------------------------------------------------
//	LangueEN
// -------------------------------------------------------------------------

class		LangueEN;
typedef	LangueEN					* LangueENPTR;

class LangueEN : public Langue
	{
public:
										LangueEN ();

	virtual Chaine					EnteteDUsage ();

	Chaine							FormatLangueInconnue ();
	Chaine							LesLanguesConnuesSont ();

	};	//	LangueEN


// -------------------------------------------------------------------------
//	Ecritures
// -------------------------------------------------------------------------

int									TailleChampEcritureNombres ();
int									NombreDecimalesEcritureNombres ();


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

extern LanguePTR					gLANGUE;
											// langue courante, selon makefile
											//	et options des executables

extern LangueFR					gLANGUE_FR;
extern LangueEN					gLANGUE_EN;


#endif /* __Langues__ */
