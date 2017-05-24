#pragma once
#include "Renderer2D.h"
class State
{
public:
	State();
	~State();

	virtual void OnEnter() = 0;
	virtual void OnUpdate(float fDeltaTime) = 0;
	virtual void OnDRaw(Renderer2D* m_2dRender) = 0;
	virtual void OnExit() = 0;


};

