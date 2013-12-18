// =========================================================================
//	LanguesSemantique.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "LanguesSemantique.h"

#include "SupportCPlusPlus.h"

#include <iostream>

#include <cstdlib>


// -------------------------------------------------------------------------
//	LangueSemantique
// -------------------------------------------------------------------------

LangueSemantique :: LangueSemantique ()
	{}

LangueSemantique :: ~ LangueSemantique ()
	{}


// -------------------------------------------------------------------------
//	LangueSemantiqueFR
// -------------------------------------------------------------------------

LangueSemantiqueFR :: LangueSemantiqueFR ()
	{}

LangueSemantiqueFR :: ~ LangueSemantiqueFR ()
	{}


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatNomQualifie ()
	{ return "%s::%s"; }

Chaine
LangueSemantiqueFR :: ConstantePredefinie ()
	{ return "Constante predefinie"; }

Chaine
LangueSemantiqueFR :: FonctionPredefinie ()
	{ return "Fonction predefinie"; }

Chaine
LangueSemantiqueFR :: IterationPredefinie ()
	{ return "Iteration predefinie"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: NonUtilise ()
	{ return ": non utilise(e)"; }

Chaine
LangueSemantiqueFR :: FormatContenuDuDictionnaire ()
	{ return "\nContenu du Dictionnaire '%s':"; }
	
Chaine
LangueSemantiqueFR :: FormatPurgeDuDictionnaireVide ()
	{ return "On purge le dictionnaire '%s', qui est vide\n"; }
Chaine
LangueSemantiqueFR :: FormatPurgeDuDictionnaire ()
	{ return "On purge le dictionnaire '%s', contenant:\n"; }

Chaine
LangueSemantiqueFR :: FormatEmpilageNiveauDeDeclaration ()
	{ return "On empile le niveau de declaration '%s'"; }
Chaine
LangueSemantiqueFR :: FormatDesempilageNiveauDeDeclaration ()
	{ return "\nOn desempile le niveau de declaration '%s'"; }

Chaine
LangueSemantiqueFR :: TableDesSymbolesVide ()
	{ return "TableDesSymboles vide"; }
Chaine
LangueSemantiqueFR :: FormatTableDesSymboles ()
	{ return "===> TableDesSymboles -- %s <==="; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatIdentNonDeclare ()
	{ return "L'identificateur NON DECLARE '%s'"; }
Chaine
LangueSemantiqueFR :: FormatIdentNonDeclareSousFormeDeChaine ()
	{ return "L'identificateur NON DECLARE '%s': '%s'"; }
Chaine
LangueSemantiqueFR :: FacteurIdentificateurMalForme ()
	{
	return
		"Constante predefinie, fonction predefinie, \n"
		"fonction utilisateur, parametre formel ou indice d'iteration \n"
		"attendu(e) comme Facteur";
	}
Chaine
LangueSemantiqueFR :: FormatIdentDeFonctionNonDeclare ()
	{ return "L'identificateur de fonction NON DECLARE '%s'"; }

Chaine
LangueSemantiqueFR :: FormatConstantePredefinie ()
	{ return "'%s', %s:\n\t\t%s"; }
Chaine
LangueSemantiqueFR :: FormatFonctionPredefinie ()
	{ return "'%s', %s:\n\t\t(%s) -> %s"; }
Chaine
LangueSemantiqueFR :: FormatIterateurPredefini ()
	{ return "'%s', %s:\n\t\t(*Indice*, %s) -> %s"; }

Chaine
LangueSemantiqueFR :: FormatParametreFormel ()
	{ return "Le parametre formel %s '%s': '%s', declare (eval: %d, stat: %d)"; }


Chaine
LangueSemantiqueFR :: FormatErreurCommeNombre ()
	{
	return
		"ValeurLista :: CommeNombre, "
		"on a affaire a une valeur du type %s";
	}
Chaine
LangueSemantiqueFR :: FormatErreurCommeBooleen ()
	{
	return
		"ValeurLista :: CommeBooleen, "
		"on a affaire a une valeur du type %s";
	}
Chaine
LangueSemantiqueFR :: FormatErreurCommeChaine ()
	{
	return
		"ValeurLista :: CommeChaine, "
		"on a affaire a une valeur du type %s";
	}


Chaine
LangueSemantiqueFR :: FormatErreurTypeValeurLista ()
	{
	return
		"ValeurLista.Ecrire (): "
		"le type \"%s\" n'est ni Nombre, ni Booleen, ni Chaine";
	}


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: ParValeur ()
	{ return "par valeur"; }
Chaine
LangueSemantiqueFR :: ParNom ()
	{ return "par nom"; }
Chaine
LangueSemantiqueFR :: ParBesoin ()
	{ return "par besoin"; }

Chaine
LangueSemantiqueFR :: DelimiteurDeFonctionsEtEvaluations ()
	{
	return
		"/* ************************************************ */";
	}
Chaine
LangueSemantiqueFR :: SeparationDernierParametre ()
	{ return " et "; }

Chaine
LangueSemantiqueFR :: FormatFonctionUtilisateur ()
	{ return "'%s' (s: %d): '(%s) -> %s'"; }
Chaine
LangueSemantiqueFR :: FormatBesoinDUnLienStatique ()
	{ return "La fonction '%s' a besoin d'un lien statique (LS)"; }


Chaine
LangueSemantiqueFR :: FormatParametreParValeur ()
	{ return "parametre '%s' (numero %d) par valeur: "; }
Chaine
LangueSemantiqueFR :: FormatConsultationParametreParValeur ()
	{ return "... On consulte le parametre par valeur '%s', no %d, contexte %d"; }

Chaine
LangueSemantiqueFR :: FormatParametreParNom ()
	{ return "parametre '%s' (numero %d) par nom: "; }
Chaine
LangueSemantiqueFR :: FormatEvaluationParametreParNom ()
	{ return "... On EVALUE le parametre par nom '%s', no %d, contexte %d"; }

Chaine
LangueSemantiqueFR :: ResultatEvaluation ()
	{ return "... la valeur est: "; }

Chaine
LangueSemantiqueFR :: FormatParametreParBesoinNonEvalue ()
	{ return "parametre par besoin '%s' (numero %d) non-encore evalue: "; }
Chaine
LangueSemantiqueFR :: ParametreParBesoinDejaEvalue ()
	{ return "parametre par besoin deja evalue: "; }
Chaine
LangueSemantiqueFR :: FormatEvaluationParametreParBesoin ()
	{ return "... On EVALUE le parametre par besoin '%s', no %d, contexte %d"; }
Chaine
LangueSemantiqueFR :: FormatConsultationParametreParBesoin ()
	{ return "... On consulte le parametre par besoin '%s', no %d, contexte %d"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatContexteDEvaluation ()
	{ return "ContexteEval %d (%d associations):"; }

Chaine
LangueSemantiqueFR :: FormatRemonteeStatique ()
	{
	return
		"Remontee statique:\n\t"
		"niveau d'evaluation courant    : %d\n\t"
		"difference de niveaux statiques: %d";
	}

Chaine
LangueSemantiqueFR :: FormatTempsDEvaluationDirecte ()
	{ return "\n*** Temps d'evaluation directe: %d seconde(s) ***\n"; }

Chaine
LangueSemantiqueFR :: ContinuationApresOperandeGauche ()
	{ return "continuationApresOperandeGauche"; }
Chaine
LangueSemantiqueFR :: ContinuationApresOperandeDroit ()
	{ return "continuationApresOperandeDroit"; }
Chaine
LangueSemantiqueFR :: OnJetteLOperandeDroitDeSeq1 ()
	{ return "On jette l'operande droit de Seq1"; }
Chaine
LangueSemantiqueFR :: SeqImplicite ()
	{ return "Seq IMPLICITE"; }

Chaine
LangueSemantiqueFR :: ValeurInconnue ()
	{ return "ValeurInconnue"; }
Chaine
LangueSemantiqueFR :: ValeurVide ()
	{ return "*** VIDE ***"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: ArgumentDAppel ()
	{ return "argument d'appel"; }

Chaine
LangueSemantiqueFR :: FormatTropDArgumentsDansAppelAPredefinie ()
	{
	return
		"il y a TROP d'arguments dans "
		"un appel a la fonction predefinie '%s'";
	 }
Chaine
LangueSemantiqueFR :: FormatTropPeuDArgumentsDansAppelAPredefinie ()
	{
	return
		"il y a TROP PEU d'arguments dans "
		"un appel a la fonction predefinie parametree '%s'";
	 }

Chaine
LangueSemantiqueFR :: FormatTropDArgumentsDansAppelAFonctionParametree ()
	{
	return
		"il y a TROP d'arguments dans "
		"un appel de fonction utilisateur parametree '%s'";
	}
Chaine
LangueSemantiqueFR :: FormatTropPeuDArgumentsDansAppelAFonctionParametree ()
	{
	return
		"il y a TROP PEU d'arguments dans "
		"un appel a la fonction utilisateur parametree '%s'\n"
		"\t%s ont besoin d'une valeur";
	}

Chaine
LangueSemantiqueFR :: FormatNomDeFonction ()
	{ return "fonction '%s'"; }
Chaine
LangueSemantiqueFR :: FormatNumeroDeFonction ()
	{ return "Fonction_%d"; }
Chaine
LangueSemantiqueFR :: FormatNomDeParametre ()
	{ return "parametre '%s'"; }
Chaine
LangueSemantiqueFR :: FormatNumeroDeParametre ()
	{ return "Parametre_%d"; }
Chaine
LangueSemantiqueFR :: FormatNumeroDEvaluation ()
	{ return "Evaluation_%d"; }

Chaine
LangueSemantiqueFR :: FormatTypeLogiqueDeFonction ()
	{ return "%s decrit le type de la fonction '%s'\n"; }
Chaine
LangueSemantiqueFR :: FormatTypeLogiqueDeParametre ()
	{ return "%s decrit le type du parametre '%s'\n"; }
Chaine
LangueSemantiqueFR :: FormatTypeLogiqueDIdentificateurNonDeclare ()
	{ return "%s decrit le type de l'identificateur non declare '%s'\n"; }
Chaine
LangueSemantiqueFR :: FormatTypeLogiqueDeFonctionNonDeclaree ()
	{ return "%s decrit le type de la fonction non declaree '%s'\n"; }

Chaine
LangueSemantiqueFR :: FormatRedefinitionDeFonctionUtilisateur ()
	{ return "re-definition de la fonction utilisateur '%s'"; }
Chaine
LangueSemantiqueFR :: FormatDefinitionDeFonctionUtilisateurMasque ()
	{
	return
		"la definition de la fonction utilisateur '%s' "
		"masque la declaration de \n\t%s";
	}

Chaine
LangueSemantiqueFR :: FormatRedefinitionDeParametre ()
	{ return "re-definition du parametre '%s'"; }
Chaine
LangueSemantiqueFR :: FormatDefinitionDeParametreMasque ()
	{
	return
		"la definition du parametre formel '%s' "
		"masque la declaration de \n\t%s";
	}

Chaine
LangueSemantiqueFR :: FormatAucuneDeclarationAccessible ()
	{
	return
		"l'identificateur '%s' "
		"n'a aucune declaration accessible";
	}

Chaine
LangueSemantiqueFR :: ConditionDUnSi ()
	{ return "condition d'un 'Si'"; }
Chaine
LangueSemantiqueFR :: FormatAlternativesDUnSiPasDuMemeType ()
	{
	return
		"les deux alternatives d'un 'Si' ne "
		"retournent pas des valeurs du meme type\n"
		"\t(ici, '%s' et '%s')";
	}

Chaine
LangueSemantiqueFR :: GrapheSemantiqueDeLaSequenceDExpressionsAEvaluer ()
	{ return "\nGraphe semantique de la sequence d'expressions a evaluer:\n"; }
Chaine
LangueSemantiqueFR :: FormePostfixeeDeLaSequenceDExpressionsAEvaluer ()
	{ return "\nForme postfixee de la sequence d'expressions a evaluer:\n"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatIteration ()
	{ return "Iteration_%d"; }
Chaine
LangueSemantiqueFR :: BorneInferieure ()
	{ return "borne inferieure"; }
Chaine
LangueSemantiqueFR :: BorneSuperieure ()
	{ return "borne superieure"; }
Chaine
LangueSemantiqueFR :: ExpressionIteree ()
	{ return "expression iteree"; }

Chaine
LangueSemantiqueFR :: IndiceInconnu ()
	{ return "Indice inconnu"; }
Chaine
LangueSemantiqueFR :: IdentAttenduCommeIndiceDIteration ()
	{ return "IDENT attendu comme indice d'iteration"; }
Chaine
LangueSemantiqueFR :: FormatVirguleAttendueApresLIndice ()
	{ return "apres l'indice d'iteration '%s' d'un '%s'"; }
Chaine
LangueSemantiqueFR :: FormatVirguleAttendueApresLaBorneInferieure ()
	{ return "apres la borne inferieure d'un '%s'"; }
Chaine
LangueSemantiqueFR :: FormatVirguleAttendueApresLaBorneSuperieure ()
	{ return "apres la borne superieure d'un '%s'"; }
Chaine
LangueSemantiqueFR :: FormatRedefinitionDeLIndiceDIteration ()
	{ return "re-definition de l'indice d'iteration '%s'"; }
Chaine
LangueSemantiqueFR :: FormatDefinitionDeLIndiceDIterationMasque ()
	{
	return
		"la definition de l'indice d'iteration '%s' "
		"masque la declaration de \n\t%s";
	}
Chaine
LangueSemantiqueFR :: FormatParentheseInattendueDansAppelAFonctionNonParametree ()
	{ return "'(' inattendu dans un appel a la fonction '%s'"; }
Chaine
LangueSemantiqueFR :: FormatEmpilageDescrAppelDeFonction ()
	{ return "On empile une description d'appel de fonction pour '%s'"; }
Chaine
LangueSemantiqueFR :: FormatDesempilageDescrAppelDeFonction ()
	{ return "On desempile une description d'appel de fonction pour '%s'"; }

// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatCreationDescrAppelDeFonctionPredefinie ()
	{ return "On construit une DescrAppelFonctionPredefinie pour %s a %d arguments"; }
Chaine
LangueSemantiqueFR :: FormatEnregistrementArgumentDeFonctionPredefinie ()
	{ return "EnregistrerArgument %d de %s"; }
Chaine
LangueSemantiqueFR :: FormatVerifierSiPasTropDArgumentsPourFonctionPredefinie ()
	{ return "DescrAppelFonctionPredefinie :: VerifierSiPasTropDArguments %d de %s"; }
Chaine
LangueSemantiqueFR :: FormatVerifierSiAssezDArgumentsPourFonctionPredefinie ()
	{ return "DescrAppelFonctionPredefinie :: VerifierSiAssezDArguments %d de %s"; }


Chaine
LangueSemantiqueFR :: FormatCreationDescrAppelIteration ()
	{ return "On construit une DescrAppelIteration pour %s"; }


Chaine
LangueSemantiqueFR :: FormatCreationDescrAppelFonctionUtilisateur ()
	{ return "On construit une DescrAppelFonctionUtilisateur pour %s"; }
Chaine
LangueSemantiqueFR :: FormatVerifierSiPasTropDArgumentsPourFonctionUtilisateur ()
	{ return "DescrAppelFonctionUtilisateur :: VerifierSiPasTropDArguments %d de %s"; }
Chaine
LangueSemantiqueFR :: FormatVerifierSiAssezDArgumentsPourFonctionUtilisateur ()
	{ return "DescrAppelFonctionUtilisateur :: VerifierSiAssezDArguments %d de %s"; }


Chaine
LangueSemantiqueFR :: FormatCreationDescrAppelFonctionErronee ()
	{ return "On construit une DescrAppelFonctionErronee pour %s"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: ValeurInconnueNEstPasEvaluable ()
	{ return "ON NE PEUT EVALUER UNE VALEUR INCONNUE"; }

Chaine
LangueSemantiqueFR :: OnJetteLOperandeDeGaucheDeSeq ()
	{ return "On jette l'operande gauche de 'Seq'"; }

Chaine
LangueSemantiqueFR :: FormatEcritureAppelDeFonction ()
	{
		return
			"Fonction '%s', declaree (eval:%d,s:%d), appelee (eval: %d, stat: %d)";
	}
Chaine
LangueSemantiqueFR :: FormatEcritureEmploiParametre ()
	{
	return
		"Parametre %s '%s', declare (eval: %d, stat: %d), utilise (eval: %d, stat: %d)";
	}

Chaine
LangueSemantiqueFR :: FormatEmploiParametreDifferenceStatiqueTropGrande ()
	{
	return
		"EmploiParametre :: Evaluer (): "
		"differenceDeNiveauDEvaluation %d trop grande";
	}

Chaine
LangueSemantiqueFR :: FormatDescripteurDuParametreParNom ()
	{ return "Descripteur du parametre par nom %s (no %d)"; }
Chaine
LangueSemantiqueFR :: FormatDescripteurDuParametreParBesoin ()
	{ return "Descripteur du parametre par besoin %s (no %d)"; }
Chaine
LangueSemantiqueFR :: FormatAdresseDuResultatDe ()
	{ return "Adresse du resultat de %s (no %d)"; }
Chaine
LangueSemantiqueFR :: EtiquetteIntermediaireParBesoin ()
	{ return "etiquetteIntermediaireParBesoin"; }
Chaine
LangueSemantiqueFR :: FormatAdresseDuBooleenDeControleParBesoin ()
	{ return "Adresse du booleen de controle du parametre par besoin '%s' (no %d)"; }
Chaine
LangueSemantiqueFR :: FormatValeurDuBooleenDeControleParBesoin ()
	{ return "Valeur du booleen de controle du parametre par besoin '%s' (no %d)"; }
Chaine
LangueSemantiqueFR :: FormatValeurParBesoin ()
	{ return "Valeur du parametre par besoin '%s' (no %d)"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatAppelALaFonctionSansArguments ()
	{ return ">>> Appel a '%s' (contexte %d) sans arguments"; }
Chaine
LangueSemantiqueFR :: FormatAppelALaFonctionAvecArguments ()
	{ return ">>> Appel a '%s' (contexte %d) avec comme arguments:"; }
Chaine
LangueSemantiqueFR :: FormatResultatDeLAppelALaFonction ()
	{ return "<<< Resultat de l'appel a '%s' (contexte %d) = "; }
Chaine
LangueSemantiqueFR :: FormatSortieDeLAppelALaFonction ()
	{ return "<<< Retour de l'appel a '%s' (contexte %d)"; }
Chaine
LangueSemantiqueFR :: FormatLienStatiquePourAppelALaFonction ()
	{ return "lien statique (LS) pour l'appel a \"%s\""; }

Chaine
LangueSemantiqueFR :: EtiquetteSiFaux ()
	{ return "etiquetteSiFaux"; }
Chaine
LangueSemantiqueFR :: EtiquetteSuiteDuSi ()
	{ return "etiquetteSuiteDuSi"; }
Chaine
LangueSemantiqueFR :: EtiquetteContinuationDeLaContinuationDuSi ()
	{ return "continuationDeLaConditionSuSi"; }

Chaine
LangueSemantiqueFR :: FormatDebutDuCorpsDeFonction ()
	{ return "Debut du corps de '%s' (eval: %d, stat: %d)"; }
Chaine
LangueSemantiqueFR :: FormatLienStatiqueNecessairePourFonction ()
	{ return "dont 1 pour le lien statique (LS) de cette fonction"; }
Chaine
LangueSemantiqueFR :: FormatFinDuCorpsDeFonction ()
	{ return "Fin du corps de '%s'"; }
Chaine
LangueSemantiqueFR :: FormatGrapheSemantiqueDuCoprsDUneFonction ()
	{ return "\nGraphe semantique du corps de %s :\n"; }
Chaine
LangueSemantiqueFR :: FormatFormePostfixeeDuCoprsDUneFonction ()
	{ return "\nForme postfixee du corps de '%s' :\n"; }

Chaine
LangueSemantiqueFR :: EtiquetteCorpsDeFonction ()
	{ return "corpsDeFonction"; }
Chaine
LangueSemantiqueFR :: EtiquetteSuiteDeCorpsDeFonction ()
	{ return "suiteDeCorpsDeFonction"; }
Chaine
LangueSemantiqueFR :: EtiquetteContinuationDuCorpsDeFonction ()
	{ return "continuationDuCorpsDeFonction"; }

Chaine
LangueSemantiqueFR :: DebutDUneEvaluation ()
	{ return "Debut d'une evaluation"; }
Chaine
LangueSemantiqueFR :: EtiquetteContinuationDUneEvaluation ()
	{ return "continuationDUneEvaluation"; }
Chaine
LangueSemantiqueFR :: FinDUneEvaluation ()
	{ return "Fin d'une evaluation"; }

Chaine
LangueSemantiqueFR :: EtiquetteDeCorpsDeThunk ()
	{ return "corpsDeThunk"; }
Chaine
LangueSemantiqueFR :: FormatDebutDuCorpsDeThunk ()
	{ return "Debut du thunk pour \"%s\""; }
Chaine
LangueSemantiqueFR :: FormatLienStatiqueNecessairePourThunk ()
	{ return "dont 1 pour le lien statique (LS) de ce thunk"; }
Chaine
LangueSemantiqueFR :: FormatLienMarqueDeBlocDActivation ()
	{ return "et 1 pour la marque separant les blocs d'activation"; }
Chaine
LangueSemantiqueFR :: FormatFinDuCorpsDeThunk ()
	{ return "Fin du thunk pour \"%s\""; }

Chaine
LangueSemantiqueFR :: EtiquetteSuiteDeCorpsDeThunk ()
	{ return "suiteDeCorpsDeThunk"; }
Chaine
LangueSemantiqueFR :: EtiquetteContinuationDuCorpsDeThunk ()
	{ return "continuationDuCorpsDeThunk"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatIndiceDIterationSousFormeDeChaine ()
	{ return "L'indice d'iteration '%s' declare (eval: %d, stat: %d): '%s'"; }
Chaine
LangueSemantiqueFR :: IndiceDIteration ()
	{ return "indice d'iteration: "; }

Chaine
LangueSemantiqueFR :: FormatConsultationIndiceDIteration ()
	{ return "... On consulte l'indice d'iteration '%s', contexte %d"; }
Chaine
LangueSemantiqueFR :: FormatEmploiIndiceDIteration ()
	{ return "%s, employe (eval: %d, stat: %d)"; }

Chaine
LangueSemantiqueFR :: FormatEmploiIndiceDIterationDifferenceDEvaluationTropGrande ()
	{
	return
		"EmploiIndiceIteration :: Evaluer (): "
		"difference de niveau d'evaluation %d trop grande";
	}
Chaine
LangueSemantiqueFR :: FormatEmploiIndiceDIterationDansSynthese ()
	{
	return
		"Emploi de l'indice d'iteration %s (eval: %d, stat: %d)";
	}
Chaine
LangueSemantiqueFR :: FormatIndiceDIteration ()
	{ return "L'indice d'iteration '%s' declare (eval: %d, stat: %d)"; }
Chaine
LangueSemantiqueFR :: FormatIndiceDIterationPostFixe ()
	{ return "\tindice %s"; }

Chaine
LangueSemantiqueFR :: EtiquetteDebutDIteration ()
	{ return "debutDIteration"; }
Chaine
LangueSemantiqueFR :: EtiquetteSuiteDIteration ()
	{ return "suiteDIteration"; }

Chaine
LangueSemantiqueFR :: FormatAdresseIndiceDIteration ()
	{ return "Adresse de l'indice d'iteration de %s"; }
Chaine
LangueSemantiqueFR :: FormatValeurIndiceDIteration ()
	{ return "Valeur de l'indice d'iteration de %s"; }
Chaine
LangueSemantiqueFR :: FormatValeurInitialeIndiceDIteration ()
	{ return "Valeur initiale de l'indice de %s"; }
Chaine
LangueSemantiqueFR :: FormatAdresseBorneDeLIndiceDIteration ()
	{ return "Adresse de la borne superieure de l'indice de %s"; }
Chaine
LangueSemantiqueFR :: FormatValeurBorneDeLIndiceDIteration ()
	{ return "Valeur de la borne superieure de l'indice de %s"; }
Chaine
LangueSemantiqueFR :: FormatValeurInitialeDeLaBorneDIteration ()
	{ return "Valeur initiale de la borne superieure de %s"; }
Chaine
LangueSemantiqueFR :: FormaIncrementationIndiceDIteration ()
	{ return "Incrementation a jour de l'indice de %s"; }

Chaine
LangueSemantiqueFR :: AdresseDeLaSomme ()
	{ return "Adresse de la somme"; }
Chaine
LangueSemantiqueFR :: ValeurDeLaSomme ()
	{ return "Valeur de la somme"; }
Chaine
LangueSemantiqueFR :: CumulDansLaSomme ()
	{ return "Cumul dans la somme"; }
Chaine
LangueSemantiqueFR :: ValeurDeLaSommeResultante ()
	{ return "Valeur de la somme resultante"; }
Chaine
LangueSemantiqueFR :: DebutDeSomme ()
	{ return "Debut de 'Somme'"; }
Chaine
LangueSemantiqueFR :: FinDeSomme ()
	{ return "Fin de 'Somme'"; }

Chaine
LangueSemantiqueFR :: AdresseDuProduit ()
	{ return "Adresse du produit"; }
Chaine
LangueSemantiqueFR :: ValeurDuProduit ()
	{ return "Valeur du produit"; }
Chaine
LangueSemantiqueFR :: CumulDansLeProduit ()
	{ return "Cumul dans le produit"; }
Chaine
LangueSemantiqueFR :: ValeurDuProduitResultant ()
	{ return "Valeur du produit resultant"; }
Chaine
LangueSemantiqueFR :: DebutDeProduit ()
	{ return "Debut de 'Produit'"; }
Chaine
LangueSemantiqueFR :: FinDeProduit ()
	{ return "Fin de 'Produit'"; }

Chaine
LangueSemantiqueFR :: DebutDePour ()
	{ return "Debut de 'Pour'"; }
Chaine
LangueSemantiqueFR :: FinDePour ()
	{ return "Fin de 'Pour'"; }



// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: NiveauDesPredefinis ()
	{ return "Identificateurs predefinis"; }
Chaine
LangueSemantiqueFR :: NiveauPrincipal ()
	{ return "Principal"; }

Chaine
LangueSemantiqueFR :: FormatPasageDesParametres ()
	{ return "\n--- Les parametres des fonctions utilisateur sont passes %s ---\n"; }

Chaine
LangueSemantiqueFR :: CourtCircuitDesOperateursBinaires ()
	{ return "--- Les operateurs logiques binaires sont court-circuites ---\n"; }

Chaine
LangueSemantiqueFR :: TypeParametreFictifPourRattrapageDErreurs ()
	{ return "--- Type du parametre FICTIF pour rattrage d'erreurs ---"; }

Chaine
LangueSemantiqueFR :: NomParametreInconnu ()
	{ return "###  ParametreInconnu ###"; }
Chaine
LangueSemantiqueFR :: NomQualifieParametreInconnu ()
	{ return "###  ???::ParametreInconnu ###"; }

Chaine
LangueSemantiqueFR :: IdentPredefiniDefiniMultiplement ()
	{ return "Identificateur predefini '%s' defini multiplement"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatErreurSemantique ()
	{
	return
		"### %s ERREUR semantique: %s ###\n"
		"--> Terminal courant: %s\n";
	}
Chaine
LangueSemantiqueFR :: FormatAvertissementSemantique ()
	{
	return
		"### %s AVERTISSEMENT semantique: ###\n"
		"    %s\n"
		"--> Terminal courant: %s\n";
	}
Chaine
LangueSemantiqueFR :: FormatTestDeTypeAttendu ()
	{
	return
		"==> Test du type attendu:\n"
		"\t type attendu       : %s\n"
		"\t type logique trouve: %s";
	}
Chaine
LangueSemantiqueFR :: FormatEchecTestDeTypeAttendu ()
	{
	return
		"un(e) %s du type '%s' est attendu,\n"
		"    une valeur du type '%s' a ete trouvee";
	}
Chaine
LangueSemantiqueFR :: FormatLeTypeNAPasPuEtreInfere ()
	{ return "le type de '%s' n'a pas pu etre infere"; }
Chaine
LangueSemantiqueFR :: FormatLeTypeDuParametreFormelNAPasPuEtreInfere ()
	{ return "le type du parametre formel '%s' n'a pas pu etre infere"; }

Chaine
LangueSemantiqueFR :: FormatNiveauDEvaluationIncremente ()
	{ return "==> Niveau d'evaluation courant: %d"; }
Chaine
LangueSemantiqueFR :: FormatNiveauDEvaluationDecremente ()
	{ return "<== Niveau d'evaluation courant: %d"; }

Chaine
LangueSemantiqueFR :: FormatNiveauStatiqueIncremente ()
	{ return "==> Niveau statique courant: %d"; }
Chaine
LangueSemantiqueFR :: FormatNiveauStatiqueDecremente ()
	{ return "<== Niveau statique courant: %d"; }

Chaine
LangueSemantiqueFR :: LesSautSurDesSautsSontOptimises ()
	{ return "\n--- Les sauts sur des sauts sont optimises ---"; }

Chaine
LangueSemantiqueFR :: BlocDActivationPrincipal ()
	{ return "Bloc d'activation principal"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: EnteteEvalFonction ()
	{ return "Valeur:"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: EnteteEvalProcedure ()
	{ return "Execution..."; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: DebutEvaluationDirecte ()
	{ return "Debut de l'evaluation directe..."; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FinEvalProcedure ()
	{ return "...Fin"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: CodeSemantiquementCorrect ()
	{ return "*** Code Lista semantiquement correct   ***"; }

Chaine
LangueSemantiqueFR :: CodeSemantiquementIncorrect ()
	{ return "### Code Lista semantiquement INCORRECT ###"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueFR :: FormatTempsEcoule ()
	{ return "\n*** Temps ecoule: %d seconde(s) ***\n"; }


// -------------------------------------------------------------------------
//	LangueSemantiqueEN
// -------------------------------------------------------------------------

LangueSemantiqueEN :: LangueSemantiqueEN ()
	{}

LangueSemantiqueEN :: ~ LangueSemantiqueEN ()
	{}


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatNomQualifie ()
	{ return "%s::%s"; }

Chaine
LangueSemantiqueEN :: ConstantePredefinie ()
	{ return "Built-in constant"; }

Chaine
LangueSemantiqueEN :: FonctionPredefinie ()
	{ return "Built-in function"; }

Chaine
LangueSemantiqueEN :: IterationPredefinie ()
	{ return "Built-in Iteration"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: NonUtilise ()
	{ return ": unused"; }

Chaine
LangueSemantiqueEN :: FormatContenuDuDictionnaire ()
	{ return "\nContents of dictionary '%s':"; }

Chaine
LangueSemantiqueEN :: FormatPurgeDuDictionnaireVide ()
	{ return "Purging dictionary '%s', which is empty\n"; }
Chaine
LangueSemantiqueEN :: FormatPurgeDuDictionnaire ()
	{ return "Purging dictionary '%s', containing:\n"; }

Chaine
LangueSemantiqueEN :: FormatEmpilageNiveauDeDeclaration ()
	{ return "Pushing declaration level '%s'"; }
Chaine
LangueSemantiqueEN :: FormatDesempilageNiveauDeDeclaration ()
	{ return "\nPopping declaration level '%s'"; }

Chaine
LangueSemantiqueEN :: TableDesSymbolesVide ()
	{ return "Empty symbols table"; }
Chaine
LangueSemantiqueEN :: FormatTableDesSymboles ()
	{ return "===> Symbols table -- %s <==="; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatIdentNonDeclare ()
	{ return "UNDECLARED identifier '%s'"; }
Chaine
LangueSemantiqueEN :: FormatIdentNonDeclareSousFormeDeChaine ()
	{ return "UNDECLARED identifier '%s': '%s'"; }
Chaine
LangueSemantiqueEN :: FacteurIdentificateurMalForme ()
	{
	return
		"Built-in constant, built-in funciton, \n"
		"user function, formal parameter or iteration index \n"
		"expected as Factor";
	}
Chaine
LangueSemantiqueEN :: FormatIdentDeFonctionNonDeclare ()
	{ return "UNDECLARED function identifier '%s'"; }

Chaine
LangueSemantiqueEN :: FormatConstantePredefinie ()
	{ return "'%s', %s:\n\t\t%s"; }
Chaine
LangueSemantiqueEN :: FormatFonctionPredefinie ()
	{ return "'%s', %s:\n\t\t(%s) -> %s"; }
Chaine
LangueSemantiqueEN :: FormatIterateurPredefini ()
	{ return "'%s', %s: (*index*, %s) -> %s"; }

Chaine
LangueSemantiqueEN :: FormatParametreFormel ()
	{ return "Formal parameter %s '%s': '%s', declared (eval: %d, stat: %d)"; }


Chaine
LangueSemantiqueEN :: FormatErreurCommeNombre ()
	{
	return
		"ValeurLista :: CommeNombre, "
		"found a value of type %s";
	}
Chaine
LangueSemantiqueEN :: FormatErreurCommeBooleen ()
	{
	return
		"ValeurLista :: CommeBooleen, "
		"found a value of type %s";
	}
Chaine
LangueSemantiqueEN :: FormatErreurCommeChaine ()
	{
	return
		"ValeurLista :: CommeChaine, "
		"found a value of type %s";
	}


Chaine
LangueSemantiqueEN :: FormatErreurTypeValeurLista ()
	{
	return
		"ValeurLista.Ecrire (): "
		"le type \"%s\" %s is no Number, Boolean nor String";
	}


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: ParValeur ()
	{ return "by value"; }
Chaine
LangueSemantiqueEN :: ParNom ()
	{ return "by name"; }
Chaine
LangueSemantiqueEN :: ParBesoin ()
	{ return "by need"; }

Chaine
LangueSemantiqueEN :: DelimiteurDeFonctionsEtEvaluations ()
	{
	return
		"/* ************************************************ */";
	}
Chaine
LangueSemantiqueEN :: SeparationDernierParametre ()
	{ return " and "; }

Chaine
LangueSemantiqueEN :: FormatFonctionUtilisateur ()
	{ return "'%s' (s: %d): '(%s) -> %s'"; }
Chaine
LangueSemantiqueEN :: FormatBesoinDUnLienStatique ()
	{ return "Function '%s' needs a static link (SL)"; }


Chaine
LangueSemantiqueEN :: FormatParametreParValeur ()
	{ return "by value parameter '%s' (number %d): "; }
Chaine
LangueSemantiqueEN :: FormatConsultationParametreParValeur ()
	{ return "... Consulting by value parameter '%s', no %d, context %d"; }

Chaine
LangueSemantiqueEN :: FormatParametreParNom ()
	{ return "by name parameter '%s' (number %d): "; }
Chaine
LangueSemantiqueEN :: FormatEvaluationParametreParNom ()
	{ return "... EVALUATING by name parameter '%s', no %d, context %d"; }

Chaine
LangueSemantiqueEN :: ResultatEvaluation ()
	{ return "... the value is: "; }

Chaine
LangueSemantiqueEN :: FormatParametreParBesoinNonEvalue ()
	{ return "by need parameter '%s' (number %d) not evaluated yet: "; }
Chaine
LangueSemantiqueEN :: ParametreParBesoinDejaEvalue ()
	{ return "by need parameter already evaluated: "; }
Chaine
LangueSemantiqueEN :: FormatEvaluationParametreParBesoin ()
	{ return "... EVALUATING by need parameter '%s', no %d, context %d"; }
Chaine
LangueSemantiqueEN :: FormatConsultationParametreParBesoin ()
	{ return "... Consulting by need parameter '%s', no %d, context %d"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatContexteDEvaluation ()
	{ return "ContexteEval %d (%d associations):"; }

Chaine
LangueSemantiqueEN :: FormatRemonteeStatique ()
	{
	return
		"Static walk:\n\t"
		"current evaluation level: %d\n\t"
		"staic levels difference : %d";
	}

Chaine
LangueSemantiqueEN :: FormatTempsDEvaluationDirecte ()
	{ return "\n*** Direct evaluation time: %d second(s) ***\n"; }

Chaine
LangueSemantiqueEN :: ContinuationApresOperandeGauche ()
	{ return "continuationAfterLeftOperand"; }
Chaine
LangueSemantiqueEN :: ContinuationApresOperandeDroit ()
	{ return "continuationAfterRightOperand"; }
Chaine
LangueSemantiqueEN :: OnJetteLOperandeDroitDeSeq1 ()
	{ return "Throwing right operand of Seq1 away"; }
Chaine
LangueSemantiqueEN :: SeqImplicite ()
	{ return "IMPLICIT Seq"; }

Chaine
LangueSemantiqueEN :: ValeurInconnue ()
	{ return "UnknowValue"; }
Chaine
LangueSemantiqueEN :: ValeurVide ()
	{ return "*** EMPTY ***"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: ArgumentDAppel ()
	{ return "call argument"; }

Chaine
LangueSemantiqueEN :: FormatTropDArgumentsDansAppelAPredefinie ()
	{
	return
		"there are TOO MANY arguments in "
		"a call to built-in function '%s'";
	 }
Chaine
LangueSemantiqueEN :: FormatTropPeuDArgumentsDansAppelAPredefinie ()
	{
	return
		"there are TOO FEW arguments in "
		"a call to parametered built-in function '%s'";
	 }

Chaine
LangueSemantiqueEN :: FormatTropDArgumentsDansAppelAFonctionParametree ()
	{
	return
		"there are TOO MANY arguments in "
		"a call to parametered user function '%s'";
	}
Chaine
LangueSemantiqueEN :: FormatTropPeuDArgumentsDansAppelAFonctionParametree ()
	{
	return
		"there are TOO FEW arguments in "
		"a call to parametered user function '%s'\n"
		"\t%s need a value";
	}

Chaine
LangueSemantiqueEN :: FormatNomDeFonction ()
	{ return "function '%s'"; }
Chaine
LangueSemantiqueEN :: FormatNumeroDeFonction ()
	{ return "Function_%d"; }
Chaine
LangueSemantiqueEN :: FormatNomDeParametre ()
	{ return "parameter '%s'"; }
Chaine
LangueSemantiqueEN :: FormatNumeroDeParametre ()
	{ return "Parameter_%d"; }
Chaine
LangueSemantiqueEN :: FormatNumeroDEvaluation ()
	{ return "Evaluation_%d"; }

Chaine
LangueSemantiqueEN :: FormatTypeLogiqueDeFonction ()
	{ return "%s describes the type of fonction '%s'\n"; }
Chaine
LangueSemantiqueEN :: FormatTypeLogiqueDeParametre ()
	{ return "%s describes the type of parameter '%s'\n"; }
Chaine
LangueSemantiqueEN :: FormatTypeLogiqueDIdentificateurNonDeclare ()
	{ return "%s describes the type of undeclared identifier '%s'\n"; }
Chaine
LangueSemantiqueEN :: FormatTypeLogiqueDeFonctionNonDeclaree ()
	{ return "%s describes the type of undeclared function '%s'\n"; }

Chaine
LangueSemantiqueEN :: FormatRedefinitionDeFonctionUtilisateur ()
	{ return "re-definition of user function '%s'"; }
Chaine
LangueSemantiqueEN :: FormatDefinitionDeFonctionUtilisateurMasque ()
	{
	return
		"the definition of user function '%s' "
		"masks the declaration of \n\t%s";
	}

Chaine
LangueSemantiqueEN :: FormatRedefinitionDeParametre ()
	{ return "re-definition of parameter '%s'"; }
Chaine
LangueSemantiqueEN :: FormatDefinitionDeParametreMasque ()
	{
	return
		"the  definition of formal parameter '%s' "
		"masks the declaration of \n\t%s";
	}

Chaine
LangueSemantiqueEN :: FormatAucuneDeclarationAccessible ()
	{
	return
		"the identifier '%s' "
		"has no accessible declaration";
	}

Chaine
LangueSemantiqueEN :: ConditionDUnSi ()
	{ return "condition of an 'If'"; }
Chaine
LangueSemantiqueEN :: FormatAlternativesDUnSiPasDuMemeType ()
	{
	return
		"the two alternatives of an 'If' do not "
		"return values of one and the same type\n"
		"\t(here, '%s' and '%s')";
	}

Chaine
LangueSemantiqueEN :: GrapheSemantiqueDeLaSequenceDExpressionsAEvaluer ()
	{ return "\nSemantic graph of expression sequence to be evaluated:\n"; }
Chaine
LangueSemantiqueEN :: FormePostfixeeDeLaSequenceDExpressionsAEvaluer ()
	{ return "\nPostfixed form of expression sequence to be evaluated:\n"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatIteration ()
	{ return "Iteration_%d"; }
Chaine
LangueSemantiqueEN :: BorneInferieure ()
	{ return "lower bound"; }
Chaine
LangueSemantiqueEN :: BorneSuperieure ()
	{ return "upper bound"; }
Chaine
LangueSemantiqueEN :: ExpressionIteree ()
	{ return "expression iterated over"; }

Chaine
LangueSemantiqueEN :: IndiceInconnu ()
	{ return "Unknown index"; }
Chaine
LangueSemantiqueEN :: IdentAttenduCommeIndiceDIteration ()
	{ return "IDENT expected as iteration index"; }
Chaine
LangueSemantiqueEN :: FormatVirguleAttendueApresLIndice ()
	{ return "after the iteration index '%s' of a '%s'"; }
Chaine
LangueSemantiqueEN :: FormatVirguleAttendueApresLaBorneInferieure ()
	{ return "after the lower bound of a '%s'"; }
Chaine
LangueSemantiqueEN :: FormatVirguleAttendueApresLaBorneSuperieure ()
	{ return "after the upper bound of a '%s'"; }
Chaine
LangueSemantiqueEN :: FormatRedefinitionDeLIndiceDIteration ()
	{ return "iteration index '%s' is being re-defined"; }
Chaine
LangueSemantiqueEN :: FormatDefinitionDeLIndiceDIterationMasque ()
	{
	return
		"defining iteration index '%s' "
		"masks the declaration of \n\t%s";
	}
Chaine
LangueSemantiqueEN :: FormatParentheseInattendueDansAppelAFonctionNonParametree ()
	{ return "'(' unexpected in a call to fonction '%s'"; }
Chaine
LangueSemantiqueEN :: FormatEmpilageDescrAppelDeFonction ()
	{ return "Pushing a function call descriptor for '%s'"; }
Chaine
LangueSemantiqueEN :: FormatDesempilageDescrAppelDeFonction ()
	{ return "Popping a function call descriptor for '%s'"; }

// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatCreationDescrAppelDeFonctionPredefinie ()
	{ return "Creating a DescrAppelFonctionPredefinie for %s with %d arguments"; }
Chaine
LangueSemantiqueEN :: FormatEnregistrementArgumentDeFonctionPredefinie ()
	{ return "EnregistrerArgument %d of %s"; }
Chaine
LangueSemantiqueEN :: FormatVerifierSiPasTropDArgumentsPourFonctionPredefinie ()
	{ return "DescrAppelFonctionPredefinie :: VerifierSiPasTropDArguments %d of %s"; }
Chaine
LangueSemantiqueEN :: FormatVerifierSiAssezDArgumentsPourFonctionPredefinie ()
	{ return "DescrAppelFonctionPredefinie :: VerifierSiAssezDArguments %d of %s"; }


Chaine
LangueSemantiqueEN :: FormatCreationDescrAppelIteration ()
	{ return "Creating a DescrAppelIteration for %s"; }


Chaine
LangueSemantiqueEN :: FormatCreationDescrAppelFonctionUtilisateur ()
	{ return "Creating a DescrAppelFonctionUtilisateur for %s"; }
Chaine
LangueSemantiqueEN :: FormatVerifierSiPasTropDArgumentsPourFonctionUtilisateur ()
	{ return "DescrAppelFonctionUtilisateur :: VerifierSiPasTropDArguments %d of %s"; }
Chaine
LangueSemantiqueEN :: FormatVerifierSiAssezDArgumentsPourFonctionUtilisateur ()
	{ return "DescrAppelFonctionUtilisateur :: VerifierSiAssezDArguments %d of %s"; }


Chaine
LangueSemantiqueEN :: FormatCreationDescrAppelFonctionErronee ()
	{ return "Creating a DescrAppelFonctionErronee for %s"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: ValeurInconnueNEstPasEvaluable ()
	{ return "AN UNKNOWN VALUE CANNOT BE EVALUATED"; }

Chaine
LangueSemantiqueEN :: OnJetteLOperandeDeGaucheDeSeq ()
	{ return "Throwing left operand of 'Seq' away"; }

Chaine
LangueSemantiqueEN :: FormatEcritureAppelDeFonction ()
	{
	return
		"Function '%s', declared (eval: %d, stat: %d), called (eval: %d, stat: %d)";
	}
Chaine
LangueSemantiqueEN :: FormatEcritureEmploiParametre ()
	{
	return
		"Parameter %s '%s', declared (eval: %d, stat: %d), used (eval: %d, stat: %d)";
	}

Chaine
LangueSemantiqueEN :: FormatEmploiParametreDifferenceStatiqueTropGrande ()
	{
	return
		"EmploiParametre :: Evaluer (): "
		"differenceDeNiveauDEvaluation %d too large";
	}

Chaine
LangueSemantiqueEN :: FormatDescripteurDuParametreParNom ()
	{ return "Descriptor of by name parameter %s (no %d)"; }
Chaine
LangueSemantiqueEN :: FormatDescripteurDuParametreParBesoin ()
	{ return "Descriptor of by need parameter %s (no %d)"; }
Chaine
LangueSemantiqueEN :: FormatAdresseDuResultatDe ()
	{ return "Address of result of %s (no %d)"; }
Chaine
LangueSemantiqueEN :: EtiquetteIntermediaireParBesoin ()
	{ return "intermediateByNeedLabel"; }
Chaine
LangueSemantiqueEN :: FormatAdresseDuBooleenDeControleParBesoin ()
	{ return "Address of boolean to control by need parameter '%s' (no %d)"; }
Chaine
LangueSemantiqueEN :: FormatValeurDuBooleenDeControleParBesoin ()
	{ return "Value of boolean to control by need parameter '%s' (no %d)"; }
Chaine
LangueSemantiqueEN :: FormatValeurParBesoin ()
	{ return "Value of by need parameter '%s' (no %d)"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatAppelALaFonctionSansArguments ()
	{ return ">>> Call to '%s' (context %d) without arguments"; }
Chaine
LangueSemantiqueEN :: FormatAppelALaFonctionAvecArguments ()
	{ return ">>> Call to '%s' (context %d) with arguments:"; }
Chaine
LangueSemantiqueEN :: FormatResultatDeLAppelALaFonction ()
	{ return "<<< Result of call to '%s' (context %d) = "; }
Chaine
LangueSemantiqueEN :: FormatSortieDeLAppelALaFonction ()
	{ return "<<< Return from call to '%s' (context %d)"; }
Chaine
LangueSemantiqueEN :: FormatLienStatiquePourAppelALaFonction ()
	{ return "static link (SL) of call to \"%s\""; }

Chaine
LangueSemantiqueEN :: EtiquetteSiFaux ()
	{ return "etiquetteSiFaux"; }
Chaine
LangueSemantiqueEN :: EtiquetteSuiteDuSi ()
	{ return "etiquetteSuiteDuSi"; }
Chaine
LangueSemantiqueEN :: EtiquetteContinuationDeLaContinuationDuSi ()
	{ return "continuationDeLaConditionSuSi"; }

Chaine
LangueSemantiqueEN :: FormatDebutDuCorpsDeFonction ()
	{ return "Beginning of the body of '%s' (eval: %d, stat: %d)"; }
Chaine
LangueSemantiqueEN :: FormatLienStatiqueNecessairePourFonction ()
	{ return "among which 1 for this function's static link (SL)"; }
Chaine
LangueSemantiqueEN :: FormatFinDuCorpsDeFonction ()
	{ return "End of the body of '%s'"; }
Chaine
LangueSemantiqueEN :: FormatGrapheSemantiqueDuCoprsDUneFonction ()
	{ return "\nSemantic graph of %s's body:\n"; }
Chaine
LangueSemantiqueEN :: FormatFormePostfixeeDuCoprsDUneFonction ()
	{ return "\nPostfixed form of %s's body:\n"; }

Chaine
LangueSemantiqueEN :: EtiquetteCorpsDeFonction ()
	{ return "functionBody"; }
Chaine
LangueSemantiqueEN :: EtiquetteSuiteDeCorpsDeFonction ()
	{ return "functionBodyFollower"; }
Chaine
LangueSemantiqueEN :: EtiquetteContinuationDuCorpsDeFonction ()
	{ return "functionBodyContinuation"; }

Chaine
LangueSemantiqueEN :: DebutDUneEvaluation ()
	{ return "Beginning of an evaluation"; }
Chaine
LangueSemantiqueEN :: EtiquetteContinuationDUneEvaluation ()
	{ return "continuationDUneEvaluation"; }
Chaine
LangueSemantiqueEN :: FinDUneEvaluation ()
	{ return "End of an evaluation"; }

Chaine
LangueSemantiqueEN :: EtiquetteDeCorpsDeThunk ()
	{ return "thunkBody"; }
Chaine
LangueSemantiqueEN :: FormatDebutDuCorpsDeThunk ()
	{ return "Beginning of the thunk for \"%s\""; }
Chaine
LangueSemantiqueEN :: FormatLienStatiqueNecessairePourThunk ()
	{ return "among which 1 for the static link (SL) of this thunk"; }
Chaine
LangueSemantiqueEN :: FormatLienMarqueDeBlocDActivation ()
	{ return "and 1 for the activation record separation mark"; }
Chaine
LangueSemantiqueEN :: FormatFinDuCorpsDeThunk ()
	{ return "End of the thunk for \"%s\""; }

Chaine
LangueSemantiqueEN :: EtiquetteSuiteDeCorpsDeThunk ()
	{ return "thunkBodyFollower"; }
Chaine
LangueSemantiqueEN :: EtiquetteContinuationDuCorpsDeThunk ()
	{ return "thunkBodyContinuation"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatIndiceDIterationSousFormeDeChaine ()
	{ return "Iteration index '%s' declared (eval: %d, stat: %d): '%s'"; }
Chaine
LangueSemantiqueEN :: IndiceDIteration ()
	{ return "Iteration index: "; }

Chaine
LangueSemantiqueEN :: FormatConsultationIndiceDIteration ()
	{ return "... Consulting iteration index '%s', context %d"; }
Chaine
LangueSemantiqueEN :: FormatEmploiIndiceDIteration ()
	{ return "Iteration index %s, used (eval: %d, stat: %d)"; }

Chaine
LangueSemantiqueEN :: FormatEmploiIndiceDIterationDifferenceDEvaluationTropGrande ()
	{
	return
		"EmploiIndiceIteration :: Evaluer (): "
		"evaluation level difference %d too large";
	}
Chaine
LangueSemantiqueEN :: FormatEmploiIndiceDIterationDansSynthese ()
	{
	return
		"Use of iteration index %s (eval: %d, stat: %d)";
	}
Chaine
LangueSemantiqueEN :: FormatIndiceDIteration ()
	{ return "Iteration index '%s' declared (eval: %d, stat: %d)"; }
Chaine
LangueSemantiqueEN :: FormatIndiceDIterationPostFixe ()
	{ return "\tteration index %s"; }

Chaine
LangueSemantiqueEN :: EtiquetteDebutDIteration ()
	{ return "iterationStart"; }
Chaine
LangueSemantiqueEN :: EtiquetteSuiteDIteration ()
	{ return "iterationFollower"; }

Chaine
LangueSemantiqueEN :: FormatAdresseIndiceDIteration ()
	{ return "Address of iteration index of %s"; }
Chaine
LangueSemantiqueEN :: FormatValeurIndiceDIteration ()
	{ return "Value of iteration index of %s"; }
Chaine
LangueSemantiqueEN :: FormatValeurInitialeIndiceDIteration ()
	{ return "Initial value of index of %s"; }
Chaine
LangueSemantiqueEN :: FormatAdresseBorneDeLIndiceDIteration ()
	{ return "Address upper bound of the index of %s"; }
Chaine
LangueSemantiqueEN :: FormatValeurBorneDeLIndiceDIteration ()
	{ return "Value of upper bound of the index of %s"; }
Chaine
LangueSemantiqueEN :: FormatValeurInitialeDeLaBorneDIteration ()
	{ return "Initial value of upper bound of %s"; }
Chaine
LangueSemantiqueEN :: FormaIncrementationIndiceDIteration ()
	{ return "Incrementation of the index of %s"; }

Chaine
LangueSemantiqueEN :: AdresseDeLaSomme ()
	{ return "Address of sum"; }
Chaine
LangueSemantiqueEN :: ValeurDeLaSomme ()
	{ return "Valeur of sum"; }
Chaine
LangueSemantiqueEN :: CumulDansLaSomme ()
	{ return "Cumulating into the sum"; }
Chaine
LangueSemantiqueEN :: ValeurDeLaSommeResultante ()
	{ return "Value of the resulting sum"; }
Chaine
LangueSemantiqueEN :: DebutDeSomme ()
	{ return "Start of 'Sum'"; }
Chaine
LangueSemantiqueEN :: FinDeSomme ()
	{ return "End of 'Sum'"; }

Chaine
LangueSemantiqueEN :: AdresseDuProduit ()
	{ return "Address of product"; }
Chaine
LangueSemantiqueEN :: ValeurDuProduit ()
	{ return "Value of product"; }
Chaine
LangueSemantiqueEN :: CumulDansLeProduit ()
	{ return "Cumulating into the product"; }
Chaine
LangueSemantiqueEN :: ValeurDuProduitResultant ()
	{ return "Value of resulting product"; }
Chaine
LangueSemantiqueEN :: DebutDeProduit ()
	{ return "Start de 'Product'"; }
Chaine
LangueSemantiqueEN :: FinDeProduit ()
	{ return "End de 'Product'"; }

Chaine
LangueSemantiqueEN :: DebutDePour ()
	{ return "Start de 'For'"; }
Chaine
LangueSemantiqueEN :: FinDePour ()
	{ return "End de 'For'"; }



// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: NiveauDesPredefinis ()
	{ return "Builtin identifiers"; }
Chaine
LangueSemantiqueEN :: NiveauPrincipal ()
	{ return "Main"; }

Chaine
LangueSemantiqueEN :: FormatPasageDesParametres ()
	{ return "\n--- User functions parameters are passed by %s ---\n"; }

Chaine
LangueSemantiqueEN :: CourtCircuitDesOperateursBinaires ()
	{ return "--- The logical binary operators are short-cutted ---\n"; }

Chaine
LangueSemantiqueEN :: TypeParametreFictifPourRattrapageDErreurs ()
	{ return "--- Type of FICTIVIOUS parameter for error recovery ---"; }

Chaine
LangueSemantiqueEN :: NomParametreInconnu ()
	{ return "###  UnknownParameter ###"; }
Chaine
LangueSemantiqueEN :: NomQualifieParametreInconnu ()
	{ return "###  ???::UnknownParameter ###"; }

Chaine
LangueSemantiqueEN :: IdentPredefiniDefiniMultiplement ()
	{ return "Builtin identifier '%s' is multiply defined"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatErreurSemantique ()
	{
	return
		"### %s Semantic ERROR: %s ###\n"
		"--> Current token: %s\n";
	}
Chaine
LangueSemantiqueEN :: FormatAvertissementSemantique ()
	{
	return
		"### %s Semantic WARNING: ###\n"
		"    %s\n"
		"--> Current token: %s\n";
	}
Chaine
LangueSemantiqueEN :: FormatTestDeTypeAttendu ()
	{
	return
		"==> Check of expected type:\n"
		"\t expected type     : %s\n"
		"\t logical type found: %s";
	}
Chaine
LangueSemantiqueEN :: FormatEchecTestDeTypeAttendu ()
	{
	return
		"a %s of type '%s' is expected,\n"
		"    a value of type '%s' has been found";
	}
Chaine
LangueSemantiqueEN :: FormatLeTypeNAPasPuEtreInfere ()
	{ return "the type of '%s' couldn't be infered"; }
Chaine
LangueSemantiqueEN :: FormatLeTypeDuParametreFormelNAPasPuEtreInfere ()
	{ return "the type of formal parameter '%s' couldn't be infered"; }

Chaine
LangueSemantiqueEN :: FormatNiveauDEvaluationIncremente ()
	{ return "==> Current evaluation level: %d"; }
Chaine
LangueSemantiqueEN :: FormatNiveauDEvaluationDecremente ()
	{ return "<== Current evaluation level: %d"; }

Chaine
LangueSemantiqueEN :: FormatNiveauStatiqueIncremente ()
	{ return "==> Current static level: %d"; }
Chaine
LangueSemantiqueEN :: FormatNiveauStatiqueDecremente ()
	{ return "<== Current static level: %d"; }

Chaine
LangueSemantiqueEN :: LesSautSurDesSautsSontOptimises ()
	{ return "\n--- Jumps to jumps are optimized ---"; }

Chaine
LangueSemantiqueEN :: BlocDActivationPrincipal ()
	{ return "Main activation record"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: EnteteEvalFonction ()
	{ return "Value:"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: EnteteEvalProcedure ()
	{ return "Execution..."; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: DebutEvaluationDirecte ()
	{ return "Beginning direct evaluation..."; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FinEvalProcedure ()
	{ return "...End"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: CodeSemantiquementCorrect ()
	{ return "*** Lista code semantically  correct   ***"; }

Chaine
LangueSemantiqueEN :: CodeSemantiquementIncorrect ()
	{ return "### Lista code semantically  INCORRECT ###"; }


// -------------------------------------------------------------------------

Chaine
LangueSemantiqueEN :: FormatTempsEcoule ()
	{ return "\n*** Elapsed time: %d second(s) ***\n"; }



// -------------------------------------------------------------------------
// Variables globales
// -------------------------------------------------------------------------

LangueSemantiquePTR				gLANGUE_Semantique				= NULL;

LanguePredefinisPTR				gLANGUE_Traduction				= NULL;


// -------------------------------------------------------------------------
//	ChoisirLaLangueDeTraduction
// -------------------------------------------------------------------------

void
ChoisirLaLangueDeTraduction (Chaine leMnemonique)
	{
	LanguePTR	laLangue =
						Langue :: RechercherLaLangue (leMnemonique);

	if (laLangue == NULL)
		{
		std::cerr <<
			std::endl <<
			MiseEnForme (
				gLANGUE ->
					FormatLangueInconnue (),
				leMnemonique ) <<
			std::endl;
		Langue :: ListerLesLanguesConnues ();
		exit (1);
		}

	if (leMnemonique == "fr")
		{
		gLANGUE_Traduction =
			new LanguePredefinisFR;
		}
	if (leMnemonique == "en")
		{
		gLANGUE_Traduction =
			new LanguePredefinisEN;
		}

	}	// ChoisirLaLangueDeTraduction


// -------------------------------------------------------------------------
//	InitialiserLanguesSemantique
// -------------------------------------------------------------------------

void
InitialiserLanguesSemantique (Chaine leMnemonique)
	{
	if (gLANGUE_Semantique != NULL)
		delete gLANGUE_Semantique;

	if (leMnemonique == "fr")
		gLANGUE_Semantique = new LangueSemantiqueFR;
	if (leMnemonique == "en")
		gLANGUE_Semantique = new LangueSemantiqueEN;
	}
