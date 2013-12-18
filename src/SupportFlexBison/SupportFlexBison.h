// =========================================================================
//	SupportFlexBison.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __SupportFlexBison__
#define __SupportFlexBison__

#include "Langues.h"


// -------------------------------------------------------------------------
//	Librairie de support pour l'emploi combine de Flex et Bison
// -------------------------------------------------------------------------

extern "C" int						yywrap (void);
											//	il faut vivre avec ce 'extern "C"' pour Flex 2.5.x

extern bool							gPremierTerminalDejaAccepte;
extern bool							gSortirALaPremiereErreurLexicale;
extern bool							gSourceCorrectLexicalement;

void									AppondreAuSourceCumule ();
void									CompterFinDeLigne ();

Chaine								DescriptionPositionCourante ();

void									ErreurLexicale (Chaine leMessage);
void									ErreurSyntaxique (Chaine leMessage);

int									yyerror (CharPTR leMessage);

bool									AnalyserFlexBison (
											int		argc,
											CharPTR	* argv,
											bool		leModeVerbeux,
											bool		leTraduire );


#endif /* __SupportFlexBison__ */
