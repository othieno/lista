# -------------------------------------------------------------------------
#	Makefile pour la créer la documentation
#	J. Menu - 19/10/2010
# -------------------------------------------------------------------------


TYPE_D_OS		= $(shell uname -s)


ifeq ($(TYPE_D_OS), Darwin)


DOXYGEN = \
	/Applications/Doxygen-1.4.7/Doxygen.app/Contents/Resources/doxygen
		# cf Doxygen-1.4.7.dmg

else

DOXYGEN = \
	/usr/local/bin/doxygen
		# par exemple

endif



DOXYGEN_CONFIG = \
	Doxyfile

MODELE_DOXYGEN_CONFIG = \
	ModeleDoxyfile


doc : \
		$(DOXYGEN_CONFIG)
	$(DOXYGEN) $<
