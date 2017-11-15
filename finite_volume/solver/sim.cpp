/* This file contains the main method and runs the simulation */
#include "../include/init.h"
#include "../include/ignore.h"
#include "../include/printmatrix.h"
#include "../include/momentum.h"
#include "../include/boundary.h"
#include "../include/pressure.h"
#include "../include/writetocsv.h"
#include <iostream>

//#include "../include/gnuplot-iostream.h"

int main()
{
	Initialization init;
	Ignore object;
	Momentum velocitystep;
	PrintMatrix printm; // DEBUG
	Boundary boundary;
	Pressure pressurestep;

	//circle parameters
	double radius = 1.0;
	double xcenter = 8.0;
	double ycenter = 3.0;
	//populate ignore vector

	for(unsigned int x = 0; x < (init.getU()).size(); x++)
	{
		for(unsigned int y = 0; y < (init.getV())[x].size(); y++)
		{
			object.circle(radius, xcenter, ycenter, x, y, init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());
		}
	}	


	for(int i = 0; i < 100; i++)
	{
//	std::cout << "Pressure before : " << std::endl;
//	printm.print(init.getP());	

//	std::cout << "Coefficients : " << std::endl;
//	printm.print(init.getCoeff());	

				boundary.boundary(init.getUTop(), init.getUBottom(), init.getVLeft(), init.getVRight(), init.getU(), init.getV());	
		velocitystep.velocity_intermediate(init.getH(), init.getMu(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges()); 

/*
		std::cout << "Ut Velocity : " << std::endl;
	printm.print(init.getUt());	
		std::cout << "Vt Velocity : " << std::endl;
	printm.print(init.getVt());	
*/

		pressurestep.pressure_calc(init.getBeta(), init.getH(), init.getDt(), init.getMaxIt(), init.getP(), init.getUt(), init.getVt(), init.getCoeff(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());
		velocitystep.velocity_correction(init.getH(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getP(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());

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


