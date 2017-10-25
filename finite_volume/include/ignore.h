#include <vector>
#include <cmath>
#include <algorithm>

class Ignore
{

	public:
		void circle(double radius, double xcenter, double ycenter, double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore, std::vector<double> xedges, std::vector<double> yedges); 

		bool checker(double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore);

		double obj_boundary(double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore, std::vector<double> xedges, std::vector<double> yedges, std::vector<std::vector<double>> & u, std::vector<std::vector<double>> & v);

}; 

