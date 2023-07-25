#pragma once
#include "CAtlas.h"
#include <vector>
namespace TomNook
{
	class CAnimation : public CAtlas , public IUpdateable
	{
	public:
		CAnimation(Object* parent) : CAtlas(parent)
		{
		};
		virtual void Draw() override;
		virtual void Update() override;
		void InitAnimation(std::string path, int width, int height);
		void AddClip(const std::string& name, std::vector<int> frameindexes, float delay);
		void Stop();
		void Play(const std::string& name,bool loop);
	private:
		bool m_Loop = false;
		bool m_Playing = false;
		float m_TimeElapsed = 0.0f;
		int m_Index = 0;
		int m_AnimationLength = 0;
		int m_FrameCount = 0;
		int m_Width = 0;
		int m_Height = 0;
		std::string m_CurrentAnim;
		std::map<std::string, std::pair<std::vector<int>, float>> m_AnimationClips;
		std::vector<RectI> m_Frames;


	};
}