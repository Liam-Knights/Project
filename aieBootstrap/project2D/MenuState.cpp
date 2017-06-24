#include "MenuState.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"
#include "input.h"

MenuState::MenuState()
{
	//sets the font and creats menu state
	resourceManag<Font>* MenuStateMan = resourceManag<Font>::getinstance();
	//sets the font and the size of the font
	m_font = MenuStateMan->loadResource("./font/consolas_italic.ttf", 50);

}


MenuState::~MenuState()
{
	//delets font
	delete m_font;
}

void MenuState::OnEnter(StateMachine* pMachine)
{
	//empty
}

void MenuState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	//sets the imput and gets the instance
	Input* input = Input::getInstance();
	//if enter is pressed pop the state
	if (input->isKeyDown(INPUT_KEY_ENTER))
	{
		pMachine->PopState();
	}
}

void MenuState::OnDraw(Renderer2D* m_2dRenderer)
{
	//draws the menu text and where it is
	m_2dRenderer->drawText(m_font, "press enter to play", 100, 600);
}

void MenuState::OnExit(StateMachine* pMachine)
{
	//empty
}