#pragma once
#include "State.h"

class loadScreen : public State
{
public:
	//constructor to set the tmer and the font
	loadScreen();
	//destructor that deletes font
	~loadScreen();

	//empty on enter function;
	void OnEnter(StateMachine* pMachine);
	
	//updates the timer and pops the state after the timer
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	
	//draws some text for the load
	void OnDraw(Renderer2D* m_2dRenderer);
	
	//empty on exit function
	void OnExit(StateMachine* pMachine);
private:
	
	float m_timer;
	Font* m_font;
};

