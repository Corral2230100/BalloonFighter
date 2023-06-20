#pragma once
#include "IInput.h"

using namespace Engine2;
class SDLInput final : public IInput 
{
public:
	virtual ~SDLInput() = default;

	virtual bool IsKeyDown(EKey key) override;
	virtual bool IsMouseButtonDown(EButton button) override;
	virtual void GetMousePosition(int* m_x, int* m_y) override;

private:
	const unsigned char* m_KeyStates = nullptr;
	int m_MouseX = 0;
	int m_MouseY = 0;
	bool m_MouseStates[3]{ false,false,false };

	virtual void Update() override;
};