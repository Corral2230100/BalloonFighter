#pragma once
namespace Engine
{
	enum class EButton
	{
		EBLeft = 0, EBRight = 1, EBMiddle = 3
	};
	enum class EKey
	{
		EKEY_W = 26,
		EKEY_S = 22,
		EKEY_D = 7,
		EKEY_A = 4,
		EKEY_RIGHT = 79,
		EKEY_LEFT = 80,
		EKEY_DOWN = 81,
		EKEY_UP = 82,
		EKEY_RETURN = 40,
		EKEY_ESCAPE = 41,
		EKEY_BACKSPACE = 42,
		EKEY_TAB = 43,
		EKEY_SPACE = 44
	};
	class IInput
	{
	public:
		virtual ~IInput() = default;



		virtual bool IsKeyDown(EKey key) = 0;
		virtual bool IsMouseButtonDown(EButton button) = 0;
		virtual void GetMousePosition(int* x, int* y) = 0;

	private:
		friend class Engine;
		virtual void Update() = 0;
	};
}


