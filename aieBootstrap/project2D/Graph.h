#pragma once
#include "GraphNode.h"
#include "LinkedList.h"
#include "Renderer2D.h"
#include "stack.h"

template <typename t>

class Graph 
{
public:
	Graph(){}
	~Graph(){}

	void insert(GraphNode<t>* node)
	{
		m_Nodes.pushback(node);
	}
	void remove(GraphNode<t>* node)
	{
		
	}
	void remove(t data){}

	void drawGraph(aie::Renderer2D* m_2DRender)  
	{
		stack<GraphNode<t>*> stack;
		stack.pushFront(m_Nodes[0]);

		while (!stack.empty())
		{
			GraphNode<t>*
		}
	}

private:

	LinkedList<GraphNode<t>*> m_Nodes;
};