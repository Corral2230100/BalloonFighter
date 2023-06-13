#include "SDLRender.h"
#include "SDLInput.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <SDL.h>


static SDL_Color ColorToSDLColor(Engine::Color _color)
{
	SDL_Color _newcolor = {};
	_newcolor.a = static_cast<Uint8>(_color.A);
	_newcolor.b = static_cast<Uint8>(_color.B);
	_newcolor.g = static_cast<Uint8>(_color.G);
	_newcolor.r = static_cast<Uint8>(_color.R);
	return _newcolor;
}

static SDL_Rect RectFToSDLRect(Engine::RectF _rect)
{
	SDL_Rect _newrect = { 0 };
	_newrect.x = static_cast<int>(_rect.x);
	_newrect.y = static_cast<int>(_rect.y);
	_newrect.w = static_cast<int>(_rect.w);
	_newrect.h = static_cast<int>(_rect.h);

	return _newrect;
}
static SDL_Rect RectIToSDLRect(Engine::RectI _rect)
{
	SDL_Rect _newrect = { 0 };
	_newrect.x = static_cast<int>(_rect.x);
	_newrect.y = static_cast<int>(_rect.y);
	_newrect.w = static_cast<int>(_rect.w);
	_newrect.h = static_cast<int>(_rect.h);

	return _newrect;
}
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
	for (auto &iter : *m_TextureList)
	{
		SDL_DestroyTexture(iter.second);
		//iter.second = nullptr;
	}
	for (auto iter : *m_FontList)
	{
		TTF_CloseFont(iter.second);
		//iter.second = nullptr;
	}
	m_FontList->clear();
	m_TextureList->clear();
	delete m_TextureList;
	delete m_FontList;
	TTF_Quit();
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;

	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void Engine::SDLRender::SetColor(const Color& color)
{
	SDL_Color _color = ColorToSDLColor(color);
	SDL_SetRenderDrawColor(m_Renderer,_color.r,_color.g,_color.b,_color.a);
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
	_rect.x = static_cast<int>(x);
	_rect.y = static_cast<int>(y);
	_rect.w = static_cast<int>(100);
	_rect.h = static_cast<int>(100);
	SDL_RenderFillRect(m_Renderer, &_rect);
}

void Engine::SDLRender::DrawRect(const RectF& rect, const Color& color)
{
	SetColor(color);
	SDL_Rect _rect = RectFToSDLRect(rect);
	SDL_RenderDrawRect(m_Renderer, &_rect);
}

void Engine::SDLRender::FillRect(float x, float y, float w, float h, const Color& color)
{
	SetColor(color);
	SDL_Rect _rect = { 0 };
	_rect.x = static_cast<int>(x);
	_rect.y = static_cast<int>(y);
	_rect.w = static_cast<int>(w);
	_rect.h = static_cast<int>(h);

	SDL_RenderFillRect(m_Renderer, &_rect);
}

void Engine::SDLRender::FillRect(const RectF& rect, const Color& color)
{
	SetColor(color);
	SDL_Rect _rect = RectFToSDLRect(rect);

	SDL_RenderFillRect(m_Renderer, &_rect);
}

void Engine::SDLRender::DrawLine(float x1, float y1, float x2, float y2, const Color& color)
{
	SetColor(color);
	SDL_RenderDrawLine(m_Renderer, static_cast<int>(x1), static_cast<int>(y1), static_cast<int>(x2), static_cast<int>(y2));
}

size_t Engine::SDLRender::LoadTexture(const std::string& filename)
{
	const size_t _textureId = std::hash<std::string>()(filename);
	if (m_TextureList->count(_textureId) > 0) {
		return _textureId;
	}
	std::string _path = SDL_GetBasePath() + filename;
	SDL_Texture* _texture = IMG_LoadTexture(m_Renderer,_path.c_str());

	if (_texture != nullptr) {
		(*m_TextureList)[_textureId] = _texture;
		return _textureId;
	}

	return -1;
}

void Engine::SDLRender::DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color)
{

	SDL_Texture* _texture = (*m_TextureList)[id];

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
	_rectF.x = static_cast<int>(dst.x);
	_rectF.y = static_cast<int>(dst.y);
	_rectF.h = static_cast<int>(dst.h);
	_rectF.w = static_cast<int>(dst.w);

	SDL_RenderCopyEx(m_Renderer, _texture, &_rect, &_rectF, angle, nullptr, _sdlflip);
}

void Engine::SDLRender::DrawTexture(size_t id, const RectF& dst, const Color& color)
{

	SDL_Texture* _texture = (*m_TextureList)[id];
	SDL_RendererFlip _sdlflip = SDL_FLIP_NONE;

	SDL_Rect _rectF = RectFToSDLRect(dst);

	SDL_RenderCopyEx(m_Renderer, _texture, nullptr, &_rectF, 0, nullptr, _sdlflip);
}

void Engine::SDLRender::DrawTexture(size_t id, const Color& color)
{
	SDL_Texture* _texture = (*m_TextureList)[id];
	SDL_RendererFlip _sdlflip = SDL_FLIP_NONE;

	SDL_RenderCopyEx(m_Renderer, _texture, nullptr, nullptr, 0, nullptr, _sdlflip);
}

void Engine::SDLRender::GetTextureSize(size_t id, int* w, int* h)
{
}

size_t Engine::SDLRender::LoadFont(const std::string& filename, int fontSize)
{
	const size_t _fontId = std::hash<std::string>()(filename);

	if (m_FontList->count(_fontId) > 0) {
		return _fontId;
	}
	std::string _path = SDL_GetBasePath() + filename;
	TTF_Font* _font = TTF_OpenFont(_path.c_str(), fontSize);

	if (_font != nullptr) {
		m_FontList->emplace(_fontId,_font);
		return _fontId;
	}

	return -1;
}

void Engine::SDLRender::DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color)
{

	SDL_Rect _rect; 
	_rect.x = static_cast<int>(x);
	_rect.y = static_cast<int>(y);

	if ((*m_FontList)[fontId] != nullptr)
	{

		TTF_Font* _font =   (*m_FontList)[fontId];
		SDL_Surface* _surface = TTF_RenderText_Solid(_font, text.c_str(), ColorToSDLColor(color));
		m_TextureBuffer = SDL_CreateTextureFromSurface(m_Renderer, _surface);
		TTF_SizeText(_font, text.c_str(), &_rect.w, &_rect.h);
		SDL_RenderCopy(m_Renderer, m_TextureBuffer, NULL, &_rect);
		SDL_FreeSurface(_surface);
		SDL_DestroyTexture(m_TextureBuffer);
	}
}

void Engine::SDLRender::GetTextSize(const std::string& text, size_t fontId, int* w, int* h)
{
}
