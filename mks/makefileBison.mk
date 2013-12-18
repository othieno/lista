# -------------------------------------------------------------------------
#	Règles communes pour les "makefile" utilisant Bison
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


# -------------------------------------------------------------------------
#	Compilation des grammaires par Bison
# -------------------------------------------------------------------------

%.tab.cc : \
		%.Bison \
		$(MAKEFILE)
	@echo ""
	bison \
		-o $@ \
		$(OPTIONS_BISON) $<
	@echo ""


# -------------------------------------------------------------------------
#	Options pour Bison
# -------------------------------------------------------------------------

OPTIONS_BISON = \
	--defines --verbose --token-table --debug --yacc

	#	Options utiles pour Bison :
	#
	#		-v, --verbose : cree le fichier ".output" necessaire pour mettre la grammaire au point
	#
	#		--yacc : pour un comportement voisin du Yacc original
	#
	#		-l, -no-lines : equivalent au '-L' de Flex, voir ci-dessus
	#
	#		-k, --token-tables : le fichier produit contient la table "yytname" des noms des terminaux
	#
	#		-d, --defines : cree le fichier ".h" pour inclusion dans lex.yy.cc
	#
	#		-o, --output-file : specifie le nom du fichier produit 


