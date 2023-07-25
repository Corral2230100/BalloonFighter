#include "Menu.h"
#include "Object.h"
#include "CAnimation.h"
#include "CController.h"
Menu::~Menu()
{
}

void Menu::Start()
{

	m_TextFont = Engine::Get().Graphics().LoadFont("./Assets/slkscr.ttf", 8);
	m_Music = Engine::Get().Audio().LoadMusic("./Assets/Sounds/TitleSong.mp3");
	Engine::Get().Audio().PlayMusic(m_Music);
	Engine::Get().Audio().SetMusicVolume(40);
	m_Pointer = Engine::Get().m_World->Create("TitlePointer");
	m_Pointer->SetPosition(80, 128);
	CAnimation* _Anim = m_Pointer->AddComponent<CAnimation>();
	_Anim->InitAnimation("./Assets/FloatingBalloon.png", 24, 24);
	std::vector<int> _frames = { 0,1,2,3 };
	_Anim->AddClip("Hover", _frames, 0.3f);
	_Anim->Play("Hover", true);

	m_Ding = Engine::Get().Audio().LoadSound("./Assets/Sounds/MenuTing.wav");
	m_Entity->AddComponent<CController>();
	std::function<void()> _func = std::bind(&Menu::Up, this);
	m_Entity->GetComponent<CController>()->m_InputBindingsDown.emplace(EKey::EKEY_UP, _func);
	_func = std::bind(&Menu::Down, this);
	m_Entity->GetComponent<CController>()->m_InputBindingsDown.emplace(EKey::EKEY_DOWN, _func);
	_func = std::bind(&Menu::Select, this);
	m_Entity->GetComponent<CController>()->m_InputBindingsDown.emplace(EKey::EKEY_SPACE, _func);
	m_Entity->GetComponent<CController>()->m_InputBindingsDown.emplace(EKey::EKEY_RETURN, _func);
}

void Menu::Destroy()
{
	Engine::Get().Audio().StopMusic();
}

void Menu::Draw()
{

	for (int i = 0; i <= sizeof(*MenuOptions) / sizeof(MenuOptions[0]); i++)
	{
		Color _col = { 255,255,255,175 };
		if (i == MenuIndex)
		{
			_col.A = 255;
		}
		Engine::Get().Graphics().DrawString(MenuOptions[i], m_TextFont, 100, m_MenuStartY+(m_MenuStep*i), _col);
	}
}

void Menu::Update()
{

}

void Menu::Up()
{
	MenuIndex--;
	if (MenuIndex < 0) MenuIndex = 1;
	m_Pointer->SetPosition(80, m_MenuStartY - 8 + (MenuIndex * m_MenuStep));
	Engine::Get().Audio().PlaySFX(m_Ding);
}

void Menu::Down()
{
	MenuIndex++;
	if (MenuIndex > 1) MenuIndex = 0;
	m_Pointer->SetPosition(80, m_MenuStartY - 8 + (MenuIndex * m_MenuStep));
	Engine::Get().Audio().PlaySFX(m_Ding);
}

void Menu::Select()
{
	Engine::Get().m_World->Load("Level1");
	Engine::Get().Audio().StopMusic();
}
