#include "CController.h"
using namespace TomNook;

CController::~CController()
{
}

void CController::Start()
{
}

void CController::Destroy()
{
}

void CController::Update()
{
	for (auto const& input : m_InputBindingsDown)
	{
		if (m_Inputs.IsKeyDown(input.first))
		{
			input.second();
		}
	}
	for (auto const& input : m_InputBindingsUp)
	{
		if (m_Inputs.IsKeyUp(input.first))
		{
			input.second();
		}
	}
}
