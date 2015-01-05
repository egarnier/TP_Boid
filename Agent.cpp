//****************************************************************************
//
//
//
//****************************************************************************


 
 
// ===========================================================================
//                                   Libraries
// ===========================================================================



// ===========================================================================
//                                 Project Files
// ===========================================================================
#include <math.h>
#include "Agent.h"
#define dt 1 



//############################################################################
//                                                                           #
//                           Class Template_class                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
int Agent::RADIUS = 20;

// ===========================================================================
//                                  Constructors
// ===========================================================================
Agent::Agent(void)
{
	xi = new double[2];
	xi[0] = 0;
	xi[1] = 0;

	vi = new double[2];
	vi[0] = 0;
	vi[1] = 0;
}

Agent::Agent(double xi1, double xi2)
{
	xi = new double[2];
	xi[0] = xi1;
	xi[1] = xi2;

	vi = new double[2];
	vi[0] = 0;
	vi[1] = 0;
}

Agent::Agent(double xi1, double xi2, double vi1, double vi2)
{
	xi = new double[2];
	xi[0] = xi1;
	xi[1] = xi2;

	vi = new double[2];
	vi[0] = vi1;
	vi[1] = vi2;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Agent::~Agent(void)
{
	delete xi;
	delete vi;
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
	printf("dans le setter %f\n",vi[0] );
}

// Methods
void Agent::updatepos(void)
{
	xi[0] = xi[0] + dt*vi[0];
	xi[1] = xi[1] + dt*vi[1];
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

void Agent::speed1(Agent* tabAgent, int length, int pos)
{
int K = 0;
bool val;
double* vim = new double[2];
vim[0] = vim[1] = 0;
for(int i = 0; i<length; i++)
{
	val = this->perception(tabAgent[i]);

	if(val == true && i != pos)
	{
		K = K +1;
		vim[0] = vim[0] + tabAgent[i].GetVi()[0] - vi[0];
		vim[1] = vim[1] + tabAgent[i].GetVi()[1] - vi[1];
	}
	
}
vim[0] = vim[0]/K;
vim[1] = vim[1]/K;

this->SetVi(vim);

delete vim;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
