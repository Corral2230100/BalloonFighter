#pragma once
#include "Component.h"
#include "IUpdateable.h"



class CController : public Component, public IUpdateable
{
public:
	virtual ~CController();
	// H�rit� via Component
	virtual void Start() override;
	virtual void Destroy() override;
	// H�rit� via IUpdateable
	virtual void Update() override;
private:
	

};