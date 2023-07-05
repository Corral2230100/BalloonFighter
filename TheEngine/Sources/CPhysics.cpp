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

		GravityTimer = clip(GravityTimer + TomNook::Engine::Get().DeltaTime()*0.05f,0.0f,1.0f);
		GravityModifier = lerp(0, GravityForce, GravityTimer);
	}
	VelX = clip(VelX, VelXCap[0], VelXCap[1]);
	VelY = clip(VelY, VelYCap[0], VelYCap[1]);
	

	/// A Changer avec un futur setting de bouciness par objet physique
	if (m_Collision.CollisionDir.x != 0)
	{
		VelX = -VelX/2;
	}
	if (m_Collision.CollisionDir.y != 0)
	{
		VelY = -VelY/4;
		GravityTimer = 0.0f;
	}
	else
	{
		VelY += GravityModifier;
	}
	///

	float _X = VelX * TomNook::Engine::Get().DeltaTime();
	float _Y = VelY  * TomNook::Engine::Get().DeltaTime() ;
	float* vec = m_Entity->Position();

	vec[0] += _X;
	vec[1] += _Y;
	m_Collision.CollisionDir = { 0,0 };
}

void CPhysics::Start()
{
}

void CPhysics::Destroy()
{
}

void CPhysics::OnNotify(const CollisionInfo& value)
{
	m_Collision = value;
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

void  CPhysics::SetVelY(float Vel,bool KeepGravity)
{
	if (!KeepGravity)
	{
		GravityTimer = 0.0f;
	}
	VelY = Vel;
}