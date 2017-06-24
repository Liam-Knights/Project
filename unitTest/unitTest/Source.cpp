#include <iostream>
#include "stack.h"
#include "dyna.h"
#include "LinkedList.h"
#include "queue.h"

using namespace std;

void dArray()
{
	dynamArray<int> dynam;

	cout << "dynamic array test \n";

	dynam.pushBack(1);
	cout << dynam.Size() << endl;

	dynam.pushFront(9);
	cout << dynam.Size() << endl;

	dynam.insert(1, 2);
	cout << dynam.Size() << endl;

	dynam.resize();
	cout << dynam.Capacity() << endl;

	dynam.popBack();
	cout << dynam.Size() << endl;

	dynam.shrink();
	cout << dynam.Size() << endl;

	dynam.clear();
	cout << dynam.Size() << endl <<endl;

	
}

void S_tack()
{
	Stack<int> stack;

	stack.push(6);
	stack.push(9);
	stack.push(4);
	cout << stack.size() << endl;
	cout << stack.top() << endl;

	stack.pop();
	cout << stack.size() << endl;

	stack.empty();
	cout << stack.size() << endl <<endl;
}

void L_List()
{
	LinkedList<int> list;

	list.pushback(8);
	list.pushback(3);
	list.pushback(6);
	cout << list.size() << endl;

	list.pushFront(1);
	list.pushFront(4);
	cout << list.size() << endl;

	list.popFront();
	cout << list.size() << endl;

	list.first();

	list.clear();
	cout << list.size() << endl << endl;

	
}

void Qu()
{
	queue<int> q;

	q.push(1);
	q.push(6);
	cout << q.size() << endl;

	q.top();

	q.pop();
	cout << q.size() << endl;

	q.empty();
	cout << q.size() << endl;
}

void main()
{
	dArray();
	S_tack();
	L_List();
	Qu();
	system("pause");
}