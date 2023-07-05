#include "Colliders.h"

TomNook::Collider::Collider(CCollider* parent)
	:m_Parent(parent)
{
}

void TomNook::Collider::Collide(CollisionInfo info)
{
	m_Parent->OnCollision.Invoke(info);
}
