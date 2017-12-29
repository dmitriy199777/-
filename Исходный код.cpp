#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Queue.h"
#include "Stack.h"

void main()
{
	setlocale(LC_ALL, "RUS");

	//////////////////////////
	////////////////////////// нвепедэ.
	//////////////////////////
	Queue queue;

	queue.POSTROENIE();
	queue.VYVOD();

	queue.push(2);
	queue.VYVOD();

	queue.VYVOD();

	queue.pop();
	queue.VYVOD();

	//////////////////////////
	////////////////////////// ярей.
	//////////////////////////
	Stack MyStack;

	MyStack.POSTROENIE();
	MyStack.VYVOD();

	MyStack.push(123);
	MyStack.VYVOD();

	MyStack.pop();
	MyStack.VYVOD();

	system("pause");

}