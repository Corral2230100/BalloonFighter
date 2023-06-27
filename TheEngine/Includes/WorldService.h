#pragma once
#include <vector>
#include <map>
#include <string>

namespace TomNook
{
	class Object;
	class WorldService
	{

	public:
		
		static WorldService& Get() 
		{ 
			static WorldService* m_Instance;
			if (m_Instance == nullptr)
			{
				m_Instance = new WorldService();
			}
			return *m_Instance; 
		}
		~WorldService();
		Object* Create(const std::string& name);
		void Add(Object* Entity);
		void Remove(Object* PEntity);
		void WorldService::Update(float dt);
		void WorldService::Draw(float dt, float LagCorrection);
		Object* WorldService::FindObjectByName(std::string Name);
	private:
		std::map<std::string, Object*> m_EntityMap;
		std::vector<Object*> m_EntityWorld;
		std::vector<Object*> m_InactiveEntityWorld;
	};
}
