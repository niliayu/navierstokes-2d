#include <array>
#include <algorithm>

// Initialization of flow problem

class Initialization
{

public:
	// grid size dimensions
	static const int gridx = 16;
	static const int gridy = 16;	

	// fixed time stepping
	int dt = 0.01;
	int tfinal = 100;

	int psolvit = 100; //pressure solver max iterations
	int mu = 0.001; // kinematic viscosity
	int beta = 1.2; // SOR extrapolation factor
	int h = 1/gridx; // grid height

	/* MESH INITIALIZATION */

	// x direction velocity matrix
	std::array<std::array<int,gridy+1>,gridx> u = { };

	// y direction velocity matrix
	std::array<std::array<int,gridy>,gridx+1> v = { };

	// pressure matrix
	std::array<std::array<int,gridy+1>,gridx+1> p = { };

	// x intermediate velocity matrix
	std::array<std::array<int,gridy+1>,gridx> ut = { };

	// y intermediate velocity matrix
	std::array<std::array<int,gridy>,gridx+1> vt = { };

	// coefficient matrix for pressure equations
	std::array<std::array<int,gridy+1>,gridx+1> coef = { };
	



};


