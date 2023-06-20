#pragma once
#include "Component.h"
#include "IUpdateable.h"
#include "IDrawable.h"

class CSprite : public Component ,public IUpdateable, public IDrawable
{
public:
	CSprite() = default;
	// H�rit� via IUpdateable
	virtual void Update() override;
	// H�rit� via IDrawable
	virtual void Draw() override;

	// H�rit� via Component
	virtual void Start() override;
	virtual void Destroy() override;


	// Self
	void LoadTexture(std::string AssetPath);

private:
	size_t m_Id = 0;

	int m_Index = 0;

	int m_SizeX = 32;
	int m_SizeY = 32;

	int m_OffsetX = 8;
	int m_OffsetY = 8;

	int m_GapX = 0;
	int m_GapY = 1;

	Flip m_Flip = { false,false };
	Color m_Color = { 255,255,255,255 };
	double m_Angle = 0;




};