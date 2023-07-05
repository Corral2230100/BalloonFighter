#include "..\Includes\CAtlas.h"

void TomNook::CAtlas::AddFrame(const std::string& name, int x, int y, int w, int h)
{
	if (m_FrameMap.count(name) > 0) return;
	RectI _rect = RectI{ x,y,w,h };
	m_FrameMap.emplace(name, _rect);
}

void TomNook::CAtlas::SetFrame(const std::string& name)
{
	if (m_FrameMap.count(name) == 0) return;
	m_SpriteSource = m_FrameMap[name];
}

void TomNook::CAtlas::SetFile(const std::string path)
{
	CSprite::LoadTexture(path);
}

void TomNook::CAtlas::Draw()
{
	CSprite::Draw();
}
