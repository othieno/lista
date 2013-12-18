# -------------------------------------------------------------------------
#	Règles pour nettoyer tout Lista/Pilum
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
#	clean
# -------------------------------------------------------------------------

.PHONY : clean cleanAllEtDoc

clean : \
		clean_SupportCPlusPlus \
		\
		clean_LanguesEtDecodageDOptions \
		clean_LanguesPredefinis \
		\
		clean_SupportFlex \
		clean_Lexique \
		\
		clean_SupportFlexBison \
		clean_Syntaxe \
		\
		clean_SynthesePilum \
		\
		clean_Extensions \
		\
		clean_Semantique \
		\
		clean_Pilum \
		\
		clean_CompilateursComplets \
		\
		clean_FonctionsImbriquees \
		\
		clean_bin


cleanAllEtDoc : \
		clean_SupportCPlusPlus \
		\
		clean_LanguesEtDecodageDOptions \
		clean_LanguesPredefinis \
		\
		clean_SupportFlex \
		clean_Lexique \
		\
		clean_SupportFlexBison \
		clean_Syntaxe \
		\
		clean_SynthesePilum \
		\
		clean_Extensions \
		\
		clean_Semantique \
		\
		clean_Pilum \
		\
		clean_CompilateursComplets \
		\
		clean_FonctionsImbriquees \
		\
		clean_bin \
		\
		clean_doc
