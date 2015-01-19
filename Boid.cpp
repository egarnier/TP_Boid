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
}


Boid::Boid(const Boid &model)
{
	N = model.GetN();
	pop = new Agent[N];
	for(int i=0 ; i<N ; i++)
	{
		pop[i] = Agent(model.GetAgent(i));
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

Agent Boid::GetAgent(int pos) const
{
	if(pos>N)
	{
		printf("La valeur entrée dépasse le nombre d'agents possible.\n");
	}
	return pop[pos];
}

Agent* Boid::GetPop(void) const
{
	return pop;
}

int Boid::GetNo(void) const
{
	return No;
}

Obstacle Boid::GetObstacle(int pos) const
{
	if(pos>No)
	{
		printf("La valeur entrée dépasse le nombre d'obstacle possible.\n");
	}
	return obs[pos];
}


// Methods
void Boid::updateposBoid(void)
{
	for(int i=0;i<N;i++)
	{
		pop[i].updatepos(i, N, pop);
	}
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
