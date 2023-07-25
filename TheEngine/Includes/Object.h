#pragma once
#include <string>
#include <vector>
#include <typeinfo>
#include <map>
#include "IDrawable.h"
#include "IUpdateable.h"
#include "Component.h"


namespace TomNook
{
	class Component;
	class Object final
	{

	public:
		Object(const std::string& name);
		~Object();
		void Update(float dt);
		void Init();
		void Draw(float LagCorrection, float dt);
		void SetPosition(float NewX, float NewY);
		void SetActive(bool Setting);
		void SetTag(std::string newtag) { m_Tag = newtag; };
		std::string GetTag() { return m_Tag; }
		float X() { return m_Position[0];}
		float Y() { return m_Position[1];}
		Vector2* Size() { return &m_Size; }
		float* Position() { return m_Position; }
		std::string GetName() { return m_Name; }

		template <typename T>
		T* AddComponent()
		{
			const type_info* _type = &typeid(T);

			if (m_ComponentByType.count(_type)) return (T*)m_ComponentByType[_type];

			T* _cmp = new T(this);
			auto _updateable = dynamic_cast<IUpdateable*>(_cmp);

			if (_updateable != nullptr)
			{
				m_ComponentsToUpdate.emplace_back(_updateable);
			}

			auto _drawable = dynamic_cast<IDrawable*>(_cmp);
			if (_drawable != nullptr)
			{
				m_ComponentsToDraw.emplace_back(_drawable);
			}
			m_Components.emplace_back(_cmp);
			m_ComponentByType.emplace(_type, _cmp);
			return _cmp;
		}
		template <typename T>
		inline T* GetComponent()
		{
			const type_info* _type = &typeid(T);
			return (T*)m_ComponentByType[_type];
		}

	private:
		std::vector<Component*> m_Components;
		std::map<const type_info*, Component*> m_ComponentByType;

		std::vector<IDrawable*> m_ComponentsToDraw;
		std::vector<IUpdateable*> m_ComponentsToUpdate;
		float m_Position[2] = {0};
		Vector2 m_Size = { 0,0 };
		std::string m_Name;
		float m_Active = true;
		std::string m_Tag;
		/// Need to put this in another class later VV

	};
}



