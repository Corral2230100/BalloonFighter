#pragma once
#include "IInput.h"

class SDLInput final : public Engine::IInput 
{
public:
	virtual ~SDLInput() = default;

	virtual bool IsKeyDown(Engine::EKey key) override;
	virtual bool IsMouseButtonDown(Engine::EButton button) override;
	virtual void GetMousePosition(int* m_x, int* m_y) override;

private:
	const unsigned char* m_KeyStates = nullptr;
	int m_MouseX = 0;
	int m_MouseY = 0;
	bool m_MouseStates[3]{ false,false,false };

	virtual void Update() override;
};