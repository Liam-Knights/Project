#pragma once
#include "Renderer2D.h"
#include "dyna.h"
#include "State.h"


class stateMachine
{
public:
	stateMachine();
	~stateMachine();

	void Update(float fDeltaTime);
	void Draw(Renderer2D* m_2dRender);
	void setState(int nStateIndex);
	void addState(int nStateIndex, State* pState);


private:
		int m_nCurrentState;
		dynamArray<State*> m_StateList;
};

