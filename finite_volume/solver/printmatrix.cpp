#include <vector>
#include <iostream>


class PrintMatrix
{
	public:
		void print(std::vector<std::vector<double>> & matrix);
}; 

void PrintMatrix::print(std::vector<std::vector<double>> & matrix)
{

	int xmax = matrix.size(); //convert to signed int

	for(int x = 0; x < xmax; x++){
		int ymax = matrix[x].size(); //convert to signed int
		for(int y = 0; y < ymax; y++)
		{
			std::cout << matrix[x][y] << " ";
			if(y == ymax - 1)
				std::cout << std::endl;
		}
	}	

}



