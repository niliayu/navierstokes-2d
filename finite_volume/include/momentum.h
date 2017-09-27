/* Velocity calculation from momentum conservation equations */

#include "init.h"

class Momentum
{

	private:
		static Initialization init;
		static constexpr int gridy = init.getGridx();
		static constexpr int gridx = init.getGridy();

	public:	

		void velocity_calc(double h, double mu, double dt, std::array<std::array<double, gridy + 1>, gridx> & u_matrix, std::array<std::array<double, gridy>, gridx+1> & v_matrix, std::array<std::array<double, gridy + 1>, gridx> & return_u, std::array<std::array<double, gridy>, gridx+1> & return_v);

}; 

