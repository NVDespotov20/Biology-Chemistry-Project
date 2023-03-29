#pragma once
#include <fstream>

class FileReader
{
public:
	FileReader();
	FileReader(std::string path);
	~FileReader();
	void openFile(std::string path);
	void closeFile();
	std::string getText();

private:

	std::ifstream file;
	int lenght;
};