#pragma once
#include "State.h"

class MenuState : public State
{
public:
	//constructor to set the font
	MenuState();
	//destructor that deletes font
	~MenuState();

	//empty on enter function;
	void OnEnter(StateMachine* pMachine);

	//updates the timer and pops the state after the timer
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);

	//draws some text for the load
	void OnDraw(Renderer2D* m_2dRenderer);

	//empty on exit function
	void OnExit(StateMachine* pMachine);
private:

	Font* m_font;
};

