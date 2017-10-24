#include "../include/ignore.h"

	void Ignore::circle(double radius, double xcenter, double ycenter, double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore, std::vector<double> xedges, std::vector<double> yedges)
		{

			double position = sqrt(pow((xpos - xcenter), 2) 
					+ pow((ypos - ycenter), 2));
		
			if(position < radius)
			{
				xignore.push_back(xpos); 
				yignore.push_back(ypos);	
			}else if(position == radius)
			{
				xedges.push_back(xpos);
				yedges.push_back(ypos);
			}	

		}


	bool Ignore::checker(double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore)
	{

		return (std::find(xignore.begin(), xignore.end(), xpos) != xignore.end())
			&& (std::find(yignore.begin(), yignore.end(), ypos) != yignore.end()); 

	}

	double Ignore::obj_boundary(double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore)
	{
		if (std::find(xignore.begin(), xignore.end(), xpos) != xignore.end())
		{
			if(std::find(yignore.begin(), yignore.end(), ypos+1) != yignore.end())
			{
				//call north
			}	
		
		}	


	}


