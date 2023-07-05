#include "SDLInput.h"
#include "SDL.h"
#include "stdio.h"
#include "Engine.h"
#include <cstring>


SDLInput::SDLInput()
{

	m_KeyStates = const_cast <unsigned char*> (SDL_GetKeyboardState(&m_StateSize));
	m_PreviousKeyStates = new unsigned char[m_StateSize];
}

SDLInput::~SDLInput()
{
	delete m_PreviousKeyStates;
	m_PreviousKeyStates = nullptr;
}


void SDLInput::Update()
{
		if (m_KeyStates != nullptr)
		{
			memcpy(m_PreviousKeyStates, m_KeyStates,m_StateSize);
		}
		SDL_Event _event;
		while (SDL_PollEvent(&_event))
		{
			m_KeyStates = const_cast <unsigned char*> (SDL_GetKeyboardState(nullptr));
			switch (_event.type)
			{
			case SDL_QUIT:
				Engine::Get().Exit();
				return;
				break;
			}
			
		}

		
}

bool SDLInput::IsKeyUp(EKey key)
{
	if (m_KeyStates[static_cast<int>(key)] == 0)
	{
		if (m_PreviousKeyStates != nullptr && m_PreviousKeyStates[static_cast<int>(key)] == 1)
		{

		}
		return true;
	}
	return false;
}

bool SDLInput::IsKeyHeld(EKey key)
{
	if (m_KeyStates[static_cast<int>(key)] == 1)
	{
		return true;
	}
	return false;
}



bool SDLInput::IsKeyDown(EKey key)
{
	if (m_KeyStates[static_cast<int>(key)] == 1 )
	{
		if (m_PreviousKeyStates != nullptr && m_PreviousKeyStates[static_cast<int>(key)] == 0)
		{
			return true;
		}

	}
	return false;
}


bool SDLInput::IsMouseButtonDown(EButton button)
{
	return false;
}


void SDLInput::GetMousePosition(int* m_x, int* m_y)
{

}
