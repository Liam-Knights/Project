#pragma once


template <typename t>
class listNode
{

public:
	listNode() {};
	~listNode() {};

	t data;
	listNode* next;
	listNode* prev;
};

