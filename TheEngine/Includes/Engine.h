#pragma once
#include <string>
#include <vector>
#include "Object.h"
#include "IInput.h"
#include "IGraphics.h"
#include "WorldService.h"
#include "ILogger.h"


namespace Engine
{
	class Engine final
	{
	public:
		bool Init(const std::string& Title, int Width, int Height);
		void Start();
		void Exit();
		WorldService* m_World;
		IInput& Input() const { return *m_Input; }
	private:
		IInput* m_Input = nullptr;
		ILogger* m_Logger;
		IGraphics* m_Graphics = nullptr;
		void ProcessInput();
		void Update(float dt);
		void Render(float dt,float LagCorrection);
		void ShutDown();
		Object* Test;
	private:
		bool m_IsRunning = false;
		bool m_IsInit = false;
		
	};
}