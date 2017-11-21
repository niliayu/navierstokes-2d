#include "../include/boundary.h"
#include <cmath>
#include <iostream>

void Boundary::boundary(double nval, double sval, double eval, double wval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v)
{

	for(unsigned int x = 0; x < u.size(); x++)
	{
		(u[x])[0] = north(nval, (u[x])[1]);
		(u[x])[u[x].size()] = south(sval, (u[x])[u[x].size()-1]);
	}
	
	for(unsigned int y = 0; y < v.size(); y++)
	{
		(v[0])[y] = west(wval, (v[1])[y]);
		(v[v[y].size()])[y] = east(eval, (v[v[y].size()-1])[y]); 
	}
}

void Boundary::boundary(double nval, double sval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v)
{
	for(unsigned int x = 0; x < u.size(); x++)
	{
		(u[x])[0] = north(nval, (u[x])[0]);
		(u[x])[u[x].size()-2] = south(sval, (u[x])[u[x].size()-2]);
	}

/*	for(unsigned int y = 0; y < v[0].size(); y++)
	{
		(v[1])[y] = west(wval, (v[1])[y]);
	}
*/

	for(unsigned int y = 0; y < v[v.size()-1].size(); y++)
	{
		(v[v.size()-2])[y] = getEWparabolic(y, v[v.size()-2].size());
	}

}

double Boundary::getNSparabolic(double xpos, double xgrid){ return 0.0; }

double Boundary::getEWparabolic(double ypos, double ygrid)
		{
			double maxU = 0.3;
			double gridActual = 0.41;	

			double pos = (ypos/ygrid)*gridActual;

			return (4*maxU*pos*(gridActual - pos))/(pow(0.41,2));	
		}



double Boundary::north(double north, double cell_value)
{
	return 2*north-cell_value;
}

double Boundary::south(double south, double cell_value)
{
	return 2*south-cell_value;
}

double Boundary::east(double east, double cell_value)
{
	return 2*east-cell_value;
}

double Boundary::west(double west, double cell_value)
{
	return 2*west-cell_value;
}

