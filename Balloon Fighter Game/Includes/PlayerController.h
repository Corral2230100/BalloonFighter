#include "IUpdateable.h"
using namespace Engine2;

class PlayerController : IUpdateable
{
	// H�rit� via IUpdateable
public:
	virtual void Update() override;
private:

};