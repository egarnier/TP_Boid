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
#include "Predateur.h"
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
Predateur::Predateur(void)
{
	xi = new double[2];
	xi[0] = rand()%641;
	xi[1] = rand()%481;

	vi = new double[2];
	vi[0] = rand()%Vpmax;
	vi[1] = rand()%Vpmax;

	temps_stop = 0;
}

Predateur::Predateur(const Predateur &model)
{
	xi = new double[2];
	xi[0] = model.GetXi()[0];
	xi[1] = model.GetXi()[1];

	vi = new double[2];
	vi[0] = model.GetVi()[0];
	vi[1] = model.GetVi()[1];

	temps_stop = 0;
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Predateur::~Predateur(void)
{
	delete[] xi;
	xi = NULL;
	delete[] vi;
	vi=NULL;
}

// ===========================================================================
//                                 Public Methods
// ===========================================================================
void Predateur::speedpred(int length_pop, Agent* pop){

	double norm = Rp;
	int pos = 0;
	double dis = 0;

	double* proie = new double[2];
	proie[0] = 0;
	proie[1] = 0;

	double* dead_pos = new double[2];
	dead_pos[0] = 700;
	dead_pos[1] = 50;

	double* dead_vit = new double[2];
	dead_vit[0] = 0;
	dead_vit[1] = 0;



	if(temps_stop == 0)
	{
		
		for(int i=0; i<length_pop; i++)
		{
			dis = sqrt((pop[i].GetXi()[0] - xi[0])*(pop[i].GetXi()[0] - xi[0]) + (pop[i].GetXi()[1] - xi[1])*(pop[i].GetXi()[1] - xi[1]));

			if(dis < norm)
			{
				norm = dis;
				proie[0] = pop[i].GetXi()[0];
				proie[1] = pop[i].GetXi()[1];	
				pos = i;	
			}
		}

		if(norm < Rp)
		{
			vi[0] = proie[0] - xi[0];
			vi[1] = proie[1] - xi[1];
		}
		else
		{
			vi[0] = rand()%Vpmax;
			vi[1] = rand()%Vpmax; 
		}
	
		updatePred();

		if(fabs(xi[0] - proie[0]) < Reat && fabs(xi[1] - proie[1]) < Reat)
		{
			pop[pos].SetXi(dead_pos);
			pop[pos].SetVi(dead_vit);
			pop[pos].alive(0);
			temps_stop = 1;
		}
	}

	temps_stop = rest(temps_stop);

	delete[] proie;	
	proie = NULL;
	delete[] dead_vit;
	dead_vit = NULL;
	delete[] dead_pos;
	dead_pos = NULL;

}


int Predateur::rest(int stop)
{
	if(stop != 0 && stop != pause)
	{
		stop = stop + 1;
		vi[0] = 0;
		vi[1] = 0;
	}
	else
	{
		vi[0] = rand()%20;
		vi[1] = rand()%20;
		stop = 0;
	}

	return stop;
}


void Predateur::updatePred(void)
{
	double posx = xi[0] + dt*vi[0];
	double posy = xi[1] + dt*vi[1];		
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
	maxspeedPred();
}

void Predateur::maxspeedPred(void)
{
	double norm;
	norm = sqrt(vi[0]*vi[0] + vi[1]*vi[1]);

	if(norm > Vpmax)
	{
		vi[0] = (vi[0]*Vpmax)/norm;
		vi[1] = (vi[1]*Vpmax)/norm;
	}
}
// ===========================================================================
//                                Protected Methods
// ===========================================================================

// ===========================================================================
//                               Non inline accessors
// ===========================================================================
