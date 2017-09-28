/* Velocity calculation from momentum conservation equations */

#include "init.h"

class Momentum
{

	private:
		static Initialization init;
		static constexpr int gridy = init.getGridx();
		static constexpr int gridx = init.getGridy();

	public:	
//		template<std::size_t SIZE>
	
		void velocity_calc(double h, double mu, double dt, std::array<std::array<double, gridy + 1>, gridx> & u, std::array<std::array<double, gridy>, gridx+1> & v, std::array<std::array<double, gridy + 1>, gridx> & return_u, std::array<std::array<double, gridy>, gridx+1> & return_v);

}; 

