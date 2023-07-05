#pragma once
#include <vector>
#pragma once
#include <map>
#include <string>

namespace TomNook
{
	class Collider;
	struct CollisionInfo;
	class PhysicsService
	{

	public:

		static PhysicsService& Get()
		{
			static PhysicsService* m_Instance;
			if (m_Instance == nullptr)
			{
				m_Instance = new PhysicsService();
			}
			return *m_Instance;
		}
		~PhysicsService();
		CollisionInfo CheckCollisions(Collider* collider);
		void AddCollider(Collider* collider);
		void RemoveCollider(Collider* collider);
	private:
		CollisionInfo SolveCollisions(Collider* collider1, Collider* collider2);
		std::vector<Collider*> m_Colliders;
	};
}