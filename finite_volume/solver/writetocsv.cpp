#include "../include/writetocsv.h"
#include <iostream>
#include <stdio.h>

void WriteToCSV::write( const std::string& filename, std::vector<std::vector<double>> & mat)
{

	std::ofstream openfile;
	openfile.open(filename + ".csv", std::ios_base::app);
	
	for(unsigned int x = 0; x < mat.size(); x++)
	{
		for(unsigned int y = 0; y < mat[x].size(); y++)
		{
			openfile << mat[x][y]; 
			openfile << ","; 
		}
		openfile << "\n"; 
	}
	openfile.close();
}

void WriteToCSV::deletefile( const std::string& filename)
{

	std::remove((filename + ".csv").c_str()); 

}


