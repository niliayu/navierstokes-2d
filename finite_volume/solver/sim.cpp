/* This file contains the main method and runs the simulation */
#include "../include/printmatrix.h"
#include "../include/momentum.h"
#include "../include/boundary.h"
#include <iostream>

int main()
{
	Initialization init;
	Momentum velocitystep;
	PrintMatrix printm; // DEBUG
	Boundary boundary;


	std::cout << "Before : " << std::endl;
	printm.print(init.getU());	

	boundary.boundary(init.getUTop(), init.getUBottom(), init.getVLeft(), init.getVRight(), init.getU(), init.getV());	
	velocitystep.velocity_calc(init.getH(), init.getMu(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt()); 

	std::cout << "After : " << std::endl;
	printm.print(init.getU());	

}

