#include "../include/pressure.h"

void Pressure::pressure_calc(double beta, double height, double dt, double maxit, std::vector<std::vector<double>> & p, std::vector<std::vector<double>> & ut, std::vector<std::vector<double>> & vt, std::vector<std::vector<double>> & coeff) 
{
	for(int it = 0; it < maxit; it++)
	{
		for(unsigned int x = 1; x < ut.size()-1; x++)
		{
			for(unsigned int y = 1; y < ut[x].size()-1; y++)
			{
				double psum = beta*coeff[x][y]*(p[x+1][y]+p[x-1][y]+p[x][y+1]+p[x+1][y]); 
				double vsum = (height/dt)*(ut[x][y]-ut[x-1][y]+vt[x][y]+vt[x][y-1]); 
				double relaxation = (1-beta)*p[x][y];
				p[x][y] = psum - vsum + relaxation;		
			}
		
		}
	}
}

