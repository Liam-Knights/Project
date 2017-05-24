#include "ObjectPool.h"
#include "entity.h"

ObjectPool::ObjectPool(int nMaxSize)
{
	m_nMaxSize = nMaxSize;
	m_pPool = new entity*[nMaxSize];

	for (int i = 0; i < nMaxSize; ++i)
	{
		m_pPool[i] = new entity();
	}
}

ObjectPool::~ObjectPool()
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}
	delete[] m_pPool;
}

entity* ObjectPool::Allocate() 
{
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (!m_pPool[i]->getActive())
		{
			m_pPool[i]->setActive(true);
			return m_pPool[i];
		}
	}

	return nullptr;
}

void ObjectPool::DeAllocate(entity* object)
{
	object->setActive(false);
}