#include "FileSystem.h"
#include<filesystem>
#include <fstream>
#include <sstream>

namespace nc
{
	void setFilePath(const std::string& pathway)
	{
		std::filesystem::current_path(pathway);

	}
	std::string GetFilePath()
	{
		return std::filesystem::current_path().string();
	}
	bool ReadFileToString(const std::string& filename, std::string& filestring)
	{
		std::ifstream fileStream(filename, std::ios::in);
		if (!fileStream)
		{
			SDL_Log("Error: Failed to open file: %s", filename.c_str());
			return false;
		}

		std::stringstream stream;
		stream << fileStream.rdbuf();
		filestring = stream.str();
		fileStream.close();
		return true;

	}
}