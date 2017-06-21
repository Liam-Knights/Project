#include "GameObj.h"
#include "cmath"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"



GameObj::GameObj()
{
	m_timer = 0;
	m_bActive = false;
}


GameObj::~GameObj()
{

}

void GameObj::updateGlobalTransform(float fDeltaTime)
{
	m_timer += fDeltaTime;

	if (m_timer > 15)
	{ 
		m_bActive = false;

		m_timer = 0;
	}
}

void GameObj::Draw(aie::Renderer2D* m_2dRender)
{
	m_2dRender->setRenderColour(70, 0, 100, 100);
	m_2dRender->drawCircle(sin(m_timer) * 100 + 700, tan(m_timer) * 100 + 650, sin(m_timer) * 100 + 50);
}
void GameObj::setActive(bool bActive)
{
	bActive = true;
	m_bActive = bActive;
}

bool GameObj::getActive()
{
	return m_bActive;
}
