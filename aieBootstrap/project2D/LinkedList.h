#pragma once
#include "listNode.h"
#include <iostream>

using namespace std;
template <typename t>
class LinkedList
{
public:
	LinkedList() 
	{
		start = new listNode<t>();
		end = new listNode<t>();
		start->next = end;
		start->prev = nullptr;
		end->next = nullptr;
		end->prev = start;

	}
	~LinkedList() 
	{
		delete start;
		delete end;
	}

	void insert(t value, listNode<t>* prev, listNode<t>* next)
	{
		listNode<t>* N1 = new listNode<t>();
		N1->data = value;
		N1->next = next;
		prev->next = N1;
		next->prev = N1;
		N1->prev = prev;
		++nCount;
	}

	void pushback(t value)
	{
		insert(value, end->prev, end);
	}

	void pushFront(t value)
	{
		insert(value, start, start->next);
	}

	void IndexInsert(int index, t values)
	{
		listNode<t>* current = start;
		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
			{
				cout << "invalaid" << endl;
				return value;
			}
			current = current->next;
		}
		insert(value, current, current->next)
	}

	t first()
	{
		if (start->next == end)
		{
			cout << "list is empty \n";
			return defualt;
		}
		else
		{
			t value = start->next->data;
			return value;
		}
	}

	t last()
	{
		if (start->next == end)
		{
			cout << "list is empty \n";
			return defualt;
		}
		else
		{
			t value = end->prev->data;
			return value;
		}

	}
	
	int count()
	{
		return nCount;
	}

	void erase(int index)
	{
		listNode<t>* current = start;
		for (int i = 0; i < index; ++i)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			current = current->next;
		}
		if (current == start || current == end)
		{
			cout << "Cannot delete start and end!" << endl;
			return;
		}
		current->next->prev = current->prev;
		current->prev->next = current->next;
		delete current;
	}

	void remove(t value)
	{
		listNode<t>* temp = nullptr;
		listNode<t>* current = start;
		while (current->next != end)
		{
			if (current->next == end)
			{
				cout << "Invalid index location!" << endl;
				return;
			}
			if (current->data == value)
			{
				temp = current->prev;
				current->next->prev = current->prev;
				current->prev->next = current->next;
				delete current;
				current = temp;
			}
			current = current->next;
		}
	}

	t popFront()
	{
		listNode<t>* n = start->next;
		t temp = n->data;
		if (n != end)
		{


			n->next->prev = start;
			start->next = n->next;

			delete n;
			return temp;
			--nCount;
		}
		else
			return defualt;
	}

	t popback()
	{
		listNode<t>* n = end->prev;
		t temp = n->data;
		if (n != end)
		{

			n->prev->next = end;
			end->prev = n->prev

				delete n;
			return temp;
			--nCount
		}
		else
		{
			return defualt
		}
	}

	bool empty()
	{
		if (start->next == end)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void clear()
	{
		while (start-> != end)
		{
			popback();
		}
	}

private:
	int nCount = 0;
	listNode<t>* start;
	listNode<t>* end;
	t defualt;
};

