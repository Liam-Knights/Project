#pragma once
#include "Renderer2D.h"
using namespace aie;

class StateMachine;

class State
{
public:
	State();
	~State();

	virtual void OnEnter(StateMachine* pMachine) = 0;
	virtual void OnUpdate(float fDeltaTime, StateMachine* pMachine) = 0;
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;
	virtual void OnExit(StateMachine* pMachine) = 0;

};

