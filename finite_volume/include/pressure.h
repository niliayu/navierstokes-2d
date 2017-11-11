#include <vector>
#include <algorithm> 

class Pressure
{
	public:
		void pressure_calc(double beta, double height, double dt, double maxit, std::vector<std::vector<double>> & p, std::vector<std::vector<double>> & ut, std::vector<std::vector<double>> & vt, std::vector<std::vector<double>> & coeff, std::vector<double> & xignore, std::vector<double> & yignore, std::vector<double> & xedges, std::vector<double> & yedges); 
};
