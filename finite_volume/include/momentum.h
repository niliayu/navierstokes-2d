/* Velocity calculation from momentum conservation equations */
#include <vector>

class Momentum
{
	public:	
		void velocity_intermediate(double h, double mu, double dt, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v, std::vector<std::vector<double>> & return_u, std::vector<std::vector<double>> & return_v, std::vector<double> & xignore, std::vector<double> & yignore, std::vector<double> & xedges, std::vector<double> & yedges);

		void velocity_correction(double h, double dt, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v, std::vector<std::vector<double>> & u_temp, std::vector<std::vector<double>> & v_temp, std::vector<std::vector<double>> & p, std::vector<double> & xignore, std::vector<double> & yignore, std::vector<double> & xedges, std::vector<double> & yedges);

}; 

