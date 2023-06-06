#pragma once
#include "IGraphics.h"
#include <string>

class SDL_Window;
class SDL_Renderer;
namespace Engine
{


class SDLRender : public IGraphics
{

	public:
		//void Draw(float dt, float LagCorrection) override;
	private:
		SDL_Window* m_Window = nullptr;
		SDL_Renderer* m_Renderer = nullptr;
		
		// Hérité via IGraphics
		virtual bool Initialize(const std::string& Title, int Width, int Height) override;
		virtual void Shutdown() override;
		virtual void SetColor(const Color& color) override;
		virtual void Clear() override;
		virtual void Present() override;
		virtual void DrawRect(float x, float y, float w, float h, const Color& color) override;
		virtual void DrawRect(const RectF& rect, const Color& color) override;
		virtual void FillRect(float x, float y, float w, float h, const Color& color) override;
		virtual void FillRect(const RectF& rect, const Color& color) override;
		virtual void DrawLine(float x1, float y1, float x2, float y2, const Color& color) override;
		virtual size_t LoadTexture(const std::string& filename) override;
		virtual void DrawTexture(size_t id, const RectI& src, const RectF& dst, double angle, const Flip& flip, const Color& color) override;
		virtual void DrawTexture(size_t id, const RectF& dst, const Color& color) override;
		virtual void DrawTexture(size_t id, const Color& color) override;
		virtual void GetTextureSize(size_t id, int* w, int* h) override;
		virtual size_t LoadFont(const std::string& filename, int fontSize) override;
		virtual void DrawString(const std::string& text, size_t fontId, float x, float y, const Color& color) override;
		virtual void GetTextSize(const std::string& text, size_t fontId, int* w, int* h) override;
	};
}