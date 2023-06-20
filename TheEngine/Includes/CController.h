#pragma once
#include "Component.h"
#include "IUpdateable.h"



class CController : public Component, public IUpdateable
{
public:
	virtual ~CController();
	// Hérité via Component
	virtual void Start() override;
	virtual void Destroy() override;
	// Hérité via IUpdateable
	virtual void Update() override;
private:
	

};