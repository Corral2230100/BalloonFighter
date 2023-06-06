#pragma once
#include <vector>
#include "Object.h"
#include "SDLRender.h"
#include <map>

class WorldService
{

public:
	~WorldService()
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
	void Add(Engine::Object* Entity)
	{
		m_EntityWorld.push_back(Entity);
		m_EntityMap.emplace(Entity->GetName(), Entity);
	}
	void Remove(Engine::Object* PEntity)
	{
		for (int i = 0; i < m_EntityWorld.size(); i++ )
		{
			if (m_EntityWorld[i] == PEntity)
			{
				m_EntityMap.erase(PEntity->GetName());
				delete(m_EntityWorld[i]);
				m_EntityWorld.erase(m_EntityWorld.begin()+i-1);
				break;
			}
		}
	}
	void Update(float dt)
	{
		for (auto entity : m_EntityWorld)
		{
			entity->Update(dt);
		}
	}
	void Draw(Engine::IGraphics* Renderer,float dt, float LagCorrection)
	{
		for (auto entity : m_EntityWorld)
		{
			entity->Draw(Renderer,dt,LagCorrection);
		}
	}
	Engine::Object* FindObjectByName(std::string Name)
	{
		if (m_EntityMap.count(Name) > 0)
		{
			return m_EntityMap[Name];
		}
		return nullptr;
	}
private:
	std::map<std::string, Engine::Object*> m_EntityMap;
	std::vector<Engine::Object*> m_EntityWorld;
};