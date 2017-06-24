#include "splash.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"


splash::splash()
{
	//sets the timer to 0
	m_timer = 0;
	//creates the font 
	resourceManag<Font>* splashMan = resourceManag<Font>::getinstance();
	//gets the font and the size of the font
	m_font = splashMan->loadResource("./font/consolas_italic.ttf", 50);

}


splash::~splash()
{
	//delets font
	delete m_font;
}

void splash::OnEnter(StateMachine* pMachine)
{
	//empty
}

void splash::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	//adds deltatime to timer
	m_timer += fDeltaTime;

	//pops the state after timer gets to 2 or greater
	if (m_timer >= 2)
	{
		pMachine->PopState();
	}
}

void splash::OnDraw(Renderer2D* m_2dRenderer)
{
	//draws text to screen
	m_2dRenderer->drawText(m_font, "splash screen", 450, 400);
}

void splash::OnExit(StateMachine* pMachine)
{
	//empty
}