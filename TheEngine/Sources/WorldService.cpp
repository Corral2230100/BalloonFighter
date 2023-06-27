#include "WorldService.h"
#include "Object.h"
using namespace TomNook;

	/// <summary>
	/// Constructor
	/// </summary>
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
	/// <summary>
	/// Creates a new object into the world and returns a reference to it.
	/// </summary>
	/// <param name="name"></param>
	/// <returns></returns>
	Object* WorldService::Create(const std::string& name)
	{
			Object* _object = new Object(name);
			Add(_object);
			return _object;
	}
	/// <summary>
	/// Adds a new object to the world.
	/// </summary>
	/// <param name="Entity"></param>
	void WorldService::Add(Object* Entity)
	{
		m_EntityWorld.push_back(Entity);
		m_EntityMap.emplace(Entity->GetName(), Entity);
		Entity->Init();
	}
	/// <summary>
	/// Removed an object from the world.
	/// </summary>
	/// <param name="PEntity"></param>
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
	/// <summary>
	/// Updates all the objects in the world.
	/// </summary>
	/// <param name="dt"></param>
	void WorldService::Update(float dt)
	{
		for (auto entity : m_EntityWorld)
		{
			entity->Update(dt);
		}
	}
	/// <summary>
	/// Draws all objects in the world.
	/// </summary>
	/// <param name="dt"></param>
	/// <param name="LagCorrection"></param>
	void WorldService::Draw( float dt, float LagCorrection)
	{
		for (auto entity : m_EntityWorld)
		{
			entity->Draw(dt, LagCorrection);
		}
	}
	/// <summary>
	/// Searches for an object by it's name.
	/// </summary>
	/// <param name="Name"></param>
	/// <returns> hopefully a reference or nullptr</returns>
	Object* WorldService::FindObjectByName(std::string Name)
	{
		if (m_EntityMap.count(Name) > 0)
		{
			return m_EntityMap[Name];
		}
		return nullptr;
	}
