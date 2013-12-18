// =========================================================================
// DecodageDOptionsLexique.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __DecodageDOptionsLexique__
#define __DecodageDOptionsLexique__


#include "Types.h"

#include "DecodageDOptions.h"


// --------------------------------------------------------------------------
// OptionsLexique
// --------------------------------------------------------------------------

class    OptionsLexique;
typedef  OptionsLexique       * OptionsLexiquePTR;

class OptionsLexique
   {
public:
                              OptionsLexique (
                                 bool  leRenoncerSurErreurLexicale,
                                 bool  leModeVerbeux,
                                 bool  leMontrerLesTerminaux,
                                 bool  leTraduire );

   bool                       RenoncerSurErreurLexicale ();

   bool                       ModeVerbeux ();

   bool                       MontrerLesTerminaux ();
   bool                       Traduire ();

private:

   bool                       fRenoncerSurErreurLexicale;

   bool                       fModeVerbeux;

   bool                       fMontrerLesTerminaux;
   bool                       fTraduire;
   }; // OptionsLexique


inline
bool
OptionsLexique :: RenoncerSurErreurLexicale ()
   { return fRenoncerSurErreurLexicale; }

inline
bool
OptionsLexique :: MontrerLesTerminaux ()
   { return fMontrerLesTerminaux; }

inline
bool
OptionsLexique :: Traduire ()
   { return fTraduire; }


enum TerminalP
   {
   t_FIN,                  /* 0, sera retourne par 'yylex ()' lorsque 'yywrap ()'
                           retournera lui-meme une valeur non-nulle */

   t_NOMBRE,               t_IDENT,             t_CHAINE,

   t_PAR_GAUCHE,           t_PAR_DROITE,
   t_EGALE,                t_VIRGULE,

   t_PLUS,                 t_MOINS,             t_FOIS,              t_DIVISE,
   t_CONCAT,

   t_CROCHET_GAUCHE,       t_CROCHET_DROIT,

   t_POINT_VIRGULE,        t_INTERROGE
   };


const char                    SENTINELLE = ';';
                              // pour optimiser la detection de la fin
                              // du code source Lista


// -------------------------------------------------------------------------
// DecodageDOptionsLexique
// -------------------------------------------------------------------------

class    DecodageDOptionsLexique;
typedef  DecodageDOptionsLexique
                              * DecodageDOptionsLexiquePTR;

class DecodageDOptionsLexique : public DecodageDOptions
   {
public:
                              DecodageDOptionsLexique (
                                 int         leNbDArguments,
                                 CharPTR  lesArguments [],
                                 ChaineOptionsPFM
                                             laFonctionVersion,
                                 bool        lAnalyseLexicalePure );
                                    // il y des sous-classes pour
                                    // la syntaxe et la semantique


   virtual void               Initialiser ();

   virtual void               Langue (Chaine argument);

   virtual void               Groupees (Chaine argument);

   virtual void               MontrerLeCodeSource (Chaine argument);
   virtual void               MontrerLesTerminaux (Chaine argument);
   virtual void               SortirALaPremiereErreurLexicale (
                                 Chaine argument );


   bool                       MontrerLeCodeSource ();
   bool                       MontrerLesTerminaux ();

   bool                       SortirALaPremiereErreurLexicale ();

   virtual void               ArgumentsNonOptions (Chaine argument);


protected:

   bool                       fAnalyseLexicalePure;

   bool                       fMontrerLeCodeSource;
   bool                       fMontrerLesTerminaux;

   bool                       fSortirALaPremiereErreurLexicale;

   }; // DecodageDOptionsLexique


typedef TemplateAssocInstanceMethodeOptions
                              <DecodageDOptionsLexique>
                                 AssocDecodageDOptionsLexique;


#endif /* __DecodageDOptionsLexique__ */

