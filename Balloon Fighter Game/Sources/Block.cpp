#include "Block.h"
#include "CAtlas.h"
#include "CPhysics.h"
#include "Object.h"
#include "CController.h"
#include "CCollider.h"
#include "BoxCollider.h"
Block::Block()
{
	m_Block = Engine::Get().m_World->Create("Wall1");
	(*m_Block->Size()) = Vector2{ 48,48 };
	m_Block->Position()[0] = 150;
	m_Block->Position()[1] = 100;
	m_Block->AddComponent<CAtlas>();
	m_Block->GetComponent<CAtlas>()->LoadTexture("./Assets/TestBlock.png");
	m_Block->GetComponent<CAtlas>()->AddFrame("one", 0, 0, 48, 48);
	m_Block->GetComponent<CAtlas>()->SetFrame("one");
	CCollider* _collider = m_Block->AddComponent<CCollider>();
	TempBox = new BoxCollider(_collider);
	TempBox->Corners =
	{
		Vector2{static_cast<int>(m_Block->X()),static_cast<int>(m_Block->Y()) },
		Vector2{static_cast<int>(m_Block->X() + m_Block->Size()->x),static_cast<int>(m_Block->Y() + m_Block->Size()->y)}
	};
	_collider->SetCollider(TempBox);
}

Block::~Block()
{
	if (m_Block != nullptr)
	{
		m_Block = nullptr;
	}
	if (TempBox != nullptr)
	{
		TempBox = nullptr;
	}
}
