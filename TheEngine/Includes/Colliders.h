#pragma once
#include "CCollider.h"
namespace TomNook
{
	class SphereCollider;
	class BoxCollider;
	class Collider
	{
	public:
		Collider(CCollider* parent);
		virtual ~Collider() { if (m_Parent != nullptr) { m_Parent = nullptr; } };
		void Collide(CollisionInfo info);
		virtual CollisionInfo CollideWithBox(BoxCollider* other) = 0;
		virtual CollisionInfo CollideWithSphere(SphereCollider* other) = 0;
		virtual void UpdatePoints() = 0;
		CCollider* m_Parent = nullptr;
		CollisionMode GetMode() { return m_Mode; };
		CollisionMode SetMode(CollisionMode newmode) { m_Mode = newmode; };
	protected:
		CollisionMode m_Mode = CollisionMode::Active;
	};




	//class LineCollider : public Collider
	//{
	//public:
	//	LineCollider(CCollider* parent) : Collider(parent)
	//		, PointA({0,0})
	//		, PointB({0,0})
	//	{
	//	};
	//	virtual ~LineCollider() = default;
	//	Vector2 PointA;
	//	Vector2 PointB;
	//};
}