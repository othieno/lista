// =========================================================================
// TerminauxFlexLista.h
// J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
// Version $Id$ du $Date$
// =========================================================================


#ifndef __TerminauxFlexLista__
#define __TerminauxFlexLista__

// -------------------------------------------------------------------------
// Types pour la specificatin de Lista dans Flex
// -------------------------------------------------------------------------

// Les terminaux du langage
// ------------------------

enum TerminalFlexLista
   {
   t_FIN,               // 0, sera retourne par 'yylex ()' lorsque 'yywrap ()'
                        // retournera lui-meme une valeur non-nulle

   t_NOMBRE,            t_IDENT,             t_CHAINE,

   t_PAR_GAUCHE,        t_PAR_DROITE,
   t_EGALE,             t_VIRGULE,

   t_PLUS,              t_MOINS,             t_FOIS,              t_DIVISE,
   t_CONCAT,

   t_CROCHET_GAUCHE,    t_CROCHET_DROIT,

   t_POINT_VIRGULE,     t_INTERROGE
   };


// Description du terminal courant
// -------------------------------

union DescriptionTerminal
   {
   double                     fNombre;
   CharPTR                    fIdent;
   CharPTR                    fChaine;
   };


DescriptionTerminal           yylval;


#endif /* __TerminauxFlexLista__ */
