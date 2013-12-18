// =========================================================================
//	DecodageDOptions.h
//	J. Menu - http://cui.unige.ch/DI/cours/CompInterpretes
//
//	Version $Id$ du $Date$
// =========================================================================


#ifndef __DecodageDOptions__
#define __DecodageDOptions__


// -------------------------------------------------------------------------
//	Prédéclarations
// -------------------------------------------------------------------------

#include "PreDeclarationsLanguesEtDecodageDOptions.h"


// -------------------------------------------------------------------------
//	Autres inclusions
// -------------------------------------------------------------------------

#include "Types.h"

#include "SupportCPlusPlus.h"

#include "Langues.h"

#include <iostream>

#include <vector>


// -------------------------------------------------------------------------
//	GenreDArgumentEventuel
// -------------------------------------------------------------------------

enum GenreDArgumentEventuel
	{
	kAucun,				kOptionnel,		kObligatoire
	};


// -------------------------------------------------------------------------
//	OptionLigneDeCommande
// -------------------------------------------------------------------------

//	Description dee options des executables dans la ligne de commande

class		OptionLigneDeCommande;
typedef	OptionLigneDeCommande
										* OptionLigneDeCommandePTR;

class OptionLigneDeCommande
	{
public:
										OptionLigneDeCommande (
											Chaine						leNomCourt,
											Chaine						leNomLong,
											GenreDArgumentEventuel	leGenreDArgumentEventuel,
											Chaine						laDescrArgumentEventuel,
											Chaine						leCommentaire );

										OptionLigneDeCommande ();

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

	};	// OptionLigneDeCommande


// -------------------------------------------------------------------------
//	Options
// -------------------------------------------------------------------------

class		Options;
typedef	Options					* OptionsPTR;

typedef Chaine						(Options :: * ChaineOptionsPFM) ();

typedef OptionLigneDeCommandePTR
										(Options :: * OptionLigneDeCommandeOptionsPFM) ();


class Options
	{
public:
										Options ();

	virtual							~ Options ();


	//	Versions des executables
	// -------------------------------------------------------------------------

	virtual Chaine					VersionLexiqueP () = 0;
											// virtuelle pure
	virtual Chaine					VersionLexiqueF () = 0;
											// virtuelle pure

	virtual Chaine					VersionSyntaxePredictifDescenteRecursive () = 0;
											// virtuelle pure
	virtual Chaine					VersionSyntaxeFlexBison () = 0;
											// virtuelle pure

	virtual Chaine					VersionSemantiquePredictifDescenteRecursive () = 0;
											// virtuelle pure
	virtual Chaine					VersionSemantiqueFlexBison () = 0;
											// virtuelle pure

	virtual Chaine					VersionPredictifDescenteRecursive () = 0;
											// virtuelle pure
	virtual Chaine					VersionFlexBison () = 0;
											// virtuelle pure

	virtual Chaine					VersionPilum () = 0;
											// virtuelle pure

	virtual Chaine					VersionFonctionsImbriquees () = 0;
											// virtuelle pure


	//	Options des executables
	// -------------------------------------------------------------------------

	virtual OptionLigneDeCommandePTR
										OptionLigneDeCommandeVide () = 0;
											// virtuelle pure


	virtual OptionLigneDeCommandePTR
										OptionAide () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionVersion () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionLangue () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionModeVerbeux () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionModeDebug () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionMontrerLeCodeSource () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionMontrerLesTerminaux () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionSortirALaPremiereErreurLexicale () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionSortirALaPremiereErreurSyntaxique () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionSortirALaPremiereErreurSemantique () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionMontrerLesDictionnaires () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionMontrerLeDictionnaireDesPredefinis () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionMontrerLesGraphesSemantiques () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionMontrerLesAppelsImbriques () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionMontrerLInferenceDeType () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionMontrerLeCodePostfixe () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionLangueDestination () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionStrategieParValeur () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionStrategieParNom () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionStrategieParBesoin () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionCourtCircuitLogiquesBinaires () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionEvaluationDirecteSansTrace () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionEvaluationDirecteAvecTrace () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionModeDebugSynthese () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionCommenterLeCode () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionMarquerLesBlocsDActivation () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionOptimiserLesSauts () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionMontrerLeCodeParLeSynthetiseur () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionMontrerLeCodeParPilum () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionModeTracePilum () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionModeDebugPilum () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionTailleDeLaPile () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										OptionsGroupeesLexique () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionsGroupeesSyntaxe () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionsGroupeesSemantique () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionsGroupeesSemantique_SYNTHESE_PILUM () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionsGroupeesPilum () = 0;
											// virtuelle pure
	virtual OptionLigneDeCommandePTR
										OptionsGroupeesFonctionsImbriquees () = 0;
											// virtuelle pure


	//	Options
	// -------------------------------------------------------------------------

	virtual Chaine					FormatOptionInconnue () = 0;
											// virtuelle pure
	virtual Chaine					FormatOptionAUnArgumentObligatoire () = 0;
											// virtuelle pure

	virtual Chaine					FormatOptionCourteDejaEnregistree () = 0;
											// virtuelle pure
	virtual Chaine					FormatOptionLongueDejaEnregistree () = 0;
											// virtuelle pure


	//	Arguments des executables
	// -------------------------------------------------------------------------
										
	virtual OptionLigneDeCommandePTR
										ArgumentsCompilateurs () = 0;
											// virtuelle pure

	virtual OptionLigneDeCommandePTR
										ArgumentsPilum () = 0;
											// virtuelle pure
	};	//	Options


// -------------------------------------------------------------------------
//	OptionsFR
// -------------------------------------------------------------------------

class		OptionsFR;
typedef	OptionsFR				* OptionsFRPTR;

class OptionsFR : public Options
	{
public:
										OptionsFR ();


	//	Versions des executables
	// -------------------------------------------------------------------------

	Chaine							VersionLexiqueP ();
	Chaine							VersionLexiqueF ();

	Chaine							VersionSyntaxePredictifDescenteRecursive ();
	Chaine							VersionSyntaxeFlexBison ();

	Chaine							VersionSemantiquePredictifDescenteRecursive ();
	Chaine							VersionSemantiqueFlexBison ();

	Chaine							VersionPredictifDescenteRecursive ();
	Chaine							VersionFlexBison ();

	Chaine							VersionPilum ();

	Chaine							VersionFonctionsImbriquees ();


	//	Options des executables
	// -------------------------------------------------------------------------
										
	OptionLigneDeCommandePTR	OptionLigneDeCommandeVide ();

	OptionLigneDeCommandePTR	OptionAide ();
	OptionLigneDeCommandePTR	OptionVersion ();

	OptionLigneDeCommandePTR	OptionLangue ();

	OptionLigneDeCommandePTR	OptionModeVerbeux ();
	OptionLigneDeCommandePTR	OptionModeDebug ();

	OptionLigneDeCommandePTR	OptionMontrerLeCodeSource ();
	OptionLigneDeCommandePTR	OptionMontrerLesTerminaux ();

	OptionLigneDeCommandePTR	OptionSortirALaPremiereErreurLexicale ();
	OptionLigneDeCommandePTR	OptionSortirALaPremiereErreurSyntaxique ();
	OptionLigneDeCommandePTR	OptionSortirALaPremiereErreurSemantique ();

	OptionLigneDeCommandePTR	OptionMontrerLesDictionnaires ();
	OptionLigneDeCommandePTR	OptionMontrerLeDictionnaireDesPredefinis ();
	OptionLigneDeCommandePTR	OptionMontrerLesAppelsImbriques ();
	OptionLigneDeCommandePTR	OptionMontrerLInferenceDeType ();
	OptionLigneDeCommandePTR	OptionMontrerLesGraphesSemantiques ();
	OptionLigneDeCommandePTR	OptionMontrerLeCodePostfixe ();
	OptionLigneDeCommandePTR	OptionLangueDestination ();

	OptionLigneDeCommandePTR	OptionStrategieParValeur ();
	OptionLigneDeCommandePTR	OptionStrategieParNom ();
	OptionLigneDeCommandePTR	OptionStrategieParBesoin ();

	OptionLigneDeCommandePTR	OptionEvaluationDirecteSansTrace ();
	OptionLigneDeCommandePTR	OptionEvaluationDirecteAvecTrace ();

	OptionLigneDeCommandePTR	OptionCourtCircuitLogiquesBinaires ();

	OptionLigneDeCommandePTR	OptionModeDebugSynthese ();
	OptionLigneDeCommandePTR	OptionCommenterLeCode ();
	OptionLigneDeCommandePTR	OptionMarquerLesBlocsDActivation ();
	OptionLigneDeCommandePTR	OptionOptimiserLesSauts ();

	OptionLigneDeCommandePTR	OptionMontrerLeCodeParLeSynthetiseur ();
	OptionLigneDeCommandePTR	OptionMontrerLeCodeParPilum ();

	OptionLigneDeCommandePTR	OptionModeTracePilum ();
	OptionLigneDeCommandePTR	OptionModeDebugPilum ();
	OptionLigneDeCommandePTR	OptionTailleDeLaPile ();

	OptionLigneDeCommandePTR	OptionsGroupeesLexique ();
	OptionLigneDeCommandePTR	OptionsGroupeesSyntaxe ();
	OptionLigneDeCommandePTR	OptionsGroupeesSemantique ();
	OptionLigneDeCommandePTR	OptionsGroupeesSemantique_SYNTHESE_PILUM ();
	OptionLigneDeCommandePTR	OptionsGroupeesPilum ();
	OptionLigneDeCommandePTR	OptionsGroupeesFonctionsImbriquees ();


	//	Options
	// -------------------------------------------------------------------------

	Chaine							FormatOptionInconnue ();
	Chaine							FormatOptionAUnArgumentObligatoire ();

	Chaine							FormatOptionCourteDejaEnregistree ();
	Chaine							FormatOptionLongueDejaEnregistree ();


	//	Arguments des executables
	// -------------------------------------------------------------------------
										
	OptionLigneDeCommandePTR	ArgumentsCompilateurs ();

	OptionLigneDeCommandePTR	ArgumentsPilum ();

	};	//	OptionsFR


// -------------------------------------------------------------------------
//	OptionsEN
// -------------------------------------------------------------------------

class		OptionsEN;
typedef	OptionsEN				* OptionsENPTR;

class OptionsEN : public Options
	{
public:
										OptionsEN ();


	//	Versions des executables
	// -------------------------------------------------------------------------

	Chaine							VersionLexiqueP ();
	Chaine							VersionLexiqueF ();

	Chaine							VersionSyntaxePredictifDescenteRecursive ();
	Chaine							VersionSyntaxeFlexBison ();

	Chaine							VersionSemantiquePredictifDescenteRecursive ();
	Chaine							VersionSemantiqueFlexBison ();

	Chaine							VersionPredictifDescenteRecursive ();
	Chaine							VersionFlexBison ();

	Chaine							VersionPilum ();

	Chaine							VersionFonctionsImbriquees ();


	//	Options des executables
	// -------------------------------------------------------------------------
										
	OptionLigneDeCommandePTR	OptionLigneDeCommandeVide ();

	OptionLigneDeCommandePTR	OptionAide ();
	OptionLigneDeCommandePTR	OptionVersion ();

	OptionLigneDeCommandePTR	OptionLangue ();

	OptionLigneDeCommandePTR	OptionModeVerbeux ();
	OptionLigneDeCommandePTR	OptionModeDebug ();

	OptionLigneDeCommandePTR	OptionMontrerLeCodeSource ();
	OptionLigneDeCommandePTR	OptionMontrerLesTerminaux ();

	OptionLigneDeCommandePTR	OptionSortirALaPremiereErreurLexicale ();
	OptionLigneDeCommandePTR	OptionSortirALaPremiereErreurSyntaxique ();
	OptionLigneDeCommandePTR	OptionSortirALaPremiereErreurSemantique ();

	OptionLigneDeCommandePTR	OptionMontrerLesDictionnaires ();
	OptionLigneDeCommandePTR	OptionMontrerLeDictionnaireDesPredefinis ();
	OptionLigneDeCommandePTR	OptionMontrerLesAppelsImbriques ();
	OptionLigneDeCommandePTR	OptionMontrerLInferenceDeType ();
	OptionLigneDeCommandePTR	OptionMontrerLesGraphesSemantiques ();
	OptionLigneDeCommandePTR	OptionMontrerLeCodePostfixe ();
	OptionLigneDeCommandePTR	OptionLangueDestination ();

	OptionLigneDeCommandePTR	OptionStrategieParValeur ();
	OptionLigneDeCommandePTR	OptionStrategieParNom ();
	OptionLigneDeCommandePTR	OptionStrategieParBesoin ();

	OptionLigneDeCommandePTR	OptionEvaluationDirecteSansTrace ();
	OptionLigneDeCommandePTR	OptionEvaluationDirecteAvecTrace ();

	OptionLigneDeCommandePTR	OptionCourtCircuitLogiquesBinaires ();

	OptionLigneDeCommandePTR	OptionModeDebugSynthese ();
	OptionLigneDeCommandePTR	OptionCommenterLeCode ();
	OptionLigneDeCommandePTR	OptionMarquerLesBlocsDActivation ();
	OptionLigneDeCommandePTR	OptionOptimiserLesSauts ();

	OptionLigneDeCommandePTR	OptionMontrerLeCodeParLeSynthetiseur ();
	OptionLigneDeCommandePTR	OptionMontrerLeCodeParPilum ();

	OptionLigneDeCommandePTR	OptionModeTracePilum ();
	OptionLigneDeCommandePTR	OptionModeDebugPilum ();
	OptionLigneDeCommandePTR	OptionTailleDeLaPile ();

	OptionLigneDeCommandePTR	OptionsGroupeesLexique ();
	OptionLigneDeCommandePTR	OptionsGroupeesSyntaxe ();
	OptionLigneDeCommandePTR	OptionsGroupeesSemantique ();
	OptionLigneDeCommandePTR	OptionsGroupeesSemantique_SYNTHESE_PILUM ();
	OptionLigneDeCommandePTR	OptionsGroupeesPilum ();
	OptionLigneDeCommandePTR	OptionsGroupeesFonctionsImbriquees ();


	//	Options
	// -------------------------------------------------------------------------

	Chaine							FormatOptionInconnue ();
	Chaine							FormatOptionAUnArgumentObligatoire ();

	Chaine							FormatOptionCourteDejaEnregistree ();
	Chaine							FormatOptionLongueDejaEnregistree ();


	//	Arguments des executables
	// -------------------------------------------------------------------------
										
	OptionLigneDeCommandePTR	ArgumentsCompilateurs ();

	OptionLigneDeCommandePTR	ArgumentsPilum ();

	};	//	OptionsEN


// -------------------------------------------------------------------------
//	BaseAssocInstanceMethodeOptions
// -------------------------------------------------------------------------

/*
Classe abstraite dont les sous-classes associent:
	- une instance d'une classe
	- une de ses methodes
pour pouvoir ensuite faire executer la seconde par la premiere.

Cette technique est souvent appelee 'foncteur' (functor) dans la litterature
*/

class		BaseAssocInstanceMethodeOptions;
typedef	BaseAssocInstanceMethodeOptions
										* BaseAssocInstanceMethodeOptionsPTR;

class BaseAssocInstanceMethodeOptions
   {
public:

										BaseAssocInstanceMethodeOptions (
											OptionLigneDeCommandeOptionsPFM
														leOptionLigneDeCommandeOptionsPFM );

	virtual							~ BaseAssocInstanceMethodeOptions ();


	OptionLigneDeCommandeOptionsPFM
										LeOptionLigneDeCommandeOptionsPFM ();

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

	OptionLigneDeCommandeOptionsPFM
										fOptionLigneDeCommandeOptionsPFM;
   };	// BaseAssocInstanceMethodeOptions


typedef std::vector <BaseAssocInstanceMethodeOptionsPTR>
										TableauDeBaseAssocInstanceMethodeOptions;
typedef TableauDeBaseAssocInstanceMethodeOptions
										* TableauDeBaseAssocInstanceMethodeOptionsPTR;


// -------------------------------------------------------------------------
//	TemplateAssocInstanceMethodeOptions
// -------------------------------------------------------------------------

template <class TClass>
class TemplateAssocInstanceMethodeOptions: public BaseAssocInstanceMethodeOptions
   {
public:
										TemplateAssocInstanceMethodeOptions (
											OptionLigneDeCommandeOptionsPFM
														leOptionLigneDeCommandeOptionsPFM,
											TClass	* lInstance,
											void		(TClass :: * leFonctionMembrePTR) (Chaine) )
											:	BaseAssocInstanceMethodeOptions (
													leOptionLigneDeCommandeOptionsPFM )
											{
											fInstance = lInstance;
											fFonctionMembrePTR = leFonctionMembrePTR;
											};

	virtual void					Declencher (Chaine lArgumentDeLOption)
											{
											(fInstance ->* fFonctionMembrePTR)
												(lArgumentDeLOption);
											};

	virtual void					operator () (Chaine lArgumentDeLOption)
											{
											(fInstance ->* fFonctionMembrePTR)
												(lArgumentDeLOption);
											};


private:

	TClass							* fInstance;
	void								(TClass :: * fFonctionMembrePTR)	(Chaine);
	
   };	// TemplateAssocInstanceMethodeOptions


// -------------------------------------------------------------------------
//	DecodageDOptions
// -------------------------------------------------------------------------

class   DecodageDOptions;
typedef TemplateAssocInstanceMethodeOptions
										<DecodageDOptions>
											AssocDecodageDOptions;
typedef AssocDecodageDOptions
										* AssocDecodageDOptionsPTR;

class DecodageDOptions
	{
public:
										DecodageDOptions (
											int			leNbDArguments,
											CharPTR	lesArguments [],
											ChaineOptionsPFM
															laFonctionVersion );
										
	virtual							~ DecodageDOptions ();


	virtual void					Initialiser ();

	void								EnregistrerLAssociation (
											BaseAssocInstanceMethodeOptionsPTR
														leFunctor );

	Chaine							Usage ();

	int								DecortiquerLesOptions ();
											//	retourne le numero du premier argument
											//	suivant les options

	void								DecortiquerLOption (
											int	& leNumArgumentCourant,
											bool	& lArgumentNonOptionTrouve );


	void								OptionVide (Chaine argument);

	void								Version (Chaine argument);
	virtual void					Aide (Chaine argument);
	virtual void					Langue (Chaine argument);


protected:
	
	int								fNbDArguments;
	CharPTR *						fLesArguments;
	ChaineOptionsPFM				fFonctionVersion;

	TableauDeBaseAssocInstanceMethodeOptionsPTR
										fTableauDeBaseAssocInstanceMethodeOptions;

	static AssocDecodageDOptionsPTR
										sAssocDecodageDOptions;

	};	// DecodageDOptions


// -------------------------------------------------------------------------
//	GenreDOption
// -------------------------------------------------------------------------

enum GenreDOption
	{
	kPasUneOption,					kOptionCourte,				kOptionLongue
	};

GenreDOption						LeGenreDOption (Chaine laChaine);


// -------------------------------------------------------------------------
//	Variables globales
// -------------------------------------------------------------------------

extern OptionsPTR					gOPTIONS;

extern OptionsFR					gOPTIONS_FR;
extern OptionsEN					gOPTIONS_EN;


#endif /* __DecodageDOptions__ */

