// =========================================================================
// LanguesPredefinis.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __LanguesPredefinis__
#define __LanguesPredefinis__


#include "Langues.h"


// -------------------------------------------------------------------------
// LanguePredefinis
// -------------------------------------------------------------------------

class    LanguePredefinis;
typedef  LanguePredefinis     * LanguePredefinisPTR;

typedef Chaine                (LanguePredefinis :: * ChaineLanguePredefinisPFM) ();

class LanguePredefinis
   {
public:
                              LanguePredefinis ();

   virtual                    ~ LanguePredefinis ();


   // Types predefinis
   // -------------------------------------------------------------------------

   virtual Chaine             TypeLogiqueLIBRE () = 0;
                                 // virtuelle pure
   virtual Chaine             TypeInconnu () = 0;
                                 // virtuelle pure
   virtual Chaine             TypeNonPrecise () = 0;
                                 // virtuelle pure
   virtual Chaine             TypeNombre () = 0;
                                 // virtuelle pure
   virtual Chaine             TypeBooleen () = 0;
                                 // virtuelle pure
   virtual Chaine             TypeChaine () = 0;
                                 // virtuelle pure
   virtual Chaine             TypeVide () = 0;
                                 // virtuelle pure
   virtual Chaine             TypeListe () = 0;
                                 // virtuelle pure


   // Identificateurs predefinis
   // -------------------------------------------------------------------------

   virtual Chaine             Vrai () = 0;
                                 // virtuelle pure
   virtual Chaine             Faux () = 0;
                                 // virtuelle pure

   virtual Chaine             Pi () = 0;
                                 // virtuelle pure
   virtual Chaine             E () = 0;
                                 // virtuelle pure

   virtual Chaine             Vide () = 0;
                                 // virtuelle pure

   virtual Chaine             Non () = 0;
                                 // virtuelle pure
   virtual Chaine             Et () = 0;
                                 // virtuelle pure
   virtual Chaine             Ou () = 0;
                                 // virtuelle pure

   virtual Chaine             Pair () = 0;
                                 // virtuelle pure

   virtual Chaine             Egale () = 0;
                                 // virtuelle pure
   virtual Chaine             Different () = 0;
                                 // virtuelle pure
   virtual Chaine             Inf () = 0;
                                 // virtuelle pure
   virtual Chaine             Sup () = 0;
                                 // virtuelle pure
   virtual Chaine             InfEgale () = 0;
                                 // virtuelle pure
   virtual Chaine             SupEgale () = 0;
                                 // virtuelle pure

   virtual Chaine             Modulo () = 0;
                                 // virtuelle pure

   virtual Chaine             Hasard () = 0;
                                 // virtuelle pure

   virtual Chaine             Racine () = 0;
                                 // virtuelle pure
   virtual Chaine             Sin () = 0;
                                 // virtuelle pure
   virtual Chaine             Cos () = 0;
                                 // virtuelle pure
   virtual Chaine             ArcTan () = 0;
                                 // virtuelle pure
   virtual Chaine             Log () = 0;
                                 // virtuelle pure
   virtual Chaine             Exp () = 0;
                                 // virtuelle pure

   virtual Chaine             LongueurChaine () = 0;
                                 // virtuelle pure
   virtual Chaine             ChaineVide () = 0;
                                 // virtuelle pure
   virtual Chaine             ContientChaine () = 0;
                                 // virtuelle pure
   virtual Chaine             ConcatChaines () = 0;
                                 // virtuelle pure
   virtual Chaine             RepliquerChaine () = 0;
                                 // virtuelle pure
   virtual Chaine             RemplacerChaine () = 0;
                                 // virtuelle pure
   virtual Chaine             FormaterNombre () = 0;
                                 // virtuelle pure

   virtual Chaine             LireNombre () = 0;
                                 // virtuelle pure
   virtual Chaine             LireBooleen () = 0;
                                 // virtuelle pure
   virtual Chaine             LireChaine () = 0;
                                 // virtuelle pure

   virtual Chaine             EcrireNombre () = 0;
                                 // virtuelle pure
   virtual Chaine             EcrireBooleen () = 0;
                                 // virtuelle pure
   virtual Chaine             EcrireChaine () = 0;
                                 // virtuelle pure
   virtual Chaine             EcrireFinDeLigne () = 0;
                                 // virtuelle pure

   virtual Chaine             Si () = 0;
                                 // virtuelle pure

   virtual Chaine             Seq () = 0;
                                 // virtuelle pure
   virtual Chaine             Seq1 () = 0;
                                 // virtuelle pure

   virtual Chaine             Somme () = 0;
                                 // virtuelle pure
   virtual Chaine             Produit () = 0;
                                 // virtuelle pure
   virtual Chaine             Pour () = 0;
                                 // virtuelle pure

   virtual Chaine             Car () = 0;
                                 // virtuelle pure
   virtual Chaine             Cdr () = 0;
                                 // virtuelle pure
   virtual Chaine             Cons () = 0;
                                 // virtuelle pure
   virtual Chaine             Append () = 0;
                                 // virtuelle pure
   virtual Chaine             ConcatListes () = 0;
                                 // virtuelle pure
   virtual Chaine             LongueurListe () = 0;
                                 // virtuelle pure

   }; // LanguePredefinis


// -------------------------------------------------------------------------
// LanguePredefinisFR
// -------------------------------------------------------------------------

class    LanguePredefinisFR;
typedef  LanguePredefinisFR   * LanguePredefinisFRPTR;

class LanguePredefinisFR : virtual public LanguePredefinis
   {
public:
                              LanguePredefinisFR ();


   // Types predefinis
   // -------------------------------------------------------------------------

   Chaine                     TypeLogiqueLIBRE ();
   Chaine                     TypeInconnu ();
   Chaine                     TypeNonPrecise ();
   Chaine                     TypeNombre ();
   Chaine                     TypeBooleen ();
   Chaine                     TypeChaine ();
   Chaine                     TypeVide ();
   Chaine                     TypeListe ();


   // Identificateurs predefinis
   // -------------------------------------------------------------------------

   Chaine                     Vrai ();
   Chaine                     Faux ();

   Chaine                     Pi ();
   Chaine                     E ();

   Chaine                     Vide ();

   Chaine                     Non ();
   Chaine                     Et ();
   Chaine                     Ou ();

   Chaine                     Pair ();

   Chaine                     Egale ();
   Chaine                     Different ();
   Chaine                     Inf ();
   Chaine                     Sup ();
   Chaine                     InfEgale ();
   Chaine                     SupEgale ();

   Chaine                     Modulo ();

   Chaine                     Hasard ();

   Chaine                     Racine ();
   Chaine                     Sin ();
   Chaine                     Cos ();
   Chaine                     ArcTan ();
   Chaine                     Log ();
   Chaine                     Exp ();

   Chaine                     LongueurChaine ();
   Chaine                     ChaineVide ();
   Chaine                     ContientChaine ();
   Chaine                     ConcatChaines ();
   Chaine                     RepliquerChaine ();
   Chaine                     RemplacerChaine ();
   Chaine                     FormaterNombre ();

   Chaine                     LireNombre ();
   Chaine                     LireBooleen ();
   Chaine                     LireChaine ();

   Chaine                     EcrireNombre ();
   Chaine                     EcrireBooleen ();
   Chaine                     EcrireChaine ();
   Chaine                     EcrireFinDeLigne ();

   Chaine                     Si ();

   Chaine                     Seq ();
   Chaine                     Seq1 ();

   Chaine                     Somme ();
   Chaine                     Produit ();
   Chaine                     Pour ();

   Chaine                     Car ();
   Chaine                     Cdr ();
   Chaine                     Cons ();
   Chaine                     Append ();
   Chaine                     ConcatListes ();
   Chaine                     LongueurListe ();

   }; // LanguePredefinisFR


// -------------------------------------------------------------------------
// LanguePredefinisEN
// -------------------------------------------------------------------------

class    LanguePredefinisEN;
typedef  LanguePredefinisEN   * LanguePredefinisENPTR;

class LanguePredefinisEN : virtual public LanguePredefinis
   {
public:
                              LanguePredefinisEN ();


   // Types predefinis
   // -------------------------------------------------------------------------

   Chaine                     TypeLogiqueLIBRE ();
   Chaine                     TypeInconnu ();
   Chaine                     TypeNonPrecise ();
   Chaine                     TypeNombre ();
   Chaine                     TypeBooleen ();
   Chaine                     TypeChaine ();
   Chaine                     TypeVide ();
   Chaine                     TypeListe ();


   // Identificateurs predefinis
   // -------------------------------------------------------------------------

   Chaine                     Vrai ();
   Chaine                     Faux ();

   Chaine                     Pi ();
   Chaine                     E ();

   Chaine                     Vide ();

   Chaine                     Non ();
   Chaine                     Et ();
   Chaine                     Ou ();

   Chaine                     Pair ();

   Chaine                     Egale ();
   Chaine                     Different ();
   Chaine                     Inf ();
   Chaine                     Sup ();
   Chaine                     InfEgale ();
   Chaine                     SupEgale ();

   Chaine                     Modulo ();

   Chaine                     Hasard ();

   Chaine                     Racine ();
   Chaine                     Sin ();
   Chaine                     Cos ();
   Chaine                     ArcTan ();
   Chaine                     Log ();
   Chaine                     Exp ();

   Chaine                     LongueurChaine ();
   Chaine                     ChaineVide ();
   Chaine                     ContientChaine ();
   Chaine                     ConcatChaines ();
   Chaine                     RepliquerChaine ();
   Chaine                     RemplacerChaine ();
   Chaine                     FormaterNombre ();

   Chaine                     LireNombre ();
   Chaine                     LireBooleen ();
   Chaine                     LireChaine ();

   Chaine                     EcrireNombre ();
   Chaine                     EcrireBooleen ();
   Chaine                     EcrireChaine ();
   Chaine                     EcrireFinDeLigne ();

   Chaine                     Si ();

   Chaine                     Seq ();
   Chaine                     Seq1 ();

   Chaine                     Somme ();
   Chaine                     Produit ();
   Chaine                     Pour ();

   Chaine                     Car ();
   Chaine                     Cdr ();
   Chaine                     Cons ();
   Chaine                     Append ();
   Chaine                     ConcatListes ();
   Chaine                     LongueurListe ();

   }; // LanguePredefinisEN


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

extern LanguePredefinisPTR    gLANGUE_Predefinis;


// -------------------------------------------------------------------------
// InitialiserLanguesPredefinis
// -------------------------------------------------------------------------

void                          InitialiserLanguesPredefinis (
                                 Chaine leMnemonique = LANGUE_PAR_DEFAUT );


#endif /* __LanguesPredefinis__ */
