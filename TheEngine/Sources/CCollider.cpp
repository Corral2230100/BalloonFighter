#pragma once
#include "CCollider.h"
#include "Colliders.h"

TomNook::CCollider::~CCollider()
{
	if (m_Collider != nullptr)
	{
		delete m_Collider;
		m_Collider = nullptr;
	}
	
}
void TomNook::CCollider::SetCollider(Collider* collider)
{
	m_Collider = collider;
	Engine::Get().m_Physics->AddCollider(collider);
}

void TomNook::CCollider::Update()
{
	if (m_Collider != nullptr)
	{
		m_Collider->UpdatePoints();
		CollisionInfo _info = Engine::Get().m_Physics->CheckCollisions(m_Collider);
		if (_info.Hit)
		{
 			OnCollision.Invoke(_info);
		}
	}
}

void TomNook::CCollider::Start()
{  

}

void TomNook::CCollider::Destroy()
{

}
