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
#define c 10
#define gamma1 0.1
#define gamma2 0.2
#define gamma3 0.1
#define dt 1

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
	N = 10;
	pop = new Agent[N];
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Boid::~Boid(void)
{
	delete[] pop;
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
		printf("La valeur entrée dépasse le Boid.\n");
	}
	return pop[pos];
}

Agent* Boid::GetPop(void) const
{
	return pop;
}




// Methods
void Boid::updatepos(void)
{
	for(int i=0;i<N;i++)
	{
		pop[i].updatepos();
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

double* Boid::speed1(int pos)
{
int K = 0;
bool val;

double* vim = new double[2];
vim[0] = 0;
vim[1] = 0;

for(int i = 0; i<N; i++)
{
	val = pop[pos].perception(pop[i]);

	if(val == true && i != pos)
	{
		K = K +1;
		vim[0] = vim[0] + pop[i].GetVi()[0] - pop[pos].GetVi()[0];
		vim[1] = vim[1] + pop[i].GetVi()[1] - pop[pos].GetVi()[1];
	}
	
}
if(K != 0)
{
	vim[0] = vim[0]/K;
	vim[1] = vim[1]/K;
	pop[pos].SetVi(vim);
}

return vim;

delete vim;
}


double* Boid::speed2(int pos)
{
int K = 0;
bool val;

double* vim = new double[2];
vim[0] = 0;
vim[1] = 0;

for(int i = 0; i<N; i++)
{
	val = pop[pos].perception(pop[i]);

	if(val == true && i != pos)
	{
		K = K +1;
		vim[0] = vim[0] + pop[i].GetXi()[0] - pop[pos].GetXi()[0];
		vim[1] = vim[1] + pop[i].GetXi()[1] - pop[pos].GetXi()[1];
	}
	
}
if(K != 0)
{
	vim[0] = vim[0]/K;
	vim[1] = vim[1]/K;
	pop[pos].SetVi(vim);
}
return vim;

delete vim;
}

double* Boid::speed3(int pos)
{
int K = 0;
int dis = 0;
bool val;
double* vim = new double[2];
vim[0] = 0;
vim[1] = 0;

for(int i = 0; i<N; i++)
{
	val = pop[pos].perception(pop[i]);
	dis = sqrt((pop[i].GetXi()[0] - pop[pos].GetXi()[0])*(pop[i].GetXi()[0] - pop[pos].GetXi()[0]) + (pop[i].GetXi()[1] - pop[pos].GetXi()[1])*(pop[i].GetXi()[1] - pop[pos].GetXi()[1]));

	if(val == true && i != pos && dis<c)
	{
		K = K +1;
		vim[0] = vim[0] + pop[i].GetXi()[0] - pop[pos].GetXi()[0];
		vim[1] = vim[1] + pop[i].GetXi()[1] - pop[pos].GetXi()[1];
	}
	
}
if(K != 0)
{
	vim[0] = -vim[0]/K;
	vim[1] = -vim[1]/K;
	pop[pos].SetVi(vim);
}
return vim;

delete vim;
}

void Boid::speed(int pos)
{
	double* v1 = this->speed1(pos);
	double* v2 = this->speed2(pos);
	double* v3 = this->speed3(pos);
	pop[pos].GetVi()[0] = pop[pos].GetVi()[0] + dt*(gamma1*v1[0] + gamma2*v2[0] + gamma3*v3[0]);
	pop[pos].GetVi()[1] = pop[pos].GetVi()[1] + dt*(gamma1*v1[1] + gamma2*v2[1] + gamma3*v3[1]);
	this->updatepos();
}
// ===========================================================================
//                                Protected Methods
// ==========================================Adedd=================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
