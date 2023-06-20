#include "CController.h"
using namespace Engine2;

CController::~CController()
{
}

void CController::Start()
{
}

void CController::Destroy()
{
}

void CController::Update()
{
	if (GetInput().IsKeyDown(EKey::EKEY_H))
	{
		//m_AudioService->PlaySFX(_Goodtime);
	}
	/// test player controller---------------
	if (GetInput().IsKeyDown(EKey::EKEY_RIGHT) || GetInput().IsKeyDown(EKey::EKEY_D))
	{
		//TestCharacter->SetVelX(100);
	}
	else if (GetInput().IsKeyDown(EKey::EKEY_LEFT) || GetInput().IsKeyDown(EKey::EKEY_A))
	{
		//TestCharacter->SetVelX(-100);
	}
	else
	{
		//TestCharacter->SetVelX(0);
	}

	if (GetInput().IsKeyDown(EKey::EKEY_UP) || GetInput().IsKeyDown(EKey::EKEY_W))
	{
		//TestCharacter->SetVelY(-100);
	}
	else if (GetInput().IsKeyDown(EKey::EKEY_DOWN) || GetInput().IsKeyDown(EKey::EKEY_S))
	{
		//TestCharacter->SetVelY(100);
	}
	else
	{
		//TestCharacter->SetVelY(0);
	}
}
