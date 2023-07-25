#pragma once
#include "Object.h"
#include <string>

using namespace TomNook;

	class IScene
	{
	public:
		virtual void Load() = 0;

	protected:
		Object* Instantiate(const std::string& name);
	};