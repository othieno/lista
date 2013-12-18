// =========================================================================
//	Identificateur.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __Identificateur__
#define __Identificateur__


#include "Types.h"

#include "DescriptionDesTypes.h"

#include "LanguesSemantique.h"


// -------------------------------------------------------------------------
//	Identificateur
// -------------------------------------------------------------------------

enum GenreIdentificateur
	{
	kIdentNonDeclare,				//	rattrapage d'erreurs semantiques
	
	kIdentConstantePredefinie,		kIdentFonctionPredefinie,
	kIdentFonctionUtilisateur,		kIdentParametreFormel,

	kIdentIndiceIteration
	};


enum GenreIdentificateurFlexBison		// pour interaction entre analyses
										// lexicale et semantique
	{
	kIterateurFlexBison,						kSequenceurFlexBison,			

	kAutreIdentificateurFlexBison
	};


// -------------------------------------------------------------------------

class		Identificateur;
typedef	Identificateur			* IdentificateurPTR;
	
class Identificateur
	{
public:
										Identificateur (
											Chaine						leNom,
											Chaine						leNomQualifie,
											GenreIdentificateur		leGenreIdentificateur,
											GenreIdentificateurFlexBison	leGenreIdentificateurFlexBison,
											VariableLogiqueTypePTR	laVariableLogiqueType );

	virtual							~ Identificateur ();

	Chaine							Nom ();
	Chaine							NomQualifie ();

	GenreIdentificateur			LeGenreIdentificateur ();
	GenreIdentificateurFlexBison		LeGenreIdentificateurFlexBison ();

	TypePTR							TypeIdentificateur ();
	void								TypeIdentificateur (TypePTR leTypeIdentificateur);

	VariableLogiqueTypePTR		VariableLogiqueType ();

	void								EstUtilise ();

	bool								RecupererLeTypeInfere ();

	virtual void					PurgerIdent (
											int		lIdentation,
											bool		leModeVerbeux,
											bool		leMontrerLesDictionnaires );

	virtual Chaine					SousFormeDeChaine () = 0;
											// virtuelle pure

	virtual Chaine					Traduction ();


protected:

	Chaine							fNom;
	Chaine							fNomQualifie;

	GenreIdentificateur			fGenreIdentificateur;
	GenreIdentificateurFlexBison		fGenreIdentificateurFlexBison;

	TypePTR							fTypeIdentificateur;
	
	VariableLogiqueTypePTR		fVariableLogiqueType;	// pour l'inference de type

	int								fNbUtilisations;
	};	//	Identificateur


#endif /* __Identificateur__ */

