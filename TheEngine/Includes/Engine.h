#pragma once
#include <string>
#include "Object.h"
#include "IInput.h"
#include "IGraphics.h"
struct SDL_Window;
struct SDL_Renderer;

namespace Engine
{
	class Engine final
	{
	public:
		bool Init(const std::string& Title, int Width, int Height);
		void Start();
		void Exit();

		IInput& Input() const { return *m_Input; }
	private:
		IInput* m_Input = nullptr;
		IGraphics* m_Graphics = nullptr;
		IGraphics* m_Graphics = nullptr;
		void ProcessInput();
		void Update(float dt);
		void Render(float dt,float LagCorrection);
		void ShutDown();
		Object* Test;
	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;
		SDL_Window* m_Window = nullptr;
		SDL_Renderer* m_Renderer = nullptr;
	};
}