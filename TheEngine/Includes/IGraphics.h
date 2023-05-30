#pragma once
#include "SDL.h"

namespace Engine
{
	class IGraphics
	{
	public:
		virtual void Draw(SDL_Renderer* Renderer, float dt, float LagCorrection) = 0;
	private:

	};
}