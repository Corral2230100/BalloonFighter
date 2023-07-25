#pragma once
#include "BaseFighter.h"
#include "IUpdateable.h"

using namespace TomNook;

class EnnemyFighter : public BaseFighter , public IUpdateable
{
public:
	EnnemyFighter(Object * parent) : BaseFighter(parent) {};
	~EnnemyFighter();


	/// From BaseFighter
	virtual void Start() override;
	virtual void Destroy() override;
	// Hérité via IUpdateable
	virtual void Update() override;
private:

	Object* m_Player = nullptr;
	const float ActionCooldown = 0.1f;
	float ActionTimer = 0.0f;


	// Hérité via BaseFighter
	virtual void OnDeath() override;



};