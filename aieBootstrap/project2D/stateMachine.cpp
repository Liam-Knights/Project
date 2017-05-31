#include "stateMachine.h"



stateMachine::stateMachine()
{
	m_nCurrentState = -1;
}


stateMachine::~stateMachine(){}


void stateMachine::Update(float fDeltaTime)
{
	if (m_StateList.Size() <= 0)
	{
		return;
	}
	m_StateList[m_nCurrentState]->OnUpdate(fDeltaTime);
}

void stateMachine::Draw(Renderer2D* m_2dRender)
{
	if (m_StateList.Size() <= 0)
	{
		return;
	}
	m_StateList[m_nCurrentState]->OnDraw(m_2dRender);
}

void stateMachine::setState(int nStateIndex)
{
	if (m_StateList.Size() <= 0)
	{
		m_StateList[m_nCurrentState]->OnExit();
	}
	m_nCurrentState = nStateIndex;

	m_StateList[m_nCurrentState]->OnEnter();
}

void stateMachine::addState(int nStateIndex, State* pState)
{
	m_StateList.insert(nStateIndex, pState);
}