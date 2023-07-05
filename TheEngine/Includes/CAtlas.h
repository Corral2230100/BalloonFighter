#pragma once
#include "CSprite.h"

namespace TomNook
{
	class CAtlas : public CSprite
	{
	public:
		CAtlas(Object* parent) : CSprite(parent)
		{
		};
		void AddFrame(const std::string& name, int x, int y, int w, int h);
		void SetFrame(const std::string& name);
		void SetFile(const std::string path);
		// Hérité via IDrawable
		virtual void Draw() override;
	private:
		std::map<std::string, RectI> m_FrameMap;

	};
}

