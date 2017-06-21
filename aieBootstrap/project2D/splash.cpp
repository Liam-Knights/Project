#include "splash.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"


splash::splash()
{
	m_timer = 0;
	resourceManag<Font>* splashMan = resourceManag<Font>::getinstance();
	m_font = splashMan->loadResource("./font/consolas_italic.ttf", 50);

}


splash::~splash()
{
	delete m_font;
}

void splash::OnEnter(StateMachine* pMachine)
{

}

void splash::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	m_timer += fDeltaTime;

	if (m_timer >= 2)
	{
		pMachine->PopState();
	}
}

void splash::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "splash screen", 450, 400);
}

void splash::OnExit(StateMachine* pMachine)
{

}