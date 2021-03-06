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
#include "Obstacle.h"




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
Obstacle::Obstacle(void)
{
	xo = new int[2];
	xo[0] = rand()%630;
	xo[1] = rand()%470;
	printf("%d %d \n",xo[0],xo[1]);
}

Obstacle::Obstacle(const Obstacle &model)
{
	xo = new int[2];
	xo[0] = model.GetXo()[0];
	xo[1] = model.GetXo()[1];
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Obstacle::~Obstacle(void)
{
	delete[] xo;
	xo=NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
int* Obstacle::GetXo(void) const
{
	return xo;
}

// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================