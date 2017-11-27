#include "../include/ignore.h"
#include "../include/boundary.h"
#include <iostream>


	void Ignore::circle(double radius, double xcenter, double ycenter, double xpos, double ypos, std::vector<double> & xignore, std::vector<double> & yignore, std::vector<double> & xedges, std::vector<double> & yedges)
		{

			double position = sqrt(pow((xpos - xcenter), 2) 
					+ pow((ypos - ycenter), 2));
	
			if(floor(position) < radius)
			{
				xignore.push_back(xpos); 
				yignore.push_back(ypos);	
			}else if(floor(position) == radius)
			{
				xedges.push_back(xpos);
				yedges.push_back(ypos);
			}	

		}


	bool Ignore::checker(double xpos, double ypos, std::vector<double> & xignore, std::vector<double> & yignore, std::vector<double> & xedges, std::vector<double> & yedges)
	{
		
		return (((std::find(xignore.begin(), xignore.end(), xpos) != xignore.end())
			&& (std::find(yignore.begin(), yignore.end(), ypos) != yignore.end()))
			|| ((std::find(xedges.begin(), xedges.end(), xpos) != xedges.end())
			&& (std::find(yedges.begin(), yedges.end(), ypos) != yedges.end()))); 

	}

	void Ignore::obj_boundary(double xpos, double ypos, std::vector<double> & xignore, std::vector<double> & yignore, std::vector<double> & xedges, std::vector<double> & yedges, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v)
{
	Boundary bound;

//	for(int i = 0; i < xignore.size(); i++)

	if((std::find(xedges.begin(), xedges.end(), xpos) != xedges.end()) && (std::find(yedges.begin(), yedges.end(), ypos) != yedges.end()))
	{	
		if (std::find(yignore.begin(), yignore.end(), ypos-1) == yignore.end())
		{ 
			//call west with x-1
			//reflect + extend xval on x+1	
//			v[xpos][ypos] = bound.reflect(v[xpos][ypos], v[xpos-1][ypos]);	
			v[xpos][ypos] = bound.reflect(0, v[xpos-1][ypos]);	
		}
		
		if(std::find(yignore.begin(), yignore.end(), ypos+1) == yignore.end()){
			//call east with x+1 
			//reflect + extend xval on x-1	
			//v[xpos][ypos] = bound.reflect(v[xpos][ypos], v[xpos+1][ypos]);	
			v[xpos][ypos] = bound.reflect(0, v[xpos+1][ypos]);	
		}
	
		if(std::find(xignore.begin(), xignore.end(), xpos-1) == xignore.end())
		{
			//call north, y+1 is in yignore, call with y-1
			//reflect + extend yval on y+1	
			//u[xpos][ypos] = bound.reflect(u[xpos][ypos], u[xpos][ypos-1]);	
			u[xpos][ypos] = bound.reflect(0, u[xpos][ypos-1]);	
		}
		
		if(std::find(xignore.begin(), xignore.end(), xpos+1) == xignore.end()){
			//call south, y-1 is in yignore, call with y+1
			//reflect + extend yval on y-1	
			//u[xpos][ypos] = bound.reflect(u[xpos][ypos], u[xpos][ypos+1]);	
			u[xpos][ypos] = bound.reflect(0, u[xpos][ypos+1]);	
		}	
	}
}
	


