#pragma once

template<typename T>
#pragma once

class Observer
{
public:
	virtual ~Observer() = default;
	virtual void OnNotify(const T& value) = 0;
};