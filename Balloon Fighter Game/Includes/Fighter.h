#include "Engine.h"
#include "CSprite.h"

using namespace Engine2;
class Fighter 
{
public:
	Fighter() 
	{
		Object* FighterTest = Engine::Get().m_World->Create("Fighter1");
		FighterTest->AddComponent<CSprite>();
		CSprite& _tmp = FighterTest->GetComponent<CSprite>();
		_tmp.LoadTexture("./Assets/Fighter.png");
	}
private:

};