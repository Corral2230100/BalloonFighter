#pragma once
#include <string>
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
	private:
		void ProcessInput();
		void Update(float dt);
		void Render();
		void ShutDown();

	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;
		SDL_Window* m_Window = nullptr;
		SDL_Renderer* m_Renderer = nullptr;
	};
}