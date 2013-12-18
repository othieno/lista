# -------------------------------------------------------------------------
#	Règles pour construire tout Lista/Pilum
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
#	all
# -------------------------------------------------------------------------

.PHONY : all

all : \
		objets_SupportCPlusPlus \
		\
		objets_LanguesEtDecodageDOptions \
		objets_LanguesPredefinis \
		\
		objets_SupportFlex \
		executables_Lexique \
		\
		objets_SupportFlexBison \
		executables_Syntaxe \
		\
		objets_SynthesePilum \
		\
		objets_Extensions \
		\
		executables_Semantique \
		\
		executables_Pilum \
		\
		executables_CompilateursComplets \
		\
		executable_FonctionsImbriquees \
		\
		liens_bin


allEtDoc : \
		objets_SupportCPlusPlus \
		\
		objets_LanguesEtDecodageDOptions \
		objets_LanguesPredefinis \
		\
		objets_SupportFlex \
		executables_Lexique \
		\
		objets_SupportFlexBison \
		executables_Syntaxe \
		\
		objets_SynthesePilum \
		\
		objets_Extensions \
		\
		executables_Semantique \
		\
		executables_Pilum \
		\
		executables_CompilateursComplets \
		\
		executable_FonctionsImbriquees \
		\
		liens_bin \
		\
		doc
