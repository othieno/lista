# -------------------------------------------------------------------------
#	Règles communes pour les "makefile" utilisant Flex
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------

# Il faut utiliser Flex 2.5.4 au minimun


# -------------------------------------------------------------------------
#	Compilation des grammaires par Flex
# -------------------------------------------------------------------------

%.yy.cc : \
		%.Flex \
		$(MAKEFILE)
	@echo ""
	flex \
		-o$@ \
		$(OPTIONS_FLEX) $<
	@echo ""


# -------------------------------------------------------------------------
#	Options pour Flex
# -------------------------------------------------------------------------

OPTIONS_FLEX = \
	-v -s

	#	Options utiles pour Flex :
	#
	#		-v : pour avoir des statistiques sur l'analyseur synthetisé
	#
	#		-s : supprime la règle d'ECHO par défaut, utile pour repérer les
	#			  spécifications incomplètes
	#
	#		-l : pour un comportement voisin de celui du Lex original
	#
	#		-L : pour que les "#line" se réfèrent au fichier produit, et non au fichier source
	#			  (equivalent à '%option yylineno' dans le fichier source)
	#
	#		-f : pour avoir un analyseur plus rapide, mais avec des tables plus grosses
	#			  (incompatible avec '-L')
	#
	#		NOTE : Flex 2.5.x veut que "yywrap" soit 'extern "C"', c'est ainsi!
