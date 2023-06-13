#pragma once
#include <Object.h>

namespace Engine
{
	class Component
	{
	public:
		virtual ~Component() = default;
		Component(Object* parent)
		{
		};
		virtual void Start() {};
		virtual void Destroy() {};
	protected:
		Object *m_Entity = nullptr;
	};
}


