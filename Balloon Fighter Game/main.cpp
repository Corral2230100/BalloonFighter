#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>

#include "Engine.h"
#include "vld.h"
#include "Fighter.h"
using namespace Engine2;
void InitGameplay()
{
	// cringe temporary cancer
	Fighter* _m = new Fighter();



}




INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT)
{
	Engine& TheEngine = Engine::Get();
	if (TheEngine.Init("BalloonFight", 800, 600))
	{
		InitGameplay();
		TheEngine.Start();
	}
	delete &TheEngine;
	return 0;
}