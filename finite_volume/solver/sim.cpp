#include "../include/sim.h"
#include "../include/momentum.h"
#include "../include/boundary.h"
#include "../include/pressure.h"
#include "../include/writetocsv.h"


void Simulation::drivenCavity(int timesteps)
{
	//initialize objects
	Initialization init(18,18);
	Momentum velocitystep;
	Boundary boundary;
	Pressure pressurestep;
	WriteToCSV writer;

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


void cylinderRe20(int timesteps)
{

}


void cylinderRe100(int timesteps)
{


}



