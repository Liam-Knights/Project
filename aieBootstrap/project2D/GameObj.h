#pragma once
#include "entity.h"
#include "ObjectPool.h"
class GameObj :public entity
{
public:
	//constructor sets timer and the m_bActive
	GameObj();
	//defualt destructor
	~GameObj();


	//function made to update the object
	//its base function is located in entity and is empty
	void updateGlobalTransform(float fDeltaTime);

	// draws a moving circle that changes size and moves up the scren kinda like a bubble effect
	//its base function is located in entity and is empty
	void Draw(aie::Renderer2D* m_2dRender);

	//sets m_bActive andbActive
	void setActive(bool bActive);

	//returns m_bActive
	bool getActive();

private:
	int colour;
	float m_timer;
	bool m_bActive;
};

