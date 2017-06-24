#include "PauseState.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"
#include "Input.h"


PauseState::PauseState()
{
	//gets the font and creats pauseStateMan
	resourceManag<Font>* PauseStateMan = resourceManag<Font>::getinstance();
	//gets the font and its size
	m_font = PauseStateMan->loadResource("./font/consolas_italic.ttf", 50);

}


PauseState::~PauseState()
{
	//deletes font
	delete m_font;
}

void PauseState::OnEnter(StateMachine* pMachine)
{
	//calls set backround to make the backround invisable
	pMachine->setBackround(true);
}

void PauseState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	//sets imput to get instance
	Input* input = Input::getInstance();

	//pops the state when the p key is enterd
	if (input->wasKeyPressed(INPUT_KEY_P))
	{
		pMachine->PopState();
	}
}

void PauseState::OnDraw(Renderer2D* m_2dRenderer)
{
	//draws the text for the pause screen and places its position on the screen
	m_2dRenderer->drawText(m_font, "press p to un-Pause", 50, 600);
}

void PauseState::OnExit(StateMachine* pMachine)
{
	//sets backround to false
	pMachine->setBackround(false);
}