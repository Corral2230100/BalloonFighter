#include "WorldService.h"
#include "Object.h"
#include "IScene.h"
using namespace TomNook;


WorldService::~WorldService()
{

	Unload();

	for (auto scene : m_SceneRegistry)
	{
		delete scene.second;
	}

	m_SceneRegistry.clear();

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
	std::string _name = name;
	if (m_EntityMap.count(name) != 0)
	{
		_name = name + std::to_string(m_EntityMap.count(name));
	}
	Object* _object = new Object(_name);
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
	m_EntityToRemove.push_back(PEntity);
}

void WorldService::Update(float dt)
{
	for (auto entity : m_EntityWorld)
	{
		if (entity != nullptr)
		{
			entity->Update(dt);
		}
		
	}
	UpdateLoadScene();
	CleanEntities();
}

void WorldService::Draw(float dt, float LagCorrection)
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

void WorldService::Load(const std::string& scene)
{
	if (m_SceneRegistry.count(scene) > 0)
	{
		m_SceneToLoad = scene;
	}
}

void WorldService::Register(const std::string& name, IScene* scene)
{
	if (m_SceneRegistry.count(name) == 0)
	{
		m_SceneRegistry[name] = scene;
	}
}

void WorldService::Unload()
{
	for (auto entity : m_EntityWorld)
	{
		delete entity;
	}

	//for (auto entity : m_EntityToRemove)
	//{
	//	delete entity;
	//}

	m_EntityWorld.clear();
	m_EntityMap.clear();
	//m_EntityRemove.clear();
}


void WorldService::CleanEntities()
{
	if (m_EntityToRemove.size() > 0)
	{
		std::vector<Object*> _trash = m_EntityToRemove;
		m_EntityToRemove.clear();

		for (auto entity : _trash)
		{
			m_EntityMap.erase(entity->GetName());

			for (auto it = m_EntityWorld.begin(); it != m_EntityWorld.end(); ++it)
			{
				if (entity == *it)
				{
					m_EntityWorld.erase(it);
					delete entity;
					break;
				}
			}
		}

		_trash.clear();
	}
}

void WorldService::UpdateLoadScene()
{
	if (!m_SceneToLoad.empty())
	{
		Unload();
		m_SceneRegistry[m_SceneToLoad]->Load();
		m_SceneToLoad.clear();
	}
}

