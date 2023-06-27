#pragma once
#include "Component.h"
#include "IUpdateable.h"

namespace TomNook
{
	class CController : public Component, public IUpdateable
	{
	public:
		CController(Object* parent) : Component(parent)
		{
		};
		virtual ~CController();
		// Hérité via Component
		virtual void Start() override;
		virtual void Destroy() override;
		// Hérité via IUpdateable
		virtual void Update() override;
	private:


	};
}

