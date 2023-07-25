#pragma once
#include "Component.h"
#include "IUpdateable.h"
#include "IDrawable.h"
#include <string>
using namespace TomNook;

class Menu : public Component, public IDrawable, public IUpdateable
{

public:
	Menu(Object* parent) : Component(parent) {};
	~Menu();
	// Inherited via Component
	virtual void Start() override;
	virtual void Destroy() override;

	// Inherited via IDrawable
	virtual void Draw() override;

	// Inherited via IUpdateable
	virtual void Update() override;

private:
	int MenuIndex = 0;
	size_t m_TextFont = -1;
	size_t m_Music = -1;
	size_t m_Ding = -1;
	Object* m_Pointer = nullptr;
	std::string MenuOptions[2] = { "1 Player Game", "Other Thing" };
	void Up();
	void Down();
	void Select();

	const int m_MenuStep = 24;
	const int m_MenuStartY = 136;
};