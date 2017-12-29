#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



Stack::Stack()
{
	stk = NULL;
}

//Возврат выделенной памяти в "кучу".
Stack::~Stack()
{
	zveno *tek, *qDelete;

	tek = stk;
	if (tek != NULL)
	{
		qDelete = tek->next;
		while (qDelete != NULL)
		{
			delete tek;
			tek = qDelete;
			qDelete = qDelete->next;
		}
		delete tek;
	}
}

void Stack::POSTROENIE()
//Построение стека, заданного указателем stk. 
{
	zveno *tek;
	int el;

	printf("Вводите элементы стека:\n");
	scanf("%d", &el);
	while (el != 0)
	{
		tek = new (zveno);
		tek->valueInt = el;
		tek->next = stk;
		stk = tek; 
		scanf("%d", &el);
	}
}

void Stack::VYVOD()
//Вывод содержимого стека, заданного указателем stk.
{
	zveno *tek;

	printf("Содержимое стека: "); 
	tek = stk;
	while (tek != NULL)
	{
		printf("%d ", tek->valueInt);
		tek = tek->next;
	}
	printf("\n");
}

void Stack::push(int el)
//Помещение элемента el в стек stk.
{
	zveno *qDelet;

	qDelet = new (zveno);
	qDelet->valueInt = el;
	qDelet->next = stk;
	stk = qDelet;
}

void Stack::pop()
//Удаление элемента из стека, заданного указателем stk.
//Значение информационного поля удаляемого элемента 
//помещается в параметр klad.
{
	zveno *qDelet;

	if (stk == NULL)
		printf("Стек пуст!\n");
	else
	{
		klad = stk->valueInt;
		qDelet = stk;
		stk = stk->next;
		delete qDelet;
	}
}
