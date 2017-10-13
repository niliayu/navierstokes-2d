#include "../include/boundary.h"
#include <iostream>

void Boundary::boundary(double nval, double sval, double eval, double wval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v)
{
	for(unsigned int x = 0; x < u.size(); x++)
	{
		(u[x])[0] = north(nval, (u[x])[0]);
		(u[x])[u[x].size()-2] = south(sval, (u[x])[u[x].size()-2]);
	}

	for(unsigned int y = 0; y < v[0].size(); y++)
	{
		(u[1])[y] = west(wval, (u[1])[y]);
	}
	for(unsigned int y = 0; y < v[v.size()-1].size(); y++)
	{
		(v[v.size()-1])[y] = east(eval, (v[v.size()-1])[y]);
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

double Boundary::circle(double radius, double xcenter, double ycenter, double xpos, double ypos)
{

	double position = pow((xpos - xcenter), 2) + pow((ypos - ycenter), 2);

	if(position > sqrt(radius))
	{
		return 0.0;
	}else{

		double chk = radius*sqrt(2.0)/2.0; 
//		if(position > (chk+xcenter))
			

	}
	

}

