#include "WorldService.h"
namespace Engine
{

	WorldService::~WorldService()
	{
		for (auto entity : m_EntityWorld)
		{
			if (entity != nullptr)
			{
				delete(entity);
				entity = nullptr;
			}
		}
		m_EntityMap.clear();
		m_EntityWorld.clear();
	}
	Object* WorldService::Create(const std::string& name)
	{
			Object* _object = new Object(name);
			Add(_object);
			return _object;
	}
	void WorldService::Add(Object* Entity)
	{
		m_EntityWorld.push_back(Entity);
		m_EntityMap.emplace(Entity->GetName(), Entity);
		Entity->Init();
	}
	void WorldService::Remove(Object* PEntity)
	{
		for (int i = 0; i < m_EntityWorld.size(); i++)
		{
			if (m_EntityWorld[i] == PEntity)
			{
				m_EntityMap.erase(PEntity->GetName());
				delete(m_EntityWorld[i]);
				m_EntityWorld.erase(m_EntityWorld.begin() + i - 1);
				break;
			}
		}
	}
	void WorldService::Update(float dt)
	{
		for (auto entity : m_EntityWorld)
		{
			entity->Update(dt);
		}
	}
	void WorldService::Draw( float dt, float LagCorrection)
	{
		for (auto entity : m_EntityWorld)
		{
			entity->Draw(dt, LagCorrection);
		}
	}
	Object* WorldService::FindObjectByName(std::string Name)
	{
		if (m_EntityMap.count(Name) > 0)
		{
			return m_EntityMap[Name];
		}
		return nullptr;
	}


}