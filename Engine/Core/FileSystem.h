#pragma once
#include <string>
#include <sdl_log.h>


namespace nc 
{
	void setFilePath(const std::string& pathway);
	std::string GetFilePath();
	bool ReadFileToString(const std::string& filename, std::string& filestring);

}