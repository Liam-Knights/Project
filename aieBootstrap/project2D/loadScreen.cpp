#include "loadScreen.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"


loadScreen::loadScreen()
{
	//sets the timer to 0
	m_timer = 0;
	//gets the instance for the font
	resourceManag<Font>* ResMan = resourceManag<Font>::getinstance();
	//thest the font and its size
	m_font = ResMan->loadResource("./font/consolas_italic.ttf", 50);

}


loadScreen::~loadScreen()
{
	//delets the font
	delete m_font;
}

void loadScreen::OnEnter(StateMachine* pMachine)
{
	//stays empty
}

void loadScreen::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	//adds deltaTime to the timer
	m_timer += fDeltaTime;

	//pops the state if the timer is above 2 or higher
	if (m_timer >= 2)
	{
		pMachine->PopState();
	}
}

void loadScreen::OnDraw(Renderer2D* m_2dRenderer)
{
	//draws the loading screen text and where it is
	m_2dRenderer->drawText(m_font, "please wait for loading screen", 250, 400);
}

void loadScreen::OnExit(StateMachine* pMachine)
{
	//stays empty
}