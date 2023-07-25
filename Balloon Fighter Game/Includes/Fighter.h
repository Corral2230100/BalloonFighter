#pragma once
#include "Engine.h"
#include "CSprite.h"
#include "CController.h"
#include "Component.h"
#include "BoxCollider.h"
#include "CAnimation.h"
#include "BaseFighter.h"

using namespace TomNook;

class Fighter: public BaseFighter
{
public:
	Fighter(Object* parent) : BaseFighter(parent) {};
	~Fighter();
	

	/// From BaseFighter
	virtual void Start() override;
	virtual void Destroy() override;

private:
	/// <summary>
	/// Handle's the player's inputs before calling BaseFighter's Float.
	/// </summary>
	void FloatInput();


	// Hérité via BaseFighter
	virtual void OnDeath() override;

};