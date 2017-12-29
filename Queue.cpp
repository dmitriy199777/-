#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



Queue::Queue()
{
	nach = konec = NULL;
}

// ¬озврат выделенной пам€ти в "кучу".
Queue::~Queue()
{
	zveno *qDelet;

	qDelet = nach;
	if (nach != NULL)
	{
		while (nach != konec)
		{
			nach = (*qDelet).next;
			delete qDelet;
			qDelet = nach;
		}
		delete nach;
		nach = konec = NULL;
	}
}

void Queue::POSTROENIE()
// ѕостроение очереди на базе однонаправленного списка.
// без заглавного звена.
// nach - указатель на начало очереди. 
// konec - указатель на конец очереди. 
{
	zveno *rab;
	int el;

	printf("¬водите элементы очереди:\n");
	scanf("%d", &el);
	if (el != 0)
	{
		rab = new (zveno);
		(*rab).valueInt = el;
		(*rab).next = NULL;
		nach = rab; 
		konec = rab; 
		scanf("%d", &el);
		while (el != 0)
		{
			rab = new (zveno);
			(*rab).valueInt = el;
			(*rab).next = NULL;
			(*konec).next = rab;
			konec = rab; 
			scanf("%d", &el);
		}
	}
	else
	{
		rab = NULL; 
		nach = rab; 
		konec = rab;
	}
}

void Queue::VYVOD()
// ¬ывод содержимого очереди.
// nach - указатель на начало очереди.
// konec - указатель на конец очереди. 
{
	zveno *rab;
	printf("ќчередь: ");
	rab = nach;
	while (rab != NULL)
	{
		printf("%d ", (*rab).valueInt);
		rab = (*rab).next;
	}
	printf("\n");
}

void Queue::push(int el)
// ƒобавление звена с информационным полем el к очереди,
// определенной указател€ми  nach и konec. 
{
	zveno *rab;

	rab = new (zveno);
	(*rab).valueInt = el;
	(*rab).next = NULL;
	if (nach != NULL)
	{
		(*konec).next = rab; 
		konec = rab;
	}
	else
	{
		nach = rab; 
		konec = rab;
	}
}

void Queue::pop()
// ”даление звена из очереди, определенной указател€ми
// nach и konec, с помещением его информационного пол€ в 
// параметр klad.
{
	zveno *qDelet;

	if (nach == NULL)
		printf("”далить нельз€, так как очередь пуста!\n");
	else
	{
		klad = (*nach).valueInt;
		qDelet = nach;
		nach = (*nach).next; 
		delete qDelet;
	}
}
