#include <vector>
#include <cmath>

class Boundary
{

	public:
		void boundary(double nval, double sval, double eval, double wval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v);

		void boundary(double nval, double sval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v, double max);

		double getNSparabolic(double xpos, double xgrid, double max);
		double getEWparabolic(double ypos, double ygrid, double max); 
	
		double reflect(double val, double cell_value);
};


