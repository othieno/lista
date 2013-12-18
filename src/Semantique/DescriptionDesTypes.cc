// =========================================================================
// DescriptionDesTypes.cc
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#include "DescriptionDesTypes.h"


// -------------------------------------------------------------------------
// Types
// -------------------------------------------------------------------------

Type :: Type (
   ChaineLanguePredefinisPFM
            laFonctionNom )
   {
   fFonctionNom = laFonctionNom;
   }

Type :: ~ Type ()
   {}


bool
Type :: DecritUneAbsenceDeValeur ()
   { return false; }

bool
Type :: ConversionAccepteeDUn (TypePTR unAutreType)
   {
   return unAutreType == gTypeInconnu;
   }

Chaine
Type :: SousFormeDeChaine ()
   { return (gLANGUE_Predefinis ->* fFonctionNom) (); }


// -------------------------------------------------------------------------

TypeInconnu :: TypeInconnu ()
   : Type (
      & LanguePredefinis :: TypeInconnu )
   {}


bool
TypeInconnu :: ConversionAccepteeDUn (TypePTR unAutreType)
   {
   return true;
   }

template <>
bool Type :: ConversionPossible <TypeInconnu> (TypeInconnu * lAutreType)
   {
   return true;
   }

/*
template <>
bool                          ConversionPossibleDeEn
                                 <Type, TypeInconnu>
                                 (
                                 Type        *  typeOrigine,
                                 TypeInconnu *  typeDestination )
                                 {
                                 std::cout <<
                                    "ConversionPossible <Type, TypeInconnu>" <<
                                    std::endl;
                                 return true;
                                 }

template <>
bool                          ConversionPossibleDeEn
                                 <TypeInconnu, Type>
                                 (
                                 TypeInconnu * typeOrigine,
                                 Type        * typeDestination )
                                 {
                                 std::cout <<
                                    "ConversionPossible <TypeInconnu, Type>" <<
                                    std::endl;
                                 return true;
                                 }
*/

// -------------------------------------------------------------------------

TypeNonPrecise :: TypeNonPrecise ()
   : Type (
      & LanguePredefinis :: TypeNonPrecise )
   {}


// -------------------------------------------------------------------------

TypeNombre :: TypeNombre ()
   : Type (
      & LanguePredefinis :: TypeNombre )
   {}



// -------------------------------------------------------------------------

TypeBooleen :: TypeBooleen ()
   : Type (
      & LanguePredefinis :: TypeBooleen )
   {}



// -------------------------------------------------------------------------

TypeChaine :: TypeChaine ()
   : Type (
      & LanguePredefinis :: TypeChaine )
   {}



// -------------------------------------------------------------------------

TypeListe :: TypeListe ()
   : Type (
      & LanguePredefinis :: TypeListe )
   {}

// -------------------------------------------------------------------------

TypeVide :: TypeVide ()
   : Type (
      & LanguePredefinis :: TypeVide )
   {}

bool
TypeVide :: DecritUneAbsenceDeValeur ()
   { return true; }


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

TypePTR                       gTypeInconnu         = NULL;
TypePTR                       gTypeNonPrecise      = NULL;

TypePTR                       gTypeNombre          = NULL;
TypePTR                       gTypeBooleen         = NULL;
TypePTR                       gTypeChaine          = NULL;
TypePTR                       gTypeListe			   = NULL;

TypePTR                       gTypeVide            = NULL;



// -------------------------------------------------------------------------

VariableLogiqueTypePTR        gTypeLogiqueNombre      = NULL;
VariableLogiqueTypePTR        gTypeLogiqueBooleen     = NULL;
VariableLogiqueTypePTR        gTypeLogiqueChaine      = NULL;
VariableLogiqueTypePTR        gTypeLogiqueListe			= NULL;

VariableLogiqueTypePTR        gTypeLogiqueVide        = NULL;

VariableLogiqueTypePTR        gTypeLogiqueInconnu     = NULL;

VariableLogiqueTypePTR        gTypeLogiqueNonPrecise  = NULL;


// -------------------------------------------------------------------------
// Initialisation
// -------------------------------------------------------------------------

void
InitialiserDescriptionDesTypes ()
   {
   gTypeInconnu               = new TypeInconnu;
   gTypeNonPrecise            = new TypeNonPrecise;

   gTypeNombre                = new TypeNombre;
   gTypeBooleen               = new TypeBooleen;
   gTypeChaine                = new TypeChaine;
   gTypeListe			         = new TypeListe;

   gTypeVide                  = new TypeVide;

   // -------------------------------------------------------------------------

   gTypeLogiqueInconnu     =
      new VariableLogiqueType (
         gLANGUE_Predefinis -> TypeInconnu (),
         gTypeInconnu );
   gTypeLogiqueNonPrecise  =
      new VariableLogiqueType (
         gLANGUE_Predefinis -> TypeNonPrecise (),
         gTypeNonPrecise );

   gTypeLogiqueNombre      =
      new VariableLogiqueType (
         gLANGUE_Predefinis -> TypeNombre (),
         gTypeNombre );
   gTypeLogiqueBooleen     =
      new VariableLogiqueType (
         gLANGUE_Predefinis -> TypeBooleen (),
         gTypeBooleen );
   gTypeLogiqueChaine      =
      new VariableLogiqueType (
         gLANGUE_Predefinis -> TypeChaine (),
         gTypeChaine );
   gTypeLogiqueListe =
      new VariableLogiqueType (
         gLANGUE_Predefinis -> TypeListe (),
         gTypeListe );

   gTypeLogiqueVide        =
      new VariableLogiqueType (
         gLANGUE_Predefinis -> TypeVide (),
         gTypeVide );
   }  //InitialiserDescriptionDesTypes
