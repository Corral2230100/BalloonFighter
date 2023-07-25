#pragma once
#include "Engine.h"
#include "CSprite.h"
#include "CController.h"
#include "Component.h"
#include "BoxCollider.h"
#include "CAnimation.h"
using namespace TomNook;

class BaseFighter : public Component, public Observer<CollisionInfo>
{
public:
	BaseFighter(Object* parent) : Component(parent) {};
	~BaseFighter();

	/// <summary>
	/// Sets up the Fighter and his components.
	/// </summary>
	virtual void Start() override;
	virtual void Destroy() override;
	virtual void OnNotify(const CollisionInfo& value) override;
protected:
	/// <summary>
	/// Does the flap animation and gives the little momentum boost based on direction parameter.
	/// </summary>
	/// <param name="direction"></param>
	void Float(int direction);
	void PopBalloon();
	BoxCollider* BalloonBox = nullptr;
	CAnimation* m_Animator = nullptr;
	int BalloonsLeft = 2;
	size_t FlapSound = -1;
private:



};