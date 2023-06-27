#pragma once
#include "Component.h"
#include "IUpdateable.h"

namespace TomNook
{
	class CPhysics : public Component, public IUpdateable
	{
	public:
		CPhysics(Object* parent) : Component(parent)
		{
		};
		void SetVelX(float Vel);
		void SetVelY(float Vel);
		float GetVelX() { return VelX; };
		float GetVelY() { return VelY; };
		void SetGravity(bool value) { UseGravity = value; };
		// Hérité via IUpdateable
		virtual void Update() override;

		// Hérité via Component
		virtual void Start() override;
		virtual void Destroy() override;
	private:
		float VelX = 0.0f;
		float VelY = 0.0f;
		float Drag = 0.0f;

		bool  UseGravity = false;
		float GravityForce = 5.0f;
		float GravityModifier = 0.0f;
		float GravityTimer = 0.0f;


	};
}
