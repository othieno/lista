// =========================================================================
//	ParametresFormels.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "ParametresFormels.h"

#include "ContexteDEvaluation.h"

#include "AnalyseurSemantiqueLista.h"


#if defined SYNTHESE_PILUM
	#include "SynthesePilum.h"
	#include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	ParametreFormel
// -------------------------------------------------------------------------

ParametreFormel :: ParametreFormel (
	Chaine						leNom,
	Chaine						leNomQualifie,
	VariableLogiqueTypePTR	laVariableLogiqueType,
	DescrParametrePTR			laDescrParametre,
	int							leNiveauDEvaluation )
	: Identificateur (
		leNom, leNomQualifie, kIdentParametreFormel, kAutreIdentificateurFlexBison,
		laVariableLogiqueType )
	{
	fDescrParametre = laDescrParametre;
	fNiveauDEvaluation = leNiveauDEvaluation;
	}


Chaine 
ParametreFormel :: SousFormeDeChaine ()
	{
	return
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatParametreFormel (),
			fDescrParametre -> 
				StrategieDEvaluation () -> SousFormeDeChaine (),
			fNomQualifie,
			fTypeIdentificateur -> SousFormeDeChaine (),
			fDescrParametre -> NiveauDEvaluation (),
			fDescrParametre -> NiveauStatique () );
	}

DescrParametrePTR 
ParametreFormel :: DescrParametre ()
	{ return fDescrParametre; }

int 
ParametreFormel :: NiveauDEvaluation ()
	{ return fNiveauDEvaluation; }


// -------------------------------------------------------------------------
//	AssocArgumentParametre
// -------------------------------------------------------------------------

AssocArgumentParametre :: AssocArgumentParametre (
	Chaine						leNom,
	Chaine						leNomQualifie,
	int							leNumeroDeParametre,
	ContexteDEvaluationPTR	leContexteDEvaluation )
	{
	fNom = leNom;
	fNomQualifie = leNomQualifie;
	fNumeroDeParametre = leNumeroDeParametre;
	fContexteDEvaluation = leContexteDEvaluation;
	}

AssocArgumentParametre :: ~ AssocArgumentParametre ()
	{}

Chaine 
AssocArgumentParametre :: Nom ()
	{ return fNom; }

int 
AssocArgumentParametre :: NumeroDeParametre ()
	{ return fNumeroDeParametre; }

ContexteDEvaluationPTR 
AssocArgumentParametre :: ContexteDEvaluation ()
	{ return fContexteDEvaluation; }


// ------------------------------------------------------------------------
//	AssocArgumentParametreParValeur
// ------------------------------------------------------------------------

AssocArgumentParametreParValeur :: AssocArgumentParametreParValeur (
	Chaine						leNom,
	Chaine						leNomQualifie,
	int							leNumeroDeParametre,
	ContexteDEvaluationPTR	leContexteDEvaluation,
	ValeurLista					laValeur )
	:	AssocArgumentParametre (
			leNom, leNomQualifie, leNumeroDeParametre, leContexteDEvaluation )
	{ fValeur = laValeur; }

AssocArgumentParametreParValeur :: ~ AssocArgumentParametreParValeur ()
	{}

void 
AssocArgumentParametreParValeur :: Ecrire (int lIndentation)
	{
	Indenter (lIndentation);
	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatParametreParValeur (),
			fNomQualifie,
			fNumeroDeParametre );
	fValeur.Ecrire (lIndentation);
	std::cout << std::endl;
	}

// -------------------------------------------------------------------------

ValeurLista 
AssocArgumentParametreParValeur :: Evaluer (int lIndentation)
	{
	if (fContexteDEvaluation -> TraceDEvaluation ())
		{
		Indenter (lIndentation);
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatConsultationParametreParValeur (),
				fNomQualifie,
				fNumeroDeParametre,
				fContexteDEvaluation -> NumeroContexteDEvaluation () ) <<
			std::endl;

		Indenter (lIndentation);
		std::cout <<
			gLANGUE_Semantique ->
				ResultatEvaluation ();
		fValeur.Ecrire (lIndentation);
		std::cout << std::endl;
		}

	return fValeur;
	}	// AssocArgumentParametreParValeur :: Evaluer


// ------------------------------------------------------------------------
//	AssocArgumentParametreParNom
// ------------------------------------------------------------------------

AssocArgumentParametreParNom :: AssocArgumentParametreParNom (
	Chaine						leNom,
	Chaine						leNomQualifie,
	int							leNumeroDeParametre,
	DescrSemantiquePTR		leGrapheSemantique,
	ContexteDEvaluationPTR	leContexteDEvaluation )
	:	AssocArgumentParametre (
			leNom, leNomQualifie, leNumeroDeParametre, leContexteDEvaluation )
	{
	fGrapheSemantique = leGrapheSemantique;
	fContexteDEvaluation = leContexteDEvaluation;
	}

AssocArgumentParametreParNom :: ~ AssocArgumentParametreParNom ()
	{}

void 
AssocArgumentParametreParNom :: Ecrire (int lIndentation)
	{
	Indenter (lIndentation);
	std::cout <<
		MiseEnForme (
			gLANGUE_Semantique ->
				FormatParametreParNom (),
			fNomQualifie,
			fNumeroDeParametre ) <<
		std::endl;
	fGrapheSemantique -> Ecrire (lIndentation + 1);
	}

// -------------------------------------------------------------------------

ValeurLista 
AssocArgumentParametreParNom :: Evaluer (int lIndentation)
	{
	bool	traceDEvaluation = fContexteDEvaluation -> TraceDEvaluation ();

	if (traceDEvaluation)
		{
		Indenter (lIndentation);
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatEvaluationParametreParNom (),
				fNomQualifie,
				fNumeroDeParametre,
				fContexteDEvaluation -> NumeroContexteDEvaluation () ) <<
			std::endl;
		}

	ValeurLista		res = fGrapheSemantique -> Evaluer (fContexteDEvaluation);

	if (traceDEvaluation)
		{
		Indenter (lIndentation);
		std::cout <<
			gLANGUE_Semantique ->
				ResultatEvaluation ();
		res.Ecrire (lIndentation);
		std::cout << std::endl;
		}

	return res;
	}	// AssocArgumentParametreParNom :: Evaluer


// ------------------------------------------------------------------------
//	AssocArgumentParametreParBesoin
// ------------------------------------------------------------------------

AssocArgumentParametreParBesoin :: AssocArgumentParametreParBesoin (
	Chaine						leNom,
	Chaine						leNomQualifie,
	int							leNumeroDeParametre,
	DescrSemantiquePTR		leGrapheSemantique,
	ContexteDEvaluationPTR	leContexteDEvaluation )
	:	AssocArgumentParametre (
			leNom, leNomQualifie, leNumeroDeParametre, leContexteDEvaluation )
	{
	fGrapheSemantique = leGrapheSemantique;
	fContexteDEvaluation = leContexteDEvaluation;
	fValeurDisponible = false;
	}

AssocArgumentParametreParBesoin :: ~ AssocArgumentParametreParBesoin ()
	{}

void 
AssocArgumentParametreParBesoin :: Ecrire (int lIndentation)
	{
	Indenter (lIndentation);

	if (! fValeurDisponible)
		{
		std::cout <<
			MiseEnForme (
				gLANGUE_Semantique ->
					FormatParametreParBesoinNonEvalue (),
				fNomQualifie,
				fNumeroDeParametre ) <<
			std::endl;
		fGrapheSemantique -> Ecrire (lIndentation + 1);
		}
	else
		{
		std::cout <<
			gLANGUE_Semantique ->
				ParametreParBesoinDejaEvalue ();
		fValeur.Ecrire (lIndentation);
		}
	}

// -------------------------------------------------------------------------

ValeurLista 
AssocArgumentParametreParBesoin :: Evaluer (int lIndentation)
	{
	long	numeroContexteDEvaluation =
				fContexteDEvaluation -> NumeroContexteDEvaluation ();
	bool	traceDEvaluation			=
				fContexteDEvaluation -> TraceDEvaluation ();

	if (! fValeurDisponible)
		{
		if (traceDEvaluation)
			{
			Indenter (lIndentation);
			std::cout <<
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatEvaluationParametreParBesoin (),
					fNomQualifie,
					fNumeroDeParametre,
					numeroContexteDEvaluation ) <<
				std::endl;
			}

		fValeur = fGrapheSemantique -> Evaluer (fContexteDEvaluation);

		if (traceDEvaluation)
			{
			Indenter (lIndentation);
			std::cout <<
				gLANGUE_Semantique ->
					ResultatEvaluation ();
			fValeur.Ecrire (lIndentation);
			std::cout << std::endl;
			}

		fValeurDisponible = true;
		}

	else
		{
		if (traceDEvaluation)
			{
			Indenter (lIndentation);
			std::cout <<
				MiseEnForme (
					gLANGUE_Semantique ->
						FormatConsultationParametreParBesoin (),
					fNomQualifie,
					fNumeroDeParametre,
					numeroContexteDEvaluation ) <<
				std::endl;
			Indenter (lIndentation);
			std::cout <<
				gLANGUE_Semantique ->
					ResultatEvaluation ();
			fValeur.Ecrire (lIndentation);
			std::cout << std::endl;
			}
		}

	return fValeur;
	}	//	AssocArgumentParametreParBesoin :: Evaluer


// -------------------------------------------------------------------------
//	DescrParametre
// -------------------------------------------------------------------------

DescrParametre :: DescrParametre (
	int							leNumeroDeParametre,
	StrategieDEvaluationPTR	laStrategieDEvaluation )
	{
	fParametreFormel = NULL;	//	doit etre mis a jour plus tard

	fNumeroDeParametre = leNumeroDeParametre;
	fStrategieDEvaluation = laStrategieDEvaluation;

	fNiveauDEvaluation	=
		gAnalyseurSemantiqueLista -> NiveauDEvaluationCourant ();
	fNiveauStatique		=
		gAnalyseurSemantiqueLista -> NiveauStatiqueCourant ();

#if defined SYNTHESE_PILUM
	fPositionDansLeBloc = 0;
#endif /* SYNTHESE_PILUM */
	}

DescrParametre :: ~ DescrParametre ()
	{}


// -------------------------------------------------------------------------

void 
DescrParametre :: ParametreFormel (ParametreFormelPTR leParametreFormel)
	{ fParametreFormel = leParametreFormel; }

ParametreFormelPTR 
DescrParametre :: ParametreFormel ()
	{ return fParametreFormel; }

int 
DescrParametre :: NumeroDeParametre ()
	{ return fNumeroDeParametre; }

StrategieDEvaluationPTR 
DescrParametre :: StrategieDEvaluation ()
	{ return fStrategieDEvaluation; }

int 
DescrParametre :: NiveauDEvaluation ()
	{ return fNiveauDEvaluation; }
int 
DescrParametre :: NiveauStatique ()
	{ return fNiveauStatique; }

#if defined SYNTHESE_PILUM

void 
DescrParametre :: PositionDansLeBloc (long laPosition)
	{ fPositionDansLeBloc = laPosition; }

long 
DescrParametre :: PositionDansLeBloc ()
	{ return fPositionDansLeBloc; }

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	DescrParametreParValeur
// -------------------------------------------------------------------------

DescrParametreParValeur :: DescrParametreParValeur (
	int		leNumeroDeParametre )
	:	DescrParametre (leNumeroDeParametre, gStrategieParValeur)
	{}

DescrParametreParValeur :: ~ DescrParametreParValeur ()
	{}

AssocArgumentParametrePTR 
DescrParametreParValeur :: CreerAssocArgumentParametre (
	DescrSemantiquePTR		lArgumentDAppel,
	ContexteDEvaluationPTR	leContexteDEvaluation )
	{
	//	on evalue l'argument AVANT d'entrer dans la fonction
	return
		new AssocArgumentParametreParValeur (
			fParametreFormel -> Nom (),
			fParametreFormel -> NomQualifie (),
			fNumeroDeParametre,
			leContexteDEvaluation,
			lArgumentDAppel -> Evaluer (leContexteDEvaluation) );
	}

// -------------------------------------------------------------------------

#if defined SYNTHESE_PILUM

int 
DescrParametreParValeur :: TailleEnMemoire ()
	//	la valeur a déjà été évaluée, donc 1 cellule dans ce cas
	{ return 1; }

void 
DescrParametreParValeur :: Synthetiser (
	ContexteDeSynthesePTR	leContexteDeSynthese,
	DescrSemantiquePTR		lArgumentDAppel )
	{
	//	on evalue l'argument AVANT d'entrer dans la fonction

	lArgumentDAppel -> Synthetiser (leContexteDeSynthese);
	}

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	DescrParametreParNom
// -------------------------------------------------------------------------

DescrParametreParNom :: DescrParametreParNom (
	int		leNumeroDeParametre )
:	DescrParametre (leNumeroDeParametre, gStrategieParNom)
	{}

DescrParametreParNom :: ~ DescrParametreParNom ()
	{}

AssocArgumentParametrePTR 
DescrParametreParNom :: CreerAssocArgumentParametre (
	DescrSemantiquePTR		lArgumentDAppel,
	ContexteDEvaluationPTR	leContexteDEvaluation )
	{
	//	on passe l'argument NON EVALUE à la fonction
	return
		new AssocArgumentParametreParNom (
			fParametreFormel -> Nom (),
			fParametreFormel -> NomQualifie (),
			fNumeroDeParametre,
			lArgumentDAppel,
			leContexteDEvaluation );
	}

// -------------------------------------------------------------------------

#if defined SYNTHESE_PILUM

int 
DescrParametreParNom :: TailleEnMemoire ()
	//	le descripteur contient l'adresse du thunk et le lien statique
	{ return 2; }


void 
DescrParametreParNom :: Synthetiser (
	ContexteDeSynthesePTR	leContexteDeSynthese,
	DescrSemantiquePTR		lArgumentDAppel )
	{
	SynthetiseurPilumListaPTR
				synth = leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	//	on passe l'argument NON EVALUE à la fonction:
	//	pour cela on cree un THUNK

	VariableLogiqueEtiquettePTR
				lEtiquetteDuThunk =
					synth -> SynthetiserCorpsDeThunk (
						leContexteDeSynthese,
						this,
						lArgumentDAppel );

	synth -> EmpilerDescripteurDeThunk (lEtiquetteDuThunk);

	}	//	DescrParametreParNom :: Synthetiser

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	DescrParametreParBesoin
// -------------------------------------------------------------------------

DescrParametreParBesoin :: DescrParametreParBesoin (
	int		leNumeroDeParametre )
	:	DescrParametre (leNumeroDeParametre, gStrategieParBesoin)
	{}

DescrParametreParBesoin :: ~ DescrParametreParBesoin ()
	{}

AssocArgumentParametrePTR 
DescrParametreParBesoin :: CreerAssocArgumentParametre (
	DescrSemantiquePTR		lArgumentDAppel,
	ContexteDEvaluationPTR	leContexteDEvaluation )
	{
	//	on passe l'argument NON EVALUE à la fonction
	return
		new AssocArgumentParametreParBesoin (
			fParametreFormel -> Nom (),
			fParametreFormel -> NomQualifie (),
			fNumeroDeParametre,
			lArgumentDAppel,
			leContexteDEvaluation );
	}

// -------------------------------------------------------------------------

#if defined SYNTHESE_PILUM

int 
DescrParametreParBesoin :: TailleEnMemoire ()
	//	le booleen de controle, la valeur apres calcul,
	//	l'adresse du thunk et le lien statique
	{ return 4; }


void 
DescrParametreParBesoin :: Synthetiser (
	ContexteDeSynthesePTR	leContexteDeSynthese,
	DescrSemantiquePTR		lArgumentDAppel )
	{
	SynthetiseurPilumListaPTR
				synth = leContexteDeSynthese -> LeSynthetiseurPilumLista ();

	//	on empile le booleen de controle (faux initialement),
	//	on alloue la place pour la valeur,
	//	et on passe l'argument NON EVALUE à la fonction:
	//	pour cela on cree un THUNK

	VariableLogiqueEtiquettePTR
				lEtiquetteDuThunk =
					synth -> SynthetiserCorpsDeThunk (
						leContexteDeSynthese,
						this,
						lArgumentDAppel );

	synth -> Logique (true);
	//	le thunk doit encore etre evalue une premiere fois

	synth -> ValeurInconnue ();
	//	valeur neutre avant evaluation effective

	synth -> EmpilerDescripteurDeThunk (lEtiquetteDuThunk);

	}	//	DescrParametreParBesoin :: Synthetiser

#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
//	ListeDeParametresFormels
// -------------------------------------------------------------------------

ListeDeParametresFormels :: ListeDeParametresFormels ()
	{}

ListeDeParametresFormels :: ~ ListeDeParametresFormels ()
	{
	ListeDesDescrParametres :: iterator	i;
	
	for (
		i = fListeDesDescrParametres.begin ();
		i != fListeDesDescrParametres.end ();
		++ i )
		{
		delete (* i);
		}	// for
	}	//	ListeDeParametresFormels :: ~ ListeDeParametresFormels


ListeDesDescrParametresPTR 
ListeDeParametresFormels :: LaListeDesDescrParametres ()
	{ return & fListeDesDescrParametres; }

bool 
ListeDeParametresFormels :: Vide ()
	{ return fListeDesDescrParametres.size () == 0; }

void 
ListeDeParametresFormels :: Ajouter (DescrParametrePTR leParametre)
	{ fListeDesDescrParametres.push_back (leParametre); }

int 
ListeDeParametresFormels :: NombreDeParametres ()
	{ return fListeDesDescrParametres.size (); }

// -------------------------------------------------------------------------

Chaine 
ListeDeParametresFormels :: NomsDesParametres ()
	{
	Chaine	res = "";

	ListeDesDescrParametres :: iterator
				i;
	int		nombreDeParametres =
					fListeDesDescrParametres.size ();
	
	for (
		i = fListeDesDescrParametres.begin ();
		i != fListeDesDescrParametres.end ();
		++ i )
		{
		Chaine	leNom =
						(* i) -> ParametreFormel () -> Nom ();
		Chaine	separation;
		
		if ((* i) == fListeDesDescrParametres.at (nombreDeParametres - 1))
			separation =
				gLANGUE_Semantique ->
					SeparationDernierParametre ();
		else
			separation	= ", ";
			
		res =
			(* i) == fListeDesDescrParametres.at (0)
				?	MiseEnForme (
						"'%s'",
						leNom )
				:	MiseEnForme (
						"%s%s'%s'",
						res,
						separation,
						leNom );
		}	// for

	return res;
	}	//	ListeDeParametresFormels :: NomsDesParametres

// -------------------------------------------------------------------------

Chaine 
ListeDeParametresFormels :: ProfilDesParametres ()
	{
	Chaine	res = "";

	ListeDesDescrParametres :: iterator
				i;
	int		nombreDeParametres =
					fListeDesDescrParametres.size ();
	
	for (
		i = fListeDesDescrParametres.begin ();
		i != fListeDesDescrParametres.end ();
		++ i )
		{
		Chaine	separation;
		
		if ((* i) != fListeDesDescrParametres.at (nombreDeParametres - 1))
			separation = ", ";
		else
			separation	= "";

		res =
			MiseEnForme (
				"%s%s%s",
				res,
				(* i) -> ParametreFormel () ->
					TypeIdentificateur () -> SousFormeDeChaine (),
				separation );
		}	//	if

	return res;
	}	//	ListeDeParametresFormels :: ProfilDesParametres ()


// -------------------------------------------------------------------------

#if defined SYNTHESE_PILUM

void 
ListeDeParametresFormels :: AllouerLesParametres (int positionDeDepart)
	{
	EffectuerAllocation (
		fListeDesDescrParametres.begin (),
		 positionDeDepart,
		 fTailleDesParametres );
		//	on jette la valeur retournee, c'est l'effet de bord
		//	sur "fTailleDesParametres" qui compte
	}

int 
ListeDeParametresFormels :: EffectuerAllocation (
	ListeDesDescrParametres :: iterator		parametreCourant,
	int												positionDeDepart,
	int												& tailleAccumulee )
	//	alloue "* parametreCourant" dans le bloc d'activation
	//	AU RETOUR DE LA RECURSION,
	//	donc en parcourant la liste en ordre inverse
	{
	if (parametreCourant != fListeDesDescrParametres.end ())
		{
		int		laPosition =
						EffectuerAllocation (
							parametreCourant + 1,
							positionDeDepart,
							tailleAccumulee );

		int		tailleDuParametre =
						(* parametreCourant) -> TailleEnMemoire ();
		
		tailleAccumulee += tailleDuParametre;

		(* parametreCourant) -> PositionDansLeBloc (
			laPosition - tailleDuParametre + 1 );
		
		return laPosition - tailleDuParametre;
		}

	else
		{
		tailleAccumulee = 0;
		return positionDeDepart;
		}
	}	//	ListeDeParametresFormels :: EffectuerAllocation


int 
ListeDeParametresFormels :: TailleDesParametres ()
	{ return fTailleDesParametres; }

#endif /* SYNTHESE_PILUM */

