# -------------------------------------------------------------------------
#	Règles communes pour tous les makefile de Lista/Pilum
#	J. Menu - 03/10/2010
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
#	Environnement
# -------------------------------------------------------------------------

export DOSSIER_COURANT := $(shell pwd)
export TYPE_D_OS       := $(shell uname -s)


# -------------------------------------------------------------------------
#	Dépendance de base
# -------------------------------------------------------------------------

export MAKEFILE	= makefile

	#	Valeur possible : 'makefile', pour forcer la reconstruction du tout
	#	lors des modifications des dependances


# -------------------------------------------------------------------------
#	Shell à utiliser
# -------------------------------------------------------------------------

export SHELL	= /bin/bash

	# car certains sh ont un "read" qui veut un argument, cf Ubuntu


# -------------------------------------------------------------------------
#	Les sous-dossiers de l'implantation
# -------------------------------------------------------------------------

export MKS_DIR		= $(START_DIR)/mks

export SOURCES_DIR	= $(START_DIR)/src
export INCLUDE_DIR	= $(START_DIR)/include
export BIN_DIR			= $(START_DIR)/bin
export EXAMPLES_DIR	= $(START_DIR)/examples
export EXAMEN_DIR		= $(START_DIR)/examen


DOSSIER_include				= $(START_DIR)/include

DOSSIER_SupportCPlusPlus	= $(SOURCES_DIR)/SupportCPlusPlus

DOSSIER_Langues				= $(SOURCES_DIR)/Langues
DOSSIER_LanguesPredefinis	= $(SOURCES_DIR)/LanguesPredefinis

DOSSIER_SupportFlex			= $(SOURCES_DIR)/SupportFlex
DOSSIER_Lexique				= $(SOURCES_DIR)/Lexique

DOSSIER_SupportFlexBison	= $(SOURCES_DIR)/SupportFlexBison
DOSSIER_Syntaxe				= $(SOURCES_DIR)/Syntaxe

DOSSIER_MachinePilum			= $(SOURCES_DIR)/MachinePilum
DOSSIER_SynthesePilum		= $(SOURCES_DIR)/SynthesePilum

DOSSIER_Semantique			= $(SOURCES_DIR)/Semantique

DOSSIER_SyntheseFonctionsImbriquees	= \
 									  $(SOURCES_DIR)/SyntheseFonctionsImbriquees

DOSSIER_Extensions			= $(SOURCES_DIR)/Extensions

# -------------------------------------------------------------------------
#	Exécutables de base
# -------------------------------------------------------------------------

EXECUTABLES_DE_BASE = \
	\
	../src/Semantique/ListaPredictifDescenteRecursive \
	\
	../src/Semantique/ListaFlexBison \
	\
	../src/MachinePilum/Pilum \
	../src/MachinePilum/PILUM_DEBUG


EXECUTABLES_COMPLEMENTAIRES = \
	../src/Lexique/ListaLexPredictif \
	../src/Syntaxe/ListaSyntPredictifDescenteRecursive \
	../src/Semantique/ListaSemPredictifDescenteRecursive \
	\
	../src/Lexique/ListaLexFlex \
	../src/Syntaxe/ListaSyntFlexBison \
	../src/Semantique/ListaSemFlexBison \
	\
	../src/SyntheseFonctionsImbriquees/FonctionsImbriquees


# -------------------------------------------------------------------------
#	Tous les exécutables
# -------------------------------------------------------------------------

TOUS_LES_EXECUTABLES = \
	$(EXECUTABLES_DE_BASE) \
	$(EXECUTABLES_COMPLEMENTAIRES)

# -------------------------------------------------------------------------
#	Exécutables PrédictifDescenteRécursive
# -------------------------------------------------------------------------

EXECUTABLES_PDR = \
	../src/Lexique/ListaLexPredictif \
	../src/Syntaxe/ListaPredictifDescenteRecursive \
	../src/Semantique/ListaSemPredictifDescenteRecursive \
	../src/Semantique/ListaPredictifDescenteRecursive \
	\
	../src/MachinePilum/Pilum \
	../src/MachinePilum/PILUM_DEBUG

# -------------------------------------------------------------------------
#	Exécutables FlexBison
# -------------------------------------------------------------------------

EXECUTABLES_FB = \
	../src/Lexique/ListaLexFlex \
	../src/Syntaxe/ListaSyntFlexBison \
	../src/Semantique/ListaSemFlexBison \
	../src/Syntaxe/ListaFlexBison \
	\
	../src/MachinePilum/Pilum \
	../src/MachinePilum/PILUM_DEBUG
