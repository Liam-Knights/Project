#include "GameState.h"
#include "resourceManag.h"
#include "stateMachine.h"
#include "font.h"
#include "Input.h"


GameState::GameState()
{
	Input* input = Input::getInstance();
	resourceManag<Font>* GameStateMan = resourceManag<Font>::getinstance();
	m_font = GameStateMan->loadResource("./font/consolas_italic.ttf", 50);

	Obj01 = new ObjectPool(99);

}


GameState::~GameState()
{
	delete m_font;
	delete Obj01;
}

void GameState::OnEnter()
{

}

void GameState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	Input* input = Input::getInstance();
	if (input->isKeyDown(INPUT_KEY_ENTER))
	{

	}
	if (input->isKeyDown(INPUT_KEY_P))
	{
		pMachine->PushState(4);
	}
	
}

void GameState::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawText(m_font, "ENTER TO SPAWN OBJECT", 450, 400);
	m_2dRenderer->drawText(m_font, "P TO PAUSE THE GAME", 250, 300);
}

void GameState::OnExit()
{

}