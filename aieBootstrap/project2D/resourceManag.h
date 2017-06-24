#pragma once
#include "dyna.h"
#include "resource.h"
#include "string.h"
#include <crtdbg.h>

template <typename t> 
class resourceManag
{
public:


	t* loadResource(char* szFileName, int size)
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			if (strcmp(m_ResourceList[i]->m_szFileName, szFileName) == 0)
			{
				return m_ResourceList[i]->m_Data;
			}
		}
		
		resource<t>* pResource = new resource<t>(szFileName, size);
		_ASSERT(pResource);
		m_ResourceList.pushBack(pResource);
		return pResource->m_Data;
		
	}
	
	void unloadAll()
	{
		for (int i = 0; i < m_ResourceList.Size(); ++i)
		{
			delete m_ResourceList[i];
		}
		m_ResourceList.clear();
	}

	static void create()
	{
		if (!m_Pinstance)
		{	
			
			m_Pinstance = new resourceManag<t>();
			_ASSERT(m_Pinstance);
		}
	}

	static void Delete()
	{
		delete m_Pinstance;
		delete pResource;
	}

	static resourceManag<t>* getinstance()
	{
		return m_Pinstance;
	}

private:
	resourceManag() {}
	~resourceManag()
	{
		unloadAll();
	}

	dynamArray<resource<t>*> m_ResourceList;
	static resourceManag<t>* m_Pinstance;

};

template <typename t>
resourceManag<t>* resourceManag<t>::m_Pinstance = nullptr;