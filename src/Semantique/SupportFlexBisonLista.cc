// =========================================================================
// SupportFlexBisonLista.cc
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================

#include "SupportCPlusPlus.h"

#include "Langues.h"

#include "LanguesSyntaxe.h"
#include "LanguesSemantique.h"

#include "SupportFlexBison.h"
#include "SupportFlexBisonLista.h"

#include "Semantique.tab.hh"

#include "AnalyseurListaFlexBison.h"

#include <iostream>


#if defined SYNTHESE_PILUM
   #include "SynthesePilum.h"
   #include "SynthesePilumLista.h"
#endif /* SYNTHESE_PILUM */


// -------------------------------------------------------------------------
// Externes synthetises par Flex
// -------------------------------------------------------------------------

extern char                   yytext [];  // pour "ErreurSemantique ()"


// -------------------------------------------------------------------------
// Fonctions et variables globales definies dans la grammaire *.Flex
// -------------------------------------------------------------------------

extern void                   CompterFinDeLigne ();

extern Chaine                 DescriptionPositionCourante ();
extern Chaine                 DescriptionTerminalCourant ();


/* ---------------------------------------------------------------------- */
// DescriptionTerminalCourant
/* ---------------------------------------------------------------------- */

Chaine
DescriptionTerminalCourant ()
   {
   return
      gPremierTerminalDejaAccepte
         ?  TerminalSousFormeTextuelle (gTerminalCourantFlexBison)
         :  (Chaine) "-- Aucun terminal accepte encore --";
   }


/* ---------------------------------------------------------------------- */
// TerminalSousFormeTextuelle
/* ---------------------------------------------------------------------- */

Chaine
TerminalSousFormeTextuelle (TerminalFlexBison leTerminalFlexBison)
   {
   switch (leTerminalFlexBison)
      {
      case t_NOMBRE:
         return
            MiseEnForme (
               "%-10s %*.*f",
               gLANGUE_Lexique ->
                  TerminalFlottant (),
               TailleChampEcritureNombres (),
               NombreDecimalesEcritureNombres (),
               yylval.fNombre );

      case t_CHAINE:
         return
            MiseEnForme (
               "%-10s %s",
               gLANGUE_Lexique ->
                  TerminalChaine (),
               yylval.fChaine );

      case t_SEQUENCEUR:
         return
            MiseEnForme (
               "%-10s %s",
               gLANGUE_Lexique ->
                  TerminalSequenceur (),
               yylval.fDescrIdentificateurFlexBison.fNom);
      case t_ITERATEUR:
         return
            MiseEnForme (
               "%-10s %s",
               gLANGUE_Lexique ->
                  TerminalIterateur (),
               yylval.fDescrIdentificateurFlexBison.fNom );

      case t_IDENT:
         return
            MiseEnForme (
               "%-10s %s",
               gLANGUE_Lexique ->
                  TerminalIdent (),
               yylval.fDescrIdentificateurFlexBison.fNom );

      case t_PAR_GAUCHE:
         return "           (";
      case t_PAR_DROITE:
         return "           )";

      case t_EGALE:
         return "           =";
      case t_VIRGULE:
         return "           ,";

      case t_PLUS:
         return "           +";
      case t_MOINS:
         return "           -";
      case t_FOIS:
         return "           *";
      case t_DIVISE:
         return "           /";
      case t_CONCAT:
         return "           !!";

      case t_POINT_VIRGULE:
         return "           ;";
      case t_INTERROGE:
         return "           ?";

      case t_CROCHET_GAUCHE:
         return "           [";
      case t_CROCHET_DROIT:
         return "           ]";

      default:
         return
            MiseEnForme (
               gLANGUE_Lexique ->
                  FormatTerminalInconnu (),
               yytext );

      }  // switch
   }  // TerminalSousFormeTextuelle


// -------------------------------------------------------------------------
// L'analyseur Lista */
// -------------------------------------------------------------------------

extern AnalyseurListaFlexBisonPTR      gAnalyseurListaFlexBison;


// -------------------------------------------------------------------------
// DescrParametrePredef
// -------------------------------------------------------------------------

DescrParametrePredef :: DescrParametrePredef (
   int                     leNumeroDeParametre )
   :  DescrParametre (leNumeroDeParametre, gStrategieParValeur)
   {}

AssocArgumentParametrePTR
DescrParametrePredef :: CommentEvaluer (
   long                    leNumeroContexte,
   DescrSemantiquePTR      laValeur,
   ContexteDEvaluationPTR  leContexteDEvaluation )
   {
   SortieSurErreur (
      "DescrParametrePredef :: CommentEvaluer ()",
      15 );
   return NULL;   // superflu
   }

int
DescrParametrePredef :: TailleEnMemoire ()
   {
   SortieSurErreur (
      "DescrParametrePredef :: TailleEnMemoire ()",
      16 );
   return 0;   // superflu
   }


#if defined SYNTHESE_PILUM

void
DescrParametrePredef :: Synthetiser (
   ContexteDeSynthesePTR   leContexteDeSynthese,
   DescrSemantiquePTR      lArgumentDAppel )
   {
   SortieSurErreur (
      "DescrParametrePredef :: Synthetiser ()",
      17);
   }

#endif /* SYNTHESE_PILUM */

// -------------------------------------------------------------------------
// DescrAppelFonction
// -------------------------------------------------------------------------

DescrAppelFonction :: DescrAppelFonction (
   Chaine   leNom,
   int      leNombreDeParametres )
   {
   fNom = leNom;
   fNombreDeParametres = leNombreDeParametres;

   fBlocDArguments = // on les initialise a "gDescrSemantiqueInconnue"
      new DescrSemantiquePTR [fNombreDeParametres];

   for (int i = 0; i < fNombreDeParametres; i ++)
      fBlocDArguments [i] = gDescrSemantiqueInconnue;

   fNumeroDArgument = 0;

   fEnCoursDeRattrapage = false;
   }  // DescrAppelFonction :: DescrAppelFonction

DescrAppelFonction :: ~ DescrAppelFonction ()
   {}


Chaine
DescrAppelFonction :: Nom ()
   { return fNom; }

int
DescrAppelFonction :: NombreDeParametres ()
   { return fNombreDeParametres; }


// -------------------------------------------------------------------------
// DescrAppelFonctionPredefinie
// -------------------------------------------------------------------------

DescrAppelFonctionPredefinie :: DescrAppelFonctionPredefinie (
   FonctionPredefiniePTR laFonctionPredefinie )
   : DescrAppelFonction (
      laFonctionPredefinie -> Nom (),
      laFonctionPredefinie -> NombreDeParametres ()
      )
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatCreationDescrAppelDeFonctionPredefinie (),
            laFonctionPredefinie -> Nom (),
            laFonctionPredefinie -> NombreDeParametres () ) <<
         std::endl;

   fFonctionPredefinie = laFonctionPredefinie;
   }

DescrAppelFonctionPredefinie :: ~ DescrAppelFonctionPredefinie ()
   {}


FonctionPredefiniePTR
DescrAppelFonctionPredefinie :: FonctionPredefinie ()
   { return fFonctionPredefinie; }


void
DescrAppelFonctionPredefinie :: EnregistrerArgument (
   DescrSemantiquePTR lArgument )
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatEnregistrementArgumentDeFonctionPredefinie (),
            fNumeroDArgument,
            fFonctionPredefinie -> Nom () ) <<
         std::endl;

   if (! fEnCoursDeRattrapage)
      {
      VariableLogiqueTypePTR
               laVariableLogiqueType = fFonctionPredefinie ->
                  TypesLogiquesDesParametres () [fNumeroDArgument];

      fBlocDArguments [fNumeroDArgument ++] = lArgument;

      if (laVariableLogiqueType != gTypeLogiqueNonPrecise)
         gAnalyseurSemantiqueLista ->
            TesterLeTypeAttendu (
               laVariableLogiqueType -> ValeurDeLiaison (),
               lArgument -> TypeLogique (),
               gLANGUE_Semantique ->
                  ArgumentDAppel () );
      // Pour "Si", le controle sera fait dans CreerGrapheSemantique ()

      }  // if
   }  // DescrAppelFonctionPredefinie :: EnregistrerArgument


void
DescrAppelFonctionPredefinie :: VerifierSiPasTropDArguments ()
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatVerifierSiPasTropDArgumentsPourFonctionPredefinie (),
            fNumeroDArgument,
            fFonctionPredefinie -> Nom ()) <<
         std::endl;

   if (fNumeroDArgument >= fNombreDeParametres)
      {
      gAnalyseurSemantiqueLista ->
         ErreurSemantique (
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatTropDArgumentsDansAppelAPredefinie (),
               fFonctionPredefinie -> Nom () ));

      DebutRattrappage ();
      }  // if
   }  // DescrAppelFonctionPredefinie :: VerifierSiPasTropDArguments


void
DescrAppelFonctionPredefinie :: VerifierSiAssezDArguments ()
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatVerifierSiAssezDArgumentsPourFonctionPredefinie (),
            fNumeroDArgument,
            fFonctionPredefinie -> Nom () ) <<
         std::endl;

   Chaine   leNomDeLaFonction =
               fFonctionPredefinie -> Nom ();

   if (
      fNumeroDArgument < fNombreDeParametres
         &&
      ! fEnCoursDeRattrapage
      )
      gAnalyseurSemantiqueLista ->
         ErreurSemantique (
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatTropPeuDArgumentsDansAppelAPredefinie (),
               leNomDeLaFonction ));

   while (fNumeroDArgument < fNombreDeParametres)
      // on complte le bloc d'arguments tout de mme!
      fBlocDArguments [fNumeroDArgument ++] = gDescrSemantiqueInconnue;

   }  // DescrAppelFonctionPredefinie :: VerifierSiAssezDArguments


void
DescrAppelFonctionPredefinie :: DebutRattrappage ()
   {  fEnCoursDeRattrapage = true; }


DescrSemantiquePTR
DescrAppelFonctionPredefinie :: CreerGrapheSemantique ()
   {
   return
      fFonctionPredefinie ->
         CreerGrapheDAppelALaFonction (
            kLectureSansAutre, fBlocDArguments );
   }  // DescrAppelFonctionPredefinie :: CreerGrapheSemantique


// -------------------------------------------------------------------------
// DescrAppelIteration
// -------------------------------------------------------------------------

DescrAppelIteration :: DescrAppelIteration (
   FonctionPredefiniePTR   laFonctionPredefinie )
   : DescrAppelFonctionPredefinie (laFonctionPredefinie)
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatCreationDescrAppelIteration (),
            laFonctionPredefinie -> Nom () ) <<
         std::endl;

   fIndice = NULL;
   }  // DescrAppelIteration :: DescrAppelIteration

DescrAppelIteration :: ~ DescrAppelIteration ()
   {}


IndiceIterationPTR
DescrAppelIteration :: EnregistrerIndice (
   IndiceIterationPTR lIndice )
   {
   fIndice = lIndice;
   return NULL;   // superflu
   }


void
DescrAppelIteration :: EnregistrerBorneInf (
   DescrSemantiquePTR laBorneInf )
   {
   gAnalyseurSemantiqueLista ->
      TesterLeTypeAttendu (
         gTypeNombre,
         laBorneInf -> TypeLogique (),
         gLANGUE_Semantique ->
            BorneInferieure () );
   fBlocDArguments [0] = laBorneInf;
   }


void
DescrAppelIteration :: EnregistrerBorneSup (
   DescrSemantiquePTR laBorneSup )
   {
   gAnalyseurSemantiqueLista ->
      TesterLeTypeAttendu (
         gTypeNombre,
         laBorneSup -> TypeLogique (),
         gLANGUE_Semantique ->
            BorneSuperieure () );
   fBlocDArguments [1] = laBorneSup;
   }


void
DescrAppelIteration :: EnregistrerExprIteree (
   DescrSemantiquePTR lExpression )
   {
   IterateurPredefPTR (fFonctionPredefinie) ->
      TesterTypeExpressionIteree (lExpression -> TypeLogique ());

   fBlocDArguments [2] = lExpression;
   }  // DescrAppelIteration :: EnregistrerExprIteree


DescrSemantiquePTR
DescrAppelIteration :: CreerGrapheSemantique ()
   {
   return
      IterateurPredefPTR (fFonctionPredefinie) ->
         CreerGrapheIteration (fIndice, fBlocDArguments);
   }  // DescrAppelIteration :: CreerGrapheSemantique


// -------------------------------------------------------------------------
// DescrAppelFonctionUtilisateur
// -------------------------------------------------------------------------

DescrAppelFonctionUtilisateur :: DescrAppelFonctionUtilisateur (
   FonctionUtilisateurPTR laFonctionUtilisateur )
   : DescrAppelFonction (
      laFonctionUtilisateur -> Nom (),
      laFonctionUtilisateur ->
         LaListeDeParametresFormels () -> NombreDeParametres () )
   {
   fFonctionUtilisateur = laFonctionUtilisateur;

   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatCreationDescrAppelFonctionUtilisateur (),
            fFonctionUtilisateur -> Nom () ) <<
         std::endl;

   ListeDeParametresFormelsPTR
            laListeDeParametresFormels =
               fFonctionUtilisateur -> LaListeDeParametresFormels ();

   fListeDesDescrParametres =
      laListeDeParametresFormels -> LaListeDesDescrParametres ();
   fParametreCourant =
      fListeDesDescrParametres -> begin ();

   fEnCoursDeRattrapage =
      laListeDeParametresFormels
         ==
      gAnalyseurSemantiqueLista -> ListeDeParametresFormelsInconnus ();
   }

DescrAppelFonctionUtilisateur :: ~ DescrAppelFonctionUtilisateur ()
   {}


FonctionUtilisateurPTR
DescrAppelFonctionUtilisateur :: LaFonctionUtilisateur ()
   { return fFonctionUtilisateur; }


void
DescrAppelFonctionUtilisateur :: EnregistrerArgument (
   DescrSemantiquePTR lArgument )
   {
   if (! fEnCoursDeRattrapage)
      {
      fBlocDArguments [fNumeroDArgument ++] = lArgument;

      ParametreFormelPTR
               leParametreFormel =
                  (* fParametreCourant) -> ParametreFormel ();

      VariableLogiqueTypePTR
               laVariableLogiqueType =
                  leParametreFormel -> VariableLogiqueType ();

      gAnalyseurSemantiqueLista ->
         TesterLeTypeAttendu (
            laVariableLogiqueType -> ValeurDeLiaison (),
            lArgument -> TypeLogique (),
            gLANGUE_Semantique ->
               ArgumentDAppel () );
      }  // if

   if (! fEnCoursDeRattrapage)
      fParametreCourant ++;
      // sinon, on reste sur l'inconnu
   }  // DescrAppelFonctionUtilisateur :: EnregistrerArgument


void
DescrAppelFonctionUtilisateur :: VerifierSiPasTropDArguments ()
   {
   Chaine   nomDeLaFonction   = fFonctionUtilisateur -> Nom ();

   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatVerifierSiPasTropDArgumentsPourFonctionUtilisateur (),
            fNumeroDArgument,
            nomDeLaFonction ) <<
         std::endl;

   ListeDeParametresFormelsPTR
            laListeDeParametresFormels =
               fFonctionUtilisateur -> LaListeDeParametresFormels ();

   if (
      fParametreCourant
         ==
      laListeDeParametresFormels -> LaListeDesDescrParametres () -> end ()
      )
      {
      gAnalyseurSemantiqueLista ->
         ErreurSemantique (
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatTropDArgumentsDansAppelAFonctionParametree (),
               nomDeLaFonction ));

      // on rattrape l'erreur en se raccordant sur
      // la liste circulaire de parametres inconnus

      DebutRattrappage ();
      }  // if
   }  // DescrAppelFonctionUtilisateur :: VerifierSiPasTropDArguments

void
DescrAppelFonctionUtilisateur :: VerifierSiAssezDArguments ()
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatVerifierSiAssezDArgumentsPourFonctionUtilisateur (),
            fNumeroDArgument,
            fFonctionUtilisateur -> Nom () ) <<
         std::endl;

   ListeDeParametresFormelsPTR
            laListeDeParametresFormels =
               fFonctionUtilisateur -> LaListeDeParametresFormels ();
   int      nombreDeParametres =
               laListeDeParametresFormels -> NombreDeParametres ();

   if (
      ! fEnCoursDeRattrapage
         &&
      nombreDeParametres > 0
         &&
      (
      (* fParametreCourant)
         ==
      laListeDeParametresFormels ->
         LaListeDesDescrParametres () -> at (nombreDeParametres - 1)
      )
      )
      gAnalyseurSemantiqueLista ->
         ErreurSemantique (
            MiseEnForme (
               gLANGUE_Semantique ->
                  FormatTropPeuDArgumentsDansAppelAFonctionParametree (),
               fFonctionUtilisateur -> Nom (),
               fFonctionUtilisateur ->
                  LaListeDeParametresFormels () ->
                     NomsDesParametres () ));

   while (fNumeroDArgument < fNombreDeParametres)
      // on complte le bloc d'arguments tout de mme!
      fBlocDArguments [fNumeroDArgument ++] =
         gDescrSemantiqueInconnue;

   }  // DescrAppelFonctionUtilisateur :: VerifierSiAssezDArguments


void
DescrAppelFonctionUtilisateur :: DebutRattrappage ()
   {
   fListeDesDescrParametres =
      gAnalyseurSemantiqueLista ->
         ListeDeParametresFormelsInconnus () ->
            LaListeDesDescrParametres ();
   fParametreCourant =
      fListeDesDescrParametres -> begin ();

   fEnCoursDeRattrapage = true;
   }


DescrSemantiquePTR
DescrAppelFonctionUtilisateur :: CreerGrapheSemantique ()
   {
   return
      new AppelDeFonctionUtilisateur (
         fFonctionUtilisateur, fBlocDArguments );
   }


// -------------------------------------------------------------------------
// DescrAppelFonctionErronee
// -------------------------------------------------------------------------

DescrAppelFonctionErronee :: DescrAppelFonctionErronee (
   IdentificateurPTR lIdentificateur )
   : DescrAppelFonction (lIdentificateur -> Nom (), 1)
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatCreationDescrAppelFonctionErronee (),
            lIdentificateur -> Nom () ) <<
         std::endl;

   fIdentificateur = lIdentificateur;
   }

DescrAppelFonctionErronee :: ~ DescrAppelFonctionErronee ()
   {}


void
DescrAppelFonctionErronee :: EnregistrerArgument (
   DescrSemantiquePTR lArgument )
   {}


void
DescrAppelFonctionErronee :: VerifierSiPasTropDArguments ()
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         "DescrAppelFonctionErronee :: VerifierSiPasTropDArguments" <<
         std::endl;
   }

void
DescrAppelFonctionErronee :: VerifierSiAssezDArguments ()
   {
   if (gAnalyseurListaFlexBison -> ModeDebug ())
      std::cout <<
         "DescrAppelFonctionErronee :: VerifierSiAssezDArguments" <<
         std::endl;
   }

void
DescrAppelFonctionErronee :: DebutRattrappage ()
   {}

DescrSemantiquePTR
DescrAppelFonctionErronee :: CreerGrapheSemantique ()
   {
   return
      new ValeurInconnue (fIdentificateur -> VariableLogiqueType ());
      // pour permettre l'inference du type
      // de cet identificateur non declare
   }


// -------------------------------------------------------------------------
// PileDesAppels
// -------------------------------------------------------------------------

PileDesAppels :: PileDesAppels ()
   {
   fPileDesDescrAppelFonction = new PileDesDescrAppelFonction;
   }

PileDesAppels :: ~ PileDesAppels ()
   {}

void
PileDesAppels :: Empiler (DescrAppelFonctionPTR leDescrAppelFonction)
   {
   if (gAnalyseurListaFlexBison -> OptionsFlexBison () -> MontrerLesAppelsImbriques ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatEmpilageDescrAppelDeFonction (),
            leDescrAppelFonction -> Nom () ) <<
         std::endl;

   fPileDesDescrAppelFonction -> push_front (leDescrAppelFonction);
   }

DescrAppelFonctionPTR
PileDesAppels :: Sommet ()
   { return fPileDesDescrAppelFonction -> front (); }

DescrAppelFonctionPTR
PileDesAppels :: Desempiler ()
   {
   DescrAppelFonctionPTR
            res = fPileDesDescrAppelFonction -> front ();

   if (gAnalyseurListaFlexBison -> OptionsFlexBison () -> MontrerLesAppelsImbriques ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Semantique ->
               FormatDesempilageDescrAppelDeFonction (),
            res -> Nom () ) <<
         std::endl;

   fPileDesDescrAppelFonction -> pop_front ();

   return res;
   }


// -------------------------------------------------------------------------
// OptionsFlexBison
// -------------------------------------------------------------------------

OptionsFlexBison :: OptionsFlexBison (
   bool     modeVerbeux,
   bool     leMontrerLesAppelsImbriques )
   {
   fModeVerbeux = modeVerbeux;

   fMontrerLesAppelsImbriques = leMontrerLesAppelsImbriques;
   }

bool
OptionsFlexBison :: ModeVerbeux ()
   { return fModeVerbeux; }

bool
OptionsFlexBison :: MontrerLesAppelsImbriques ()
   { return fMontrerLesAppelsImbriques; }


/* ---------------------------------------------------------------------- */
/* Variables globales */
/* ---------------------------------------------------------------------- */

TerminalFlexBison             gTerminalCourantFlexBison;

bool                          gTraduire;
