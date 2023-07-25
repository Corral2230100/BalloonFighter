#include "EnnemyFighter.h"
#include "Object.h"
EnnemyFighter::~EnnemyFighter()
{
}

void EnnemyFighter::Start()
{
	BaseFighter::Start();
	BalloonsLeft = 1;
	m_Animator->InitAnimation("./Assets/BadguyOne.png", 24, 24);
	m_Player = Engine::Get().m_World->FindObjectByName("Player");
	std::vector<int> _frames = {3,4,5};
	m_Animator->AddClip("Flap2", _frames, 0.08f);
	m_Animator->AddClip("Flap1", _frames, 0.08f);
}

void EnnemyFighter::Destroy()
{
}


void EnnemyFighter::Update()
{
	float _myX = m_Entity->Position()[0];
	float _PlayerX = m_Player->Position()[0];
	float _myY = m_Entity->Position()[1];
	float _PlayerY = m_Player->Position()[1];
	if (ActionTimer >= ActionCooldown)
	{
		ActionTimer = 0.0F;
		if (_myX > _PlayerX)
		{
			if (_myY > _PlayerY)
			{
				Float(-1);
				m_Animator->SetFlip(Flip{ false,false });
			}
		}
		else
		{
			if (_myY > _PlayerY)
			{
				Float(1);
				m_Animator->SetFlip(Flip{ true,false });
			}
		}
	}
	ActionTimer += Engine::Get().DeltaTime();
}

void EnnemyFighter::OnDeath()
{
	// no anim for now

	//add score
	OnDeathNotify.Invoke(300);
	Engine::Get().m_World->Remove(m_Entity);
}


