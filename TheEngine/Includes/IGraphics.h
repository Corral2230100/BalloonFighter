#pragma once
#include <vector>
namespace Engine
{
	class IGraphics
	{
	public:
		virtual void Draw(float dt, float LagCorrection) = 0;
	};
}