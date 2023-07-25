#pragma once
#include "Colliders.h"
namespace TomNook
{
	class BoxCollider : public Collider
	{
	public:
		BoxCollider(CCollider* parent) : Collider(parent) { Init(); };

		~BoxCollider() = default;
		std::vector<Vector2> Corners = {Vector2{0,0}};
		// Inherited via Collider
		virtual CollisionInfo CollideWithBox(BoxCollider* other) override;
		virtual CollisionInfo CollideWithSphere(SphereCollider* other) override;
		virtual void UpdatePoints() override;
		Subject<CollisionInfo> OnCollide;
		void Init();
	};
}
