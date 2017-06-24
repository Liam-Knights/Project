#pragma once
#include "Renderer2D.h"
#include "GameObj.h"
class GameObj;

class ObjectPool
{
public:
	//constructor the size of the pool
	ObjectPool(int nMaxSize);

	//deletes all the pointers for the pool
	~ObjectPool();

	//function to allocate and object in the pool
	GameObj* Allocate();

	//function to dealocate an object in the pool
	void DeAllocate(GameObj* object);

	//update function updates all the objects in the pool
	void Update(float fDeltaTime);
	//draws objects
	void Draw(aie::Renderer2D* m_2dRenderer);

private:

	GameObj** m_pPool;
	int m_nMaxSize;
};

