#include "CSprite.h"
#include "Object.h"
using namespace TomNook;


void CSprite::Draw()
{
	RectF _dest = { m_Entity->X(),m_Entity->Y(),m_SpriteSource.w,m_SpriteSource.h};
	RectI _src = m_SpriteSource;
	// Commented in case i need it again but shouldn't need it after fixing the spritesheets.
	/*if (m_Flip.h == true)
	{
		_dest.x -= static_cast<float>(m_SpriteSource.w);
	}*/


	Engine::Get().Graphics().DrawTexture(m_Id, _src, _dest, m_Angle, m_Flip, m_Color);
	float _x = Engine::Get().Graphics().GetScreenSize().x;
	if (_dest.x + m_SpriteSource.w/2 > _x)
	{
		_dest.x -= _x;
		Engine::Get().Graphics().DrawTexture(m_Id, _src, _dest, m_Angle, m_Flip, m_Color);
	}
	else
	if (_dest.x - m_SpriteSource.w/2 < _x)
	{
		_dest.x += _x;
		Engine::Get().Graphics().DrawTexture(m_Id, _src, _dest, m_Angle, m_Flip, m_Color);  
	}

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
