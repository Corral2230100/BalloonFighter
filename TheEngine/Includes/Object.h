#pragma once
struct SDL_Renderer;
class Object
{
public:
	Object();
	~Object();
	void Update(float dt);
	void Draw(SDL_Renderer* Renderer,float LagCorrection,float dt);
	void SetVelX(float Vel);
	void SetVelY(float Vel);
private:
	/// put this in a struct later
	float x = 0;
	float y = 0;
	float VelX = 0;
	float VelY = 0;


};

