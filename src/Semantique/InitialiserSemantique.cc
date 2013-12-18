// =========================================================================
//	InitialiserSemantique.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "InitialiserSemantique.h"

#include "DescriptionDesTypes.h"

#include "DescrSemantique.h"

#include "StrategiesDEvaluation.h"

#include "AlgebreBooleenne.h"

#include "Arithmetique.h"


// -------------------------------------------------------------------------
//	InitialiserSemantique
// -------------------------------------------------------------------------

void 
InitialiserSemantique ()
	{
	//	necessaire car on ne maitrise pas 
	//	l'ordre d'initialisation
	//	des variables globales
	//	au chargement

	InitialiserDescriptionDesTypes ();
	
	InitialiserDescrSemantique ();

	InitialiserStrategiesDEvaluation ();
	
	InitialiserArithmetique ();
	
	InitialiserAlgebreBooleenne ();
	
	}	// InitialiserSemantique
