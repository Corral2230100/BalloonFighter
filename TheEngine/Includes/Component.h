#pragma once
#include "Engine.h"

using namespace Engine2;


	class Component
	{
	public:
		Component() = default;
		virtual ~Component() = default;
		Component(Object* parent)
		{
			m_Entity = parent;
		};
		virtual void Start() = 0;
		virtual void Destroy() = 0;
	protected:
		Object* m_Entity = nullptr;
		IInput& GetInput() { return Engine2::Engine::Get().Input();};
	};



