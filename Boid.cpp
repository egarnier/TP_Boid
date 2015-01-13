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
	printf("youhou je suis dans le constructor by default !\n");
}

Boid::Boid(Agent firstAgent)
{
	N = 1;
	pop = new Agent[N];
	pop[0] = firstAgent;
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
int Boid::getN(void) const
{
	return N;
}

Agent* Boid::getPop(void) const
{
	return pop;
}

const Agent& Boid::getAgent(int pos) const
{
	return pop[pos];
}

// Operator
const Agent& Boid::operator[] (int pos) const
{
	if(pos<N)
	{
		Agent agt;
		agt = pop[pos];
		return agt;
	}
	else
	{
		Agent* a = '\0';
		return a[0];
		delete a;
	}
}

// Methods
void Boid::AddAgent(Agent newAgent)
{
	if(pop == NULL)
	{
		//printf("youhou je suis dans le AddAgent() dans le cas ou pop est nul !\n");
		N = 1;
		pop = new Agent[1];
		pop[0] = newAgent;
		//printf("youhou je suis dans le AddAgent() dans le cas ou pop est nul !\n");
	}
	else
	{
		//printf("youhou je suis dans le AddAgent() dans le cas ou pop est non nul !\n");
		Agent* tmp = new Agent[N];
		for(int i = 0 ; i < N ; i++)
		{
			tmp[i] = pop[i];
			//printf("%d\n", tmp[i].getXi()[0]);
		}
		N = N + 1;
		pop = new Agent[N];
		for(int j = 0 ; j < N-1 ; j++)
		{
			pop[j] = tmp[j];
			//printf("%d\n", pop[j].getXi()[0]);
		}
		pop[N] = newAgent;
		//printf("%d\n", pop[N-1].getXi()[0]);
		//printf("youhou je suis dans le AddAgent() dans le cas ou pop est nul !\n");
		//printf("%d\n", pop[N-1].getXi()[0]);
		//printf("youhou je suis dans le AddAgent() dans le cas ou pop nonest nul !\n");
	}
}

// ===========================================================================
//                                Protected Methods
// ==========================================Adedd=================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
