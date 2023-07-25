#include "PhysicsService.h"
#include "Colliders.h"
#include "BoxCollider.h"
#include "SphereCollider.h"
#include "DataTypes.h"
using namespace TomNook;
PhysicsService::~PhysicsService()
{
	for (Collider* collider : m_Colliders)
	{
		if (collider != nullptr)
		{
			collider = nullptr;
		}

	}
	m_Colliders.clear();
}

CollisionInfo PhysicsService::CheckCollisions(Collider* collider)
{
	CollisionInfo _info = {};
	for (int i = 0; i < m_Colliders.size(); i++)
	{
		if (collider != m_Colliders[i])
		{
			_info = SolveCollisions(collider, m_Colliders[i]);
			if (_info.Hit) break;
		}	
	}
	return _info;
}

void TomNook::PhysicsService::AddCollider(Collider* collider)
{
	m_Colliders.emplace_back(collider);
}

void TomNook::PhysicsService::RemoveCollider(Collider* collider)
{
	int i = 0;
	for (Collider* collideriter : m_Colliders)
	{
		if (collideriter == collider)
		{
			m_Colliders.erase(m_Colliders.begin() + i);
		}
		i++;
	}
}

CollisionInfo PhysicsService::SolveCollisions(Collider* collider1, Collider* collider2)
{
	CollisionInfo _info{};
	if (collider1->GetMode() == CollisionMode::Disabled) return _info;
	BoxCollider* _box = dynamic_cast<BoxCollider*>(collider2);

	if (_box != nullptr)
	{
		_info = collider1->CollideWithBox(_box);
	}

	return _info;
}
