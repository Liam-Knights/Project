#pragma once
#include "LinkedList.h"

template <typename t>
class GraphNode
{
public:
	GraphNode() {}
	GraphNode(t data)
	{
		m_Data = data;
	}
	~GraphNode() {}
	void connect(GraphNode<t>* other)
	{
		m_Edges.pushback(other);
	}
	void RemoveCOnection(GraphNode<t>* other)
	{
		m_Edges.remove(other);
	}
	void setTrav(){}
	void getTrav(){}

private:

	LinkedList<GraphNode<t>*> m_Edges;
	t m_Data;
};