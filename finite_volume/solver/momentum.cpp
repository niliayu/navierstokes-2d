/* Implementation of momentum equations for solving intermediate velocity */

#include "../include/momentum.h"
#include <cmath>

/* Defer to boundary solver if at edge of control volume */

void Momentum::velocity_calc(double h, double mu, double dt, std::array<std::array<double, gridy + 1>, gridx> & u, std::array<std::array<double, gridy>, gridx+1> & v, std::array<std::array<double, gridy + 1>, gridx> & return_u, std::array<std::array<double, gridy>, gridx+1> & return_v)
{

	// x direction velocity estimates
	for(int x = 0; x < gridx; x++)
	{
		for(int y = 0; y < gridy + 1; y++)
		{
		//if((y == 0) || (y == gridy))	
		/* TODO: add call to boundary calculation */ 
		//else if((x == 0) || (x == gridx))
		/* TODO */

		return_u[x][y] = u[x][y] + dt*((-0.25/h)*(pow((u[x+1][y]+u[x][y]),2.0) - pow((u[x-1][y]+u[x][y]),2.0) + ((u[x][y+1]+u[x][y])*(v[x+1][y]+v[x][y])) - ((u[x][y]+u[x][y-1])*(v[x+1][y-1]+v[x][y-1]))) + (mu/pow(h,2.0))*(u[x+1][y]+u[x-1][y]+u[x][y+1]+u[x][y-1]-(4*u[x][y])));	

		return_v[x][y] = v[x][y] + dt*(-(0.25/h)*((u[x][y+1]+u[x][y])*(v[x+1][y]+v[x][y]) - (u[x-1][y+1]+u[x-1][y])*(v[x+1][y]+v[x][y]) + (pow((v[x][y+1]+v[x][y]),2.0) - pow((u[x][y-1]+u[x][y]),2.0))) + (mu/pow(h,2.0))*(v[x+1][y]+v[x-1][y]+v[x][y+1]+v[x][y-1]-(4*v[x][y]))); 

		}	
	}	

}



