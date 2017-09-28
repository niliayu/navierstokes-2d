/* Velocity calculation from momentum conservation equations */

#include "init.h"

class Momentum
{

	public:	
		void velocity_calc(double h, double mu, double dt, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v, std::vector<std::vector<double>> & return_u, std::vector<std::vector<double>> & return_v);

}; 

