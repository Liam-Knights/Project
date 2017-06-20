#include "GameObj.h"
#include "cmath"
#include "time.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"



GameObj::GameObj()
{
	m_timer = 0;
	srand(time(0));
	colour = rand() % 100;
	resourceManag<ObjectPool>* gameobject = resourceManag<ObjectPool>::getinstance();
	m_object = gameobject->loadResource("./font/consolas_italic.ttf", 50);
}


GameObj::~GameObj()
{
	delete m_object;
}

void GameObj::updateGlobalTransform(float fDeltaTime)
{
	m_timer += fDeltaTime;
	if (m_timer > 10)
	{
		setActive(false);
	}

}

void GameObj::Draw(aie::Renderer2D* m_2dRender)
{
	m_2dRender->setRenderColour(colour, colour, colour, colour);
	m_2dRender->drawCircle(sin(m_timer) * 100 + 700, 150, sin(m_timer) * 100 + 50);
}
