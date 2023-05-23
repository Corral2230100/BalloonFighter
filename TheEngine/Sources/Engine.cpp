#include "..\Includes\Engine.h"

#include <SDL.h>
#include <Time.h>
#include <Windows.h>

bool Engine::Engine::Init(const std::string& Title, int Width, int Height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;

	Uint32 _flag = SDL_WINDOW_TOOLTIP | SDL_WINDOW_RESIZABLE;
	m_Window = SDL_CreateWindow(Title.c_str(), _x, _y, Width, Height, _flag);
	if (!m_Window)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	_flag = SDL_RENDERER_ACCELERATED;
	m_Renderer = SDL_CreateRenderer(m_Window, -1, _flag);
	if (!m_Renderer)
	{
		SDL_Log(SDL_GetError());
		return false;
	}



	m_IsInit = true;
	return true;
}

void Engine::Engine::Start()
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
			Update(_dt); // TEMP Deltatime is probably not being corrected for lag here.
			_lag -= MilisecondsPerUpdate;
		}
		
		Render();
		Sleep(clock() + MilisecondsPerUpdate - clock());
		_end = _start;
	}
	ShutDown();
}



void Engine::Engine::ProcessInput()
{
	SDL_Event _event;

	while (SDL_PollEvent(&_event))
	{
		switch (_event.type)
		{
		case SDL_QUIT:

			Exit();
			break;
		case SDL_MOUSEBUTTONDOWN:
			SDL_MouseButtonEvent _buttonDown = _event.button;
			break;
		case SDL_MOUSEBUTTONUP:
			SDL_MouseButtonEvent _buttonUp = _event.button;
			break;
		case SDL_MOUSEMOTION:
			SDL_MouseMotionEvent _motion = _event.motion;
			break;
		}
	}
}

static float x = 0;
static float y = 0;
void Engine::Engine::Update(float dt)
{
	const unsigned char* _keyStates = SDL_GetKeyboardState(nullptr);
	if (_keyStates[SDL_SCANCODE_D])
	{
		x += 100 * dt;
	}
	if (_keyStates[SDL_SCANCODE_A])
	{
		x -= 100 * dt;
	}
	if (_keyStates[SDL_SCANCODE_W])
	{
		y -= 100 * dt;
	}
	if (_keyStates[SDL_SCANCODE_S])
	{
		y += 100 * dt;
	}
}

void Engine::Engine::Render()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
	SDL_SetRenderDrawColor(m_Renderer, 255, 64, 64, 255);
	SDL_Rect _rect = { 0 };
	_rect.x = 100 + x;
	_rect.y = 100 + y;
	_rect.w = 100;
	_rect.h = 100;
	SDL_RenderFillRect(m_Renderer, &_rect);
	SDL_RenderPresent(m_Renderer);

}

void Engine::Engine::Exit()
{
	ShutDown();
}

void Engine::Engine::ShutDown()
{
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;

	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;

	SDL_Quit();

	m_IsRunning = false;
}
