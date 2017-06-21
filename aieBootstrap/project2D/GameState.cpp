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

	Obj01 = new ObjectPool(15);

}


GameState::~GameState()
{
	delete m_font;
	delete Obj01;
}

void GameState::OnEnter(StateMachine* pMachine)
{

}

void GameState::OnUpdate(float fDeltaTime, StateMachine* pMachine)
{
	Input* input = Input::getInstance();


	if (input->wasKeyPressed(INPUT_KEY_ENTER))
	{
		GameObj* p = Obj01->Allocate();
	}

	if (input->wasKeyPressed(INPUT_KEY_P))
	{
		pMachine->PushState(4);
	}
	Obj01->Update(fDeltaTime);
	
}

void GameState::OnDraw(Renderer2D* m_2dRenderer)
{
	Obj01->Draw(m_2dRenderer);

	m_2dRenderer->drawText(m_font, "ENTER TO SPAWN OBJECT", 450, 400 , 1);
	m_2dRenderer->drawText(m_font, "P TO PAUSE THE GAME", 250, 300, 1);
	
}

void GameState::OnExit(StateMachine* pMachine)
{

}