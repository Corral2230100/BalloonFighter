#pragma once
#include "Component.h"
#include "Subject.h"
#include "IUpdateable.h"
namespace TomNook
{
	class Collider;
	class CCollider : public Component, public IUpdateable
	{
	public:
		CCollider(Object* parent) : Component(parent)
		{
		};
		~CCollider();
		void SetCollider(Collider* collider);
		Subject<CollisionInfo> OnCollision;
		Collider* m_Collider = nullptr;
		// Inherited via IUpdateable
		virtual void Update() override;
	private:



		// Inherited via Component
		virtual void Start() override;

		virtual void Destroy() override;

	};
}