#pragma once
#include <memory.h>
#include <crtdbg.h>

template <typename t>
class dynamArray
{


public:

	dynamArray(int size = 0) 
	{
		int cap = size;
		if (cap <= 0)
		{
			cap = 1;
		}

		_ASSERT(data);
		data = new t[cap];
		m_nCapacity = cap;
		m_nUsed = 0;
	}

	~dynamArray() 
	{
		delete[] data;
	}

	dynamArray(const dynamArray& other)
	{

		m_nCapacity = other.m_nCapacity;
		m_nUsed = other.m_nUSed;

		_ASSERT(data);
		data = new t[m_nCapacity];
		mempcy(data, other.data, sizeof(t) * m_nCapacity);
	}

	void pushBack(t value)
	{
		if (m_nUsed >= m_nCapacity)
		{
			resize();
		}
		data[m_nUsed] = value;
		++m_nUsed;
	}

	void pushFront(t value)
	{
		insert(0, value);
	}

	void insert(int index, t value)
	{
		if (index > m_nUsed)
		{
			return;
		}
		if (m_nUsed >= m_nCapacity)
		{
			resize();
		}
		for (int i = m_nUsed - 1; i >= index; --i)
		{
			data[i + 1] = data[i];
		}
		data[index] = value;
		++m_nUsed;
	}

	void resize()
	{
		
		t* newData = new t[m_nCapacity * 2];
		_ASSERT(newData);
		memcpy(newData, data, sizeof(t) * m_nCapacity);
		delete data;
		data = newData;
		m_nCapacity = m_nCapacity * 2;

	}

	t popBack()
	{
		if (m_nUsed <= 0)
			return 0;
		
		--m_nUsed;

		return data[m_nUsed + 1];
	}

	t remove(int index)
	{
		t value = data[index];

		for (int i = index; index < m_nUsed; ++i)
		{
			data[i] = data[i + 1];
		}
		--m_nUsed;

		return value;

	}

	t popFront()
	{
		return remove(0);
	}
	void clear()
	{
		delete data;
		m_nUsed = 0;
	}

	void shrink()
	{

		int nCapacity = m_nUsed;
		if (nCapacity <= 0)
		{
			nCapacity = 1;
		}
		_ASSERT(newData);
		t* newData = new t[m_nCapacity];
		memcpy(newData, data, sizeof(t) * m_nCapacity);
		delete data;
		data = newData;
		m_nCapacity = m_nCapacity;

	}

	t& operator[](const int index)
	{
		return data[index];
	}

	int Size()
	{
		return m_nUsed;
	}

	int Capacity()
	{
		return m_nCapacity;
	}

	bool empty()
	{
		if (m_nUsed <= 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	t back()
	{
		return data[m_nUsed - 1];
	}

	t SecondLast()
	{
		return data[m_nUsed - 2];
	}
private:
	dynamArray& operator= (const dynamArray& other) = default;
	dynamArray(dynamArray&& other) = default;
	dynamArray& operator= (dynamArray&& other) = default;
	
	int m_nCapacity;
	int m_nUsed;
	t* data;

};

