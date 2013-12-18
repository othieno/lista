// =========================================================================
//	SupportCPlusPlus.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "SupportCPlusPlus.h"

#include <cstdarg>	//	pour va_list, va_start, va_end
#include <cstdlib>
#include <cmath>			// for "powl ()"

#include <libgen.h>	// pour basename

#include <cstring>


// -------------------------------------------------------------------------
//	Chaines
// -------------------------------------------------------------------------

CharPTR
AllouerUnTampon (int laTaille)
	{
	CharPTR
				res = new char [laTaille + 1];

	if (res != NULL)
		return res;
	else
		{
		std::cerr <<
			gLANGUE_SupportCPlusPlus ->
				DebordementDuTas ();
		exit (-1);
		}
	}	//	AllouerUnTampon



CharPTR
SauvegarderChaine (CharPTR laChaine)
	{
	//	duplique "laChaine" dans le tas

	CharPTR
				res = strdup (laChaine);;
	
	if (res == NULL)
		SortieSurErreur (
			gLANGUE_SupportCPlusPlus ->
				DebordementDuTas (),
			33 );

	return res;
	}	//	SauvegarderChaine


// -------------------------------------------------------------------------
//	La fonction de bas niveau pour MiseEnForme, locale a ce fichier
// -------------------------------------------------------------------------

CharPTR
_mise_en_forme_ (Chaine leFormat, ...)
	{
	/*
	Les valeur du type Chaine (string) etant des objets,
	passer 'laValeur.c_str ()' en argument, le '...' imposant des types
	non objets pourles arguments en nombre variable correspondants
	*/
	
	char			tampon [8192];	// devrait suffire!
	va_list		descripteurDArgumentsOptionnels;

	va_start (descripteurDArgumentsOptionnels, leFormat);

	vsprintf (tampon, leFormat.c_str (), descripteurDArgumentsOptionnels);

	va_end (descripteurDArgumentsOptionnels);

	return SauvegarderChaine (tampon);
	}	// _mise_en_forme_


// -------------------------------------------------------------------------

Chaine
MiseEnForme (
	Chaine	leFormat,
	int		lEntier )
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	double	leFlottant )
	{
	return
		_mise_en_forme_ (
			leFormat,
			leFlottant );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	chaine1,
	Chaine	chaine2 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) chaine1.c_str (),
			(CharPTR) chaine2.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	chaine1,
	Chaine	chaine2,
	Chaine	chaine3 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) chaine1.c_str (),
			(CharPTR) chaine2.c_str (),
			(CharPTR) chaine3.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	chaine1,
	Chaine	chaine2,
	Chaine	chaine3,
	Chaine	chaine4 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) chaine1.c_str (),
			(CharPTR) chaine2.c_str (),
			(CharPTR) chaine3.c_str (),
			(CharPTR) chaine4.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	chaine1,
	Chaine	chaine2,
	Chaine	chaine3,
	Chaine	chaine4,
	Chaine	chaine5 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) chaine1.c_str (),
			(CharPTR) chaine2.c_str (),
			(CharPTR) chaine3.c_str (),
			(CharPTR) chaine4.c_str (),
			(CharPTR) chaine5.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	chaine1,
	Chaine	chaine2,
	Chaine	chaine3,
	int		lEntier )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) chaine1.c_str (),
			(CharPTR) chaine2.c_str (),
			(CharPTR) chaine3.c_str (),
			lEntier );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine,
	int		lEntier1,
	int		lEntier2,
	double	leFlottant)
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine.c_str (),
			lEntier1,
			lEntier2,
			leFlottant );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine,
	int		lEntier)
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine.c_str (),
			lEntier );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine,
	int		lEntier1,
	int		lEntier2)
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine.c_str (),
			lEntier1,
			lEntier2 );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	int		lEntier1,
	int		lEntier2)
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier1,
			lEntier2 );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	long		lEntier)
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	chaine1,
	int		lEntier,
	Chaine	chaine2,
	Chaine	chaine3 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) chaine1.c_str (),
			lEntier,
			(CharPTR) chaine2.c_str (),
			(CharPTR) chaine3.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	int		lEntier1,
	int		lEntier2,
	double	leFlottant)
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier1,
			lEntier2,
			leFlottant );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine1,
	Chaine	laChaine2,
	int		lEntier1,
	int		lEntier2,
	int		lEntier3,
	int		lEntier4)
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine1.c_str (),
			(CharPTR) laChaine2.c_str (),
			lEntier1,
			lEntier2,
			lEntier3,
			lEntier4 );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine1,
	Chaine	laChaine2,
	int		lEntier1,
	int		lEntier2,
	int		lEntier3,
	int		lEntier4,
	int		lEntier5)
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine1.c_str (),
			(CharPTR) laChaine2.c_str (),
			lEntier1,
			lEntier2,
			lEntier3,
			lEntier4,
			lEntier5 );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine,
	int		lEntier1,
	int		lEntier2,
	int		lEntier3,
	int		lEntier4)
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine.c_str (),
			lEntier1,
			lEntier2,
			lEntier3,
			lEntier4 );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine1,
	int		lEntier1,
	int		lEntier2,
	Chaine	laChaine2 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine1.c_str (),
			lEntier1,
			lEntier2,
			(CharPTR) laChaine2.c_str () );
	}

Chaine
MiseEnForme (
	Chaine		leFormat,
	int			lEntier1,
	int			lEntier2,
	char			leCaractere1,
	char			leCaractere2,
	Chaine		laChaine1,
	CharPTR		laChaine2,
	Chaine		laChaine3 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier1,
			lEntier2,
			leCaractere1,
			leCaractere2,
			(CharPTR) laChaine1.c_str (),
			laChaine2,
			(CharPTR) laChaine3.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	int		lEntier,
	Chaine	laChaine1,
	Chaine	laChaine2,
	Chaine	laChaine3 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier,
			(CharPTR) laChaine1.c_str (),
			(CharPTR) laChaine2.c_str (),
			(CharPTR) laChaine3.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	int		lEntier,
	Chaine	laChaine1,
	Chaine	laChaine2 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier,
			(CharPTR) laChaine1.c_str (),
			(CharPTR) laChaine2.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	int		lEntier,
	Chaine	laChaine)
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier,
			(CharPTR) laChaine.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	laChaine1,
	int		lEntier,
	Chaine	laChaine2 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) laChaine1.c_str (),
			lEntier,
			(CharPTR) laChaine2.c_str () );
	}

Chaine
MiseEnForme (
	Chaine	leFormat,
	long		lEntier,
	Chaine	laChaine)
	{
	return
		_mise_en_forme_ (
			leFormat,
			lEntier,
			(CharPTR) laChaine.c_str () );
	}


Chaine
MiseEnForme (
	Chaine	leFormat,
	Chaine	chaine1,
	Chaine	chaine2,
	Chaine	chaine3,
	int		lEntier1,
	int		lEntier2 )
	{
	return
		_mise_en_forme_ (
			leFormat,
			(CharPTR) chaine1.c_str (),
			(CharPTR) chaine2.c_str (),
			(CharPTR) chaine3.c_str (),
			lEntier1,
			lEntier2 );
	}


// -------------------------------------------------------------------------
//	SortieSurErreur
// -------------------------------------------------------------------------

void
SortieSurErreur (
	Chaine	message,
	int		valeurDeSortie )
	{
	std::cerr <<
		std::endl <<
		MiseEnForme (
			gLANGUE_SupportCPlusPlus ->
				FormatSortieSurErreur (),
			message ) <<
		std::endl;
	exit (valeurDeSortie);
	}


// -------------------------------------------------------------------------
//	Fichiers
// -------------------------------------------------------------------------

void
MontrerLeContenuDuFichier (Chaine nomDuFichier)
	{
	Chaine	separation =
					"---------------------------------------------------------------";

	std::cout <<
		std::endl <<
		MiseEnForme (
			gLANGUE_SupportCPlusPlus ->
				FormatContenuDuFichierSource (),
			nomDuFichier ) <<
		separation <<
		std::endl;

	Chaine	commande_montrer_le_contenu =
					MiseEnForme ("cat %s", nomDuFichier);

	system (commande_montrer_le_contenu.c_str ());

	std::cout << separation << std::endl << std::endl;
	}	// MontrerLeContenuDuFichier


Chaine
NomDuFichierSansExtension (Chaine nomDuFichierSource)
	{
	return
		nomDuFichierSource.substr (
			0,
			nomDuFichierSource.rfind (".") );
	}	// NomDuFichierBinaire


bool
EcritureFichierOK (
	std::ofstream		& leFichier,
	Chaine				leNomDuFichier)
	{
	if (! leFichier)
		{			
		std::cerr <<
			MiseEnForme (
				gLANGUE_SupportCPlusPlus ->
					FormatPasPuEcrireSurLeFichier (),
				leNomDuFichier ) <<
				std::endl;
		leFichier.close (); 
		return false;
		}
	else
		return true;
	}	//	EcritureFichierOK


Chaine
DecoderErreurLecture (
	std::ifstream		& leFichier,
	Chaine				leNomDuFichier )
	{
	int		theState = leFichier.rdstate ();

	if (theState & std::ios_base :: eofbit)
		return Chaine ("");	//	ok
	else if (theState & std::ios_base :: failbit)
		return
			MiseEnForme (
				gLANGUE_SupportCPlusPlus ->
					FormatPasPuLireDuFichier (),
				leNomDuFichier,
				"failbit" );
	else if (theState & std::ios_base :: badbit)
		return
			MiseEnForme (
				gLANGUE_SupportCPlusPlus ->
					FormatPasPuLireDuFichier (),
				leNomDuFichier,
				"badbit" );
	else
		return
			MiseEnForme (
				gLANGUE_SupportCPlusPlus ->
					FormatPasPuLireDuFichier (),
				leNomDuFichier,
				"???" );
	}	//	DecoderErreurLecture


// -------------------------------------------------------------------------
//	Lectures
// -------------------------------------------------------------------------

Chaine
FLireChaine (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	Chaine						message )
	{
	const int
				kTAILLE_BUFFER	= 8192;	// devrait suffire
	char		laChaine [kTAILLE_BUFFER];

	if (! message.empty () > 0 )
		{
		std::cout << message << ": ";
		std::cout.flush ();
		}

	int		position = 0;
	char		caractere;

	if (leGenreLectureAuClavier == kLectureIgnorantLePremierCaractere)
		getchar ();	// on ignore le premier caractere

	while (1)
		{
		caractere = getchar ();
		if (caractere == '\n')
			break;
		if (position < kTAILLE_BUFFER)
			laChaine [position ++] = caractere;
		else
			SortieSurErreur (
				MiseEnForme (
					gLANGUE_SupportCPlusPlus ->
						FormatDebordementDuTamponDeFLireChaine(),
					kTAILLE_BUFFER ),
				1 );
		} // while
	laChaine [position ++] = '\0';
		
	return SauvegarderChaine (laChaine);
	}	// FLireChaine


CharPTR
FLireChaine (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	CharPTR						message )
	{
	const int
				kTAILLE_BUFFER	= 8192;	// devrait suffire
	char		laChaine [kTAILLE_BUFFER];

	if (strlen (message) > 0 )
		{
		std::cout << message << ": ";
		std::cout.flush ();
		}

	int		position = 0;
	char		caractere;

	if (leGenreLectureAuClavier == kLectureIgnorantLePremierCaractere)
		getchar ();	// on ignore le premier caractere

	while (1)
		{
		caractere = getchar ();
		if (caractere == '\n')
			break;
		if (position < kTAILLE_BUFFER)
			laChaine [position ++] = caractere;
		else
			SortieSurErreur (
				MiseEnForme (
					gLANGUE_SupportCPlusPlus ->
						FormatDebordementDuTamponDeFLireChaine (),
					kTAILLE_BUFFER ),
				1 );
		} // while
	laChaine [position ++] = '\0';
		
	return SauvegarderChaine (laChaine);
	}	// FLireChaine


// -------------------------------------------------------------------------

long
FLireEntier (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	Chaine						message )
	{
	return
		atoi (FLireChaine (leGenreLectureAuClavier, message).c_str ());
	}

double
FLireFlottant (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	Chaine						message )
	{
	return
		atof (FLireChaine (leGenreLectureAuClavier, message).c_str ());
	}

bool
FLireBooleen (
	
	GenreLectureAuClavier	leGenreLectureAuClavier,
	Chaine						message,
	Chaine						chaineVrai )
	{
	Chaine	invite	=
					MiseEnForme (
						"%s (%s/_)",
						message,
						chaineVrai );
	Chaine	donnee	=
					FLireChaine (leGenreLectureAuClavier, invite);
	
	return donnee == chaineVrai;
	}

char
FLireCaractere (
	GenreLectureAuClavier	leGenreLectureAuClavier,
	Chaine						message )
	{ return FLireChaine (leGenreLectureAuClavier, message) [0]; }


// -------------------------------------------------------------------------
//	Mise en page
// -------------------------------------------------------------------------

void
Indenter (int lIndentation)
	{
	while (lIndentation -- > 0)
		std::cout << '\t';
	}


// -------------------------------------------------------------------------
//	Variante maison de "powl ()"...
// -------------------------------------------------------------------------

long
Puissance (long base, long exposant)
	{
	long	res = 1;
	
	do
		{
		while (exposant % 2 == 0)
			{
			exposant = exposant / 2;
			base = base * base;
			} // while
		exposant = exposant - 1;
		res = base * res;
		}
	while (exposant != 0);
	
	return res;
	} // Puissance


// -------------------------------------------------------------------------
//	Chaines de caracteres
// -------------------------------------------------------------------------

Chaine
FConcatChaines (
	Chaine	chaine1,
	Chaine	chaine2 )
	{
	return chaine1 + chaine2;
	}


CharPTR
FConcatChaines (
	CharPTR	chaine1,
	CharPTR	chaine2 )
	{
	int		longueurChaine1	= strlen (chaine1),
				longueurChaine2	= strlen (chaine2);

	CharPTR
				res =
					AllouerUnTampon (longueurChaine1 + longueurChaine2 + 1);
	
	strncpy (res, chaine1, longueurChaine1);
	strcpy (res + longueurChaine1, chaine2);
	
//	std::cout << "res = " << res << std::endl << std::endl;

	return res;
	}	// FConcatChaines


// -------------------------------------------------------------------------

Chaine
FRepliquerChaine (
	Chaine	laChaine,
	int		nbOccurrences )
	{
	Chaine	res = Chaine ("");

	for (int i = 1; i <= nbOccurrences; i ++)
		res += laChaine;
		
	return res;
	}	// FRepliquerChaine

// -------------------------------------------------------------------------

CharPTR
FRepliquerChaine (
	CharPTR		chaine,
	int			nbOccurrences )
	{
	CharPTR	res = CharPTR ("");
	
	for (int i = 1; i <= nbOccurrences; i ++)
		{
		CharPTR
					inter = FConcatChaines (res, chaine);
		
		if (strlen (res) != 0)
			delete [] res;
		res = inter;
		}	// for
		
	return res;
	}	// FRepliquerChaine


// -------------------------------------------------------------------------

Chaine
FRemplacerChaine (
	Chaine	laChaine,
	Chaine	fragment,
	Chaine	succedane )
	{
	return
		laChaine.replace (
			laChaine.find (fragment),
			fragment.length (),
			succedane );
	}

CharPTR
FRemplacerChaine (
	CharPTR	chaine,
	CharPTR	fragment,
	CharPTR	succedane )
	{
	CharPTR	res = chaine;
	CharPTR	posFragment	= strstr (chaine, fragment);
	
	if (posFragment != NULL)
		{
		int		longueurPrefixe
						= posFragment - chaine;
		CharPTR	posSuffixe =
						posFragment + strlen (fragment);
		int		longueurSuffixe =
						(chaine + strlen (chaine)) - posSuffixe;
		int		longueurSuccedane	=
						strlen (succedane);
	
		res = AllouerUnTampon (
			longueurPrefixe + longueurSuccedane + longueurSuffixe + 1 );
		
		strncpy (res, chaine, longueurPrefixe);
		strncpy (res + longueurPrefixe, succedane, longueurSuccedane);
		strncpy (
			res + longueurPrefixe + longueurSuccedane,
			posSuffixe,
			longueurSuffixe + 1 );
		}	// if
		
	return res;
	}	// FRemplacerChaine

// -------------------------------------------------------------------------

Chaine
FFormaterFlottant (
	double	leFlottant,
	int		tailleDuChamp,
	int		taillePartieDecimale )
	{
	return
		_mise_en_forme_ (
			"%*.*f",
			tailleDuChamp,
			taillePartieDecimale,
			leFlottant );
	}


// -------------------------------------------------------------------------
//	Hasard
// -------------------------------------------------------------------------

double
FHasard ()
//	{ return random () / (powl (2, 31) - 1); }
	{
	const long						// constantes
		a1 = 4193,
		c1 = 1111111,
		a2 = 5659,
		c2 = 1111111;

	static long						//	variables statiques
		germe1 = 123457,			//	valeur initiale
		germe2 = 123455;			//	valeur initiale

	long								//	variables automatiques													
		modulo1 = Puissance (2, 16),
		modulo2 = Puissance (3, 9);

	double	res;							

	germe1 = (germe1 * a1 + c1) % modulo1;
	germe2 = (germe2 * a2 + c2) % modulo2;

	res = (double) germe1 / modulo1 - (double) germe2 / modulo2;	// casts
	if (res < 0.0)
		res = res + 1.0;

	return res;
	}	//	FHasard


// -------------------------------------------------------------------------
//	ValeurEntiere
// -------------------------------------------------------------------------

ValeurEntiere :: ValeurEntiere (int laValeur)
	{ fValeur = laValeur; }

int
ValeurEntiere :: Valeur ()
	{ return fValeur; }

Chaine
ValeurEntiere :: SousFormeDeChaine ()
	{
	return _mise_en_forme_ ("%d", fValeur);
	}
