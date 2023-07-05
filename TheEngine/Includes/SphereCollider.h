#pragma once
#include "Colliders.h"

namespace TomNook
{
	class SphereCollider : public Collider
	{
	public:
		SphereCollider(CCollider* parent) : Collider(parent) {};
		virtual ~SphereCollider() = default;

		Vector2 Center{0,0};
		float Radius = 0.0f;

		// Inherited via Collider
		virtual CollisionInfo CollideWithSphere(SphereCollider* other) override;
		virtual CollisionInfo CollideWithBox(BoxCollider* other) override;

		virtual void UpdatePoints() override;
	};
}

