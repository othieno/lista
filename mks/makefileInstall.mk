# -------------------------------------------------------------------------
#	Règles communes pour installer Lista/Pilum (par 'root' en general)
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


export INSTALL_DIR = /usr/local/bin


install : \
	echo ""; \
	\
	for DOSSIER in $(SOUS_DOSSIERS_SOURCES); do \
		echo "# -------------------------------------------------------------------------"; \
		echo "--> $$DOSSIER"; \
		echo "# -------------------------------------------------------------------------"; \
		echo ""; \
		\
		$(MAKE) -C $$DOSSIER ZZZclean; \
		\
		echo ""; \
		echo ""; \
	done


uninstall : \
	echo ""; \
	\
	for DOSSIER in $(SOUS_DOSSIERS_SOURCES); do \
		echo "# -------------------------------------------------------------------------"; \
		echo "--> $$DOSSIER"; \
		echo "# -------------------------------------------------------------------------"; \
		echo ""; \
		\
		$(MAKE) -C $$DOSSIER XXXXclean; \
		\
		echo ""; \
		echo ""; \
	done

