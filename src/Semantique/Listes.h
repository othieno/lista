// =========================================================================
// Listes.h
// Jeremy OTHIENO
// =========================================================================

#ifndef __Listes__
#define __Listes__

#include "OperateursNAires.h"
#include "TableDesSymboles.h"
#include "ContexteDEvaluation.h"

// -------------------------------------------------------------------------
// Manipulation des listes
// -------------------------------------------------------------------------

class CarPredef : public FonctionPredefinie
{
public:
                                 CarPredef( ChaineLanguePredefinisPFM );

   virtual DescrSemantiquePTR    CreerGrapheDAppelALaFonction
                                 (
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments
                                 );
};

// -------------------------------------------------------------------------

class CdrPredef : public FonctionPredefinie
{
public:
                                 CdrPredef( ChaineLanguePredefinisPFM );

   virtual DescrSemantiquePTR    CreerGrapheDAppelALaFonction
                                 (
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments
                                 );
};

// -------------------------------------------------------------------------

class ConsPredef : public FonctionPredefinie
{
public:
                                 ConsPredef( ChaineLanguePredefinisPFM );

   virtual DescrSemantiquePTR    CreerGrapheDAppelALaFonction
                                 (
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments
                                 );
};

// -------------------------------------------------------------------------

class AppendPredef : public FonctionPredefinie
{
public:
                                 AppendPredef( ChaineLanguePredefinisPFM );

   virtual DescrSemantiquePTR    CreerGrapheDAppelALaFonction
                                 (
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments
                                 );
};

// -------------------------------------------------------------------------

class ConcatListesPredef : public FonctionPredefinie
{
public:
                                 ConcatListesPredef( ChaineLanguePredefinisPFM );

   virtual DescrSemantiquePTR    CreerGrapheDAppelALaFonction
                                 (
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments
                                 );
};

// -------------------------------------------------------------------------

class LongueurListePredef : public FonctionPredefinie
{
public:
                                 LongueurListePredef( ChaineLanguePredefinisPFM );

   virtual DescrSemantiquePTR    CreerGrapheDAppelALaFonction
                                 (
                                    GenreLectureAuClavier   leGenreLectureAuClavier,
                                    DescrSemantiquePTR*     leBlocDArguments
                                 );
};

// -------------------------------------------------------------------------
// Operateurs unaires
// -------------------------------------------------------------------------

class Car : public OperateurUnaire
{
public:
                              Car( Chaine, DescrSemantiquePTR, VariableLogiqueTypePTR );
   virtual ValeurLista        Evaluer( ContexteDEvaluationPTR );

#if defined SYNTHESE_PILUM
   virtual void               Synthetiser( ContexteDeSynthesePTR );
#endif /* SYNTHESE_PILUM */
};

// -------------------------------------------------------------------------

class Cdr : public OperateurUnaire
{
public:
                              Cdr( Chaine, DescrSemantiquePTR );
   virtual ValeurLista        Evaluer( ContexteDEvaluationPTR );

#if defined SYNTHESE_PILUM
   virtual void               Synthetiser( ContexteDeSynthesePTR );
#endif /* SYNTHESE_PILUM */
};

// -------------------------------------------------------------------------

class LongueurListe : public OperateurUnaire
{
public:
                              LongueurListe( Chaine, DescrSemantiquePTR );
   virtual ValeurLista        Evaluer( ContexteDEvaluationPTR );

#if defined SYNTHESE_PILUM
   virtual void               Synthetiser( ContexteDeSynthesePTR );
#endif /* SYNTHESE_PILUM */
};


// -------------------------------------------------------------------------
// Operateurs binaires
// -------------------------------------------------------------------------

class ConcatListes : public OperateurBinaire
{
public:
                              ConcatListes(  Chaine,
                                             DescrSemantiquePTR, DescrSemantiquePTR
                                          );
   virtual ValeurLista        Evaluer( ContexteDEvaluationPTR );

#if defined SYNTHESE_PILUM
   virtual void               Synthetiser( ContexteDeSynthesePTR );
#endif /* SYNTHESE_PILUM */
};

// -------------------------------------------------------------------------

class Cons : public OperateurBinaire
{
public:
                              Cons( Chaine,
                                    DescrSemantiquePTR, DescrSemantiquePTR
                                  );
   virtual ValeurLista        Evaluer( ContexteDEvaluationPTR );

#if defined SYNTHESE_PILUM
   virtual void               Synthetiser( ContexteDeSynthesePTR );
#endif /* SYNTHESE_PILUM */
};

// -------------------------------------------------------------------------

class Append : public OperateurBinaire
{
public:
                              Append(  Chaine,
                                       DescrSemantiquePTR, DescrSemantiquePTR
                                    );
   virtual ValeurLista        Evaluer( ContexteDEvaluationPTR );

#if defined SYNTHESE_PILUM
   virtual void               Synthetiser( ContexteDeSynthesePTR );
#endif /* SYNTHESE_PILUM */
};

#endif /* __Listes__ */
