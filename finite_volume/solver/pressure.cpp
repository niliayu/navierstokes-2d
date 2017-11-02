#include "../include/pressure.h"
#include <iostream>
#include "../include/printmatrix.h"

void Pressure::pressure_calc(double beta, double height, double dt, double maxit, std::vector<std::vector<double>> & p, std::vector<std::vector<double>> & ut, std::vector<std::vector<double>> & vt, std::vector<std::vector<double>> & coeff) 
{

	//assuming uniform grid
	std::vector<std::vector<double>> p_temp(p.size(), std::vector<double>(p[0].size(), 0));

	for(int it = 0; it < maxit; it++)
	{
		for(unsigned int x = 1; x < ut.size()-1; x++)
		{
			for(unsigned int y = 1; y < ut[x].size()-1; y++)
			{
				double psum = beta*coeff[x][y]*(p[x+1][y]+p[x-1][y]+p[x][y+1]+p[x][y-1]); 
				double vsum = beta*coeff[x][y]*(height/dt)*(-ut[x][y]+ut[x-1][y]-vt[x][y]+vt[x][y-1]); 
				double relaxation = (1-beta)*p[x][y];
/*
				std::cout << "x:" << x << " y: " << y << std::endl;
				std::cout << "ut[x][y]: " << ut[x][y] << " ut[x-1][y]: " << ut[x-1][y] << std::endl;
				std::cout << "p1: " << p[x+1][y] << ", p2: " << p[x-1][y] <<
					", p3: " << p[x][y+1] << ", p4: " << p[x][y-1] 
					<< std::endl;
				std::cout << "psum: " << psum << ", vsum: " << vsum << ", relax: " << relaxation << std::endl;
*/
//				p_temp[x][y] = psum - vsum + relaxation;		
				p[x][y] = psum - vsum + relaxation;	
			}
		
//		std::copy(&p_temp[0][0], &p_temp[0][0]+p_temp.size()*p_temp[0].size(), &p[0][0]);	
		}
/*
		std::cout << "Pressure iteration#" << it << std::endl;
				PrintMatrix printm;
				printm.print(p);
*/

	}
}

