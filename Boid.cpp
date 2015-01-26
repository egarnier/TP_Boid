//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <math.h>


// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Boid.h"
#include "params.h"


//############################################################################
//                                                                           #
//                           Class Template_class                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================

// ===========================================================================
//                                  Constructors
// ===========================================================================
Boid::Boid(void)
{
	N = nb;
	pop = new Agent[N];
	No = nbo;
	obs = new Obstacle[No];
	Np = nbp;
	pred = new Predateur[Np];
}


Boid::Boid(const Boid &model)
{
	N = model.GetN();
	pop = new Agent[N];
	for(int i=0 ; i<N ; i++)
	{
		pop[i] = Agent(model.GetAgent(i));
	}
	No = model.GetNo();
	obs = new Obstacle[No];
	for(int j=0 ; j < No ; j++)
	{
		obs[j] = Obstacle(model.GetObstacle(j));
	}
	Np = model.GetNp();
	pred = new Predateur[Np];
	for(int k=0 ; k < Np ; k++)
	{
		pred[k] = Predateur(model.GetPredateur(k));
	}
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Boid::~Boid(void)
{
	delete[] pop;
	pop = NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
// Getters
int Boid::GetN (void) const
{
	return N;
}

int Boid::GetNo(void) const
{
	return No;
}

int Boid::GetNp(void) const
{
	return Np;
}

Agent Boid::GetAgent(int pos) const
{
	if(pos>N)
	{
		printf("La valeur entrée dépasse le nombre d'agents possible.\n");
	}
	return pop[pos];
}


Obstacle Boid::GetObstacle(int pos) const
{
	if(pos>No)
	{
		printf("La valeur entrée dépasse le nombre d'obstacle possible.\n");
	}
	return obs[pos];
}

Predateur Boid::GetPredateur(int pos) const
{
	if(pos>Np)
	{
		printf("La valeur entrée dépasse le nombre de prédateurs possible.\n");
	}
	return pred[pos];
}


Agent* Boid::GetPop(void) const
{
	return pop;
}



// Methods
void Boid::updateposBoid(void)
{
	double* vitesseX_pred = new double[Np];
	double* vitesseY_pred = new double[Np];

	for(int j = 0 ; j < Np ; j++)
	{
		pred[j].speedpred(N, pop);
		vitesseX_pred[j] = pred[j].GetVi()[0];
		vitesseY_pred[j] = pred[j].GetVi()[1];
	}

	for(int i=0;i<N;i++)
	{
		pop[i].updatepos(i, N, No, Np, pop, obs, vitesseX_pred, vitesseY_pred);
	}
	
delete[] vitesseX_pred;
vitesseX_pred = NULL;
delete[] vitesseY_pred;
vitesseY_pred = NULL;
}

void Boid::affiche(void)
{
	for(int i=0;i<N;i++)
	{
		printf("La position de l'agent %d est %f ; %f \n",i,pop[i].GetXi()[0],pop[i].GetXi()[1]);
		printf("La  vitesse de l'agent %d est %f ; %f \n",i,pop[i].GetVi()[0],pop[i].GetVi()[1]);
	}
}
// ===========================================================================
//                                Protected Methods
// ==========================================Adedd=================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
