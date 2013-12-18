// =========================================================================
// AnalyseurListaFlexBison.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __AnalyseurListaFlexBison__
#define __AnalyseurListaFlexBison__


// -------------------------------------------------------------------------
// Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
// Autres inclusions
// -------------------------------------------------------------------------

#include "FonctionsUtilisateur.h"

#include "AnalyseurSemantiqueLista.h"

#include "SupportFlexBison.h"
#include "SupportFlexBisonLista.h"
#include <deque>


// -------------------------------------------------------------------------
// AnalyseurListaFlexBison
// -------------------------------------------------------------------------

class    AnalyseurListaFlexBison;
typedef  AnalyseurListaFlexBison    * AnalyseurListaFlexBisonPTR;

class AnalyseurListaFlexBison : public AnalyseurSemantiqueLista
   {
public:

                              AnalyseurListaFlexBison (
                                 bool                       leModeDebug,
                                 bool                       leMontrerLesTerminaux,
                                 OptionsStrategiePTR        lesOptionsStrategie,
                                 OptionsSemantiquePTR       lesOptionsSemantique,
                                 OptionsFlexBisonPTR              lesOptionsFlexBison,
                                 OptionsEvaluationPTR       lesOptionsEvaluation
#if defined SYNTHESE_PILUM
                              ,  SynthetiseurPilumListaPTR  leSynthetiseurPilumLista
#endif /* SYNTHESE_PILUM */
                                 );

   virtual                    ~ AnalyseurListaFlexBison ();


   Chaine                     DescriptionDuTerminalCourant ();
   Chaine                     DescriptionDeLaPositionCourante ();

   bool                       ModeDebug ();
   bool                       MontrerLesTerminaux ();

   OptionsFlexBisonPTR              OptionsFlexBison ();

   FonctionUtilisateurPTR     IdentFonction ();


   // Methodes pour les actions semantiques
   // -------------------------------------

   void                       TraiterIdentFonction (
                                 DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );

   void                       TraiterDebutParametres ();
   void                       TraiterParametre (
                                 DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );

   void                       TraiterCorpsDefinitionDeFonction (
                                 FonctionUtilisateurPTR  lIdentFonction,
                                 DescrSemantiquePTR      leCorps );
   void                       TraiterFinDefinitionDeFonction (
                                 FonctionUtilisateurPTR  lIdentFonction,
                                 DescrSemantiquePTR      leCorps );

   void                       TraiterDebutEvaluation ();
   void                       TraiterFinEvaluation (DescrSemantiquePTR laSequence);

   DescrSemantiquePTR         TraiterFacteurIdentSimple (
                                 DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );

   DescrAppelFonctionPTR      AccepterFacteurAppelDeFonctionInconnue (
                                 Chaine nomIdentCourant );
   void                       TraiterDebutAppelFonction (
                                 DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );
   DescrSemantiquePTR         TraiterFinAppelFonction ();

   void                       TraiterDebutIteration (
                                 DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );
   void                       TraiterIndiceIteration (
                                 DescrIdentificateurFlexBison laDescrIdentificateurFlexBison );
   void                       TraiterBorneInf (DescrSemantiquePTR laBorneInf);
   void                       TraiterBorneSup (DescrSemantiquePTR laBorneSup);
   void                       TraiterExprIteree (DescrSemantiquePTR lExpression);
   DescrSemantiquePTR         TraiterFinIteration ();

   DescrSemantiquePTR         TraiterSequence (
                                 DescrIdentificateurFlexBison  laDescrIdentificateurFlexBison,
                                 DescrSemantiquePTR      lExpression,
                                 DescrSemantiquePTR      laFinExpressionsSequencees );

   void                       TraiterDebutArgument ();
   void                       TraiterFinArgument (DescrSemantiquePTR lArgument);

   void                       TraiterDebutListe ();
   void                       AjouterElementALaListe (DescrSemantiquePTR);
   ValeurListe*               TraiterFinListe ();


   // Interaction entre Analyse Lexicale et Analyse Semantique
   // --------------------------------------------------------

   GenreIdentificateurFlexBison     InteractionLexiqueSemantique (
                                 DescrIdentificateurFlexBison & laDescrIdentificateurFlexBison );


private:

   bool                       fModeDebug;
   bool                       fMontrerLesTerminaux;

   OptionsFlexBisonPTR        fOptionsFlexBison;

   PileDesAppelsPTR           fPileDesAppels;

   std::deque<ListeDescrSemantique*>    fPileDesListes;

   // Variables de communication entre actions semantiques
   // ----------------------------------------------------

   FonctionUtilisateurPTR     fIdentFonction;
                                 // pour EnteteDeFonction et TraiterParametre
   int                        fNumeroDeParametre;
                                 // pour Parametres et TraiterParametre

   }; // AnalyseurListaFlexBison


#endif /* __AnalyseurListaFlexBison__ */

