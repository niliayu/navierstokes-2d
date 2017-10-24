#include <vector>
#include <cmath>
#include <algorithm>

class Ignore
{

	public:
		void circle(double radius, double xcenter, double ycenter, double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore); 

		bool checker(double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore);

		double obj_boundary(double xpos, double ypos, std::vector<double> xignore, std::vector<double> yignore);

}; 

