#pragma once
#include "IInput.h"

using namespace TomNook;
class SDLInput final : public IInput 
{
public:
	SDLInput();
	~SDLInput();
	virtual bool IsKeyDown(EKey key) override;
	virtual bool IsKeyUp(EKey key) override;
	virtual bool IsKeyHeld(EKey key) override;
	virtual bool IsMouseButtonDown(EButton button) override;
	virtual void GetMousePosition(int* m_x, int* m_y) override;

private:
	unsigned char* m_PreviousKeyStates = nullptr;
	unsigned char* m_KeyStates = nullptr;
	int m_MouseX = 0;
	int m_MouseY = 0;
	int m_StateSize = 0;
	bool m_MouseStates[3]{ false,false,false };

	virtual void Update() override;

	// Inherited via IInput

};