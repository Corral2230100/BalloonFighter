#pragma once

namespace TomNook
{
	class Object;
	struct Vector2
	{
	public:
		int x;
		int y;
	};

	struct Color
	{
	public:
		float R = 0;
		float G = 0;
		float B = 0;
		float A = 0;
		Color(float r, float g, float b, float a)
		{
			float R = r;
			float G = g;
			float B = b;
			float A = a;
		}
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
	};

	/// -------------------------------------------------------------------


}




