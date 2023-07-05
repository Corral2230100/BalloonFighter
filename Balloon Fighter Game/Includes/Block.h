#include "Engine.h"
#include "CSprite.h"
#include "CController.h"
#include "CPhysics.h"
#include "BoxCollider.h"
using namespace TomNook;

class Block
{
public:
	Block();
	~Block();
private:
	Object* m_Block = nullptr;
	BoxCollider* TempBox = nullptr;
};