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
		// H�rit� via Component
		virtual void Start() override;
		virtual void Destroy() override;
		// H�rit� via IUpdateable
		virtual void Update() override;
	private:


	};
}

