#pragma once
#include <string>
#include <vector>
#include <typeinfo>
#include <map>
class Component;

namespace Engine2
{
	class Object final
	{
	public:
		Object(const std::string& name);
		~Object();
		void Update(float dt);
		void Init();
		void Draw(float LagCorrection, float dt);
		void SetVelX(float Vel);
		void SetVelY(float Vel);
		void SetPosition(float NewX, float NewY);
		void SetActive(bool Setting);
		
		float& X() { return m_x; }
		float& Y() { return m_y; }
		std::string GetName() { return m_Name; }

		template <typename T>
		inline T AddComponent()
		{
			T* _cmp = new T();
			m_Components.emplace_back(_cmp);

		}
		template <typename T>
		inline T& GetComponent()
		{
			const type_info* type = &typeid(T);
			return m_ComponentByType[type];
		}

	private:
		std::vector<Component*> m_Components;
		std::map<const type_info*, Component*> m_ComponentByType;
		std::string m_Name;
		/// put this in a struct later
		float m_x = 0;
		float m_y = 0;
		float VelX = 0;
		float VelY = 0;
		float m_Active = true;
		/// Need to put this in another class later VV

		

		

	};
}


