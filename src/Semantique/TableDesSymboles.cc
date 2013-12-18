// =========================================================================
//	TableDesSymboles.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "TableDesSymboles.h"

#include "LanguesSemantique.h"

#include "AlgebreBooleenne.h"
#include "Arithmetique.h"

#include "AnalyseurSemantiqueLista.h"


// -------------------------------------------------------------------------
//	IdentNonDeclare
// -------------------------------------------------------------------------

IdentNonDeclare :: IdentNonDeclare (
	Chaine						leNom,
	Chaine						leNomQualifie,
	VariableLogiqueTypePTR	laVariableLogiqueType )
	: Identificateur (
		leNom, leNomQualifie, kIdentNonDeclare, kAutreIdentificateurFlexBison,
		laVariableLogiqueType )
	{ this -> EstUtilise (); }

Chaine 
IdentNonDeclare :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			gLANGUE_Semantique -> 
				FormatIdentNonDeclareSousFormeDeChaine (),
			fNomQualifie,
			fTypeIdentificateur -> SousFormeDeChaine () );
	}

void 
IdentNonDeclare :: PurgerIdent (
	int		lIdentation,
	bool		leModeVerbeux,
	bool		leMontrerLesDictionnaires )
	{
	if (! RecupererLeTypeInfere ())
		;	//	RIEN

	this -> Identificateur :: PurgerIdent (
		lIdentation, leModeVerbeux, leMontrerLesDictionnaires );
	}


// -------------------------------------------------------------------------
//	IdentPredefini
// -------------------------------------------------------------------------

IdentPredefini :: IdentPredefini (
	ChaineLanguePredefinisPFM
											laFonctionNom,
	GenreIdentificateur				leGenreIdentificateur,
	GenreIdentificateurFlexBison	leGenreIdentificateurFlexBison,
	VariableLogiqueTypePTR			laVariableLogiqueType )
	: Identificateur (
		(gLANGUE_Predefinis ->* laFonctionNom) (),
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatNomQualifie (),
			gAnalyseurSemantiqueLista ->
				LaTableDesSymboles () -> Sommet () -> Nom (),
			Chaine (""),
			(gLANGUE_Predefinis ->* laFonctionNom) () ),
		leGenreIdentificateur,
		leGenreIdentificateurFlexBison,
		laVariableLogiqueType )
	{
	fFonctionNom = laFonctionNom;
	}

Chaine
IdentPredefini :: Traduction ()
	{ return (gLANGUE_Traduction ->* fFonctionNom) (); }


// -------------------------------------------------------------------------
//	ConstantePredefinie
// -------------------------------------------------------------------------

ConstantePredefinie :: ConstantePredefinie (
	ChaineLanguePredefinisPFM
									laFonctionNom,
	VariableLogiqueTypePTR	laVariableLogiqueType )
	: IdentPredefini (
		laFonctionNom,
		kIdentConstantePredefinie,
		kAutreIdentificateurFlexBison,
		laVariableLogiqueType )
	{}

Chaine
ConstantePredefinie :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatConstantePredefinie (),
			fNom,
			gLANGUE_Semantique ->
				ConstantePredefinie (),
			fTypeIdentificateur -> SousFormeDeChaine () );
	}


// -------------------------------------------------------------------------
//	Les constantes predefinies
// -------------------------------------------------------------------------

VraiPredef :: VraiPredef (
	ChaineLanguePredefinisPFM laFonctionNom )
	: ConstantePredefinie (laFonctionNom, gTypeLogiqueBooleen)
	{}

DescrSemantiquePTR
VraiPredef :: CreerGrapheConstante ()
	{ return gValeurVrai; }

// -------------------------------------------------------------------------

FauxPredef :: FauxPredef (
	ChaineLanguePredefinisPFM laFonctionNom )
	: ConstantePredefinie (laFonctionNom, gTypeLogiqueBooleen)
	{}

DescrSemantiquePTR
FauxPredef :: CreerGrapheConstante ()
	{ return gValeurFaux; }

// -------------------------------------------------------------------------

PiPredef :: PiPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: ConstantePredefinie (laFonctionNom, gTypeLogiqueNombre)
	{}

DescrSemantiquePTR
PiPredef :: CreerGrapheConstante ()
	{ return gValeurPi; }

// -------------------------------------------------------------------------

EPredef :: EPredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: ConstantePredefinie (laFonctionNom, gTypeLogiqueNombre)
	{}

DescrSemantiquePTR
EPredef :: CreerGrapheConstante ()
	{ return gValeurE; }

// -------------------------------------------------------------------------

VidePredef :: VidePredef (
	ChaineLanguePredefinisPFM laFonctionNom  )
	: ConstantePredefinie (laFonctionNom, gTypeLogiqueVide)
	{}

DescrSemantiquePTR
VidePredef :: CreerGrapheConstante ()
	{ return gValeurVide; }


// -------------------------------------------------------------------------
//	FonctionPredefinie
// -------------------------------------------------------------------------

FonctionPredefinie :: FonctionPredefinie (
	ChaineLanguePredefinisPFM
												laFonctionNom,
	GenreFonctionPredefinie				leGenreFonctionPredefinie,
	GenreIdentificateurFlexBison		leGenreIdentificateurFlexBison,
	VariableLogiqueTypePTR				laVariableLogiqueType )
	: IdentPredefini (
		laFonctionNom,
		kIdentFonctionPredefinie,
		leGenreIdentificateurFlexBison,
		laVariableLogiqueType )
	{
	fGenreFonctionPredefinie = leGenreFonctionPredefinie;
	}	//	FonctionPredefinie :: FonctionPredefinie

GenreFonctionPredefinie
FonctionPredefinie :: LeGenreFonctionPredefinie ()
	{ return fGenreFonctionPredefinie; }

int
FonctionPredefinie :: NombreDeParametres ()
	{ return fNombreDeParametres; }

VariableLogiqueTypePTR *
FonctionPredefinie :: TypesLogiquesDesParametres ()
	{ return fTypesLogiquesDesParametres; }


// -------------------------------------------------------------------------

Chaine
FonctionPredefinie :: DescriptionDesParametres ()
	{
	Chaine	res = "";
	Chaine	separateur;
	
	for (int i = 0; i < fNombreDeParametres; i ++)
		{		
		if (i > 0)
			separateur = ", ";
		else
			separateur = "";
		
		res +=
			separateur
				+
			fTypesLogiquesDesParametres [i] -> 
				ValeurDeLiaison () -> SousFormeDeChaine ();
		}	// for
		
	return res;
	}	// FonctionPredefinie :: DescriptionDesParametres


Chaine 
FonctionPredefinie :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatFonctionPredefinie (),
			fNom,
			gLANGUE_Semantique ->
				FonctionPredefinie (),
			DescriptionDesParametres (),
			fTypeIdentificateur -> SousFormeDeChaine () );
	}	// FonctionPredefinie :: SousFormeDeChaine


// -------------------------------------------------------------------------
//	NoeudDArbre
// -------------------------------------------------------------------------

NoeudDArbre :: NoeudDArbre (IdentificateurPTR lIdentificateur)
	{
	fIdentificateur = lIdentificateur;
	fPlusPetits = NULL;
	fPlusGrandsEgaux = NULL;
	}

NoeudDArbre :: ~ NoeudDArbre ()
	{
	if (fPlusPetits != NULL)
		delete fPlusPetits;

	delete fIdentificateur;

	if (fPlusGrandsEgaux != NULL)
		delete fPlusGrandsEgaux;
	}

IdentificateurPTR 
NoeudDArbre :: Identificateur ()
	{ return fIdentificateur; }

NoeudDArbrePTR & 
NoeudDArbre :: PlusPetits ()
	{ return fPlusPetits; }

NoeudDArbrePTR & 
NoeudDArbre :: PlusGrandsEgaux ()
	{ return fPlusGrandsEgaux; }


// -------------------------------------------------------------------------
//	Dictionnaire
// -------------------------------------------------------------------------

Dictionnaire :: Dictionnaire (Chaine leNom)
	{
	fNom = leNom;
	fRacine = NULL;
	fTaille = 0;
	fProfondeur = 0;
	}

Dictionnaire :: ~ Dictionnaire ()
	{
	delete fRacine;
	}


Chaine 
Dictionnaire :: Nom ()
	{ return fNom; }

bool 
Dictionnaire :: InsererLIdentificateur (IdentificateurPTR lIdentificateur)
	//	retourne 'faux' si "lIdentificateur -> fNom" déjà présent
	{
	bool	res = InsererDansLArbre (fRacine, lIdentificateur, 0);

	++ fTaille;
	
	return res;
	}

bool 
Dictionnaire :: InsererDansLArbre (
	NoeudDArbrePTR			& laRacine,
	IdentificateurPTR		lIdentificateur,
	int						laProfondeur )
	{
	if (laRacine == NULL)
		{
		laRacine = new NoeudDArbre (lIdentificateur);
		if (laProfondeur > fProfondeur)
			fProfondeur = laProfondeur;
		return true;
		}
	else
		{
		long		comparaison =
						lIdentificateur -> Nom ().compare (
							laRacine -> Identificateur () -> Nom () );
			
		if (comparaison == 0)
			return false;	//	"lIdentificateur -> Nom ()" est déjà présent

		if (comparaison < 0)
			return
				InsererDansLArbre (
					laRacine -> PlusPetits (), lIdentificateur, laProfondeur + 1 );
		else
			return
				InsererDansLArbre (
					laRacine -> PlusGrandsEgaux (), lIdentificateur, laProfondeur + 1 );
		}
	}	//	Dictionnaire :: InsererDansLArbre


IdentificateurPTR 
Dictionnaire :: ContientIdentificateur (Chaine leNom)
	{
	NoeudDArbrePTR
				curseur = fRacine;
	
	while (curseur != NULL)
		{
		long		comparaison =
						leNom.compare (
							curseur -> Identificateur () -> Nom () );

		if (comparaison == 0)
			//	on a trouvé "leNom"
			return curseur -> Identificateur ();

		curseur =
			(comparaison < 0)
				?	curseur -> PlusPetits ()
				:	curseur -> PlusGrandsEgaux ();		
		}	//	while

	return NULL;	//	on n’a pas trouvé "leNom"
	}	//	Dictionnaire :: ContientIdentificateur


void 
Dictionnaire :: EcrireDictionnaire ()
	{
	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatContenuDuDictionnaire (),
			fNom ) << 
		std::endl;
	EcrireLArbre (fRacine);
	}

void 
Dictionnaire :: EcrireLArbre (
	NoeudDArbrePTR laRacine )
	{
	if (laRacine != NULL)
		{
		EcrireLArbre (laRacine -> PlusPetits ());

		std::cout <<
			"\t" <<
			laRacine -> Identificateur () -> SousFormeDeChaine () << 
			std::endl;
		
		EcrireLArbre (laRacine -> PlusGrandsEgaux ());
		}
	}


void 
Dictionnaire :: PurgerDictionnaire (
	int		lIdentation,
	bool		leModeVerbeux,
	bool		leMontrerLesDictionnaires )
	{
	if (leMontrerLesDictionnaires)
		{
		std::cout <<
			std::endl;
		
		Indenter (lIdentation);

		if (fRacine == NULL)
			std::cout <<
				MiseEnForme (
					gLANGUE_Semantique -> 
						FormatPurgeDuDictionnaireVide (),
					fNom );
		else
			std::cout <<
				MiseEnForme (
					gLANGUE_Semantique -> 
						FormatPurgeDuDictionnaire (),
						fNom );
		}	// if
	
	if (fRacine != NULL)
		PurgerLArbre (
			fRacine,
			lIdentation + 1,
			leModeVerbeux,
			leMontrerLesDictionnaires );

	std::cout << std::flush;
	} // Dictionnaire :: PurgerDictionnaire

void 
Dictionnaire :: PurgerLArbre (
	NoeudDArbrePTR		laRacine,
	int					lIdentation,
	bool					leModeVerbeux,
	bool					leMontrerLesDictionnaires )
	{
	if (laRacine != NULL)
		{
		PurgerLArbre (
			laRacine -> PlusPetits (), lIdentation,
			leModeVerbeux, leMontrerLesDictionnaires);

		laRacine -> Identificateur () -> 
			PurgerIdent (
				lIdentation, leModeVerbeux, leMontrerLesDictionnaires );
		
		PurgerLArbre (
			laRacine -> PlusGrandsEgaux (), lIdentation,
			leModeVerbeux, leMontrerLesDictionnaires);
		}
	}


// -------------------------------------------------------------------------
//	NiveauDeDeclaration
// -------------------------------------------------------------------------

NiveauDeDeclaration :: NiveauDeDeclaration (Chaine leNom)
	{
	fNom = leNom;
	fDictionnaireLocal = new Dictionnaire (leNom);
	}

NiveauDeDeclaration :: NiveauDeDeclaration (DictionnairePTR leDictionnaire)
	{
	fDictionnaireLocal = leDictionnaire;
	fNom = fDictionnaireLocal -> Nom ();
	}

NiveauDeDeclaration :: ~ NiveauDeDeclaration ()
	{
	delete fDictionnaireLocal;
	}

Chaine 
NiveauDeDeclaration :: Nom ()
	{ return fNom; }

DictionnairePTR 
NiveauDeDeclaration :: DictionnaireLocal ()
	{ return fDictionnaireLocal; }


// -------------------------------------------------------------------------
//	TableDesSymboles
// -------------------------------------------------------------------------

TableDesSymboles :: TableDesSymboles (
	bool 	leModeVerbeux,
	bool	leMontrerLesDictionnaires)
	{
	fModeVerbeux = leModeVerbeux;
	fMontrerLesDictionnaires = leMontrerLesDictionnaires;
	}

TableDesSymboles :: ~ TableDesSymboles ()
	{
	PileDesNiveauxDeDeclaration :: iterator	i;
	
	for (
		i = fPileDesNiveauxDeDeclaration.begin ();
		i != fPileDesNiveauxDeDeclaration.end ();
		++ i )
		{
		delete (* i);
		}	// for
	}


void 
TableDesSymboles :: Empiler (
	NiveauDeDeclarationPTR leNiveauDeDeclaration )
	{
	if (fModeVerbeux)
		{
		std::cout <<
			std::endl <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatEmpilageNiveauDeDeclaration (),
				leNiveauDeDeclaration -> Nom () ) <<
			std::endl;
		}

	fPileDesNiveauxDeDeclaration.push_front (leNiveauDeDeclaration);
	}

NiveauDeDeclarationPTR 
TableDesSymboles :: Sommet ()
	{ return fPileDesNiveauxDeDeclaration.front (); }

NiveauDeDeclarationPTR 
TableDesSymboles :: Desempiler ()
	{
	NiveauDeDeclarationPTR	res = fPileDesNiveauxDeDeclaration.front ();
	
	if (fModeVerbeux)
		{
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatDesempilageNiveauDeDeclaration (),
				res -> Nom () ) <<
			std::endl <<
			std::endl;
		}

	res -> DictionnaireLocal () ->
		PurgerDictionnaire (0, fModeVerbeux, fMontrerLesDictionnaires);

	fPileDesNiveauxDeDeclaration.pop_front ();

	return res;
	}	//	TableDesSymboles :: Desempiler


void 
TableDesSymboles :: InsererLIdentificateur (
	IdentificateurPTR		lIdentificateur,
	bool						& dejaPresentAuSommet,
	IdentificateurPTR		& autreDeclarationMasquee )
	{
	if (fPileDesNiveauxDeDeclaration.size () == 0)
		SortieSurErreur (
			gLANGUE_Semantique ->
				TableDesSymbolesVide (),
			1 );

	DictionnairePTR
				leDictionnaire = NULL;

	autreDeclarationMasquee =
		RechercherLeNom (
			lIdentificateur -> Nom (), leDictionnaire, true );
		
	dejaPresentAuSommet =
		! fPileDesNiveauxDeDeclaration.front () ->
			DictionnaireLocal () ->
				InsererLIdentificateur (lIdentificateur );
	}	//	TableDesSymboles :: InsererLIdentificateur


IdentificateurPTR 
TableDesSymboles :: RechercherLeNom (
	Chaine					leNom,
	DictionnairePTR		& leDictionnaire,
	bool						ignorerSommet )
	//	retourne 'NULL' si "leNom" pas trouvé
	{
	if (fPileDesNiveauxDeDeclaration.size () == 0)
		return NULL;

	PileDesNiveauxDeDeclaration :: iterator
				niveauDeDepart =
					fPileDesNiveauxDeDeclaration.begin ();
	
	if (ignorerSommet)
		{
		try
			{
			niveauDeDepart ++;
			}
		catch (...)
			{
			return NULL;
			}
		}

	PileDesNiveauxDeDeclaration :: iterator
				i;

	for (
		i = niveauDeDepart;
		i != fPileDesNiveauxDeDeclaration.end ();
		++ i )
		{
		leDictionnaire = (* i) -> DictionnaireLocal ();

		IdentificateurPTR
					lIdentificateur =
						leDictionnaire -> ContientIdentificateur (leNom);

		if (lIdentificateur != NULL)
			{
			lIdentificateur -> EstUtilise ();
			return lIdentificateur;
			}
		}	//	for

	return NULL;
	}	//	TableDesSymboles :: RechercherLeNom


void 
TableDesSymboles :: Ecrire (Chaine leContexte)
	{
	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatTableDesSymboles (),
			leContexte ) <<
		std::endl;
	
	PileDesNiveauxDeDeclaration :: iterator	i;
	
	for (
		i = fPileDesNiveauxDeDeclaration.begin ();
		i != fPileDesNiveauxDeDeclaration.end ();
		++ i )
		{
		(* i) -> DictionnaireLocal () -> EcrireDictionnaire ();		
		}	//	for

	std::cout <<
		"===>  <===" <<
		std::endl;
	}	//	TableDesSymboles :: Ecrire


void 
TableDesSymboles :: ModeVerbeux (bool leModeVerbeux)
	{ fModeVerbeux = leModeVerbeux; }

void 
TableDesSymboles :: MontrerLesDictionnaires (bool leMontrerLesDictionnaires)
	{ fMontrerLesDictionnaires = leMontrerLesDictionnaires; }
