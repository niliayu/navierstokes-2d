/* This file contains the main method and runs the simulation */
#include "../include/printmatrix.h"
#include "../include/momentum.h"
#include "../include/boundary.h"
#include "../include/pressure.h"
#include <iostream>

int main()
{
	Initialization init;
	Momentum velocitystep;
	PrintMatrix printm; // DEBUG
	Boundary boundary;
	Pressure pressurestep;
	
	for(int i = 0; i < 10; i++)
	{
		boundary.boundary(init.getUTop(), init.getUBottom(), init.getVLeft(), init.getVRight(), init.getU(), init.getV());	
		velocitystep.velocity_intermediate(init.getH(), init.getMu(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt()); 
		pressurestep.pressure_calc(init.getBeta(), init.getH(), init.getDt(), init.getP(), init.getUt(), init.getVt(), init.getCoeff());
		velocitystep.velocity_correction(init.getH(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getP());

	std::cout << "U Velocity : " << std::endl;
	printm.print(init.getU());	

	std::cout << "V Velocity : " << std::endl;
	printm.print(init.getV());	

	std::cout << "Pressure : " << std::endl;
	printm.print(init.getP());	
	}
}


