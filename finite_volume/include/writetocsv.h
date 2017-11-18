#include <iostream>
#include <fstream>
#include <vector>
#include <string>


class WriteToCSV
{

	public:
		void write( const std::string& filename, std::vector<std::vector<double>> & mat);
		void deletefile(const std::string& filename);

}; 

