# -------------------------------------------------------------------------
#	Makefile pour tester que la base fonctionne
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
#	Le fichier source Lista d'exemple
# -------------------------------------------------------------------------

NOM_DU_SOURCE_DE_TEST = \
	SansFin
	

# -------------------------------------------------------------------------
#	Test de base des implantations
# -------------------------------------------------------------------------

.PHONY : test testParNom intermedeTest testParValeur

test : \
		$(EXEMPLES)/$(NOM_DU_SOURCE_DE_TEST).lista \
		\
		executables_Semantique \
		executables_Pilum \
		\
		testParNom \
		intermedeTest \
		testParValeur


testParNom :
	@echo ""
	@echo "====================================================================="
	@echo "==> Test de base des implantations de Lista/Pilum"
	@echo "====================================================================="
	@echo ""
	@echo ""
	@echo "====================================================================="
	@echo "--> On teste $(NOM_DU_SOURCE_DE_TEST).lista d'abord par nom ..."
	@echo "====================================================================="
	@echo ""
	$(COMPILATEURS_COMPLETS)/ListaPredictifDescenteRecursive \
	 	-ms -sn -oc -ob \
		$(EXEMPLES)/$(NOM_DU_SOURCE_DE_TEST).lista
	$(PILUM)/Pilum_SANS_DEBUG \
		$(EXEMPLES)/$(NOM_DU_SOURCE_DE_TEST).nom_PDR
	@echo ""


intermedeTest :
	@echo "==>"
	@echo "==> Tapez n'importe quoi, voire rien, puis un retour de chariot pour continuer..."
	@echo "==>"
	@read


testParValeur :
	@echo ""
	@echo "====================================================================="
	@echo "--> On teste le même $(NOM_DU_SOURCE_DE_TEST).lista par valeur..."
	@echo "====================================================================="
	@echo ""
	$(COMPILATEURS_COMPLETS)/ListaFlexBison \
		-sv -oc -ob \
		$(EXEMPLES)/$(NOM_DU_SOURCE_DE_TEST).lista
	$(PILUM)/Pilum_AVEC_DEBUG \
		-pc -pd \
		$(EXEMPLES)/$(NOM_DU_SOURCE_DE_TEST).valeur_FB
	@echo ""
