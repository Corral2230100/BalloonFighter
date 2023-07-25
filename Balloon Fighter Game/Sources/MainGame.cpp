#include "MainGame.h"

MainGame::~MainGame()
{
}

void MainGame::Start()
{
	m_TextFont = Engine::Get().Graphics().LoadFont("./Assets/slkscr.ttf", 8);
}

void MainGame::Destroy()
{

}

void MainGame::Update()
{

}

void MainGame::Draw()
{
	Engine::Get().Graphics().DrawString("Score  " + std::to_string(Score), m_TextFont, 0,0, Color {255,255,255,255});
}

void MainGame::OnNotify(const int& value)
{
	if (value != -1)
	{
		Score += value;
	}
}
