#include <pch.hpp>
#include "FileReader.hpp"

FileReader::FileReader()
{
}

FileReader::FileReader(std::string path)
{
	openFile(path);
}

FileReader::~FileReader()
{
	closeFile();
}

void FileReader::openFile(std::string path)
{
	closeFile();

	file.open(path);
	if (!file.is_open())
	{
		std::cout << "File not loaded path: " << path;
	}
}

void FileReader::closeFile()
{
	if (file.is_open())
		file.close();
}

std::string FileReader::getText()
{
	if (!file.is_open())
		return "";

	std::string str, tmp;

	while (!file.eof())
	{
		std::getline(file, tmp);
		str += tmp + '\n';
	}
	str.erase(str.end() - 1);

	return str;
}