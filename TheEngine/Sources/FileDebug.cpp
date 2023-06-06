#pragma once
#include "..\Includes\FileDebug.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <fstream>



void Engine::FileDebug::Init()
{
	 MyFile = new std::ofstream("DebugLog.txt");
}

void Engine::FileDebug::Print(const std::string Message)
{
	(*MyFile) << Message << std::endl;
}

void Engine::FileDebug::PrintError(const std::string Message)
{
	(*MyFile) << "ERROR: " << Message << std::endl;
}

void Engine::FileDebug::PrintWarning(const std::string Message)
{
	(*MyFile) << "WARNING: " << Message << std::endl;
}

void Engine::FileDebug::Close()
{
	(*MyFile).close();
	delete(MyFile);
	MyFile = nullptr;
}
