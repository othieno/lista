# -------------------------------------------------------------------------
#	Makefile pour tester les extensions de l'étudiant-e
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
#	Le fichier source Lista d'exemple pour tester que l'extension fonctionne
# -------------------------------------------------------------------------

NOM_DU_SOURCE_DE_L_EXAMEN = \
	examen


# -------------------------------------------------------------------------
#	Utilisé par l'examinateur lors de l'examen...
# -------------------------------------------------------------------------

.PHONY : examen examenParNom intermedeExamen examenParValeur

examen : \
		$(EXAMEN)/$(NOM_DU_SOURCE_DE_L_EXAMEN).lista \
		\
		$(COMPILATEURS_COMPLETS)/ListaPredictifDescenteRecursive \
		$(COMPILATEURS_COMPLETS)/ListaFlexBison \
		\
		executables_Pilum \
		\
		examenParNom \
		intermedeExamen \
		examenParValeur


examenParNom :
	@echo ""
	@echo "====================================================================="
	@echo "==> Test pour l'examen oral!"
	@echo "====================================================================="
	@echo ""
	@echo ""
	@echo "====================================================================="
	@echo "--> On teste $(NOM_DU_SOURCE_DE_L_EXAMEN).lista d'abord par nom ..."
	@echo "====================================================================="
	@echo ""
	$(COMPILATEURS_COMPLETS)/ListaPredictifDescenteRecursive \
		-ms -sn -oc -ob \
		$(EXAMEN)/$(NOM_DU_SOURCE_DE_L_EXAMEN).lista
	$(PILUM)/Pilum_SANS_DEBUG\
		$(EXAMEN)/$(NOM_DU_SOURCE_DE_L_EXAMEN).nom_PDR
	@echo ""


intermedeExamen :
	@echo "==>"
	@echo "==> Tapez n'importe quoi, voire rien, puis un retour de chariot pour continuer..."
	@echo "==>"
	@read


examenParValeur :
	@echo ""
	@echo "====================================================================="
	@echo "--> On teste le même $(NOM_DU_SOURCE_DE_L_EXAMEN).lista par valeur..."
	@echo "====================================================================="
	@echo ""
	$(COMPILATEURS_COMPLETS)/ListaFlexBison \
		-sv -oc -ob \
		$(EXAMEN)/$(NOM_DU_SOURCE_DE_L_EXAMEN).lista
	$(PILUM)/Pilum_AVEC_DEBUG \
		-pc -pd \
		$(EXAMEN)/$(NOM_DU_SOURCE_DE_L_EXAMEN).valeur_FB
	@echo ""
