#include "SphereCollider.h"
#include "BoxCollider.h"
#include "CPhysics.h"
using namespace TomNook;
CollisionInfo SphereCollider::CollideWithBox(BoxCollider* other)
{
	CollisionInfo _info;
	_info.OtherObject = other->m_Parent->GetParent();



	return _info;
}
void TomNook::SphereCollider::UpdatePoints()
{
}

CollisionInfo SphereCollider::CollideWithSphere(SphereCollider* other)
{
	CollisionInfo _info;
	_info.OtherObject = other->m_Parent->GetParent();
	float _dy = static_cast<float>(Center.y) - static_cast<float>(other->Center.y);
	float _dx = static_cast<float>(Center.x) - static_cast<float>(other->Center.x);
	if (sqrt(_dy * _dy) + (_dx * _dx) < Radius)
	{
		_info.CollisionPoint = { 0,0 };
		_info.Hit = true;
		
	}
	return _info;
}
