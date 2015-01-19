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
void Agent::updatepos(int pos, int length, Agent* pop)
{
	speed(pos, length, pop);
	double posx = xi[0] + dt*vi[0];
	double posy = xi[1]+dt*vi[1];
	int a;

	if( posx < 640 && posx > 0)
	{
		xi[0] = posx;
	}
	else if(posx >= 640)
	{
		a = posx - 640;
		xi[0] = 640;
		updateXneg(a);
	}
	else
	{
		a = -posx;
		xi[0] = a;
		updateXpos(a);
	}

	if(posy < 480 && posy>0)
	{
		xi[1] = posy;
	}
	else if(posy >= 480)
	{
		a = posy - 480;
		xi[1] = 480;
		updateYneg(a);
	}
	else
	{
		a = -posy;
		xi[1] = a;
		updateYpos(a);
	}
}

void Agent::updateXneg(int a)
{
	xi[0] = 640-a;
	vi[0] = -vi[0];
}

void Agent::updateYneg(int a)
{
	xi[1] = 480-a;
	vi[1] = -vi[1];
}

void Agent::updateXpos(int a)
{
	xi[0] = a;
	vi[0] = -vi[0];
}

void Agent::updateYpos(int a)
{
	xi[1] = a;
	vi[1] = -vi[1];
}

bool Agent::perception(const Agent& anAgent)
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

double* Agent::speed1(int pos, int length, Agent* pop)
{
int K = 0;
bool val;
double* vim = new double[2];

vim[0] = 0;
vim[1] = 0;

for(int i = 0; i<length; i++)
{
	val = perception(pop[i]);

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


double* Agent::speed2(int pos, int length, Agent* pop)
{
int K = 0;
bool val;

double* vim = new double[2];
vim[0] = 0;
vim[1] = 0;

for(int i = 0; i<length; i++)
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
}
return vim;
}


double* Agent::speed3(int pos, int length, Agent* pop)
{
int K = 0;
int dis = 0;
bool val;
double* vim = new double[2];
vim[0] = 0;
vim[1] = 0;

for(int i = 0; i<length; i++)
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
}
return vim;
}

void Agent::speed(int pos, int length, Agent* pop)
{
	//printf("Je suis dans le speed final\n");
	double* v1 = speed1(pos, length, pop);
	double* v2 = speed2(pos, length, pop);
	double* v3 = speed3(pos, length, pop);
	//printf("%f %f\n", v1[0], v1[1]);
	//printf("%f %f\n", v2[0], v2[1]);
	//printf("%f %f\n", v3[0], v3[1]);
	printf("%f %f \n",vi[0],vi[1] );
	vi[0] = vi[0] + dt*(gamma1*v1[0] + gamma2*v2[0] + gamma3*v3[0]);
	vi[1] = vi[1] + dt*(gamma1*v1[1] + gamma2*v2[1] + gamma3*v3[1]);
	//	printf("%f %f \n",vi[0],vi[1] );
	delete [] v1;
	v1 = NULL;
	delete [] v2;
	v2 = NULL;
	delete [] v3;
	v3 = NULL;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
