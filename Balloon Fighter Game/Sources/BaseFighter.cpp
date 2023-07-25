#include "BaseFighter.h"
#include "CAnimation.h"
#include "CPhysics.h"
#include "Object.h"
#include "CController.h"
#include "CCollider.h"
#include "BoxCollider.h"
#include <vector>
using namespace TomNook;


BaseFighter::~BaseFighter()
{
}

void BaseFighter::Float(int direction)
{

	if (BalloonsLeft == 2)
	{
		m_Animator->Play("Flap2", false);
	}
	else
	{
		m_Animator->Play("Flap1", false);
	}

	Engine::Get().Audio().PlaySFX(FlapSound);
	float _CurVelY = m_Entity->GetComponent<CPhysics>()->GetVelY();
	m_Entity->GetComponent<CPhysics>()->SetVelY(_CurVelY - 8.0f, false);
	float _CurVelX = m_Entity->GetComponent<CPhysics>()->GetVelX();


	m_Entity->GetComponent<CPhysics>()->SetVelX(_CurVelX += (10.0f * direction));
}

void BaseFighter::PopBalloon()
{
	BalloonsLeft--;
	if (BalloonsLeft <= 0)
	{
		OnDeath();
	}
}



void BaseFighter::Start()
{
	(*m_Entity->Size()) = Vector2{ 24,24 };
	m_Entity->SetTag("Bouncy");
	FlapSound = Engine::Get().Audio().LoadSound("./Assets/Sounds/Flap.wav");

	m_Animator = m_Entity->AddComponent<CAnimation>();

	CPhysics* _physics = m_Entity->AddComponent<CPhysics>();
	_physics->SetGravity(true);
	_physics->OnCollision.AddListener(this);

	m_Entity->AddComponent<CCollider>();
	BoxCollider* TempBox = new BoxCollider(m_Entity->GetComponent<CCollider>());

	TempBox->Corners =
	{
		Vector2{static_cast<int>(m_Entity->X()+4),static_cast<int>(m_Entity->Y()) },
		Vector2{static_cast<int>(m_Entity->X() + m_Entity->Size()->x)-4,static_cast<int>(m_Entity->Y() + m_Entity->Size()->y)}
	};

	m_Entity->GetComponent<CCollider>()->SetCollider(TempBox);
	TempBox = nullptr;
	m_Entity->GetComponent<CCollider>()->OnCollision.AddListener(_physics);




}

void BaseFighter::Destroy()
{
	BalloonBox = nullptr;
}

void BaseFighter::OnNotify(const CollisionInfo& value)
{
	BalloonBox = new BoxCollider(m_Entity->GetComponent<CCollider>());
	BalloonBox->Corners =
	{
		Vector2{static_cast<int>(m_Entity->X() + 2),static_cast<int>(m_Entity->Y() - 2) },
		Vector2{static_cast<int>(m_Entity->X() + 22),static_cast<int>(m_Entity->Y() + 8)}
	};
	if (BalloonBox->CollideWithBox(static_cast<BoxCollider*>(value.Aggressor)).Hit)
	{
		if (value.OtherObject->GetTag("Poke"))
		{
			PopBalloon();
		}
	}
	Engine::Get().m_Physics->RemoveCollider(BalloonBox);
	delete BalloonBox;
	BalloonBox = nullptr;
}








