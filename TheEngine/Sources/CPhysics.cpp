#include "CPhysics.h"
#include "Object.h"

using namespace TomNook;
float lerp(float a, float b, float f)
{
	return a * (1.0 - f) + (b * f);
}

void CPhysics::Update()
{
	if (UseGravity)
	{
		GravityTimer += TomNook::Engine::Get().DeltaTime();
		GravityModifier = lerp(0, GravityForce, GravityTimer)* TomNook::Engine::Get().DeltaTime();
	}
	float _X = VelX * TomNook::Engine::Get().DeltaTime();
	float _Y = VelY * TomNook::Engine::Get().DeltaTime() - GravityModifier;
	float* vec = m_Entity->Position();
	vec[0] = _X;
	vec[1] = _Y;
}

void CPhysics::Start()
{
}

void CPhysics::Destroy()
{
}


/// <summary>
/// Changes the object's x velocity.
/// </summary>
/// <param name="Vel"></param>
void  CPhysics::SetVelX(float Vel)
{
	VelX = Vel;
}
/// <summary>
/// Changes the object's y velocity
/// </summary>
/// <param name="Vel"></param>
void  CPhysics::SetVelY(float Vel)
{
	VelY = Vel;
}