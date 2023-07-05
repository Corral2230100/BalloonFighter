#pragma once
#include "Component.h"
#include "IUpdateable.h"
#include "IDrawable.h"

namespace TomNook
{
	class CSprite : public Component, public IDrawable
	{
	public:
		CSprite(Object* parent) : Component(parent)
		{
		};
		// Hérité via IDrawable
		virtual void Draw() override;

		// Hérité via Component
		virtual void Start() override;
		virtual void Destroy() override;


		// Self
		void LoadTexture(std::string AssetPath);
		void SetFlip(Flip newflip) { m_Flip = newflip; };
	protected:
		size_t m_Id = 0;
		RectI m_SpriteSource{};

		Flip m_Flip = { false,false};
		Color m_Color = { 255,255,255,255 };
		double m_Angle = 0;




	};
}
