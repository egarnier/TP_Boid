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
#include "Boid.h"




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
	pop = NULL;
	N = 0;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Boid::~Boid(void)
{
	delete pop;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
// Getters
int Boid::GetN (void)
{
	return N;
}

// Operator
const Agent& Boid::operator[] (int pos) const
{
	if(pos<N)
	{
		return pop[pos];
	}
	else
	{
		Agent* a = '\0';
		return a[0];
	}
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
