#pragma once
#include "State.h"

class MenuState : public State
{
public:
	MenuState();
	~MenuState();
	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
private:

	Font* m_font;
};

