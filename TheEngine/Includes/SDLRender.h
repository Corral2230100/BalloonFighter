#include "IGraphics.h"

class SDLRender : public Engine::IGraphics
{

public:
	void Draw(float dt, float LagCorrection) override;
private:

};