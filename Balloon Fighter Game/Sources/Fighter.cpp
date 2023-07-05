#include "Fighter.h"
#include "CAnimation.h"
#include "CPhysics.h"
#include "Object.h"
#include "CController.h"
#include "CCollider.h"
#include "BoxCollider.h"
using namespace TomNook;

Fighter::Fighter()
{
	m_Fighter = Engine::Get().m_World->Create("Fighter1");
	(*m_Fighter->Size()) = Vector2{ 24,24 };
	m_Fighter->AddComponent<CAnimation>();
	m_Fighter->GetComponent<CAnimation>()->InitAnimation("./Assets/FighterOne.png", 24, 24);
	int _frames[] = { 1,2,3,4,5 };
	m_Fighter->GetComponent<CAnimation>()->AddClip("Flap", _frames, 0.1f);


	CPhysics* _physics = m_Fighter->AddComponent<CPhysics>();
	_physics->SetGravity(true);
	 m_Fighter->AddComponent<CController>();
	std::function<void()> _func = std::bind(&Fighter::Float, this);
	m_Fighter->GetComponent<CController>()->m_InputBindingsDown.emplace(EKey::EKEY_SPACE, _func);
	m_Fighter->AddComponent<CCollider>();
	TempBox = new BoxCollider(m_Fighter->GetComponent<CCollider>());
	TempBox->Corners =
	{
		Vector2{static_cast<int>(m_Fighter->X()),static_cast<int>(m_Fighter->Y()) },
		Vector2{static_cast<int>(m_Fighter->X() + m_Fighter->Size()->x),static_cast<int>(m_Fighter->Y() + m_Fighter->Size()->y)}
	};
	m_Fighter->GetComponent<CCollider>()->SetCollider(TempBox);
	m_Fighter->GetComponent<CCollider>()->OnCollision.AddListener(_physics);
}
Fighter::~Fighter()
{

	if (TempBox != nullptr)
	{
		TempBox = nullptr;
	}
	if (m_Fighter != nullptr)
	{
		m_Fighter = nullptr;
	}
}
void Fighter::Float()
{
	CAnimation* _animator = m_Fighter->GetComponent<CAnimation>();
	_animator->Play("Flap", false);

	IInput& Inputs = m_Fighter->GetComponent<CController>()->m_Inputs;
	float _CurVelY = m_Fighter->GetComponent<CPhysics>()->GetVelY();
	m_Fighter->GetComponent<CPhysics>()->SetVelY(_CurVelY - 16.0f, false);
	float _CurVelX = m_Fighter->GetComponent<CPhysics>()->GetVelX();
	float _dir = 0.0f;
	if (Inputs.IsKeyHeld(EKey::EKEY_A) && !Inputs.IsKeyHeld(EKey::EKEY_D))
	{
		_dir = -1.0f;
		_animator->SetFlip(Flip{ false,false });
	}
	else if (Inputs.IsKeyHeld(EKey::EKEY_D) && !Inputs.IsKeyHeld(EKey::EKEY_A))
	{
		_dir = 1.0f;
		_animator->SetFlip(Flip{ true,false });
	}
	m_Fighter->GetComponent<CPhysics>()->SetVelX(_CurVelX += (16.0f * _dir));
}


