// =========================================================================
// Pilum.h
//  J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __Pilum__
#define __Pilum__


#include "SupportCPlusPlus.h"

#include "Langues.h"


#include <iostream>
#include <fstream>


// -------------------------------------------------------------------------
// Types de base
// -------------------------------------------------------------------------

typedef  long                 AdresseDansLeCode;
typedef  long                 AdresseDansLaPile;

struct AccesStatique
   // sans constructeur: utilise dans une union dans "InstrPilum"
   {
   int                        fDifferenceStatique;
   int                        fDeplacement;
   };


// -------------------------------------------------------------------------
// Les valeurs manipulées par la machine Pilum
// -------------------------------------------------------------------------

enum TypeValeurPilum
   {
   kValeurInconnue,

   kLienDynamique,            kLienStatique,             kAdresseDeRetour,
   kAdresseThunk,             kLienStatiqueFutur,
   kAdresseDansLaPile,

   kEntier,                   kFlottant,                 kBooleen,
   kCaractere,                kChaine,
   kListe,

   kMarqueBlocDActivationDeFonction,
   kMarqueBlocDActivationDeThunk

   };

struct   ValeurPilum;
typedef  ValeurPilum          * ValeurPilumPTR;

struct ValeurPilum
   {
                              ValeurPilum ();   // pour l'initialisation


   Chaine                     TypeSousFormeDeChaine ();

   // methodes de TEST DE TYPE DYNAMIQUE
   int                        CommeEntier ();
   double                     CommeFlottant ();
   bool                       CommeBooleen ();
   CharPTR                    CommeChaine ();
   ListePTR							CommeListe ();

   Chaine                     SousFormeDeChaine ();

   TypeValeurPilum            fTypeValeurPilum;

   union
      {
      AdresseDansLeCode       fAdresseDansLeCode;
      AdresseDansLaPile       fAdresseDansLaPile;

      long                    fEntier;
      double                  fFlottant;
      bool                    fBooleen;
      char                    fCaractere;
      ListePTR						fListe;
      CharPTR                 fChaine;
                                 // Chaine (std::string) est un objet,
                                 // et donc pas autorise dans une union
      }; // union

   }; // ValeurPilum


// -------------------------------------------------------------------------
// Les instructions de la machine Pilum
// -------------------------------------------------------------------------

enum CodeOpPilum
   {
   iInstructionInconnue,

   iHalte,

   iCommentaire,              iEmpilerMarqueBlocDActivation,

   iReserver,                 iDesempiler,
   iStocker,                  iDupliquer,

   iEmpilerValeur,            iEmpilerAdresse,           iEmpilerLienStatique,
   iEmpilerEntier,            iEmpilerFlottant,          iEmpilerBooleen,
   iEmpilerCaractere,         iEmpilerChaine,            iEmpilerValInconnue,

   iSauter,                   iSauterSiFaux,
   iAppel,                    iRetourDeFonction,         iRetourDeProcedure,
   iEmpilerDescripteurDeThunk,
   iEvaluerThunk,             iEvaluerThunkAvecMarqueBlocDActivation,

   iLireEntier,               iLireFlottant,             iLireBooleen,
   iLireCaractere,            iLireChaine,
   iEcrireEntier,             iEcrireFlottant,           iEcrireBooleen,
   iEcrireCaractere,          iEcrireChaine,             iEcrireFinDeLigne,
   iFormaterFlottant,

   iConvertirEntierEnFlottant,      iTronquerFlottantEnEntier,

   iIncrEntier,               iDecrEntier,
   iIncrFlottant,             iDecrFlottant,
   iMoins1Entier,             iMoins1Flottant,

   iAbsEntier,                iAbsFlottant,
   iPair,

   iPlusEntier,               iMoinsEntier,
   iFoisEntier,               iDiviseEntier,             iModuloEntier,
   iPlusFlottant,             iMoinsFlottant,
   iFoisFlottant,             iDiviseFlottant,

   iNon,                      iEt,                       iOu,

   iEgaleEntier,              iInfEntier,                iInfEgaleEntier,
   iDifferentEntier,          iSupEgaleEntier,           iSupEntier,
   iEgaleFlottant,            iInfFlottant,              iInfEgaleFlottant,
   iDifferentFlottant,        iSupEgaleFlottant,         iSupFlottant,
   iEgaleChaine,              iInfChaine,                iInfEgaleChaine,
   iDifferentChaine,          iSupEgaleChaine,           iSupChaine,

   iRacine,                   iHasard,
   iSin,                      iCos,                      iArcTan,
   iLog,                      iExp,

   iGenererListe,
   iLireListe,
   iEcrireListe,
   iCar,                      iCdr,                      iCons,
   iAppend,                   iConcatListes,             iLongueurListe,

   iLongueurChaine,           iChaineVide,               iContientChaine,
   iConcatChaines,            iRepliquerChaine,          iRemplacerChaine

   }; // CodeOpPilum


struct   InstructionPilum;
typedef  InstructionPilum     * InstructionPilumPTR;

struct InstructionPilum
   {
                              InstructionPilum ();
                                 // pour gérer l'initialisation

   Chaine                     CodesOpSousFormeDeChaine ();

   Chaine                     SousFormeDeChaine ();

   CodeOpPilum                fCodeOpPilum;

   union
      {
      AdresseDansLeCode       fAdresseDansLeCode;

      long                    fEntier;
      double                  fFlottant;
      bool                    fBooleen;
      char                    fCaractere;
      CharPTR                 fChaine;
                                 // Chaine (std::string) est un objet,
                                 // et donc pas autorise dans une union

      AccesStatique           fAccesStatique;
      }; // union

   }; // InstructionPilum

const int                     kTailleInstructionPilum =
                                 sizeof (InstructionPilum);

const int                     kLargeurChampCodeOpPilum = 30;


// -------------------------------------------------------------------------
// Les etats de la machine Pilum
// -------------------------------------------------------------------------

enum EtatPilum
   {
   kErreurInterne,

   kExecution,                kFinNormale,
   kInterruptionUtilisateur,

   kDebordementPile,          kDebordementPileVersLeBas,
   kVariableNonInitialisee,

   kDiviseEntierParZero,      kModuloEntierParZero,
   kDiviseFlottantParZero
   };


// --------------------------------------------------------------------------
// OptionsPilum
// --------------------------------------------------------------------------

const long                    kTailleDeLaPileParDefaut      = 2000;

const int                     kTailleDesLiensObligatoires   = 2;
                                 // adresse de retour et lien dynamique

const int                     kPosLienStatique              = -2;
                                 // pas toujours utilise


enum GenreDExecution
   {
   kEnContinu,

   kPasAPas,                  kPasAPasAvecAffichageDeLaPile,

   kArretSurAppelOuRetour,    kArretSurAppelOuRetourAvecAffichageDeLaPile
   };


class    OptionsPilum;
typedef  OptionsPilum         * OptionsPilumPTR;

class OptionsPilum
   {
public:
                              OptionsPilum (
                                 bool              leModeVerbeux,
                                 bool              leMontrerLeCode,
                                 long              laTailleDeLaPile,
                                 GenreDExecution   leGenreDExecution,
                                 bool              leMontrerLesCommandesInitialement );

   bool                       ModeVerbeux ();
   bool                       MontrerLeCode ();
   long                       TailleDeLaPile ();
   GenreDExecution            LeGenreDExecution ();
   bool                       MontrerLesCommandesInitialement ();

private:

   bool                       fModeVerbeux;
   bool                       fMontrerLeCode;
   long                       fTailleDeLaPile;
   GenreDExecution            fGenreDExecution;
   bool                       fMontrerLesCommandesInitialement;

   }; // OptionsPilum


inline
bool
OptionsPilum :: ModeVerbeux ()
   { return fModeVerbeux; }

inline
bool
OptionsPilum :: MontrerLeCode ()
   { return fMontrerLeCode; }

inline
long
OptionsPilum :: TailleDeLaPile ()
   { return fTailleDeLaPile; }

inline
GenreDExecution
OptionsPilum :: LeGenreDExecution ()
   { return fGenreDExecution; }

inline
bool
OptionsPilum :: MontrerLesCommandesInitialement ()
   { return fMontrerLesCommandesInitialement; }


// -------------------------------------------------------------------------
// La machine Pilum
// -------------------------------------------------------------------------

class    Pilum;
typedef  Pilum                * PilumPTR;

class Pilum
   {
public:
                              Pilum (
                                 Chaine            leNom,
                                 Chaine            nomDuFichierBinaire,
                                 OptionsPilumPTR   lesOptionsPilum );

   virtual                    ~ Pilum ();


   bool                       ModeVerbeux ();
   GenreDExecution            LeGenreDExecution ();

   virtual void               Interrompre ();

   virtual void               AfficherLaTableDesChaines ();
   virtual void               AfficherLaMemoireDuCode ();
   virtual void               AfficherLaPile ();

   virtual void               AfficherLEtatInterne (
                                 Chaine   leTitre           = "",
                                 bool     afficherLeCode    = false,
                                 bool     afficherLaPile    = false );

   virtual void               ModePasAPas ();
   virtual void               ModeContinu ();

   virtual void               ModeArretSurAppelOuRetour ();

   virtual void               ModePasAPasAvecAffichageDeLaPile ();
   virtual void               ModeArretSurAppelOuRetourAvecAffichageDeLaPile ();

   void                       ErreurFatale (Chaine message);

   void                       ChargerBinaire (Chaine nomDuFichierBinaire);

   void                       ActionAvantInteraction ();
   void                       ActionAvantChaqueCommande ();
   void                       ActionApresChaqueCommande ();
   void                       ActionApresInteraction ();

   void                       Executer (
                                 AdresseDansLeCode adresseDeDepart = 0 );

   virtual void               InstructionInconnue (
                                 InstructionPilum lInstruction );


protected:

   void                       CreerLaTableDesChaines ();
   void                       CreerLaMemoireDuCode (
                                 long tailleDeLaMemoireDuCode );
   void                       CreerLaPile (long tailleDeLaPile);

   void                       DetruireLesChaines ();
   void                       DetruireLaMemoireDuCode ();
   void                       DetruireLaPile ();

   void                       LireLesChaines (
                                 Chaine         nomDuFichierBinaire,
                                 std::ifstream  & fichierBinaire );
   void                       LireLesInstructions (
                                 Chaine         nomDuFichierBinaire,
                                 std::ifstream  & fichierBinaire );

   AdresseDansLaPile          RemonteeStatique (AccesStatique lAccesStatique);


   Chaine                     fNom;
   OptionsPilumPTR            fOptionsPilum;

   CharPTR                    fTableDesChaines;
   long                       fTailleDesChaines;

   InstructionPilumPTR        fMemoireDuCode;
   long                       fTailleDeLaMemoireDuCode;
   AdresseDansLeCode          fInstructionCourante;

   ValeurPilumPTR             fPile;
   long                       fSommet; // 0 <=> pile vide
   long                       fLimiteSommet;

   EtatPilum                  fEtatCourant;
   AdresseDansLaPile          fEnvironnementCourant;

   bool                       fModeVerbeux;

   GenreDExecution            fGenreDExecution;

   }; // Pilum


#endif /* __Pilum__ */
