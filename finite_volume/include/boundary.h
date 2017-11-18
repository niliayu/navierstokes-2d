#include <vector>
#include <cmath>

class Boundary
{

	public:
		void boundary(double nval, double sval, double eval, double wval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v);

		void boundary(double nval, double sval, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v);

		double getNSparabolic(double xpos, double xgrid);
		double getEWparabolic(double ypos, double ygrid); 
	
		double north(double nval, double cell_value);
		double south(double sval, double cell_value);
		double east(double eval, double cell_value);
		double west(double wval, double cell_value);

};


