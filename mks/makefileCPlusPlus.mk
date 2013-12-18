# -------------------------------------------------------------------------
#	Règles communes pour les "makefile" utilisant g++
#	J. Menu - 19/10/2010
#
#	Version $Id$ du $Date$
# -------------------------------------------------------------------------


export CXX 				= g++


export OPTIONS_CXX	= \
								-ggdb \
								\
								-Wall $(OPTIONS_LANGUES) \
								\
								-DLISTES

	#	Options utiles pour g++ :
	#		-v
	#
	#		-Wall pour avoir tous les messages d'avertissement
	#
	#		-ggdb ou -ggdb3 pour pouvoir utiliser "gdb executable core_dump"
	#			Penser à
	#			 	"limit coredumpsize unlimited"
	#			ou
	#				"ulimit -c unlimited",
	#			selon le shell utilisé!
	#
	#		-save-temps pour garder les fichiers *.ii et *.s
