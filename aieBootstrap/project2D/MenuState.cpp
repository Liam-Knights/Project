#include "MenuState.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"
#include "input.h"

MenuState::MenuState()
{
	resourceManag<Font>* MenuStateMan = resourceManag<Font>::getinstance();
	m_font = MenuStateMan->loadResource("./font/consolas_italic.ttf", 50);

}


MenuState::~MenuState()
{
	delete m_font;
}

void MenuState::OnEnter()
{
	
}

void MenuState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_ENTER))
	{
		pMachine->PopState();
	}
}

void MenuState::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "press enter to play", 100, 600);
}

void MenuState::OnExit()
{
	
}