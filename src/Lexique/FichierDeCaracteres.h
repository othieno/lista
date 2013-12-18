// =========================================================================
//	FichierDeCaracteres.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __FichierDeCaracteres__
#define __FichierDeCaracteres__

#include "Langues.h"


// -------------------------------------------------------------------------
//	FichierDeCaracteres
// -------------------------------------------------------------------------

class FichierDeCaracteres
	{
public:
										FichierDeCaracteres (Chaine nomDuFichier);
											
	virtual							~ FichierDeCaracteres ();

	void								Ouvrir ();
	void								Fermer ();
	long								Taille ();
	
	void								Rembobiner ();

	void								LireDansTampon (
											CharPTR			& leTampon,
											long				& longueurDuTampon,
											char				laSentinelle );

	virtual void					ErreurFichier (Chaine message);


private:

	int								fDescripteur;		// vue "C", et non "C++"
	Chaine							fNomDuFichier;
	
	};	//	FichierDeCaracteres


#endif /* __FichierDeCaracteres__ */
