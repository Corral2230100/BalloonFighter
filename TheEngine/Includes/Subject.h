#pragma once
#include "IObserver.h"
#include <list>

namespace TomNook
{
	template<typename T>
	class Subject
	{
	public:
		void AddListener(Observer<T>* object)
		{
			m_Observers.push_back(object);
		}
		void RemoveListener(Observer<T>* object)
		{
			m_Observers.remove(object);
		}
		void RemoveListeners()
		{
			m_Observers.clear();
		}
		void Invoke(const T& value)
		{
			for (Observer<T>* o : m_Observers)
			{
				o->OnNotify(value);
			}
		}
	private:
		std::list<Observer<T>*> m_Observers;
	};
}

