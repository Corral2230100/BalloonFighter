#include "Block.h"
#include "CAtlas.h"
#include "CPhysics.h"
#include "Object.h"
#include "CController.h"
#include "CCollider.h"
#include "BoxCollider.h"
Block::Block()
{

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
