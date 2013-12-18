%{

/* déclarations globales */

// =========================================================================
//	PutzerVersionDeTravail.Flex
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


/*
Ou comment exploiter les modes de Lex et une pile pour faire l'analyse 
d'une grammaire independante du contexte...
*/


/* ---------------------------------------------------------------------- */
/* Inclusions */
/* ---------------------------------------------------------------------- */


#include <iostream>

#include <cstdlib>
#include <cstdio>


/* ---------------------------------------------------------------------- */
/* Variables globales */
/* ---------------------------------------------------------------------- */

/*
bool									gMontrerLesTerminaux;

//	on gere les deux lignes precedant la ligne courante
//	la premiere acceptation d'une expression reguliere donne leur vraie
//	valeur initiale aux trois variables suivantes :
char									* gDebutLigneCourante;
char									* gDebutLigneCourante_1;	// la precedente
char									* gDebutLigneCourante_2;	// la precedente de la precedente

int									gTailleTamponAuxiliaire		=
											1024;	// pourra croitre si necessaire
char									* gTamponAuxiliaire			=
											AllouerUnTampon (gTailleTamponAuxiliaire);

bool									gPremierTerminalDejaAccepte;
TerminalF							gTerminalFCourant;
*/

	
struct DescriptionDeMode
	{
	int								fMode;
	int								fDebut;
	bool								fElseRencontre;
	};


const int							mINITIAL				= 0;
const int							mLISTES				= 1;
const int							mAVEC_PROMESSES	= 2;
const int							mSYNTHESE_PILUM	= 3;
const int							mDEBUG_PILUM		= 4;


char *								nomDuMode [] =
											{
											"INITIAL",
											"LISTES",
											"AVEC_PROMESSES",
											"SYNTHESE_PILUM",
											"DEBUG_PILUM"
											};
/*
char *								nomDuMode [10];

nomDuMode [mINITIAL]				= "INITIAL";
nomDuMode [mLISTES]				= "LISTES";
nomDuMode [mAVEC_PROMESSES]	= "AVEC_PROMESSES";
nomDuMode [mSYNTHESE_PILUM]	= "SYNTHESE_PILUM";
nomDuMode [mDEBUG_PILUM]		= "DEBUG_PILUM";
*/

const int							kTailleDeLaPileDesModes = 10;
struct DescriptionDeMode		pileDesModes [kTailleDeLaPileDesModes];
int									sommetDeLaPileDesModes = -1;		// vide
struct DescriptionDeMode		modeCourant = 
											{ INITIAL, false };


/* ---------------------------------------------------------------------- */
/* Fonctions */
/* ---------------------------------------------------------------------- */

void									AfficherLImbricationDesModes ();

bool									IlFautIgnorer ();											

void									Inaction ();

void									DebutDeMode (int leMode);
void									FinDeMode (int leMode);

%}


/* ---------------------------------------------------------------------- */
/* Options */
/* ---------------------------------------------------------------------- */

%option	yylineno


/* ---------------------------------------------------------------------- */
/* Expressions régulières */
/* ---------------------------------------------------------------------- */

blancs								[ \t]*
finDeLigne							[\n]
queueDeLigneBlanche				{blancs}{finDeLigne}
queueDeLigneQuelconque			(.)*{finDeLigne}

ifDefinedLISTES					{blancs}#{blancs}if{blancs}defined{blancs}LISTES{queueDeLigneBlanche}
ifDefinedAVEC_PROMESSES			{blancs}#{blancs}if{blancs}defined{blancs}AVEC_PROMESSES{queueDeLigneBlanche}
ifDefinedSYNTHESE_PILUM			{blancs}#{blancs}if{blancs}defined{blancs}SYNTHESE_PILUM{queueDeLigneBlanche}
ifDefinedDEBUG_PILUM				{blancs}#{blancs}if{blancs}defined{blancs}DEBUG_PILUM{queueDeLigneBlanche}
else									{blancs}#{blancs}else{queueDeLigneQuelconque}
endif									{blancs}#{blancs}endif{queueDeLigneQuelconque}

/* modes exclusifs, pour que les autres productions ne s'appliquent pas */
%x										LISTES
%x										AVEC_PROMESSES
%x										SYNTHESE_PILUM
%x										DEBUG_PILUM



%%	/* Les terminaux du langage et les actions correspondantes */


%{
/* Variables locales à "yylex" */
%}


<LISTES>{else} |
<AVEC_PROMESSES>{else}			{
										std::cerr <<
											"--> " <<
											yylineno - 1 <<
											": else, inclus dans " <<
											nomDuMode [modeCourant.fMode] <<
											std::endl;

										modeCourant.fElseRencontre = ! modeCourant.fElseRencontre;

										AfficherLImbricationDesModes ();
										}


{ifDefinedLISTES} |
<AVEC_PROMESSES>{ifDefinedLISTES} |
<SYNTHESE_PILUM>{ifDefinedLISTES} |
<DEBUG_PILUM>{ifDefinedLISTES}	{
										DebutDeMode (LISTES);
										}


<LISTES>.							{
										Inaction (); /* on ne garde pas */
										}
<LISTES>{finDeLigne}				{
										Inaction (); /* on ne garde pas */
										}


<LISTES>{endif}					{
										FinDeMode (LISTES);
										}



{ifDefinedAVEC_PROMESSES} |
<LISTES>{ifDefinedAVEC_PROMESSES} |
<SYNTHESE_PILUM>{ifDefinedAVEC_PROMESSES}	|
<DEBUG_PILUM>{ifDefinedAVEC_PROMESSES}		{
										DebutDeMode (AVEC_PROMESSES);
										}


<AVEC_PROMESSES>.					{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */
										else
											Inaction (); /* on ne garde pas */
										}
<AVEC_PROMESSES>{finDeLigne}	{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */
										else
											Inaction (); /* on ne garde pas */
										}


<AVEC_PROMESSES>{endif}			{
										FinDeMode (AVEC_PROMESSES);
										}



{ifDefinedSYNTHESE_PILUM} |
<LISTES>{ifDefinedSYNTHESE_PILUM} |
<AVEC_PROMESSES>{ifDefinedSYNTHESE_PILUM}	{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */

										DebutDeMode (SYNTHESE_PILUM);
										}


<SYNTHESE_PILUM>.					{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */
										}
<SYNTHESE_PILUM>{finDeLigne}	{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */
										}


<SYNTHESE_PILUM>{endif}			{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */

										FinDeMode (SYNTHESE_PILUM);
										}



{ifDefinedDEBUG_PILUM} |
<LISTES>{ifDefinedDEBUG_PILUM} |
<AVEC_PROMESSES>{ifDefinedDEBUG_PILUM}	{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */

										DebutDeMode (DEBUG_PILUM);
										}


<DEBUG_PILUM>.						{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */
										}
<DEBUG_PILUM>{finDeLigne}		{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */
										}


<DEBUG_PILUM>{endif}				{
										if (! IlFautIgnorer ())
											ECHO; /* on garde */

										FinDeMode (DEBUG_PILUM);
										}


{finDeLigne}						{
										ECHO; /* on garde */
										}
.										{
										ECHO; /* on garde */
										}



%%	/* Le code de service */
	/* ------------------ */


/* ---------------------------------------------------------------------- */
/* AfficherLImbricationDesModes */
/* ---------------------------------------------------------------------- */

void
AfficherLImbricationDesModes ()
	{
	int		curseur;
	
	std::cerr <<
		"--> " <<
		yylineno - 1 <<
		": Imbrication des modes (" <<
		sommetDeLaPileDesModes <<
		" elements):" <<
		std::endl;

	for (
		curseur = 0;
		curseur <= sommetDeLaPileDesModes;
		curseur ++
		)
		{
		std::cerr <<
			"               " <<
			curseur <<
			": " <<
			nomDuMode [pileDesModes [curseur].fMode] <<
			", depuis " <<
			pileDesModes [curseur].fDebut <<
			", elseRencontre = " <<
			pileDesModes [curseur].fElseRencontre <<
			std::endl;
		}	// for
	
	std::cerr <<
		"     modeCourant: " <<
		nomDuMode [modeCourant.fMode] <<
		", depuis " <<
		modeCourant.fDebut <<
		", elseRencontre = " <<
		modeCourant.fElseRencontre <<
		std::endl;

	std::cerr << std::endl;
	}	// AfficherLImbricationDesModes
											

/* ---------------------------------------------------------------------- */
/* IlFautIgnorer */
/* ---------------------------------------------------------------------- */

bool
IlFautIgnorer ()
	{
	int		curseur;
	
	for (
		curseur = 0;
		curseur <= sommetDeLaPileDesModes;
		curseur ++
		)
		{
		bool		modeATraiterEventuellement =
						pileDesModes [curseur].fMode == LISTES
							||
						pileDesModes [curseur].fMode == AVEC_PROMESSES;
		
		if (modeATraiterEventuellement)	
			{
/*
			std::cerr <<
				"**> " <<
				yylineno - 1 <<
				": mode LISTES ou AVEC_PROMESSES dans la pile" <<
				", elseRencontre = " <<
				pileDesModes [curseur].fElseRencontre <<
				std::endl;
*/

			bool		res = 
							! pileDesModes [curseur].fElseRencontre;

			if (res)
				{
/*
				std::cerr <<
					"--> " <<
					yylineno - 1 <<
					": il faut ignorer" <<
					std::endl;
*/

				return true;
				}	// if
			}	// if
		}	// for


	bool		modeATraiterEventuellement =
					modeCourant.fMode == LISTES
						||
					modeCourant.fMode == AVEC_PROMESSES;

	if (modeATraiterEventuellement)	
		{
/*
		std::cerr <<
			"**> " <<
			yylineno - 1 <<
			": mode LISTES ou AVEC_PROMESSES dans modeCourant" <<
			", elseRencontre = " <<
			modeCourant.fElseRencontre <<
			std::endl;
*/

		bool		res = 
						! modeCourant.fElseRencontre;

		if (res)
			{
/*
			std::cerr <<
				"--> " <<
				yylineno - 1 <<
				": il faut ignorer" <<
				std::endl;
*/

			return true;
			}	// if
		}	// if
	
	return false;
	}	// IlFautIgnorer


/* ---------------------------------------------------------------------- */
/* Inaction */
/* ---------------------------------------------------------------------- */

void 
Inaction ()
	{}


/* ---------------------------------------------------------------------- */
/* DebutDeMode */
/* ---------------------------------------------------------------------- */

void
DebutDeMode (int leMode)
	{
	std::cerr <<
		"--> " <<
		yylineno - 1 <<
		": mode " <<
		nomDuMode [leMode] <<
		", inclus dans " <<
		nomDuMode [modeCourant.fMode] <<
		std::endl;

	if (++ sommetDeLaPileDesModes >= kTailleDeLaPileDesModes)
		{
		std::cerr <<
			"Il y a plus de " << 
			kTailleDeLaPileDesModes <<
			" modes imbriques!" <<
			std:: endl;
		}
	pileDesModes [sommetDeLaPileDesModes] = modeCourant;

	modeCourant.fMode = leMode;
	modeCourant.fDebut = yylineno - 1;
	modeCourant.fElseRencontre = false;

	AfficherLImbricationDesModes ();

	BEGIN modeCourant.fMode;
	}	// DebutDeMode


/* ---------------------------------------------------------------------- */
/* FinDeMode */
/* ---------------------------------------------------------------------- */

void
FinDeMode (int leMode)
	{
	if (sommetDeLaPileDesModes < 0)
		{
		std::cerr <<
			"Il y a un 'endif' sans ouvreur correspondant!" <<
			std:: endl;
		}

	std::cerr <<
		"--> " <<
		yylineno - 1 <<
		": fin du mode " <<
		nomDuMode [leMode] <<
		" debutant en " <<
		modeCourant.fDebut;

	modeCourant =
		pileDesModes [sommetDeLaPileDesModes --];
		
	std::cerr <<
		", on revient au mode " <<
		nomDuMode [modeCourant.fMode] <<
		std::endl << std::endl;

	BEGIN modeCourant.fMode;
	}	// FinDeMode
