/* This file contains the main method and runs the simulation */

#include "../include/momentum.h"
#include <iostream>
//#include "../include/init.h"

int main()
{
	Initialization init;

	Momentum velocitystep;

	std::vector<std::vector<double>> test = init.getU();
	std::cout << "Presumably got U" << std::endl;
	velocitystep.velocity_calc(init.getH(), init.getMu(), init.getDt(), test, test, test, test); 
//	velocitystep.velocity_calc(init.getH(), init.getMu(), init.getDt(), init.getU(), init.getU(), init.getU(), init.getU()); 
	

}

