#pragma once
#include "State.h"
class loadScreen : public State
{
public:
	loadScreen();
	~loadScreen();

	void OnEnter();
	void OnUpdate(float fDeltaTime, StateMachine* pMachine);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
private:
	
	float m_timer;
	aie::Font* m_font;
};

