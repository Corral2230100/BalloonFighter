#include "SDLInput.h"
#include "SDL.h"
#include "stdio.h"
void SDLInput::Update()
{
		SDL_Event _event;

		while (SDL_PollEvent(&_event))
		{
			switch (_event.type)
			{
			case SDL_QUIT:
				//Exit();
				break;
			}
		}
			m_KeyStates = const_cast <unsigned char*> (SDL_GetKeyboardState(nullptr));
}

bool SDLInput::IsKeyDown(Engine::EKey key)
{
	
	if (m_KeyStates[static_cast<int>(key)] == 1)
	{
		return true;
	}
	return false;
}

bool SDLInput::IsMouseButtonDown(Engine::EButton button)
{
	return false;
}

void SDLInput::GetMousePosition(int* m_x, int* m_y)
{

}
