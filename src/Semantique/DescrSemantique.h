// =========================================================================
// DescrSemantique.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __DescrSemantique__
#define __DescrSemantique__


// -------------------------------------------------------------------------
// Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
// Autres inclusions
// -------------------------------------------------------------------------

#include "DescriptionDesTypes.h"

#include "ValeurLista.h"


// -------------------------------------------------------------------------
// DescrSemantique
// -------------------------------------------------------------------------

class DescrSemantique
   {
public:
                              DescrSemantique (VariableLogiqueTypePTR leTypeLogique);

   virtual                    ~ DescrSemantique ();

   VariableLogiqueTypePTR     TypeLogique ();
   bool                       ProduitUneValeur ();

   virtual void               Ecrire (int lIndentation);
   virtual void               PostFixer ();

   virtual ValeurLista        Evaluer (
                                 ContexteDEvaluationPTR leContexteDEvaluation ) = 0;
   // virtuelle pure

   void                       FaireLEvaluationDirecte (
                                 ContexteDEvaluationPTR leContexteDEvaluation );

   VariableLogiqueTypePTR     TypeLogiqueDuPremierElementDeListe ();
   ListeDescrSemantique       TraverserLeGrapheSemantique ();

#if defined SYNTHESE_PILUM
   virtual void               Synthetiser (
                                 ContexteDeSynthesePTR leContexteDeSynthese ) = 0;
   // virtuelle pure
#endif /* SYNTHESE_PILUM */

protected:

   VariableLogiqueTypePTR     fTypeLogique;

   }; // DescrSemantique


// -------------------------------------------------------------------------
// Valeurs simples
// -------------------------------------------------------------------------

class ValeurInconnue : public DescrSemantique
   {
public:
                              ValeurInconnue (
                                 VariableLogiqueTypePTR
                                          leVariableLogiqueType =
                                             gTypeLogiqueInconnu );

   virtual void               Ecrire (int lIndentation);

   virtual ValeurLista        Evaluer (
                                 ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
   virtual void               Synthetiser (
                                 ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
   };

// -------------------------------------------------------------------------

class ValeurNombre : public DescrSemantique
   {
public:
                              ValeurNombre (double laValeurNombre);

   virtual void               Ecrire (int lIndentation);

   virtual ValeurLista        Evaluer (
                                 ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
   virtual void               Synthetiser (
                                 ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */

private:

   double                     fValeurNombre;
   };

// -------------------------------------------------------------------------

class ValeurLogique : public DescrSemantique
   {
public:
                              ValeurLogique (bool laValeurLogique);

   virtual void               Ecrire (int lIndentation);

   virtual ValeurLista        Evaluer (
                                 ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
   virtual void               Synthetiser (
                                 ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */

private:

   bool                       fValeurLogique;
   };

// -------------------------------------------------------------------------

class ValeurChaine : public DescrSemantique
   {
public:
                              ValeurChaine (Chaine laValeurChaine);

   virtual void               Ecrire (int lIndentation);

   virtual ValeurLista        Evaluer (
                                 ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
   virtual void               Synthetiser (
                                 ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */

private:

   Chaine                     fValeurChaine;
   };

// -------------------------------------------------------------------------

class ValeurVide : public DescrSemantique
   {
public:
                              ValeurVide ();

   virtual void               Ecrire (int lIndentation);

   virtual ValeurLista        Evaluer (
                                 ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
   virtual void               Synthetiser (
                                 ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
   };

// -------------------------------------------------------------------------

class ValeurListe : public DescrSemantique
   {
private:
   ListeDescrSemantique       fListeDeDescriptionsSemantique;
public:
                              ValeurListe ( ListeDescrSemantique );
   ListeDescrSemantique       ListeDeDescriptionsSemantique(){ return fListeDeDescriptionsSemantique; }

   virtual void               Ecrire (int lIndentation);

   virtual ValeurLista        Evaluer (
                                 ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
   virtual void               Synthetiser (
                                 ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */
   };


// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

extern DescrSemantiquePTR           gValeurVide;

extern DescrSemantiquePTR           gDescrSemantiqueInconnue;


// -------------------------------------------------------------------------
// Initialisation
// -------------------------------------------------------------------------

void
InitialiserDescrSemantique ();


#endif /* __DescrSemantique__ */
