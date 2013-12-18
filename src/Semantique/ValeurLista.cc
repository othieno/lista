// =========================================================================
// ValeurLista.cc
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#include "ValeurLista.h"

//#include "LanguesSyntaxe.h"
#include "LanguesSemantique.h"


// -------------------------------------------------------------------------
// ValeurLista
// -------------------------------------------------------------------------

ValeurLista :: ValeurLista ()
   {
   fType = gTypeVide;
   }

// -------------------------------------------------------------------------

ValeurLista :: ValeurLista (Nombre leNombre)
   {
   fType = gTypeNombre;
   fNombre = leNombre;
   }

// -------------------------------------------------------------------------

ValeurLista :: ValeurLista (bool leBooleen)
   {
   fType = gTypeBooleen;
   fBooleen = leBooleen;
   }

// -------------------------------------------------------------------------

ValeurLista :: ValeurLista (Chaine laChaine)
   {
   fType = gTypeChaine;
   fChaine = laChaine;
   }

// -------------------------------------------------------------------------

ValeurLista :: ValeurLista (Liste laListe)
   {
   fType = gTypeListe;
   fListe = laListe;
   }

// -------------------------------------------------------------------------
// Méthodes de TEST DYNAMIQUE DE TYPE
// -------------------------------------------------------------------------

Nombre
ValeurLista :: CommeNombre ()
   {
   if (dynamic_cast <TypeNombre *> (fType) != NULL)
      return fNombre;


   else
      {
      SortieSurErreur (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatErreurCommeNombre (),
             fType -> SousFormeDeChaine () ),
         1 );
      return Nombre (0);   // superflu
      }
   }  // ValeurLista :: CommeNombre ()

// -------------------------------------------------------------------------

bool
ValeurLista :: CommeBooleen ()
   {
   if (dynamic_cast <TypeBooleen *> (fType) != NULL)
      return fBooleen;


   else
      {
      SortieSurErreur (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatErreurCommeBooleen (),
            fType -> SousFormeDeChaine () ),
         1 );
      return false;  // superflu
      }
   }  // ValeurLista :: CommeBooleen ()

// -------------------------------------------------------------------------

Chaine
ValeurLista :: CommeChaine ()
   {
   if (dynamic_cast <TypeChaine *> (fType) != NULL)
      return fChaine;


   else
      {
      SortieSurErreur (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatErreurCommeChaine (),
            fType -> SousFormeDeChaine () ),
         1 );
      return false;  // superflu
      }
   }  // ValeurLista :: CommeChaine ()


// -------------------------------------------------------------------------

Liste
ValeurLista :: CommeListe ()
   {
   if ( dynamic_cast <TypeListe*> (fType) )
      return fListe;

   return Liste();   // superflu
   }  // ValeurLista :: CommeListe ()


// -------------------------------------------------------------------------

void
ValeurLista :: Ecrire (int lIndentation)
   {

   if (dynamic_cast <TypeNombre *> (fType) != NULL)
      {
      std::cout <<
         MiseEnForme (
            "%*.*f",
            TailleChampEcritureNombres (),
            NombreDecimalesEcritureNombres (),
            fNombre );
      }

   else if (dynamic_cast <TypeBooleen *> (fType) != NULL)
      {
      std::cout <<
         MiseEnForme (
            "%s",
            fBooleen
               ?  gLANGUE_Predefinis ->
                     Vrai ()
               :  gLANGUE_Predefinis ->
                     Faux () );
      }

   else if (dynamic_cast <TypeChaine *> (fType) != NULL)
      {
      std::cout <<
         MiseEnForme ("%s", fChaine);
      }

   else if (dynamic_cast <TypeListe *>(fType) != NULL)
      std::cout << MiseEnForme( "%s", fListe.str() );

   else
      {
      SortieSurErreur (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatErreurTypeValeurLista (),
            fType -> SousFormeDeChaine () ),
         1 );
      }

   }; // ValeurLista :: Ecrire


// -------------------------------------------------------------------------

TypePTR
ValeurLista :: Type ()
   { return fType; }
