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
#include "Agent.h"
#define dt 0.5 



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
	xi = new int[2];
	xi[0] = 0;
	xi[1] = 0;

	vi = new double[2];
	vi[0] = 0;
	vi[1] = 0;
}

Agent::Agent(int xi1, int xi2)
{
	xi = new int[2];
	xi[0] = xi1;
	xi[1] = xi2;

	vi = new double[2];
	vi[0] = 0;
	vi[1] = 0;
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

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
