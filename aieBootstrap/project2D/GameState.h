#pragma once
#include "State.h"
#include "ObjectPool.h"
#include "GameObj.h"

class GameState : public State
{
public:
	GameState();
	~GameState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);
private:

	float m_timer;
	ObjectPool* Obj01;
	Font* m_font;
};

