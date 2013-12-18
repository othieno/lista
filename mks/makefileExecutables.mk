# -------------------------------------------------------------------------
#	Makefile pour la construction des exécutables
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
#	Exécutables de base
# -------------------------------------------------------------------------

EXECUTABLES_DE_BASE = \
	\
	$(SRC)/Semantique/ListaPredictifDescenteRecursive \
	\
	$(SRC)/Semantique/ListaFlexBison \
	\
	$(SRC)/Pilum/Pilum \
	$(SRC)/Pilum/PILUM_DEBUG


EXECUTABLES_COMPLEMENTAIRES = \
	\
	$(SRC)/Lexique/ListaLexPredictif \
	$(SRC)/Syntaxe/ListaSyntPredictifDescenteRecursive \
	$(SRC)/Semantique/ListaSemPredictifDescenteRecursive \
	\
	$(SRC)/Lexique/ListaLexFlex \
	$(SRC)/Syntaxe/ListaSyntFlexBison \
	$(SRC)/Semantique/ListaSemFlexBison \
	\
	$(SRC)/FonctionsImbriquees/FonctionsImbriquees


# -------------------------------------------------------------------------
#	Tous les exécutables
# -------------------------------------------------------------------------

TOUS_LES_EXECUTABLES = \
	$(EXECUTABLES_DE_BASE) \
	$(EXECUTABLES_COMPLEMENTAIRES)


# -------------------------------------------------------------------------
#	Exécutables PrédictifDescenteRécursive
# -------------------------------------------------------------------------

EXECUTABLES_PREDICTIF_DESCENTE_RECURSIVE = \
	$(SRC)/Lexique/ListaLexPredictif \
	$(SRC)/Syntaxe/ListaPredictifDescenteRecursive \
	$(SRC)/Semantique/ListaSemPredictifDescenteRecursive \
	$(SRC)/Semantique/ListaPredictifDescenteRecursive \
	\
	$(SRC)/Pilum/Pilum \
	$(SRC)/Pilum/PILUM_DEBUG


# -------------------------------------------------------------------------
#	Exécutables FlexBison
# -------------------------------------------------------------------------

EXECUTABLES_FLEX_BISON = \
	$(SRC)/Lexique/ListaLexFlex \
	$(SRC)/Syntaxe/ListaSyntFlexBison \
	$(SRC)/Semantique/ListaSemFlexBison \
	$(SRC)/Syntaxe/ListaFlexBison \
	\
	$(SRC)/Pilum/Pilum \
	$(SRC)/Pilum/PILUM_DEBUG


# -------------------------------------------------------------------------
#	Exécutables complémentaires
# -------------------------------------------------------------------------

complements : \
		$(EXECUTABLES_COMPLEMENTAIRES)


# -------------------------------------------------------------------------
#	Exécutables PrédictifDescenteRécursive
# -------------------------------------------------------------------------

pdr : \
		$(EXECUTABLES_PREDICTIF_DESCENTE_RECURSIVE)


# -------------------------------------------------------------------------
#	Exécutables FlexBison
# -------------------------------------------------------------------------

fb : \
		$(EXECUTABLES_FLEX_BISON)
