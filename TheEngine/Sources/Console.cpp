#include "..\Includes\Console.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>
#include <fstream>

static HANDLE hConsole;
using namespace Engine2;
/// <summary>
/// Initialies the console service
/// </summary>
void Console::Init()
{
	AllocConsole();
	int _r = freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
}

/// <summary>
/// Displays a message in the console
/// </summary>
/// <param name="Message"></param>
void Console::Print(const std::string Message)
{
	std::cout << Message << std::endl;
}

/// <summary>
/// Displays a red error in the console
/// </summary>
/// <param name="Message"></param>
void Console::PrintError(const std::string Message)
{
	SetConsoleTextAttribute(hConsole, 12);
	std::cout << "ERROR: " << Message << std::endl;
}

/// <summary>
/// Displays a yellow warning in the console
/// </summary>
/// <param name="Message"></param>
void Console::PrintWarning(const std::string Message)
{
	SetConsoleTextAttribute(hConsole, 14);
	std::cout << "WARNING: " << Message << std::endl;
}


/// <summary>
/// Shuts the console down
/// </summary>
void Console::Close()
{
	FreeConsole();
}


