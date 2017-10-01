/* Implementation of momentum equations for solving intermediate velocity */

#include "../include/momentum.h"
#include <cmath>

void Momentum::velocity_intermediate(double h, double mu, double dt, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v, std::vector<std::vector<double>> & return_u, std::vector<std::vector<double>> & return_v)
{
	int xmax = u.size();
	// x direction velocity estimates
	for(int x = 1; x < xmax-1; x++)
	{
		int ymax = u[x].size();	
		for(int y = 1; y < ymax-1; y++)
		{
		return_u[x][y] = u[x][y] + dt*((-0.25/h)*(pow((u[x+1][y]+u[x][y]),2.0) 
					- pow((u[x-1][y]+u[x][y]),2.0) 
					+ ((u[x][y+1]+u[x][y])*(v[x+1][y]+v[x][y])) 
					- ((u[x][y]+u[x][y-1])*(v[x+1][y-1]+v[x][y-1]))) 
				+ (mu/pow(h,2.0))*(u[x+1][y]+u[x-1][y]+u[x][y+1]+u[x][y-1]
					-(4*u[x][y])));	

		return_v[x][y] = v[x][y] + dt*(-(0.25/h)*((u[x][y+1]+u[x][y])
					*(v[x+1][y]+v[x][y]) - (u[x-1][y+1]+u[x-1][y])
					*(v[x+1][y]+v[x][y]) + (pow((v[x][y+1]+v[x][y]),2.0)
					       	- pow((u[x][y-1]+u[x][y]),2.0))) 
				+ (mu/pow(h,2.0))*(v[x+1][y]+v[x-1][y]+v[x][y+1]+v[x][y-1]
					-(4*v[x][y]))); 

		}	
	}	
}



