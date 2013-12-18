// =========================================================================
// DescriptionDesTypes.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __DescriptionDesTypes__
#define __DescriptionDesTypes__


#include "SupportCPlusPlus.h"

#include "LanguesPredefinis.h"


// -------------------------------------------------------------------------
// Type
// -------------------------------------------------------------------------

class    Type;
typedef  Type                 * TypePTR;

class Type
   {
public:
                              Type (
                                 ChaineLanguePredefinisPFM
                                          laFonctionNom =
                                             & LanguePredefinis ::
                                                TypeLogiqueLIBRE );

   virtual                    ~ Type ();


   virtual bool               DecritUneAbsenceDeValeur ();

   template <class TType>
   bool                       ConversionPossible (TType * lAutreType)
                                 {
                                 std::cout << "Type :: ConversionPossible" << std::endl;
                                 return false;
                                 }

   virtual bool               ConversionAccepteeDUn (TypePTR unAutreType);

   Chaine                     SousFormeDeChaine ();

private:

   ChaineLanguePredefinisPFM  fFonctionNom;

   }; // Type


template <class TTypeOrigine, class TTypeDestination>
bool                          ConversionPossibleDeEn (
                                 TTypeOrigine *       typeOrigine,
                                 TTypeDestination *   typeDestination )
                                 {
                                 std::cout << "ConversionPossible generique" << std::endl;
                                 return false;
                                 }

/*
void
f (CObjects * ptr)
   {
   CWnd * p =
         dynamic_cast <CWnd *> (ptr); //safe downcast

   if (p==0)
      //handle failure in an orderly fashion
   else
      //success, use p safely
   }
*/


// -------------------------------------------------------------------------
// Type concrets utilises
// -------------------------------------------------------------------------

class TypeInconnu : public Type
   {
public:
                              TypeInconnu ();

   template <class TType>
   bool                       ConversionPossible (TType * lAutreType)
                                 {
                                 std::cout << "TypeInconnu :: ConversionPossible" << std::endl;
                                 return true;
                                 }

   virtual bool               ConversionAccepteeDUn (TypePTR unAutreType);

   }; // TypeInconnu


// -------------------------------------------------------------------------

class TypeNonPrecise : public Type
   {
public:
                              TypeNonPrecise ();
   };


// -------------------------------------------------------------------------

class TypeNombre : public Type
   {
public:
                              TypeNombre ();
   };


// -------------------------------------------------------------------------

class TypeBooleen : public Type
   {
public:
                              TypeBooleen ();
   };


// -------------------------------------------------------------------------

class TypeChaine : public Type
   {
public:
                              TypeChaine ();
   };


// -------------------------------------------------------------------------

class TypeVide : public Type
   {
public:
                              TypeVide ();

   virtual bool               DecritUneAbsenceDeValeur ();
   };


// -------------------------------------------------------------------------

class TypeListe : public Type
   {
public:
                              TypeListe ();
   };


// -------------------------------------------------------------------------
// VariableLogiqueType
// -------------------------------------------------------------------------

typedef  VariableLogique <Type>  VariableLogiqueType;
typedef  VariableLogiqueType     * VariableLogiqueTypePTR;


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

extern TypePTR                      gTypeInconnu;
extern TypePTR                      gTypeNonPrecise;

extern TypePTR                      gTypeNombre;
extern TypePTR                      gTypeBooleen;
extern TypePTR                      gTypeChaine;
extern TypePTR                      gTypeListe;

extern TypePTR                      gTypeVide;


// -------------------------------------------------------------------------

extern VariableLogiqueTypePTR       gTypeLogiqueNombre;
extern VariableLogiqueTypePTR       gTypeLogiqueBooleen;
extern VariableLogiqueTypePTR       gTypeLogiqueChaine;
extern VariableLogiqueTypePTR       gTypeLogiqueListe;

extern VariableLogiqueTypePTR       gTypeLogiqueVide;

extern VariableLogiqueTypePTR       gTypeLogiqueNonPrecise;

extern VariableLogiqueTypePTR       gTypeLogiqueInconnu;


// -------------------------------------------------------------------------
// Initialisation
// -------------------------------------------------------------------------

void
InitialiserDescriptionDesTypes ();


#endif /* __DescriptionDesTypes__ */
