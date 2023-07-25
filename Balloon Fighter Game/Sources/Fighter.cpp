#include "Fighter.h"
#include "CAnimation.h"
#include "CPhysics.h"
#include "Object.h"
#include "CController.h"
#include "CCollider.h"
#include "BoxCollider.h"
#include "BaseFighter.h"
#include <vector>

Fighter::~Fighter()
{
}

void Fighter::Start()
{
	BaseFighter::Start();
	m_Entity->SetTag("Poke");
	m_Entity->AddComponent<CController>();
	std::function<void()> _func = std::bind(&Fighter::FloatInput, this);
	m_Entity->GetComponent<CController>()->m_InputBindingsDown.emplace(EKey::EKEY_SPACE, _func);


	m_Animator->InitAnimation("./Assets/FighterOne.png", 24, 24);

	std::vector<int> _frames = { 0,1,2,3,4 };
	m_Animator->AddClip("Flap2", _frames, 0.08f);

	_frames = {6,7,8,9 };
	m_Animator->AddClip("Flap1", _frames, 0.08f);


}

void Fighter::Destroy()
{
	BaseFighter::Destroy();
}


void Fighter::FloatInput()
{
	int _dir = 0;
	IInput& Inputs = m_Entity->GetComponent<CController>()->m_Inputs;
	if (Inputs.IsKeyHeld(EKey::EKEY_A) && !Inputs.IsKeyHeld(EKey::EKEY_D))
	{
		_dir = -1;
		m_Animator->SetFlip(Flip{ false,false });
	}
	else if (Inputs.IsKeyHeld(EKey::EKEY_D) && !Inputs.IsKeyHeld(EKey::EKEY_A))
	{
		_dir = 1;
		m_Animator->SetFlip(Flip{ true,false });
	}
	Float(_dir);
}

void Fighter::OnDeath()
{

}
