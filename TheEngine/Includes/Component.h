#pragma once
#include "Engine.h"
#include "DataTypes.h"

namespace TomNook
{
	class Object;
	class IInput;
	class Component
	{
	public:
		virtual ~Component();
		Component(Object* parent)
		{
			m_Entity = parent;
		};
		virtual void Start() = 0;
		virtual void Destroy() = 0;
		Object* GetParent() { return m_Entity; };
	protected:
		Object* m_Entity = nullptr;
		IInput& GetInput() { return TomNook::Engine::Get().Input(); };
	};
}


