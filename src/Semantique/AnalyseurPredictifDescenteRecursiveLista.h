// =========================================================================
// AnalyseurPredictifDescenteRecursiveLista.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __AnalyseurPredictifDescenteRecursiveLista__
#define __AnalyseurPredictifDescenteRecursiveLista__


#include "AnalyseurDescendantLista.h"

#include "AnalyseurSemantiqueLista.h"


#if defined SYNTHESE_PILUM
   #include "LanguesSynthesePilum.h"

   #include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
// AnalyseurPredictifDescenteRecursiveLista
//    (analyseur syntaxico-sŽmantique en descente recursive)
// -------------------------------------------------------------------------

enum StatutMessage
   { kMessageDejaProduit,     kMessagePasEncoreProduit };


class AnalyseurListaPredictifDescenteRecursive : public AnalyseurSemantiqueLista
   {
public:

                              AnalyseurListaPredictifDescenteRecursive (
                                 AnalyseurLexicalLista   * lAnalyseurLexical,
                                 GenreLectureAuClavier   leGenreLectureAuClavier,
                                 OptionsSyntaxePTR       lesOptionsSyntaxe,
                                 OptionsStrategiePTR     lesOptionsStrategie,
                                 OptionsSemantiquePTR    lesOptionsSemantique,
                                 OptionsEvaluationPTR    lesOptionsEvaluation
#if defined SYNTHESE_PILUM
                              ,  SynthetiseurPilumListaPTR
                                                         leSynthetiseurPilumLista,
                                 OptionsSynthesePTR      lesOptionsSynthese
#endif /* SYNTHESE_PILUM */
                                 );

   Chaine                     DescriptionDuTerminalCourant ();
   Chaine                     DescriptionDeLaPositionCourante ();

#if defined SYNTHESE_PILUM
   OptionsSynthesePTR         OptionsSynthese ();
#endif /* SYNTHESE_PILUM */


   void                       Analyser ();


private:

   // Analyse Lexicale
   // ----------------

   AnalyseurLexicalLista      * fAnalyseurLexical;
   GenreLectureAuClavier      fGenreLectureAuClavier;


   // Analyse Syntaxico-SŽmantique
   // ----------------------------

   OptionsSyntaxePTR          fOptionsSyntaxe;

   TerminalP                  fTerminalPCourant;

   void                       Avancer ();

   void                       Programme ();

   void                       DefinitionDeFonction ();
   void                       Evaluation ();

   FonctionUtilisateurPTR     EnteteDeFonction ();
   void                       Parametres (
                                 FonctionUtilisateurPTR laFonctionUtilisateur );

   DescrSemantiquePTR         SequenceDExpressions ();

   DescrSemantiquePTR         Expression ();
   DescrSemantiquePTR         Terme ();
   DescrSemantiquePTR         Facteur ();
   DescrSemantiquePTR         FacteurIdent ();
   DescrSemantiquePTR         Liste ();
   void                       AccepterArgumentsSuperflus (
                                 StatutMessage leStatutMessage );

   DescrSemantiquePTR         AppelFonctionPredefinie (
                                 FonctionPredefiniePTR laFonctionPredefinie );

   DescrSemantiquePTR         AppelAutreFonctionPredefinie (
                                 FonctionPredefiniePTR laFonctionPredefinie );

   DescrSemantiquePTR         InstrSi (
                                 FonctionPredefiniePTR laFonctionPredefinie );

   DescrSemantiquePTR         InstrSequence (
                                 FonctionPredefiniePTR laFonctionPredefinie );

   DescrSemantiquePTR         InstrIteration (
                                 FonctionPredefiniePTR laFonctionPredefinie );

   DescrSemantiquePTR         InstrListe (
                                 FonctionPredefiniePTR laFonctionPredefinie );

   DescrSemantiquePTR         AppelFonctionUtilisateur (
                                 FonctionUtilisateurPTR laFonctionUtilisateur );

   DescrSemantiquePTR         * Arguments (
                                 Chaine   nomDeLaFonction,
                                 ListeDeParametresFormelsPTR
                                          laListeDeParametresFormels );

   void                       ErreurSyntaxique (Chaine leMessage);

   void                       TesterTerminal (
                                 TerminalP   terminalAttendu,
                                 Chaine      contexte );

   bool                       fSourceCorrectSyntaxiquement;


   // Synthse de code
   // ----------------

#if defined SYNTHESE_PILUM
   OptionsSynthesePTR         fOptionsSynthese;
#endif /* SYNTHESE_PILUM */

   }; // AnalyseurListaPredictifDescenteRecursive


#if defined SYNTHESE_PILUM
inline
OptionsSynthesePTR
AnalyseurListaPredictifDescenteRecursive :: OptionsSynthese ()
   { return fOptionsSynthese; }
#endif /* SYNTHESE_PILUM */


inline
void
AnalyseurListaPredictifDescenteRecursive :: Avancer ()
   {
   fTerminalPCourant = fAnalyseurLexical -> AccepterUnTerminal ();
   }


// -------------------------------------------------------------------------
// CompilateurPilumListaPredictifDescenteRecursive
// -------------------------------------------------------------------------

#if defined SYNTHESE_PILUM

class    CompilateurPilumListaPredictifDescenteRecursive;
typedef  CompilateurPilumListaPredictifDescenteRecursive
            * CompilateurPilumListaPredictifDescenteRecursivePTR;


class CompilateurPilumListaPredictifDescenteRecursive :
   public AnalyseurListaPredictifDescenteRecursive, public SynthetiseurPilumLista
   {
public:

                              CompilateurPilumListaPredictifDescenteRecursive (
                                 AnalyseurLexicalLista   * lAnalyseurLexical,
                                 GenreLectureAuClavier   leGenreLectureAuClavier,
                                 OptionsSyntaxePTR       lesOptionsSyntaxe,
                                 OptionsStrategiePTR     lesOptionsStrategie,
                                 OptionsSemantiquePTR    lesOptionsSemantique,
                                 OptionsEvaluationPTR    lesOptionsEvaluation,
                                 std::ostream            * leFlotTexte,
                                 std::ofstream           * leFichierBinaire,
                                 OptionsSynthesePTR      lesOptionsSynthese );

   void                       Analyser ();


private:

   // Analyse Lexicale
   // ----------------

   AnalyseurLexicalLista      * fAnalyseurLexical;


   }; // CompilateurPilumListaPredictifDescenteRecursive

#endif /* SYNTHESE_PILUM */


#endif /* __AnalyseurPredictifDescenteRecursiveLista__ */
