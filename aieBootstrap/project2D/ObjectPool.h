#pragma once
#include "Renderer2D.h"
#include "GameObj.h"
class GameObj;

class ObjectPool
{
public:

	ObjectPool(int nMaxSize);

	~ObjectPool();
	GameObj* Allocate();
	void DeAllocate(GameObj* object);
	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* m_2dRenderer);

private:

	GameObj** m_pPool;
	int m_nMaxSize;
};

