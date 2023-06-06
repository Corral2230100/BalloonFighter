#include "SDLRender.h"
#include "SDLInput.h"
#include <SDL.h>


bool Engine::SDLRender::Initialize(const std::string& Title, int Width, int Height)
{
	Uint32 _flag = SDL_WINDOW_TOOLTIP | SDL_WINDOW_RESIZABLE;
	int _x = SDL_WINDOWPOS_CENTERED;
	int _y = SDL_WINDOWPOS_CENTERED;

	m_Window = SDL_CreateWindow(Title.c_str(), _x, _y, Width, Height, _flag);
	if (!m_Window)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	_flag = SDL_RENDERER_ACCELERATED;
	m_Renderer = SDL_CreateRenderer(m_Window, -1, _flag);
	if (!m_Renderer)
	{
		SDL_Log(SDL_GetError());
		return false;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING != 0))
	{
		SDL_Log(SDL_GetError());
		return false;
	}


	return false;
}

void Engine::SDLRender::Shutdown()
{

	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;

	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void Engine::SDLRender::SetColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer,color.R,color.G,color.B,color.A);
}

void Engine::SDLRender::Clear()
{
	
	SDL_RenderClear(m_Renderer);

}

void Engine::SDLRender::Present()
{
	
	SDL_RenderPresent(m_Renderer);
}

void Engine::SDLRender::DrawRect(float x, float y, float w, float h, const Color& color)
{
	SetColor(color);
	SDL_Rect _rect = { 0 };
	_rect.x = x;
	_rect.y = y;
	_rect.w = 100;
	_rect.h = 100;
	SDL_RenderFillRect(m_Renderer, &_rect);
}

void Engine::SDLRender::DrawRect(const RectF& rect, const Color& color)
{
}

void Engine::SDLRender::FillRect(float x, float y, float w, float h, const Color& color)
{
}

void Engine::SDLRender::FillRect(const RectF& rect, const Color& color)
{
}

void Engine::SDLRender::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
}

size_t Engine::SDLRender::LoadTexture(const std::string& filename)
{
	return size_t();
}

void Engine::SDLRender::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
}

void Engine::SDLRender::DrawTexture(size_t id, const RectF& dst, const Color& color)
{
}

void Engine::SDLRender::DrawTexture(size_t id, const Color& color)
{
}

void Engine::SDLRender::GetTextureSize(size_t id, int* w, int* h)
{
}

size_t Engine::SDLRender::LoadFont(const std::string& filename, int fontSize)
{
	return size_t();
}

void Engine::SDLRender::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
}

void Engine::SDLRender::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
