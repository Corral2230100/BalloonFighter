#pragma once
struct SDL_Renderer;
#include "string"
#include <IGraphics.h>
namespace Engine
{
	class Object
	{
	public:
		Object(const std::string& name);
		virtual ~Object();
		void Update(float dt);
		void Draw(IGraphics* Renderer, float LagCorrection, float dt);
		void SetVelX(float Vel);
		void SetVelY(float Vel);
		void SetPosition(float NewX, float NewY);
		void SetActive(bool Setting);
		std::string GetName() { return m_Name; }
	private:
		/// put this in a struct later
		float m_x = 0;
		float m_y = 0;
		float VelX = 0;
		float VelY = 0;
		float m_Active = true;
		std::string m_Name;

	};
}


