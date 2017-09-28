/* This file contains the main method and runs the simulation */

//#include "../include/init.h"
#include "../include/momentum.h"
#include <iostream>


int main()
{
Initialization init;
Momentum veltemp;

init.fill_coeff_matrix();

std::cout << init.getH() << std::endl; 
std::cout << init.h << std::endl;

}
