#include "StateMachine.h"
#include <crtdbg.h>
#include "Renderer2D.h"

using namespace aie;

StateMachine::StateMachine()
{
}

StateMachine::~StateMachine()
{
	while (m_CurrentStack.size() > 0)
		PopState();

	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

void StateMachine::Update(float deltaTime)
{
	if (m_CurrentStack.size() <= 0)
		return;
	
	m_CurrentStack.top()->OnUpdate(deltaTime, this);

}


void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if (m_CurrentStack.size() <= 0)
	{
		return;
	}
	if (onoff)
	{
		m_CurrentStack.SecondLast()->OnDraw(m_2dRenderer);
	}
	m_CurrentStack.top()->OnDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	// Example of Assert
	/*_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;*/

	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnExit(this);

	m_CurrentStack.push(m_StateList[nStateIndex]);
	m_CurrentStack.top()->OnEnter(this);
}

void StateMachine::PopState()
{
	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnExit(this);
	
	m_CurrentStack.pop();
	if (m_CurrentStack.size() > 0)
		m_CurrentStack.top()->OnEnter(this);
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	m_StateList.insert(nStateIndex, pState);
}

void StateMachine::setBackround(bool OnOff)
{
	this->onoff = OnOff;
}