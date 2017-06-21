#pragma once
#include "State.h"

class PauseState : public State
{
public:
	PauseState();
	~PauseState();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);
private:

	Font* m_font;
};

