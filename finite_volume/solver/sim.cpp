/* This file contains the main method and runs the simulation */

//#include "../include/init.h"
#include "../include/momentum.h"
#include <iostream>


int main()
{
Initialization init;
Momentum veltemp;

init.fill_coeff_matrix();

veltemp.velocity_calc(init.getH(), init.getMu(), init.getDt(), init.uptr, init.vptr, init.utptr, init.vtptr );

}
