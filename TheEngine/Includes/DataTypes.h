#pragma once

namespace TomNook
{
	class Object;
	class Collider;
	struct Vector2
	{
	public:
		int x;
		int y;
	};

	struct Color
	{
	public:
		int R;
		int G;
		int B;
		int A;
	};
	struct RectF
	{
		float x;
		float y;
		float w;
		float h;
	};
	struct RectI
	{
		int x;
		int y;
		int w;
		int h;
	};
	struct Flip
	{
		bool h;
		bool v;
	};
	enum class CollisionMode
	{
		Active,Passive,Disabled
	};
	struct CollisionInfo
	{
		Vector2 CollisionPoint;
		Object* OtherObject;
		bool Hit = false;
		Vector2 CollisionDir{0,0};
		Collider* Victim = nullptr;
		Collider* Aggressor = nullptr;
	};

	/// -------------------------------------------------------------------


}




