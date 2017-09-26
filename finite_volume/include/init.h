#include <array>
#include <algorithm>
#include <iostream>

// Initialization of flow problem

class Initialization
{

public:
	/* MESH INITIALIZATION */
	
	// grid size dimensions
	static const int gridx = 16;
	static const int gridy = 16;	


	// x direction velocity matrix
	std::array<std::array<double,gridy+1>,gridx> u = { };

	// y direction velocity matrix
	std::array<std::array<double,gridy>,gridx+1> v = { };

	// pressure matrix
	std::array<std::array<double,gridy+1>,gridx+1> p = { };

	// x doubleermediate velocity matrix
	std::array<std::array<double,gridy+1>,gridx> ut = { };

	// y doubleermediate velocity matrix
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

			// DEBUG
			std::cout << "X";
			std::cout << x << std::endl;
			std::cout << "Y";
			std::cout << y << std::endl;
			std::cout << coeff[x][y] << std::endl;	
		}
	}
	}


	/* SIMULATION INITIALIZATION */
	double time = 0.0;

	// fixed time stepping
	int dt = 0.01;
	int tfinal = 100;

	int psolvit = 100; //pressure solver max iterations
	int mu = 0.001; // kinematic viscosity
	int beta = 1.2; // SOR extrapolation factor
	int h = 1/gridx; // grid height

};


