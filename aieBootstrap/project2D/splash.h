#pragma once
#include "State.h"

class splash : public State
{
public:
	//constructor sets the timer and font
	splash();
	//deletes font
	~splash();

	//empty on enter function
	void OnEnter(StateMachine* pMachine);

	//updates the timer and pops the state
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);

	//draws the text to the screen
	void OnDraw(Renderer2D* m_2dRenderer);

	//empty on exit function
	void OnExit(StateMachine* pMachine);
private:

	float m_timer;
	Font* m_font;
};

