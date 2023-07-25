#include "CAnimation.h"
#include <vector>


void TomNook::CAnimation::InitAnimation(std::string path, int width, int height)
{
	LoadTexture(path);
	int _w;
	int _h;
	Engine::Get().Graphics().GetTextureSize(m_Id, &_w, &_h);
	for (int y = 0; y < _h; y += height)
	{
		for (int x = 0; x < _w; x += height)
		{

			m_Frames.emplace_back(RectI{ x,y,width,height });
		}
	}
	m_SpriteSource = m_Frames[m_Index];
}

void TomNook::CAnimation::Draw()
{
	CSprite::Draw();
}

void TomNook::CAnimation::AddClip(const std::string& name, std::vector<int> frameindexes, float delay)
{
	std::pair<std::vector<int>, float> _pair(frameindexes, delay);
	m_AnimationClips.emplace(name, _pair);
}

void TomNook::CAnimation::Stop()
{
	m_Playing = false;
}

void TomNook::CAnimation::Play(const std::string& name, bool loop)
{
	if (m_AnimationClips.count(name) == 0) return;
	if (m_CurrentAnim == name && m_Playing)
	{
		m_Index = 0;
		return;
	}
	m_Loop = loop;
	m_CurrentAnim = name;
	std::pair<std::vector<int>, float> _clip = m_AnimationClips[name];
	m_Index = 0;
	m_AnimationLength = _clip.first.size()-1;
	m_SpriteSource = m_Frames[m_AnimationClips[m_CurrentAnim].first[m_Index]];
	m_TimeElapsed = _clip.second;
	m_Playing = true;
}

void TomNook::CAnimation::Update()
{
	if (!m_Playing) return;
	m_TimeElapsed -= Engine::Get().DeltaTime();
	if (m_TimeElapsed <= 0.0f)
	{
		m_Index += 1;
		if (m_Index > m_AnimationLength)
		{
			if (m_Loop)
			{
				m_Index = 0;
			}
			else
			{
				m_Playing = false;
				return;
			}
		}
		m_TimeElapsed = m_AnimationClips[m_CurrentAnim].second;
		m_SpriteSource = m_Frames[m_AnimationClips[m_CurrentAnim].first[m_Index]];
	}
}
