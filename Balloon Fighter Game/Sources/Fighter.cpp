#include "Fighter.h"
#include "CSprite.h"
#include "CPhysics.h"
#include "Object.h"

using namespace TomNook;

Fighter::Fighter()
:m_Inputs(Engine::Get().Input())
{
	Object* FighterTest = Engine::Get().m_World->Create("Fighter1");
	CSprite* _sprite = FighterTest->AddComponent<CSprite>();
	_sprite->LoadTexture("./Assets/Fighter.png");
	CPhysics* _physics = FighterTest->AddComponent<CPhysics>();
	_physics->SetGravity(true);
}