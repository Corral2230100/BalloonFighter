#pragma once
#include "..\Includes\FileDebug.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <fstream>


using namespace Engine2;
/// <summary>
/// Initialises the file log
/// </summary>
void FileDebug::Init()
{
	 MyFile = new std::ofstream("DebugLog.txt");
}

/// <summary>
/// prints a message to the output file.
/// </summary>
/// <param name="Message"></param>
void FileDebug::Print(const std::string Message)
{
	(*MyFile) << Message << std::endl;
}

/// <summary>
/// prints an error message to the output file
/// </summary>
/// <param name="Message"></param>
void FileDebug::PrintError(const std::string Message)
{
	(*MyFile) << "ERROR: " << Message << std::endl;
}

/// <summary>
/// prints a warning to the output file
/// </summary>
/// <param name="Message"></param>
void FileDebug::PrintWarning(const std::string Message)
{
	(*MyFile) << "WARNING: " << Message << std::endl;
}

/// <summary>
/// stops edditing the file and "ends" the service
/// </summary>
void FileDebug::Close()
{
	(*MyFile).close();
	delete(MyFile);
	MyFile = nullptr;
}
