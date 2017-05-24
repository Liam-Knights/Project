#pragma once
#include <string.h>

template <typename t>
class resource
{
public:
	resource(char* szFileName)
	{
		int length = strlen(szFileName);
		m_szFileName = new char[length + 1];
		strcpy_s(m_szFileName, length, szFileName);

		m_Data = new t(szFileName);
	}
	~resource()
	{
		delete m_Data;
		delete[] m_szFileName;
	}

	char* m_szFileName;
	t m_Data

};

