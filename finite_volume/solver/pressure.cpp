#include "../include/pressure.h"
#include "../include/ignore.h"
#include <iostream>
#include "../include/printmatrix.h"

void Pressure::pressure_calc(double beta, double height, double dt, double maxit, std::vector<std::vector<double>> & p, std::vector<std::vector<double>> & ut, std::vector<std::vector<double>> & vt, std::vector<std::vector<double>> & coeff, std::vector<double> xignore, std::vector<double> yignore, std::vector<double> xedges, std::vector<double> yedges) 
{

	Ignore object;

	for(int it = 0; it < maxit; it++)
	{
		for(unsigned int x = 1; x < ut.size(); x++)
		{
			for(unsigned int y = 1; y < ut[x].size()-1; y++)
			{
				if(!object.checker(x, y, xignore, yignore, xedges, yedges)){	
					double psum = beta*coeff[x][y]*(p[x+1][y]+p[x-1][y]+p[x][y+1]+p[x][y-1]); 
					double vsum = beta*coeff[x][y]*(height/dt)*(-ut[x][y]+ut[x-1][y]-vt[x][y]+vt[x][y-1]); 
					double relaxation = (1-beta)*p[x][y];
	/*
					std::cout << "x:" << x << " y: " << y << std::endl;
					std::cout << "ut[x][y]: " << ut[x][y] << " ut[x-1][y]: " << ut[x-1][y] << std::endl;
					std::cout << "vt[x][y]: " << vt[x][y] << " vt[x-1][y]: " << vt[x-1][y] << std::endl;
					std::cout << "p1: " << p[x+1][y] << ", p2: " << p[x-1][y] <<
						", p3: " << p[x][y+1] << ", p4: " << p[x][y-1] 
						<< std::endl;
					std::cout << "psum: " << psum << ", vsum: " << vsum << ", relax: " << relaxation << std::endl;
	*/
	//				p_temp[x][y] = psum - vsum + relaxation;		
					p[x][y] = psum - vsum + relaxation;	
			}	
		}
		
		}
/*
		std::cout << "Pressure iteration#" << it << std::endl;
				PrintMatrix printm;
				printm.print(p);
*/

	}
}

