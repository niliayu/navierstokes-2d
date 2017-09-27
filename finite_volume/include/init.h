#include <array>
#include <algorithm>
#include <iostream>

// Initialization of flow problem

class Initialization
{

public:
	/* MESH INITIALIZATION */
	
	// grid size dimensions
	static constexpr int gridx = 16;
	static constexpr int gridy = 16;	

	// x direction velocity matrix
	std::array<std::array<double,gridy+1>,gridx> u = { };

	// y direction velocity matrix
	std::array<std::array<double,gridy>,gridx+1> v = { };

	// pressure matrix
	std::array<std::array<double,gridy+1>,gridx+1> p = { };

	// x intermediate velocity matrix
	std::array<std::array<double,gridy+1>,gridx> ut = { };

	// y intermediate velocity matrix
	std::array<std::array<double,gridy>,gridx+1> vt = { };

	// coefficient matrix for pressure equations
	std::array<std::array<double,gridy+1>,gridx+1> coeff = { };
	
	// must run to initialize coefficient matrix
	void fill_coeff_matrix(){
	for(int x = 0; x < gridx+1; x++){
		for(int y = 0; y < gridy+1; y++){
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
	constexpr int getGridx()
	{
		return gridx;
	}

	constexpr int getGridy()
	{
		return gridy;
	}


	int getUTop(){ return u_top; }
	int getUBottom(){return u_bottom; }
	int getVLeft(){return v_left; }
	int getVRight(){return v_right; }

	int getMu(){return mu; }
	int getH(){return h; }
	int getBeta(){return beta; }
	int getDt(){return dt; }
	int getTime(){return time; }
	int getTFinal(){return tfinal; }	
};


