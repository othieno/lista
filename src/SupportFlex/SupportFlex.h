// =========================================================================
//	SupportFlex.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __SupportFlex__
#define __SupportFlex__

#include "Langues.h"


// -------------------------------------------------------------------------
//	Librairie de support pour l'emploi de Flex
// -------------------------------------------------------------------------

extern "C" int						yywrap (void);
											//	il faut vivre avec ce 'extern "C"' pour Flex 2.5.x

extern bool							gPremierTerminalDejaAccepte;
extern bool							gSortirALaPremiereErreurLexicale;
extern bool							gSourceCorrectLexicalement;

void									AppondreAuSourceCumule ();
void									CompterFinDeLigne ();

Chaine								DescriptionPositionCourante ();

void									ErreurLexicale (Chaine leFormat);

void									AnalyserF (
											int		argc,
											CharPTR	* argv,
											bool		leModeVerbeux );


#endif /* __SupportFlex__ */
