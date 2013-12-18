# -------------------------------------------------------------------------
#	Makefile pour l'exemple des 99 bouteilles de bière
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
#	Exécution de 99BottlesOfBeer.lista par évaluation directe
# -------------------------------------------------------------------------

99ed : \
		$(EXEMPLES)/99BottlesOfBeer.lista \
		\
		executables_Semantique \
		executables_Pilum
	@echo ""
	@echo "====================================================================="
	@echo "==> Direct evaluation of 99BottlesOfBeer.lista with ListaFlexBison"
	@echo "====================================================================="
	@echo ""
	@echo ""
	$(COMPILATEURS_COMPLETS)/ListaFlexBison \
		-l en -bl -nt \
		$(EXEMPLES)/99BottlesOfBeer.lista


# -------------------------------------------------------------------------
#	Exécution de 99BottlesOfBeer.lista par Pilum
# -------------------------------------------------------------------------

99pil : \
		$(EXEMPLES)/99BottlesOfBeer.lista \
		\
		executables_Semantique \
		executables_Pilum
	@echo ""
	@echo "====================================================================="
	@echo "==> Compiling 99BottlesOfBeer.lista with ListaPredictifDescenteRecursive"
	@echo "====================================================================="
	@echo ""
	@echo ""
	$(COMPILATEURS_COMPLETS)/ListaPredictifDescenteRecursive \
		-l en -bl \
		$(EXEMPLES)/99BottlesOfBeer.lista
	@echo "====================================================================="
	@echo "==> Executing 99BottlesOfBeer.need_PDR with PILUM_AVEC_DEBUG"
	@echo "====================================================================="
	@echo ""
	@echo ""
	$(PILUM)/Pilum_AVEC_DEBUG \
		-l en \
		$(EXEMPLES)/99BottlesOfBeer.need_PRD

