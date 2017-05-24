#pragma once
#include "LinkedList.h"

template <typename t>
class queue
{
public:
	queue(){}
	~queue(){}

	void push(t value)
	{
		Q.pushback(value);
	}

	void pop()
	{
		Q.popFront();
	}

	void top()
	{
		Q.first();
	}

	bool empty()
	{
		return Q.empty();
	}

	int size()
	{
		return Q.count();
		
	}

	LinkedList<t> Q;

};

