#include "Component.h"


TomNook::Component::~Component()
{
	if (m_Entity != nullptr)
	{
		m_Entity = nullptr;
	}

}