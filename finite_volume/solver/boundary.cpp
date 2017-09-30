#include "../include/boundary.h"

void Boundary::boundary(double nval, double sval, double eval, double wval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v)
{
	for(unsigned int x = 0; x < u.size(); x++)
	{
		north(nval, (u[x])[0]);
		south(sval, (u[x])[u[x].size()-2]);
	}

	for(unsigned int y = 0; y < v[0].size(); y++)
	{
		west(wval, (u[1])[y]);
	}
	for(unsigned int y = 0; y < v[v.size()-1].size(); y++)
	{
		east(eval, (v[v.size()-1])[y]);
	}	
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


