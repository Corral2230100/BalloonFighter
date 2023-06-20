#include "SDLInput.h"
#include "SDL.h"
#include "stdio.h"
#include "Engine.h"
/// <summary>
/// Registers events and inputs from the SDL library at runtime
/// </summary>
void SDLInput::Update()
{
		SDL_Event _event;

		while (SDL_PollEvent(&_event))
		{
			switch (_event.type)
			{
			case SDL_QUIT:
				Engine::Engine::Get().Exit();
				break;
			}
		}
			m_KeyStates = const_cast <unsigned char*> (SDL_GetKeyboardState(nullptr));
}

/// <summary>
/// Checks the state of a given key
/// </summary>
/// <param name="key"></param>
/// <returns></returns>
bool SDLInput::IsKeyDown(EKey key)
{
	
	if (m_KeyStates[static_cast<int>(key)] == 1)
	{
		return true;
	}
	return false;
}

/// <summary>
/// Checks the state of a mouse button
/// </summary>
/// <param name="button"></param>
/// <returns></returns>
bool SDLInput::IsMouseButtonDown(EButton button)
{
	return false;
}

/// <summary>
/// Checks the mouse's position
/// </summary>
/// <param name="m_x"></param>
/// <param name="m_y"></param>
void SDLInput::GetMousePosition(int* m_x, int* m_y)
{

}
