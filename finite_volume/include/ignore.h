#include <cmath>

class Ignore
{

	public:
		void circle(double radius, double xcenter, double ycenter, double xpos, double ypos)
		{

			double position = pow((xpos - xcenter), 2) + pow((ypos - ycenter), 2);
		
			if(position > sqrt(radius))
				return 0.0;

		}

}


