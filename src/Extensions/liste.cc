/// OTHIENO Jeremy.
#include "Types.h"
#include <sstream>					/* Pour la classe stringstream. */
#include "SupportCPlusPlus.h"		/* Pour 'MiseEnForme'. Types.h est deja inclut par ce fichier. */
#include "LanguesPredefinis.h"	/* Pour la variable globale gLANGUE_Predefinis */


// Constructeur par defaut.
Liste::Liste(){}


Liste::Liste( std::list<Element> listeDElements )
{
	fListe = listeDElements;
}


Liste::Liste( ListePTR liste )
{
	*this = *liste;
}


// Il faut gerer la memoire qui a ete allouee dynamiquement.
// TODO: Completer
Liste::~Liste()
{
/**
	for (IterateurListe it = fListe.begin(); it != fListe.end(); it++)
	{
		Element element = *it;
		if (element.fType == kTypeChaine)
			delete element.fChaine;
		else if (element.fType == kTypeListe)
			delete element.fListe;
	}
**/
}

// -------------------------------------------------------------------------------------------------

IterateurListe
Liste::begin()
{
	return fListe.begin();
}


IterateurListe
Liste::end()
{
	return fListe.end();
}

// -------------------------------------------------------------------------------------------------

Element
Liste::car()
{
	return fListe.front();
}


Liste
Liste::cdr()
{
	// Creer une copie de la liste.
	std::list<Element> copie = fListe;

	// Supprimer le premier element.
	copie.pop_front();

	// Retourner la nouvelle liste.
	return Liste( copie );
}

// -------------------------------------------------------------------------------------------------

void
Liste::cons( Element& lElement )
{
	fListe.push_front( lElement );
}

void
Liste::cons( Nombre& leNombre )
{
	Element lElement;

	lElement.fNombre	= leNombre;
	lElement.fType		= kTypeNombre;

	fListe.push_front( lElement );
}

void
Liste::cons( Chaine& laChaine )
{
	Element lElement;
	lElement.fChaine	= new Chaine( laChaine );
	lElement.fType		= kTypeChaine;

	fListe.push_front( lElement );
}


void
Liste::cons( bool& leBooleen )
{
	Element lElement;

	lElement.fBooleen	= leBooleen;
	lElement.fType		= kTypeBooleen;

	fListe.push_front( lElement );
}


void
Liste::cons( Liste& laListe )
{
	Element lElement;

	lElement.fListe		= new Liste();
	*(lElement.fListe)	= laListe;
	lElement.fType			= kTypeListe;

	fListe.push_front( lElement );
}


void
Liste::cons( ListePTR laListe )
{
	Element lElement;

	lElement.fListe	= laListe;
	lElement.fType		= kTypeListe;

	fListe.push_front( lElement );
}

// -------------------------------------------------------------------------------------------------

void
Liste::append( Element& lElement )
{
	fListe.push_back( lElement );
}

void
Liste::append( Nombre &leNombre )
{
	Element lElement;

	lElement.fNombre	= leNombre;
	lElement.fType		= kTypeNombre;

	fListe.push_back( lElement );
}

void
Liste::append( Chaine &laChaine )
{
	Element lElement;

	lElement.fChaine	= new Chaine( laChaine );
	lElement.fType		= kTypeChaine;

	fListe.push_back( lElement );

	return;

}

void
Liste::append( bool &leBooleen )
{
	Element lElement;
	lElement.fBooleen	= leBooleen;
	lElement.fType		= kTypeBooleen;

	fListe.push_back( lElement );
}

void
Liste::append( Liste &laListe )
{
	Element lElement;
	lElement.fListe		= new Liste();
	*(lElement.fListe)	= laListe;
	lElement.fType			= kTypeListe;

	fListe.push_back( lElement );
}

void
Liste::append( ListePTR laListe )
{
	Element lElement;
	lElement.fListe	= laListe;
	lElement.fType		= kTypeListe;

	//FIXME Why is this commented out?
	//fListe.push_back( lElement );
}

// -------------------------------------------------------------------------------------------------

void
Liste::concat( Liste& laListe )
{
	IterateurListe it = laListe.begin();

	for (; it != laListe.end(); it ++)
	{
		Element lElement = *it;
		fListe.push_back( lElement );
	}
}

void
Liste::concat( ListePTR laListe )
{
	IterateurListe it = laListe -> begin();

	for (; it != laListe -> end(); it ++)
	{
		Element lElement = *it;
		fListe.push_back( lElement );
	}
}

// -------------------------------------------------------------------------------------------------

Nombre
Liste::taille()
{
	return Nombre( fListe.size() );
}

// -------------------------------------------------------------------------------------------------

// Une liste sous sa forme textuelle.
Chaine
Liste::str()
{
	std::stringstream		flot;
	IterateurListe			it = fListe.begin();

	// Ecrire un crochet gauche sur le flot.
	flot << "[";

	if (it != fListe.end())
	{
		// Traverser la liste en ecrivant chacun des elements dans le flot.
		while ( 1 )
		{
			switch (it -> fType)
			{
				case kTypeNombre:
				{
					flot << MiseEnForme( "%f", it -> fNombre );
					break;
				}
				case kTypeBooleen:
				{
					flot << MiseEnForme(	"%s",
												it -> fBooleen ?	gLANGUE_Predefinis -> Vrai() :
																		gLANGUE_Predefinis -> Faux()
												);
					break;
				}
				case kTypeChaine:
				{
					flot << "\"" << *(it -> fChaine) << "\"";
					break;
				}
				case kTypeListe:
				{
					flot << it->fListe->str();
					break;
				}
				default:
					flot << "???";
			}

			if (++it != fListe.end())
				flot << ", ";
			else
				break;
		}
	}
	// Ecrire le crochet droit et retourner le flot sous la forme d'une chaine de caracteres.
	flot << "]";
	return flot.str();
}
