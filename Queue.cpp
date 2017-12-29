#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



Queue::Queue()
{
	nach = konec = NULL;
}

// ������� ���������� ������ � "����".
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
// ���������� ������� �� ���� ����������������� ������.
// ��� ���������� �����.
// nach - ��������� �� ������ �������. 
// konec - ��������� �� ����� �������. 
{
	zveno *rab;
	int el;

	printf("������� �������� �������:\n");
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
// ����� ����������� �������.
// nach - ��������� �� ������ �������.
// konec - ��������� �� ����� �������. 
{
	zveno *rab;
	printf("�������: ");
	rab = nach;
	while (rab != NULL)
	{
		printf("%d ", (*rab).valueInt);
		rab = (*rab).next;
	}
	printf("\n");
}

void Queue::push(int el)
// ���������� ����� � �������������� ����� el � �������,
// ������������ �����������  nach � konec. 
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
// �������� ����� �� �������, ������������ �����������
// nach � konec, � ���������� ��� ��������������� ���� � 
// �������� klad.
{
	zveno *qDelet;

	if (nach == NULL)
		printf("������� ������, ��� ��� ������� �����!\n");
	else
	{
		klad = (*nach).valueInt;
		qDelet = nach;
		nach = (*nach).next; 
		delete qDelet;
	}
}
