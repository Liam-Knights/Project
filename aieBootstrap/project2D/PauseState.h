#pragma once
#include "State.h"

class PauseState : public State
{
public:
	//constructor to set the font
	PauseState();
	//destructor to deleate the font
	~PauseState();

	//on enter function makes the backround invisable
	void OnEnter(StateMachine* pMachine);
	
	//on update is used to pop the state when enter is pressed
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	
	//draws the text for the pause screen
	void OnDraw(Renderer2D* m_2dRenderer);
	//on exit function sets the backround to false
	void OnExit(StateMachine* pMachine);
private:

	Font* m_font;
};

