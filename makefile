# =========================================================================
#	Makefile pour l'implantation de Lista/Pilum
#	J. Menu - 19/10/2010
#
#	http://cui.unige.ch/DI/cours/CompInterpretes
#
#	Version $Id$ du $Date$
# =========================================================================


# -------------------------------------------------------------------------
#	Règles génériques
# -------------------------------------------------------------------------

#  Dans les actions de construction :
#		$@		indique la cible
#		$<		indique le premier prérequis
#		$^		contient l'ensemble des prérequis,avec leur chemin d'accès relatif
#		$?		contient les nomes des prérequis qui sont plus récents que la cible
#		%		est un modèle pouvant être remplacé
#		   	par un fragment du nom de fichier à construire


# -------------------------------------------------------------------------
#	Options de "make"
# -------------------------------------------------------------------------

MAKEFLAGS							= --warn-undefined-variables


# -------------------------------------------------------------------------
#	Shell à utiliser
# -------------------------------------------------------------------------

SHELL									= /bin/bash

	# car certains "sh" ont un "read" qui veut un argument, cf Ubuntu


# -------------------------------------------------------------------------
#	Dépendance de base
# -------------------------------------------------------------------------

MAKEFILE								= makefile

	#	Valeurs possibles :
	#
	#		vide
	#
	#		'makefile', pour forcer la reconstruction du tout
	#		lors des modifications des dépendances


# -------------------------------------------------------------------------
#	Les dossiers de l'implantation
# -------------------------------------------------------------------------

TOP_DIR								= .

	# Valeurs possibles :
	#
	#		., pour que les chemins d'accès soient relatifs
	#
	#		$(CURDIR), pour qu'il soient absolus


MKS									= $(TOP_DIR)/mks

SRC									= $(TOP_DIR)/src

BIN									= $(TOP_DIR)/bin

DOC									= $(TOP_DIR)/doc


EXEMPLES								= $(TOP_DIR)/exemples


EXAMEN								= $(TOP_DIR)/examen


INSTALL								= /usr/local


# -------------------------------------------------------------------------
#	Les sous-dossiers du code source de l'implantation
# -------------------------------------------------------------------------

TYPES_ET_VERSION					= $(SRC)/TypesEtVersion

SUPPORT_CPLUSPLUS					= $(SRC)/SupportCPlusPlus

LANGUES_ET_DECODAGE_D_OPTIONS	= $(SRC)/LanguesEtDecodageDOptions
LANGUES_PREDEFINIS				= $(SRC)/LanguesPredefinis

SUPPORT_FLEX						= $(SRC)/SupportFlex
LEXIQUE								= $(SRC)/Lexique

SUPPORT_FLEX_BISON				= $(SRC)/SupportFlexBison
SYNTAXE								= $(SRC)/Syntaxe

SYNTHESE_PILUM						= $(SRC)/SynthesePilum

SEMANTIQUE							= $(SRC)/Semantique

PILUM									= $(SRC)/Pilum

EXTENSIONS							= $(SRC)/Extensions


COMPILATEURS_COMPLETS			= $(SRC)/CompilateursComplets

FONCTIONS_IMBRIQUEES				= $(SRC)/FonctionsImbriquees

# -------------------------------------------------------------------------
#	Les "makefile" des sous-dossiers du code
# -------------------------------------------------------------------------

MAKEFILE_SupportCPlusPlus		= $(SUPPORT_CPLUSPLUS)/makefileSupportCPlusPlus

MAKEFILE_LanguesEtDecodageDOptions	= \
										  $(LANGUES_ET_DECODAGE_D_OPTIONS)/makefileLanguesEtDecodageDOptions
MAKEFILE_LanguesPredefinis		= $(LANGUES_PREDEFINIS)/makefileLanguesPredefinis

MAKEFILE_SupportFlex				= $(SUPPORT_FLEX)/makefileSupportFlex
MAKEFILE_Lexique					= $(LEXIQUE)/makefileLexique

MAKEFILE_SupportFlexBison		= $(SUPPORT_FLEX_BISON)/makefileSupportFlexBison
MAKEFILE_Syntaxe					= $(SYNTAXE)/makefileSyntaxe

MAKEFILE_SynthesePilum			= $(SYNTHESE_PILUM)/makefileSynthesePilum

MAKEFILE_Semantique				= $(SEMANTIQUE)/makefileSemantique

MAKEFILE_Pilum						= $(PILUM)/makefilePilum

MAKEFILE_Extensions				= $(EXTENSIONS)/makefileExtensions


MAKEFILE_CompilateursComplets	= $(COMPILATEURS_COMPLETS)/makefileCompilateursComplets

MAKEFILE_FonctionsImbriquees	= $(FONCTIONS_IMBRIQUEES)/makefileFonctionsImbriquees


MAKEFILE_bin						= $(BIN)/makefile_bin

MAKEFILE_doc						= $(DOC)/makefile_doc

MAKEFILE_exemples					= $(EXEMPLES)/makefile_exemples

# -------------------------------------------------------------------------
#	Le message d'aide, fourni par défaut
# -------------------------------------------------------------------------

help :
	@echo ""
	@echo "--> Pour:"
	@echo "    tout savoir sur la construction de Lista:          make help"
	@echo ""
	@echo "    construire et tester la base minimale:             make test"
	@echo "    construire et tester la version de l'examen:       make examen"
	@echo ""
	@echo "    construire FonctionsImbriquees:                    make fi"
	@echo ""
	@echo "    mettre en place les liens dans "bin":              make bin"
	@echo ""
	@echo "    exécution directe de '99 bouteilles de bière':     make 99ed"
	@echo "    exécution de '99 bouteilles de bière' par Pilum:   make 99pil"
	@echo ""
	@echo "    construire tous les exécutables:                   make all"
	@echo ""
	@echo "    construire la documentation:                       make doc"
	@echo ""
	@echo "    construire tous les exécutables et la doc:         make allEtDoc"
	@echo ""
	@echo "    supprimer tout ce qui a été construit:             make clean"
	@echo "    supprimer tout ce qui a été construit et la doc:   make cleanAllEtDoc"
	@echo ""
	@echo "    supprimer les fichiers de code Pilum des exemples: make clean_exemples"
	@echo ""


# -------------------------------------------------------------------------
#	Inclusion des "makefile" des sous-dossiers
# -------------------------------------------------------------------------

include \
	$(MAKEFILE_SupportCPlusPlus) \
	\
	$(MAKEFILE_LanguesEtDecodageDOptions) \
	$(MAKEFILE_LanguesPredefinis) \
	\
	$(MAKEFILE_SupportFlex) \
	$(MAKEFILE_Lexique) \
	\
	$(MAKEFILE_SupportFlexBison) \
	$(MAKEFILE_Syntaxe) \
	\
	$(MAKEFILE_SynthesePilum) \
	\
	$(MAKEFILE_Semantique) \
	\
	$(MAKEFILE_Pilum) \
	\
	$(MAKEFILE_Extensions) \
	\
	$(MAKEFILE_CompilateursComplets) \
	\
	$(MAKEFILE_FonctionsImbriquees) \
	\
	$(MAKEFILE_bin) \
	\
	$(MAKEFILE_doc) \
	\
	$(MAKEFILE_exemples)


# -------------------------------------------------------------------------
#	Où rechercher les prérequis en dehors du dossier courant
# -------------------------------------------------------------------------

VPATH	= \
	$(TYPES_ET_VERSION) \
	\
	$(SUPPORT_CPLUSPLUS) \
	\
	$(LANGUES_ET_DECODAGE_D_OPTIONS) \
	$(LANGUES_PREDEFINIS) \
	\
	$(SUPPORT_FLEX) \
	$(LEXIQUE) \
	\
	$(SUPPORT_FLEX_BISON) \
	$(SYNTAXE) \
	\
	$(SYNTHESE_PILUM) \
	\
	$(SUPPORT_SEMANTIQUE) \
	$(SEMANTIQUE) \
	\
	$(PILUM) \
	\
	$(EXTENSIONS) \
	\
	$(FONCTIONS_IMBRIQUEES) \
	\
	$(BIN) \
	\
	$(DOC) \
	\
	$(EXEMPLES)


# -------------------------------------------------------------------------
#	Inclusion des règles particulières
# -------------------------------------------------------------------------

include $(MKS)/makefileCPlusPlus.mk

include $(MKS)/makefileLangues.mk

include $(MKS)/makefileSemantique.mk

include $(MKS)/makefileFlex.mk
include $(MKS)/makefileBison.mk


include $(MKS)/makefileTest.mk

include $(MKS)/makefileAll.mk

include $(MKS)/makefile99BouteillesDeBiere.mk

include $(MKS)/makefileExamen.mk


include $(MKS)/makefileClean.mk


include $(MKS)/makefileInstall.mk

