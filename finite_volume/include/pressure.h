#include <vector>

class Pressure
{
	public:
		void pressure_calc(double beta, double height, double dt, std::vector<std::vector<double>> & p, std::vector<std::vector<double>> & ut, std::vector<std::vector<double>> & vt, std::vector<std::vector<double>> & coeff); 
};
