// =========================================================================
//	DecodageDeCommandesPilum.cc
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#include "DecodageDeCommandesPilum.h"

#include "LanguesPredefinis.h"

#include "LanguesPilum.h"


// -------------------------------------------------------------------------
//	CommandeInteractive
// -------------------------------------------------------------------------

CommandeInteractive :: CommandeInteractive (
	Chaine						leNomCourt,
	Chaine						leNomLong,
	GenreDArgumentEventuel	leGenreDArgumentEventuel,
	Chaine						laDescrArgumentEventuel,
	Chaine						leCommentaire )
	{
	fNomCourt = leNomCourt;
	fNomLong = leNomLong;
	fGenreDArgumentEventuel = leGenreDArgumentEventuel;
	fDescrArgumentEventuel = laDescrArgumentEventuel;
	fCommentaire = leCommentaire;
	}

CommandeInteractive :: CommandeInteractive ()
	{
	fNomCourt = "";
	fNomLong = "";
	fGenreDArgumentEventuel = kAucun;
	fDescrArgumentEventuel = "";
	fCommentaire = "";
	}


// -------------------------------------------------------------------------

Chaine
CommandeInteractive :: NomCourt ()
	{ return fNomCourt; }
Chaine
CommandeInteractive :: NomLong ()
	{ return fNomLong; }
GenreDArgumentEventuel
CommandeInteractive :: LeGenreDArgumentEventuel ()
	{ return fGenreDArgumentEventuel; }
Chaine
CommandeInteractive :: DescrArgumentEventuel ()
	{ return fDescrArgumentEventuel; }
Chaine
CommandeInteractive :: Commentaire ()
	{ return fCommentaire; }


// -------------------------------------------------------------------------
//	CommandesPilum
// -------------------------------------------------------------------------

CommandesPilum :: CommandesPilum ()
	{}

CommandesPilum :: ~ CommandesPilum ()
	{}


CommandeInteractivePTR
CommandesPilum :: CommandeVide ()
	{ return new CommandeInteractive (); }


// -------------------------------------------------------------------------
//	CommandesPilumFR
// -------------------------------------------------------------------------

CommandesPilumFR :: CommandesPilumFR ()
	{}


// -------------------------------------------------------------------------

Chaine
CommandesPilumFR :: FormatCommandeInconnue ()
	{ return "la commande '%s' est inconnue\n%s"; }

Chaine
CommandesPilumFR :: FormatCommandeAUnArgumentObligatoire ()
	{ return "la commande '%s' a un argument obligatoire '%s'\n%s"; }

Chaine
CommandesPilumFR :: FormatCommandeCourteDejaEnregistree ()
	{ return "la commande courte '%s' a deja ete enregistree"; }
Chaine
CommandesPilumFR :: FormatCommandeLongueDejaEnregistree ()
	{ return "la commande longue '%s' a deja ete enregistree"; }


// -------------------------------------------------------------------------

CommandeInteractivePTR
CommandesPilumFR :: CommandeAide ()
	{
	return
		new CommandeInteractive (
			"h",		"aide",							kAucun,			"",
			"affiche la presente aide"
			);
	}

CommandeInteractivePTR
CommandesPilumFR :: CommandeLangue ()
	{
	return
		new CommandeInteractive (
			"l",		"langue",						kObligatoire,	"fr | en",
			"choix de la langue des CommandesPilum Pilum"
			);
	}

CommandeInteractivePTR
CommandesPilumFR :: CommandeInterrompre ()
	{
	return
		new CommandeInteractive (
			"q",		"quitter",							kAucun,			"",
			"interrompre l'execution par Pilum"
			);
	}

CommandeInteractivePTR
CommandesPilumFR :: CommandeAfficherLaMemoireDuCode ()
	{
	return
		new CommandeInteractive (
			"c",		"code",						kAucun,			"",
			"affiche la memoire du code"
			);
	}
CommandeInteractivePTR
CommandesPilumFR :: CommandeAfficherLaTableDesChaines ()
	{
	return
		new CommandeInteractive (
			"t",		"chaines",						kAucun,			"",
			"affiche la table des chaines"
			);
	}
CommandeInteractivePTR
CommandesPilumFR :: CommandeAfficherLaPile ()
	{
	return
		new CommandeInteractive (
			"p",		"pile",						kAucun,			"",
			"affiche la pile"
			);
	}

CommandeInteractivePTR
CommandesPilumFR :: CommandeAfficherLEtatInterne ()
	{
	return
		new CommandeInteractive (
			"e",		"etat",						kAucun,			"",
			"affiche l'etat interne de Pilum"
			);
	}

CommandeInteractivePTR
CommandesPilumFR :: CommandeModePasAPas ()
	{
	return
		new CommandeInteractive (
			"s",		"pas",						kAucun,			"",
			"mode pas-a-pas"
			);
	}
CommandeInteractivePTR
CommandesPilumFR :: CommandeModeContinu ()
	{
	return
		new CommandeInteractive (
			"k",		"continu",						kAucun,			"",
			"mode continu"
			);
	}

CommandeInteractivePTR
CommandesPilumFR :: CommandeModeArretSurAppelOuRetour ()
	{
	return
		new CommandeInteractive (
			"f",		"appel-et-retour",						kAucun,			"",
			"arret sur les appels et retours"
			);
	}

CommandeInteractivePTR
CommandesPilumFR :: CommandeModePasAPasAvecAffichageDeLaPile ()
	{
	return
		new CommandeInteractive (
			"sp",		"pas-et-pile",						kAucun,			"",
			"mode pas a pas avec affichage de la pile"
			);
	}
CommandeInteractivePTR
CommandesPilumFR :: CommandeModeArretSurAppelOuRetourAvecAffichageDeLaPile ()
	{
	return
		new CommandeInteractive (
			"fp",		"appel-et-retour-et-pile",						kAucun,			"",
			"arret sur les appels et retours avec affichage de la pile"
			);
	}


// -------------------------------------------------------------------------
//	CommandesPilumEN
// -------------------------------------------------------------------------

CommandesPilumEN :: CommandesPilumEN ()
	{}


// -------------------------------------------------------------------------

Chaine
CommandesPilumEN :: FormatCommandeInconnue ()
	{ return "command `%s' is unknown"; }

Chaine
CommandesPilumEN :: FormatCommandeAUnArgumentObligatoire ()
	{ return "command '%s' has a mandatory argument '%s'\n%s"; }

Chaine
CommandesPilumEN :: FormatCommandeCourteDejaEnregistree ()
	{ return "short command '%s' has already been registered"; }
Chaine
CommandesPilumEN :: FormatCommandeLongueDejaEnregistree ()
	{ return "long command '%s' has already been registered"; }


// -------------------------------------------------------------------------

CommandeInteractivePTR
CommandesPilumEN :: CommandeAide ()
	{
	return
		new CommandeInteractive (
			"h",		"help",							kAucun,			"",
			"displays this help"
			);
	}

CommandeInteractivePTR
CommandesPilumEN :: CommandeLangue ()
	{
	return
		new CommandeInteractive (
			"l",		"language",						kObligatoire,	"fr | en",
			"choice of Pilum commands' language"
			);
	}

CommandeInteractivePTR
CommandesPilumEN :: CommandeInterrompre ()
	{
	return
		new CommandeInteractive (
			"q",		"quit",							kAucun,			"",
			"interrupt Pilum execution"
			);
	}

CommandeInteractivePTR
CommandesPilumEN :: CommandeAfficherLaMemoireDuCode ()
	{
	return
		new CommandeInteractive (
			"c",		"code",						kAucun,			"",
			"displays the code memory"
			);
	}
CommandeInteractivePTR
CommandesPilumEN :: CommandeAfficherLaTableDesChaines ()
	{
	return
		new CommandeInteractive (
			"t",		"strings",						kAucun,			"",
			"displays the strings table"
			);
	}
CommandeInteractivePTR
CommandesPilumEN :: CommandeAfficherLaPile ()
	{
	return
		new CommandeInteractive (
			"p",		"stack",						kAucun,			"",
			"displays the stack"
			);
	}

CommandeInteractivePTR
CommandesPilumEN :: CommandeAfficherLEtatInterne ()
	{
	return
		new CommandeInteractive (
			"e",		"state",						kAucun,			"",
			"displays Pilum's internal state"
			);
	}

CommandeInteractivePTR
CommandesPilumEN :: CommandeModePasAPas ()
	{
	return
		new CommandeInteractive (
			"s",		"step",						kAucun,			"",
			"step-by-step mode"
			);
	}
CommandeInteractivePTR
CommandesPilumEN :: CommandeModeContinu ()
	{
	return
		new CommandeInteractive (
			"k",		"continuous",						kAucun,			"",
			"continuous mode"
			);
	}

CommandeInteractivePTR
CommandesPilumEN :: CommandeModeArretSurAppelOuRetour ()
	{
	return
		new CommandeInteractive (
			"f",		"call-and-return",						kAucun,			"",
			"stop at calls and returns"
			);
	}

CommandeInteractivePTR
CommandesPilumEN :: CommandeModePasAPasAvecAffichageDeLaPile ()
	{
	return
		new CommandeInteractive (
			"sp",		"step-and-stack",						kAucun,			"",
			"step-by-step mode with stack display"
			);
	}
CommandeInteractivePTR
CommandesPilumEN :: CommandeModeArretSurAppelOuRetourAvecAffichageDeLaPile ()
	{
	return
		new CommandeInteractive (
			"fp",		"call-and-return-and-stack",						kAucun,			"",
			"stop at calls and returns with stack display"
			);
	}


// -------------------------------------------------------------------------
//	DecodageDeCommandesPilum
// -------------------------------------------------------------------------

void
DecodageDeCommandesPilum :: CommandeVide (Chaine argument)
	{}

void
DecodageDeCommandesPilum :: Aide (Chaine argument)
	{
	std::cout <<
		Usage () <<
		std::endl;
	}

void
DecodageDeCommandesPilum :: Langue (Chaine argument)
	{
	if (Langue :: RechercherLaLangue (argument) != NULL)
		{
		InitialiserLanguesPredefinis (argument);
		InitialiserLanguesSupportCPlusPlus (argument);

		InitialiserLanguesPilum (argument);
		}	// if

	LInteractionDoitSePoursuivre (true);
	}


// -------------------------------------------------------------------------

void
DecodageDeCommandesPilum :: ExecuterLaCommande (
	Chaine	laCommande,
	Chaine	lArgument )
	{		
	// retourne true si l'interaction
	// doit se poursuivre

	bool		commandeReconnue = false;
		
	TableauDeBaseAssocInstanceMethodeCommandesPilum :: iterator
				i;
	
	for (
		i = fTableauDeBaseAssocInstanceMethodeCommandesPilum -> begin ();
		i != fTableauDeBaseAssocInstanceMethodeCommandesPilum -> end ();
		++ i )
		{
		CommandeInteractiveCommandesPilumPFM
					leCommandeInteractiveCommandesPilumPFM =
						(* i) -> LeCommandeInteractiveCommandesPilumPFM ();

		commandeReconnue =
			laCommande
				==
			((fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) ()) -> NomCourt ()
				||
			laCommande
				==
			(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) () -> NomLong ();

//			std::cout << "==> commandeReconnue  = " << commandeReconnue << std::endl << std::flush;

		if (commandeReconnue)
			{
			switch (
				(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) () ->
					LeGenreDArgumentEventuel ()
				)
				{
				case kAucun:
					break;

				case kOptionnel:
					{
					if (! lArgument.empty ())
						{
						//	on a un argument pour cette commande
//							std::cout << 
//								"==> argument optionnel d'option reconnu " 
//								<< lArgument << std::endl << std::flush;
						}	// if
					}
					break;

				case kObligatoire:
					{
					if (! lArgument.empty ())
						{
						//	on a un argument pour cette commande
//							std::cout << "==> argument obligatoire d'option reconnu " << lArgument << std::endl << std::flush;
						}
					else
						std::cout <<
							MiseEnForme (
								fCommandesPilum ->
									FormatCommandeAUnArgumentObligatoire (),
								laCommande,
								(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) ()
									-> DescrArgumentEventuel (),
								Usage () ) <<
							std::cout;
					}
					break;
				}	// switch

			return
				(* i) -> Declencher (lArgument);

			break;
			}	// if
		}	// for

	if (! commandeReconnue)
		std::cout <<
			MiseEnForme (
				fCommandesPilum ->
					FormatCommandeInconnue (),
				laCommande,
				Usage () );

	}	// DecodageDeCommandesPilum :: ExecuterLaCommande


// -------------------------------------------------------------------------

void 
DecodageDeCommandesPilum :: ActionAvantInteraction ()
	{
	if (fModeVerbeux && ! fDejaInteragi)
		Aide ("");

	fMachinePilum -> ActionAvantInteraction  ();

	LInteractionDoitSePoursuivre (true);
	}

void 
DecodageDeCommandesPilum :: ActionAvantChaqueCommande ()
	{
	fMachinePilum -> ActionAvantChaqueCommande  ();

	std::cout <<
		MiseEnForme (
			gLANGUE_Pilum ->
				FormatCommandePilum (),
			fDerniereCommandeInteractive,
			fDernierArgumentDeLaCommandeInteractive );		
	}

void 
DecodageDeCommandesPilum :: ActionApresChaqueCommande ()
	{
	fMachinePilum -> ActionApresChaqueCommande  ();
	}

void 
DecodageDeCommandesPilum :: ActionApresInteraction ()
	{ 
	fDejaInteragi = true;

	fMachinePilum -> ActionApresInteraction  ();
	}


// -------------------------------------------------------------------------

void 
DecodageDeCommandesPilum :: InteragirAvecLUtilisateur ()
	{
	bool		lInteractionContinue = true;

	ActionAvantInteraction ();
	
//	std::cout << "==> Pilum :: InteragirAvecLUtilisateur..." << std::endl;
	
	while (lInteractionContinue)	//	boucle infinie
		{
		ActionAvantChaqueCommande ();

		Chaine	chaineLue =
						FLireChaine (kLectureSansAutre, Chaine (""));
	
		if (chaineLue.empty ())
			{
			//	fCommandeCourante reste inchangee
			}
		else
			{
			std::string::size_type
						positionEspace = chaineLue.find (" ");
			
			if (positionEspace != std::string::npos)
				{
				fCommandeInteractiveCourante =
					chaineLue.substr (0, positionEspace);
				fArgumentDeLaCommandeInteractiveCourante = 
					chaineLue.substr (
						positionEspace + 1, chaineLue.length () );
				}
			else
				{
				fCommandeInteractiveCourante = chaineLue;
				fArgumentDeLaCommandeInteractiveCourante = "";
				}

			fDerniereCommandeInteractive = fCommandeInteractiveCourante;
			fDernierArgumentDeLaCommandeInteractive =
				fArgumentDeLaCommandeInteractiveCourante;
			}
				
		ExecuterLaCommande (
			fCommandeInteractiveCourante, fArgumentDeLaCommandeInteractiveCourante );
		
		lInteractionContinue =
			LInteractionDoitSePoursuivre ();

		ActionApresChaqueCommande ();
		}	//	while

	ActionApresInteraction ();

	}	//	DecodageDeCommandesPilum :: InteragirAvecLUtilisateur


// -------------------------------------------------------------------------

void
DecodageDeCommandesPilum :: LInteractionDoitSePoursuivre (
	bool laValeur )
	{ fLInteractionDoitSePoursuivre = laValeur; }

bool
DecodageDeCommandesPilum :: LInteractionDoitSePoursuivre ()
	{ return fLInteractionDoitSePoursuivre; }


// -------------------------------------------------------------------------

AssocDecodageDeCommandesPilumPTR
DecodageDeCommandesPilum :: sAssocDecodageDeCommandesPilum = NULL;


// -------------------------------------------------------------------------
//	BaseAssocInstanceMethodeCommandesPilum
// -------------------------------------------------------------------------

BaseAssocInstanceMethodeCommandesPilum :: BaseAssocInstanceMethodeCommandesPilum (
	CommandeInteractiveCommandesPilumPFM
				leCommandeInteractiveCommandesPilumPFM )
	{
	fCommandeInteractiveCommandesPilumPFM =
		leCommandeInteractiveCommandesPilumPFM;
/*
	std::cout << JMI
		MiseEnForme (
			"BaseAssocInstanceMethodeCommandesPilum :: BaseAssocInstanceMethodeCommandesPilum %s, %s, |%s|",
			leCommandeInteractiveCommandesPilumPFM -> NomCourt (),
			leCommandeInteractiveCommandesPilumPFM -> NomLong (),
			leCommandeInteractiveCommandesPilumPFM -> Commentaire ()
			) << std::endl;
*/
	}


BaseAssocInstanceMethodeCommandesPilum :: ~ BaseAssocInstanceMethodeCommandesPilum ()
	{}

CommandeInteractiveCommandesPilumPFM
BaseAssocInstanceMethodeCommandesPilum :: LeCommandeInteractiveCommandesPilumPFM ()
	{ return fCommandeInteractiveCommandesPilumPFM; }


// -------------------------------------------------------------------------
//	DecodageDeCommandesPilum
// -------------------------------------------------------------------------

DecodageDeCommandesPilum :: DecodageDeCommandesPilum (
	CommandesPilumPTR	lesCommandesPilum,
	PilumPTR				laMachinePilum )
	{
	fCommandesPilum = lesCommandesPilum;
	fMachinePilum = laMachinePilum;

	fModeVerbeux = fMachinePilum -> ModeVerbeux ();
	
	fTableauDeBaseAssocInstanceMethodeCommandesPilum = NULL;

	fDejaInteragi = false;

	fCommandeInteractiveCourante = "";
	fArgumentDeLaCommandeInteractiveCourante = "";

	fDerniereCommandeInteractive = "";	
	fDernierArgumentDeLaCommandeInteractive = "";

	fLInteractionDoitSePoursuivre = false;


	GenreDExecution
				leGenreDExecution =
					fMachinePilum -> LeGenreDExecution ();

	switch (leGenreDExecution)
		{
		case kPasAPas:
			fDerniereCommandeInteractive =
				gCommandesPilum ->
					CommandeAide () -> NomCourt ();
			break;

		case kPasAPasAvecAffichageDeLaPile :
			fDerniereCommandeInteractive =
				gCommandesPilum ->
					CommandeModePasAPasAvecAffichageDeLaPile () -> NomCourt ();
			break;

		case kArretSurAppelOuRetour:
			fDerniereCommandeInteractive =
				gCommandesPilum ->
					CommandeModeArretSurAppelOuRetour () -> NomCourt ();
			break;

		case kArretSurAppelOuRetourAvecAffichageDeLaPile:
			fDerniereCommandeInteractive =
				gCommandesPilum ->
					CommandeModeArretSurAppelOuRetourAvecAffichageDeLaPile () -> 
						NomCourt ();
			break;

		case kEnContinu:
			fDerniereCommandeInteractive =
				gCommandesPilum ->
					CommandeModeContinu () -> NomCourt ();
			break;

		default:
			fDerniereCommandeInteractive =
				gCommandesPilum ->
					CommandeAide () -> NomCourt ();
		}	//	switch

	fCommandeInteractiveCourante = fDerniereCommandeInteractive;
	}	// DecodageDeCommandesPilum :: DecodageDeCommandesPilum



DecodageDeCommandesPilum :: ~ DecodageDeCommandesPilum ()
	{}


// -------------------------------------------------------------------------

void
DecodageDeCommandesPilum :: Initialiser ()
	{
	sAssocDecodageDeCommandesPilum =
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeVide,
			NULL,
			& DecodageDeCommandesPilum :: CommandeVide );

	fTableauDeBaseAssocInstanceMethodeCommandesPilum =
		new TableauDeBaseAssocInstanceMethodeCommandesPilum;

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeAide,
			this,
			& DecodageDeCommandesPilum :: Aide ));

	EnregistrerLAssociation (sAssocDecodageDeCommandesPilum);

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeLangue,
			this,
			& DecodageDeCommandesPilum :: Langue ));

	EnregistrerLAssociation (sAssocDecodageDeCommandesPilum);

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeAfficherLaMemoireDuCode,
			this,
			& DecodageDeCommandesPilum :: AfficherLaMemoireDuCode ));

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeAfficherLaTableDesChaines,
			this,
			& DecodageDeCommandesPilum :: AfficherLaTableDesChaines ));

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeAfficherLaPile,
			this,
			& DecodageDeCommandesPilum :: AfficherLaPile ));

	EnregistrerLAssociation (sAssocDecodageDeCommandesPilum);

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeAfficherLEtatInterne,
			this,
			& DecodageDeCommandesPilum :: AfficherLEtatInterne ));

	EnregistrerLAssociation (sAssocDecodageDeCommandesPilum);

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeModePasAPas,
			this,
			& DecodageDeCommandesPilum :: ModePasAPas ));

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeModeContinu,
			this,
			& DecodageDeCommandesPilum :: ModeContinu ));

	EnregistrerLAssociation (sAssocDecodageDeCommandesPilum);

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeModeArretSurAppelOuRetour,
			this,
			& DecodageDeCommandesPilum :: ModeArretSurAppelOuRetour ));

	EnregistrerLAssociation (sAssocDecodageDeCommandesPilum);

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeModePasAPasAvecAffichageDeLaPile,
			this,
			& DecodageDeCommandesPilum ::
				ModePasAPasAvecAffichageDeLaPile ));

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeModeArretSurAppelOuRetourAvecAffichageDeLaPile,
			this,
			& DecodageDeCommandesPilum ::
				ModeArretSurAppelOuRetourAvecAffichageDeLaPile ));

	EnregistrerLAssociation (sAssocDecodageDeCommandesPilum);

	EnregistrerLAssociation (
		new AssocDecodageDeCommandesPilum (
			& CommandesPilum :: CommandeInterrompre,
			this,
			& DecodageDeCommandesPilum :: Interrompre ));

	}	// DecodageDeCommandesPilum :: Initialiser


// -------------------------------------------------------------------------

void
DecodageDeCommandesPilum :: EnregistrerLAssociation (
	BaseAssocInstanceMethodeCommandesPilumPTR leFunctor )
	{
	CommandeInteractiveCommandesPilumPFM
				leCommandeInteractiveCommandesPilumPFMAEnregistrer =
					leFunctor -> LeCommandeInteractiveCommandesPilumPFM ();
	
	Chaine	nomCourtAEnregistrer =
					(fCommandesPilum ->* 
						leCommandeInteractiveCommandesPilumPFMAEnregistrer) () ->
							NomCourt ();
	Chaine	nomLongAEnregistrer	=
					(fCommandesPilum ->* 
						leCommandeInteractiveCommandesPilumPFMAEnregistrer) () ->
							NomLong ();

	if (
		! nomCourtAEnregistrer.empty ()
			||
		! nomLongAEnregistrer.empty ()
		)
		{
		TableauDeBaseAssocInstanceMethodeCommandesPilum :: iterator
					i;
		
		for (
			i = fTableauDeBaseAssocInstanceMethodeCommandesPilum -> begin ();
			i != fTableauDeBaseAssocInstanceMethodeCommandesPilum -> end ();
			++ i )
			{
			CommandeInteractiveCommandesPilumPFM
						leCommandeInteractiveCommandesPilumPFMTrouve =
							(* i) -> LeCommandeInteractiveCommandesPilumPFM ();
			
			Chaine	nomCourtTrouve =
							(fCommandesPilum ->* 
								leCommandeInteractiveCommandesPilumPFMTrouve) () ->
									NomCourt ();
			Chaine	nomLongTrouve	=
							(fCommandesPilum ->* 
								leCommandeInteractiveCommandesPilumPFMTrouve) () ->
									NomLong ();

			if (
				nomCourtAEnregistrer == nomCourtTrouve
					||
				nomLongAEnregistrer == nomLongTrouve
				)
				{
				std::cout <<
					Usage () <<
					std::endl;
				SortieSurErreur (
					MiseEnForme (
						fCommandesPilum ->
							FormatCommandeCourteDejaEnregistree (),
						nomCourtAEnregistrer ),
						17 );
				}

			if (
				nomLongAEnregistrer == nomCourtTrouve
					||
				nomLongAEnregistrer == nomLongTrouve
				)
				{
				std::cout <<
					Usage () <<
					std::endl;
				SortieSurErreur (
					MiseEnForme (
						fCommandesPilum ->
							FormatCommandeLongueDejaEnregistree (),
						nomLongAEnregistrer ),
						17 );
				}
			}	// for
		}	// if

	fTableauDeBaseAssocInstanceMethodeCommandesPilum -> 
		push_back (leFunctor);
	}	// DecodageDeCommandesPilum :: EnregistrerLAssociation


// -------------------------------------------------------------------------

Chaine
DecodageDeCommandesPilum :: DecodageDeCommandesPilum :: Usage ()
	{
	Chaine	res = "";

	TableauDeBaseAssocInstanceMethodeCommandesPilum :: iterator
				i;
	
	for (
		i = fTableauDeBaseAssocInstanceMethodeCommandesPilum -> begin ();
		i != fTableauDeBaseAssocInstanceMethodeCommandesPilum -> end ();
		++ i )
		{
		Chaine	descrArgument;

		CommandeInteractiveCommandesPilumPFM
					leCommandeInteractiveCommandesPilumPFM =
						(* i) -> LeCommandeInteractiveCommandesPilumPFM ();

		if (leCommandeInteractiveCommandesPilumPFM == NULL)
			SortieSurErreur (
				"DecodageDeCommandesPilum :: Usage (): "
				"leCommandeInteractiveCommandesPilumPFM == NULL",
				77 );
			
		switch (
			(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) () -> 
				LeGenreDArgumentEventuel ()
			)
			{
			case kAucun:
				 descrArgument= "";

			case kObligatoire:
				descrArgument =
					(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) () ->
						DescrArgumentEventuel ();
				break;

			case kOptionnel:
				descrArgument =
					MiseEnForme (
						"[%s]",
						(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) () -> 
							DescrArgumentEventuel ());
				break;
			}	// switch

		if ((* i) == sAssocDecodageDeCommandesPilum)
			res = FConcatChaines (res, "\n");
		else if (
			(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) ()
				-> NomCourt ().empty ()
				&&
			(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) ()
				-> NomLong () .empty ()
			)
			// les arguments de l'executabble
			{
			res =
				FConcatChaines (
					res,
					MiseEnForme (
						"\t%s\n\t\t%s\n",
						descrArgument,
						(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) () ->
							Commentaire ()
						));
			}
		else
			{
			res =
				FConcatChaines (
					res,
					MiseEnForme (
						"\t%s, %s %s\n\t\t%s\n",
						(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) () ->
							NomCourt (),
						(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) ()
							-> NomLong (),
						descrArgument,
						(fCommandesPilum ->* leCommandeInteractiveCommandesPilumPFM) ()
							-> Commentaire ()
						));
			}

//		std::cout << "==> res  = " << res << std::endl << std::flush;
		}	// for

	return res;
	}	// DecodageDeCommandesPilum :: Usage


// -------------------------------------------------------------------------



// -------------------------------------------------------------------------


void
DecodageDeCommandesPilum :: Interrompre (Chaine argument)
	{
	fMachinePilum -> Interrompre ();
	LInteractionDoitSePoursuivre (false);
	}


void
DecodageDeCommandesPilum :: AfficherLaMemoireDuCode (Chaine argument)
	{
	fMachinePilum -> AfficherLaMemoireDuCode ();
	LInteractionDoitSePoursuivre (true);
	}

void
DecodageDeCommandesPilum :: AfficherLaTableDesChaines (Chaine argument)
	{
	fMachinePilum -> AfficherLaTableDesChaines ();
	LInteractionDoitSePoursuivre (true);
	}

void
DecodageDeCommandesPilum :: AfficherLaPile (Chaine argument)
	{
	fMachinePilum -> AfficherLaPile ();
	LInteractionDoitSePoursuivre (true);
	}


void
DecodageDeCommandesPilum :: AfficherLEtatInterne (Chaine argument)
	{
	fMachinePilum -> AfficherLEtatInterne ();
	LInteractionDoitSePoursuivre (true);
	}


void
DecodageDeCommandesPilum :: ModePasAPas (Chaine argument)
	{
	fMachinePilum -> ModePasAPas ();
	LInteractionDoitSePoursuivre (false);
	}

void
DecodageDeCommandesPilum :: ModeContinu (Chaine argument)
	{
	fMachinePilum -> ModeContinu ();
	LInteractionDoitSePoursuivre (false);
	}

void
DecodageDeCommandesPilum :: ModeArretSurAppelOuRetour (Chaine argument)
	{
	fMachinePilum -> ModeArretSurAppelOuRetour ();
	LInteractionDoitSePoursuivre (false);
	}

void
DecodageDeCommandesPilum :: ModePasAPasAvecAffichageDeLaPile (
	Chaine argument )
	{
	fMachinePilum -> ModePasAPasAvecAffichageDeLaPile ();
	LInteractionDoitSePoursuivre (false);
	}
void
DecodageDeCommandesPilum :: ModeArretSurAppelOuRetourAvecAffichageDeLaPile (
	Chaine argument )
	{
	fMachinePilum -> ModeArretSurAppelOuRetourAvecAffichageDeLaPile ();
	LInteractionDoitSePoursuivre (false);
	}


