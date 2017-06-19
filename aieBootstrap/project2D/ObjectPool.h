#pragma once
#include "Renderer2D.h"
class entity;

class ObjectPool
{
public:

	ObjectPool(int nMaxSize);

	~ObjectPool();
	entity* Allocate();
	void DeAllocate(entity* object);
	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);

private:

	entity** m_pPool;
	int m_nMaxSize;
};

