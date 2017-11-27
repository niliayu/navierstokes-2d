#include "../include/boundary.h"
#include <cmath>
#include <iostream>

void Boundary::boundary(double nval, double sval, double eval, double wval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v)
{

	for(unsigned int x = 0; x < u.size(); x++)
	{
		(u[x])[0] = reflect(nval, (u[x])[1]);
		(u[x])[u[x].size()] = reflect(sval, (u[x])[u[x].size()-1]);
	}
	
	for(unsigned int y = 0; y < v.size(); y++)
	{
		(v[0])[y] = reflect(wval, (v[1])[y]);
		(v[v[y].size()])[y] = reflect(eval, (v[v[y].size()-1])[y]); 
	}
}

void Boundary::boundary(double eval, double wval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v, double max)
{
	for(unsigned int x = 0; x < u.size(); x++)
	{
		(u[x])[0] = getNSparabolic(x, u.size(), max);
	       	(u[x])[u[x].size()] = (u[x])[u[x].size()-1];  

	}
	
	for(unsigned int y = 0; y < v.size(); y++)
	{
		(v[0])[y] = reflect(wval, (v[1])[y]);
		(v[v[y].size()])[y] = reflect(eval, (v[v[y].size()-1])[y]); 
	}
}

double Boundary::getNSparabolic(double xpos, double xgrid, double max)
{ 
		double maxU = 0.3;
		double gridActual = 0.41;	

		double pos = (xpos/xgrid)*gridActual;

		return (4*maxU*pos*(gridActual - pos))/(pow(0.41,2));	
}

double Boundary::getEWparabolic(double ypos, double ygrid, double max)
{
		double maxU = 0.3;
		double gridActual = 0.41;	

		double pos = (ypos/ygrid)*gridActual;

		return (4*maxU*pos*(gridActual - pos))/(pow(0.41,2));	
}



double Boundary::reflect(double val, double cell_value)
{
	return 2*val-cell_value;
}


