#include <vector>
#include <algorithm>
#include <iostream>

// Initialization of flow problem

class Initialization
{
	//grid initialization	
	int gridx;
	int gridy;	
	
	//velocity matrices	,
	std::vector< std::vector<double> > u; 
	std::vector< std::vector<double> > v; 
	std::vector< std::vector<double> > p; 
	std::vector< std::vector<double> > ut; 
	std::vector< std::vector<double> > vt; 
	std::vector< std::vector<double> > coeff; 

	//ignore vector
	std::vector<double> xignore;
	std::vector<double> yignore;
	std::vector<double> xedges;
	std::vector<double> yedges;

	// vector boundary conditions
	double u_top;
	double u_bottom;
	double v_left;
	double v_right;
			
	public:
		/* MESH INITIALIZATION */
	
	Initialization(): 
		gridx(16), gridy(16), 
		u(gridx, std::vector<double>(gridy, 0)) ,
		v(gridx, std::vector<double>(gridy, 0)) ,
		p(gridx, std::vector<double>(gridy)) ,
		ut(gridx, std::vector<double>(gridy)) ,
		vt(gridx, std::vector<double>(gridy)) ,
		coeff(gridx, std::vector<double>(gridy)),
		u_top(1), u_bottom(0),
		v_left(0), v_right(0)
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

	//TODO: Move these declarations and add to initialization list	
	// OR add to functions and add to constructor	
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
	
		std::vector<std::vector<double>> & getU() { return u; }	
		std::vector<std::vector<double>> & getV() { return v; }	
		std::vector<std::vector<double>> & getP() { return p; }	
		std::vector<std::vector<double>> & getUt() { return ut; }	
		std::vector<std::vector<double>> & getVt() { return vt; }	
		std::vector<std::vector<double>> & getCoeff() { return coeff; }	
	};


