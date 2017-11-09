#include "../include/ignore.h"
#include "../include/boundary.h"
#include <iostream>

	void Ignore::circle(double radius, double xcenter, double ycenter, double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore, std::vector<double> xedges, std::vector<double> yedges)
		{

			double position = sqrt(pow((xpos - xcenter), 2) 
					+ pow((ypos - ycenter), 2));
		
			if(position < radius)
			{
				xignore.push_back(xpos); 
				yignore.push_back(ypos);	
				//std::cout << "Inside: x: " << xpos << ", y: " << ypos << std::endl;	
			}else if(position == radius)
			{
				xedges.push_back(xpos);
				yedges.push_back(ypos);
				//std::cout << "Edge: x: " << xpos << ", y: " << ypos << std::endl;	
		}	

		}


	bool Ignore::checker(double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore, std::vector<double> xedges, std::vector<double> yedges)
	{

		return ((std::find(xignore.begin(), xignore.end(), xpos) != xignore.end())
			&& (std::find(yignore.begin(), yignore.end(), ypos) != yignore.end())
			&& (std::find(xignore.begin(), xignore.end(), xpos) != xignore.end())
			&& (std::find(yignore.begin(), yignore.end(), ypos) != yignore.end())); 

	}

	void Ignore::obj_boundary(double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore, std::vector<double> xedges, std::vector<double> yedges, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v)
{
	Boundary bound;

	if (std::find(xignore.begin(), xignore.end(), xpos+1) != xignore.end())
	{ 
		//call west with x-1
		//reflect + extend xval on x+1	
		v[xpos][ypos] = bound.west(v[xpos][ypos], v[xpos-1][ypos]);	
	}else if(std::find(xignore.begin(), xignore.end(), xpos-1) != xignore.end()){
		//call east with x+1 
		//reflect + extend xvalon x-1	
		v[xpos][ypos] = bound.east(v[xpos][ypos], v[xpos+1][ypos]);	
	}


	if(std::find(yignore.begin(), yignore.end(), ypos+1) != yignore.end())
	{
		//call north, y+1 is in yignore, call with y-1
		//reflect + extend yval on y+1	
		u[xpos][ypos] = bound.north(v[xpos][ypos], v[xpos][ypos-1]);	
	}else if(std::find(yignore.begin(), yignore.end(), ypos-1) != yignore.end()){
		//call south, y-1 is in yignore, call with y+1
		//reflect + extend yval on y-1	
		u[xpos][ypos] = bound.south(v[xpos][ypos], v[xpos][ypos+1]);	
	}	
		
}	


	


