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

#include <iostream>
#include <cstdlib>
#include "Stack.h"

using namespace std;
using namespace DataStructuresAndAlgos;

namespace
{
	void showOption()
	{
		cout << "Welcome to the Stack Data Structure" << endl;
		cout << "Here are the operations you can perform in stack" << endl;
		cout << "Press 1 for entering the element in the stack" << endl;
		cout << "Press 2 for deleting the element in the stack" << endl;
		cout << "Press 3 to print the elements in the stack" << endl;
		cout << "Press 4 to check if the stack is empty" << endl;
		cout << "Press any other key to exit from the program" << endl;
		cout << "Enter your choice:-";
	}
}

int main()
{
	Stack *pStack = new Stack;
	do
	{
		int choice;
		showOption();
		cin >> choice;
		system("clear");
		switch (choice)
		{
		case 1:
			cout << "Enter the element to insert:- ";
			int element;
			cin >> element;
			pStack->push(element);
			break;
		case 2:
			pStack->pop();
			break;
		case 3:
			cout << "Elements in stack are:-" << endl;
			pStack->print();
			break;
		case 4:
			cout << "Is stack empty:-" << pStack->isEmpty();
			break;
		default:
			delete pStack;
			pStack = nullptr;
			return 0;
		}
	} while (1);

	return 0;
}
