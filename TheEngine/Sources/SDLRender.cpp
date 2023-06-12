#include "SDLRender.h"
#include "SDLInput.h"
#include "SDL_image.h"
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

	TTF_Init();
	return false;
}

void Engine::SDLRender::Shutdown()
{

	TTF_Quit();
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
	SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
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
	SetColor(color);
	SDL_Rect _rect = { 0 };
	_rect.x = rect.x;
	_rect.y = rect.y;
	_rect.w = rect.w;
	_rect.h = rect.h;


	SDL_RenderDrawRect(m_Renderer, &_rect);
}

void Engine::SDLRender::FillRect(float x, float y, float w, float h, const Color& color)
{
	SetColor(color);
	SDL_Rect _rect = { 0 };
	_rect.x = x;
	_rect.y = y;
	_rect.w = w;
	_rect.h = h;


	SDL_RenderFillRect(m_Renderer, &_rect);
}

void Engine::SDLRender::FillRect(const RectF& rect, const Color& color)
{
	SetColor(color);
	SDL_Rect _rect = { 0 };
	_rect.x = rect.x;
	_rect.y = rect.y;
	_rect.w = rect.w;
	_rect.h = rect.h;


	SDL_RenderFillRect(m_Renderer, &_rect);
}

void Engine::SDLRender::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
	SetColor(color);
	SDL_RenderDrawLine(m_Renderer, x1, y1, x2, y2);
}

size_t Engine::SDLRender::LoadTexture(const std::string& filename)
{
	const size_t _textureId = std::hash<std::string>()(filename);
	if (_textureId == m_TextureIdList[filename]) {
		return _textureId;
	}
	std::string _path = static_cast<std::string>(SDL_GetBasePath()) + filename.c_str();
	SDL_Texture* _texture = IMG_LoadTexture(m_Renderer,_path.c_str());

	if (_texture != nullptr) {
		m_TextureIdList.emplace(filename.c_str(),_textureId);
		m_TextureList[_textureId] = _texture;
		return _textureId;
	}

	return -1;
}

void Engine::SDLRender::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{
	SDL_Texture* _texture = m_TextureList[id];
	SDL_RendererFlip _sdlflip = SDL_FLIP_NONE;

	if (flip.h && flip.v) _sdlflip = static_cast<SDL_RendererFlip>(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
	else if (flip.h) _sdlflip = SDL_FLIP_HORIZONTAL;
	else if (flip.v) _sdlflip = SDL_FLIP_VERTICAL;

	SDL_Rect _rect = { 0 };
	_rect.x = src.x;
	_rect.y = src.y;
	_rect.h = src.h;
	_rect.w = src.w;

	SDL_Rect _rectF = { 0 };
	_rectF.x = dst.x;
	_rectF.y = dst.y;
	_rectF.h = dst.h;
	_rectF.w = dst.w;

	SDL_RenderCopyEx(m_Renderer, _texture, &_rect, &_rectF, angle, nullptr, _sdlflip);
}

void Engine::SDLRender::DrawTexture(size_t id, const RectF& dst, const Color& color)
{

	SDL_Texture* _texture = m_TextureList[id];
	SDL_RendererFlip _sdlflip = SDL_FLIP_NONE;

	SDL_Rect _rectF = { 0 };
	_rectF.x = dst.x;
	_rectF.y = dst.y;
	_rectF.h = dst.h;
	_rectF.w = dst.w;

	SDL_RenderCopyEx(m_Renderer, _texture, nullptr, &_rectF, 0, nullptr, _sdlflip);
}

void Engine::SDLRender::DrawTexture(size_t id, const Color& color)
{
	SDL_Texture* _texture = m_TextureList[id];
	SDL_RendererFlip _sdlflip = SDL_FLIP_NONE;

	SDL_RenderCopyEx(m_Renderer, _texture, nullptr, nullptr, 0, nullptr, _sdlflip);
}

void Engine::SDLRender::GetTextureSize(size_t id, int* w, int* h)
{
}

size_t Engine::SDLRender::LoadFont(const std::string& filename, int fontSize)
{
	const size_t fontId = std::hash<std::string>()(filename);

	if (fontId == m_FontIdList[filename]) {
		return fontId;
	}

	TTF_Font* _font = TTF_OpenFont(filename.c_str(), fontSize);
	if (_font != nullptr) {
		m_FontIdList.emplace(filename.c_str(),fontId);
		return fontId;
	}

	return -1;
}

void Engine::SDLRender::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{
	SDL_Color _color = {};
	_color.a = color.A;
	_color.b = color.B;
	_color.g = color.G;
	_color.r = color.R;
	if (m_FontList[fontId] != nullptr)
	{

		TTF_Font* _font = m_FontList[fontId];
		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), _color);
		m_TextureBuffer = SDL_CreateTextureFromSurface(m_Renderer, _surface);

		SDL_RenderCopy(m_Renderer, m_TextureBuffer, nullptr, nullptr);
		SDL_FreeSurface(_surface);
	}
}

void Engine::SDLRender::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
