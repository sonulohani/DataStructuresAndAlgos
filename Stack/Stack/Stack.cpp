/*
This file is part of project DataStructureAndAlgos.
Copyright © 2017 Sonu Lohani <sonulohani@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "Stack.h"
#include <iostream>

namespace DataStructuresAndAlgos
{
	Stack::Stack()
	{
	}

	void Stack::push(int data)
	{
		if (top == nullptr)
		{
			top = new Stack::node;
			top->data = data;
			top->link = nullptr;
		}
		else
		{
			Stack::node *pLastNode = getNodePrevToNodeSpecified();
			Stack::node *newNode = new Stack::node;
			newNode->data = data;
			newNode->link = nullptr;
			pLastNode->link = newNode;
		}
	}

	void Stack::pop()
	{
		try
		{
			if (isEmpty())
			{
				throw "Stack is empty\n";
			}
			Stack::node *pLastNode = getNodePrevToNodeSpecified();
			if (pLastNode != top)
			{
				Stack::node *pPrevToLastNode = getNodePrevToNodeSpecified(pLastNode);
				pPrevToLastNode->link = nullptr;
			}
			std::cout << "Deleted element is:- " << pLastNode->data << std::endl;
			bool isTop = ( top == pLastNode );
			delete pLastNode;
			pLastNode = nullptr;
			if (isTop)
			{
				top = pLastNode;
			}
		}
		catch (char* msg)
		{
			std::cout << msg;
		}
	}

	void Stack::print()
	{
		Stack::node *node = top;
		while (node != nullptr)
		{
			std::cout << node->data << std::endl;
			node = node->link;
		}
	}

	int Stack::size() const
	{
		Stack::node *lastNode = top;
		int count = 0;
		while (lastNode != nullptr)
		{
			lastNode = lastNode->link;
			count++;
		}
		return count;
	}

	int Stack::isEmpty() const
	{
		return top == nullptr;
	}

	Stack::node * Stack::getNodePrevToNodeSpecified(Stack::node *pNode) const
	{
		Stack::node *lastNode = top;
		while (lastNode->link != pNode)
		{
			lastNode = lastNode->link;
		}
		return lastNode;
	}
}
