#include "loadScreen.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"


loadScreen::loadScreen()
{
	m_timer = 0;
	resourceManag<Font>* ResMan = resourceManag<Font>::getinstance();
	m_font = ResMan->loadResource("./font/consolas_italic.ttf", 50);

}


loadScreen::~loadScreen()
{
	delete m_font;
}

void loadScreen::OnEnter(StateMachine* pMachine)
{
	
}

void loadScreen::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	m_timer += fDeltaTime;

	if (m_timer >= 2)
	{
		pMachine->PopState();
	}
}

void loadScreen::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "please wait for loading screen", 250, 400);
}

void loadScreen::OnExit(StateMachine* pMachine)
{
	
}