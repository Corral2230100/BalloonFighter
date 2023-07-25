#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <Windows.h>

#include "Engine.h"
#include "vld.h"
#include "FirstLevel.h"
#include "TitleScreen.h"

using namespace TomNook;

void InitGameplay()
{
	Engine::Get().m_World->Register("Level1", new FirstLevel());
	Engine::Get().m_World->Register("Title", new TitleScreen());
	Engine::Get().m_World->Load("Title");



}




INT WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ PSTR, _In_ INT)
{
	Engine& TheEngine = Engine::Get();

	if (TheEngine.Init("BalloonFight", 768, 720))
	{
		InitGameplay();
		TheEngine.Start();
	}
	delete& TheEngine;
	return 0;
}