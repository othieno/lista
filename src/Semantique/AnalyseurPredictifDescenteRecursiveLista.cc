// =========================================================================
// AnalyseurPredictifDescenteRecursiveLista.cc
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#include "AnalyseurPredictifDescenteRecursiveLista.h"

#include "LanguesSyntaxe.h"

#include "AlgebreBooleenne.h"
#include "Arithmetique.h"
#include "ChainesDeCaracteres.h"
#include "Comparaisons.h"
#include "EntreesSorties.h"
#include "Sequencements.h"
#include "Si.h"
#include "Iterations.h"

#include "DecodageDOptionsSemantique.h"


// -------------------------------------------------------------------------
// AnalyseurListaPredictifDescenteRecursive
// -------------------------------------------------------------------------

AnalyseurListaPredictifDescenteRecursive :: AnalyseurListaPredictifDescenteRecursive (
   AnalyseurLexicalLista      * lAnalyseurLexical,
      GenreLectureAuClavier   leGenreLectureAuClavier,
   OptionsSyntaxePTR          lesOptionsSyntaxe,
   OptionsStrategiePTR        lesOptionsStrategie,
   OptionsSemantiquePTR       lesOptionsSemantique,
   OptionsEvaluationPTR       lesOptionsEvaluation
#if defined SYNTHESE_PILUM
,  SynthetiseurPilumListaPTR  leSynthetiseurPilumLista,
   OptionsSynthesePTR         lesOptionsSynthese
#endif /* SYNTHESE_PILUM */
   )
   : AnalyseurSemantiqueLista (
      lesOptionsStrategie,
      lesOptionsSemantique,
      lesOptionsEvaluation
#if defined SYNTHESE_PILUM
   ,  leSynthetiseurPilumLista
#endif /* SYNTHESE_PILUM */
      )
   {
   fAnalyseurLexical = lAnalyseurLexical;
   fGenreLectureAuClavier = leGenreLectureAuClavier;
   fOptionsSyntaxe = lesOptionsSyntaxe;

   fSourceCorrectSyntaxiquement = true;

#if defined SYNTHESE_PILUM
   fOptionsSynthese = lesOptionsSynthese;
#endif /* SYNTHESE_PILUM */

   }  // AnalyseurListaPredictifDescenteRecursive :: AnalyseurListaPredictifDescenteRecursive


// -------------------------------------------------------------------------
// Analyse Syntaxico-Semantique
// -------------------------------------------------------------------------

Chaine
AnalyseurListaPredictifDescenteRecursive :: DescriptionDuTerminalCourant ()
   {
   return
      fAnalyseurLexical -> TerminalSousFormeTextuelle (fTerminalPCourant);
   }

Chaine
AnalyseurListaPredictifDescenteRecursive :: DescriptionDeLaPositionCourante ()
   {
   return fAnalyseurLexical -> DescriptionPositionCourante ();
   }


// -------------------------------------------------------------------------

void
AnalyseurListaPredictifDescenteRecursive :: Programme ()
   {
   do
      {
      switch (fTerminalPCourant)
         {
         case t_INTERROGE :
            Avancer ();
            Evaluation ();
            break;
         case t_IDENT :
            // ne PAS Avancer ();
            DefinitionDeFonction ();
            break;
         default:
            ErreurSyntaxique (
               gLANGUE_Syntaxe ->
                  IdentOuInterrogeAttendu () );
            Avancer ();
         } // switch
      }
   while (fTerminalPCourant != t_FIN);
   }  // AnalyseurListaPredictifDescenteRecursive :: Programme


// -------------------------------------------------------------------------

FonctionUtilisateurPTR
AnalyseurListaPredictifDescenteRecursive :: EnteteDeFonction ()
   {
   Chaine   nomDeLaFonction;

   ++ fCompteurFonctions;

   if (fTerminalPCourant != t_IDENT)
      {
      ErreurSyntaxique (
         gLANGUE_Syntaxe ->
            IdentAttenduCommeNomDeFonction () );
      nomDeLaFonction =
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatNumeroDeFonction (),
            fCompteurFonctions );
      }
   else
      {
      nomDeLaFonction =
         fAnalyseurLexical -> DernierIdentAccepte ();
         // car on ne s'en sert qu'apres
      }

   if (fOptionsSemantique -> Traduire ())
      std::cout << nomDeLaFonction;

   Avancer ();

   DictionnairePTR
            dictionnaireFonction =
               new Dictionnaire (nomDeLaFonction);

   NiveauDeDeclarationPTR
            leNiveauDeDeclaration =
               new NiveauDeDeclaration (dictionnaireFonction);
               // pour les paramtres et idents non dŽclarŽs Žventuels

   VariableLogiqueTypePTR
            leTypeLogiqueFonction =
               new VariableLogiqueType (
                  MiseEnForme (
                     gLANGUE_Semantique ->
                        FormatNomDeFonction (),
                     nomDeLaFonction ));

   if (fOptionsSemantique -> MontrerLInferenceDeType ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatTypeLogiqueDeFonction (),
            leTypeLogiqueFonction -> SousFormeDeChaine (),
            nomDeLaFonction ) <<
         std::endl;

   FonctionUtilisateurPTR
            lIdentFonctionUtilisateur =
               new
                  FonctionUtilisateur (
                     nomDeLaFonction,
                     MiseEnForme (
                        gLANGUE_Semantique ->
                           FormatNomQualifie (),
                        fTableDesSymboles -> Sommet () -> Nom (),
                        nomDeLaFonction ),
                     leTypeLogiqueFonction,
                     dictionnaireFonction );

   bool     dejaPresentAuSommet = false;
   IdentificateurPTR
            autreDeclarationMasquee = NULL;

   fTableDesSymboles ->
      InsererLIdentificateur (
         lIdentFonctionUtilisateur,
         dejaPresentAuSommet,
         autreDeclarationMasquee );

   if (dejaPresentAuSommet)
      ErreurSemantique (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatRedefinitionDeFonctionUtilisateur (),
            nomDeLaFonction ));

   if (autreDeclarationMasquee != NULL)
      AvertissementSemantique (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatDefinitionDeFonctionUtilisateurMasque (),
            lIdentFonctionUtilisateur -> NomQualifie (),
            autreDeclarationMasquee -> SousFormeDeChaine () )
         );

   fTableDesSymboles -> Empiler (leNiveauDeDeclaration);
      // sera dŽsempilŽ par "DefinitionDeFonction ()"

   IncrementerNiveauDEvaluation ();
      // sera decremente par "DefinitionDeFonction ()"
   IncrementerNiveauStatique ();
      // sera decremente par "DefinitionDeFonction ()"

   if (fTerminalPCourant == t_PAR_GAUCHE)
      {
      Avancer ();

      Parametres (lIdentFonctionUtilisateur);

      TesterTerminal (
         t_PAR_DROITE,
         gLANGUE_Syntaxe ->
            ParentheseAttendueApresDesParametres () );
      }

   return lIdentFonctionUtilisateur;
   }  // AnalyseurListaPredictifDescenteRecursive :: EnteteDeFonction


// -------------------------------------------------------------------------

void
AnalyseurListaPredictifDescenteRecursive :: Parametres (FonctionUtilisateurPTR laFonctionUtilisateur)
   {
   int      numeroDeParametre = 0;

   while (true)   // boucle infinie
      {
      ++ numeroDeParametre;

      Chaine   nomDuParametre;

      if (fTerminalPCourant == t_IDENT)
         {
         nomDuParametre =
            fAnalyseurLexical -> DernierIdentAccepte ();
            // car on ne s'en servira qu'apres;
         }
      else
         {
         ErreurSyntaxique (
            gLANGUE_Syntaxe ->
               IdentAttenduCommeParametreDeFonction () );

         nomDuParametre =
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatNumeroDeParametre (),
               numeroDeParametre );

         if (fTerminalPCourant == t_PAR_DROITE)
            break;
         }

      if (fOptionsSemantique -> Traduire ())
         std::cout << nomDuParametre;

      Avancer ();

      VariableLogiqueTypePTR
               leTypeLogiqueParametre =
                  new VariableLogiqueType (
                     MiseEnForme (
                        gLANGUE_Semantique ->
                           FormatNomDeParametre (),
                        nomDuParametre ) );

      if (fOptionsSemantique -> MontrerLInferenceDeType ())
         std::cout <<
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatTypeLogiqueDeParametre (),
               leTypeLogiqueParametre -> SousFormeDeChaine (),
               nomDuParametre ) <<
            std::endl;

      DescrParametrePTR
               laDescrParametre =
                  fOptionsStrategie -> StrategieDEvaluation () ->
                     CreerDescrParametre (
                        laFonctionUtilisateur, numeroDeParametre );

      ParametreFormelPTR
               lIdentParametre =
                  new ParametreFormel (
                     nomDuParametre,
                     MiseEnForme (
                        gLANGUE_Semantique ->
                           FormatNomQualifie (),
                        fTableDesSymboles -> Sommet () -> Nom (),
                        nomDuParametre ),
                     leTypeLogiqueParametre,
                     laDescrParametre,
                     fNiveauDEvaluationCourant );

      // mise a jour
      laDescrParametre -> ParametreFormel (lIdentParametre);

      DictionnairePTR
               dictionnaireFonction =
                  laFonctionUtilisateur -> DictionnaireLocal ();

      if (
         ! dictionnaireFonction ->
            InsererLIdentificateur (lIdentParametre)
         )
         ErreurSemantique (
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatRedefinitionDeParametre (),
               nomDuParametre ));

      DictionnairePTR
               leDictionnaire;
      IdentificateurPTR
               lIdentMasque =
                  fTableDesSymboles ->
                     RechercherLeNom (
                        nomDuParametre, leDictionnaire, true );

      if (lIdentMasque != NULL)
         AvertissementSemantique (
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatDefinitionDeParametreMasque (),
               lIdentParametre -> NomQualifie (),
               lIdentMasque -> SousFormeDeChaine () ));

      laFonctionUtilisateur ->
         LaListeDeParametresFormels () ->
            Ajouter (laDescrParametre);

      if (fTerminalPCourant != t_VIRGULE)
         break;

      Avancer ();
      }  // while
   }  // AnalyseurListaPredictifDescenteRecursive :: Parametres


// -------------------------------------------------------------------------

void
AnalyseurListaPredictifDescenteRecursive :: DefinitionDeFonction ()
   {
   FonctionUtilisateurPTR
            lIdentFonctionUtilisateur = EnteteDeFonction ();

   TesterTerminal (
      t_EGALE,
      gLANGUE_Syntaxe ->
         EgaleAttenduApresEnteteDeFonction () );

   DescrSemantiquePTR
            leGrapheSemantiqueDuCorps = SequenceDExpressions ();

   Chaine   leNomDeLaFonction = lIdentFonctionUtilisateur -> Nom ();
   VariableLogiqueTypePTR
            laVariableLogiqueType =
               lIdentFonctionUtilisateur -> VariableLogiqueType ();

   Chaine   leMessage =
               MiseEnForme (
                  gLANGUE_Semantique ->
                     FormatNomDeFonction (),
                  leNomDeLaFonction );

   TypePTR  typeFonction =
               RecupererLeType (leGrapheSemantiqueDuCorps, leMessage);

   lIdentFonctionUtilisateur -> TypeIdentificateur (typeFonction);
   laVariableLogiqueType -> UnifierValeur (
      typeFonction, fOptionsSemantique -> MontrerLInferenceDeType () );

   ListeDeParametresFormelsPTR
            laListeDeParametresFormels =
               lIdentFonctionUtilisateur ->
                  LaListeDeParametresFormels ();

   RecupererLesTypesDesParametres (
      laListeDeParametresFormels );

   fTableDesSymboles -> Desempiler ();
      // avait ŽtŽ empilŽ par "EnteteDeFonction ()"

   lIdentFonctionUtilisateur ->
      GrapheSemantiqueDuCorps (leGrapheSemantiqueDuCorps);

   if (fOptionsSemantique -> ModeVerbeux ())
      std::cout <<
         std::endl <<
         MiseEnForme (
            gLANGUE_Syntaxe ->
               FormatTraceDUneDefinitionDeFonction (),
            lIdentFonctionUtilisateur -> SousFormeDeChaine () ) <<
         std::endl <<
         std::endl;

   if (fOptionsSemantique -> MontrerLesGraphes ())
      {
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatGrapheSemantiqueDuCoprsDUneFonction (),
            leNomDeLaFonction );
      leGrapheSemantiqueDuCorps -> Ecrire (1);
      std::cout <<
         "-----------------" <<
         std::endl;
      }

   if (fOptionsSemantique -> MontrerLePostfixe ())
      {
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatFormePostfixeeDuCoprsDUneFonction (),
            leNomDeLaFonction );
      leGrapheSemantiqueDuCorps -> PostFixer ();
      std::cout <<
         "-----------------" <<
         std::endl;
      }

#if defined SYNTHESE_PILUM
   fSynthetiseurPilumLista ->
      SynthetiserDefinitionDeFonction (
         lIdentFonctionUtilisateur, leGrapheSemantiqueDuCorps );
#endif /* SYNTHESE_PILUM */

   DecrementerNiveauDEvaluation ();
      // avait ete incremente par "EnteteDeFonction ()"
   DecrementerNiveauStatique ();
      // avait ete incremente par "EnteteDeFonction ()"

   TesterTerminal (
      t_POINT_VIRGULE,
      MiseEnForme (
         gLANGUE_Syntaxe ->
            FormatPointVirguleAttenduApresUneDefinitionDeFonction (),
         leNomDeLaFonction ));

   }  // AnalyseurListaPredictifDescenteRecursive :: DefinitionDeFonction


// -------------------------------------------------------------------------

void
AnalyseurListaPredictifDescenteRecursive :: Evaluation ()
   {
   ++ fCompteurEvaluations;

   NiveauDeDeclarationPTR
            leNiveauDeDeclaration =
               new NiveauDeDeclaration (
                  MiseEnForme (
                     gLANGUE_Semantique ->
                        FormatNumeroDEvaluation (),
                     fCompteurEvaluations ));
               // pour les idents non declares eventuels

   fTableDesSymboles -> Empiler (leNiveauDeDeclaration);

   // t_INTERROGE a ete accepte
   DescrSemantiquePTR
            laSequence = SequenceDExpressions ();

   TypePTR  typeExpression =
               RecupererLeType (
                  laSequence,
                  gLANGUE_Syntaxe ->
                     SequenceDExpressionsAEvaluer () );

   if (fOptionsSemantique -> ModeVerbeux ())
      std::cout <<
         std::endl <<
         MiseEnForme (
            gLANGUE_Syntaxe ->
               FormatTraceDUneEvaluation (),
            typeExpression-> SousFormeDeChaine () ) <<
         std::endl <<
         std::endl;

   if (fOptionsSemantique -> MontrerLesGraphes ())
      {
      std::cout <<
         gLANGUE_Semantique ->
            GrapheSemantiqueDeLaSequenceDExpressionsAEvaluer ();
      laSequence -> Ecrire (1);
      std::cout <<
         "-----------------" <<
         std::endl;
      }

   if (fOptionsSemantique -> MontrerLePostfixe ())
      {
      std::cout <<
         gLANGUE_Semantique ->
            FormePostfixeeDeLaSequenceDExpressionsAEvaluer ();
      laSequence -> PostFixer ();
      std::cout <<
         "-----------------" <<
         std::endl;
      }

   if (fOptionsSemantique -> EvaluerDirectement ())
      {
      ContexteDEvaluation
               unContexteDEvaluationVide (
                  NULL,
                  0,
                  fOptionsEvaluation -> ModeTrace (),
                  fOptionsStrategie -> CourtCircuitLogiquesBinaires (),
                  0,
                  NULL,
                  NULL );

      laSequence -> FaireLEvaluationDirecte (
         & unContexteDEvaluationVide );
      }

#if defined SYNTHESE_PILUM
   fSynthetiseurPilumLista -> SynthetiserEvaluation (laSequence);
#endif /* SYNTHESE_PILUM */

   fTableDesSymboles -> Desempiler (); // leNiveauDeDeclaration

   TesterTerminal (
      t_POINT_VIRGULE,
      gLANGUE_Syntaxe ->
         PointVirguleAttenduApresUneEvaluation ());

   }  // AnalyseurListaPredictifDescenteRecursive :: Evaluation


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: SequenceDExpressions ()
   {
   DescrSemantiquePTR
            res = Expression ();

   if (fTerminalPCourant == t_VIRGULE)
      {
      Avancer (); // on l'accepte

      DescrSemantiquePTR
               operandeDroit = SequenceDExpressions ();

      res =
         new Seq (
            gLANGUE_Semantique ->
               SeqImplicite (),
               res,
               operandeDroit );
      }  // while

   return res;
   }


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: Expression ()
   {
   bool  moinsUnairePresent = false;

   if (fTerminalPCourant == t_MOINS)
      {
      moinsUnairePresent = true;
      Avancer (); // on l'accepte
      }

   DescrSemantiquePTR   exprCourante = Terme ();

   if (moinsUnairePresent)
      {
      TesterLeTypeAttendu (
         gTypeNombre,
         exprCourante -> TypeLogique (),
         gLANGUE_Syntaxe ->
            Terme () );

      exprCourante =
         new MoinsUnaire ("-", exprCourante);
      }

   if (
      fTerminalPCourant == t_PLUS || fTerminalPCourant == t_MOINS
      )
      {
      TesterLeTypeAttendu (
         gTypeNombre,
         exprCourante -> TypeLogique (),
         gLANGUE_Syntaxe ->
            Terme () );

      while (
         fTerminalPCourant == t_PLUS || fTerminalPCourant == t_MOINS
         )
         {
         TerminalP   leTerminalP = fTerminalPCourant;

         Avancer ();

         DescrSemantiquePTR
                  terme2 = Terme ();

         TesterLeTypeAttendu (
            gTypeNombre,
            terme2 -> TypeLogique (),
            gLANGUE_Syntaxe ->
               Terme () );

         switch (leTerminalP)
            {
            case t_PLUS:
               exprCourante =
                  new Plus ("+", exprCourante, terme2);
               break;
            case t_MOINS:
               exprCourante =
                  new Moins ("-", exprCourante, terme2);
               break;
            default:
               ;
            }  // switch
         }  // while
      }  // if

   return exprCourante;
   }  // AnalyseurListaPredictifDescenteRecursive :: Expression


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: Terme ()
   {
   DescrSemantiquePTR
            termeCourant = Facteur ();

   switch (fTerminalPCourant)
      {
      case t_FOIS:
      case t_DIVISE:
         {
         TesterLeTypeAttendu (
            gTypeNombre,
            termeCourant -> TypeLogique (),
            gLANGUE_Syntaxe ->
               Facteur () );

         while (
            fTerminalPCourant == t_FOIS || fTerminalPCourant == t_DIVISE
            )
            {
            TerminalP
                     leTerminalP = fTerminalPCourant;

            Avancer ();

            DescrSemantiquePTR
                     facteur2 = Facteur ();

            TesterLeTypeAttendu (
               gTypeNombre,
               facteur2 -> TypeLogique (),
               gLANGUE_Syntaxe ->
                  Facteur () );

            switch (leTerminalP)
               {
               case t_FOIS:
                  termeCourant =
                     new Fois ("*", termeCourant, facteur2);
                  break;
               case t_DIVISE:
                  termeCourant =
                     new DivisePar ("/", termeCourant, facteur2);
                  break;
               default:
                  ;
               }  // switch
            }  // while
         }
      break;

      case t_CONCAT:
         {
         TesterLeTypeAttendu (
            gTypeChaine,
            termeCourant -> TypeLogique (),
            gLANGUE_Syntaxe ->
               Facteur () );

         while (
            fTerminalPCourant == t_CONCAT
            )
            {
            Avancer ();

            DescrSemantiquePTR
                     facteur2 = Facteur ();

            TesterLeTypeAttendu (
               gTypeChaine,
               facteur2 -> TypeLogique (),
               gLANGUE_Syntaxe ->
                  Facteur () );

            termeCourant =
               new ConcatChaines ("!!", termeCourant, facteur2);
            }  // while
         }
      break;

      default:
         ;
      }  // switch

   return termeCourant;
   }  // AnalyseurListaPredictifDescenteRecursive :: Terme


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: Facteur ()
   {
   switch (fTerminalPCourant)
      {
      case t_NOMBRE:
         Avancer (); // on l'accepte
         return
            new
               ValeurNombre (fAnalyseurLexical -> DernierNombreAccepte ());
         break;

      case t_CHAINE:
         {
         Chaine   laChaine =
                     fAnalyseurLexical -> DerniereChaineAcceptee ();

         Avancer (); // on l'accepte

         while (fTerminalPCourant == t_CHAINE)
            {
            laChaine =
               FConcatChaines (
                  laChaine, fAnalyseurLexical -> DerniereChaineAcceptee () );
            Avancer ();
            }  // while

         return
            new ValeurChaine (laChaine);
         }
         break;

      case t_IDENT:
         return FacteurIdent ();
         break;

      case t_PAR_GAUCHE:
         {
         Avancer ();

         DescrSemantiquePTR
                  res = Expression ();

         TesterTerminal (
            t_PAR_DROITE,
            gLANGUE_Syntaxe ->
               ParentheseAttendueApresExpressionParenthesee () );

         return res;
         }
         break;

      case t_CROCHET_GAUCHE:
      //case t_ACCOLADE_GAUCHE:
         {
         // On retourne la description semantique de la liste en cas d'inference reussie,
         // ou celle d'une valeur inconnue dans le cas contraire.
         return Liste ();
         }

      default:
         ErreurSyntaxique (
            gLANGUE_Syntaxe ->
               FacteurMalForme () );
         Avancer ();
         return gDescrSemantiqueInconnue;

      }  // switch
   }  // AnalyseurListaPredictifDescenteRecursive :: Facteur


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: FacteurIdent ()
   {
   Chaine   nomIdentCourant =
               fAnalyseurLexical -> DernierIdentAccepte ();

   DictionnairePTR
            leDictionnaire;

   IdentificateurPTR
            lIdentificateurCourant =
               fTableDesSymboles ->
                  RechercherLeNom (nomIdentCourant, leDictionnaire, false);

   // seuls les emplois d'identificateurs predefinis peuvent avoir une
   // traduction qui differe de l'original

   if (fOptionsSemantique -> Traduire ())
      {
      if (lIdentificateurCourant != NULL)
         std::cout <<
            lIdentificateurCourant -> Traduction ();
      else
         std::cout << nomIdentCourant;
      }  // if

   if (lIdentificateurCourant == NULL)
      {
      Avancer ();
      AccepterArgumentsSuperflus (kMessageDejaProduit);

      return
         AccepterFacteurIdentificateurInconnu (nomIdentCourant);
      }

   else
      {
      IdentNonDeclarePTR
               lIdentNonDeclare =
                  dynamic_cast <IdentNonDeclarePTR> (lIdentificateurCourant);

      if (lIdentNonDeclare != NULL)
         {
         Avancer ();

         AccepterArgumentsSuperflus (kMessageDejaProduit);

         return
            new ValeurInconnue (
               lIdentNonDeclare -> VariableLogiqueType () );
            // pour permettre l'inference du type
            // de cet identificateur non declare
         }  // if


      ConstantePredefiniePTR
               laConstantePredefinie =
                  dynamic_cast <ConstantePredefiniePTR> (lIdentificateurCourant);

      if (laConstantePredefinie != NULL)
         {
         Avancer ();

         AccepterArgumentsSuperflus (kMessagePasEncoreProduit);

         return
            laConstantePredefinie-> CreerGrapheConstante ();
         }  // if


      FonctionPredefiniePTR
               laFonctionPredefinie =
                  dynamic_cast <FonctionPredefiniePTR> (lIdentificateurCourant);

      if (laFonctionPredefinie != NULL)
         {
         Avancer ();

         return
            AppelFonctionPredefinie (laFonctionPredefinie);
         }  // if


      FonctionUtilisateurPTR
               laFonctionUtilisateur =
                  dynamic_cast <FonctionUtilisateurPTR> (lIdentificateurCourant);

      if (laFonctionUtilisateur != NULL)
         {
         Avancer ();

         return
            AppelFonctionUtilisateur (laFonctionUtilisateur);
         }  // if


      ParametreFormelPTR
               leParametreFormel =
                  dynamic_cast <ParametreFormelPTR> (lIdentificateurCourant);

      if (leParametreFormel != NULL)
         {
         Avancer ();

         AccepterArgumentsSuperflus (kMessagePasEncoreProduit);

         return
            fOptionsStrategie -> StrategieDEvaluation () ->
               CreerEmploiParametre (leParametreFormel);
         }  // if


      IndiceIterationPTR
               lIndiceIteration =
                  dynamic_cast <IndiceIterationPTR> (lIdentificateurCourant);

      if (lIndiceIteration != NULL)
         {
         Avancer ();

         return
            new EmploiIndiceIteration (lIndiceIteration);
         }  // if


      ErreurSemantique (
         gLANGUE_Semantique ->
            FacteurIdentificateurMalForme ());

      Avancer ();

      return gDescrSemantiqueInconnue;

      }  // lIdentificateurCourant != NULL

   return gDescrSemantiqueInconnue; // superflu

   }  // AnalyseurListaPredictifDescenteRecursive :: FacteurIdent


// -------------------------------------------------------------------------

void
AnalyseurListaPredictifDescenteRecursive :: AccepterArgumentsSuperflus (
   StatutMessage leStatutMessage )
   {
   if (fTerminalPCourant == t_PAR_GAUCHE)
      {
      if (leStatutMessage == kMessagePasEncoreProduit)
         ErreurSemantique (
            gLANGUE_Syntaxe ->
               ArgumentsSuperflusPourUneNonFonction () );

      Avancer ();

      Arguments (
         gLANGUE_Syntaxe ->
            ListeDeParametresInconnus (),
         fListeDeParametresFormelsInconnus );

      TesterTerminal (
         t_PAR_DROITE,
         gLANGUE_Syntaxe ->
            ApresUneListeDArgumentsSuperflus () );
      }
   }  // AnalyseurListaPredictifDescenteRecursive :: AccepterArgumentsSuperflus


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: AppelFonctionPredefinie (
   FonctionPredefiniePTR laFonctionPredefinie )
   {
   // IDENT a ete accepte

   GenreFonctionPredefinie
            leGenreFonctionPredefinie     =
               laFonctionPredefinie -> LeGenreFonctionPredefinie ();
   Chaine   leNomDeLaFonctionPredefinie   =
               laFonctionPredefinie -> Nom ();

   TesterTerminal (
      t_PAR_GAUCHE,
      MiseEnForme (
         gLANGUE_Syntaxe ->
            FormatParentheseAttendueAvantUnAppelDeFonctionPredefinie (),
         leNomDeLaFonctionPredefinie ));

   DescrSemantiquePTR   res;

   switch (leGenreFonctionPredefinie)
      {
      case kAutreFonctionPredefinie:
         res = AppelAutreFonctionPredefinie (laFonctionPredefinie);
         break;

      case kSi:
         res = InstrSi (laFonctionPredefinie);
         break;

      case kSequence:
         res = InstrSequence (laFonctionPredefinie);
         break;

      case kFonctionListe:
         res = InstrListe (laFonctionPredefinie);
         break;

      case kIterateur:
         res = InstrIteration (laFonctionPredefinie);
         break;
      }  // switch

   TesterTerminal (
      t_PAR_DROITE,
      MiseEnForme (
         gLANGUE_Syntaxe ->
            FormatParentheseAttendueApresUnAppelDeFonction (),
         leNomDeLaFonctionPredefinie ));

   return res;
   }  // AnalyseurListaPredictifDescenteRecursive :: AppelFonctionPredefinie


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: AppelAutreFonctionPredefinie (
   FonctionPredefiniePTR laFonctionPredefinie )
   {
   int      nombreDeParametres =
               laFonctionPredefinie -> NombreDeParametres ();
   VariableLogiqueTypePTR
            * typesLogiquesDesParametres =
               laFonctionPredefinie -> TypesLogiquesDesParametres ();

   DescrSemantiquePTR
            * blocDArguments =
               // on les initialise a "gDescrSemantiqueInconnue"
               new DescrSemantiquePTR [nombreDeParametres];

   for (int i = 0; i < nombreDeParametres; i ++)
      blocDArguments [i] = gDescrSemantiqueInconnue;

   for (
      int   numeroDArgument = 0;
      numeroDArgument < nombreDeParametres;
      numeroDArgument ++
      )
      {
      DescrSemantiquePTR   lArgument = Expression ();

      TesterLeTypeAttendu (
         typesLogiquesDesParametres [numeroDArgument] ->
            ValeurDeLiaison (),
         lArgument -> TypeLogique (),
         gLANGUE_Syntaxe ->
            Expression () );

      blocDArguments [numeroDArgument] = lArgument;

      if (numeroDArgument == nombreDeParametres - 1)
         break;

      TesterTerminal (
         t_VIRGULE,
         MiseEnForme (
            gLANGUE_Syntaxe ->
               FormatVirguleAttendueApresUnArgumentDAppel (),
            numeroDArgument + 1,
            laFonctionPredefinie -> Nom () )
         );
      }  // for

   return
      laFonctionPredefinie -> CreerGrapheDAppelALaFonction (
         fGenreLectureAuClavier,
         blocDArguments );
   }  // AnalyseurListaPredictifDescenteRecursive :: AppelAutreFonctionPredefinie


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: InstrSi (
   FonctionPredefiniePTR laFonctionPredefinie )
   {
   DescrSemantiquePTR
            condition = Expression ();

   TesterLeTypeAttendu (
      gTypeBooleen,
      condition -> TypeLogique (),
      gLANGUE_Semantique ->
         ConditionDUnSi () );

   TesterTerminal (
      t_VIRGULE,
      gLANGUE_Syntaxe ->
         VirguleAttendueApresConditionDUnSi () );

   DescrSemantiquePTR
            valeurSiVrai = Expression ();

   TesterTerminal (
      t_VIRGULE,
      gLANGUE_Syntaxe ->
         VirguleAttendueApresPartieAlorsDUnSi () );

   DescrSemantiquePTR
            valeurSiFaux = Expression ();

   DescrSemantiquePTR
            * leBlocDArguments =
               // on les initialise a "gDescrSemantiqueInconnue"
               new DescrSemantiquePTR [
                  laFonctionPredefinie -> NombreDeParametres () ];

   leBlocDArguments [0] = condition;
   leBlocDArguments [1] = valeurSiVrai;
   leBlocDArguments [2] = valeurSiFaux;

   return
      laFonctionPredefinie ->
         CreerGrapheDAppelALaFonction (
            kLectureIgnorantLePremierCaractere, leBlocDArguments );
   }  // AnalyseurListaPredictifDescenteRecursive :: InstrSi


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: InstrSequence (
   FonctionPredefiniePTR laFonctionPredefinie )
   {
   DescrSemantiquePTR
            operande1 = Expression ();

   TesterTerminal (
      t_VIRGULE,
      MiseEnForme (
         gLANGUE_Syntaxe ->
            FormatVirguleAttendueDansUneSequence (),
         laFonctionPredefinie -> Nom () )
      );

   DescrSemantiquePTR
            operande2 = SequenceDExpressions ();

   DescrSemantiquePTR
            * leBlocDArguments =
               // on les initialise a "gDescrSemantiqueInconnue"
               new DescrSemantiquePTR [
                  laFonctionPredefinie -> NombreDeParametres () ];

   leBlocDArguments [0] = operande1;
   leBlocDArguments [1] = operande2;

   return
      laFonctionPredefinie ->
         CreerGrapheDAppelALaFonction (
            kLectureIgnorantLePremierCaractere, leBlocDArguments );
   }  // AnalyseurListaPredictifDescenteRecursive :: InstrSequence


// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: InstrIteration (
   FonctionPredefiniePTR laFonctionPredefinie )
   {
   ++ fCompteurIterations;

   IterateurPredefPTR
            lIterateurPredefini=
               IterateurPredefPTR (laFonctionPredefinie);
   Chaine   leNomDeLIterateurPredefini =
               lIterateurPredefini -> Nom ();

   DescrSemantiquePTR
            res = NULL;
   Chaine   nomDeLIndice =
               gLANGUE_Semantique ->
                  IndiceInconnu ();

   if (fTerminalPCourant != t_IDENT)
      ErreurSyntaxique (
         gLANGUE_Semantique ->
            IdentAttenduCommeIndiceDIteration () );
   else
      nomDeLIndice =
         fAnalyseurLexical ->
            DernierIdentAccepte ();
         // car on ne s'en sert qu'apres

   if (fOptionsSemantique -> Traduire ())
      std::cout << nomDeLIndice;

   Avancer ();

   TesterTerminal (
      t_VIRGULE,
      MiseEnForme (
         gLANGUE_Semantique ->
            FormatVirguleAttendueApresLIndice (),
         nomDeLIndice,
         leNomDeLIterateurPredefini ));

   DescrSemantiquePTR
      borneInf = Expression ();

   TesterLeTypeAttendu (
      gTypeNombre,
      borneInf -> TypeLogique (),
      gLANGUE_Semantique ->
         BorneInferieure () );

   TesterTerminal (
      t_VIRGULE,
      MiseEnForme (
         gLANGUE_Semantique ->
            FormatVirguleAttendueApresLaBorneInferieure (),
         nomDeLIndice,
         leNomDeLIterateurPredefini ));

   DescrSemantiquePTR
            borneSup = Expression ();

   TesterLeTypeAttendu (
      gTypeNombre,
      borneSup -> TypeLogique (),
      gLANGUE_Semantique ->
         BorneSuperieure () );

   TesterTerminal (
      t_VIRGULE,
      MiseEnForme (
         gLANGUE_Semantique ->
            FormatVirguleAttendueApresLaBorneSuperieure (),
         nomDeLIndice,
         leNomDeLIterateurPredefini ));


   // on a atteint le point de definition de l'indice

   IncrementerNiveauDEvaluation ();

   NiveauDeDeclarationPTR
            leNiveauDeDeclaration =
               new NiveauDeDeclaration (
                  MiseEnForme (
                     gLANGUE_Semantique ->
                        FormatIteration (),
                     fCompteurIterations ));
               // pour l'indice et les idents non declares eventuels

   fTableDesSymboles -> Empiler (leNiveauDeDeclaration);

   Chaine   nomQualifieDeLIndice =
               MiseEnForme (
                  gLANGUE_Semantique ->
                     FormatNomQualifie (),
                  fTableDesSymboles -> Sommet () -> Nom (),
                  nomDeLIndice );

   IndiceIterationPTR
            lIndice =
               new IndiceIteration (
                  nomDeLIndice,
                  nomQualifieDeLIndice,
                  gTypeLogiqueNombre );

   bool     dejaPresentAuSommet;
   IdentificateurPTR
            autreDeclarationMasquee = NULL;

   fTableDesSymboles ->
      InsererLIdentificateur (
         lIndice,
         dejaPresentAuSommet,
         autreDeclarationMasquee);

   if (dejaPresentAuSommet)
      ErreurSemantique (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatRedefinitionDeLIndiceDIteration (),
            nomDeLIndice ));

   if (autreDeclarationMasquee != NULL)
      AvertissementSemantique (
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatDefinitionDeLIndiceDIterationMasque (),
            nomQualifieDeLIndice,
            autreDeclarationMasquee ->
               SousFormeDeChaine () ));

   DescrSemantiquePTR
            lExpressionIteree = Expression ();

   lIterateurPredefini -> TesterTypeExpressionIteree (
      lExpressionIteree -> TypeLogique () );

   DescrSemantiquePTR
            * leBlocDArguments =
               // on les initialise a "gDescrSemantiqueInconnue"
               new DescrSemantiquePTR [
                  lIterateurPredefini -> NombreDeParametres () ];

   leBlocDArguments [0] = borneInf;
   leBlocDArguments [1] = borneSup;
   leBlocDArguments [2] = lExpressionIteree;

   res =
      lIterateurPredefini ->
         CreerGrapheIteration (lIndice, leBlocDArguments);

   DecrementerNiveauDEvaluation ();

   fTableDesSymboles -> Desempiler (); // leNiveauDeDeclaration

   return res;
   }  // AnalyseurListaPredictifDescenteRecursive :: InstrIteration


// -------------------------------------------------------------------------


DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive::InstrListe( FonctionPredefiniePTR laFonction )
{
   // Les seules fonctions qui concernent les listes et qui soient traitees de maniere speciale
   // sont Cons et Append, i.e. leur premier argument peut etre de type quelconque.
   // L'idee est donc de ne pas mettre de contraintes sur celui-ci mais de quand-meme verifier que
   // le deuxieme argument est bien une liste.

   // Aucune contrainte sur le premier argument, on l'ecrit tout de suite dans le bloc d'arguments.
   DescrSemantiquePTR lOperandeGauche = Expression();

   // Un virgule doit suivre l'argument (puisqu'on est dans le cas d'un operateur binaire).
   TesterTerminal(   t_VIRGULE,
               MiseEnForme(   gLANGUE_Syntaxe -> FormatVirguleAttendueApresUnArgumentDAppel(),
                              1, laFonction -> Nom()
                           )
            );

   // Verifier les contraintes definies pour l'operande droit.
   DescrSemantiquePTR lOperandeDroit = Expression();
   VariableLogiqueTypePTR typeLogiqueOperandeDroit = laFonction -> TypesLogiquesDesParametres()[1];

   TesterLeTypeAttendu (
      typeLogiqueOperandeDroit -> ValeurDeLiaison (),
      lOperandeDroit -> TypeLogique (),
      gLANGUE_Syntaxe -> Expression ()
   );

   DescrSemantiquePTR* leBlocDArguments = new DescrSemantiquePTR[2];
   leBlocDArguments[0] = lOperandeGauche;
   leBlocDArguments[1] = lOperandeDroit;

   // Retourner la description semantique.
   return laFonction->CreerGrapheDAppelALaFonction( fGenreLectureAuClavier, leBlocDArguments );
}

// -------------------------------------------------------------------------

DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: AppelFonctionUtilisateur (
   FonctionUtilisateurPTR laFonctionUtilisateur )
   {
   // IDENT a ete accepte

   Chaine   nomDeLaFonction = laFonctionUtilisateur -> Nom ();
   ListeDeParametresFormelsPTR
            laListeDeParametresFormels =
               laFonctionUtilisateur -> LaListeDeParametresFormels ();

   bool     fonctionParametree =
               ! laListeDeParametresFormels -> Vide ();

   DescrSemantiquePTR
            * blocDArguments = NULL;

   if (fTerminalPCourant == t_PAR_GAUCHE)
      {
      if (! fonctionParametree)
         ErreurSyntaxique (
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatParentheseInattendueDansAppelAFonctionNonParametree (),
                nomDeLaFonction ));

      Avancer ();

      blocDArguments =
         Arguments (
            nomDeLaFonction,
            fonctionParametree
               ?  laListeDeParametresFormels
               :  fListeDeParametresFormelsInconnus );

      if (fTerminalPCourant != t_PAR_DROITE)
         {
         if (fonctionParametree)
            ErreurSyntaxique (
               MiseEnForme (
                  gLANGUE_Syntaxe ->
                     FormatParentheseAttendueApresUnAppelDeFonction (),
                  nomDeLaFonction ));
         }
      else
         Avancer ();
      }  // if

   else
      {
      if (fonctionParametree)
         ErreurSyntaxique (
            MiseEnForme (
               gLANGUE_Syntaxe ->
                  FormatArgumentsAttendusDansAppelDeFonction (),
               nomDeLaFonction ));

      blocDArguments =
         new DescrSemantiquePTR [1];
      blocDArguments [0] =
         gDescrSemantiqueInconnue;
      }

   return
      new
         AppelDeFonctionUtilisateur (
            laFonctionUtilisateur, blocDArguments );
   }  // AnalyseurListaPredictifDescenteRecursive :: AppelFonctionUtilisateur


// -------------------------------------------------------------------------

DescrSemantiquePTR *
AnalyseurListaPredictifDescenteRecursive :: Arguments (
   Chaine   nomDeLaFonction,
   ListeDeParametresFormelsPTR
            laListeDeParametresFormels )
   {
   bool     enCoursDeRattrappage =
               laListeDeParametresFormels
                  ==
               fListeDeParametresFormelsInconnus;

   int      nombreDeParametres =
               laListeDeParametresFormels -> NombreDeParametres ();

   DescrSemantiquePTR
            * blocDArguments =
               new DescrSemantiquePTR [nombreDeParametres];

   StrategieDEvaluationPTR
            laStrategieDEvaluation =
               fOptionsStrategie -> StrategieDEvaluation ();

   ListeDesDescrParametresPTR
            listeDesDescrParametres =
               laListeDeParametresFormels ->
                  LaListeDesDescrParametres ();

   ListeDesDescrParametres :: iterator
            parametreCourant;
   int      numeroDArgument = 0;

   parametreCourant = listeDesDescrParametres -> begin ();

   while (true)   // boucle infinie
      {
      if (parametreCourant == listeDesDescrParametres -> end ())
         {
         ErreurSemantique (
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatTropDArgumentsDansAppelAFonctionParametree (),
               nomDeLaFonction ));

         // on rattrape l'erreur en se raccordant sur
         // la liste circulaire de parametres inconnus

         listeDesDescrParametres =
            fListeDeParametresFormelsInconnus -> LaListeDesDescrParametres ();
         parametreCourant = listeDesDescrParametres -> begin ();
         enCoursDeRattrappage = true;
         }  // if

      bool     besoinDUnLienStatique =
                  laStrategieDEvaluation -> ABesoinDUnLienStatique ();

      if (besoinDUnLienStatique)
         IncrementerNiveauStatique ();

      DescrSemantiquePTR
               lArgument = Expression ();

      if (besoinDUnLienStatique)
         DecrementerNiveauStatique ();

      if (! enCoursDeRattrappage)
         {
         blocDArguments [numeroDArgument ++] = lArgument;

         ParametreFormelPTR
                  leParametreFormel =
                     (* parametreCourant) -> ParametreFormel ();

         VariableLogiqueTypePTR
                  laVariableLogiqueType =
                     leParametreFormel -> VariableLogiqueType ();

         TesterLeTypeAttendu (
            laVariableLogiqueType -> ValeurDeLiaison (),
            lArgument -> TypeLogique (),
            gLANGUE_Semantique ->
               ArgumentDAppel () );
         }  // if

      if (! enCoursDeRattrappage)
         parametreCourant ++;
         // sinon, on reste sur l'inconnu

      if (fTerminalPCourant != t_VIRGULE)
         {
         if (
            ! enCoursDeRattrappage
               &&
            (* parametreCourant)
               ==
            listeDesDescrParametres -> at (nombreDeParametres - 1)
            )
            ErreurSemantique (
               MiseEnForme (
                  gLANGUE_Semantique ->
                     FormatTropPeuDArgumentsDansAppelAFonctionParametree (),
                  nomDeLaFonction,
                  laListeDeParametresFormels ->
                     NomsDesParametres () ));

         while (numeroDArgument < nombreDeParametres)
            // on complete le bloc d'arguments tout de meme!
            blocDArguments [numeroDArgument ++] =
               gDescrSemantiqueInconnue;

         break;
         }  // if

      Avancer (); // on consomme la t_VIRGULE
      }  // while

   return blocDArguments;
   }  // AnalyseurListaPredictifDescenteRecursive :: Arguments


// -------------------------------------------------------------------------


DescrSemantiquePTR
AnalyseurListaPredictifDescenteRecursive :: Liste ()
{
   ListeDescrSemantique    listeDeDescriptionsSemantique;
   DescrSemantiquePTR      descr;

   // Consommer le terminal.
   Avancer();

   // Si le terminal courant est un crochet droit (une liste vide), consomme-le, sinon on traite
   // les elements de la liste.
   if (fTerminalPCourant != t_CROCHET_DROIT)
   {
      while (fTerminalPCourant != t_CROCHET_DROIT && fTerminalPCourant != t_FIN)
      {
         // Obtenir le graphe semantique d'un element de la liste.
         descr = Expression();

         // Ajouter la description semantique a la liste de descriptions.
         listeDeDescriptionsSemantique.push_back( descr );

         // Le terminal qui suit une expression doit etre un nombre. Par consequent, le terminal
         // courant devrait etre une virgule. Si c'est le cas ...
         if (fTerminalPCourant == t_VIRGULE)
         {
            // ... on consomme la virgule.
            Avancer();

            // Et il faut que ce que suit une virgule soit toujours une expression (!), et non
            // pas un crochet droit, ou une point-virgule.
            if (fTerminalPCourant == t_CROCHET_DROIT || fTerminalPCourant == t_POINT_VIRGULE)
            {
               ErreurSyntaxique("Expression attendue apres un ','");
               return gDescrSemantiqueInconnue;
            }
         }
         // Dans le cas ou une virgule ne suit pas l'expression, le terminal courant peut etre
         // un crochet droit. Si ce n'est pas un crochet droit, la structure est fausse.
         else if (fTerminalPCourant != t_VIRGULE && fTerminalPCourant != t_CROCHET_DROIT)
         {
            ErreurSyntaxique("',' ou ']' attendu apres l'expression");
            return gDescrSemantiqueInconnue;
         }
      }
      // Si on quitte la boucle et que le terminal courant ne soit pas un crochet droit, il y a
      // une erreur! On retourne alors la description semantique d'une valeur inconnue
      // (gDescrSemantiqueInconnue).
      if (fTerminalPCourant != t_CROCHET_DROIT)
         return gDescrSemantiqueInconnue;
   }
   // On a atteint le crochet droit. Le crochet est consomme, et la description semantique de la
   // liste retournee.
   Avancer();
   return new ValeurListe( listeDeDescriptionsSemantique );
}


// -------------------------------------------------------------------------


void
AnalyseurListaPredictifDescenteRecursive :: ErreurSyntaxique (Chaine leMessage)
   {
   if (fOptionsSyntaxe -> ModeVerbeux ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Lexique ->
               FormatLocalisationErreur (),
            gLANGUE_Syntaxe ->
               ErreurSyntaxique (),
            leMessage,
            fAnalyseurLexical ->
               TerminalSousFormeTextuelle (fTerminalPCourant),
            fAnalyseurLexical ->
               DescriptionPositionCourante () ) <<
         std::endl <<
         std::endl;
   else
      std::cout <<
         MiseEnForme (
            gLANGUE_Lexique ->
               FormatLocalisationErreurAllege (),
            fAnalyseurLexical ->
               DescriptionPositionCourante (),
            gLANGUE_Syntaxe ->
               ErreurSyntaxique (),
            leMessage,
            fAnalyseurLexical ->
               TerminalSousFormeTextuelle (fTerminalPCourant) ) <<
         std::endl <<
         std::endl;

   fSourceCorrectSyntaxiquement = false;

   if (fOptionsSyntaxe -> RenoncerSurErreurSyntaxique ())
      SortieSurErreur (leMessage, 1);
   }  // AnalyseurListaPredictifDescenteRecursive :: ErreurSyntaxique


// -------------------------------------------------------------------------

void
AnalyseurListaPredictifDescenteRecursive :: TesterTerminal (
   TerminalP   terminalAttendu,
   Chaine      contexte )
   {
   if (fTerminalPCourant != terminalAttendu)
      ErreurSyntaxique (
         contexte ); // le contexte indique le terminal attendu
/* JMI
         MiseEnForme (
            gLANGUE_Syntaxe ->
               FormatTerminalAttendu (),
            fAnalyseurLexical ->
               TerminalSousFormeTextuelle (terminalAttendu),
            contexte ));
*/
   else
      Avancer ();
   }


// -------------------------------------------------------------------------
// AnalyseurListaPredictifDescenteRecursive :: Analyser ()
// -------------------------------------------------------------------------

void
AnalyseurListaPredictifDescenteRecursive :: Analyser ()
   {
   Avancer (); // on amorce la pompe !

   Programme ();

   if (! fOptionsSemantique -> Traduire ())
      {
      if (fAnalyseurLexical -> SourceCorrectLexicalement ())
         std::cout <<
            gLANGUE_Lexique ->
               CodeLexicalementCorrect () <<
            std::endl;
      else
         std::cout <<
            gLANGUE_Lexique -> CodeLexicalementIncorrect () <<
            std::endl;

      if (fSourceCorrectSyntaxiquement)
         std::cout <<
            gLANGUE_Syntaxe ->
               CodeSyntaxiquementCorrect () <<
            std::endl;
      else
         std::cout <<
            gLANGUE_Syntaxe ->
               CodeSyntaxiquementIncorrect () <<
            std::endl;

      if (fSourceCorrectSemantiquement)
         std::cout <<
            gLANGUE_Semantique ->
               CodeSemantiquementCorrect () <<
            std::endl;
      else
         std::cout <<
            gLANGUE_Semantique ->
               CodeSemantiquementIncorrect () <<
            std::endl;
      }  // if
   } // AnalyseurListaPredictifDescenteRecursive :: Analyser


// -------------------------------------------------------------------------
// CompilateurPilumListaPredictifDescenteRecursive
// -------------------------------------------------------------------------

#if defined SYNTHESE_PILUM

CompilateurPilumListaPredictifDescenteRecursive ::
   CompilateurPilumListaPredictifDescenteRecursive (
   AnalyseurLexicalLista   * lAnalyseurLexical,
   GenreLectureAuClavier   leGenreLectureAuClavier,
   OptionsSyntaxePTR       lesOptionsSyntaxe,
   OptionsStrategiePTR     lesOptionsStrategie,
   OptionsSemantiquePTR    lesOptionsSemantique,
   OptionsEvaluationPTR    lesOptionsEvaluation,
   std::ostream            * leFlotTexte,
   std::ofstream           * leFichierBinaire,
   OptionsSynthesePTR      lesOptionsSynthese )
   :  AnalyseurListaPredictifDescenteRecursive (
         lAnalyseurLexical,
         leGenreLectureAuClavier,
         lesOptionsSyntaxe,
         lesOptionsStrategie,
         lesOptionsSemantique,
         lesOptionsEvaluation,
         SynthetiseurPilumListaPTR (this),
         lesOptionsSynthese ),
      SynthetiseurPilumLista (
         gLANGUE_SynthesePilum ->
            NomDuSynthetiseurPilumListaParDefaut (),
         leFlotTexte,
         leFichierBinaire,
         lesOptionsSynthese )
   {
   }  // CompilateurPilumListaPredictifDescenteRecursive :: CompilateurPilumListaPredictifDescenteRecursive


void
CompilateurPilumListaPredictifDescenteRecursive :: Analyser ()
   {
   AnalyseurListaPredictifDescenteRecursive :: Analyser ();

   SynthetiserLEpilogue ();
   FinaliserLaSyntheseDeCode ();

   EcrireSurLeFichierBinaire ();
   }

#endif /* SYNTHESE_PILUM */
