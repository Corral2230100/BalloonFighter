#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>

#include "Engine.h"
#include "vld.h"
#include "Fighter.h"
#include "Block.h"



using namespace TomNook;

void InitGameplay()
{




}




INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT)
{
	Engine& TheEngine = Engine::Get();
	Fighter* _fighter{};
	Block* _block{};

	if (TheEngine.Init("BalloonFight", 800, 600))
	{
		InitGameplay();
		// cringe temporary cancer
		_fighter = new Fighter();
		// More temporary cringe
		_block = new Block();
		TheEngine.Start();
	}
	delete _fighter;
	delete _block;
	delete& TheEngine;
	return 0;
}