// =========================================================================
// ValeurLista.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __ValeurLista__
#define __ValeurLista__


#include "DescriptionDesTypes.h"


// ------------------------------------------------------------------------
// ValeurLista
// ------------------------------------------------------------------------

class ValeurLista
   {
public:
                              ValeurLista ();

                              ValeurLista (Nombre leNombre);
                              ValeurLista (bool leBooleen);
                              ValeurLista (Chaine laChaine);
                              ValeurLista (Liste laListe);


   //
   // methodes de TEST DYNAMIQUE DE TYPE
   //

   Nombre                     CommeNombre ();
   bool                       CommeBooleen ();
   Chaine                     CommeChaine ();
   Liste                      CommeListe ();



   void                       Ecrire (int lIndentation);

   Nombre                     fNombre;
   bool                       fBooleen;
   Chaine                     fChaine;
   Liste                      fListe;


   TypePTR                    Type ();

private:

   TypePTR                    fType;   // type de la valeur, immutable

   }; // ValeurLista


#endif /* __ValeurLista__ */
