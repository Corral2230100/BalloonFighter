#include "IUpdateable.h"
using namespace Engine2;

class PlayerController : IUpdateable
{
	// Hérité via IUpdateable
public:
	virtual void Update() override;
private:

};