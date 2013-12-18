// =========================================================================
//	LanguesPilum.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "LanguesPilum.h"


#include "Langues.h"
#include <iostream>

#include <cstdlib>


// -------------------------------------------------------------------------
//	LanguePilum
// -------------------------------------------------------------------------

LanguePilum :: LanguePilum ()
	{}

LanguePilum :: ~ LanguePilum ()
	{}


// -------------------------------------------------------------------------
//	LanguePilumFR
// -------------------------------------------------------------------------

LanguePilumFR :: LanguePilumFR ()
	{}


// -------------------------------------------------------------------------

Chaine
LanguePilumFR :: LienDynamique ()
	{ return "LienDynamique"; }
Chaine
LanguePilumFR :: LienStatique ()
	{ return "LienStatique"; }

Chaine
LanguePilumFR :: AdresseDeRetour ()
	{ return "AdresseDeRetour"; }
Chaine
LanguePilumFR :: AdresseThunk ()
	{ return "AdresseThunk"; }
Chaine
LanguePilumFR :: LienStatiqueFutur ()
	{ return "LienStatiqueFutur"; }

Chaine
LanguePilumFR :: AdresseDansLaPile ()
	{ return "AdresseDansLaPile"; }


// -------------------------------------------------------------------------

Chaine
LanguePilumFR :: ValeurInconnue ()
	{ return "ValeurInconnue"; }


// -------------------------------------------------------------------------

Chaine
LanguePilumFR :: FormatCommeEntier ()
	{
	return
		"Une valeur entiere Pilum est attendue, "
		"on a affaire a une valeur du type %s";
	}
Chaine
LanguePilumFR :: FormatCommeFlottant ()
	{
	return
		"Une valeur flottante Pilum est attendue, "
		"on a affaire a une valeur du type %s";
	}
Chaine
LanguePilumFR :: FormatCommeBooleen ()
	{
	return
		"Une valeur booleenne Pilum est attendue, "
		"on a affaire a une valeur du type %s";
	}
Chaine
LanguePilumFR :: FormatCommeChaine ()
	{
	return
		"Une valeur chaine Pilum est attendue, "
		"on a affaire a une valeur du type %s";
	}



// -------------------------------------------------------------------------

Chaine
LanguePilumFR :: Entier ()
	{ return "Entier"; }
Chaine
LanguePilumFR :: Flottant ()
	{ return "Flottant"; }
Chaine
LanguePilumFR :: Booleen ()
	{ return "Booleen"; }
Chaine
LanguePilumFR :: Caractere ()
	{ return "Caractere"; }
Chaine
LanguePilumFR :: Chaine_ ()
	{ return "Chaine"; }


Chaine
LanguePilumFR :: MarqueBlocDActivationDeFonction ()
	{ return "MarqueBlocDActivationDeFonction"; }
Chaine
LanguePilumFR :: MarqueBlocDActivationDeThunk ()
	{ return "MarqueBlocDActivationDeThunk"; }

/* JMI
Chaine
LanguePilumFR :: MarqueBlocDActivation ()
	{ return "MarqueBlocDActivation"; }
*/

Chaine
LanguePilumFR :: FormatValeurInconnue ()
	{ return "* ValeurInconnue *"; }

Chaine
LanguePilumFR :: FormatLienDynamique ()
	{ return "LD                  %3d"; }

Chaine
LanguePilumFR :: FormatLienStatique ()
	{ return "LS (lien statique)  %3d"; }

Chaine
LanguePilumFR :: FormatAdresseDeRetour ()
	{ return "AR                  %3d"; }

Chaine
LanguePilumFR :: FormatAdresseThunk ()
	{ return "@ Thunk             %3d"; }

Chaine
LanguePilumFR :: FormatLienStatiqueFutur  ()
	{ return "LS futur du thunk   %3d"; }

Chaine
LanguePilumFR :: FormatAdresseDansLaPile ()
	{ return "@ Pile              %3d"; }

Chaine
LanguePilumFR :: FormatEntier ()
	{ return "                    %d"; }

Chaine
LanguePilumFR :: FormatFlottant ()
	{ return "                    %-10s %*.*f"; }

Chaine
LanguePilumFR :: FormatBooleen ()
	{ return "                    %s"; }

Chaine
LanguePilumFR :: FormatCaractere ()
	{ return "                   '%c'"; }

Chaine
LanguePilumFR :: FormatChaine ()
	{ return "                   \"%s\""; }


Chaine
LanguePilumFR :: ModeleMarqueBlocDActivation ()
	{ return "--------------------------------------------"; }
Chaine
LanguePilumFR :: FormatMarqueBlocDActivation ()
	{ return "-%s[%*s]-"; }

Chaine
LanguePilumFR :: FormatTypeValeurPilumInconnu ()
	{ return "fTypeValeurPilum %d inconnu"; }


// -------------------------------------------------------------------------

Chaine
LanguePilumFR :: PretPourLExecution ()
	{ return "PRET POUR L'EXECUTION"; }

Chaine
LanguePilumFR :: ErreurFatalePilum ()
	{ return "### Erreur fatale dans la machine Pilum ###"; }

Chaine
LanguePilumFR :: VoulezVousVoirLeCode ()
	{ return "Voulez-vous voir la memoire du code"; }
Chaine
LanguePilumFR :: VoulezVousVoirLEtatDeLaPile ()
	{ return "Voulez-vous voir le contenu de la pile"; }
Chaine
LanguePilumFR :: Oui ()
	{ return "o"; }

Chaine
LanguePilumFR :: PasPuAllouerLaMemoireDuCode ()
	{ return "On n'a pas pu allouer la memoire du code"; }
Chaine
LanguePilumFR :: PasPuAllouerLaMemoireDesChaines ()
	{ return "On n'a pas pu allouer la table des chaines"; }
Chaine
LanguePilumFR :: PasPuAllouerLaPile ()
	{ return "on n'a pas pu allouer la pile"; }

Chaine
LanguePilumFR :: FormatPasPuOuvrirLeFichierBinaireEnLecture ()
	{ return "Pas pu ouvrir le fichier binaire '%s' en lecture"; }

Chaine
LanguePilumFR :: FormatCodeOperatoirePilumInconnu ()
	{ return "instruction Pilum '%d' inconnue"; }

Chaine
LanguePilumFR :: FormatTailleDesChaines ()
	{ return "Taille des chaines: %d"; }
Chaine
LanguePilumFR :: FormatTableDesChaines ()
	{ return "Table des chaines: \n%s"; }
Chaine
LanguePilumFR :: FormatNombreDInstructions ()
	{ return "Nombre d'instructions: %d"; }

Chaine
LanguePilumFR :: FormatInstructionPilumInconnue ()
	{ return "Instruction Pilum inconnue '%d'"; }

Chaine
LanguePilumFR :: FormatValeurDansLaPilePasDuBonType ()
	{ return "%s: %s (%s)"; }

Chaine
LanguePilumFR :: ZonesDePilumPasAllouees ()
	{
	return
		"Il faut allouer la memoire du code, la table des chaines\n"
		"et la pile avant d'executer du code par Pilum!";
	}

Chaine
LanguePilumFR :: SommetDePileDevraitEtreBooleen ()
	{ return "le sommet de la pile devrait etre un booleen"; }
Chaine
LanguePilumFR :: ElementSousSommetDePileDevraitEtreBooleen ()
	{ return "l'element sous le sommet de la pile devrait etre un booleen"; }
Chaine
LanguePilumFR :: SommetDePileDevraitEtreEntier ()
	{ return "le sommet de la pile devrait etre un nombre entier"; }
Chaine
LanguePilumFR :: ElementSousSommetDePileDevraitEtreEntier ()
	{ return "l'element sous le sommet de la pile devrait etre un nombre entier"; }
Chaine
LanguePilumFR :: SommetDePileDevraitEtreFlottant ()
	{ return "le sommet de la pile devrait etre un nombre flottant"; }
Chaine
LanguePilumFR :: ElementSousSommetDePileDevraitEtreFlottant ()
	{ return "l'element sous le sommet de la pile devrait etre un nombre flottant"; }
Chaine
LanguePilumFR :: SecondElementSousSommetDePileDevraitEtreFlottant ()
	{ return "le second element sous le sommet de la pile devrait etre un nombre flottant"; }
Chaine
LanguePilumFR :: SommetDePileDevraitEtreUneCaractere ()
	{ return "le sommet de la pile devrait etre un caractere"; }
Chaine
LanguePilumFR :: SommetDePileDevraitEtreUneChaine ()
	{ return "le sommet de la pile devrait etre une chaine"; }
Chaine
LanguePilumFR :: ElementSousSommetDePileDevraitEtreUneChaine ()
	{ return "l'element sous le sommet de la pile devrait etre une chaine"; }
Chaine
LanguePilumFR :: SecondElementSousSommetDePileDevraitEtreUneChaine ()
	{ return "le second element sous le sommet de la pile devrait etre une chaine"; }

Chaine
LanguePilumFR :: SommetDePileDevraitEtreAdresseDansLaPile ()
	{ return "le sommet de la pile devrait etre une adresse dans la pile"; }
Chaine
LanguePilumFR :: ElementSousSommetDePileDevraitEtreAdresseDansLaPile ()
	{ return "l'element sous le sommet de la pile devrait etre une adresse dans la pile"; }

Chaine
LanguePilumFR :: SommetDePileDevraitEtreAdresseDUnThunk ()
	{ return "le sommet de la pile devrait etre l'adresse d'un thunk"; }

Chaine
LanguePilumFR :: FormatBlocDActivationPourFonction ()
	{ return "bloc d'activation pour '%s'"; }
Chaine
LanguePilumFR :: FormatBlocDActivationPourThunk ()
	{ return "bloc d'activation pour thunk '%s'"; }



// -------------------------------------------------------------------------

Chaine
LanguePilumFR :: InstructionInconnue ()
	{ return "*** InstructionInconnue ***"; }

Chaine
LanguePilumFR :: Halte ()
	{ return "Halte"; }

Chaine
LanguePilumFR :: Commentaire ()
	{ return "Commentaire"; }

Chaine
LanguePilumFR :: EmpilerMarqueBlocDActivation ()
	{ return "EmpilerMarqueBlocDActivation"; }

Chaine
LanguePilumFR :: Reserver ()
	{ return "Reserver"; }
Chaine
LanguePilumFR :: Desempiler ()	
	{ return "Desempiler"; }
Chaine
LanguePilumFR :: Stocker ()
	{ return "Stocker"; }
Chaine
LanguePilumFR :: Dupliquer ()
	{ return "Dupliquer"; }
			
Chaine
LanguePilumFR :: EmpilerValeur ()
	{ return "EmpilerValeur"; }
Chaine
LanguePilumFR :: EmpilerAdresse ()
	{ return "EmpilerAdresse"; }
Chaine
LanguePilumFR :: EmpilerLienStatique ()
	{ return "EmpilerLienStatique"; }
Chaine
LanguePilumFR :: EmpilerEntier ()
	{ return "EmpilerEntier"; }
Chaine
LanguePilumFR :: EmpilerFlottant ()
	{ return "EmpilerFlottant"; }
Chaine
LanguePilumFR :: EmpilerBooleen ()
	{ return "EmpilerBooleen"; }
Chaine
LanguePilumFR :: EmpilerCaractere ()
	{ return "EmpilerCaractere"; }
Chaine
LanguePilumFR :: EmpilerChaine ()
	{ return "EmpilerChaine"; }
Chaine
LanguePilumFR :: EmpilerValInconnue ()
	{ return "EmpilerValInconnue"; }

Chaine
LanguePilumFR :: Sauter ()
	{ return "Sauter"; }
Chaine
LanguePilumFR :: SauterSiFaux ()
	{ return "SauterSiFaux"; }
Chaine
LanguePilumFR :: Appel ()
	{ return "Appel "; }
Chaine
LanguePilumFR :: RetourDeFonction ()
	{ return "RetourDeFonction"; }
Chaine
LanguePilumFR :: RetourDeProcedure ()
	{ return "RetourDeProcedure"; }
Chaine
LanguePilumFR :: EmpilerDescripteurDeThunk ()
	{ return "EmpilerDescripteurDeThunk"; }
Chaine
LanguePilumFR :: EvaluerThunk ()
	{ return "EvaluerThunk"; }
Chaine
LanguePilumFR :: EvaluerThunkAvecMarqueBlocDActivation ()
	{ return "EvaluerThunkAvecMarqueBlocDActivation"; }

Chaine
LanguePilumFR :: LireEntier ()
	{ return "LireEntier"; }
Chaine
LanguePilumFR :: LireFlottant ()
	{ return "LireFlottant"; }
Chaine
LanguePilumFR :: LireBooleen ()
	{ return "LireBooleen"; }
Chaine
LanguePilumFR :: LireCaractere ()
	{ return "LireCaractere"; }
Chaine
LanguePilumFR :: LireChaine ()
	{ return "LireChaine"; }
Chaine
LanguePilumFR :: EcrireEntier ()
	{ return "EcrireEntier"; }
Chaine
LanguePilumFR :: EcrireFlottant ()
	{ return "EcrireFlottant"; }
Chaine
LanguePilumFR :: EcrireBooleen ()
	{ return "EcrireBooleen"; }
Chaine
LanguePilumFR :: EcrireCaractere ()
	{ return "EcrireCaractere"; }
Chaine
LanguePilumFR :: EcrireChaine ()
	{ return "EcrireChaine"; }
Chaine
LanguePilumFR :: EcrireFinDeLigne ()
	{ return "EcrireFinDeLigne"; }

Chaine
LanguePilumFR :: FormaterFlottant ()
	{ return "FormaterFlottant"; }

Chaine
LanguePilumFR :: IncrEntier ()
	{ return "IncrEntier"; }
Chaine
LanguePilumFR :: DecrEntier ()
	{ return "DecrEntier"; }
Chaine
LanguePilumFR :: IncrFlottant ()
	{ return "IncrFlottant"; }
Chaine
LanguePilumFR :: DecrFlottant ()
	{ return "DecrFlottant"; }
Chaine
LanguePilumFR :: Moins1Entier ()
	{ return "Moins1Entier"; }
Chaine
LanguePilumFR :: Moins1Flottant ()
	{ return "Moins1Flottant"; }

Chaine
LanguePilumFR :: AbsEntier ()
	{ return "AbsEntier"; }
Chaine
LanguePilumFR :: AbsFlottant ()
	{ return "AbsFlottant"; }

Chaine
LanguePilumFR :: PlusEntier ()
	{ return "PlusEntier"; }
Chaine
LanguePilumFR :: MoinsEntier ()
	{ return "MoinsEntier"; }
Chaine
LanguePilumFR :: FoisEntier ()
	{ return "FoisEntier"; }
Chaine
LanguePilumFR :: DiviseEntier ()
	{ return "DiviseEntier"; }
Chaine
LanguePilumFR :: ModuloEntier ()
	{ return "ModuloEntier"; }
Chaine
LanguePilumFR :: PlusFlottant ()
	{ return "PlusFlottant"; }
Chaine
LanguePilumFR :: MoinsFlottant ()
	{ return "MoinsFlottant"; }
Chaine
LanguePilumFR :: FoisFlottant ()
	{ return "FoisFlottant"; }
Chaine
LanguePilumFR :: DiviseFlottant ()
	{ return "DiviseFlottant"; }

Chaine
LanguePilumFR :: ConvertirEntierEnFlottant ()
	{ return "ConvertirEntierEnFlottant"; }

Chaine
LanguePilumFR :: TronquerFlottantEnEntier ()
	{ return "TronquerFlottantEnEntier"; }

Chaine
LanguePilumFR :: EgaleEntier ()
	{ return "EgaleEntier"; }
Chaine
LanguePilumFR :: InfEntier ()
	{ return "InfEntier"; }
Chaine
LanguePilumFR :: InfEgaleEntier ()
	{ return "InfEgaleEntier"; }
Chaine
LanguePilumFR :: DifferentEntier ()
	{ return "DifferentEntier"; }
Chaine
LanguePilumFR :: SupEgaleEntier ()
	{ return "SupEgaleEntier"; }
Chaine
LanguePilumFR :: SupEntier ()
	{ return "SupEntier"; }
Chaine
LanguePilumFR :: EgaleFlottant ()
	{ return "EgaleFlottant"; }
Chaine
LanguePilumFR :: InfFlottant ()
	{ return "InfFlottant"; }
Chaine
LanguePilumFR :: InfEgaleFlottant ()
	{ return "InfEgaleFlottant"; }
Chaine
LanguePilumFR :: DifferentFlottant ()
	{ return "DifferentFlottant"; }
Chaine
LanguePilumFR :: SupEgaleFlottant ()
	{ return "SupEgaleFlottant"; }
Chaine
LanguePilumFR :: SupFlottant ()
	{ return "SupFlottant"; }
Chaine
LanguePilumFR :: EgaleChaine ()
	{ return "EgaleChaine"; }
Chaine
LanguePilumFR :: InfChaine ()
	{ return "InfChaine"; }
Chaine
LanguePilumFR :: InfEgaleChaine ()
	{ return "InfEgaleChaine"; }
Chaine
LanguePilumFR :: DifferentChaine ()
	{ return "DifferentChaine"; }
Chaine
LanguePilumFR :: SupEgaleChaine ()
	{ return "SupEgaleChaine"; }
Chaine
LanguePilumFR :: SupChaine ()
	{ return "SupChaine"; }
			

// -------------------------------------------------------------------------


// -------------------------------------------------------------------------

Chaine
LanguePilumFR :: ErreurInterne ()
	{ return "Erreur interne dans la machine Pilum"; }
	
Chaine
LanguePilumFR :: DebordementPile ()
	{ return "Débordement de la pile"; }
Chaine
LanguePilumFR :: DebordementPileVersLeBas  ()
	{ return "Débordement de la pile vers le bas"; }
	
Chaine
LanguePilumFR :: VariableNonInitialisee ()
	{ return "Variable non ininitialisée"; }
	
Chaine
LanguePilumFR :: DiviseEntierParZero ()
	{ return "Integer division by zero"; }
Chaine
LanguePilumFR :: ModuloEntierParZero ()
	{ return "Integer modulo by zero"; }

Chaine
LanguePilumFR :: DiviseFlottantParZero ()
	{ return "Double division by zero"; }
	
Chaine
LanguePilumFR :: InterruptionUtilisateur ()
	{ return "\n\n### Arret de Pilum par l'utilisateur ###\n"; }
	
Chaine
LanguePilumFR :: ErreurInternePilum ()
	{ return "\n\n### Pilum: erreur interne ###\n"; }

Chaine
LanguePilumFR :: FormatEtatDePilum ()
	{ return "                     --- Etat de '%s' ---\n"; }
Chaine
LanguePilumFR :: FormatTailleDeLaMemoireDuCode ()
	{ return "Taille de la memoire du code   = %5d"; }
Chaine
LanguePilumFR :: FormatLimiteSommet ()
	{ return "Limite du sommet               = %5d"; }
Chaine
LanguePilumFR :: FormatTailleDesChainesPilum ()
	{ return "Taille de la table des chaines = %5d"; }
Chaine
LanguePilumFR :: FormatEtatCourant ()
	{ return "Etat courant                   = %5d"; }
Chaine
LanguePilumFR :: FormatInstructionCourante ()
	{ return "Instruction courante           = %5d"; }
Chaine
LanguePilumFR :: FormatSommet ()
	{ return "Sommet                         = %5d"; }
Chaine
LanguePilumFR :: FormatEnvironnementCourant ()
	{ return "Environnement courant          = %5d"; }

Chaine
LanguePilumFR :: FormatPromptPilum ()
	{ return "Pilum      @%5d: "; }
Chaine
LanguePilumFR :: FormatCommandePilum ()
	{ return "Commande [%2s %s] > "; }
Chaine
LanguePilumFR :: SurPointDArret ()
	{ return "sur point d'arret"; }

Chaine
LanguePilumFR :: FormatCommandePilumInconnue ()
	{ return "--> La commandee '%s' est inconnue: essayez h ou H"; }

Chaine
LanguePilumFR :: FinNormaleDeLExecution ()
	{ return "FIN NORMALE DE L'EXECUTION"; }

Chaine
LanguePilumFR :: FormatTempsDExecutionParPilum ()
	{ return "\n*** Temps d'execution par Pilum: %d seconde(s) ***\n"; }

Chaine
LanguePilumFR :: FormatContenuDeLaMemoireDuCode ()
	{
	return
		"Contenu de la memoire du code (%d instructions)";
	}

Chaine
LanguePilumFR :: FormatContenuDeLaTableDesChaines ()
	{
	return
		"Contenu de la table des chaines (%d octets)";
	}

Chaine
LanguePilumFR :: FormatPileVide ()
	{ return
		"\n                       *** Pile vide ***"
		"\n                       EnvCourant = %d\n"; }
Chaine
LanguePilumFR :: ContenuDeLaPile ()
	{ return
		"\n                       Contenu de la pile"
		"\n                       ------------------"; }
Chaine
LanguePilumFR :: EnvironnementCourant ()
	{ return "EnvCourant ---->"; }
Chaine
LanguePilumFR :: AutreEnvironnement ()
	{ return "          ----->"; }
Chaine
LanguePilumFR :: PasUnEnvironnement ()
	{ return "                "; }


// -------------------------------------------------------------------------

Chaine
LanguePilumFR :: FormatTailleDeLaPilePasEntiere ()
	{ return "--> La taille de la pile '%s' n'est pas un entier positif!"; }

Chaine
LanguePilumFR :: FichierBinairePilumAttendu ()
	{ return "--> Un nom de fichier binaire Pilum est attendu!"; }


// -------------------------------------------------------------------------
//	LanguePilumEN
// -------------------------------------------------------------------------

LanguePilumEN :: LanguePilumEN ()
	{}

// -------------------------------------------------------------------------

Chaine
LanguePilumEN :: LienDynamique ()
	{ return "DynamicLink"; }
Chaine
LanguePilumEN :: LienStatique ()
	{ return "StaticLink"; }

Chaine
LanguePilumEN :: AdresseDeRetour ()
	{ return "ReturnAddress"; }
Chaine
LanguePilumEN :: AdresseThunk ()
	{ return "ThunkAddress"; }
Chaine
LanguePilumEN :: LienStatiqueFutur ()
	{ return "FutureStaticLink"; }

Chaine
LanguePilumEN :: AdresseDansLaPile ()
	{ return "InStackAddress"; }


// -------------------------------------------------------------------------

Chaine
LanguePilumEN :: ValeurInconnue ()
	{ return "UnknownValue"; }


// -------------------------------------------------------------------------

Chaine
LanguePilumEN :: FormatCommeEntier ()
	{
	return
		"An integer Pilum value is expected, "
		"found a value of type %s";
	}
Chaine
LanguePilumEN :: FormatCommeFlottant ()
	{
	return
		"A double Pilum value is expected, "
		"found a value of type %s";
	}
Chaine
LanguePilumEN :: FormatCommeBooleen ()
	{
	return
		"A boolean Pilum value is expected, "
		"found a value of type %s";
	}
Chaine
LanguePilumEN :: FormatCommeChaine ()
	{
	return
		"A string Pilum value is expected, "
		"found a value of type %s";
	}



// -------------------------------------------------------------------------

Chaine
LanguePilumEN :: Entier ()
	{ return "Integer"; }
Chaine
LanguePilumEN :: Flottant ()
	{ return "Double"; }
Chaine
LanguePilumEN :: Booleen ()
	{ return "Boolean"; }
Chaine
LanguePilumEN :: Caractere ()
	{ return "Character"; }
Chaine
LanguePilumEN :: Chaine_ ()
	{ return "String"; }


Chaine
LanguePilumEN :: MarqueBlocDActivationDeFonction ()
	{ return "FunctionActivationRecordMark"; }
Chaine
LanguePilumEN :: MarqueBlocDActivationDeThunk ()
	{ return "ThunkActivationRecordMark"; }

/* JMI
Chaine
LanguePilumEN :: MarqueBlocDActivation ()
	{ return "MarqueBlocDActivation"; }
*/

Chaine
LanguePilumEN :: FormatValeurInconnue ()
	{ return "* UnknownValue *"; }

Chaine
LanguePilumEN :: FormatLienDynamique ()
	{ return "DL                  %3d"; }

Chaine
LanguePilumEN :: FormatLienStatique ()
	{ return "SL (static link)    %3d"; }

Chaine
LanguePilumEN :: FormatAdresseDeRetour ()
	{ return "RA                  %3d"; }

Chaine
LanguePilumEN :: FormatAdresseThunk ()
	{ return "@ Thunk             %3d"; }

Chaine
LanguePilumEN :: FormatLienStatiqueFutur  ()
	{ return "Future thunk SL     %3d"; }

Chaine
LanguePilumEN :: FormatAdresseDansLaPile ()
	{ return "@ Stack             %3d"; }

Chaine
LanguePilumEN :: FormatEntier ()
	{ return "                    %d"; }

Chaine
LanguePilumEN :: FormatFlottant ()
	{ return "                    %-10s %*.*f"; }

Chaine
LanguePilumEN :: FormatBooleen ()
	{ return "                    %s"; }

Chaine
LanguePilumEN :: FormatCaractere ()
	{ return "                   '%c'"; }

Chaine
LanguePilumEN :: FormatChaine ()
	{ return "                   \"%s\""; }


Chaine
LanguePilumEN :: ModeleMarqueBlocDActivation ()
	{ return "--------------------------------------------"; }
Chaine
LanguePilumEN :: FormatMarqueBlocDActivation ()
	{ return "-%s[%*s]-"; }

Chaine
LanguePilumEN :: FormatTypeValeurPilumInconnu ()
	{ return "Pilum value type %d unknown"; }


// -------------------------------------------------------------------------

Chaine
LanguePilumEN :: PretPourLExecution ()
	{ return "READY FOR EXECUTION"; }

Chaine
LanguePilumEN :: ErreurFatalePilum ()
	{ return "### Fatal error in Pilum machine ###"; }

Chaine
LanguePilumEN :: VoulezVousVoirLeCode ()
	{ return "Would you like to see the code memory contents"; }
Chaine
LanguePilumEN :: VoulezVousVoirLEtatDeLaPile ()
	{ return "Would you like to see the stack contents"; }
Chaine
LanguePilumEN :: Oui ()
	{ return "y"; }

Chaine
LanguePilumEN :: PasPuAllouerLaMemoireDuCode ()
	{ return "Couldn't allocate code memory"; }
Chaine
LanguePilumEN :: PasPuAllouerLaMemoireDesChaines ()
	{ return "Couldn't allocate the strings table"; }
Chaine
LanguePilumEN :: PasPuAllouerLaPile ()
	{ return "Couldn't allocate the stack"; }

Chaine
LanguePilumEN :: FormatPasPuOuvrirLeFichierBinaireEnLecture ()
	{ return "Could not open binary file '%s' for reading"; }

Chaine
LanguePilumEN :: FormatCodeOperatoirePilumInconnu ()
	{ return "unknown Pilum instruction '%d'"; }

Chaine
LanguePilumEN :: FormatTailleDesChaines ()
	{ return "Strings size: %d"; }
Chaine
LanguePilumEN :: FormatTableDesChaines ()
	{ return "Strings table: \n%s"; }
Chaine
LanguePilumEN :: FormatNombreDInstructions ()
	{ return "Number of instructions: %d"; }

Chaine
LanguePilumEN :: FormatInstructionPilumInconnue ()
	{ return "Unknown Pilum unstruction Pilum '%d'"; }

Chaine
LanguePilumEN :: FormatValeurDansLaPilePasDuBonType ()
	{ return "%s: %s (%s)"; }

Chaine
LanguePilumEN :: ZonesDePilumPasAllouees ()
	{
	return
		"The code memory, strings table and stack\n"
		"should be created prior to executing code with Pilum!";
	}

Chaine
LanguePilumEN :: SommetDePileDevraitEtreBooleen ()
	{ return "stack top should be a boolean"; }
Chaine
LanguePilumEN :: ElementSousSommetDePileDevraitEtreBooleen ()
	{ return "the element under the stack top should be a booleen"; }
Chaine
LanguePilumEN :: SommetDePileDevraitEtreEntier ()
	{ return "stack top should be an integer number"; }
Chaine
LanguePilumEN :: ElementSousSommetDePileDevraitEtreEntier ()
	{ return "the element under the stack top should be an integer number"; }
Chaine
LanguePilumEN :: SommetDePileDevraitEtreFlottant ()
	{ return "stack top should be a double number"; }
Chaine
LanguePilumEN :: ElementSousSommetDePileDevraitEtreFlottant ()
	{ return "the element under the stack top should be a double number"; }
Chaine
LanguePilumEN :: SecondElementSousSommetDePileDevraitEtreFlottant ()
	{ return "le second element sous stack top should be a double number"; }
Chaine
LanguePilumEN :: SommetDePileDevraitEtreUneCaractere ()
	{ return "stack top should be a character"; }
Chaine
LanguePilumEN :: SommetDePileDevraitEtreUneChaine ()
	{ return "stack top should be a string"; }
Chaine
LanguePilumEN :: ElementSousSommetDePileDevraitEtreUneChaine ()
	{ return "the element under the stack top should be a string"; }
Chaine
LanguePilumEN :: SecondElementSousSommetDePileDevraitEtreUneChaine ()
	{ return "le second element sous stack top should be a string"; }

Chaine
LanguePilumEN :: SommetDePileDevraitEtreAdresseDansLaPile ()
	{ return "stack top should be ae adresse dans la pile"; }
Chaine
LanguePilumEN :: ElementSousSommetDePileDevraitEtreAdresseDansLaPile ()
	{ return "the element under the stack top should be an address in the stack"; }

Chaine
LanguePilumEN :: SommetDePileDevraitEtreAdresseDUnThunk ()
	{ return "stack top should be a thunk address"; }

Chaine
LanguePilumEN :: FormatBlocDActivationPourFonction ()
	{ return "activation record for '%s'"; }
Chaine
LanguePilumEN :: FormatBlocDActivationPourThunk ()
	{ return "activation record for thunk '%s'"; }



// -------------------------------------------------------------------------

Chaine
LanguePilumEN :: InstructionInconnue ()
	{ return "*** UnknownInstruction ***"; }

Chaine
LanguePilumEN :: Halte ()
	{ return "Halt"; }

Chaine
LanguePilumEN :: Commentaire ()
	{ return "Comment"; }

Chaine
LanguePilumEN :: EmpilerMarqueBlocDActivation ()
	{ return "PushActivationRecordMark"; }

Chaine
LanguePilumEN :: Reserver ()
	{ return "Reserve"; }
Chaine
LanguePilumEN :: Desempiler ()
	{ return "Pop"; }
Chaine
LanguePilumEN :: Stocker ()
	{ return "Store"; }
Chaine
LanguePilumEN :: Dupliquer ()
	{ return "Duplicate"; }
			
Chaine
LanguePilumEN :: EmpilerValeur ()
	{ return "PushValue"; }
Chaine
LanguePilumEN :: EmpilerAdresse ()
	{ return "PushAddress"; }
Chaine
LanguePilumEN :: EmpilerLienStatique ()
	{ return "PushStaticLink"; }
Chaine
LanguePilumEN :: EmpilerEntier ()
	{ return "PushInteger"; }
Chaine
LanguePilumEN :: EmpilerFlottant ()
	{ return "PushDouble"; }
Chaine
LanguePilumEN :: EmpilerBooleen ()
	{ return "PushBoolean"; }
Chaine
LanguePilumEN :: EmpilerCaractere ()
	{ return "PushCharacter"; }
Chaine
LanguePilumEN :: EmpilerChaine ()
	{ return "PushString"; }
Chaine
LanguePilumEN :: EmpilerValInconnue ()
	{ return "PushUnknownValue"; }

Chaine
LanguePilumEN :: Sauter ()
	{ return "Jump"; }
Chaine
LanguePilumEN :: SauterSiFaux ()
	{ return "JumpIfFalse"; }
Chaine
LanguePilumEN :: Appel ()
	{ return "Call "; }
Chaine
LanguePilumEN :: RetourDeFonction ()
	{ return "FunctionReturn"; }
Chaine
LanguePilumEN :: RetourDeProcedure ()
	{ return "ProcedureReturn"; }
Chaine
LanguePilumEN :: EmpilerDescripteurDeThunk ()
	{ return "PushThunkDescriptor"; }
Chaine
LanguePilumEN :: EvaluerThunk ()
	{ return "EvaluateThunk"; }
Chaine
LanguePilumEN :: EvaluerThunkAvecMarqueBlocDActivation ()
	{ return "EvaluateThunkWithActivationRecordMark"; }

Chaine
LanguePilumEN :: LireEntier ()
	{ return "ReadInteger"; }
Chaine
LanguePilumEN :: LireFlottant ()
	{ return "ReadDouble"; }
Chaine
LanguePilumEN :: LireBooleen ()
	{ return "ReadBoolean"; }
Chaine
LanguePilumEN :: LireCaractere ()
	{ return "ReadCharacter"; }
Chaine
LanguePilumEN :: LireChaine ()
	{ return "ReadString"; }
Chaine
LanguePilumEN :: EcrireEntier ()
	{ return "WriteInteger"; }
Chaine
LanguePilumEN :: EcrireFlottant ()
	{ return "WriteDouble"; }
Chaine
LanguePilumEN :: EcrireBooleen ()
	{ return "WriteBoolean"; }
Chaine
LanguePilumEN :: EcrireCaractere ()
	{ return "WriteCharacter"; }
Chaine
LanguePilumEN :: EcrireChaine ()
	{ return "WriteString"; }
Chaine
LanguePilumEN :: EcrireFinDeLigne ()
	{ return "WriteEndOfLine"; }

Chaine
LanguePilumEN :: FormaterFlottant ()
	{ return "FormatDouble"; }

Chaine
LanguePilumEN :: IncrEntier ()
	{ return "IncrInteger"; }
Chaine
LanguePilumEN :: DecrEntier ()
	{ return "DecrInteger"; }
Chaine
LanguePilumEN :: IncrFlottant ()
	{ return "IncrDouble"; }
Chaine
LanguePilumEN :: DecrFlottant ()
	{ return "DecrDouble"; }
Chaine
LanguePilumEN :: Moins1Entier ()
	{ return "Minus1Integer"; }
Chaine
LanguePilumEN :: Moins1Flottant ()
	{ return "Minus1Double"; }

Chaine
LanguePilumEN :: AbsEntier ()
	{ return "AbsInteger"; }
Chaine
LanguePilumEN :: AbsFlottant ()
	{ return "AbsDouble"; }

Chaine
LanguePilumEN :: PlusEntier ()
	{ return "PlusInteger"; }
Chaine
LanguePilumEN :: MoinsEntier ()
	{ return "MinusInteger"; }
Chaine
LanguePilumEN :: FoisEntier ()
	{ return "TimesInteger"; }
Chaine
LanguePilumEN :: DiviseEntier ()
	{ return "DivideInteger"; }
Chaine
LanguePilumEN :: ModuloEntier ()
	{ return "ModuloInteger"; }
Chaine
LanguePilumEN :: PlusFlottant ()
	{ return "PlusDouble"; }
Chaine
LanguePilumEN :: MoinsFlottant ()
	{ return "MoinsFlottant"; }
Chaine
LanguePilumEN :: FoisFlottant ()
	{ return "TimesFlottant"; }
Chaine
LanguePilumEN :: DiviseFlottant ()
	{ return "DivideDouble"; }

Chaine
LanguePilumEN :: ConvertirEntierEnFlottant ()
	{ return "ConvertIntegerToDouble"; }

Chaine
LanguePilumEN :: TronquerFlottantEnEntier ()
	{ return "TruncateDoubleToInteger"; }

Chaine
LanguePilumEN :: EgaleEntier ()
	{ return "EqualInteger"; }
Chaine
LanguePilumEN :: InfEntier ()
	{ return "LessThanInteger"; }
Chaine
LanguePilumEN :: InfEgaleEntier ()
	{ return "LessThanInteger"; }
Chaine
LanguePilumEN :: DifferentEntier ()
	{ return "DifferentInteger"; }
Chaine
LanguePilumEN :: SupEgaleEntier ()
	{ return "GreaterThanOrEqualInteger"; }
Chaine
LanguePilumEN :: SupEntier ()
	{ return "GreaterThanInteger"; }
Chaine
LanguePilumEN :: EgaleFlottant ()
	{ return "EqualDouble"; }
Chaine
LanguePilumEN :: InfFlottant ()
	{ return "LessThanFlottant"; }
Chaine
LanguePilumEN :: InfEgaleFlottant ()
	{ return "LessThanOrEqualDouble"; }
Chaine
LanguePilumEN :: DifferentFlottant ()
	{ return "DifferentDouble"; }
Chaine
LanguePilumEN :: SupEgaleFlottant ()
	{ return "GreaterThanOrEqualDouble"; }
Chaine
LanguePilumEN :: SupFlottant ()
	{ return "GreaterThanDouble"; }
Chaine
LanguePilumEN :: EgaleChaine ()
	{ return "EqualString"; }
Chaine
LanguePilumEN :: InfChaine ()
	{ return "LessThanString"; }
Chaine
LanguePilumEN :: InfEgaleChaine ()
	{ return "InfEqualString"; }
Chaine
LanguePilumEN :: DifferentChaine ()
	{ return "DifferentString"; }
Chaine
LanguePilumEN :: SupEgaleChaine ()
	{ return "GreaterThanOrEqualString"; }
Chaine
LanguePilumEN :: SupChaine ()
	{ return "GreaterThanString"; }
			

// -------------------------------------------------------------------------


// -------------------------------------------------------------------------


Chaine
LanguePilumEN :: ErreurInterne ()
	{ return "Pilum internal error"; }
	
Chaine
LanguePilumEN :: DebordementPile ()
	{ return "Pilum stack overflow"; }
Chaine
LanguePilumEN :: DebordementPileVersLeBas  ()
	{ return "Pilum stack underflow"; }
	
Chaine
LanguePilumEN :: VariableNonInitialisee ()
	{ return "Uninitialized variable"; }
	
Chaine
LanguePilumEN :: DiviseEntierParZero ()
	{ return "Division entiere par zero"; }
Chaine
LanguePilumEN :: ModuloEntierParZero ()
	{ return "Modulo entier par zero"; }
	
Chaine
LanguePilumEN :: DiviseFlottantParZero ()
	{ return "Division flottante par zero"; }
	
Chaine
LanguePilumEN :: InterruptionUtilisateur ()
	{ return "\n\n### Pilum has been interrupted by user ###\n"; }
	
Chaine
LanguePilumEN :: ErreurInternePilum ()
	{ return "\n\n### Pilum: internal error ###\n"; }

Chaine
LanguePilumEN :: FormatEtatDePilum ()
	{ return "                     --- Status of '%s' ---\n"; }
Chaine
LanguePilumEN :: FormatTailleDeLaMemoireDuCode ()
	{ return "Code memory size        = %5d"; }
Chaine
LanguePilumEN :: FormatLimiteSommet ()
	{ return "Stack top limit         = %5d"; }
Chaine
LanguePilumEN :: FormatTailleDesChainesPilum ()
	{ return "Stromgs table size      = %5d"; }
Chaine
LanguePilumEN :: FormatEtatCourant ()
	{ return "Current status          = %5d"; }
Chaine
LanguePilumEN :: FormatInstructionCourante ()
	{ return "Current instruction     = %5d"; }
Chaine
LanguePilumEN :: FormatSommet ()
	{ return "Stop top                = %5d"; }
Chaine
LanguePilumEN :: FormatEnvironnementCourant ()
	{ return "Current environment     = %5d"; }

Chaine
LanguePilumEN :: FormatPromptPilum ()
	{ return "Pilum      @%5d: "; }
Chaine
LanguePilumEN :: FormatCommandePilum ()
	{ return "Command  [%2s %s] > "; }
Chaine
LanguePilumEN :: SurPointDArret ()
	{ return "on halt point"; }

Chaine
LanguePilumEN :: FormatCommandePilumInconnue ()
	{ return "--> Command '%s' is unknown: try h ou H"; }

Chaine
LanguePilumEN :: FinNormaleDeLExecution ()
	{ return "NORMAL  EXECUTION END"; }

Chaine
LanguePilumEN :: FormatTempsDExecutionParPilum ()
	{ return "\n*** Pilum elapsed time: %d second(s) ***\n"; }

Chaine
LanguePilumEN :: FormatContenuDeLaMemoireDuCode ()
	{
	return
		"Code memory contents (%d instructions)";
	}

Chaine
LanguePilumEN :: FormatContenuDeLaTableDesChaines ()
	{
	return
		"String table contents (%d bytes)";
	}

Chaine
LanguePilumEN :: FormatPileVide ()
	{ return
		"\n                       *** Empty stack ***"
		"\n                       CurrentEnv = %d\n"; }
Chaine
LanguePilumEN :: ContenuDeLaPile ()
	{ return
		"\n                       Stack contents"
		"\n                       --------------"; }
Chaine
LanguePilumEN :: EnvironnementCourant ()
	{ return "CurrentEnv ---->"; }
Chaine
LanguePilumEN :: AutreEnvironnement ()
	{ return "          ----->"; }
Chaine
LanguePilumEN :: PasUnEnvironnement ()
	{ return "                "; }


// -------------------------------------------------------------------------

Chaine
LanguePilumEN :: FormatTailleDeLaPilePasEntiere ()
	{ return "--> Stack size '%s' is no positive integer!"; }

Chaine
LanguePilumEN :: FichierBinairePilumAttendu ()
	{ return "--> A binary Pilum file name is expected!"; }


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

LanguePilumPTR					gLANGUE_Pilum		= NULL;


CommandesPilumPTR				gCommandesPilum = NULL;

CommandesPilumFR				gCommandesPilumFR;
CommandesPilumEN				gCommandesPilumEN;


// -------------------------------------------------------------------------
//	InitialiserLanguesPilum
// -------------------------------------------------------------------------

void
InitialiserLanguesPilum (Chaine leMnemonique)
	{
	if (gLANGUE_Pilum != NULL)
		delete gLANGUE_Pilum;

	if (leMnemonique == "fr")
		gLANGUE_Pilum = new LanguePilumFR;
	if (leMnemonique == "en")
		gLANGUE_Pilum = new LanguePilumEN;


	if (gCommandesPilum != NULL)
		delete gCommandesPilum;

	if (leMnemonique == "fr")
		gCommandesPilum = new CommandesPilumFR;
	if (leMnemonique == "en")
		gCommandesPilum = new CommandesPilumEN;
	}	// InitialiserLanguesPilum
