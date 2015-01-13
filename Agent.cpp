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
#include <stdlib.h>  
#include <time.h> 
#define dt 1 



//############################################################################
//                                                                           #
//                           Class Template_class                            #
//                                                                           #
//############################################################################

// ===========================================================================
//                         Definition of static attributes
// ===========================================================================
int Agent::RADIUS = 400;

// ===========================================================================
//                                  Constructors
// ===========================================================================
Agent::Agent(void)
{
	xi = new double[2];
	xi[0] = rand()%641;
	xi[1] = rand()%481;

	vi = new double[2];
	vi[0] = rand()%641;
	vi[1] = rand()%481;
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
}

// Methods
void Agent::updatepos(void)
{
	int a;
	if((xi[0] + dt*vi[0]) <= 640 && (xi[0] + dt*vi[0]) >= 0)
	{
		xi[0] = xi[0] + dt*vi[0];
	}
	else if((xi[0] + dt*vi[0]) > 640)
	{
		a = xi[0] + dt*vi[0] - 640;
		xi[0] = 640;
		this->updateXneg(a);
	}
	else
	{
		xi[0] = 0;
		this->updateXpos(-(xi[0] + dt*vi[0]));
	}
	if((xi[1]+dt*vi[1]) <= 480 && (xi[1]+dt*vi[1])>=0)
	{
		xi[1] = xi[1] + dt*vi[1];
	}
	else if((xi[1] + dt*vi[1]) > 480)
	{
		a = xi[1] + dt*vi[1] - 480;
		xi[1] = 480;
		this->updateYneg(a);
	}
	else
	{
		xi[1] = 0;
		this->updateYpos(-(xi[1] + dt*vi[1]));
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


// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
