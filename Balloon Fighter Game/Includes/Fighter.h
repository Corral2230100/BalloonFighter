#include "Engine.h"
#include "CSprite.h"
#include "CController.h"
#include "CPhysics.h"
#include "BoxCollider.h"
using namespace TomNook;
class Fighter
{
public:
	Fighter();
	~Fighter();
	void Float();
private:
	Object* m_Fighter;
	BoxCollider* TempBox = nullptr;
};