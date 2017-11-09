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

	double time;

	// fixed time stepping
	double dt;
	int tfinal;

	int maxit; //pressure solver max iterations
	double mu; // kinematic viscosity
	double beta; // SOR extrapolation factor
	double h; // grid height
	
	public:
		/* MESH INITIALIZATION */
	
	Initialization(): 
		gridx(18), gridy(18), 
		u(gridx-1, std::vector<double>(gridy, 0)) ,
		v(gridx, std::vector<double>(gridy-1, 0)) ,
		p(gridx, std::vector<double>(gridy)) ,
		ut(gridx-1, std::vector<double>(gridy)) ,
		vt(gridx, std::vector<double>(gridy-1)) ,
		coeff(gridx, std::vector<double>(gridy)),
		u_top(1), u_bottom(0),
		v_left(0), v_right(0),
		dt(0.005),
		tfinal(100),
	
		maxit(100), //pressure solver max iterations
		mu(0.001), // kinematic viscosity
		beta(1.2), // SOR extrapolation factor
		h(1.0/(gridx-2)) // grid height
		{
			fill_coeff_matrix();	
		}
	
		// must run to initialize coefficient matrix
		void fill_coeff_matrix(){
			for(int x = 0; x < gridx; x++){
				for(int y = 0; y < gridy; y++){
					if(((x == 1) || (x == gridx-2) || (y == 1) || (y == gridy-2))&&(x!=0&&y!=0&&x!=gridx-1&&y!=gridy-1)){ //this is an edge
						if(x == y||x==y+gridy-3||y==x+gridx-3) //this is a corner
							coeff[x][y] = 0.5;
						else
							coeff[x][y] = 1.0/3.0;
					}
					else //inside the grid
						coeff[x][y] = 0.25;
				}
			}
		}
	
		/* Get/Set methods */
		int getGridx(){ return gridx; }
		int getGridy(){ return gridy; }
	
		double getUTop(){ return u_top; }
		double getUBottom(){return u_bottom; }
		double getVLeft(){return v_left; }
		double getVRight(){return v_right; }

		double getMaxIt(){return maxit; }	
		double getMu(){return mu; }
		double getH(){return h; }
		double getBeta(){return beta; }
		double getDt(){return dt; }
		double getTime(){return time; }
		int getTFinal(){return tfinal; }	
	
		std::vector<double> & getXignore(){ return xignore; }
		std::vector<double> & getYignore(){ return yignore; }
		std::vector<double> & getXedges(){ return xedges; } 
		std::vector<double> & getYedges(){ return yedges; } 

		std::vector<std::vector<double>> & getU() { return u; }	
		std::vector<std::vector<double>> & getV() { return v; }	
		std::vector<std::vector<double>> & getP() { return p; }	
		std::vector<std::vector<double>> & getUt() { return ut; }	
		std::vector<std::vector<double>> & getVt() { return vt; }	
		std::vector<std::vector<double>> & getCoeff() { return coeff; }	
	};


