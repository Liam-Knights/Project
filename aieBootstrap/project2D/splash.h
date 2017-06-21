#pragma once
#include "State.h"

class splash : public State
{
public:
	splash();
	~splash();

	void OnEnter(StateMachine* pMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pMachine);
private:

	float m_timer;
	Font* m_font;
};

