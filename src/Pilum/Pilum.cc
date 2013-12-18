// =========================================================================
// Pilum.cc
//  J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#include "Pilum.h"

#include "LanguesPilum.h"

#include <iostream>
#include <cmath>     // for "fabs ()" and the like

#include <cstdlib>

#include <cstring>


// -------------------------------------------------------------------------
// Les valeurs manipulŽes par la machine Pilum
// -------------------------------------------------------------------------

ValeurPilum :: ValeurPilum ()
   { fTypeValeurPilum = kValeurInconnue; }



// -------------------------------------------------------------------------

Chaine
ValeurPilum :: TypeSousFormeDeChaine ()
   {
   switch (fTypeValeurPilum)
      {
      case kValeurInconnue:
         return gLANGUE_Pilum -> ValeurInconnue ();

      case kLienDynamique:
         return gLANGUE_Pilum -> LienDynamique ();
      case kLienStatique:
         return gLANGUE_Pilum -> LienStatique ();

      case kAdresseDeRetour:
         return gLANGUE_Pilum -> AdresseDeRetour ();
      case kAdresseThunk:
         return gLANGUE_Pilum -> AdresseThunk ();
      case kLienStatiqueFutur:
         return gLANGUE_Pilum -> LienStatiqueFutur ();

      case kAdresseDansLaPile:
         return gLANGUE_Pilum -> AdresseDansLaPile ();

      case kEntier:
         return gLANGUE_Pilum -> Entier ();
      case kFlottant:
         return gLANGUE_Pilum -> Flottant ();
      case kBooleen:
         return gLANGUE_Pilum -> Booleen ();
      case kCaractere:
         return gLANGUE_Pilum -> Caractere ();
      case kChaine:
         return gLANGUE_Pilum -> Chaine_ ();

      case kMarqueBlocDActivationDeFonction:
         return gLANGUE_Pilum -> MarqueBlocDActivationDeFonction ();
      case kMarqueBlocDActivationDeThunk:
         return gLANGUE_Pilum -> MarqueBlocDActivationDeThunk ();

      case kListe:
         return "TypeListe";

      default:
         SortieSurErreur (
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatTypeValeurPilumInconnu (),
               fTypeValeurPilum ),
            1 );
         return "???";  // superflu
      }  // switch
   }  // ValeurPilum :: TypeSousFormeDeChaine


// -------------------------------------------------------------------------

int
ValeurPilum :: CommeEntier ()
   {
   switch (fTypeValeurPilum)
      {
      case kEntier :
         return fEntier;
         break;


      default :
         SortieSurErreur (
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatCommeEntier (),
               TypeSousFormeDeChaine () ),
            1 );
         return  0;  // superflu
      }  // switch
   }  // ValeurPilum :: CommeEntier ()

double
ValeurPilum :: CommeFlottant ()
   {
   switch (fTypeValeurPilum)
      {
      case kFlottant :
         return fFlottant;
         break;


      default :
         SortieSurErreur (
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatCommeFlottant (),
               TypeSousFormeDeChaine () ),
            1 );
         return 0.0; // superflu
      }  // switch
   }  // ValeurPilum :: CommeFlottant ()

bool
ValeurPilum :: CommeBooleen ()
   {
   switch (fTypeValeurPilum)
      {
      case kBooleen :
         return fBooleen;
         break;


      default :
         SortieSurErreur (
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatCommeBooleen (),
               TypeSousFormeDeChaine () ),
            1 );
         return false;  // superflu
      }  // switch
   }  // ValeurPilum :: CommeBooleen ()

CharPTR
ValeurPilum :: CommeChaine ()
   {
   switch (fTypeValeurPilum)
      {
      case kChaine :
         return fChaine;
         break;


      default :
         SortieSurErreur (
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatCommeChaine (),
               TypeSousFormeDeChaine () ),
            1 );
         return false;  // superflu
      }  // switch
   }  // ValeurPilum :: CommeChaine ()

ListePTR
ValeurPilum :: CommeListe ()
   {
   switch (fTypeValeurPilum)
      {
      case kListe:
         return fListe;

      default :
         SortieSurErreur (
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatCommeChaine (),      // Valable pour cette fonction aussi.
               TypeSousFormeDeChaine () ),
            1 );
         return false;  // superflu
      }  // switch
   }  // ValeurPilum :: CommeListe ()


// -------------------------------------------------------------------------

Chaine
ValeurPilum :: SousFormeDeChaine ()
   {
   switch (fTypeValeurPilum)
      {
      case kValeurInconnue:
         return
            gLANGUE_Pilum ->
               FormatValeurInconnue ();
         break;

      case kLienDynamique:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatLienDynamique (),
               fAdresseDansLeCode );
         break;
      case kLienStatique:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatLienStatique (),
               fAdresseDansLeCode );
         break;
      case kAdresseDeRetour:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatAdresseDeRetour (),
               fAdresseDansLeCode );
         break;

      case kAdresseThunk:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatAdresseThunk (),
               fAdresseDansLeCode );
         break;
      case kLienStatiqueFutur :
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatLienStatiqueFutur (),
               fAdresseDansLeCode );
         break;

      case kAdresseDansLaPile:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatAdresseDansLaPile (),
               fAdresseDansLaPile );
         break;

      case kEntier:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatEntier (),
               fEntier );
         break;
      case kFlottant:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatFlottant (),
               gLANGUE_Pilum ->
                  Flottant (),
               TailleChampEcritureNombres (),
               NombreDecimalesEcritureNombres (),
               fFlottant );
         break;
      case kBooleen:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatBooleen (),
               fBooleen
                  ?  gLANGUE_Pilum ->
                        Vrai ()
                  :  gLANGUE_Pilum ->
                        Faux () );
         break;
      case kCaractere:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatCaractere (),
               fCaractere );
         break;
      case kChaine:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatChaine (),
               fChaine );
         break;

      case kMarqueBlocDActivationDeFonction:
         {
         Chaine   modeleDeMarque =
                     gLANGUE_Pilum ->
                        ModeleMarqueBlocDActivation ();
         Chaine   laChaine =
                     MiseEnForme (
                        gLANGUE_Pilum ->
                           FormatBlocDActivationPourFonction (),
                        fChaine );
         int      longueurChaine = laChaine.length ();

         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatMarqueBlocDActivation (),
               modeleDeMarque.substr (longueurChaine),
                  // pour avoir une longueur totale fixe
               longueurChaine,
               laChaine );
         }
         break;
      case kMarqueBlocDActivationDeThunk:
         {
         Chaine   modeleDeMarque =
                     gLANGUE_Pilum ->
                        ModeleMarqueBlocDActivation ();
         Chaine   laChaine =
                     MiseEnForme (
                        gLANGUE_Pilum ->
                           FormatBlocDActivationPourThunk (),
                        fChaine );
         int      longueurChaine = laChaine.length ();

         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatMarqueBlocDActivation (),
               modeleDeMarque.substr (longueurChaine),
                  // pour avoir une longueur totale fixe
               longueurChaine,
               laChaine );
         }
         break;

      case kListe:
         return MiseEnForme( "%s", fListe->str() );

      default:
         return
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatTypeValeurPilumInconnu (),
               fTypeValeurPilum );
      }  // switch

   return "";  // superflu
   }  // ValeurPilum :: SousFormeDeChaine


// -------------------------------------------------------------------------
// Les instructions de la machine Pilum
// -------------------------------------------------------------------------

InstructionPilum :: InstructionPilum ()
   { fCodeOpPilum = iInstructionInconnue; }


// -------------------------------------------------------------------------

Chaine
InstructionPilum :: CodesOpSousFormeDeChaine ()
   {
   switch (fCodeOpPilum)
      {
      case iInstructionInconnue:
         return gLANGUE_Pilum -> InstructionInconnue ();

      case iHalte:
         return gLANGUE_Pilum -> Halte ();

      case iCommentaire:
         return gLANGUE_Pilum -> Commentaire ();

      case iEmpilerMarqueBlocDActivation:
         return gLANGUE_Pilum -> EmpilerMarqueBlocDActivation ();

      case iReserver:
         return gLANGUE_Pilum -> Reserver ();
      case iDesempiler:
         return gLANGUE_Pilum -> Desempiler ();
      case iStocker:
         return gLANGUE_Pilum -> Stocker ();
      case iDupliquer:
         return gLANGUE_Pilum -> Dupliquer ();

      case iEmpilerValeur:
         return gLANGUE_Pilum -> EmpilerValeur ();
      case iEmpilerAdresse:
         return gLANGUE_Pilum -> EmpilerAdresse ();
      case iEmpilerLienStatique:
         return gLANGUE_Pilum -> EmpilerLienStatique ();
      case iEmpilerEntier:
         return gLANGUE_Pilum -> EmpilerEntier ();
      case iEmpilerFlottant:
         return gLANGUE_Pilum -> EmpilerFlottant ();
      case iEmpilerBooleen:
         return gLANGUE_Pilum -> EmpilerBooleen ();
      case iEmpilerCaractere:
         return gLANGUE_Pilum -> EmpilerCaractere ();
      case iEmpilerChaine:
         return gLANGUE_Pilum -> EmpilerChaine ();
      case iEmpilerValInconnue:
         return gLANGUE_Pilum -> EmpilerValInconnue ();

      case iSauter:
         return gLANGUE_Pilum -> Sauter ();
      case iSauterSiFaux:
         return gLANGUE_Pilum -> SauterSiFaux ();
      case iAppel:
         return gLANGUE_Pilum -> Appel ();
      case iRetourDeFonction:
         return gLANGUE_Pilum -> RetourDeFonction ();
      case iRetourDeProcedure:
         return gLANGUE_Pilum -> RetourDeProcedure ();
      case iEmpilerDescripteurDeThunk:
         return gLANGUE_Pilum -> EmpilerDescripteurDeThunk ();
      case iEvaluerThunk:
         return gLANGUE_Pilum -> EvaluerThunk ();
      case iEvaluerThunkAvecMarqueBlocDActivation:
         return gLANGUE_Pilum -> EvaluerThunkAvecMarqueBlocDActivation ();

      case iLireEntier:
         return gLANGUE_Pilum -> LireEntier ();
      case iLireFlottant:
         return gLANGUE_Pilum -> LireFlottant ();
      case iLireBooleen:
         return gLANGUE_Pilum -> LireBooleen ();
      case iLireCaractere:
         return gLANGUE_Pilum -> LireCaractere ();
      case iLireChaine:
         return gLANGUE_Pilum -> LireChaine ();
      case iEcrireEntier:
         return gLANGUE_Pilum -> EcrireEntier ();
      case iEcrireFlottant:
         return gLANGUE_Pilum -> EcrireFlottant ();
      case iEcrireBooleen:
         return gLANGUE_Pilum -> EcrireBooleen ();
      case iEcrireCaractere:
         return gLANGUE_Pilum -> EcrireCaractere ();
      case iEcrireChaine:
         return gLANGUE_Pilum -> EcrireChaine ();
      case iEcrireFinDeLigne:
         return gLANGUE_Pilum -> EcrireFinDeLigne ();

      case iIncrEntier:
         return gLANGUE_Pilum -> IncrEntier ();
      case iDecrEntier:
         return gLANGUE_Pilum -> DecrEntier ();
      case iIncrFlottant:
         return gLANGUE_Pilum -> IncrFlottant ();
      case iDecrFlottant:
         return gLANGUE_Pilum -> DecrFlottant ();
      case iMoins1Entier:
         return gLANGUE_Pilum -> Moins1Entier ();
      case iMoins1Flottant:
         return gLANGUE_Pilum -> Moins1Flottant ();


      case iAbsEntier:
         return gLANGUE_Pilum -> AbsEntier ();
      case iAbsFlottant:
         return gLANGUE_Pilum -> AbsFlottant ();
      case iPair:
         return gLANGUE_Pilum -> Pair ();

      case iPlusEntier:
         return gLANGUE_Pilum -> PlusEntier ();
      case iMoinsEntier:
         return gLANGUE_Pilum -> MoinsEntier ();
      case iFoisEntier:
         return gLANGUE_Pilum -> FoisEntier ();
      case iDiviseEntier:
         return gLANGUE_Pilum -> DiviseEntier ();
      case iModuloEntier:
         return gLANGUE_Pilum -> ModuloEntier ();
      case iPlusFlottant:
         return gLANGUE_Pilum -> PlusFlottant ();
      case iMoinsFlottant:
         return gLANGUE_Pilum -> MoinsFlottant ();
      case iFoisFlottant:
         return gLANGUE_Pilum -> FoisFlottant ();
      case iDiviseFlottant:
         return gLANGUE_Pilum -> DiviseFlottant ();

      case iNon:
         return gLANGUE_Pilum -> Non ();
      case iEt:
         return gLANGUE_Pilum -> Et ();
      case iOu:
         return gLANGUE_Pilum -> Ou ();

      case iEgaleEntier:
         return gLANGUE_Pilum -> EgaleEntier ();
      case iInfEntier:
         return gLANGUE_Pilum -> InfEntier ();
      case iInfEgaleEntier:
         return gLANGUE_Pilum -> InfEgaleEntier ();
      case iDifferentEntier:
         return gLANGUE_Pilum -> DifferentEntier ();
      case iSupEgaleEntier:
         return gLANGUE_Pilum -> SupEgaleEntier ();
      case iSupEntier:
         return gLANGUE_Pilum -> SupEntier ();
      case iEgaleFlottant:
         return gLANGUE_Pilum -> EgaleFlottant ();
      case iInfFlottant:
         return gLANGUE_Pilum -> InfFlottant ();
      case iInfEgaleFlottant:
         return gLANGUE_Pilum -> InfEgaleFlottant ();
      case iDifferentFlottant:
         return gLANGUE_Pilum -> DifferentFlottant ();
      case iSupEgaleFlottant:
         return gLANGUE_Pilum -> SupEgaleFlottant ();
      case iSupFlottant:
         return gLANGUE_Pilum -> SupFlottant ();
      case iEgaleChaine:
         return gLANGUE_Pilum -> EgaleChaine ();
      case iInfChaine:
         return gLANGUE_Pilum -> InfChaine ();
      case iInfEgaleChaine:
         return gLANGUE_Pilum -> InfEgaleChaine ();
      case iDifferentChaine:
         return gLANGUE_Pilum -> DifferentChaine ();
      case iSupEgaleChaine:
         return gLANGUE_Pilum -> SupEgaleChaine ();
      case iSupChaine:
         return gLANGUE_Pilum -> SupChaine ();

      case iRacine:
         return gLANGUE_Pilum -> Racine ();
      case iHasard:
         return gLANGUE_Pilum -> Hasard ();
      case iSin:
         return gLANGUE_Pilum -> Sin ();
      case iCos:
         return gLANGUE_Pilum -> Cos ();
      case iArcTan:
         return gLANGUE_Pilum -> ArcTan ();
      case iLog:
         return gLANGUE_Pilum -> Log ();
      case iExp:
         return gLANGUE_Pilum -> Exp ();

      case iLongueurChaine:
         return gLANGUE_Pilum -> LongueurChaine ();
      case iChaineVide:
         return gLANGUE_Pilum -> ChaineVide ();
      case iContientChaine:
         return gLANGUE_Pilum -> ContientChaine ();
      case iConcatChaines:
         return gLANGUE_Pilum -> ConcatChaines ();
      case iRepliquerChaine:
         return gLANGUE_Pilum -> RepliquerChaine ();
      case iRemplacerChaine:
         return gLANGUE_Pilum -> RemplacerChaine ();
      case iFormaterFlottant:
         return gLANGUE_Pilum -> FormaterNombre ();

      case iConvertirEntierEnFlottant:
         return gLANGUE_Pilum -> ConvertirEntierEnFlottant ();
      case iTronquerFlottantEnEntier:
         return gLANGUE_Pilum -> TronquerFlottantEnEntier ();

      case iGenererListe:
         return "GenererListe";
      case iLireListe:
         return "LireListe";
      case iEcrireListe:
         return "EcrireListe";
      case iCar:
         return "Car";
      case iCdr:
         return "Cdr";
      case iCons:
         return "Cons";
      case iAppend:
         return "Append";
      case iConcatListes:
         return "ConcatListes";
      case iLongueurListe:
         return "LongueurListe";

      default:
         SortieSurErreur (
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatCodeOperatoirePilumInconnu (),
               fCodeOpPilum ),
            1 );
         return "";  // superflu
      }  // switch
   }  // InstructionPilum :: CodesOpSousFormeDeChaine


// -------------------------------------------------------------------------

Chaine
InstructionPilum :: SousFormeDeChaine ()
   {
   Chaine   res =
               fCodeOpPilum == iCommentaire
                  ?  MiseEnForme (
                        "// %-*s",
                        kLargeurChampCodeOpPilum - 3,
                        "" )
                  :  MiseEnForme (
                        "%-*s",
                        kLargeurChampCodeOpPilum,
                        CodesOpSousFormeDeChaine () );

   switch (fCodeOpPilum)
      {
      case iCommentaire:
         res +=
            MiseEnForme (
               "\t\"%s\"", fChaine );
         break;

      case iReserver:
      case iDesempiler:
         res +=
            MiseEnForme (
               "\t%d", fEntier );
         break;

      case iEmpilerValeur:
      case iEmpilerAdresse:
      case iEmpilerLienStatique:
         res +=
            MiseEnForme (
               "\t%d,%d",
               fAccesStatique.fDifferenceStatique,
               fAccesStatique.fDeplacement );
         break;

      case iEmpilerEntier:
         res +=
            MiseEnForme (
               "\t%d", fEntier );
         break;
      case iEmpilerFlottant:
         res +=
            MiseEnForme (
               "\t%*.*f",
               TailleChampEcritureNombres (),
               NombreDecimalesEcritureNombres (),
               fFlottant );
         break;
      case iEmpilerBooleen:
         res +=
            MiseEnForme (
               "\t%s",
               fBooleen
                  ?  gLANGUE_Pilum ->
                        Vrai ()
                  :  gLANGUE_Pilum ->
                        Faux () );
         break;
      case iEmpilerCaractere:
         res +=
            MiseEnForme (
               "\t'%c'", fCaractere );
         break;
      case iEmpilerChaine:
         res +=
            MiseEnForme (
               "\t\"%s\"", fChaine );
         break;

      case iSauter:
      case iSauterSiFaux:
      case iAppel:
      case iEmpilerDescripteurDeThunk:
         res +=
            MiseEnForme (
               "\t%d", fAdresseDansLeCode );
         break;

      case iRetourDeFonction:
      case iRetourDeProcedure:
         res +=
            MiseEnForme (
               "\t%d", fEntier );
         break;

      case iEmpilerMarqueBlocDActivation:
      case iEvaluerThunkAvecMarqueBlocDActivation:
         res +=
            MiseEnForme (
               "\t\"%s\"", fChaine );
         break;


      default:
         ;  // pas d'argument(s) a ajouter
      }  // switch

   return res;
   }  // InstructionPilum :: SousFormeDeChaine


// --------------------------------------------------------------------------
// OptionsPilum
// --------------------------------------------------------------------------

OptionsPilum :: OptionsPilum (
   bool              leModeVerbeux,
   bool              leMontrerLeCode,
   long              laTailleDeLaPile,
   GenreDExecution   leGenreDExecution,
   bool              leMontrerLesCommandesInitialement )
   {
   fModeVerbeux = leModeVerbeux;
   fMontrerLeCode = leMontrerLeCode;
   fTailleDeLaPile = laTailleDeLaPile;
   fGenreDExecution = leGenreDExecution;
   fMontrerLesCommandesInitialement =
      leMontrerLesCommandesInitialement;
   }


// -------------------------------------------------------------------------
// La machine Pilum
// -------------------------------------------------------------------------

Pilum :: Pilum (
   Chaine            leNom,
   Chaine            nomDuFichierBinaire,
   OptionsPilumPTR   lesOptionsPilum )
   {
   fNom = leNom;
   fOptionsPilum = lesOptionsPilum;

   fMemoireDuCode = NULL;
   fTailleDeLaMemoireDuCode = 0;

   fTableDesChaines = NULL;
   fTailleDesChaines = 0;

   fPile = NULL;
   fLimiteSommet = 0;

   fSommet = 0;
   fEtatCourant = kErreurInterne;
   fInstructionCourante = 0;
   fEnvironnementCourant = 0;

   ChargerBinaire (nomDuFichierBinaire);

   CreerLaPile (fOptionsPilum -> TailleDeLaPile ());

   bool     montrerLeCode =
               fOptionsPilum -> MontrerLeCode ();

   if (fOptionsPilum -> ModeVerbeux ())
      AfficherLEtatInterne  (
         gLANGUE_Pilum ->
            PretPourLExecution (),
         montrerLeCode,
         false );
   else
      if (montrerLeCode)
         AfficherLaMemoireDuCode ();

   fModeVerbeux =
      fOptionsPilum -> ModeVerbeux ();
   fGenreDExecution =
      fOptionsPilum -> LeGenreDExecution ();

   } // Pilum :: Pilum


Pilum :: ~ Pilum ()
   {
   DetruireLaPile ();
   DetruireLesChaines ();
   DetruireLaMemoireDuCode ();
   }


// -------------------------------------------------------------------------

bool
Pilum :: ModeVerbeux ()
   { return fModeVerbeux; }

GenreDExecution
Pilum :: LeGenreDExecution ()
   { return fGenreDExecution; }


void
Pilum :: Interrompre ()
   {
   fEtatCourant = kInterruptionUtilisateur;
   }


void
Pilum :: ModePasAPas ()
   {
   fGenreDExecution = kPasAPas;
   }

void
Pilum :: ModeContinu ()
   {
   fGenreDExecution = kEnContinu;
   }

void
Pilum :: ModeArretSurAppelOuRetour ()
   {
   fGenreDExecution = kArretSurAppelOuRetour;
   }

void
Pilum :: ModePasAPasAvecAffichageDeLaPile ()
   {
   fGenreDExecution = kPasAPasAvecAffichageDeLaPile;
   }

void
Pilum :: ModeArretSurAppelOuRetourAvecAffichageDeLaPile ()
   {
   fGenreDExecution = kArretSurAppelOuRetourAvecAffichageDeLaPile;
   }


// -------------------------------------------------------------------------

void
Pilum :: ErreurFatale (Chaine message)
   {
   std::cerr << "\n\n" <<
      gLANGUE_Pilum ->
         ErreurFatalePilum () <<
      std::endl <<
      message <<
      std::endl << std::endl;

   bool     afficherLeCode =
               FLireBooleen (
                  kLectureSansAutre,
                  gLANGUE_Pilum ->
                     VoulezVousVoirLeCode (),
                  gLANGUE_Pilum ->
                     Oui ());
   bool     afficherLaPile =
               FLireBooleen (
                  kLectureSansAutre,
                  gLANGUE_Pilum ->
                     VoulezVousVoirLEtatDeLaPile (),
                  gLANGUE_Pilum ->
                     Oui () );

   AfficherLEtatInterne (
      message,
      afficherLeCode,
      afficherLaPile );

   exit (1);
   }  // Pilum :: ErreurFatale


// -------------------------------------------------------------------------

void
Pilum :: CreerLaTableDesChaines ()
   {
   fTableDesChaines =
      new char [fTailleDesChaines + 1];

   if (fTableDesChaines == NULL)
      ErreurFatale (
         gLANGUE_Pilum ->
            PasPuAllouerLaMemoireDesChaines () );
   }

void
Pilum :: CreerLaMemoireDuCode (long tailleDeLaMemoireDuCode)
   {
   fMemoireDuCode =
      new InstructionPilum [tailleDeLaMemoireDuCode];

   if (fMemoireDuCode == NULL)
      ErreurFatale (
         gLANGUE_Pilum ->
            PasPuAllouerLaMemoireDuCode () );

   fTailleDeLaMemoireDuCode = tailleDeLaMemoireDuCode;
   }

void
Pilum :: CreerLaPile (long tailleDeLaPile)
   {
   fPile =
      new ValeurPilum [tailleDeLaPile];

   if (fPile == NULL)
      ErreurFatale (
         gLANGUE_Pilum ->
            PasPuAllouerLaPile () );

   fLimiteSommet = tailleDeLaPile - 1;
   }


// -------------------------------------------------------------------------

void
Pilum :: DetruireLesChaines ()
   {
   if (fTableDesChaines != NULL)
      delete [] fTableDesChaines;
   fTableDesChaines = NULL;
   }

void
Pilum :: DetruireLaMemoireDuCode ()
   {
   if (fMemoireDuCode != NULL)
      delete [] fMemoireDuCode;
   fMemoireDuCode = NULL;
   }

void
Pilum :: DetruireLaPile ()
   {
   if (fPile != NULL)
      delete [] fPile;
   fPile = NULL;
   }


// -------------------------------------------------------------------------

void
Pilum :: ChargerBinaire (Chaine nomDuFichierBinaire)
   {
   // on detruit les differentes zones si elle existent deja
   DetruireLaPile ();
   DetruireLesChaines ();
   DetruireLaMemoireDuCode ();

   std::ifstream
            fichierBinaire (
               nomDuFichierBinaire.c_str (), std::ios_base :: in );

   if (! fichierBinaire)
      ErreurFatale (
         MiseEnForme (
            gLANGUE_Pilum ->
               FormatPasPuOuvrirLeFichierBinaireEnLecture (),
            nomDuFichierBinaire ));

   LireLesChaines (nomDuFichierBinaire, fichierBinaire);
   LireLesInstructions (nomDuFichierBinaire, fichierBinaire);

   fichierBinaire.close ();

   }  // Pilum :: ChargerBinaire


// -------------------------------------------------------------------------

void
Pilum :: LireLesChaines (
   Chaine         nomDuFichierBinaire,
   std::ifstream  & fichierBinaire )
   {
   fTailleDesChaines = -1;

   fichierBinaire.read (
      (CharPTR) & fTailleDesChaines,
      sizeof (long) );

   if (fOptionsPilum -> ModeVerbeux ())
      std::cout << MiseEnForme (
         gLANGUE_Pilum ->
            FormatTailleDesChaines (),
         fTailleDesChaines ) <<
      std::endl;

   if (! fichierBinaire)
      {
      Chaine   leMessage =
                  DecoderErreurLecture (
                     fichierBinaire, nomDuFichierBinaire );

      if (! leMessage.empty ())
         // on n'a pas atteint la fin du fichier
         ErreurFatale (leMessage);
      }

   CreerLaTableDesChaines ();

   fichierBinaire.read (fTableDesChaines, fTailleDesChaines);

   if (fOptionsPilum -> ModeVerbeux ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Pilum ->
               FormatTableDesChaines (),
            fTableDesChaines ) <<
         std::endl;

   if (! fichierBinaire)
      {
      Chaine   leMessage =
                  DecoderErreurLecture (
                     fichierBinaire, nomDuFichierBinaire );

      if (! leMessage.empty ())
         // on n'a pas atteint la fin du fichier
         ErreurFatale (leMessage);
      }
   }  // Pilum :: LireLesChaines


// -------------------------------------------------------------------------

void
Pilum :: LireLesInstructions (
   Chaine         nomDuFichierBinaire,
   std::ifstream  & fichierBinaire )
   {
   long     nombreInstructions = 0;

   fichierBinaire.read (
      (CharPTR) & nombreInstructions, sizeof (long) );

   if (fOptionsPilum -> ModeVerbeux ())
      std::cout <<
         MiseEnForme (
            gLANGUE_Pilum ->
               FormatNombreDInstructions (),
            nombreInstructions ) <<
            std::endl;

   if (! fichierBinaire)
      {
      Chaine   leMessage =
                  DecoderErreurLecture (
                     fichierBinaire, nomDuFichierBinaire );

      if (! leMessage.empty ())
         // on n'a pas atteint la fin du fichier
         ErreurFatale (leMessage);
      }

   CreerLaMemoireDuCode (nombreInstructions);

   for (long i = 0; i < nombreInstructions; ++ i)
      {
      InstructionPilumPTR
               lInstr = & fMemoireDuCode [i];

      fichierBinaire.read (
         (CharPTR) lInstr, kTailleInstructionPilum );

      if (! fichierBinaire)
         {
         Chaine   leMessage =
                     DecoderErreurLecture (
                        fichierBinaire, nomDuFichierBinaire );

      if (! leMessage.empty ())
            // on n'a pas atteint la fin du fichier
            ErreurFatale (leMessage);

         break;   // on sort de la boucle
         }

      switch (lInstr -> fCodeOpPilum)
         {
         case iCommentaire:
         case iEmpilerChaine:
         case iEmpilerMarqueBlocDActivation:
         case iEvaluerThunkAvecMarqueBlocDActivation:
            // on remplace le deplacement par la chaine
            lInstr -> fChaine =
               & fTableDesChaines [lInstr -> fEntier];
            break;
         default:
            break;
         }  // switch

      }  // for
   }  // Pilum :: LireLesInstructions


// -------------------------------------------------------------------------
// Fonctions auxiliaires
// -------------------------------------------------------------------------

void
Pilum :: InstructionInconnue (InstructionPilum lInstruction)
   {
   CodeOpPilum
            leCodeOpPilum = lInstruction.fCodeOpPilum;

   switch (leCodeOpPilum)
      {
      // on peut completer ici par d'autres instructions en cas d'extension
      default:
         ErreurFatale (
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatInstructionPilumInconnue (),
               leCodeOpPilum ));
      }  // switch
   }  // Pilum :: InstructionInconnue


AdresseDansLaPile
Pilum :: RemonteeStatique (AccesStatique lAccesStatique)
   {
   AdresseDansLaPile
            lEnvironnement = fEnvironnementCourant;
   int      differenceStatique = lAccesStatique.fDifferenceStatique;

   while (differenceStatique > 0)
      {
      lEnvironnement =
         fPile [lEnvironnement + kPosLienStatique].fAdresseDansLaPile;
      -- differenceStatique;
      }

   return lEnvironnement + lAccesStatique.fDeplacement;
   }


// -------------------------------------------------------------------------
// Macros pour alleger l'ecriture des tests quand DEBUG_PILUM est active
// -------------------------------------------------------------------------

#if defined DEBUG_PILUM

#define TESTER_SOMMET_ADDRESSE_PILE(instruction) \
            if (fPile [fSommet].fTypeValeurPilum != kAdresseDansLaPile) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SommetDePileDevraitEtreAdresseDansLaPile (), \
                     fPile [fSommet].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_1_ADDRESSE_PILE(instruction) \
            if (fPile [fSommet - 1].fTypeValeurPilum != kAdresseDansLaPile) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        ElementSousSommetDePileDevraitEtreAdresseDansLaPile (), \
                     fPile [fSommet - 1].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_ADDRESSE_THUNK(instruction) \
            if ( \
               fPile [fSommet].fTypeValeurPilum != kAdresseDansLaPile \
                  || \
               fPile [fPile [fSommet].fAdresseDansLaPile].fTypeValeurPilum != kAdresseThunk \
               ) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SommetDePileDevraitEtreAdresseDUnThunk (), \
                     fPile [fSommet].TypeSousFormeDeChaine (), \
                     fPile [fSommet].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_ENTIER(instruction) \
            if (fPile [fSommet].fTypeValeurPilum != kEntier) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SommetDePileDevraitEtreEntier (), \
                     fPile [fSommet].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_1_ENTIER(instruction) \
            if (fPile [fSommet - 1].fTypeValeurPilum != kEntier) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        ElementSousSommetDePileDevraitEtreEntier (), \
                     fPile [fSommet - 1].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_FLOTTANT(instruction) \
            if (fPile [fSommet].fTypeValeurPilum != kFlottant) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SommetDePileDevraitEtreFlottant (), \
                     fPile [fSommet].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_1_FLOTTANT(instruction) \
            if (fPile [fSommet - 1].fTypeValeurPilum != kFlottant) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        ElementSousSommetDePileDevraitEtreFlottant (), \
                     fPile [fSommet - 1].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_2_FLOTTANT(instruction) \
            if (fPile [fSommet -2].fTypeValeurPilum != kFlottant) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SecondElementSousSommetDePileDevraitEtreFlottant (), \
                     fPile [fSommet - 2].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_BOOLEEN(instruction) \
            if (fPile [fSommet].fTypeValeurPilum != kBooleen) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SommetDePileDevraitEtreBooleen (), \
                     fPile [fSommet].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_1_BOOLEEN(instruction) \
            if (fPile [fSommet - 1].fTypeValeurPilum != kBooleen) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        ElementSousSommetDePileDevraitEtreBooleen (), \
                     fPile [fSommet - 1].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_CARACTERE(instruction) \
            if (fPile [fSommet].fTypeValeurPilum != kCaractere) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SommetDePileDevraitEtreUneCaractere (), \
                     fPile [fSommet].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_CHAINE(instruction) \
            if (fPile [fSommet].fTypeValeurPilum != kChaine) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SommetDePileDevraitEtreUneChaine (), \
                     fPile [fSommet].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_1_CHAINE(instruction) \
            if (fPile [fSommet - 1].fTypeValeurPilum != kChaine) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SommetDePileDevraitEtreUneChaine (), \
                     fPile [fSommet - 1].TypeSousFormeDeChaine () ));

#define TESTER_SOMMET_2_CHAINE(instruction) \
            if (fPile [fSommet -2].fTypeValeurPilum != kChaine) \
               ErreurFatale ( \
                  MiseEnForme ( \
                     gLANGUE_Pilum -> \
                        FormatValeurDansLaPilePasDuBonType (), \
                     gLANGUE_Pilum -> \
                        instruction (), \
                     gLANGUE_Pilum -> \
                        SecondElementSousSommetDePileDevraitEtreUneChaine (), \
                     fPile [fSommet - 2].TypeSousFormeDeChaine () ));


#endif /* DEBUG_PILUM */


// -------------------------------------------------------------------------

void
Pilum :: ActionAvantInteraction ()
   {
   switch (fGenreDExecution)
      {
      case kPasAPasAvecAffichageDeLaPile :
      case kArretSurAppelOuRetourAvecAffichageDeLaPile :
         AfficherLaPile ();
         break;
      default :
         break;
      } // switch
   }  // Pilum :: ActionAvantInteraction


void
Pilum :: ActionAvantChaqueCommande ()
   {
   // on a deja avance a l'instruction suivante!

   std::cout <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatPromptPilum (),
         fInstructionCourante - 1 ) <<
      fMemoireDuCode [fInstructionCourante - 1].
         SousFormeDeChaine () <<
      std::endl;
   }  // Pilum :: ActionAvantChaqueCommande


void
Pilum :: ActionApresChaqueCommande ()
   {
   }  // Pilum :: ActionAvantChaqueCommande


void
Pilum :: ActionApresInteraction ()
   {
   }  // Pilum :: ActionAvantInteraction


// -------------------------------------------------------------------------
// Executer
// -------------------------------------------------------------------------

void
Pilum :: Executer (AdresseDansLeCode adresseDeDepart)
   {
   time_t   tempsAuDebut = time (NULL);
// bool     modeVerbeux = fOptionsPilum -> ModeVerbeux ();

   if (
      fMemoireDuCode == NULL
         ||
      fTableDesChaines == NULL
         ||
      fPile == NULL
      )
      ErreurFatale (
         gLANGUE_Pilum ->
            ZonesDePilumPasAllouees () );

   fSommet = 0;
   fEtatCourant = kExecution;
   fInstructionCourante = adresseDeDepart;
   fEnvironnementCourant = 0;

   DecodageDeCommandesPilum
            leDecodageDeCommandesPilum (gCommandesPilum, this);

   leDecodageDeCommandesPilum.Initialiser ();

   if (fOptionsPilum -> MontrerLesCommandesInitialement ())
      leDecodageDeCommandesPilum.Aide ("");

   while (fEtatCourant == kExecution)
      {
      InstructionPilum
               lInstruction =
                  fMemoireDuCode [fInstructionCourante ++];

      switch (fGenreDExecution)
         {
         case kPasAPas:
         case kPasAPasAvecAffichageDeLaPile :
            leDecodageDeCommandesPilum.
               InteragirAvecLUtilisateur ();
            break;
         case kArretSurAppelOuRetour:
         case kArretSurAppelOuRetourAvecAffichageDeLaPile:
         case kEnContinu:
            break;
         }  // switch


      switch (lInstruction.fCodeOpPilum)
         {
         case iHalte:
            fEtatCourant = kFinNormale;
            break;

         case iCommentaire:
            // RIEN A FAIRE!
            break;


         // -------------------------------------------------------------------------
         // Marquage des blocs d'activation
         // -------------------------------------------------------------------------

         case iEmpilerMarqueBlocDActivation:
            switch (fGenreDExecution)
               {
               case kArretSurAppelOuRetour :
               case kArretSurAppelOuRetourAvecAffichageDeLaPile :
                  leDecodageDeCommandesPilum.InteragirAvecLUtilisateur ();
                  break;
               default :
                  break;
               }  // switch

            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fTypeValeurPilum =
                  kMarqueBlocDActivationDeFonction;
               fPile [fSommet].fChaine = lInstruction.fChaine;
               }
            break;


         // -------------------------------------------------------------------------
         // Reservation et desempilage
         // -------------------------------------------------------------------------

         case iReserver:
            if (fSommet + lInstruction.fEntier > fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               for (long i = 0; i < lInstruction.fEntier; ++ i)
                  {
                  ++ fSommet;
                  fPile [fSommet].fTypeValeurPilum = kValeurInconnue;
                  }  // for
            break;

         case iDesempiler:
            if (fSommet < lInstruction.fEntier)
               fEtatCourant = kDebordementPileVersLeBas;
            else
               fSommet -= lInstruction.fEntier;
            break;


         // -------------------------------------------------------------------------
         // Duplication
         // -------------------------------------------------------------------------

         case iDupliquer:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet] = fPile [fSommet - 1];
               }
            break;


         // -------------------------------------------------------------------------
         // Affectation
         // -------------------------------------------------------------------------


         case iStocker:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ADDRESSE_PILE (Stocker)
#endif /* DEBUG_PILUM */
            fPile [fPile [fSommet - 1].fAdresseDansLaPile] = fPile [fSommet];
            fSommet -= 2;
            break;


         // -------------------------------------------------------------------------
         // Empilage
         // -------------------------------------------------------------------------

         case iEmpilerValeur:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               fPile [++ fSommet] =
                  fPile [ RemonteeStatique (lInstruction.fAccesStatique) ];
            break;

         case iEmpilerAdresse:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fAdresseDansLaPile =
                  RemonteeStatique (lInstruction.fAccesStatique);
               fPile [fSommet].fTypeValeurPilum = kAdresseDansLaPile;
               }
            break;

         case iEmpilerLienStatique:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fAdresseDansLaPile =
                  RemonteeStatique (lInstruction.fAccesStatique);
               fPile [fSommet].fTypeValeurPilum = kLienStatique;
               }
            break;

         case iEmpilerEntier:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fEntier = lInstruction.fEntier;
               fPile [fSommet].fTypeValeurPilum = kEntier;
               }
            break;

         case iEmpilerFlottant:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fFlottant = lInstruction.fFlottant;
               fPile [fSommet].fTypeValeurPilum = kFlottant;
               }
            break;

         case iEmpilerBooleen:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fBooleen = lInstruction.fBooleen;
               fPile [fSommet].fTypeValeurPilum = kBooleen;
               }
            break;

         case iEmpilerCaractere:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fCaractere = lInstruction.fCaractere;
               fPile [fSommet].fTypeValeurPilum = kCaractere;
               }
            break;

         case iEmpilerChaine:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fChaine = lInstruction.fChaine;
               fPile [fSommet].fTypeValeurPilum = kChaine;
               }
            break;

         case iEmpilerValInconnue:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fTypeValeurPilum = kValeurInconnue;
               }
            break;


         // -------------------------------------------------------------------------
         // Sauts
         // -------------------------------------------------------------------------

         case iSauter:
            fInstructionCourante = lInstruction.fAdresseDansLeCode;
            break;

         case iSauterSiFaux:
#if defined DEBUG_PILUM
            TESTER_SOMMET_BOOLEEN (SauterSiFaux)
#endif /* DEBUG_PILUM */
            if (! fPile [fSommet --].CommeBooleen ())
               fInstructionCourante = lInstruction.fAdresseDansLeCode;
            break;


         // -------------------------------------------------------------------------
         // Fonctions et procedures
         // -------------------------------------------------------------------------

         case iAppel:
            switch (fGenreDExecution)
               {
               case kArretSurAppelOuRetour :
               case kArretSurAppelOuRetourAvecAffichageDeLaPile :
                  leDecodageDeCommandesPilum.InteragirAvecLUtilisateur ();
                  break;
               default :
                  break;
               }  // switch

            if (fSommet + 1 >= fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               // on empile l'Adresse de Retour
               ++ fSommet;
               fPile [fSommet].fAdresseDansLeCode = fInstructionCourante;
               fPile [fSommet].fTypeValeurPilum = kAdresseDeRetour;

               // on empile le Lien Dynamique
               ++ fSommet;
               fPile [fSommet].fAdresseDansLaPile = fEnvironnementCourant;
               fPile [fSommet].fTypeValeurPilum = kLienDynamique;

               // on passe a l'environnement de l'appelŽ
               fEnvironnementCourant = fSommet;

               // on saute au debut de la fonction
               fInstructionCourante = lInstruction.fAdresseDansLeCode;
               }  // iAppel
            break;

         case iRetourDeFonction:
            {
            switch (fGenreDExecution)
               {
               case kArretSurAppelOuRetour :
               case kArretSurAppelOuRetourAvecAffichageDeLaPile :
                  leDecodageDeCommandesPilum.InteragirAvecLUtilisateur ();
                  break;
               default :
                  break;
               }  // switch

            // on met de cote le resultat
            ValeurPilum
                     resultat = fPile [fSommet --];

            // on recupere lien dynamique et adresse de retour
            AdresseDansLeCode
                     lienDynamique =
                        fPile [fEnvironnementCourant].fAdresseDansLaPile;
            AdresseDansLeCode
                     adresseDeRetour =
                        fPile [fEnvironnementCourant - 1].fAdresseDansLeCode;

            // on detruit les temporaires eventuels,
            // le lien dynamique, l'adresse de retour, (2 liens)
            // les arguments eventuels et le lien statique Žventuel
            // (allocation "automatique")
            fSommet = fEnvironnementCourant - (lInstruction.fEntier + 2);

            // on re-empile le resultat
            fPile [++ fSommet] = resultat;

            // on revient a l'environnement de l'appeleur
            fEnvironnementCourant = lienDynamique;

            // on retourne a l'appeleur
            fInstructionCourante = adresseDeRetour;
            }  // iRetourDeFonction
            break;

         case iRetourDeProcedure:
            switch (fGenreDExecution)
               {
               case kArretSurAppelOuRetour :
               case kArretSurAppelOuRetourAvecAffichageDeLaPile :
                  leDecodageDeCommandesPilum.InteragirAvecLUtilisateur ();
                  break;
               default :
                  break;
               }  // switch

            {
            // on recupere lien dynamique et adresse de retour
            AdresseDansLeCode
                     lienDynamique =
                        fPile [fEnvironnementCourant].fAdresseDansLaPile;
            AdresseDansLeCode
                     adresseDeRetour =
                        fPile [fEnvironnementCourant - 1].fAdresseDansLeCode;

            // on detruit les temporaires eventuels,
            // le lien dynamique, l'adresse de retour, (2 liens)
            // les arguments eventuels et le lien statique Žventuel
            // (allocation "automatique")
            fSommet = fEnvironnementCourant - (lInstruction.fEntier + 2);

            // on revient a l'environnement de l'appeleur
            fEnvironnementCourant = lienDynamique;

            // on retourne a l'appeleur
            fInstructionCourante = adresseDeRetour;
            }  // iRetourDeProcedure
            break;


         // -------------------------------------------------------------------------
         // Thunks
         // -------------------------------------------------------------------------

         case iEmpilerDescripteurDeThunk:
            if (fGenreDExecution)
               AfficherLEtatInterne (
                  gLANGUE_Pilum ->
                     EmpilerDescripteurDeThunk (),
                  false,
                  true );

            if (fSommet + 1 >= fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               // on empile l'adresse du thunk
               ++ fSommet;
               fPile [fSommet].fAdresseDansLeCode =
                  lInstruction.fAdresseDansLeCode;
               fPile [fSommet].fTypeValeurPilum = kAdresseThunk;

               // on empile le Lien Statique futur
               ++ fSommet;
               fPile [fSommet].fAdresseDansLaPile = fEnvironnementCourant;
               fPile [fSommet].fTypeValeurPilum = kLienStatiqueFutur;
               }
            break;

         case iEvaluerThunk:
            switch (fGenreDExecution)
               {
               case kArretSurAppelOuRetour :
               case kArretSurAppelOuRetourAvecAffichageDeLaPile :
                  leDecodageDeCommandesPilum.InteragirAvecLUtilisateur ();
                  break;
               default :
                  break;
               }  // switch

            if (fGenreDExecution)
               AfficherLEtatInterne (
                  gLANGUE_Pilum ->
                     EvaluerThunk (),
                  false,
                  true );

            if (fSommet + 2 >= fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
#if defined DEBUG_PILUM
               TESTER_SOMMET_ADDRESSE_THUNK (EvaluerThunk)
#endif /* DEBUG_PILUM */
               AdresseDansLeCode
                        lAdresseDuDescripteur =
                           fPile [fSommet --].fAdresseDansLeCode;

               AdresseDansLaPile
                        leLienStatique =
                           fPile [lAdresseDuDescripteur + 1].fAdresseDansLaPile;

               // on empile le Lien Statique
               ++ fSommet;
               fPile [fSommet].fAdresseDansLaPile = leLienStatique;
               fPile [fSommet].fTypeValeurPilum = kLienStatique;

               // on empile l'Adresse de Retour
               ++ fSommet;
               fPile [fSommet].fAdresseDansLeCode = fInstructionCourante;
               fPile [fSommet].fTypeValeurPilum = kAdresseDeRetour;

               // on empile le Lien Dynamique
               ++ fSommet;
               fPile [fSommet].fAdresseDansLaPile = fEnvironnementCourant;
               fPile [fSommet].fTypeValeurPilum = kLienDynamique;

               // on passe a l'environnement de l'appele
               fEnvironnementCourant = fSommet;

               // on saute au debut du thunk
               fInstructionCourante =
                  fPile [lAdresseDuDescripteur].fAdresseDansLeCode;
               }
            break;

         case iEvaluerThunkAvecMarqueBlocDActivation:
            switch (fGenreDExecution)
               {
               case kArretSurAppelOuRetour :
               case kArretSurAppelOuRetourAvecAffichageDeLaPile :
                  leDecodageDeCommandesPilum.InteragirAvecLUtilisateur ();
                  break;
               default :
                  break;
               }  // switch

            if (fGenreDExecution)
               AfficherLEtatInterne (
                  gLANGUE_Pilum ->
                     EvaluerThunkAvecMarqueBlocDActivation (),
                  false,
                  true );

            if (fSommet + 2 >= fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
#if defined DEBUG_PILUM
               TESTER_SOMMET_ADDRESSE_THUNK (EvaluerThunkAvecMarqueBlocDActivation)
#endif /* DEBUG_PILUM */
               AdresseDansLeCode
                        lAdresseDuDescripteur =
                           fPile [fSommet --].fAdresseDansLeCode;

               AdresseDansLaPile
                        leLienStatique =
                           fPile [lAdresseDuDescripteur + 1].fAdresseDansLaPile;

               // on empile la marque du block d'activation
               ++ fSommet;
               fPile [fSommet].fTypeValeurPilum =
                  kMarqueBlocDActivationDeThunk;
               fPile [fSommet].fChaine = lInstruction.fChaine;

               // on empile le Lien Statique
               ++ fSommet;
               fPile [fSommet].fAdresseDansLaPile = leLienStatique;
               fPile [fSommet].fTypeValeurPilum = kLienStatique;

               // on empile l'Adresse de Retour
               ++ fSommet;
               fPile [fSommet].fAdresseDansLeCode = fInstructionCourante;
               fPile [fSommet].fTypeValeurPilum = kAdresseDeRetour;

               // on empile le Lien Dynamique
               ++ fSommet;
               fPile [fSommet].fAdresseDansLaPile = fEnvironnementCourant;
               fPile [fSommet].fTypeValeurPilum = kLienDynamique;

               // on passe a l'environnement de l'appele
               fEnvironnementCourant = fSommet;

               // on saute au debut du thunk
               fInstructionCourante =
                  fPile [lAdresseDuDescripteur].fAdresseDansLeCode;
               }
            break;


         // -------------------------------------------------------------------------
         // Entrees
         // -------------------------------------------------------------------------

         case iLireEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_CHAINE (LireEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fEntier =
               FLireEntier (
                  kLectureSansAutre,
                  fPile [fSommet].CommeChaine () );
            fPile [fSommet].fTypeValeurPilum = kEntier;
            break;

         case iLireFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_CHAINE (LireFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               FLireFlottant (
                  kLectureSansAutre,
                  fPile [fSommet].CommeChaine () );
            fPile [fSommet].fTypeValeurPilum = kFlottant;
            break;

         case iLireBooleen:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (LireBooleen)
            TESTER_SOMMET_CHAINE (LireBooleen)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               FLireBooleen (
                  kLectureSansAutre,
                  fPile [fSommet - 1].CommeChaine (),
                  fPile [fSommet].CommeChaine () );
            fPile [fSommet - 1].fTypeValeurPilum = kBooleen;
            -- fSommet;
            break;

         case iLireCaractere:
#if defined DEBUG_PILUM
            TESTER_SOMMET_CHAINE (LireCaractere)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fCaractere =
               FLireCaractere (
                  kLectureSansAutre,
                  fPile [fSommet].CommeChaine () );
            fPile [fSommet].fTypeValeurPilum = kCaractere;
            break;

         case iLireChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (LireChaine)
            TESTER_SOMMET_CHAINE (LireChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fChaine =
               FLireChaine (
                  kLectureSansAutre,
                  fPile [fSommet - 1].CommeChaine () );
            break;


         // -------------------------------------------------------------------------
         // Sorties
         // -------------------------------------------------------------------------

         case iEcrireEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ENTIER (EcrireEntier)
#endif /* DEBUG_PILUM */
            std::cout <<
               MiseEnForme (
                  "%d", fPile [fSommet --].fEntier );
            break;

         case iEcrireFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (EcrireFlottant)
#endif /* DEBUG_PILUM */
            std::cout <<
               MiseEnForme (
                  "%*.*f",
                  TailleChampEcritureNombres (),
                  NombreDecimalesEcritureNombres (),
                  fPile [fSommet --].fFlottant );
            break;

         case iEcrireBooleen:
#if defined DEBUG_PILUM
            TESTER_SOMMET_BOOLEEN (EcrireBooleen)
#endif /* DEBUG_PILUM */
            std::cout <<
               MiseEnForme (
                  "%s",
                  fPile [fSommet --].CommeBooleen ()
                     ?  gLANGUE_Pilum ->
                           Vrai ()
                     :  gLANGUE_Pilum ->
                           Faux () );
            break;

         case iEcrireCaractere:
#if defined DEBUG_PILUM
            TESTER_SOMMET_CARACTERE (EcrireCaractere)
#endif /* DEBUG_PILUM */
            std::cout <<
               MiseEnForme ( "%c", fPile [fSommet --].fCaractere );
            break;

         case iEcrireChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_CHAINE (EcrireChaine)
#endif /* DEBUG_PILUM */
            std::cout <<
               MiseEnForme ( "%s", fPile [fSommet --].fChaine );
            break;

         case iEcrireFinDeLigne:
            std::cout << std::endl;
            break;


         // -------------------------------------------------------------------------
         // Arithmetique
         // -------------------------------------------------------------------------

         case iIncrEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ADDRESSE_PILE (IncrEntier)
#endif /* DEBUG_PILUM */
            ++ fPile [fPile [fSommet --].fAdresseDansLaPile].fEntier;
            break;

         case iDecrEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ADDRESSE_PILE (DecrEntier)
#endif /* DEBUG_PILUM */
            -- fPile [fPile [fSommet --].fAdresseDansLaPile].fEntier;
            break;

         case iIncrFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ADDRESSE_PILE (IncrFlottant)
#endif /* DEBUG_PILUM */
            fPile [fPile [fSommet --].fAdresseDansLaPile].fFlottant += 1.0;
            break;

         case iDecrFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ADDRESSE_PILE (DecrFlottant)
#endif /* DEBUG_PILUM */
            fPile [fPile [fSommet --].fAdresseDansLaPile].fFlottant -= 1.0;
            break;

         case iMoins1Entier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ENTIER (Moins1Entier)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fEntier = - fPile [fSommet].fEntier;
            break;

         case iMoins1Flottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (Moins1Flottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               - fPile [fSommet].CommeFlottant ();
            break;

         case iAbsEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ENTIER (AbsEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fEntier = abs (fPile [fSommet].fEntier);
            break;

         case iAbsFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (Moins1Flottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               fabs (fPile [fSommet].CommeFlottant ());
            break;

         case iPair:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ENTIER (Pair)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fBooleen = fPile [fSommet].fEntier % 2 == 0;
            fPile [fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iPlusEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (PlusEntier)
            TESTER_SOMMET_ENTIER (PlusEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fEntier =
               fPile [fSommet - 1].fEntier + fPile [fSommet].fEntier;
            -- fSommet;
            break;

         case iMoinsEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (MoinsEntier)
            TESTER_SOMMET_ENTIER (MoinsEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fEntier =
               fPile [fSommet - 1].fEntier - fPile [fSommet].fEntier;
            -- fSommet;
            break;

         case iFoisEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (FoisEntier)
            TESTER_SOMMET_ENTIER (FoisEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fEntier =
               fPile [fSommet - 1].fEntier * fPile [fSommet].fEntier;
            -- fSommet;
            break;

         case iDiviseEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (DiviseEntier)
            TESTER_SOMMET_ENTIER (DiviseEntier)
#endif /* DEBUG_PILUM */
            if (fPile [fSommet].fEntier == 0)
               fEtatCourant = kDiviseEntierParZero;
            else
               {
               fPile [fSommet - 1].fEntier =
                  fPile [fSommet - 1].fEntier / fPile [fSommet].fEntier;
               -- fSommet;
               }
            break;

         case iModuloEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (ModuloEntier)
            TESTER_SOMMET_ENTIER (ModuloEntier)
#endif /* DEBUG_PILUM */
            if (fPile [fSommet].fEntier == 0)
               fEtatCourant = kModuloEntierParZero;
            else
               {
               fPile [fSommet - 1].fEntier =
                  fPile [fSommet - 1].fEntier % fPile [fSommet].fEntier;
               -- fSommet;
               }
            break;

         case iPlusFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (PlusFlottant)
            TESTER_SOMMET_FLOTTANT (PlusFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fFlottant =
               fPile [fSommet - 1].CommeFlottant ()
                  +
               fPile [fSommet].CommeFlottant ();
            -- fSommet;
            break;

         case iMoinsFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (PlusFlottant)
            TESTER_SOMMET_FLOTTANT (PlusFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fFlottant =
               fPile [fSommet - 1].CommeFlottant ()
                  -
               fPile [fSommet].CommeFlottant ();
            -- fSommet;
            break;

         case iFoisFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (PlusFlottant)
            TESTER_SOMMET_FLOTTANT (PlusFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fFlottant =
               fPile [fSommet - 1].CommeFlottant ()
                  *
               fPile [fSommet].CommeFlottant ();
            -- fSommet;
            break;

         case iDiviseFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (PlusFlottant)
            TESTER_SOMMET_FLOTTANT (PlusFlottant)
#endif /* DEBUG_PILUM */
            if (fPile [fSommet].fFlottant == 0.0)
               fEtatCourant = kDiviseFlottantParZero;
            else
               {
               fPile [fSommet - 1].fFlottant =
                  fPile [fSommet - 1].CommeFlottant ()
                     /
                  fPile [fSommet].CommeFlottant ();
               -- fSommet;
               }
            break;


         // -------------------------------------------------------------------------
         // Logique
         // -------------------------------------------------------------------------

         case iNon:
#if defined DEBUG_PILUM
            TESTER_SOMMET_BOOLEEN (Non)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fBooleen =
               ! fPile [fSommet].CommeBooleen ();
            fPile [fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iEt:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_BOOLEEN (Et)
            TESTER_SOMMET_BOOLEEN (Et)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].CommeBooleen ()
                  &&
               fPile [fSommet].CommeBooleen ();
            -- fSommet;
            fPile [fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iOu:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_BOOLEEN (Et)
            TESTER_SOMMET_BOOLEEN (Et)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].CommeBooleen ()
                  ||
               fPile [fSommet].CommeBooleen ();
            -- fSommet;
            fPile [fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iEgaleEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (EgaleEntier)
            TESTER_SOMMET_ENTIER (EgaleEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].fEntier == fPile [fSommet].fEntier;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iDifferentEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (DifferentEntier)
            TESTER_SOMMET_ENTIER (DifferentEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].fEntier != fPile [fSommet].fEntier;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iSupEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (SupEntier)
            TESTER_SOMMET_ENTIER (SupEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].fEntier > fPile [fSommet].fEntier;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iSupEgaleEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (SupEgaleEntier)
            TESTER_SOMMET_ENTIER (SupEgaleEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].fEntier >= fPile [fSommet].fEntier;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iInfEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (InfEntier)
            TESTER_SOMMET_ENTIER (InfEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].fEntier < fPile [fSommet].fEntier;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iInfEgaleEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_ENTIER (InfEgaleEntier)
            TESTER_SOMMET_ENTIER (InfEgaleEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].fEntier <= fPile [fSommet].fEntier;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iEgaleFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (EgaleFlottant)
            TESTER_SOMMET_FLOTTANT (EgaleFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].fFlottant
                  ==
               fPile [fSommet].CommeFlottant ();
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iDifferentFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (DifferentFlottant)
            TESTER_SOMMET_FLOTTANT (DifferentFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].fFlottant
                  !=
               fPile [fSommet].CommeFlottant ();
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iSupFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (SupFlottant)
            TESTER_SOMMET_FLOTTANT (SupFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].CommeFlottant ()
                  >
               fPile [fSommet].CommeFlottant ();
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iSupEgaleFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (SupEgaleFlottant)
            TESTER_SOMMET_FLOTTANT (SupEgaleFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].CommeFlottant ()
                  >=
               fPile [fSommet].CommeFlottant ();
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iInfFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (InfFlottant)
            TESTER_SOMMET_FLOTTANT (InfFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].CommeFlottant ()
                  <
               fPile [fSommet].CommeFlottant ();
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iInfEgaleFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_FLOTTANT (InfEgaleFlottant)
            TESTER_SOMMET_FLOTTANT (InfEgaleFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               fPile [fSommet - 1].CommeFlottant ()
                  <=
               fPile [fSommet].CommeFlottant ();
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iEgaleChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (EgaleChaine)
            TESTER_SOMMET_CHAINE (EgaleChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               strcmp (
                  fPile [fSommet - 1].fChaine, fPile [fSommet].fChaine
                  ) == 0;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iDifferentChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (DifferentChaine)
            TESTER_SOMMET_CHAINE (DifferentChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               strcmp (
                  fPile [fSommet - 1].fChaine, fPile [fSommet].fChaine
                  ) != 0;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iSupChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (SupChaine)
            TESTER_SOMMET_CHAINE (SupChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               strcmp (
                  fPile [fSommet - 1].fChaine, fPile [fSommet].fChaine
                  ) > 0;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iSupEgaleChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (SupEgaleChaine)
            TESTER_SOMMET_CHAINE (SupEgaleChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               strcmp (
                  fPile [fSommet - 1].fChaine, fPile [fSommet].fChaine
                  ) >= 0;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iInfChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (InfChaine)
            TESTER_SOMMET_CHAINE (InfChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               strcmp (
                  fPile [fSommet - 1].fChaine, fPile [fSommet].fChaine
                  ) < 0;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iInfEgaleChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (InfEgaleChaine)
            TESTER_SOMMET_CHAINE (InfEgaleChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               strcmp (
                  fPile [fSommet - 1].fChaine, fPile [fSommet].fChaine
                  ) <= 0;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;


         // -------------------------------------------------------------------------
         // Fonctions mathematiques
         // -------------------------------------------------------------------------

         case iRacine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (Racine)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               sqrt (fPile [fSommet].CommeFlottant ());
            break;

         case iHasard:
            if (fSommet == fLimiteSommet)
               fEtatCourant = kDebordementPile;
            else
               {
               ++ fSommet;
               fPile [fSommet].fFlottant = FHasard ();
               fPile [fSommet].fTypeValeurPilum = kFlottant;
               }
            break;

         case iSin:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (Sin)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               sin (fPile [fSommet].CommeFlottant ());
            break;

         case iCos:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (Cos)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               cos (fPile [fSommet].CommeFlottant ());
            break;

         case iArcTan:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (ArcTan)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               atan (fPile [fSommet].CommeFlottant ());
            break;

         case iLog:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (Log)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               log (fPile [fSommet].CommeFlottant ());
            break;

         case iExp:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (Exp)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               exp (fPile [fSommet].CommeFlottant ());
            break;


         case iLongueurChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_CHAINE (LongueurChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               strlen (fPile [fSommet].CommeChaine ());
            fPile [fSommet].fTypeValeurPilum = kFlottant;
            break;

         case iChaineVide:
#if defined DEBUG_PILUM
            TESTER_SOMMET_CHAINE (ChaineVide)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fBooleen =
               strlen (fPile [fSommet].CommeChaine ()) == 0;
            fPile [fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iContientChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (ContientChaine)
            TESTER_SOMMET_CHAINE (ContientChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fBooleen =
               strstr (
                  fPile [fSommet - 1].fChaine, fPile [fSommet].fChaine
                  )
                  !=
               NULL;
            fPile [-- fSommet].fTypeValeurPilum = kBooleen;
            break;

         case iConcatChaines:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (ConcatChaines)
            TESTER_SOMMET_CHAINE (ConcatChaines)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fChaine =
               FConcatChaines (
                  fPile [fSommet - 1].CommeChaine (),
                  fPile [fSommet].CommeChaine () );

            fPile [-- fSommet].fTypeValeurPilum = kChaine;
            break;

         case iRepliquerChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_1_CHAINE (RepliquerChaine)
            TESTER_SOMMET_ENTIER (RepliquerChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 1].fChaine =
               FRepliquerChaine (
                  fPile [fSommet - 1].CommeChaine (),
                  fPile [fSommet].CommeEntier () );

            fPile [-- fSommet].fTypeValeurPilum = kChaine;
            break;

         case iRemplacerChaine:
#if defined DEBUG_PILUM
            TESTER_SOMMET_2_CHAINE (RemplacerChaine)
            TESTER_SOMMET_1_CHAINE (RemplacerChaine)
            TESTER_SOMMET_CHAINE (RemplacerChaine)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 2].fChaine =
               FRemplacerChaine (
                  fPile [fSommet - 2].CommeChaine (),
                  fPile [fSommet - 1].CommeChaine (),
                  fPile [fSommet].CommeChaine () );

            -- fSommet;
            fPile [-- fSommet].fTypeValeurPilum = kChaine;
            break;

         case iFormaterFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_2_FLOTTANT (FormaterNombre)
            TESTER_SOMMET_1_ENTIER (FormaterNombre)
            TESTER_SOMMET_ENTIER (FormaterNombre)
#endif /* DEBUG_PILUM */
            fPile [fSommet - 2].fChaine =
               (CharPTR) FFormaterFlottant (
                  fPile [fSommet - 2].CommeFlottant (),
                  fPile [fSommet - 1].CommeEntier (),
                  fPile [fSommet].CommeEntier () ).c_str ();

            -- fSommet;
            fPile [-- fSommet].fTypeValeurPilum = kChaine;
            break;

         case iConvertirEntierEnFlottant:
#if defined DEBUG_PILUM
            TESTER_SOMMET_ENTIER (ConvertirEntierEnFlottant)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fFlottant =
               fPile [fSommet].CommeEntier ();
            fPile [fSommet].fTypeValeurPilum = kFlottant;
            break;

         case iTronquerFlottantEnEntier:
#if defined DEBUG_PILUM
            TESTER_SOMMET_FLOTTANT (TronquerFlottantEnEntier)
#endif /* DEBUG_PILUM */
            fPile [fSommet].fEntier =
               lroundf (fPile [fSommet].CommeFlottant ());
            fPile [fSommet].fTypeValeurPilum = kEntier;
            break;

         // -------------------------------------------------------------------------
         // Fonctions sur les listes
         // -------------------------------------------------------------------------

         // Afficher une liste.
         case iEcrireListe:
         {
            Chaine str = fPile[ fSommet-- ].fListe->str();
            std::cout << MiseEnForme( "%s", str );
            break;
         }


         // Construire une liste a partir des elements sur la pile.
         case iGenererListe:
         {
            ListePTR laListe = new Liste();

            // Prendre la taille de la liste.
            int laTaille = fPile[ fSommet ].CommeEntier();

            // Creer la liste.
            for (-- laTaille; laTaille >= 0; laTaille --)
            {
               switch (fPile[ --fSommet ].fTypeValeurPilum)
               {
                  case kFlottant:
                  {
                     Nombre leNombre = fPile[ fSommet ].CommeFlottant();
                     laListe->cons( leNombre );
                     break;
                  }
                  case kBooleen:
                  {
                     bool leBooleen = fPile[ fSommet ].CommeBooleen();
                     laListe->cons( leBooleen );
                     break;
                  }
                  case kChaine:
                  {
                     Chaine laChaine = fPile[ fSommet ].CommeChaine();
                     laListe->cons( laChaine );
                     break;
                  }
                  case kListe:
                  {
                     ListePTR lElementListe = fPile[ fSommet ].CommeListe();
                     laListe->cons( lElementListe );
                     break;
                  }
                  // On ignore les autres types (kAdresseThunk, kValeurInconnue, kEntier, ...)
                  default:
                     break;
               }
            }
            // On ecrase la cellule courante de la pile avec la nouvelle liste.
            fPile[ fSommet ].fListe             = laListe;
            fPile[ fSommet ].fTypeValeurPilum   = kListe;
            break;
         }


         case iCar:
         {
            ListePTR laListe  = fPile[ fSommet ].CommeListe();
            Element lElement  = laListe -> car();
            //delete laListe;


            // La fonction Car peut retourner de types differents (surcharge semantique) alors on
            // doit connaitre le type de l'element pour le placer correctement sur la pile.
            switch (lElement.fType)
            {
               case kTypeNombre:
               {
                  fPile[ fSommet ].fFlottant          = lElement.fNombre;
                  fPile[ fSommet ].fTypeValeurPilum   = kFlottant;
                  break;
               }
               case kTypeBooleen:
               {
                  fPile[ fSommet ].fBooleen           = lElement.fBooleen;
                  fPile[ fSommet ].fTypeValeurPilum   = kBooleen;
                  break;
               }
               case kTypeChaine:
               {
                  fPile[ fSommet ].fChaine = const_cast< CharPTR >( lElement.fChaine -> c_str() );
                  fPile[ fSommet ].fTypeValeurPilum   = kChaine;
                  break;
               }
               case kTypeListe:
               {
                  fPile[ fSommet ].fListe             = new Liste( lElement.fListe );
                  fPile[ fSommet ].fTypeValeurPilum   = kListe;
                  break;
               }
               default:
                  SortieSurErreur( "Type Inconnu!", 2 );
                  break;
            }
            break;
         }


         case iCdr:
         {
            // Ecraser la liste au sommet de la pile par son Cdr.
            ListePTR laListe = fPile[ fSommet ].CommeListe();
            *laListe = laListe -> cdr();
            break;
         }


         // Jeremy OTHIENO: A Completer
         //case iLireListe:



         case iCons:
         {
            //VariableLogiqueTypePTR leTypeLogique = fPile[ fSommet ].TypeLogique();
            ListePTR laListe = fPile[ fSommet ].CommeListe();
            Element lElement;

            // Ajouter l'element en tete de la liste.
            switch (fPile[ fSommet ].fTypeValeurPilum)
            {
               case kFlottant:
               {
                  lElement.fNombre  = fPile[ fSommet ].CommeFlottant();
                  lElement.fType    = kTypeNombre;
                  break;
               }
               case kBooleen:
               {
                  lElement.fBooleen = fPile[ fSommet ].CommeBooleen();
                  lElement.fType    = kTypeBooleen;
                  break;
               }
               case kChaine:
               {
                  lElement.fChaine  = new Chaine( fPile[ fSommet ].CommeChaine() );
                  lElement.fType    = kTypeChaine;
                  break;
               }
               case kListe:
               {
                  lElement.fListe   = new Liste( fPile[ fSommet ].CommeListe() );
                  lElement.fType    = kTypeListe;
                  break;
               }
               default:
                  SortieSurErreur("Type inconnu!", 2);
                  break;
            }

            // Ajouter le nombre en tete de la liste.
            laListe -> cons( lElement );

            fPile[ fSommet ].fListe             = laListe;
            fPile[ fSommet ].fTypeValeurPilum   = kListe;

            break;
         }


         case iAppend:
         {
            //VariableLogiqueTypePTR leTypeLogique = fPile[ fSommet ].TypeLogique();
            ListePTR laListe = fPile[ fSommet ].CommeListe();
            Element lElement;

            // Ajouter l'element en tete de la liste.
            switch (fPile[ fSommet ].fTypeValeurPilum)
            {
               case kFlottant:
               {
                  lElement.fNombre  = fPile[ fSommet ].CommeFlottant();
                  lElement.fType    = kTypeNombre;
                  break;
               }
               case kBooleen:
               {
                  lElement.fBooleen = fPile[ fSommet ].CommeBooleen();
                  lElement.fType    = kTypeBooleen;
                  break;
               }
               case kChaine:
               {
                  lElement.fChaine  = new Chaine( fPile[ fSommet ].CommeChaine() );
                  lElement.fType    = kTypeChaine;
                  break;
               }
               case kListe:
               {
                  lElement.fListe   = new Liste( fPile[ fSommet ].CommeListe() );
                  lElement.fType    = kTypeListe;
                  break;
               }
               default:
                  SortieSurErreur("Type inconnu!", 2);
                  break;
            }

            // Ajouter le nombre en tete de la liste.
            laListe -> append( lElement );

            fPile[ fSommet ].fListe             = laListe;
            fPile[ fSommet ].fTypeValeurPilum   = kListe;

            break;
         }


         case iConcatListes:
         {
            // Concatener la liste au sommet de la pile (L2) a celle d'en dessous (L1).
            ListePTR L2 = fPile[ fSommet-- ].CommeListe();
            ListePTR L1 = fPile[ fSommet   ].CommeListe();

            L1 -> concat( L2 );

            //delete L1;
            break;
         }


         case iLongueurListe:
         {
            ListePTR laListe                    = fPile[ fSommet ].CommeListe();

            fPile[ fSommet ].fFlottant          = laListe -> taille();
            fPile[ fSommet ].fTypeValeurPilum   = kFlottant;

            //delete laListe;
            break;
         }

         // -------------------------------------------------------------------------
         // Sinon...
         // -------------------------------------------------------------------------

         default:
            InstructionInconnue (lInstruction);
            break;
         }  // switch

      }  // while

   time_t   tempsALaFin = time (NULL);

   if (fEtatCourant != kFinNormale)
      switch (fEtatCourant)
         {
         case kExecution:
         case kErreurInterne:
            ErreurFatale (gLANGUE_Pilum -> ErreurInterne ());
            break;
         case kDebordementPile:
            ErreurFatale (gLANGUE_Pilum -> DebordementPile ());
            break;
         case kDebordementPileVersLeBas :
            ErreurFatale (gLANGUE_Pilum -> DebordementPileVersLeBas ());
            break;
         case kVariableNonInitialisee:
            ErreurFatale (gLANGUE_Pilum -> VariableNonInitialisee ());
            break;
         case kDiviseEntierParZero:
            ErreurFatale (gLANGUE_Pilum -> DiviseEntierParZero ());
            break;
         case kModuloEntierParZero:
            ErreurFatale (gLANGUE_Pilum -> ModuloEntierParZero ());
            break;
         case kDiviseFlottantParZero:
            ErreurFatale (gLANGUE_Pilum -> DiviseFlottantParZero ());
            break;
         case kInterruptionUtilisateur:
            std::cout << gLANGUE_Pilum -> InterruptionUtilisateur () << std::endl;
            break;
         default:
            std::cout << gLANGUE_Pilum -> ErreurInternePilum () << std::endl;
         }  // switch

   else
      {
      if (fGenreDExecution)
         AfficherLEtatInterne (
            gLANGUE_Pilum ->
               FinNormaleDeLExecution (),
            false,
            false );
      else
         std::cout <<
            MiseEnForme (
               gLANGUE_Pilum ->
                  FormatTempsDExecutionParPilum (),
               tempsALaFin - tempsAuDebut ) <<
            std::endl;
      }

   }  // Pilum :: Executer


// -------------------------------------------------------------------------
// Affichages
// -------------------------------------------------------------------------

void
Pilum :: AfficherLaTableDesChaines ()
   {
   Chaine   titre =
               MiseEnForme (
                  gLANGUE_Pilum ->
                     FormatContenuDeLaTableDesChaines (),
                  fTailleDesChaines );

   Chaine   separateur =
               Chaine (titre.length (), '-');

   std::cout <<
      std::endl <<
      titre <<
      std::endl <<
      separateur <<
      std::endl << std::endl;

   for (int i = 0; i < fTailleDesChaines; i ++)
      {
      std::cout <<
         fTableDesChaines [i];
      }  // for

   std::cout <<
      std::endl <<
      separateur <<
      std::endl;
   }  // Pilum :: AfficherLaTableDesChaines


void
Pilum :: AfficherLaMemoireDuCode ()
   {
   Chaine   titre =
               MiseEnForme (
                  gLANGUE_Pilum ->
                     FormatContenuDeLaMemoireDuCode (),
                  fTailleDeLaMemoireDuCode );

   Chaine   separateur =
               Chaine (titre.length (), '-');

   std::cout <<
      std::endl <<
      titre <<
      std::endl <<
      separateur <<
      std::endl << std::endl;

   for (
      long curseur = 0;
      curseur < fTailleDeLaMemoireDuCode;
      ++ curseur
      )
      {
      std::cout <<
         MiseEnForme (
            "%4d:  ",
            curseur ) <<
         fMemoireDuCode [curseur].SousFormeDeChaine () <<
         std::endl;
      } // for

   std::cout <<
      std::endl <<
      separateur <<
      std::endl;
   }  // Pilum :: AfficherLaMemoireDuCode


void
Pilum :: AfficherLaPile ()
   {
   if (fSommet == 0)
      std::cout <<
         MiseEnForme (
            gLANGUE_Pilum ->
               FormatPileVide (),
            fEnvironnementCourant ) <<
         std::endl << std::endl;
   else
      {
      long     prochainBloc = fEnvironnementCourant;

      std::cout <<
         gLANGUE_Pilum ->
            ContenuDeLaPile () <<
         std::endl;

      for (long curseur = fSommet; curseur >= 0; -- curseur)
         {
         if (curseur == fEnvironnementCourant)
            {
            std::cout <<
               gLANGUE_Pilum ->
                  EnvironnementCourant ();
            prochainBloc = fPile [prochainBloc].fAdresseDansLaPile;
            }
         else if (curseur == prochainBloc)
            {
            std::cout <<
               gLANGUE_Pilum ->
                  AutreEnvironnement ();
            prochainBloc = fPile [prochainBloc].fAdresseDansLaPile;
            }
         else
            std::cout <<
               gLANGUE_Pilum ->
                  PasUnEnvironnement ();

         if (curseur > 0)
            {
            std::cout <<
               MiseEnForme (
                  "%5d: ", curseur ) <<
               fPile [curseur].SousFormeDeChaine ();
            }

         std::cout << std::endl;
         } // for
      std::cout << std::endl;
      }
   } // Pilum :: AfficherLaPile


void
Pilum :: AfficherLEtatInterne (
   Chaine   leTitre,
   bool     afficherLeCode,
   bool     afficherLaPile )
   {
   Chaine   separateur =
               "------------------------------------------------------------------";

   std::cout <<
      std::endl <<
      separateur <<
      std::endl <<
      std::endl <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatEtatDePilum (),
         fNom ) <<
      std::endl <<
      MiseEnForme (
         "%s",
         leTitre ) <<
      std::endl << std::endl <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatTailleDeLaMemoireDuCode (),
         fTailleDeLaMemoireDuCode ) <<
      std::endl <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatLimiteSommet (),
         fLimiteSommet ) <<
      std::endl <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatTailleDesChainesPilum (),
         fTailleDesChaines ) <<
      std::endl <<
      std::endl <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatEtatCourant (),
         fEtatCourant ) <<
      std::endl <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatInstructionCourante (),
         fInstructionCourante ) <<
      std::endl <<
      std::endl <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatSommet (),
         fSommet ) <<
      std::endl <<
      MiseEnForme (
         gLANGUE_Pilum ->
            FormatEnvironnementCourant (),
         fEnvironnementCourant ) <<
      std::endl <<
      std::endl;

   if (afficherLeCode)
      AfficherLaMemoireDuCode ();

   if (afficherLaPile)
      AfficherLaPile ();

   std::cout <<
      separateur <<
      std::endl << std::endl;
   }  // Pilum :: AfficherLEtatInterne
