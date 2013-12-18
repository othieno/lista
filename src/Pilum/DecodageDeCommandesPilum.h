// =========================================================================
//	DecodageDeCommandesPilum.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __DecodageDeCommandesPilum__
#define __DecodageDeCommandesPilum__


#include "Pilum.h"


// -------------------------------------------------------------------------
//	CommandeInteractive
// -------------------------------------------------------------------------

//	Description de commandes interactives comme celles de Pilum

class		CommandeInteractive;
typedef	CommandeInteractive	* CommandeInteractivePTR;

class CommandeInteractive
	{
public:
										CommandeInteractive (
											Chaine						leNomCourt,
											Chaine						leNomLong,
											GenreDArgumentEventuel	leGenreDArgumentEventuel,
											Chaine						laDescrArgumentEventuel,
											Chaine						leCommentaire );

										CommandeInteractive ();

	Chaine							NomCourt ();
	Chaine							NomLong ();
	GenreDArgumentEventuel		LeGenreDArgumentEventuel ();
	Chaine							DescrArgumentEventuel ();
	Chaine							Commentaire ();

private:

	Chaine							fNomCourt;
	Chaine							fNomLong;
	GenreDArgumentEventuel		fGenreDArgumentEventuel;
	Chaine							fDescrArgumentEventuel;
	Chaine							fCommentaire;

	};	// CommandeInteractive


// -------------------------------------------------------------------------
//	CommandesPilum
// -------------------------------------------------------------------------

class		CommandesPilum;
typedef	CommandesPilum			* CommandesPilumPTR;

typedef CommandeInteractivePTR
										(CommandesPilum :: 
											* CommandeInteractiveCommandesPilumPFM) ();

class CommandesPilum
	{
public:
										CommandesPilum ();

	virtual							~ CommandesPilum ();


	//	Erreurs eventuelles
	// -------------------------------------------------------------------------

	virtual Chaine					FormatCommandeInconnue () = 0;
											// virtuelle pure
	virtual Chaine					FormatCommandeAUnArgumentObligatoire () = 0;
											// virtuelle pure

	virtual Chaine					FormatCommandeCourteDejaEnregistree () = 0;
											// virtuelle pure
	virtual Chaine					FormatCommandeLongueDejaEnregistree () = 0;
											// virtuelle pure


	//	CommandesPilum
	// -------------------------------------------------------------------------

	virtual CommandeInteractivePTR
										CommandeVide ();

	virtual CommandeInteractivePTR
										CommandeAide () = 0;
											// virtuelle pure

	virtual CommandeInteractivePTR
										CommandeLangue () = 0;
											// virtuelle pure

	virtual CommandeInteractivePTR
										CommandeInterrompre () = 0;
											// virtuelle pure

	virtual  CommandeInteractivePTR
										CommandeAfficherLaMemoireDuCode () = 0;
											// virtuelle pure
	virtual  CommandeInteractivePTR
										CommandeAfficherLaTableDesChaines () = 0;
											// virtuelle pure
	virtual  CommandeInteractivePTR
										CommandeAfficherLaPile () = 0;
											// virtuelle pure

	virtual  CommandeInteractivePTR
										CommandeAfficherLEtatInterne () = 0;
											// virtuelle pure

	virtual  CommandeInteractivePTR
										CommandeModePasAPas () = 0;
											// virtuelle pure
	virtual  CommandeInteractivePTR
										CommandeModeContinu () = 0;
											// virtuelle pure

	virtual  CommandeInteractivePTR
										CommandeModeArretSurAppelOuRetour () = 0;
											// virtuelle pure

	virtual  CommandeInteractivePTR
										CommandeModePasAPasAvecAffichageDeLaPile () = 0;
											// virtuelle pure
	virtual  CommandeInteractivePTR
										CommandeModeArretSurAppelOuRetourAvecAffichageDeLaPile () = 0;
											// virtuelle pure

	};	// CommandesPilum


// -------------------------------------------------------------------------
//	CommandesPilumFR
// -------------------------------------------------------------------------

class		CommandesPilumFR;
typedef	CommandesPilumFR		* CommandesPilumFRPTR;

class CommandesPilumFR : public CommandesPilum
	{
public:
										CommandesPilumFR ();


	//	Erreurs eventuelles
	// -------------------------------------------------------------------------

	Chaine							FormatCommandeInconnue ();
	Chaine							FormatCommandeAUnArgumentObligatoire ();

	Chaine							FormatCommandeCourteDejaEnregistree ();
	Chaine							FormatCommandeLongueDejaEnregistree ();


	//	CommandesPilum
	// -------------------------------------------------------------------------

	CommandeInteractivePTR		CommandeAide ();
	CommandeInteractivePTR		CommandeLangue ();

	CommandeInteractivePTR		CommandeInterrompre ();

	CommandeInteractivePTR		CommandeAfficherLaMemoireDuCode ();
	CommandeInteractivePTR		CommandeAfficherLaTableDesChaines ();
	CommandeInteractivePTR		CommandeAfficherLaPile ();

	CommandeInteractivePTR		CommandeAfficherLEtatInterne ();

	CommandeInteractivePTR		CommandeModePasAPas ();
	CommandeInteractivePTR		CommandeModeContinu ();

	CommandeInteractivePTR		CommandeModeArretSurAppelOuRetour ();

	CommandeInteractivePTR		CommandeModePasAPasAvecAffichageDeLaPile ();
	CommandeInteractivePTR		CommandeModeArretSurAppelOuRetourAvecAffichageDeLaPile ();

	};	// CommandesPilumFR


// -------------------------------------------------------------------------
//	CommandesPilumEN
// -------------------------------------------------------------------------

class		CommandesPilumEN;
typedef	CommandesPilumEN		* CommandesPilumENPTR;

class CommandesPilumEN : public CommandesPilum
	{
public:
										CommandesPilumEN ();


	//	Erreurs eventuelles
	// -------------------------------------------------------------------------

	Chaine							FormatCommandeInconnue ();
	Chaine							FormatCommandeAUnArgumentObligatoire ();

	Chaine							FormatCommandeCourteDejaEnregistree ();
	Chaine							FormatCommandeLongueDejaEnregistree ();


	//	CommandesPilum
	// -------------------------------------------------------------------------

	CommandeInteractivePTR		CommandeAide ();
	CommandeInteractivePTR		CommandeLangue ();

	CommandeInteractivePTR		CommandeInterrompre ();

	CommandeInteractivePTR		CommandeAfficherLaMemoireDuCode ();
	CommandeInteractivePTR		CommandeAfficherLaTableDesChaines ();
	CommandeInteractivePTR		CommandeAfficherLaPile ();

	CommandeInteractivePTR		CommandeAfficherLEtatInterne ();

	CommandeInteractivePTR		CommandeModePasAPas ();
	CommandeInteractivePTR		CommandeModeContinu ();

	CommandeInteractivePTR		CommandeModeArretSurAppelOuRetour ();

	CommandeInteractivePTR		CommandeModePasAPasAvecAffichageDeLaPile ();
	CommandeInteractivePTR		CommandeModeArretSurAppelOuRetourAvecAffichageDeLaPile ();

	};	// CommandesPilumEN


// -------------------------------------------------------------------------
//	BaseAssocInstanceMethodeCommandesPilum
// -------------------------------------------------------------------------

/*
Classe abstraite dont les sous-classes associent:
	- une instance d'une classe
	- une de ses methodes
pour pouvoir ensuite faire executer la seconde par la premiere.

Cette technique est souvent appelee 'foncteur' (functor) dans la litterature
*/

class		BaseAssocInstanceMethodeCommandesPilum;
typedef	BaseAssocInstanceMethodeCommandesPilum
										* BaseAssocInstanceMethodeCommandesPilumPTR;

class BaseAssocInstanceMethodeCommandesPilum
   {
public:

										BaseAssocInstanceMethodeCommandesPilum (
											CommandeInteractiveCommandesPilumPFM
														leCommandeInteractiveCommandesPilumPFM );

	virtual							~ BaseAssocInstanceMethodeCommandesPilum ();


	CommandeInteractiveCommandesPilumPFM
										LeCommandeInteractiveCommandesPilumPFM ();

	// two possible functions to call member function. virtual cause derived
	// classes will use a pointer to an object and a pointer to a member function
	// to make the function call

	virtual void					Declencher (Chaine lArgumentDeLOption) = 0;
											//	virtuelle pure

	virtual void					operator () (Chaine lArgumentDeLOption) = 0;
											//	virtuelle pure
											// alternative a Declencher (),
											//	vue "foncteur"


protected:

	CommandeInteractiveCommandesPilumPFM
										fCommandeInteractiveCommandesPilumPFM;
   };	// BaseAssocInstanceMethodeCommandesPilum


typedef std::vector <BaseAssocInstanceMethodeCommandesPilumPTR>
										TableauDeBaseAssocInstanceMethodeCommandesPilum;
typedef TableauDeBaseAssocInstanceMethodeCommandesPilum
										* TableauDeBaseAssocInstanceMethodeCommandesPilumPTR;


// -------------------------------------------------------------------------
//	TemplateAssocInstanceMethodeCommandesPilum
// -------------------------------------------------------------------------

template <class TClass>
class TemplateAssocInstanceMethodeCommandesPilum: 
	public BaseAssocInstanceMethodeCommandesPilum
   {
public:
										TemplateAssocInstanceMethodeCommandesPilum (
											CommandeInteractiveCommandesPilumPFM
														leCommandeInteractiveCommandesPilumPFM,
											TClass	* lInstance,
											void		(TClass :: * leFonctionMembrePTR) (Chaine) )
											:	BaseAssocInstanceMethodeCommandesPilum (
													leCommandeInteractiveCommandesPilumPFM )
											{
											fInstance = lInstance;
											fFonctionMembrePTR = leFonctionMembrePTR;
											};

	virtual void					Declencher (Chaine lArgumentDeLaCommande)
											{
											(fInstance ->* fFonctionMembrePTR)
												(lArgumentDeLaCommande);
											};

	virtual void					operator () (Chaine lArgumentDeLaCommande)
											{
											(fInstance ->* fFonctionMembrePTR)
												(lArgumentDeLaCommande);
											};


private:

	TClass							* fInstance;
	void								(TClass :: * fFonctionMembrePTR)	(Chaine);
	
   };	// TemplateAssocInstanceMethodeCommandesPilum


// -------------------------------------------------------------------------
//	DecodageDeCommandesPilum
// -------------------------------------------------------------------------

class   DecodageDeCommandesPilum;
typedef TemplateAssocInstanceMethodeCommandesPilum
										<DecodageDeCommandesPilum>
											AssocDecodageDeCommandesPilum;
typedef AssocDecodageDeCommandesPilum
										* AssocDecodageDeCommandesPilumPTR;

class DecodageDeCommandesPilum
	{
public:
										DecodageDeCommandesPilum (
											CommandesPilumPTR	lesCommandesPilum,
											PilumPTR				laMachinePilum );
										
	virtual							~ DecodageDeCommandesPilum ();


	virtual void					Initialiser ();

	void								EnregistrerLAssociation (
											BaseAssocInstanceMethodeCommandesPilumPTR
														leFunctor );

	Chaine							Usage ();

	void								CommandeVide (Chaine argument);


	virtual void					Aide (Chaine argument);
	virtual void					Langue (Chaine argument);

	virtual void					ActionAvantInteraction ();
	virtual void					ActionAvantChaqueCommande ();
	virtual void					ExecuterLaCommande (
											Chaine	laCommande,
											Chaine	lArgument );
	virtual void					ActionApresChaqueCommande ();
	virtual void					ActionApresInteraction ();

	void								InteragirAvecLUtilisateur ();

	void								LInteractionDoitSePoursuivre (
											bool laValeur );
	bool								LInteractionDoitSePoursuivre ();

	virtual void					Interrompre (Chaine argument);

	virtual void					AfficherLaMemoireDuCode (Chaine argument);
	virtual void					AfficherLaTableDesChaines (Chaine argument);
	virtual void					AfficherLaPile (Chaine argument);

	virtual void					AfficherLEtatInterne (Chaine argument);

	virtual void					ModePasAPas (Chaine argument);
	virtual void					ModeContinu (Chaine argument);

	virtual void					ModeArretSurAppelOuRetour (Chaine argument);

	virtual void					ModePasAPasAvecAffichageDeLaPile (Chaine argument);
	virtual void					ModeArretSurAppelOuRetourAvecAffichageDeLaPile (
											Chaine argument );

	void								InterruptionUtilisateur (Chaine argument);


protected:
	
	TableauDeBaseAssocInstanceMethodeCommandesPilumPTR
										fTableauDeBaseAssocInstanceMethodeCommandesPilum;

	static AssocDecodageDeCommandesPilumPTR
										sAssocDecodageDeCommandesPilum;

	CommandesPilumPTR					fCommandesPilum;

	bool								fModeVerbeux;

	bool								fDejaInteragi;

	Chaine							fCommandeInteractiveCourante;
	Chaine							fArgumentDeLaCommandeInteractiveCourante;

	Chaine							fDerniereCommandeInteractive;
	Chaine							fDernierArgumentDeLaCommandeInteractive;
	
	bool								fLInteractionDoitSePoursuivre;


	PilumPTR							fMachinePilum;

	};	// DecodageDeCommandesPilum


// -------------------------------------------------------------------------
//	DecodageDeCommandesPilum
// -------------------------------------------------------------------------

/*
class		DecodageDeCommandesPilum;
typedef	DecodageDeCommandesPilum
										* DecodageDeCommandesPilumPTR;

class DecodageDeCommandesPilum : virtual public DecodageDeCommandesPilum
	{
public:
										DecodageDeCommandesPilum (
											CommandesPilumPTR	lesCommandesPilum,
											PilumPTR				laMachinePilum );

	virtual void					Initialiser ();


	virtual void					Aide (Chaine argument);

	virtual void					Langue (Chaine argument);

	virtual void					Interrompre (Chaine argument);

	virtual void					AfficherLaMemoireDuCode (Chaine argument);
	virtual void					AfficherLaTableDesChaines (Chaine argument);
	virtual void					AfficherLaPile (Chaine argument);

	virtual void					AfficherLEtatInterne (Chaine argument);

	virtual void					ModePasAPas (Chaine argument);
	virtual void					ModeContinu (Chaine argument);

	virtual void					ModeArretSurAppelOuRetour (Chaine argument);

	virtual void					ModePasAPasAvecAffichageDeLaPile (Chaine argument);
	virtual void					ModeArretSurAppelOuRetourAvecAffichageDeLaPile (
											Chaine argument );


	virtual void					ActionAvantInteraction ();
	virtual void					ActionAvantChaqueCommande ();
	virtual void					ActionApresChaqueCommande ();
	virtual void					ActionApresInteraction ();

	void								InterruptionUtilisateur (Chaine argument);


protected:

	PilumPTR							fMachinePilum;

	};	// DecodageDeCommandesPilum


typedef TemplateAssocInstanceMethodeCommandesPilum
										<DecodageDeCommandesPilum>
											AssocDecodageDeCommandesPilum;
*/


#endif /* __DecodageDeCommandesPilum__ */
