#pragma once
#include "Component.h"
#include "IUpdateable.h"
#include "IObserver.h"
#include "Subject.h"
namespace TomNook
{
	class CCollider;
	class CPhysics : public Component, public IUpdateable , public Observer<CollisionInfo>
	{
	public:
		CPhysics(Object* parent) : Component(parent)
		{
		};
		void SetVelX(float Vel);
		void SetVelY(float Vel);
		void SetVelY(float Vel, bool KeepGravity);
		float GetVelX() { return VelX; };
		float GetVelY() { return VelY; };
		float* YVelLimit() { return VelYCap; };
		float* XVelLimit() { return VelXCap; };
		void SetGravity(bool value) { UseGravity = value; };
		// Hérité via IUpdateable
		virtual void Update() override;

		// Hérité via Component
		virtual void Start() override;
		virtual void Destroy() override;
		virtual void OnNotify(const CollisionInfo& value) override;
		Subject<CollisionInfo> OnCollision;
		Subject<CollisionInfo> OnTrigger;
	private:


		template <typename T>
		T clip(const T& n, const T& lower, const T& upper) {
			return std::max(lower, std::min(n, upper));
		}
		float VelX = 0.0f;
		float VelXCap[2] = { -64.0f,64.0f };
		float VelY = 0.0f;
		float VelYCap[2] = { -64.0f,64.0f };
		float Drag = 0.0f;
		CollisionInfo m_Collision{};
		bool  UseGravity = false;
		float GravityForce = 25.0f;
		float GravityModifier = 0.0f;
		float GravityTimer = 0.0f;
		float LastPosition[2] = { 0,0 };





	};
}
