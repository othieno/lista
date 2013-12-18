// =========================================================================
//	SupportCPlusPlus.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __SupportCPlusPlus__
#define __SupportCPlusPlus__


#include "Types.h"

#include "LanguesSupportCPlusPlus.h"

#include <iostream>
#include <fstream>

#include <vector>


// -------------------------------------------------------------------------
//	Chaines
// -------------------------------------------------------------------------

CharPTR								AllouerUnTampon (int laTaille);

CharPTR								SauvegarderChaine (CharPTR laChaine);

Chaine								MiseEnForme (
											Chaine	leFormat,
											int		lEntier );
Chaine								MiseEnForme (
											Chaine	leFormat,
											double	leFlottant );
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine );
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	chaine1,
											Chaine	chaine2 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	chaine1,
											Chaine	chaine2,
											Chaine	chaine3 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	chaine1,
											Chaine	chaine2,
											Chaine	chaine3,
											Chaine	chaine4 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	chaine1,
											Chaine	chaine2,
											Chaine	chaine3,
											Chaine	chaine4,
											Chaine	chaine5 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	chaine1,
											Chaine	chaine2,
											Chaine	chaine3,
											int		lEntier );
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine,
											int		lEntier1,
											int		lEntier2,
											double	leFlottant);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine,
											int		lEntier);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine,
											int		lEntier1,
											int		lEntier2);
Chaine								MiseEnForme (
											Chaine	leFormat,
											int		lEntier1,
											int		lEntier2);
Chaine								MiseEnForme (
											Chaine	leFormat,
											long		lEntier);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	chaine1,
											int		lEntier,
											Chaine	chaine2,
											Chaine	chaine3 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											int		lEntier1,
											int		lEntier2,
											double	leFlottant);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine1,
											Chaine	laChaine2,
											int		lEntier1,
											int		lEntier2,
											int		lEntier3,
											int		lEntier4);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine1,
											Chaine	laChaine2,
											int		lEntier1,
											int		lEntier2,
											int		lEntier3,
											int		lEntier4,
											int		lEntier5);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine,
											int		lEntier1,
											int		lEntier2,
											int		lEntier3,
											int		lEntier4);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine1,
											int		lEntier1,
											int		lEntier2,
											Chaine	laChaine2 );
Chaine								MiseEnForme (
											Chaine		leFormat,
											int			lEntier1,
											int			lEntier2,
											char			leCaractere1,
											char			leCaractere2,
											Chaine		laChaine1,
											CharPTR		laChaine2,
											Chaine		laChaine3 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											int		lEntier,
											Chaine	laChaine1,
											Chaine	laChaine2,
											Chaine	laChaine3 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											int		lEntier,
											Chaine	laChaine1,
											Chaine	laChaine2 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											int		lEntier,
											Chaine	laChaine);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	laChaine1,
											int		lEntier,
											Chaine	laChaine2 );
Chaine								MiseEnForme (
											Chaine	leFormat,
											long		lEntier,
											Chaine	laChaine);
Chaine								MiseEnForme (
											Chaine	leFormat,
											Chaine	chaine1,
											Chaine	chaine2,
											Chaine	chaine3,
											int		lEntier1,
											int		lEntier2 );


// -------------------------------------------------------------------------
//	SortieSurErreur
// -------------------------------------------------------------------------

void									SortieSurErreur (
											Chaine	message,
											int		valeurDeSortie );

									
// -------------------------------------------------------------------------
//	Fichiers
// -------------------------------------------------------------------------

void									MontrerLeContenuDuFichier (Chaine nomDuFichier);

Chaine								NomDuFichierSansExtension (
											Chaine nomDuFichierSource );

bool									EcritureFichierOK (
											std::ofstream		& leFichier,
											Chaine				leNomDuFichier);

Chaine								DecoderErreurLecture (
											std::ifstream		& leFichier,
											Chaine				leNomDuFichier );


// -------------------------------------------------------------------------
//	Lectures
// -------------------------------------------------------------------------

enum GenreLectureAuClavier
	{
	kLectureSansAutre,
	
	kLectureIgnorantLePremierCaractere	// pour evaluation directe par ListaPredictifDescenteRecursive
	};


Chaine								FLireChaine (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											Chaine						message );
CharPTR								FLireChaine (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											CharPTR					message );

long									FLireEntier (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											Chaine						message );
double								FLireFlottant (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											Chaine						message );
bool									FLireBooleen (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											Chaine						message,
											Chaine						chaineVrai);
char									FLireCaractere (
											GenreLectureAuClavier	leGenreLectureAuClavier,
											Chaine						message );


// -------------------------------------------------------------------------
//	Mise en page
// -------------------------------------------------------------------------

extern void							Indenter (int lIndentation);


// -------------------------------------------------------------------------
//	Chaines de caracteres
// -------------------------------------------------------------------------

Chaine								FConcatChaines (
											Chaine	chaine1,
											Chaine	chaine2 );
CharPTR								FConcatChaines (
											CharPTR	chaine1,
											CharPTR	chaine2 );

Chaine								FRepliquerChaine (
											Chaine	laChaine,
											int		nbOccurrences );
CharPTR								FRepliquerChaine (
											CharPTR	chaine,
											int			nbOccurrences );

Chaine								FRemplacerChaine (
											Chaine	laChaine,
											Chaine	fragment,
											Chaine	succedane );
CharPTR								FRemplacerChaine (
											CharPTR	chaine,
											CharPTR	fragment,
											CharPTR	succedane );

Chaine								FFormaterFlottant (
											double	leFlottant,
											int		tailleDuChamp,
											int		taillePartieDecimale );


// -------------------------------------------------------------------------
//	Hasard
// -------------------------------------------------------------------------

double								FHasard ();


// -------------------------------------------------------------------------
//	Variables logiques
// -------------------------------------------------------------------------

template <class TClass>
class VariableLogique

	//	Gestion de variables logiques 'a la Prolog'
	//	Toutes les variables dŽsignant la mme chose sont liŽes
	//	entre elles par le champ 'fLiaisonAutreVariable'
	//	Seule celle ˆ la fin de la cha”ne reoit une valeur dans
	//	son champ 'fValeur' lors d'une affectation
	//	On utilise la valeur 'gLiaisonVariableLogiqueLIBRE'
	//	pour indiquer une variable libre en fin de cha”ne

	{
public:
										VariableLogique (
											Chaine	laDescrVariableLogique,
											TClass	* laValeurDeLiaisonInitiale =
															gLiaisonVariableLogiqueLIBRE )
														//	initialement libre par defaut
											{
											fLiaisonAutreVariable = NULL;
											fValeur = laValeurDeLiaisonInitiale;
											
											fDescrVariableLogique = laDescrVariableLogique;
											fIDVariableLogique = ++ gCompteurVariablesLogiques;
											}

   void								operator delete (void * ptr)
											{
											// ne PAS utiliser ':: delete ptr': 
											// une VariableLogique doit perdurer
											//	 jusqu'ˆ la fin de la compilation !
											}


 	Chaine							SousFormeDeChaine ()
											{ 
											return
												MiseEnForme (
													gLANGUE_SupportCPlusPlus ->
														FormatVariableLogique (),
													fIDVariableLogique,
													fDescrVariableLogique,
													ValeurDeLiaison () ->
														SousFormeDeChaine () );
											}


	bool								UnifierAutreVariable (
											VariableLogique * lAutreVariableLogique )
											//	Žchoue si unification impossible
											{
											//	On commence par chercher les deux fins de cha”ne
											
											VariableLogique
														* curseur = this;
											
											while (curseur -> fLiaisonAutreVariable != NULL)
												curseur = curseur -> fLiaisonAutreVariable;
											
											VariableLogique
														* autreCurseur = lAutreVariableLogique;
											
											while (autreCurseur -> fLiaisonAutreVariable != NULL)
												autreCurseur = autreCurseur -> fLiaisonAutreVariable;
											

											//	On essaye maintenant d'unifier
											
											if (curseur == autreCurseur)
												//	les deux variables sont dŽjˆ unifiŽes
												return true;

											if (curseur -> fValeur == gLiaisonVariableLogiqueLIBRE)
												//	le receveur est une variable libre
												if (autreCurseur -> fValeur == gLiaisonVariableLogiqueLIBRE)
													//	les deux variables sont libres,
													//	on LIE le receveur ˆ l'autre
													//	en Žvitant d'allonger les cha”nes
													{
													fLiaisonAutreVariable = autreCurseur;
													return true;
													}
												else
													//	l'autre variable est seule liŽe,
													//	on AFFECTE sa valeur au receveur
													{
													curseur -> fValeur = autreCurseur -> fValeur;
													return true;
													}

											else
												//	le receveur est une variable liŽe
												if (autreCurseur -> fValeur != gLiaisonVariableLogiqueLIBRE)
													//	les deux variables sont liŽes
													{
													return
														curseur -> fValeur == autreCurseur -> fValeur;
													}
												else
													//	l'autre variable est seule libre,
													//	on lui AFFECTE la valeur du receveur
													{
													autreCurseur -> fValeur = curseur -> fValeur;
													return true;
													}
											}	//	VariableLogique :: UnifierAutreVariable


	bool								UnifierValeur (
											TClass	* uneValeur,
											bool		montrerLaLaisonEventuelle )
											//	Žchoue si unification impossible
											{
											//	On commence par chercher la fin de cha”ne
											
											Chaine	descrVariableLogique =
															this -> SousFormeDeChaine ();
																// AVANT inference!
											VariableLogique
														* curseur = this;
											
											while (curseur -> fLiaisonAutreVariable != NULL)
												curseur = curseur -> fLiaisonAutreVariable;
												

											//	On essaye maintenant d'unifier
											
											if (curseur -> fValeur == gLiaisonVariableLogiqueLIBRE)
												//	le receveur est une variable libre,
												// on lie cette VariableLogique a uneValeur
												{
												curseur -> fValeur = uneValeur;
												if (montrerLaLaisonEventuelle)
													std::cout <<
														MiseEnForme (
															gLANGUE_SupportCPlusPlus ->
																FormatLiaisonVariableLogique (),
															descrVariableLogique,
															uneValeur ->
																SousFormeDeChaine ()
															) << std::endl;

												return true;
												}

											else
												{
												//	le receveur est une variable liŽe, 
												// succes si la valeur de liaison est uneValeur
												bool  res = curseur -> fValeur == uneValeur;

												if (res && montrerLaLaisonEventuelle)
													std::cout <<
														MiseEnForme (
															 gLANGUE_SupportCPlusPlus ->
																FormatVariableLogiqueDejaLiee (),
															descrVariableLogique,
															uneValeur ->
																SousFormeDeChaine ()
															) << std::endl;

												return res;
												}
											}	//	VariableLogique :: UnifierValeur


	TClass							* ValeurDeLiaison ()
											{
											//	On commence par chercher la fin de cha”ne
											
											VariableLogique
														* curseur = this;
											
											while (curseur -> fLiaisonAutreVariable != NULL)
												curseur = curseur -> fLiaisonAutreVariable;

											return curseur -> fValeur;
											}


	bool								EstLibre ()
											{
											return
												ValeurDeLiaison ()
													==
												gLiaisonVariableLogiqueLIBRE;
											}

private:

	VariableLogique				* fLiaisonAutreVariable;
											//	NULL indique la fin de la cha”ne
	
	TClass							* fValeur;
	
	Chaine							fDescrVariableLogique;

	int								fIDVariableLogique;

	static int						gCompteurVariablesLogiques;
	static TClass					* gLiaisonVariableLogiqueLIBRE;
	
	};	//	VariableLogique


template <class TClass>
int
VariableLogique <TClass> :: gCompteurVariablesLogiques = 0;

template <class TClass>
TClass *
VariableLogique <TClass> :: gLiaisonVariableLogiqueLIBRE = new TClass ();


// -------------------------------------------------------------------------
//	ValeurEntiere
// -------------------------------------------------------------------------

class		ValeurEntiere;
typedef	ValeurEntiere			* ValeurEntierePTR;

class  ValeurEntiere
	{
public:
										ValeurEntiere (int laValeur = 0);

	int									Valeur ();

	Chaine							SousFormeDeChaine ();

private:
	int									fValeur;
	};	// ValeurEntiere


// -------------------------------------------------------------------------
//	VariableLogiqueEntiere
// -------------------------------------------------------------------------

typedef VariableLogique <ValeurEntiere>
										VariableLogiqueEntiere;
typedef VariableLogiqueEntiere
										* VariableLogiqueEntierePTR;


#endif /* __SupportCPlusPlus__ */

