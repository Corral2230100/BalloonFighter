#include "..\Includes\Console.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <fstream>

static HANDLE hConsole;

void Engine::Console::Init()
{
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
}

void Engine::Console::Print(const std::string Message)
{
	std::cout << "ERROR: " << Message << std::endl;
}

void Engine::Console::PrintError(const std::string Message)
{
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "ERROR: " << Message << std::endl;
}

void Engine::Console::PrintWarning(const std::string Message)
{
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "ERROR: " << Message << std::endl;
}


void Engine::Console::Close()
{
	FreeConsole();
}


