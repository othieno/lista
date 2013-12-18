// =========================================================================
// LanguesPredefinis.cc
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#include "Langues.h"

#include "LanguesPredefinis.h"

#include "SupportCPlusPlus.h"

#include <iostream>


// -------------------------------------------------------------------------
// LanguePredefinis
// -------------------------------------------------------------------------

LanguePredefinis :: LanguePredefinis ()
   {}

LanguePredefinis :: ~ LanguePredefinis ()
   {}


// -------------------------------------------------------------------------
// LanguePredefinisFR
// -------------------------------------------------------------------------

LanguePredefinisFR :: LanguePredefinisFR ()
   {}


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: TypeLogiqueLIBRE ()
   { return "TypeLogiqueLIBRE"; }

Chaine
LanguePredefinisFR :: TypeInconnu ()
   { return "TypeInconnu"; }

Chaine
LanguePredefinisFR :: TypeNonPrecise ()
   { return "TypeNonPrecise"; }

Chaine
LanguePredefinisFR :: TypeNombre ()
   { return "TypeNombre"; }

Chaine
LanguePredefinisFR :: TypeBooleen ()
   { return "TypeBooleen"; }

Chaine
LanguePredefinisFR :: TypeChaine ()
   { return "TypeChaine"; }

Chaine
LanguePredefinisFR :: TypeVide ()
   { return "TypeVide"; }

Chaine
LanguePredefinisFR :: TypeListe ()
   { return "TypeListe"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Vrai ()
   { return "Vrai"; }

Chaine
LanguePredefinisFR :: Faux ()
   { return "Faux"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Pi ()
   { return "Pi"; }

Chaine
LanguePredefinisFR :: E ()
   { return "E"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Vide ()
   { return "Vide"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Non ()
   { return "Non"; }

Chaine
LanguePredefinisFR :: Et ()
   { return "Et"; }

Chaine
LanguePredefinisFR :: Ou ()
   { return "Ou"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Pair ()
   { return "Pair"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Egale ()
   { return "Egale"; }

Chaine
LanguePredefinisFR :: Different ()
   { return "Different"; }

Chaine
LanguePredefinisFR :: Inf ()
   { return "Inf"; }

Chaine
LanguePredefinisFR :: Sup ()
   { return "Sup"; }

Chaine
LanguePredefinisFR :: InfEgale ()
   { return "InfEgale"; }

Chaine
LanguePredefinisFR :: SupEgale ()
   { return "SupEgale"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Modulo ()
   { return "Modulo"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Hasard ()
   { return "Hasard"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Racine ()
   { return "Racine"; }

Chaine
LanguePredefinisFR :: Sin ()
   { return "Sin"; }

Chaine
LanguePredefinisFR :: Cos ()
   { return "Cos"; }

Chaine
LanguePredefinisFR :: ArcTan ()
   { return "ArcTan"; }

Chaine
LanguePredefinisFR :: Log ()
   { return "Log"; }

Chaine
LanguePredefinisFR :: Exp ()
   { return "Exp"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: LongueurChaine ()
   { return "LongueurChaine"; }

Chaine
LanguePredefinisFR :: ChaineVide ()
   { return "ChaineVide"; }

Chaine
LanguePredefinisFR :: ContientChaine ()
   { return "ContientChaine"; }

Chaine
LanguePredefinisFR :: ConcatChaines ()
   { return "ConcatChaines"; }
Chaine
LanguePredefinisFR :: RepliquerChaine ()
   { return "RepliquerChaine"; }

Chaine
LanguePredefinisFR :: RemplacerChaine ()
   { return "RemplacerChaine"; }

Chaine
LanguePredefinisFR :: FormaterNombre ()
   { return "FormaterNombre"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: LireNombre ()
   { return "LireNombre"; }

Chaine
LanguePredefinisFR :: LireBooleen ()
   { return "LireBooleen"; }

Chaine
LanguePredefinisFR :: LireChaine ()
   { return "LireChaine"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: EcrireNombre ()
   { return "EcrireNombre"; }

Chaine
LanguePredefinisFR :: EcrireBooleen ()
   { return "EcrireBooleen"; }

Chaine
LanguePredefinisFR :: EcrireChaine ()
   { return "EcrireChaine"; }

Chaine
LanguePredefinisFR :: EcrireFinDeLigne ()
   { return "EcrireFinDeLigne"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Si ()
   { return "Si"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Seq ()
   { return "Seq"; }

Chaine
LanguePredefinisFR :: Seq1 ()
   { return "Seq1"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Somme ()
   { return "Somme"; }

Chaine
LanguePredefinisFR :: Produit ()
   { return "Produit"; }

Chaine
LanguePredefinisFR :: Pour ()
   { return "Pour"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisFR :: Car ()
   { return "Car"; }

Chaine
LanguePredefinisFR :: Cdr ()
   { return "Cdr"; }

Chaine
LanguePredefinisFR :: Cons ()
   { return "Cons"; }

Chaine
LanguePredefinisFR :: Append ()
   { return "Append"; }

Chaine
LanguePredefinisFR :: ConcatListes ()
   { return "ConcatListes"; }

Chaine
LanguePredefinisFR :: LongueurListe ()
   { return "LongueurListe"; }


// -------------------------------------------------------------------------



// -------------------------------------------------------------------------
// LanguePredefinisEN
// -------------------------------------------------------------------------

LanguePredefinisEN :: LanguePredefinisEN ()
   {}


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: TypeLogiqueLIBRE ()
   { return "FREELogicalType"; }

Chaine
LanguePredefinisEN :: TypeInconnu ()
   { return "UnknownType"; }

Chaine
LanguePredefinisEN :: TypeNonPrecise ()
   { return "UnspecifiedType"; }

Chaine
LanguePredefinisEN :: TypeNombre ()
   { return "NumberType"; }

Chaine
LanguePredefinisEN :: TypeBooleen ()
   { return "BooleanType"; }

Chaine
LanguePredefinisEN :: TypeChaine ()
   { return "StringType"; }

Chaine
LanguePredefinisEN :: TypeVide ()
   { return "VoidType"; }

Chaine
LanguePredefinisEN :: TypeListe ()
   { return "ListType"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Vrai ()
   { return "True"; }

Chaine
LanguePredefinisEN :: Faux ()
   { return "False"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Pi ()
   { return "Pi"; }

Chaine
LanguePredefinisEN :: E ()
   { return "E"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Vide ()
   { return "Empty"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Non ()
   { return "Not"; }

Chaine
LanguePredefinisEN :: Et ()
   { return "And"; }

Chaine
LanguePredefinisEN :: Ou ()
   { return "Or"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Pair ()
   { return "Even"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Egale ()
   { return "Equals"; }

Chaine
LanguePredefinisEN :: Different ()
   { return "NotEqual"; }

Chaine
LanguePredefinisEN :: Inf ()
   { return "LessThan"; }

Chaine
LanguePredefinisEN :: Sup ()
   { return "GreaterThan"; }

Chaine
LanguePredefinisEN :: InfEgale ()
   { return "LessThanOrEqual"; }

Chaine
LanguePredefinisEN :: SupEgale ()
   { return "GreaterThanOrEqual"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Modulo ()
   { return "Modulo"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Hasard ()
   { return "Random"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Racine ()
   { return "Sqrt"; }

Chaine
LanguePredefinisEN :: Sin ()
   { return "Sin"; }

Chaine
LanguePredefinisEN :: Cos ()
   { return "Cos"; }

Chaine
LanguePredefinisEN :: ArcTan ()
   { return "ArcTan"; }

Chaine
LanguePredefinisEN :: Log ()
   { return "Log"; }

Chaine
LanguePredefinisEN :: Exp ()
   { return "Exp"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: LongueurChaine ()
   { return "StringLength"; }

Chaine
LanguePredefinisEN :: ChaineVide ()
   { return "EmptyString"; }

Chaine
LanguePredefinisEN :: ContientChaine ()
   { return "ContainsString"; }

Chaine
LanguePredefinisEN :: ConcatChaines ()
   { return "ConcatStrings"; }
Chaine
LanguePredefinisEN :: RepliquerChaine ()
   { return "ReplicateString"; }

Chaine
LanguePredefinisEN :: RemplacerChaine ()
   { return "ReplaceString"; }

Chaine
LanguePredefinisEN :: FormaterNombre ()
   { return "FormatNumber"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: LireNombre ()
   { return "ReadNumber"; }

Chaine
LanguePredefinisEN :: LireBooleen ()
   { return "ReadBoolean"; }

Chaine
LanguePredefinisEN :: LireChaine ()
   { return "ReadString"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: EcrireNombre ()
   { return "WriteNumber"; }

Chaine
LanguePredefinisEN :: EcrireBooleen ()
   { return "WriteBoolean"; }

Chaine
LanguePredefinisEN :: EcrireChaine ()
   { return "WriteString"; }

Chaine
LanguePredefinisEN :: EcrireFinDeLigne ()
   { return "WriteEndOfLine"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Si ()
   { return "If"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Seq ()
   { return "Seq"; }

Chaine
LanguePredefinisEN :: Seq1 ()
   { return "Seq1"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Somme ()
   { return "Sum"; }

Chaine
LanguePredefinisEN :: Produit ()
   { return "Product"; }

Chaine
LanguePredefinisEN :: Pour ()
   { return "For"; }


// -------------------------------------------------------------------------

Chaine
LanguePredefinisEN :: Car ()
   { return "Car"; }

Chaine
LanguePredefinisEN :: Cdr ()
   { return "Cdr"; }

Chaine
LanguePredefinisEN :: Cons ()
   { return "Cons"; }

Chaine
LanguePredefinisEN :: Append ()
   { return "Append"; }

Chaine
LanguePredefinisEN :: ConcatListes ()
   { return "ConcatLists"; }

Chaine
LanguePredefinisEN :: LongueurListe ()
   { return "ListLength"; }

// -------------------------------------------------------------------------



// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

LanguePredefinisPTR           gLANGUE_Predefinis            = NULL;


// -------------------------------------------------------------------------
// InitialiserLanguesPredefinis
// -------------------------------------------------------------------------

void
InitialiserLanguesPredefinis (Chaine leMnemonique)
   {
   if (gLANGUE_Predefinis != NULL)
      delete gLANGUE_Predefinis;

   if (leMnemonique == "fr")
      gLANGUE_Predefinis = new LanguePredefinisFR;
   if (leMnemonique == "en")
      gLANGUE_Predefinis = new LanguePredefinisEN;
   }
