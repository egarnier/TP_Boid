//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================
#include <stdlib.h>  
#include <time.h> 
#include <math.h>

// ===========================================================================
//                                 Project Files
// ===========================================================================
#include "Agent.h"
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
Agent::Agent(void)
{
	xi = new double[2];
	xi[0] = rand()%641;
	xi[1] = rand()%481;

	vi = new double[2];
	vi[0] = rand()%10;
	vi[1] = rand()%10;
}

Agent::Agent(const Agent &model)
{
	xi = new double[2];
	xi[0] = model.GetXi()[0];
	xi[1] = model.GetXi()[1];

	vi = new double[2];
	vi[0] = model.GetVi()[0];
	vi[1] = model.GetVi()[1];
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
{
	delete xi;
	xi = NULL;
	delete vi;
	vi = NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
// Getters
double* Agent::GetXi(void) const
{
	return xi;
}
    
double* Agent::GetVi(void) const
{
	return vi;
}
    
int Agent::GetR(void) const
{
	return RADIUS;
}

// Setters
void Agent::SetVi(double* vitesse)
{
	vi[0] = vitesse[0];
	vi[1] = vitesse[1];
}

// Methods
void Agent::updatepos(int pos, int length_pop, int length_obs, int length_pred, Agent* pop, Obstacle* obs, Agent* pred)
{
	speed(pos, length_pop, length_obs, length_pred, pop, obs, pred);
	double posx = xi[0] + dt*vi[0];
	double posy = xi[1] + dt*vi[1];
	int a;

	int h = 20;
	int v = 20;

	xi[0] = xi[0] + dt*vi[0];
	xi[1] = xi[1] + dt*vi[1];

	if(posx < v)
	{
		vi[0] = vi[0] + 10;
	}
	if(posx > 640 - v)
	{
		vi[0] = vi[0] - 10;
	}
	if(posy < h)
	{
		vi[1] = vi[1] + 10;
	}
	if(posy > 480 - h)
	{
		vi[1] = vi[1] - 10;
	}
	maxspeed();
}

void Agent::maxspeed(void)
{
	double norm;
	norm = sqrt(vi[0]*vi[0] + vi[1]*vi[1]);
	if(norm > Vmax)
	{
		vi[0] = (vi[0]*Vmax)/norm;
		vi[1] = (vi[1]*Vmax)/norm;
	}
}

bool Agent::perceptionR(const Agent& anAgent)
{
	double dis;
	bool test;
	dis = sqrt((anAgent.GetXi()[0] - xi[0])*(anAgent.GetXi()[0] - xi[0]) + (anAgent.GetXi()[1] - xi[1])*(anAgent.GetXi()[1] - xi[1]));
	if(dis>RADIUS)
	{
		test = false;
	}
	else
	{
		test = true;
	}
	return test;
}

bool Agent::perceptionC(const Agent& anAgent)
{
	double dis;
	bool test;
	dis = sqrt((anAgent.GetXi()[0] - xi[0])*(anAgent.GetXi()[0] - xi[0]) + (anAgent.GetXi()[1] - xi[1])*(anAgent.GetXi()[1] - xi[1]));
	
	if(dis>c)
	{
		test = false;
	}
	else
	{
		test = true;
	}
	return test;
}

double* Agent::speed1(int pos, int length_pop, Agent* pop)
{
int K = 0;
bool val;
double* vim = new double[2];

vim[0] = 0;
vim[1] = 0;

for(int i = 0; i<length_pop; i++)
{
	val = perceptionR(pop[i]);

	if(val == true && i != pos)
	{
		K = K +1;
		vim[0] = vim[0] + pop[i].GetVi()[0] - vi[0];
		vim[1] = vim[1] + pop[i].GetVi()[1] - vi[1];
	}
	
}
if(K != 0)
{
	vim[0] = vim[0]/K;
	vim[1] = vim[1]/K;
}

return vim;
}


double* Agent::speed2(int pos, int length_pop, Agent* pop)
{
int K = 0;
bool val;

double* vim = new double[2];
vim[0] = 0;
vim[1] = 0;

for(int i = 0; i<length_pop; i++)
{
	val = pop[pos].perceptionR(pop[i]);

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
}
return vim;
}


double* Agent::speed3(int pos, int length_pop, int length_obs, Agent* pop, Obstacle* obs)
{
int K = 0;
int O = 0;
bool val;
double* vim = new double[2];
vim[0] = 0;
vim[1] = 0;
double* vo = new double[2];
vo[0] = 0;
vo[1] = 0;

for(int i = 0; i<length_pop; i++)
{
	val = pop[pos].perceptionC(pop[i]);
	
	if(i != pos && val == true)
	{
		K = K +1;
		vim[0] = vim[0] + pop[i].GetXi()[0] - pop[pos].GetXi()[0];
		vim[1] = vim[1] + pop[i].GetXi()[1] - pop[pos].GetXi()[1];
	}
	
}

for(int j = 0; j<length_obs; j++)
{
	O = O + 1;
	vo[0] = vo[0] +  obs[j].GetXo()[0] - pop[pos].GetXi()[0];
	vo[1] = vo[1] + obs[j].GetXo()[1] - pop[pos].GetXi()[1];
}

if(K != 0)
{
	vim[0] = - vim[0]/K;
	vim[1] = - vim[1]/K;
}
if(O != 0)
{
	vim[0] = vim[0] - vo[0]/O;
	vim[1] = vim[1] - vo[1]/O;
}

delete[] vo;
vo = NULL;

return vim;

}

double* Agent::speed4(int pos, int length_pred, Agent* pop, Agent* pred)
{
	double norm = 0;
	double* vim = new double[2];
	vim[0] = 0;
	vim[1] = 0;

	for(int i = 0; i<length_pred ; i++)
	{
		norm = sqrt( (pred[i].GetXi()[0] - xi[0]) * (pred[i].GetXi()[0] - xi[0]) - (pred[i].GetXi()[1] - xi[1]) * (pred[i].GetXi()[1] - xi[1]) );

		if(norm < RADIUS)
		{
			vim[0] = (pred[i].GetXi()[0] - xi[0])/norm;
			vim[1] = (pred[i].GetXi()[1] - xi[1])/norm;
		}
	}
return vim;
}



void Agent::speed(int pos, int length_pop, int length_obs, int length_pred, Agent* pop, Obstacle* obs, Agent* pred)
{
	double* v1 = speed1(pos, length_pop, pop);
	double* v2 = speed2(pos, length_pop, pop);
	double* v3 = speed3(pos, length_pop, length_obs, pop, obs);
	double* v4 = speed4(pos, length_pred, pop, pred);
	vi[0] = vi[0] + dt*(gamma1*v1[0] + gamma2*v2[0] + gamma3*v3[0] + gamma4*v4[0]);
	vi[1] = vi[1] + dt*(gamma1*v1[1] + gamma2*v2[1] + gamma3*v3[1] + gamma4*v4[1]);
	
	delete [] v1;
	v1 = NULL;
	delete [] v2;
	v2 = NULL;
	delete [] v3;
	v3 = NULL;
	delete[] v4;
	v4=NULL;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
