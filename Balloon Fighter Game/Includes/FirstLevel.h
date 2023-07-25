#pragma once
#include "IScene.h"
#include <Object.h>

class FirstLevel : public IScene
{
public:
	/// From scene
	virtual void Load() override;

};