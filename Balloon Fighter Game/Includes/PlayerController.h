#include "IUpdateable.h"
using namespace Engine;

class PlayerController : IUpdateable
{
	// Hérité via IUpdateable
public:
	virtual void Update() override;
private:

};