#pragma once
#include "Component.h"
#include "IUpdateable.h"
#include "IDrawable.h"
#include "IObserver.h"
using namespace TomNook;

class MainGame : public Component, public IUpdateable, public IDrawable, public Observer<int>
{
public:
	MainGame(Object* parent) : Component(parent) {};
	~MainGame();
	int GetScore() { return Score; };
	// Hérité via Component
	virtual void Start() override;
	virtual void Destroy() override;

	// Hérité via IUpdateable
	virtual void Update() override;
	// Hérité via IDrawable
	virtual void Draw() override;
private:
	int Score = 0;
	size_t m_TextFont = -1;

	// Hérité via Observer
	virtual void OnNotify(const int& value) override;
};