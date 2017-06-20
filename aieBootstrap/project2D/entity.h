#pragma once
#include "Renderer2D.h"
class entity
{
public:
	entity();
	~entity();

	virtual void setActive(bool bActive);
	virtual bool getActive();

	//function made to update the entire program
	virtual void updateGlobalTransform(float fDeltaTime);

	// a basic draw function it is epmty
	virtual void Draw(aie::Renderer2D* m_2dRender);

private:
	bool m_bActive;

};

