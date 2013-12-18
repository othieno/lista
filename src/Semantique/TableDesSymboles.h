// =========================================================================
// TableDesSymboles.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __TableDesSymboles__
#define __TableDesSymboles__


// -------------------------------------------------------------------------
// Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsSemantique.h"


// -------------------------------------------------------------------------
// Autres inclusions
// -------------------------------------------------------------------------

#include "SupportCPlusPlus.h"

#include "DescriptionDesTypes.h"

#include "Identificateur.h"

#include <deque>


// -------------------------------------------------------------------------
// IdentNonDeclare
// -------------------------------------------------------------------------

class    IdentNonDeclare;
typedef  IdentNonDeclare      * IdentNonDeclarePTR;

class IdentNonDeclare : public Identificateur
   {
public:
                              IdentNonDeclare (
                                 Chaine                  leNom,
                                 Chaine                  leNomQualifie,
                                 VariableLogiqueTypePTR  laVariableLogiqueType );

   virtual Chaine             SousFormeDeChaine ();

   virtual void               PurgerIdent (
                                 int      lIdentation,
                                 bool     leModeVerbeux,
                                 bool     leMontrerLesDictionnaires );

   }; // IdentNonDeclare


// -------------------------------------------------------------------------
// IdentPredefini
// -------------------------------------------------------------------------

class    IdentPredefini;
typedef  IdentPredefini       * IdentPredefiniPTR;

class IdentPredefini : public Identificateur
   {
public:
                              IdentPredefini (
                                 ChaineLanguePredefinisPFM
                                                         laFonctionNom,
                                 GenreIdentificateur     leGenreIdentificateur,
                                 GenreIdentificateurFlexBison  leGenreIdentificateurFlexBison,
                                 VariableLogiqueTypePTR  laVariableLogiqueType );

   virtual Chaine             Traduction ();

protected:

   ChaineLanguePredefinisPFM  fFonctionNom;
   }; // IdentPredefini


// -------------------------------------------------------------------------
// ConstantePredefinie
// -------------------------------------------------------------------------

class    ConstantePredefinie;
typedef  ConstantePredefinie  * ConstantePredefiniePTR;

class ConstantePredefinie : public IdentPredefini
   {
public:
                              ConstantePredefinie (
                                 ChaineLanguePredefinisPFM
                                                         laFonctionNom,
                                 VariableLogiqueTypePTR  laVariableLogiqueType );

   virtual Chaine             SousFormeDeChaine ();

   virtual DescrSemantiquePTR CreerGrapheConstante () = 0;
                                 // virtuelle pure
   }; // ConstantePredefinie


// -------------------------------------------------------------------------
// Les constantes predefinies
// -------------------------------------------------------------------------

class VraiPredef : public ConstantePredefinie
   {
public:
                              VraiPredef (
                                 ChaineLanguePredefinisPFM
                                       laFonctionNom );

   virtual DescrSemantiquePTR CreerGrapheConstante ();
   };

// -------------------------------------------------------------------------

class FauxPredef : public ConstantePredefinie
   {
public:
                              FauxPredef (
                                 ChaineLanguePredefinisPFM
                                       laFonctionNom );

   virtual DescrSemantiquePTR CreerGrapheConstante ();
   };

// -------------------------------------------------------------------------

class PiPredef : public ConstantePredefinie
   {
public:
                              PiPredef (
                                 ChaineLanguePredefinisPFM
                                       laFonctionNom );

   virtual DescrSemantiquePTR CreerGrapheConstante ();
   };

// -------------------------------------------------------------------------

class EPredef : public ConstantePredefinie
   {
public:
                              EPredef (
                                 ChaineLanguePredefinisPFM
                                       laFonctionNom );

   virtual DescrSemantiquePTR CreerGrapheConstante ();
   };

// -------------------------------------------------------------------------

class VidePredef : public ConstantePredefinie
   {
public:
                              VidePredef (
                                 ChaineLanguePredefinisPFM
                                       laFonctionNom );

   virtual DescrSemantiquePTR CreerGrapheConstante ();
   };


// -------------------------------------------------------------------------
// FonctionPredefinie
// -------------------------------------------------------------------------

enum GenreFonctionPredefinie
   {
   kSi,                       kSequence,                 kIterateur,

   kFonctionListe,

   kAutreFonctionPredefinie
   };


// ------------------------------------------------------------------------

class    FonctionPredefinie;
typedef  FonctionPredefinie   * FonctionPredefiniePTR;


class FonctionPredefinie : public IdentPredefini
   {
public:
                              FonctionPredefinie (
                                 ChaineLanguePredefinisPFM  laFonctionNom,
                                 GenreFonctionPredefinie    leGenreFonctionPredefinie,
                                 GenreIdentificateurFlexBison     leGenreIdentificateurFlexBison,
                                 VariableLogiqueTypePTR     laVariableLogiqueType );

   GenreFonctionPredefinie    LeGenreFonctionPredefinie ();
   int                        NombreDeParametres ();
   VariableLogiqueTypePTR     * TypesLogiquesDesParametres ();

   virtual Chaine             DescriptionDesParametres ();
   virtual Chaine             SousFormeDeChaine ();

   virtual DescrSemantiquePTR CreerGrapheDAppelALaFonction (
                                 GenreLectureAuClavier   leGenreLectureAuClavier,
                                 DescrSemantiquePTR      * leBlocDArguments ) = 0;
                                 // virtuelle pure

protected:

   GenreFonctionPredefinie    fGenreFonctionPredefinie;
   int                        fNombreDeParametres;
   VariableLogiqueTypePTR     * fTypesLogiquesDesParametres;
                                 // tableau dynamique

   }; // FonctionPredefinie


// -------------------------------------------------------------------------
// NoeudDArbre
// -------------------------------------------------------------------------

class    NoeudDArbre;
typedef  NoeudDArbre          * NoeudDArbrePTR;

class NoeudDArbre
   {
public:
                              NoeudDArbre (IdentificateurPTR lIdentificateur);

   virtual                    ~ NoeudDArbre ();

   IdentificateurPTR          Identificateur ();
   NoeudDArbrePTR             & PlusPetits ();
   NoeudDArbrePTR             & PlusGrandsEgaux ();

private:

   IdentificateurPTR          fIdentificateur;
   NoeudDArbrePTR             fPlusPetits;
   NoeudDArbrePTR             fPlusGrandsEgaux;

   }; // NoeudDArbre


// -------------------------------------------------------------------------
// Dictionnaire
// -------------------------------------------------------------------------

class    Dictionnaire;
typedef  Dictionnaire         * DictionnairePTR;

class Dictionnaire
   {
public:
                              Dictionnaire (Chaine leNom);

   virtual                    ~ Dictionnaire ();

   Chaine                     Nom ();

   virtual bool               InsererLIdentificateur (
                                 IdentificateurPTR lIdentificateur );
                                 // retourne 'faux' si "lIdent -> fNom" déjà présent

   virtual IdentificateurPTR  ContientIdentificateur (Chaine leNom);

   virtual void               EcrireDictionnaire ();

   virtual void               PurgerDictionnaire (
                                 int      lIdentation,
                                 bool     leModeVerbeux,
                                 bool     leMontrerLesDictionnaires );


protected:

   Chaine                     fNom;
   NoeudDArbrePTR             fRacine;


private:

   int                        fTaille;
   int                        fProfondeur;

   bool                       InsererDansLArbre (
                                 NoeudDArbrePTR       & laRacine,
                                 IdentificateurPTR    lIdentificateur,
                                 int                  laProfondeur );

   void                       EcrireLArbre (NoeudDArbrePTR laRacine);

   void                       PurgerLArbre (
                                 NoeudDArbrePTR    laRacine,
                                 int               lIdentation,
                                 bool              leModeVerbeux,
                                 bool              leMontrerLesDictionnaires );

   }; // Dictionnaire


// -------------------------------------------------------------------------
// NiveauDeDeclaration
// -------------------------------------------------------------------------

class    NiveauDeDeclaration;
typedef  NiveauDeDeclaration  * NiveauDeDeclarationPTR;

class NiveauDeDeclaration
   {
public:
                              NiveauDeDeclaration (Chaine leNom);
                              NiveauDeDeclaration (DictionnairePTR leDictionnaire);

   virtual                    ~ NiveauDeDeclaration ();

   Chaine                     Nom ();

   DictionnairePTR            DictionnaireLocal ();

private:

   Chaine                     fNom;
   DictionnairePTR            fDictionnaireLocal;

   }; // NiveauDeDeclaration


typedef std::deque <NiveauDeDeclarationPTR>
                              PileDesNiveauxDeDeclaration;
typedef PileDesNiveauxDeDeclaration
                              * PileDesNiveauxDeDeclarationPTR;


// -------------------------------------------------------------------------
// TableDesSymboles
// -------------------------------------------------------------------------

class    TableDesSymboles;
typedef  TableDesSymboles     * TableDesSymbolesPTR;

class TableDesSymboles
   {
public:
                              TableDesSymboles (
                                 bool  leModeVerbeux =
                                          false,
                                 bool  leMontrerLesDictionnaires =
                                          false );

   virtual                    ~ TableDesSymboles ();


   void                       Empiler (
                                 NiveauDeDeclarationPTR leNiveauDeDeclaration );

   NiveauDeDeclarationPTR     Sommet ();

   NiveauDeDeclarationPTR     Desempiler ();

   void                       InsererLIdentificateur (
                                 IdentificateurPTR    lIdent,
                                 bool                 & dejaPresentAuSommet,
                                 IdentificateurPTR    & autreDeclarationMasquee );

   IdentificateurPTR          RechercherLeNom (
                                 Chaine            leNom,
                                 DictionnairePTR   & leDictionnaire,
                                 bool              ignorerSommet );
                                 // retourne 'NULL' si "leNom" pas trouvé

   void                       Ecrire (Chaine leContexte);

   void                       ModeVerbeux (bool leModeVerbeux);
   void                       MontrerLesDictionnaires (bool leMontrerLesDictionnaires);

private:

   bool                       fModeVerbeux;
   bool                       fMontrerLesDictionnaires;

   PileDesNiveauxDeDeclaration
                              fPileDesNiveauxDeDeclaration;

   }; // TableDesSymboles


#endif /* __TableDesSymboles__ */
