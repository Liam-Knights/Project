#include "ObjectPool.h"
#include "entity.h"
#include <crtdbg.h>

ObjectPool::ObjectPool(int nMaxSize)
{
	//sets the size of the pool
	m_nMaxSize = nMaxSize;
	_ASSERT(m_pPool);
	m_pPool = new GameObj*[nMaxSize];

	for (int i = 0; i < nMaxSize; ++i)
	{
		_ASSERT(m_pPool[i]);
		m_pPool[i] = new GameObj();
	}
}

ObjectPool::~ObjectPool()
{
	//deletes every object in the pool
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		delete m_pPool[i];
	}
	delete[] m_pPool;
}

GameObj* ObjectPool::Allocate() 
{
	//allocates the object to the pool
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

void ObjectPool::DeAllocate(GameObj* object)
{
	//dealocates objects form the pool
	object->setActive(false);
}

void ObjectPool::Update(float fDeltaTime)
{
	//updates the pool
    for (int i = 0; i < m_nMaxSize; ++i)
    {
        if (m_pPool[i]->getActive())
        {
            m_pPool[i]->updateGlobalTransform(fDeltaTime);
        }
        else
            return;
    }
}

void ObjectPool::Draw(aie::Renderer2D* m_2dRenderer)
{
	//draws the object in the pool
	for (int i = 0; i < m_nMaxSize; ++i)
	{
		if (m_pPool[i]->getActive())
		{
			m_pPool[i]->Draw(m_2dRenderer);
		}
		else
			return;
	}
	
}