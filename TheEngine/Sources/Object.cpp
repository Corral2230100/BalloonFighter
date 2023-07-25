#include "Object.h"
#include <IGraphics.h>
#include "Engine.h"
#include "Component.h"
#include "IUpdateable.h"
#include "IDrawable.h"
using namespace TomNook;
	/// <summary>
	/// Constructeur
	/// </summary>
	/// <param name="Name"></param>
	Object::Object(const std::string& Name)
		:m_Name(Name)
	{

	}
	/// <summary>
	/// Deconstructeur
	/// </summary>
	Object::~Object()
	{
		for (auto iter : m_Components)
		{
			if (iter != nullptr)
			{
				delete(iter);
				iter = nullptr;
			}
		}
		m_Components.clear();
		m_ComponentByType.clear();
	}

	/// <summary>
	/// Updates the object, Also updates it's components.
	/// Changes the object's position relative to its velocity. To be replaced by a component.
	/// </summary>
	/// <param name="dt"></param>
	void Object::Update(float dt)
	{
		if (!m_Active) return;
		for (auto component : m_ComponentsToUpdate)
		{
			component->Update();
		}

		float _x = Engine::Get().Graphics().GetScreenSize().x;
		if (m_Position[0]-m_Size.x/2 > _x)
		{
			m_Position[0] -= _x;
		}
		else if (m_Position[0] + m_Size.x/2 < 0)
		{
			m_Position[0] += _x;
		}
	}

	/// <summary>
	/// Loads the object's texture, TO BE REMOVED 
	/// </summary>
	void Object::Init()
	{
		
	}

	/// <summary>
	/// Draws the object, most of this will be replaced by a component
	/// </summary>
	/// <param name="LagCorrection"></param>
	/// <param name="dt"></param>
	void  Object::Draw(float LagCorrection, float dt)
	{
		if (!m_Active) return;
		for (auto component : m_ComponentsToDraw)
		{
			component->Draw();
		}
	}


	/// <summary>
	/// Manually sets the object's position;
	/// </summary>
	/// <param name="NewX"></param>
	/// <param name="NewY"></param>
	void  Object::SetPosition(float NewX, float NewY)
	{
		m_Position[0] = NewX;
		m_Position[1] = NewY;
	}

	void  Object::SetActive(bool Setting)
	{
		m_Active = Setting;
	}





