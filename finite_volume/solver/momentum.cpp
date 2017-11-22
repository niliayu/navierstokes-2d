/* Implementation of momentum equations for solving intermediate velocity */

#include "../include/momentum.h"
#include "../include/ignore.h"
#include <cmath>
#include <iostream>

void Momentum::velocity_intermediate(double h, double mu, double dt, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v, std::vector<std::vector<double>> & return_u, std::vector<std::vector<double>> & return_v, std::vector<double> & xignore, std::vector<double> & yignore, std::vector<double> & xedges, std::vector<double> & yedges)
{
	Ignore object;

	//U projection matrix 
	for(unsigned int x = 1; x < u.size()-1; x++)
	{
		for(unsigned int y = 1; y < u[x].size()-2; y++)
		{
			if(!object.checker(x, y, xignore, yignore, xedges, yedges)){

				return_u[x][y] = u[x][y] + dt*((-0.25/h)*(pow((u[x-1][y]+u[x][y]),2.0) 
						- pow((u[x+1][y]+u[x][y]),2.0) 
						+ ((u[x][y-1]+u[x][y])*(v[x-1][y]+v[x][y])) 
						- ((u[x][y]+u[x][y+1])*(v[x-1][y-1]+v[x][y+1]))) 
					+ (mu/pow(h,2.0))*(u[x-1][y]+u[x+1][y]+u[x][y-1]+u[x][y+1]
						-(4*u[x][y])));	
			}else{
				object.obj_boundary(x, y, xignore, yignore, xedges, yedges, u, v);  
			}
		}	
}	

	//V projection matrix
	for(unsigned int x = 1; x < v.size()-2; x++)
	{
		for(unsigned int y = 1; y < v[x].size()-1; y++)
		{ 
			if(!object.checker(x, y, xignore, yignore, xedges, yedges)){
				return_v[x][y] = v[x][y] + dt*(-(0.25/h)*((u[x-1][y-1]+u[x-1][y])
						*(v[x-1][y]+v[x][y]) - (u[x][y]+u[x][y+1])
						*(v[x+1][y]+v[x][y]) + (pow((v[x][y-1]+v[x][y]),2.0)
						       	- pow((v[x][y+1]+v[x][y]),2.0))) 
					+ (mu/pow(h,2.0))*(v[x-1][y]+v[x+1][y]+v[x][y-1]+v[x][y+1]
						-(4*v[x][y]))); 

			std::cout << "x " << x << " y " << y << std::endl;
			std::cout << "v " << v[x][y] << ", u " << u[x-1][y] << std::endl;	
			std::cout  << " v[x][y-1] "<< v[x][y-1] << " v[x][y+1] " << v[x][y+1];
			std::cout << " v[x-1][y] " << v[x-1][y] << " v[x+1][y] " << v[x+1][y] << std::endl;
			std::cout  << " u[x-1][y-1] " << u[x-1][y-1] << " u[x][y+1] " << u[x][y+1] << "  u[x][y] " << u[x][y] << std::endl;
			std::cout << "sum " << return_v[x][y] << std::endl;	
			
			std::cout << std::endl;
			}else{
				object.obj_boundary(x, y, xignore, yignore, xedges, yedges, u, v);  
			}
		}
	}
}	

void Momentum::velocity_correction(double h, double dt, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v, std::vector<std::vector<double>> & u_temp, std::vector<std::vector<double>> & v_temp, std::vector<std::vector<double>> & p, std::vector<double> & xignore, std::vector<double> & yignore, std::vector<double> & xedges, std::vector<double> & yedges)  
{

	Ignore object;
	for(unsigned int x = 1; x < u.size()-1; x++)
	{
		for(unsigned int y = 1; y < u[x].size()-1; y++)
		{
			if(!object.checker(x, y, xignore, yignore, xedges, yedges))
				u[x][y] = u_temp[x][y] - (dt/h)*(-p[x+1][y] + p[x][y]);
		}
	}
	
	for(unsigned int x = 1; x < v.size()-1; x++)
	{
		for(unsigned int y = 1; y < v[x].size()-1; y++)
		{
			if(!object.checker(x, y, xignore, yignore, xedges, yedges))
				v[x][y] = v_temp[x][y] - (dt/h)*(-p[x][y+1] + p[x][y]); 
		}
	}
}


