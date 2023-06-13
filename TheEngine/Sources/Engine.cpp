/// jsteach


#include "Engine.h"
#include <Time.h>
#include <Windows.h>
#include "Console.h"
#include "FileDebug.h"
#include "SDLInput.h"
#include "SDLMixer.h"

namespace Engine
{

	/// <summary>
	/// Initialises the engine
	/// </summary>
	/// <param name="Title"></param>
	/// <param name="Width"></param>
	/// <param name="Height"></param>
	/// <returns></returns>
	bool Engine::Init(const std::string& Title, int Width, int Height)
	{
#ifdef _DEBUG
		m_Logger = new Console();

#else
		m_Logger = new FileDebug();
#endif
		m_Logger->Init();
		m_World = new WorldService();
		m_Graphics = new SDLRender();
		m_Input = new SDLInput();
		m_AudioService = new SDLMixer();
		m_AudioService->Init();
		m_Graphics->Initialize(Title, Width, Height);



		/// Trucs test
		_TestText = m_Graphics->LoadFont("Assets/slkscr.ttf", 24);
		TestCharacter = m_World->Create("TestObject1");
		size_t _testmusic = m_AudioService->LoadMusic("Assets/Sounds/TitleSong.mp3");
		_Goodtime = m_AudioService->LoadSound("Assets/Sounds/sfx4.wav");
		m_AudioService->PlayMusic(_testmusic);
		///
		m_IsInit = true;
		return true;
	}

	/// <summary>
	/// Engine core, this is where it boots up and then runs its game loop.
	/// </summary>
	void Engine::Start()
	{
		if (!m_IsInit)
		{
			if (!Init("Unknown Title", 800, 600))
			{
				return;
			}
		}

		m_IsRunning = true;
		clock_t _end = clock();
		float _lag = 0.0f;
		const int MilisecondsPerUpdate = 16; // 16 ms is more or less the ammount of miliseconds between frames at 60fps
		while (m_IsRunning)
		{
			const clock_t _start = clock();
			float _elapsed = _start - _end;
			float _dt = _elapsed * 0.001f;
			_lag += _elapsed;
			ProcessInput();
			// If there was more time between the frames than intended we run more updates to catch up.
			while (_lag >= MilisecondsPerUpdate)
			{
				Update(_dt * (_lag / MilisecondsPerUpdate)); // TEMP Deltatime is probably not being corrected for lag here.
				_lag -= MilisecondsPerUpdate;
			}

			Render(_lag / MilisecondsPerUpdate, _dt);

			float _sleeptime = clock() + MilisecondsPerUpdate - clock();
			if (_sleeptime >= 0)
			{
				Sleep(clock() + MilisecondsPerUpdate - clock());
			}

			_end = _start;
		}
		ShutDown();
	}


	/// <summary>
	/// Handle inputs.
	/// </summary>
	/// 
	void Engine::ProcessInput()
	{
		if (!m_IsRunning) return;
		m_Input->Update();
	}

	static float m_x = 0;
	static float m_y = 0;

	/// <summary>
	/// Update step, this is where the engine's logic happens.
	/// </summary>
	/// <param name="dt"></param>
	void Engine::Update(float dt)
	{

		if (!m_IsRunning) return;
		if (m_Input->IsKeyDown(EKey::EKEY_H))
		{
			m_AudioService->PlaySFX(_Goodtime);
		}
		/// test player controller---------------
		if (m_Input->IsKeyDown(EKey::EKEY_RIGHT) || m_Input->IsKeyDown(EKey::EKEY_D))
		{
			TestCharacter->SetVelX(100);
		}
		else if (m_Input->IsKeyDown(EKey::EKEY_LEFT) || m_Input->IsKeyDown(EKey::EKEY_A))
		{
			TestCharacter->SetVelX(-100);
			m_Logger->PrintWarning("aaaaaAAAAA LEEEFT");
		}
		else
		{
			TestCharacter->SetVelX(0);
		}

		if (m_Input->IsKeyDown(EKey::EKEY_UP) || m_Input->IsKeyDown(EKey::EKEY_W))
		{
			TestCharacter->SetVelY(-100);
		}
		else if (m_Input->IsKeyDown(EKey::EKEY_DOWN) || m_Input->IsKeyDown(EKey::EKEY_S))
		{
			TestCharacter->SetVelY(100);
		}
		else
		{
			TestCharacter->SetVelY(0);
		}
		/// ---------------------------------------------------
		m_World->Update(dt);
#ifdef _DEBUG
		if (m_Input->IsKeyDown(EKey::EKEY_ESCAPE))
		{
			TestCharacter = nullptr;
			Exit();
		}
#endif
	}

	/// <summary>
	/// Renders the screen
	/// </summary>
	/// <param name="dt"></param>
	/// <param name="LagCorrection"></param>
	void Engine::Render(float dt, float LagCorrection)
	{
		if (!m_IsRunning) return;
		m_Graphics->Clear();
		m_World->Draw(LagCorrection, dt);
		TestCharacter->Draw(0, 0);
		m_Graphics->DrawString("Press H for a good time!",_TestText,200,200,Color(0,0,0,255));
		m_Graphics->Present();
	}

	/// <summary>
	/// Public function allowing to shutdown the engine.
	/// </summary>
	void Engine::Engine::Exit()
	{
		ShutDown();
	}

	/// <summary>
	/// Destroys pointers and quits the application.
	/// </summary>
	void Engine::ShutDown()
	{

		if (m_Input != nullptr)
		{
			delete(m_Input);
			m_Input = nullptr;
		}
		if (m_World != nullptr)
		{
			delete(m_World);
			m_World = nullptr;
		}
		if (m_Graphics != nullptr)
		{
			m_Graphics->Shutdown();
			delete(m_Graphics);
			m_Graphics = nullptr;
		}
		if (m_AudioService != nullptr)
		{
			m_AudioService->StopMusic();
			delete(m_AudioService);
			m_AudioService = nullptr;
		}
		if (m_Logger != nullptr)
		{
			m_Logger->Close();
			delete(m_Logger);
			m_Logger = nullptr;
		}
		
		m_IsRunning = false;
	}
}

