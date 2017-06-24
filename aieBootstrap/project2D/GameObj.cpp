#include "GameObj.h"
#include "cmath"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"
#include <time.h>



GameObj::GameObj()
{
	//sets the timer to 0
	m_timer = 0;
	//sets m_bActive to false initialy
	m_bActive = false;
}


GameObj::~GameObj()
{
	//defuat destructor
}

void GameObj::updateGlobalTransform(float fDeltaTime)
{
	//adds deltaTime to m_timer
	m_timer += fDeltaTime;

	//resets the timer to 0 and sets m_bActive to false
	if (m_timer > 15)
	{ 
		m_bActive = false;

		m_timer = 0;
	}
}

void GameObj::Draw(aie::Renderer2D* m_2dRender)
{
	//sets the colour to pinkish
	m_2dRender->setRenderColour(70, 0, 100, 100);
	//draws the circle and sets its position
	m_2dRender->drawCircle(sin(m_timer) * 100 + 700, tan(m_timer) * 100 + 650, sin(m_timer) * 100 + 50);
}
void GameObj::setActive(bool bActive)
{
	//sets bActive to tru just in case
	bActive = true;
	//sets m_bActive to bActive
	m_bActive = bActive;
}

bool GameObj::getActive()
{
	//m_bActive
	return m_bActive;
}
