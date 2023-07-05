#pragma once
#include <string>
#include <vector>
#include "IInput.h"
#include "IGraphics.h"
#include "IAudio.h"
#include "WorldService.h"
#include "ILogger.h"
#include "PhysicsService.h"

namespace TomNook
{

	class Engine final
	{
	public:
		static Engine& Get() 
		{ 
			static Engine* m_Instance;
			if (m_Instance == nullptr)
			{
				m_Instance = new Engine();
			}
			return *m_Instance;
		}
		const float& DeltaTime() { return m_dt; };
		bool Init(const std::string& Title, int Width, int Height);
		void Start();
		void Exit();
		WorldService* m_World = nullptr;
		PhysicsService* m_Physics = nullptr;
		IInput& Input() const { return *m_Input; }
		ILogger& Logger() const { return *m_Logger; }
		IGraphics& Graphics() const { return *m_Graphics; }
		IAudio& Audio() const { return *m_AudioService; }
		
	private:
		IInput* m_Input = nullptr;
		ILogger* m_Logger = nullptr;
		IGraphics* m_Graphics = nullptr;
		IAudio* m_AudioService = nullptr;
		void ProcessInput();
		void Update(float dt);
		void Render(float dt,float LagCorrection);
		void ShutDown();
		size_t _TestText = -1;
		size_t _Goodtime = -1;
	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;
		float m_dt = 0.0f;
		
	};
}