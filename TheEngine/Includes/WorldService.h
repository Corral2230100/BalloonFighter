#pragma once
#include <vector>
#include <map>
#include <string>

class IScene;
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
		/// <summary>
		/// Creates a new object into the world and returns a reference to it.
		/// </summary>
		/// <param name="name"></param>
		/// <returns></returns>
		Object* Create(const std::string& name);
		/// <summary>
		/// Adds a new object to the world.
		/// </summary>
		/// <param name="Entity"></param>
		void Add(Object* Entity);
		/// <summary>
		/// Removed an object from the world.
		/// </summary>
		/// <param name="PEntity"></param>
		void Remove(Object* PEntity);
		/// <summary>
		/// Updates all the objects in the world.
		/// </summary>
		/// <param name="dt"></param>
		void WorldService::Update(float dt);
		/// <summary>
		/// Draws all objects in the world.
		/// </summary>
		/// <param name="dt"></param>
		/// <param name="LagCorrection"></param>
		void WorldService::Draw(float dt, float LagCorrection);
		void Load(const std::string& sceneName);
		void Unload();
		void Register(const std::string& sceneName, IScene* scene);
		/// <summary>
		/// Searches for an object by it's name.
		/// </summary>
		/// <param name="Name"></param>
		/// <returns> hopefully a reference or nullptr</returns>
		Object* WorldService::FindObjectByName(std::string Name);
	private:
		void CleanEntities();
		void UpdateLoadScene();


		std::map<std::string, Object*> m_EntityMap;
		std::vector<Object*> m_EntityWorld;
		std::vector<Object*> m_InactiveEntityWorld;
		std::vector<Object*> m_EntityToRemove;
		std::vector<Object*> m_EntityToStart;
		std::map<std::string, IScene*> m_SceneRegistry;
		std::string m_SceneToLoad;
	};
}
