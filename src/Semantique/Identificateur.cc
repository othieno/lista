// =========================================================================
//	Identificateur.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "Identificateur.h"


// -------------------------------------------------------------------------
//	Identificateur
// -------------------------------------------------------------------------

Identificateur :: Identificateur (
	Chaine								leNom,
	Chaine								leNomQualifie,
	GenreIdentificateur				leGenreIdentificateur,
	GenreIdentificateurFlexBison	leGenreIdentificateurFlexBison,
	VariableLogiqueTypePTR			laVariableLogiqueType )
	{
	fNom = leNom;
	fNomQualifie = leNomQualifie;

	fGenreIdentificateur = leGenreIdentificateur;
	fGenreIdentificateurFlexBison = leGenreIdentificateurFlexBison;

	fTypeIdentificateur = laVariableLogiqueType -> ValeurDeLiaison ();
	fVariableLogiqueType = laVariableLogiqueType;
	}


Identificateur :: ~ Identificateur ()
	{}


// -------------------------------------------------------------------------

Chaine 
Identificateur :: Nom ()
	{ return fNom; }

Chaine 
Identificateur :: NomQualifie ()
	{ return fNomQualifie; }


GenreIdentificateur 
Identificateur :: LeGenreIdentificateur ()
	{ return fGenreIdentificateur; }

GenreIdentificateurFlexBison 
Identificateur :: LeGenreIdentificateurFlexBison ()
	{ return fGenreIdentificateurFlexBison; }

// -------------------------------------------------------------------------

TypePTR 
Identificateur :: TypeIdentificateur ()
	{ return fTypeIdentificateur; }

void 
Identificateur :: TypeIdentificateur (TypePTR leTypeIdentificateur)
	{ fTypeIdentificateur = leTypeIdentificateur; }

VariableLogiqueTypePTR 
Identificateur :: VariableLogiqueType ()
	{ return fVariableLogiqueType; }

// -------------------------------------------------------------------------

void 
Identificateur :: EstUtilise ()
	{ ++ fNbUtilisations; }

// -------------------------------------------------------------------------

bool 
Identificateur :: RecupererLeTypeInfere ()
	{
	bool	res = true;

	if (fVariableLogiqueType -> EstLibre ())
		{
		res = false;
		fVariableLogiqueType -> UnifierValeur (gTypeInconnu, false);
		}

	this ->
		TypeIdentificateur (fVariableLogiqueType -> ValeurDeLiaison ());
	
	return res;
	}

// -------------------------------------------------------------------------

void 
Identificateur :: PurgerIdent (
	int		lIdentation,
	bool		leModeVerbeux,
	bool		leMontrerLesDictionnaires )
	{
	if (leMontrerLesDictionnaires)
		{
		Indenter (lIdentation);
		std::cout << SousFormeDeChaine ();

		if (leModeVerbeux && fNbUtilisations == 0)
			std::cout <<
				gLANGUE_Semantique ->
					NonUtilise ();
		
		std::cout << std::endl;
		}
	}	//	Identificateur :: PurgerIdent

// -------------------------------------------------------------------------

Chaine 
Identificateur :: Traduction ()
	{ return fNom; }


