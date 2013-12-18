// =========================================================================
// FonctionsUtilisateur.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __FonctionsUtilisateur__
#define __FonctionsUtilisateur__


// -------------------------------------------------------------------------
// Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
// Autres inclusions
// -------------------------------------------------------------------------

#include "LanguesSemantique.h"

#include "DescrSemantique.h"

#include "ParametresFormels.h"

#include "TableDesSymboles.h"

#include "ContexteDEvaluation.h"

#include <vector>


#if defined SYNTHESE_PILUM
   #include "SynthesePilum.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
// FonctionUtilisateur
// -------------------------------------------------------------------------

class    FonctionUtilisateur;
typedef  FonctionUtilisateur  * FonctionUtilisateurPTR;

class FonctionUtilisateur : public Identificateur
   {
public:

                              FonctionUtilisateur (
                                 Chaine                  leNom,
                                 Chaine                  leNomQualifie,
                                 VariableLogiqueTypePTR  laVarLogiqueType,
                                 DictionnairePTR         leDictionnaire );

   virtual Chaine             SousFormeDeChaine ();

   DictionnairePTR            DictionnaireLocal ();

   ListeDeParametresFormelsPTR
                              LaListeDeParametresFormels ();

   void                       GrapheSemantiqueDuCorps (
                                 DescrSemantiquePTR
                                          leGrapheSemantiqueDuCorps );
   DescrSemantiquePTR         GrapheSemantiqueDuCorps ();

   int                        NiveauDEvaluation ();
   int                        NiveauStatique ();

   virtual void               PurgerIdent (
                                 int      lIdentation,
                                 bool     leModeVerbeux,
                                 bool     leMontrerLesDictionnaires );

#if defined SYNTHESE_PILUM

   void                       EtiquetteDuCorps (
                                 VariableLogiqueEtiquettePTR lEtiquDuCorps );
   VariableLogiqueEtiquettePTR
                              EtiquetteDuCorps ();

   void                       UnLienStatiqueEstNecessaire ();
   bool                       LienStatiqueNecessaire ();

#endif /* SYNTHESE_PILUM */


private:

   DictionnairePTR            fDictionnaireLocal;
   ListeDeParametresFormelsPTR
                              fListeDeParametresFormels;

   DescrSemantiquePTR         fGrapheSemantiqueDuCorps;

   int                        fNiveauDEvaluation;
   int                        fNiveauStatique;

#if defined SYNTHESE_PILUM

   VariableLogiqueEtiquettePTR
                              fEtiquetteDuCorps;
   bool                       fLienStatiqueNecessaire;

#endif /* SYNTHESE_PILUM */

   }; // FonctionUtilisateur


// -------------------------------------------------------------------------
// AppelDeFonctionUtilisateur
// -------------------------------------------------------------------------

class AppelDeFonctionUtilisateur : public DescrSemantique
   {
public:
                              AppelDeFonctionUtilisateur (
                                 FonctionUtilisateurPTR  laFonctionUtilisateur,
                                 DescrSemantiquePTR      * lesArgumentsDAppel );

   virtual void               Ecrire (int lIndentation);
   virtual void               PostFixer ();

   virtual ValeurLista        Evaluer (
                                 ContexteDEvaluationPTR leContexteDEvaluation );
#if defined SYNTHESE_PILUM
   virtual void               Synthetiser (
                                 ContexteDeSynthesePTR leContexteDeSynthese );
#endif /* SYNTHESE_PILUM */

   DescrSemantiquePTR         GrapheSemantiqueDuCorps ();

private:

   FonctionUtilisateurPTR     fFonctionUtilisateur;

   DescrSemantiquePTR         * fArgumentsDAppel;
                                 // un tableau dynamique

   int                        fNiveauDEvaluation;
   int                        fNiveauStatique;
   }; // AppelDeFonctionUtilisateur


// -------------------------------------------------------------------------
// OptionsEvaluation
// -------------------------------------------------------------------------

class    OptionsEvaluation;
typedef  OptionsEvaluation    * OptionsEvaluationPTR;

class OptionsEvaluation
   {
public:
                              OptionsEvaluation (
                                 bool                 leModeTrace );

   bool                       ModeTrace ();

private:

   bool                       fModeTrace;

   }; // OptionsEvaluation


inline
bool
OptionsEvaluation :: ModeTrace ()
   { return fModeTrace; }


#endif /* __FonctionsUtilisateur__ */
