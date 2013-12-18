// =========================================================================
//	AnalyseurLexicalLista.cc
//  J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "AnalyseurLexicalLista.h"

#include "Langues.h"

#include <iostream>
#include <cstdlib>	//	pour atof


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista
// --------------------------------------------------------------------------

AnalyseurLexicalLista :: AnalyseurLexicalLista (
	ProducteurDeCaracteres	* leProducteur,
	OptionsLexiquePTR			lesOptionsLexique )
	: fProducteurDeCaracteres (leProducteur)
	{
	fOptionsLexique = lesOptionsLexique;

	fCaractereCourant = '$';
	fNumLigneCourante = 1;

	fDebutLigneCourante = 0;
	fDebutLigneCourante_1 = 0;
	fDebutLigneCourante_2 = 0;

	fTailleTamponAuxiliaire = 1024;
		// pourra croitre si necessaire
	fTamponAuxiliaire =
		AllouerUnTampon (fTailleTamponAuxiliaire);

	fPremierTerminalDejaAccepte = false;

	fNombre = -19.22;

	fLongueurIdent = 128;
	fIdent =
		AllouerUnTampon (fLongueurIdent);
		// pourra croitre si necessaire

	fChaine = "??? chaine ???";

	fSourceCorrectLexicalement = true;
	}	// AnalyseurLexicalLista :: AnalyseurLexicalLista


AnalyseurLexicalLista :: ~ AnalyseurLexicalLista ()
	{}


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: DescriptionPositionCourante
// --------------------------------------------------------------------------

Chaine
AnalyseurLexicalLista :: DescriptionPositionCourante ()
	{
	int		positionCourante = PositionDuCaractere ();
	int		nombreDeCaracteresAAfficher	=
					positionCourante - fDebutLigneCourante_2 + 1;

	if (nombreDeCaracteresAAfficher > fTailleTamponAuxiliaire)
		{
		//	 on etend fTamponAuxiliaire

		delete [] fTamponAuxiliaire;

		fTailleTamponAuxiliaire = nombreDeCaracteresAAfficher;
		fTamponAuxiliaire =
			AllouerUnTampon (fTailleTamponAuxiliaire);
		}	// if

	fProducteurDeCaracteres ->
		CopierLaChaine (
			fDebutLigneCourante_2,
			nombreDeCaracteresAAfficher,
			fTamponAuxiliaire );

	Chaine	separateur =
					"-----------------------------------------------------";

	if (fOptionsLexique -> ModeVerbeux ())
		return
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatPositionLexicaleCourante (),
				fNumLigneCourante,
				positionCourante - fDebutLigneCourante + 1,
				fCaractereCourant,
				fCaractereCourant,
				separateur,
				fTamponAuxiliaire,
				separateur );
	else
		return
			MiseEnForme (
				"[L%3d:C%3d]",
				fNumLigneCourante,
				positionCourante - fDebutLigneCourante + 1 );
	}	// AnalyseurLexicalLista :: DescriptionPositionCourante


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: DescriptionTerminalCourant
// --------------------------------------------------------------------------

Chaine
AnalyseurLexicalLista :: DescriptionTerminalCourant ()
	{
	return
		fPremierTerminalDejaAccepte
			?	TerminalSousFormeTextuelle (fTerminalPCourant)
			:	gLANGUE_Lexique ->
					AucunTerminalAccepteEncore ();
	}


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: ErreurLexicale
// --------------------------------------------------------------------------

void
AnalyseurLexicalLista :: ErreurLexicale (Chaine leFormat)
	{
	Chaine	leMessage	= MiseEnForme (leFormat, fCaractereCourant);

	if (fOptionsLexique -> ModeVerbeux ())
		std::cout <<
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatErreurLexicale (),
				leMessage,
				DescriptionTerminalCourant (),
				DescriptionPositionCourante () ) <<
			std::endl <<
			std::endl;
	else
		std::cout <<
			MiseEnForme (
				gLANGUE_Lexique ->
					FormatErreurLexicaleAllege (),
				DescriptionPositionCourante (),
				leMessage,
				DescriptionTerminalCourant () ) <<
			std::endl <<
			std::endl;

	fSourceCorrectLexicalement = false;

	if (fOptionsLexique -> RenoncerSurErreurLexicale ())
		SortieSurErreur (leMessage, 1);
	}	//	AnalyseurLexicalLista :: ErreurLexicale


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: TerminalSousFormeTextuelle
// --------------------------------------------------------------------------

Chaine
AnalyseurLexicalLista :: TerminalSousFormeTextuelle (TerminalP leTerminalP)
	{
	switch (leTerminalP)
		{
		case t_NOMBRE:
			return
				MiseEnForme (
					"%-10s %*.*f",
					gLANGUE_Lexique ->
						TerminalFlottant (),
					TailleChampEcritureNombres (),
					NombreDecimalesEcritureNombres (),
					DernierNombreAccepte () );
		case t_CHAINE:
			return
				MiseEnForme (
					"%-10s %s",
					gLANGUE_Lexique ->
						TerminalChaine (),
					DerniereChaineAcceptee () );
		case t_IDENT:
			return MiseEnForme (
				"%-10s %s",
				gLANGUE_Lexique ->
					TerminalIdent (),
				DernierIdentAccepte () );

		case t_PAR_GAUCHE:
			return "           (" ;
		case t_PAR_DROITE:
			return "           )" ;
		case t_EGALE:
			return "           =" ;
		case t_VIRGULE:
			return "           ," ;
		case t_PLUS:
			return "           +" ;
		case t_MOINS:
			return "           -" ;
		case t_FOIS:
			return "           *" ;
		case t_DIVISE:
			return "           /" ;
		case t_CONCAT:
			return "           !!" ;
		case t_POINT_VIRGULE:
			return "           ;" ;
		case t_INTERROGE:
			return "           ?" ;
		case t_CROCHET_GAUCHE:
			return "           [" ;
		case t_CROCHET_DROIT:
			return "           ]" ;

		case t_FIN:
			return gLANGUE_Lexique ->
				PseudoTerminalFin ();

		default:
			return
				MiseEnForme (
					gLANGUE_Lexique ->
						FormatTerminalInconnu (),
					leTerminalP );
			break;
		}	//	switch
	}	//	AnalyseurLexicalLista :: TerminalSousFormeTextuelle


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: CompterFinDeLigne
// --------------------------------------------------------------------------

void
AnalyseurLexicalLista :: CompterFinDeLigne ()
	{
	fNumLigneCourante ++;

	fDebutLigneCourante_2 = fDebutLigneCourante_1;
	fDebutLigneCourante_1 = fDebutLigneCourante;
	fDebutLigneCourante   = PositionDuCaractere ();
	}


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: EchoDesCaracteresAcceptes
// --------------------------------------------------------------------------

void
AnalyseurLexicalLista :: EchoDesCaracteresAcceptes ()
	{
	int		nombreDeCaracteresAAfficher =
					PositionDuCaractere () - fPositionDebutDuTerminal + 1;

	if (nombreDeCaracteresAAfficher > fTailleTamponAuxiliaire)
		{
		delete fTamponAuxiliaire;

		fTailleTamponAuxiliaire = nombreDeCaracteresAAfficher;
		fTamponAuxiliaire =
			AllouerUnTampon (fTailleTamponAuxiliaire);
		}	// if

	fProducteurDeCaracteres ->
		CopierLaChaine (
			fPositionDebutDuTerminal,
			nombreDeCaracteresAAfficher,
			fTamponAuxiliaire );

	std::cout << fTamponAuxiliaire;
	}	// AnalyseurLexicalLista :: EchoDesCaracteresAcceptes


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: AccepterUnTerminal
// --------------------------------------------------------------------------

TerminalP
AnalyseurLexicalLista :: AccepterUnTerminal ()
	//	l'analyseur lexical proprement dit
	{
	bool	traduire	= fOptionsLexique -> Traduire ();

	//	Le premier caractère à analyser est déjà disponible
	Avancer ();

	fPositionDebutDuTerminal = PositionDuCaractere ();


DEBUT:	//	pour accélérer la consommation des séparateurs

	switch (fCaractereCourant)
		{
		case ' ' :
		case '\t' :
		case '\xD' :													//	SEPARATEURS
			if (traduire)
				std::cout << fCaractereCourant;
			Avancer ();
			fPositionDebutDuTerminal = PositionDuCaractere ();
			goto DEBUT;		//	on consomme tous ces séparateurs
			break;

		case '/':														// COMMENTAIRE
			Avancer ();
			switch (fCaractereCourant)
				{
				case '/':
					// commentaire jusqu'à la fin de ligne
					do
						{
						Avancer ();
						}
					while (fCaractereCourant != '\n');

					Reculer ();
					if (traduire)
						EchoDesCaracteresAcceptes ();
					Avancer ();

					fPositionDebutDuTerminal = PositionDuCaractere ();
					goto DEBUT;
						// on consomme ce séparateur
						// et on repart chercher le prochain terminal

				case '*':
					// commentaire parenthésé
					Avancer ();
					do
						{
						while (fCaractereCourant != '*')
							{
							if (fCaractereCourant == '\n')
								CompterFinDeLigne ();
							Avancer ();
							}	// while
						Avancer ();
						}
					while (fCaractereCourant != '/');

					if (traduire)
						EchoDesCaracteresAcceptes ();
					Avancer ();

					fPositionDebutDuTerminal = PositionDuCaractere ();
					goto DEBUT;
						// on consomme ce séparateur
						// et on repart chercher le prochain terminal

				default:
					Reculer ();
					fTerminalPCourant = t_DIVISE;
				} // switch
			break;

		case '\0' :												// necessaire pour les flots
			fTerminalPCourant = t_FIN;
			break;

		case '\n' :
			if (traduire)
				std::cout << fCaractereCourant;
			Avancer ();
			CompterFinDeLigne ();

			fPositionDebutDuTerminal = PositionDuCaractere ();
			goto DEBUT;		//	on consomme tous ces séparateurs
			break;

		case SENTINELLE:
			if (fProducteurDeCaracteres -> FinAtteinte ())
				fTerminalPCourant = t_FIN;
			else
				fTerminalPCourant = t_POINT_VIRGULE;
			break;

		case '(' :
			fTerminalPCourant = t_PAR_GAUCHE;
			break;
		case ')' :
			fTerminalPCourant = t_PAR_DROITE;
			break;
		case '=' :
			fTerminalPCourant = t_EGALE;
			break;
		case ',' :
			fTerminalPCourant = t_VIRGULE;
			break;
		case '+' :
			fTerminalPCourant = t_PLUS;
			break;
		case '-' :
			fTerminalPCourant = t_MOINS;
			break;
		case '*' :
			fTerminalPCourant = t_FOIS;
			break;
		case '[':
			fTerminalPCourant = t_CROCHET_GAUCHE;
			break;
		case ']':
			fTerminalPCourant = t_CROCHET_DROIT;
			break;
		case '!':
			{
			Avancer ();
			if (fCaractereCourant == '!')
				{
				fTerminalPCourant = t_CONCAT;
				}
			else
				{
				ErreurLexicale (
					gLANGUE_Lexique ->
						FormatCaractereIllegal () );
				if (traduire)
					std::cout << fCaractereCourant;
				Avancer ();
				fPositionDebutDuTerminal = PositionDuCaractere ();
				goto DEBUT;
				}
			}
			break;
		case '?' :
			fTerminalPCourant = t_INTERROGE;
			break;

		case '"':														//	CHAINE
			if (traduire)
				std::cout << fCaractereCourant;

			fTerminalPCourant = AccepterUneChaine ();
			break;

		default:

			if (isalpha (fCaractereCourant))						//	IDENT
				fTerminalPCourant = AccepterUnIdent ();

			else if (isdigit (fCaractereCourant))				//	NOMBRE
				fTerminalPCourant = AccepterUnNombre ();

			else															//	CARACTERE ILLEGAL
				{
				ErreurLexicale (
					gLANGUE_Lexique ->
						FormatCaractereIllegal () );
				if (traduire)
					std::cout << fCaractereCourant;
				Avancer ();
				fPositionDebutDuTerminal = PositionDuCaractere ();
				goto DEBUT;
				}

		}	//	switch (fCaractereCourant)

	if (fOptionsLexique -> MontrerLesTerminaux ())
		std::cout <<
			"\t" << TerminalSousFormeTextuelle (fTerminalPCourant) << std::endl;

	if (traduire)
		{
		switch (fTerminalPCourant)
			{
			case t_IDENT :
			case t_FIN :
				break;
			default :
				EchoDesCaracteresAcceptes ();
			}	// switch
		}	// if

	if (! fPremierTerminalDejaAccepte)
		fPremierTerminalDejaAccepte = true;

	return fTerminalPCourant;

	}	//	AnalyseurLexicalLista :: AccepterUnTerminal


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: AccepterUnIdent
// --------------------------------------------------------------------------

TerminalP
AnalyseurLexicalLista :: AccepterUnIdent ()
	{
	do		//	on consomme tous les lettres et chiffres
		{
		Avancer ();
		}
	while (isalnum (fCaractereCourant) || fCaractereCourant == '_');

	Reculer ();

	int		longueurIdent =
					PositionDuCaractere () - fPositionDebutDuTerminal + 1;

	if (longueurIdent > fLongueurIdent)
		{
		delete fIdent;
		fIdent = AllouerUnTampon (longueurIdent);
		fLongueurIdent =longueurIdent;
		}

	fProducteurDeCaracteres ->
		CopierLaChaine (
			fPositionDebutDuTerminal,
			longueurIdent,
			fIdent );

	return t_IDENT;
	}	// AccepterUnIdent


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: AccepterUnNombre
// --------------------------------------------------------------------------

TerminalP
AnalyseurLexicalLista :: AccepterUnNombre ()
	{
	do		//	on consomme tous les chiffres
		{
		Avancer ();
		}
	while (isdigit (fCaractereCourant));

	switch (fCaractereCourant)
		{
		case '.' :
			Avancer ();

			if (isdigit (fCaractereCourant))
				{
				do		//	on consomme tous les chiffres
					{
					Avancer ();
					}
				while (isdigit (fCaractereCourant));

				if (
					(fCaractereCourant == 'E') || (fCaractereCourant == 'e') )
					AccepterUnExposant ();
				}

			else
				ErreurLexicale (
					gLANGUE_Lexique ->
						FormatChiffreAttendu () );
			break;

		case 'E' :
		case 'e' :
			AccepterUnExposant ();
			break;

		default:
			;	//	RIEN !
		}	//	switch

	Reculer ();

	int		longueurNombre =
					PositionDuCaractere () - fPositionDebutDuTerminal + 1;

	fProducteurDeCaracteres ->
		CopierLaChaine (
			fPositionDebutDuTerminal,
			longueurNombre,
			fIdent );

	fNombre = atof (fIdent);

	return t_NOMBRE;
	}	//	AnalyseurLexicalLista :: AccepterUnNombre


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: AccepterUnExposant
// --------------------------------------------------------------------------

void
AnalyseurLexicalLista :: AccepterUnExposant ()
	{
	Avancer ();

	if (
		(fCaractereCourant == '+') || (fCaractereCourant == '-')
		)
		{
		Avancer ();

		if (isdigit (fCaractereCourant))
			{
			do		//	on consomme tous les chiffres
				{
				Avancer ();
				}
			while (isdigit (fCaractereCourant));
			}

		else
			ErreurLexicale (
				gLANGUE_Lexique ->
					FormatChiffreAttendu () );
		}

	else if (isdigit (fCaractereCourant))
		{
		do		//	consomme tous les chiffres
			{
			Avancer ();
			}
		while (isdigit (fCaractereCourant));
		}

	else
		ErreurLexicale (
			gLANGUE_Lexique ->
				FormatChiffreOuSigneAttendu () );

	}	//	AnalyseurLexicalLista :: AccepterUnExposant


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: AccepterUneChaine
// --------------------------------------------------------------------------

TerminalP
AnalyseurLexicalLista :: AccepterUneChaine ()
	{
	bool		finChaineAtteinte = false;

	Avancer ();	// consomme le '"'

	fPositionDebutDuTerminal = PositionDuCaractere ();

	int		positionDebutDuTroncon =
					fPositionDebutDuTerminal;

	fChaine = "";

	while (true)														//		boucle infinie
		{
		switch (fCaractereCourant)
			{
			case '"':
				finChaineAtteinte = true;
				break;

			case '\\':
				{
				//	on appond le tronçon courant a fChaine

				AppondreLeFragmentALaChaine (
					fProducteurDeCaracteres ->
						ExtraireLaChaine (
							positionDebutDuTroncon,
							PositionDuCaractere () - positionDebutDuTroncon ));

				Avancer ();

				switch (fCaractereCourant)
					{
					case '"':
						AppondreLeFragmentALaChaine ("\"");
						break;
					case '\\':
						AppondreLeFragmentALaChaine ("\\");
						break;
					case 'n':
						AppondreLeFragmentALaChaine ("\n");
						break;
					case 't':
						AppondreLeFragmentALaChaine ("\t");
						break;
					default:
						ErreurLexicale (
							gLANGUE_Lexique ->
								FormatCaractereDeChaineSpecialAttendu () );
						Reculer ();
					} //			switch

				positionDebutDuTroncon = PositionDuCaractere () + 1;
				}
				break;

			case SENTINELLE:
				ErreurLexicale (
					gLANGUE_Lexique ->
						FormatCaractereDeFinDeChaineAttendu () );
				if (fProducteurDeCaracteres -> FinAtteinte ())
					return t_FIN;									//		correction de l'erreur
				else
					return t_CHAINE;								//		correction de l'erreur
				break;

			case '\n':
				CompterFinDeLigne ();
				break;

			default:
				;	//		RIEN !
			} //	switch

		if (finChaineAtteinte)
			break;

		Avancer ();
		}	//		while

	//	on appond le dernier tronçon a fChaine

	AppondreLeFragmentALaChaine (
		fProducteurDeCaracteres ->
			ExtraireLaChaine (
				positionDebutDuTroncon,
				PositionDuCaractere () - positionDebutDuTroncon ));

	return t_CHAINE;
	}	// AnalyseurLexicalLista :: AccepterUneChaine


// --------------------------------------------------------------------------
//	AnalyseurLexicalLista :: Analyser
// --------------------------------------------------------------------------

void
AnalyseurLexicalLista :: Analyser ()
	{
	do
		{
		AccepterUnTerminal ();
		}
	while (fTerminalPCourant != t_FIN);

	if (fSourceCorrectLexicalement)
		std::cout <<
			gLANGUE_Lexique ->
				CodeLexicalementCorrect () <<
			std::endl;
	else
		std::cout <<
			gLANGUE_Lexique ->
				CodeLexicalementIncorrect () <<
			std::endl;
	}	// AnalyseurLexicalLista :: Analyser


bool
AnalyseurLexicalLista :: SourceCorrectLexicalement ()
	{ return fSourceCorrectLexicalement; }
