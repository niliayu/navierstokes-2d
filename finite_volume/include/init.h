#include <vector>
#include <algorithm>
#include <iostream>

// Initialization of flow problem

class Initialization
{
	int gridx;
	int gridy;	
	
	std::vector< std::vector<double> > u; 
	std::vector< std::vector<double> > v; 
	std::vector< std::vector<double> > p; 
	std::vector< std::vector<double> > ut; 
	std::vector< std::vector<double> > vt; 
	std::vector< std::vector<double> > coeff; 
			
	public:
		/* MESH INITIALIZATION */
	
	Initialization(): 
		//grid initialization	
		gridx(16), gridy(16), 
		//velocity matrices	,
		u(gridx, std::vector<double>(gridy)) ,
		v(gridx, std::vector<double>(gridy)) ,
		p(gridx, std::vector<double>(gridy)) ,
		ut(gridx, std::vector<double>(gridy)) ,
		vt(gridx, std::vector<double>(gridy)) ,
		coeff(gridx, std::vector<double>(gridy))
		{
			fill_coeff_matrix();	
		}
	
		// must run to initialize coefficient matrix
		void fill_coeff_matrix(){
		for(int x = 0; x < gridx; x++){
			for(int y = 0; y < gridy; y++){
				if(x == y) //this is a corner
					coeff[x][y] = 0.5;
				else if((x == 0) || (x == gridx)) //this is an edge
					coeff[x][y] = 1.0/3.0;
				else //inside the grid
					coeff[x][y] = 0.25;
			}
		}
		}
		
		// vector boundary conditions
		double u_top = 1;
		double u_bottom = 0;
		double v_left = 0;
		double v_right = 0;
	
	
		/* SIMULATION INITIALIZATION */
		double time = 0.0;
	
		// fixed time stepping
		double dt = 0.01;
		int tfinal = 100;
	
		int psolvit = 100; //pressure solver max iterations
		double mu = 0.001; // kinematic viscosity
		double beta = 1.2; // SOR extrapolation factor
		double h = 1.0/gridx; // grid height
	
	
		/* Get/Set methods */
		int getGridx()
		{
			return gridx;
		}
	
		int getGridy()
		{
			return gridy;
		}
	/*
	
		double getUTop(){ return u_top; }
		double getUBottom(){return u_bottom; }
		double getVLeft(){return v_left; }
		double getVRight(){return v_right; }
	
		double getMu(){return mu; }
		double getH(){return h; }
		double getBeta(){return beta; }
		double getDt(){return dt; }
		double getTime(){return time; }
		int getTFinal(){return tfinal; }	
	
		//TODO: Add get functions for references
	
	*/	
	};


