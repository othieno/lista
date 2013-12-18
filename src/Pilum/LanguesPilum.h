// =========================================================================
//	LanguesPilum.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __LanguesPilum__
#define __LanguesPilum__


#include "Langues.h"
#include "LanguesPredefinis.h"

#include "DecodageDeCommandesPilum.h"

#include "Pilum.h"


// -------------------------------------------------------------------------
//	LanguePilum
// -------------------------------------------------------------------------

class		LanguePilum;
typedef	LanguePilum				* LanguePilumPTR;

class LanguePilum : virtual public LanguePredefinis
	{
public:
										LanguePilum ();

	virtual							~ LanguePilum ();


	//	Pilum
	// -------------------------------------------------------------------------

	virtual Chaine					LienDynamique () = 0;
											// virtuelle pure
	virtual Chaine					LienStatique () = 0;
											// virtuelle pure

	virtual Chaine					AdresseDeRetour () = 0;
											// virtuelle pure
	virtual Chaine					AdresseThunk () = 0;
											// virtuelle pure
	virtual Chaine					LienStatiqueFutur () = 0;
											// virtuelle pure

	virtual Chaine					AdresseDansLaPile () = 0;
											// virtuelle pure

	virtual Chaine					ValeurInconnue () = 0;
											// virtuelle pure

	virtual Chaine					FormatCommeEntier () = 0;
											// virtuelle pure
	virtual Chaine					FormatCommeFlottant () = 0;
											// virtuelle pure
	virtual Chaine					FormatCommeBooleen () = 0;
											// virtuelle pure
	virtual Chaine					FormatCommeChaine () = 0;
											// virtuelle pure

	virtual Chaine					Entier () = 0;
											// virtuelle pure
	virtual Chaine					Flottant () = 0;
											// virtuelle pure
	virtual Chaine					Booleen () = 0;
											// virtuelle pure
	virtual Chaine					Caractere () = 0;
											// virtuelle pure
	virtual Chaine					Chaine_ () = 0;
											// virtuelle pure

	virtual Chaine					MarqueBlocDActivationDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					MarqueBlocDActivationDeThunk () = 0;
											// virtuelle pure

	virtual Chaine					FormatValeurInconnue () = 0;
											// virtuelle pure

	virtual Chaine					FormatLienDynamique () = 0;
											// virtuelle pure
	virtual Chaine					FormatLienStatique () = 0;
											// virtuelle pure

	virtual Chaine					FormatAdresseDeRetour () = 0;
											// virtuelle pure
	virtual Chaine					FormatAdresseThunk () = 0;
											// virtuelle pure
	virtual Chaine					FormatLienStatiqueFutur  () = 0;
											// virtuelle pure

	virtual Chaine					FormatAdresseDansLaPile () = 0;
											// virtuelle pure

	virtual Chaine					FormatEntier () = 0;
											// virtuelle pure
	virtual Chaine					FormatFlottant () = 0;
											// virtuelle pure
	virtual Chaine					FormatBooleen () = 0;
											// virtuelle pure
	virtual Chaine					FormatCaractere () = 0;
											// virtuelle pure
	virtual Chaine					FormatChaine () = 0;
											// virtuelle pure


	virtual Chaine					ModeleMarqueBlocDActivation () = 0;
											// virtuelle pure
	virtual Chaine					FormatMarqueBlocDActivation () = 0;
											// virtuelle pure

	virtual Chaine					FormatTypeValeurPilumInconnu () = 0;
											// virtuelle pure

	virtual Chaine					PretPourLExecution () = 0;
											// virtuelle pure

	virtual Chaine					ErreurFatalePilum () = 0;
											// virtuelle pure

	virtual Chaine					VoulezVousVoirLeCode () = 0;
											// virtuelle pure
	virtual Chaine					VoulezVousVoirLEtatDeLaPile () = 0;
											// virtuelle pure
	virtual Chaine					Oui () = 0;
											// virtuelle pure

	virtual Chaine					PasPuAllouerLaMemoireDuCode () = 0;
											// virtuelle pure
	virtual Chaine					PasPuAllouerLaMemoireDesChaines () = 0;
											// virtuelle pure
	virtual Chaine					PasPuAllouerLaPile () = 0;
											// virtuelle pure
	virtual Chaine					FormatPasPuOuvrirLeFichierBinaireEnLecture () = 0;
											// virtuelle pure

	virtual Chaine					FormatCodeOperatoirePilumInconnu () = 0;
											// virtuelle pure

	virtual Chaine					FormatTailleDesChaines () = 0;
											// virtuelle pure
	virtual Chaine					FormatTableDesChaines () = 0;
											// virtuelle pure
	virtual Chaine					FormatNombreDInstructions () = 0;
											// virtuelle pure

	virtual Chaine					FormatInstructionPilumInconnue () = 0;
											// virtuelle pure

	virtual Chaine					FormatValeurDansLaPilePasDuBonType () = 0;
											// virtuelle pure

	virtual Chaine					ZonesDePilumPasAllouees () = 0;
											// virtuelle pure

	virtual Chaine					SommetDePileDevraitEtreBooleen () = 0;
											// virtuelle pure
	virtual Chaine					ElementSousSommetDePileDevraitEtreBooleen () = 0;
											// virtuelle pure
	virtual Chaine					SommetDePileDevraitEtreEntier () = 0;
											// virtuelle pure
	virtual Chaine					ElementSousSommetDePileDevraitEtreEntier () = 0;
											// virtuelle pure
	virtual Chaine					SommetDePileDevraitEtreFlottant () = 0;
											// virtuelle pure
	virtual Chaine					ElementSousSommetDePileDevraitEtreFlottant () = 0;
											// virtuelle pure
	virtual Chaine					SecondElementSousSommetDePileDevraitEtreFlottant () = 0;
											// virtuelle pure
	virtual Chaine					SommetDePileDevraitEtreUneCaractere () = 0;
											// virtuelle pure
	virtual Chaine					SommetDePileDevraitEtreUneChaine () = 0;
											// virtuelle pure
	virtual Chaine					ElementSousSommetDePileDevraitEtreUneChaine () = 0;
											// virtuelle pure
	virtual Chaine					SecondElementSousSommetDePileDevraitEtreUneChaine () = 0;
											// virtuelle pure

	virtual Chaine					SommetDePileDevraitEtreAdresseDansLaPile () = 0;
											// virtuelle pure
	virtual Chaine					ElementSousSommetDePileDevraitEtreAdresseDansLaPile () = 0;
											// virtuelle pure

	virtual Chaine					SommetDePileDevraitEtreAdresseDUnThunk () = 0;
											// virtuelle pure

	virtual Chaine					FormatBlocDActivationPourFonction () = 0;
											// virtuelle pure
	virtual Chaine					FormatBlocDActivationPourThunk () = 0;
											// virtuelle pure


	virtual Chaine					InstructionInconnue () = 0;
											// virtuelle pure

	virtual Chaine					Halte () = 0;
											// virtuelle pure

	virtual Chaine					Commentaire () = 0;
											// virtuelle pure

	virtual Chaine					EmpilerMarqueBlocDActivation () = 0;
											// virtuelle pure

	virtual Chaine					Reserver () = 0;
											// virtuelle pure
	virtual Chaine					Desempiler () = 0;
											// virtuelle pure	
	virtual Chaine					Stocker () = 0;
											// virtuelle pure
	virtual Chaine					Dupliquer () = 0;
											// virtuelle pure
			
	virtual Chaine					EmpilerValeur () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerAdresse () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerLienStatique () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerEntier () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerFlottant () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerBooleen () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerCaractere () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerChaine () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerValInconnue () = 0;
											// virtuelle pure

	virtual Chaine					Sauter () = 0;
											// virtuelle pure
	virtual Chaine					SauterSiFaux () = 0;
											// virtuelle pure
	virtual Chaine					Appel () = 0;
											// virtuelle pure
	virtual Chaine					RetourDeFonction () = 0;
											// virtuelle pure
	virtual Chaine					RetourDeProcedure () = 0;
											// virtuelle pure
	virtual Chaine					EmpilerDescripteurDeThunk () = 0;
											// virtuelle pure
	virtual Chaine					EvaluerThunk () = 0;
											// virtuelle pure
	virtual Chaine					EvaluerThunkAvecMarqueBlocDActivation () = 0;
											// virtuelle pure

	virtual Chaine					LireEntier () = 0;
											// virtuelle pure
	virtual Chaine					LireFlottant () = 0;
											// virtuelle pure
	virtual Chaine					LireBooleen () = 0;
											// virtuelle pure
	virtual Chaine					LireCaractere () = 0;
											// virtuelle pure
	virtual Chaine					LireChaine () = 0;
											// virtuelle pure
	virtual Chaine					EcrireEntier () = 0;
											// virtuelle pure
	virtual Chaine					EcrireFlottant () = 0;
											// virtuelle pure
	virtual Chaine					EcrireBooleen () = 0;
											// virtuelle pure
	virtual Chaine					EcrireCaractere () = 0;
											// virtuelle pure
	virtual Chaine					EcrireChaine () = 0;
											// virtuelle pure
	virtual Chaine					EcrireFinDeLigne () = 0;
											// virtuelle pure

	virtual Chaine					FormaterFlottant () = 0;
											// virtuelle pure

	virtual Chaine					IncrEntier () = 0;
											// virtuelle pure
	virtual Chaine					DecrEntier () = 0;
											// virtuelle pure
	virtual Chaine					IncrFlottant () = 0;
											// virtuelle pure
	virtual Chaine					DecrFlottant () = 0;
											// virtuelle pure
	virtual Chaine					Moins1Entier () = 0;
											// virtuelle pure
	virtual Chaine					Moins1Flottant () = 0;
											// virtuelle pure

	virtual Chaine					AbsEntier () = 0;
											// virtuelle pure
	virtual Chaine					AbsFlottant () = 0;
											// virtuelle pure

	virtual Chaine					PlusEntier () = 0;
											// virtuelle pure
	virtual Chaine					MoinsEntier () = 0;
											// virtuelle pure
	virtual Chaine					FoisEntier () = 0;
											// virtuelle pure
	virtual Chaine					DiviseEntier () = 0;
											// virtuelle pure
	virtual Chaine					ModuloEntier () = 0;
											// virtuelle pure
	virtual Chaine					PlusFlottant () = 0;
											// virtuelle pure
	virtual Chaine					MoinsFlottant () = 0;
											// virtuelle pure
	virtual Chaine					FoisFlottant () = 0;
											// virtuelle pure
	virtual Chaine					DiviseFlottant () = 0;
											// virtuelle pure

	virtual Chaine					ConvertirEntierEnFlottant () = 0;
											// virtuelle pure
	virtual Chaine					TronquerFlottantEnEntier () = 0;
											// virtuelle pure

	virtual Chaine					EgaleEntier () = 0;
											// virtuelle pure	
	virtual Chaine					InfEntier () = 0;
											// virtuelle pure
	virtual Chaine					InfEgaleEntier () = 0;
											// virtuelle pure
	virtual Chaine					DifferentEntier () = 0;
											// virtuelle pure
	virtual Chaine					SupEgaleEntier () = 0;
											// virtuelle pure
	virtual Chaine					SupEntier () = 0;
											// virtuelle pure
	virtual Chaine					EgaleFlottant () = 0;
											// virtuelle pure
	virtual Chaine					InfFlottant () = 0;
											// virtuelle pure
	virtual Chaine					InfEgaleFlottant () = 0;
											// virtuelle pure
	virtual Chaine					DifferentFlottant () = 0;
											// virtuelle pure
	virtual Chaine					SupEgaleFlottant () = 0;
											// virtuelle pure
	virtual Chaine					SupFlottant () = 0;
											// virtuelle pure
	
	virtual Chaine					EgaleChaine () = 0;
											// virtuelle pure
	virtual Chaine					InfChaine () = 0;
											// virtuelle pure
	virtual Chaine					InfEgaleChaine () = 0;
											// virtuelle pure
	virtual Chaine					DifferentChaine () = 0;
											// virtuelle pure
	virtual Chaine					SupEgaleChaine () = 0;
											// virtuelle pure
	virtual Chaine					SupChaine () = 0;
											// virtuelle pure
			

	virtual Chaine					ErreurInterne () = 0;
											// virtuelle pure
	
	virtual Chaine					DebordementPile () = 0;
											// virtuelle pure
	virtual Chaine					DebordementPileVersLeBas () = 0;
											// virtuelle pure
	
	virtual Chaine					VariableNonInitialisee () = 0;
											// virtuelle pure
	
	virtual Chaine					DiviseEntierParZero () = 0;
											// virtuelle pure
	virtual Chaine					ModuloEntierParZero () = 0;
											// virtuelle pure
	virtual Chaine					DiviseFlottantParZero () = 0;
											// virtuelle pure
	
	virtual Chaine					InterruptionUtilisateur () = 0;
											// virtuelle pure
	virtual Chaine					ErreurInternePilum () = 0;
											// virtuelle pure

	virtual Chaine					FormatEtatDePilum () = 0;
											// virtuelle pure
	virtual Chaine					FormatTailleDeLaMemoireDuCode () = 0;
											// virtuelle pure
	virtual Chaine					FormatLimiteSommet () = 0;
											// virtuelle pure
	virtual Chaine					FormatTailleDesChainesPilum () = 0;
											// virtuelle pure
	virtual Chaine					FormatEtatCourant () = 0;
											// virtuelle pure
	virtual Chaine					FormatInstructionCourante () = 0;
											// virtuelle pure
	virtual Chaine					FormatSommet () = 0;
											// virtuelle pure
	virtual Chaine					FormatEnvironnementCourant () = 0;
											// virtuelle pure

	virtual Chaine					FormatPromptPilum () = 0;
											// virtuelle pure
	virtual Chaine					FormatCommandePilum () = 0;
											// virtuelle pure
	virtual Chaine					SurPointDArret () = 0;
											// virtuelle pure

	virtual Chaine					FormatCommandePilumInconnue () = 0;
											// virtuelle pure

	virtual Chaine					FinNormaleDeLExecution () = 0;
											// virtuelle pure

	virtual Chaine					FormatTempsDExecutionParPilum () = 0;
											// virtuelle pure

	virtual Chaine					FormatContenuDeLaMemoireDuCode () = 0;
											// virtuelle pure

	virtual Chaine					FormatContenuDeLaTableDesChaines () = 0;
											// virtuelle pure

	virtual Chaine					FormatPileVide () = 0;
											// virtuelle pure
	virtual Chaine					ContenuDeLaPile () = 0;
											// virtuelle pure
											
	virtual Chaine					EnvironnementCourant () = 0;
											// virtuelle pure
	virtual Chaine					AutreEnvironnement () = 0;
											// virtuelle pure
	virtual Chaine					PasUnEnvironnement () = 0;
											// virtuelle pure

	virtual Chaine					FormatTailleDeLaPilePasEntiere () = 0;
											// virtuelle pure
	virtual Chaine					FichierBinairePilumAttendu () = 0;
											// virtuelle pure

	};	//	LanguePilum


// -------------------------------------------------------------------------
//	LanguePilumFR
// -------------------------------------------------------------------------

class		LanguePilumFR;
typedef	LanguePilumFR			* LanguePilumFRPTR;

class LanguePilumFR : 
	virtual public LanguePredefinisFR, virtual public LanguePilum
	{
public:
										LanguePilumFR ();

	//	Pilum
	// -------------------------------------------------------------------------

	Chaine							LienDynamique ();
	Chaine							LienStatique ();

	Chaine							AdresseDeRetour ();
	Chaine							AdresseThunk ();
	Chaine							LienStatiqueFutur ();

	Chaine							AdresseDansLaPile ();


	Chaine							ValeurInconnue ();

	Chaine							FormatCommeEntier ();
	Chaine							FormatCommeFlottant ();
	Chaine							FormatCommeBooleen ();
	Chaine							FormatCommeChaine ();


	Chaine							Entier ();
	Chaine							Flottant ();
	Chaine							Booleen ();
	Chaine							Caractere ();
	Chaine							Chaine_ ();

	Chaine							MarqueBlocDActivationDeFonction ();
	Chaine							MarqueBlocDActivationDeThunk ();

	Chaine							FormatValeurInconnue ();

	Chaine							FormatLienDynamique ();
	Chaine							FormatLienStatique ();

	Chaine							FormatAdresseDeRetour ();
	Chaine							FormatAdresseThunk ();
	Chaine							FormatLienStatiqueFutur  ();

	Chaine							FormatAdresseDansLaPile ();

	Chaine							FormatEntier ();
	Chaine							FormatFlottant ();
	Chaine							FormatBooleen ();
	Chaine							FormatCaractere ();
	Chaine							FormatChaine ();


	Chaine							ModeleMarqueBlocDActivation ();
	Chaine							FormatMarqueBlocDActivation ();

	Chaine							FormatTypeValeurPilumInconnu ();

	Chaine							PretPourLExecution ();

	Chaine							ErreurFatalePilum ();

	Chaine							VoulezVousVoirLeCode ();
	Chaine							VoulezVousVoirLEtatDeLaPile ();
	Chaine							Oui ();

	Chaine							PasPuAllouerLaMemoireDuCode ();
	Chaine							PasPuAllouerLaMemoireDesChaines ();
	Chaine							PasPuAllouerLaPile ();
	Chaine							FormatPasPuOuvrirLeFichierBinaireEnLecture ();

	Chaine							FormatCodeOperatoirePilumInconnu ();

	Chaine							FormatTailleDesChaines ();
	Chaine							FormatTableDesChaines ();
	Chaine							FormatNombreDInstructions ();
	
	Chaine							FormatInstructionPilumInconnue ();

	Chaine							FormatValeurDansLaPilePasDuBonType ();

	Chaine							ZonesDePilumPasAllouees ();

	Chaine							SommetDePileDevraitEtreBooleen ();
	Chaine							ElementSousSommetDePileDevraitEtreBooleen ();
	Chaine							SommetDePileDevraitEtreEntier ();
	Chaine							ElementSousSommetDePileDevraitEtreEntier ();
	Chaine							SommetDePileDevraitEtreFlottant ();
	Chaine							ElementSousSommetDePileDevraitEtreFlottant ();
	Chaine							SecondElementSousSommetDePileDevraitEtreFlottant ();
	Chaine							SommetDePileDevraitEtreUneCaractere ();
	Chaine							SommetDePileDevraitEtreUneChaine ();
	Chaine							ElementSousSommetDePileDevraitEtreUneChaine ();
	Chaine							SecondElementSousSommetDePileDevraitEtreUneChaine ();

	Chaine							SommetDePileDevraitEtreAdresseDansLaPile ();
	Chaine							ElementSousSommetDePileDevraitEtreAdresseDansLaPile ();

	Chaine							SommetDePileDevraitEtreAdresseDUnThunk ();

	Chaine							FormatBlocDActivationPourFonction ();
	Chaine							FormatBlocDActivationPourThunk ();


	Chaine							InstructionInconnue ();

	Chaine							Halte ();

	Chaine							Commentaire ();

	Chaine							EmpilerMarqueBlocDActivation ();

	Chaine							Reserver ();
	Chaine							Desempiler ();	
	Chaine							Stocker ();
	Chaine							Dupliquer ();
			
	Chaine							EmpilerValeur ();
	Chaine							EmpilerAdresse ();
	Chaine							EmpilerLienStatique ();
	Chaine							EmpilerEntier ();
	Chaine							EmpilerFlottant ();
	Chaine							EmpilerBooleen ();
	Chaine							EmpilerCaractere ();
	Chaine							EmpilerChaine ();
	Chaine							EmpilerValInconnue ();

	Chaine							Sauter ();
	Chaine							SauterSiFaux ();
	Chaine							Appel ();
	Chaine							RetourDeFonction ();
	Chaine							RetourDeProcedure ();
	Chaine							EmpilerDescripteurDeThunk ();
	Chaine							EvaluerThunk ();
	Chaine							EvaluerThunkAvecMarqueBlocDActivation ();

	Chaine							LireEntier ();
	Chaine							LireFlottant ();
	Chaine							LireBooleen ();
	Chaine							LireCaractere ();
	Chaine							LireChaine ();
	Chaine							EcrireEntier ();
	Chaine							EcrireFlottant ();
	Chaine							EcrireBooleen ();
	Chaine							EcrireCaractere ();
	Chaine							EcrireChaine ();
	Chaine							EcrireFinDeLigne ();

	Chaine							FormaterFlottant ();

	Chaine							IncrEntier ();
	Chaine							DecrEntier ();
	Chaine							IncrFlottant ();
	Chaine							DecrFlottant ();
	Chaine							Moins1Entier ();
	Chaine							Moins1Flottant ();

	Chaine							AbsEntier ();
	Chaine							AbsFlottant ();

	Chaine							PlusEntier ();
	Chaine							MoinsEntier ();
	Chaine							FoisEntier ();
	Chaine							DiviseEntier ();
	Chaine							ModuloEntier ();
	Chaine							PlusFlottant ();
	Chaine							MoinsFlottant ();
	Chaine							FoisFlottant ();
	Chaine							DiviseFlottant ();

	Chaine							ConvertirEntierEnFlottant ();
	Chaine							TronquerFlottantEnEntier ();

	Chaine							EgaleEntier ();		
	Chaine							InfEntier ();
	Chaine							InfEgaleEntier ();
	Chaine							DifferentEntier ();
	Chaine							SupEgaleEntier ();
	Chaine							SupEntier ();
	Chaine							EgaleFlottant ();
	Chaine							InfFlottant ();
	Chaine							InfEgaleFlottant ();
	Chaine							DifferentFlottant ();
	Chaine							SupEgaleFlottant ();
	Chaine							SupFlottant ();
	
	Chaine							EgaleChaine ();
	Chaine							InfChaine ();
	Chaine							InfEgaleChaine ();
	Chaine							DifferentChaine ();
	Chaine							SupEgaleChaine ();
	Chaine							SupChaine ();


	Chaine							ErreurInterne ();
	
	Chaine							DebordementPile ();
	Chaine							DebordementPileVersLeBas  ();
	
	Chaine							VariableNonInitialisee ();
	
	Chaine							DiviseEntierParZero ();
	Chaine							ModuloEntierParZero ();
	Chaine							DiviseFlottantParZero ();
	
	Chaine							InterruptionUtilisateur ();
	Chaine							ErreurInternePilum ();

	Chaine							FormatEtatDePilum ();
	Chaine							FormatTailleDeLaMemoireDuCode ();
	Chaine							FormatLimiteSommet ();
	Chaine							FormatTailleDesChainesPilum ();
	Chaine							FormatEtatCourant ();
	Chaine							FormatInstructionCourante ();
	Chaine							FormatSommet ();
	Chaine							FormatEnvironnementCourant ();

	Chaine							FormatPromptPilum ();
	Chaine							FormatCommandePilum ();
	Chaine							SurPointDArret ();

	Chaine							FormatCommandePilumInconnue ();

	Chaine							FinNormaleDeLExecution ();

	Chaine							FormatTempsDExecutionParPilum ();

	Chaine							FormatContenuDeLaMemoireDuCode ();

	Chaine							FormatContenuDeLaTableDesChaines ();

	Chaine							FormatPileVide ();
	Chaine							ContenuDeLaPile ();

	Chaine							EnvironnementCourant ();
	Chaine							AutreEnvironnement ();
	Chaine							PasUnEnvironnement ();

	Chaine							FormatTailleDeLaPilePasEntiere ();
	Chaine							FichierBinairePilumAttendu ();
	
	};	//	LanguePilumFR


// -------------------------------------------------------------------------
//	LanguePilumEN
// -------------------------------------------------------------------------

class		LanguePilumEN;
typedef	LanguePilumEN			* LanguePilumENPTR;

class LanguePilumEN :
	virtual public LanguePredefinisEN, virtual public LanguePilum
	{
public:
										LanguePilumEN ();

	//	Pilum
	// -------------------------------------------------------------------------

	Chaine							LienDynamique ();
	Chaine							LienStatique ();

	Chaine							AdresseDeRetour ();
	Chaine							AdresseThunk ();
	Chaine							LienStatiqueFutur ();

	Chaine							AdresseDansLaPile ();


	Chaine							ValeurInconnue ();

	Chaine							FormatCommeEntier ();
	Chaine							FormatCommeFlottant ();
	Chaine							FormatCommeBooleen ();
	Chaine							FormatCommeChaine ();


	Chaine							Entier ();
	Chaine							Flottant ();
	Chaine							Booleen ();
	Chaine							Caractere ();
	Chaine							Chaine_ ();

	Chaine							MarqueBlocDActivationDeFonction ();
	Chaine							MarqueBlocDActivationDeThunk ();

	Chaine							FormatValeurInconnue ();

	Chaine							FormatLienDynamique ();
	Chaine							FormatLienStatique ();

	Chaine							FormatAdresseDeRetour ();
	Chaine							FormatAdresseThunk ();
	Chaine							FormatLienStatiqueFutur  ();

	Chaine							FormatAdresseDansLaPile ();

	Chaine							FormatEntier ();
	Chaine							FormatFlottant ();
	Chaine							FormatBooleen ();
	Chaine							FormatCaractere ();
	Chaine							FormatChaine ();


	Chaine							ModeleMarqueBlocDActivation ();
	Chaine							FormatMarqueBlocDActivation ();

	Chaine							FormatTypeValeurPilumInconnu ();

	Chaine							PretPourLExecution ();

	Chaine							ErreurFatalePilum ();

	Chaine							VoulezVousVoirLeCode ();
	Chaine							VoulezVousVoirLEtatDeLaPile ();
	Chaine							Oui ();

	Chaine							PasPuAllouerLaMemoireDuCode ();
	Chaine							PasPuAllouerLaMemoireDesChaines ();
	Chaine							PasPuAllouerLaPile ();
	Chaine							FormatPasPuOuvrirLeFichierBinaireEnLecture ();

	Chaine							FormatCodeOperatoirePilumInconnu ();

	Chaine							FormatTailleDesChaines ();
	Chaine							FormatTableDesChaines ();
	Chaine							FormatNombreDInstructions ();

	Chaine							FormatInstructionPilumInconnue ();

	Chaine							FormatValeurDansLaPilePasDuBonType ();

	Chaine							ZonesDePilumPasAllouees ();

	Chaine							SommetDePileDevraitEtreBooleen ();
	Chaine							ElementSousSommetDePileDevraitEtreBooleen ();
	Chaine							SommetDePileDevraitEtreEntier ();
	Chaine							ElementSousSommetDePileDevraitEtreEntier ();
	Chaine							SommetDePileDevraitEtreFlottant ();
	Chaine							ElementSousSommetDePileDevraitEtreFlottant ();
	Chaine							SecondElementSousSommetDePileDevraitEtreFlottant ();
	Chaine							SommetDePileDevraitEtreUneCaractere ();
	Chaine							SommetDePileDevraitEtreUneChaine ();
	Chaine							ElementSousSommetDePileDevraitEtreUneChaine ();
	Chaine							SecondElementSousSommetDePileDevraitEtreUneChaine ();

	Chaine							SommetDePileDevraitEtreAdresseDansLaPile ();
	Chaine							ElementSousSommetDePileDevraitEtreAdresseDansLaPile ();

	Chaine							SommetDePileDevraitEtreAdresseDUnThunk ();

	Chaine							FormatBlocDActivationPourFonction ();
	Chaine							FormatBlocDActivationPourThunk ();


	Chaine							InstructionInconnue ();

	Chaine							Halte ();

	Chaine							Commentaire ();

	Chaine							EmpilerMarqueBlocDActivation ();

	Chaine							Reserver ();
	Chaine							Desempiler ();	
	Chaine							Stocker ();
	Chaine							Dupliquer ();
			
	Chaine							EmpilerValeur ();
	Chaine							EmpilerAdresse ();
	Chaine							EmpilerLienStatique ();
	Chaine							EmpilerEntier ();
	Chaine							EmpilerFlottant ();
	Chaine							EmpilerBooleen ();
	Chaine							EmpilerCaractere ();
	Chaine							EmpilerChaine ();
	Chaine							EmpilerValInconnue ();

	Chaine							Sauter ();
	Chaine							SauterSiFaux ();
	Chaine							Appel ();
	Chaine							RetourDeFonction ();
	Chaine							RetourDeProcedure ();
	Chaine							EmpilerDescripteurDeThunk ();
	Chaine							EvaluerThunk ();
	Chaine							EvaluerThunkAvecMarqueBlocDActivation ();

	Chaine							LireEntier ();
	Chaine							LireFlottant ();
	Chaine							LireBooleen ();
	Chaine							LireCaractere ();
	Chaine							LireChaine ();
	Chaine							EcrireEntier ();
	Chaine							EcrireFlottant ();
	Chaine							EcrireBooleen ();
	Chaine							EcrireCaractere ();
	Chaine							EcrireChaine ();
	Chaine							EcrireFinDeLigne ();

	Chaine							FormaterFlottant ();

	Chaine							IncrEntier ();
	Chaine							DecrEntier ();
	Chaine							IncrFlottant ();
	Chaine							DecrFlottant ();
	Chaine							Moins1Entier ();
	Chaine							Moins1Flottant ();

	Chaine							AbsEntier ();
	Chaine							AbsFlottant ();

	Chaine							PlusEntier ();
	Chaine							MoinsEntier ();
	Chaine							FoisEntier ();
	Chaine							DiviseEntier ();
	Chaine							ModuloEntier ();
	Chaine							PlusFlottant ();
	Chaine							MoinsFlottant ();
	Chaine							FoisFlottant ();
	Chaine							DiviseFlottant ();

	Chaine							ConvertirEntierEnFlottant ();
	Chaine							TronquerFlottantEnEntier ();

	Chaine							EgaleEntier ();		
	Chaine							InfEntier ();
	Chaine							InfEgaleEntier ();
	Chaine							DifferentEntier ();
	Chaine							SupEgaleEntier ();
	Chaine							SupEntier ();
	Chaine							EgaleFlottant ();
	Chaine							InfFlottant ();
	Chaine							InfEgaleFlottant ();
	Chaine							DifferentFlottant ();
	Chaine							SupEgaleFlottant ();
	Chaine							SupFlottant ();
	
	Chaine							EgaleChaine ();
	Chaine							InfChaine ();
	Chaine							InfEgaleChaine ();
	Chaine							DifferentChaine ();
	Chaine							SupEgaleChaine ();
	Chaine							SupChaine ();


	Chaine							ErreurInterne ();
	
	Chaine							DebordementPile ();
	Chaine							DebordementPileVersLeBas  ();
	
	Chaine							VariableNonInitialisee ();
	
	Chaine							DiviseEntierParZero ();
	Chaine							ModuloEntierParZero ();
	Chaine							DiviseFlottantParZero ();
	
	Chaine							InterruptionUtilisateur ();
	Chaine							ErreurInternePilum ();

	Chaine							FormatEtatDePilum ();
	Chaine							FormatTailleDeLaMemoireDuCode ();
	Chaine							FormatLimiteSommet ();
	Chaine							FormatTailleDesChainesPilum ();
	Chaine							FormatEtatCourant ();
	Chaine							FormatInstructionCourante ();
	Chaine							FormatSommet ();
	Chaine							FormatEnvironnementCourant ();

	Chaine							FormatPromptPilum ();
	Chaine							FormatCommandePilum ();
	Chaine							SurPointDArret ();

	Chaine							FormatCommandePilumInconnue ();

	Chaine							FinNormaleDeLExecution ();

	Chaine							FormatTempsDExecutionParPilum ();

	Chaine							FormatContenuDeLaMemoireDuCode ();

	Chaine							FormatContenuDeLaTableDesChaines ();

	Chaine							FormatPileVide ();
	Chaine							ContenuDeLaPile ();

	Chaine							EnvironnementCourant ();
	Chaine							AutreEnvironnement ();
	Chaine							PasUnEnvironnement ();

	Chaine							FormatTailleDeLaPilePasEntiere ();
	Chaine							FichierBinairePilumAttendu ();
	
	};	//	LanguePilumEN


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

extern LanguePilumPTR			gLANGUE_Pilum;

extern CommandesPilumPTR		gCommandesPilum;

extern CommandesPilumFR			gCommandesPilumFR;
extern CommandesPilumEN			gCommandesPilumEN;


// -------------------------------------------------------------------------
//	InitialiserLanguesPilum
// -------------------------------------------------------------------------

void									InitialiserLanguesPilum (
											Chaine leMnemonique = LANGUE_PAR_DEFAUT );


#endif /* __LanguesPilum__ */
