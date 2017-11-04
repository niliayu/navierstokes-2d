/* This file contains the main method and runs the simulation */
#include "../include/init.h"
#include "../include/printmatrix.h"
#include "../include/momentum.h"
#include "../include/boundary.h"
#include "../include/pressure.h"
#include <iostream>

//#include "../include/gnuplot-iostream.h"

int main()
{
	Initialization init;
	Momentum velocitystep;
	PrintMatrix printm; // DEBUG
	Boundary boundary;
	Pressure pressurestep;
	
	for(int i = 0; i < 10; i++)
	{
//	std::cout << "Pressure before : " << std::endl;
//	printm.print(init.getP());	

//	std::cout << "Coefficients : " << std::endl;
//	printm.print(init.getCoeff());	
	

		boundary.boundary(init.getUTop(), init.getUBottom(), init.getVLeft(), init.getVRight(), init.getU(), init.getV());	
		velocitystep.velocity_intermediate(init.getH(), init.getMu(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt()); 

		std::cout << "Ut Velocity : " << std::endl;
	printm.print(init.getUt());	
		std::cout << "Vt Velocity : " << std::endl;
	printm.print(init.getVt());	


		pressurestep.pressure_calc(init.getBeta(), init.getH(), init.getDt(), init.getMaxIt(), init.getP(), init.getUt(), init.getVt(), init.getCoeff());
		velocitystep.velocity_correction(init.getH(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getP());

/*
	std::cout << "Ut Velocity : " << std::endl;
	printm.print(init.getUt());	

	std::cout << "Vt Velocity : " << std::endl;
	printm.print(init.getVt());	
*/
	std::cout << "U Velocity : " << std::endl;
	printm.print(init.getU());	

	std::cout << "V Velocity : " << std::endl;
	printm.print(init.getV());	

	std::cout << "Pressure : " << std::endl;
	printm.print(init.getP());	

	}
}


