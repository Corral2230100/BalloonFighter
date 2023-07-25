#include "BoxCollider.h"
#include "SphereCollider.h"
#include "Object.h"
#include "CPhysics.h"
using namespace TomNook;
CollisionInfo BoxCollider::CollideWithBox(BoxCollider* other)
{
	CollisionInfo _info;
	_info.OtherObject = other->m_Parent->GetParent();
	_info.Victim = this;
	_info.Aggressor = other;
	std::vector<Vector2> _rect1 = Corners;
	std::vector<Vector2> _rect2 = other->Corners;



	CPhysics* _physics = m_Parent->GetParent()->GetComponent<CPhysics>();
	if (_physics != nullptr)
	{
			int _x = static_cast<int>(_physics->GetVelX() * Engine::Get().DeltaTime());
			int _y = static_cast<int>(_physics->GetVelY() * Engine::Get().DeltaTime());

			if (_rect2[0].x < _rect1[1].x + _x && _rect2[1].x > _rect1[0].x + _x)
			{
				if (_rect2[0].y < _rect1[1].y && _rect2[1].y > _rect1[0].y)
				{
					_info.CollisionPoint = { 0,0 };
					_info.Hit = true;
					_info.CollisionDir.x = 1;
				}
			}
			if (_rect2[0].x < _rect1[1].x && _rect2[1].x > _rect1[0].x)
			{
				if (_rect2[0].y < _rect1[1].y + _y && _rect2[1].y > _rect1[0].y + _y)
				{
					_info.CollisionPoint = { 0,0 };
					_info.Hit = true;
					_info.CollisionDir.y = 1;
				}
			}
	}
	else
	{
		if (_rect2[0].x < _rect1[1].x && _rect2[1].x > _rect1[0].x)
		{
			if (_rect2[0].y < _rect1[1].y && _rect2[1].y > _rect1[0].y)
			{
				_info.CollisionPoint = { 0,0 };
				_info.Hit = true;
			}
		}
	}
	return _info;
}

CollisionInfo BoxCollider::CollideWithSphere(SphereCollider* other)
{
	CollisionInfo _info;
	_info.OtherObject = other->m_Parent->GetParent();
	return _info;
}

void BoxCollider::UpdatePoints()
{
	int _w = Corners[1].x - Corners[0].x;
	int _h = Corners[1].y - Corners[0].y;
	int _x = static_cast<int>(m_Parent->GetParent()->X());
	int _y = static_cast<int>(m_Parent->GetParent()->Y());
	Corners = { Vector2{_x,_y},Vector2{_x + _w,_y + _h} };
}

void TomNook::BoxCollider::Init()
{
	CPhysics* _physics = m_Parent->GetParent()->GetComponent<CPhysics>();
	if (_physics != nullptr)
	{
		OnCollide.AddListener(_physics);
	}
}

