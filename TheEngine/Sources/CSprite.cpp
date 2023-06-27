#include "CSprite.h"
#include "Object.h"
using namespace TomNook;
void CSprite::Update()
{

}

void CSprite::Draw()
{
	RectF _dest = { m_Entity->X(),m_Entity->Y(),m_SizeX,m_SizeY };
	RectI _src =
	{
		m_OffsetX + (m_SizeX - 1) * m_Index,
		m_OffsetY + (m_SizeY - 1) * m_Index,
		m_SizeX,
		m_SizeY
	};
	Engine::Get().Graphics().DrawTexture(m_Id, _src, _dest, m_Angle, m_Flip, m_Color);
}

void CSprite::LoadTexture(std::string AssetPath)
{
	m_Id = Engine::Get().Graphics().LoadTexture(AssetPath);
}

void CSprite::Start()
{

}

void CSprite::Destroy()
{
}
