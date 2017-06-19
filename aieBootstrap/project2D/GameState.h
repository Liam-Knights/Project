#pragma once
#include "State.h"
#include "ObjectPool.h"

class GameState
{
public:
	GameState();
	~GameState();

	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
private:

	float m_timer;
	ObjectPool* Obj01;
	Font* m_font;
};
