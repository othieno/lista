// =========================================================================
// Types.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __Types__
#define __Types__

#include <string>
#include <list>


// -------------------------------------------------------------------------
// Conventions
// -------------------------------------------------------------------------

/*

Les principes suivants ont guide le choix des identificateurs:

   - k* pour les constantes, sauf les terminaux
   - f* pour les champs (field) des classes
   - g* pour les variables globales
   - p* pour les variables privees dediees a un usage particulier,
     en general des variables de classes

   - *PTR pour les types pointeurs
   - *REF pour les types pointeurs sur des pointeurs
   - *PFM pour les types pointeurs sur des fonctions membres de classes

   - gLANGUE* et gOPTIONS* pour mettre en evidence l'emploi de ces variables

*/


// -------------------------------------------------------------------------
// Nombre
// -------------------------------------------------------------------------

typedef  double            Nombre;


// -------------------------------------------------------------------------
// Chaines
// -------------------------------------------------------------------------

typedef  std::string       Chaine;
                              // pour le haut niveau,
                              // i.e. analyse semantique, messages d'erreur
                              // et gestion des langues

typedef  char *            CharPTR;
                              // pour le bas niveau,
                              // i.e. analyse lexicale et machine Pilum


// -------------------------------------------------------------------------
// Liste de nombres
// -------------------------------------------------------------------------

class Liste;
typedef Liste *            ListePTR;
typedef Chaine *           ChainePTR;


// Les types d'elements de la liste.
enum TypeElement
{
   kTypeNombre,            kTypeBooleen,
   kTypeChaine,            kTypeListe
};

// Un element de la liste.
typedef struct ElementDeListe
{
   union
   {
      Nombre               fNombre;
      bool                 fBooleen;
      ChainePTR            fChaine;
      ListePTR             fListe;
   };
   TypeElement             fType;
} Element;

// L'iterateur de la liste.
typedef std::list<Element>::iterator
                           IterateurListe;

class Liste
{
   private:
      std::list<Element>   fListe;
   public:
                           Liste();
                           Liste( std::list<Element> );
                           Liste( ListePTR );
                           ~Liste();

      IterateurListe       begin();
      IterateurListe       end();

      Element              car();
      Liste                cdr();
      void                 cons( Element& );
      void                 cons( Nombre& );
      void                 cons( Chaine& );
      void                 cons( bool& );
      void                 cons( Liste& );
      void                 cons( ListePTR );
      void                 append( Element& );
      void                 append( Nombre& );
      void                 append( Chaine& );
      void                 append( bool& );
      void                 append( Liste& );
      void                 append( ListePTR );
      void                 concat( Liste& );
      void                 concat( ListePTR );

      Nombre               taille();
      Chaine               str();               // Representation textuelle du contenu de la liste.
};

#endif /* __Types__ */
