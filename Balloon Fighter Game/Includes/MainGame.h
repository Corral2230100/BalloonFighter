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
	// H�rit� via Component
	virtual void Start() override;
	virtual void Destroy() override;

	// H�rit� via IUpdateable
	virtual void Update() override;
	// H�rit� via IDrawable
	virtual void Draw() override;
private:
	int Score = 0;
	size_t m_TextFont = -1;

	// H�rit� via Observer
	virtual void OnNotify(const int& value) override;
};