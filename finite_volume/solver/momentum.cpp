/* Implementation of momentum equations for solving intermediate velocity */

#include "../include/momentum.h"


/* Defer to boundary solver if at edge of control volume */

void Momentum::velocity_calc(double h, double mu, double dt, std::array<std::array<double, gridy + 1>, gridx> & u_matrix, std::array<std::array<double, gridy>, gridx+1> & v_matrix, std::array<std::array<double, gridy + 1>, gridx> & return_u, std::array<std::array<double, gridy>, gridx+1> & return_v)
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

		

		}	
	}	

}



