//****************************************************************************
//
//
//
//****************************************************************************



#ifndef __AGENT_H__
#define __AGENT_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================
#include "Obstacle.h"


// ===========================================================================
//                              Class declarations
// ===========================================================================






class Agent
{
  public :
    
    // =======================================================================
    //                                 Enums
    // =======================================================================
    
    // =======================================================================
    //                               Constructors
    // =======================================================================
    Agent(void);
    Agent(const Agent &model);

    // =======================================================================
    //                                Destructor
    // =======================================================================
    virtual ~Agent(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
    double* GetXi(void) const;
    double* GetVi(void) const;
    int GetR(void) const;

    // =======================================================================
    //                            Accessors: setters
    // =======================================================================
    void SetVi(double* vitesse);
    // =======================================================================
    //                                Operators
    // =======================================================================

    // =======================================================================
    //                              Public Methods
    // =======================================================================
    void updatepos(int pos, int length, int length_obs, Agent* pop, Obstacle* obs);
    void updateXneg(int a);
    void updateYneg(int a);
    void updateXpos(int a);
    void updateYpos(int a);
    bool perception(const Agent& anAgent);
    double* speed1(int pos, int length_pop, Agent* pop);
    double* speed2(int pos, int length_pop, Agent* pop);
    double* speed3(int pos, int length_pop, int length_obs, Agent* pop, Obstacle* obs);
    void speed(int pos, int length_pop, int length_obs, Agent* pop, Obstacle* obs);
    // =======================================================================
    //                             Public Attributes
    // =======================================================================





  protected :

    // =======================================================================
    //                            Forbidden Constructors
    // =======================================================================
    /*Agent(void)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/
    /*Agent(const Agent &model)
    {
      printf("%s:%d: error: call to forbidden constructor.\n", __FILE__, __LINE__);
      exit(EXIT_FAILURE);
    };*/


    // =======================================================================
    //                              Protected Methods
    // =======================================================================

    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
double* xi; // position of the agent
double* vi; // speed of the agent
};


// ===========================================================================
//                              Getters' definitions
// ===========================================================================

// ===========================================================================
//                              Setters' definitions
// ===========================================================================

// ===========================================================================
//                             Operators' definitions
// ===========================================================================

// ===========================================================================
//                          Inline functions' definition
// ===========================================================================


#endif // __AGENT_H__

