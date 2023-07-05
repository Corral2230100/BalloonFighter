#pragma once
#include "Component.h"
#include "IUpdateable.h"
#include "Subject.h"
#include <map>
#include <functional>
namespace TomNook
{
	class CController : public Component, public IUpdateable
	{
	public:
		
		CController(Object* parent) : Component(parent), m_Inputs(Engine::Get().Input())		
		{
			
		};
		virtual ~CController();
		// Hérité via Component
		virtual void Start() override;
		virtual void Destroy() override;
		// Hérité via IUpdateable
		virtual void Update() override;
		std::map<EKey,std::function<void()>> m_InputBindingsDown;
		std::map<EKey, std::function<void()>> m_InputBindingsUp;
		IInput& m_Inputs;

	private:
		

	};
}

