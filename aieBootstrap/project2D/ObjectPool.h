#pragma once
class entity;

class ObjectPool
{
public:

	ObjectPool(int nMaxSize);

	~ObjectPool();
	entity* Allocate();
	void DeAllocate(entity* object);

private:
	entity** m_pPool;
	int m_nMaxSize;
};

