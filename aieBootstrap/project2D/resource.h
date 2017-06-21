#pragma once
#include <string.h>
#include <crtdbg.h>

template <typename t>
class resource
{
public:
	resource(char* szFileName, int size)
	{
		int length = strlen(szFileName);
		_ASSERT(m_szFileName);
		m_szFileName = new char[length + 1];
		strcpy_s(m_szFileName, length + 1, szFileName);

		_ASSERT(m_Data);
		m_Data = new t(szFileName, size);
	}
	~resource()
	{
		delete m_Data;
		delete[] m_szFileName;
	}

	char* m_szFileName;
	t* m_Data;

};

