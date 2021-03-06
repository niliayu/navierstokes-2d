#include "../include/sim.h"
#include "../include/momentum.h"
#include "../include/ignore.h"
#include "../include/printmatrix.h"
#include "../include/boundary.h"
#include "../include/pressure.h"
#include "../include/writetocsv.h"


void Simulation::drivenCavity(int timesteps)
{
	//initialize objects
	Initialization init(24,24, 1, 0, 0, 0);
	Momentum velocitystep;
	Boundary boundary;
	Pressure pressurestep;
	WriteToCSV writer;

	writer.deletefile("udata_DC");
	writer.deletefile("vdata_DC");
	writer.deletefile("pdata_DC");

	PrintMatrix printer;	

	//run simulation
	for(int i = 0; i < timesteps; i++)
	{
		boundary.boundary(init.getUTop(), init.getUBottom(), init.getVLeft(), init.getVRight(), init.getU(), init.getV());	

		velocitystep.velocity_intermediate(init.getH(), init.getMu(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges()); 

	pressurestep.pressure_calc(init.getBeta(), init.getH(), init.getDt(), init.getMaxIt(), init.getP(), init.getUt(), init.getVt(), init.getCoeff(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());
	
	velocitystep.velocity_correction(init.getH(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getP(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());
	
		//export data
		writer.write("udata_DC", init.getU());
		writer.write("vdata_DC", init.getV());
		writer.write("pdata_DC", init.getP());
	}
}


void Simulation::cylinderRe20(int timesteps)
{
	
	//initialize objects
	Initialization init(24,24, 0, 0, 0, 0);
	Momentum velocitystep;
	Boundary boundary;
	Pressure pressurestep;
	Ignore object;
	WriteToCSV writer;

	PrintMatrix printer;

	//delete previous versions of files
	writer.deletefile("udata_RE20");
	writer.deletefile("vdata_RE20");
	writer.deletefile("pdata_RE20");

	double radius = 3.0;
	double xcenter = 12.0;
	double ycenter = 12.0;
	//populate ignore vector

	for(unsigned int x = 0; x < (init.getU()).size(); x++)
	{
		for(unsigned int y = 0; y < (init.getV())[x].size(); y++)
		{
			object.circle(radius, xcenter, ycenter, x, y, init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());
		}
	}	


	double max = 0.3;
	//run simulation
	for(int i = 0; i < timesteps; i++)
	{
//		std::cout << "iteration#" << i << std::endl;
		
		boundary.boundary(init.getUTop(), init.getUBottom(), init.getU(), init.getV(), max);
		
//		std::cout << "boundary" << std::endl;
//		printer.print(init.getV());

		velocitystep.velocity_intermediate(init.getH(), init.getMu(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges()); 

//		std::cout << "projection" << std::endl;
//		printer.print(init.getV());

		pressurestep.pressure_calc(init.getBeta(), init.getH(), init.getDt(), init.getMaxIt(), init.getP(), init.getUt(), init.getVt(), init.getCoeff(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());

//		std::cout << "pressure" << std::endl;
//		printer.print(init.getV());
		
		velocitystep.velocity_correction(init.getH(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getP(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());
	
		//export data
		writer.write("udata_RE20", init.getU());
		writer.write("vdata_RE20", init.getV());
		writer.write("pdata_RE20", init.getP());
	}

}


void Simulation::cylinderRe100(int timesteps)
{

	//initialize objects
	Initialization init(24,24, 0, 0, 0, 0);
	Momentum velocitystep;
	Boundary boundary;
	Pressure pressurestep;
	Ignore object;
	WriteToCSV writer;

	PrintMatrix printer;

	//delete previous versions of files
	writer.deletefile("udata_RE100");
	writer.deletefile("vdata_RE100");
	writer.deletefile("pdata_RE100");

	double radius = 3.0;
	double xcenter = 12.0;
	double ycenter = 12.0;
	//populate ignore vector

	double max = 100;

	for(unsigned int x = 0; x < (init.getU()).size(); x++)
	{
		for(unsigned int y = 0; y < (init.getV())[x].size(); y++)
		{
			object.circle(radius, xcenter, ycenter, x, y, init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());
		}
	}	

	//run simulation
	for(int i = 0; i < timesteps; i++)
	{
//		std::cout << "iteration#" << i << std::endl;
		
		boundary.boundary(init.getUTop(), init.getUBottom(), init.getU(), init.getV(), max);
		
//		std::cout << "boundary" << std::endl;
//		printer.print(init.getV());

		velocitystep.velocity_intermediate(init.getH(), init.getMu(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges()); 

//		std::cout << "projection" << std::endl;
//		printer.print(init.getV());

		pressurestep.pressure_calc(init.getBeta(), init.getH(), init.getDt(), init.getMaxIt(), init.getP(), init.getUt(), init.getVt(), init.getCoeff(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());

//		std::cout << "pressure" << std::endl;
//		printer.print(init.getV());
		
		velocitystep.velocity_correction(init.getH(), init.getDt(), init.getU(), init.getV(), init.getUt(), init.getVt(), init.getP(), init.getXignore(), init.getYignore(), init.getXedges(), init.getYedges());
	
		//export data
		writer.write("udata_RE100", init.getU());
		writer.write("vdata_RE100", init.getV());
		writer.write("pdata_RE100", init.getP());
	}

}



