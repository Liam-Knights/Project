#include "PauseState.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"
#include "Input.h"


PauseState::PauseState()
{
	resourceManag<Font>* PauseStateMan = resourceManag<Font>::getinstance();
	m_font = PauseStateMan->loadResource("./font/consolas_italic.ttf", 50);

}


PauseState::~PauseState()
{
	delete m_font;
}

void PauseState::OnEnter(StateMachine* pMachine)
{
	pMachine->setBackround(true);
}

void PauseState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{

	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_P))
	{
		pMachine->PopState();
	}
}

void PauseState::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "press p to un-Pause", 50, 600);
}

void PauseState::OnExit(StateMachine* pMachine)
{
	pMachine->setBackround(false);
}