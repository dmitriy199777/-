#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



Stack::Stack()
{
	stk = NULL;
}

//������� ���������� ������ � "����".
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
//���������� �����, ��������� ���������� stk. 
{
	zveno *tek;
	int el;

	printf("������� �������� �����:\n");
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
//����� ����������� �����, ��������� ���������� stk.
{
	zveno *tek;

	printf("���������� �����: "); 
	tek = stk;
	while (tek != NULL)
	{
		printf("%d ", tek->valueInt);
		tek = tek->next;
	}
	printf("\n");
}

void Stack::push(int el)
//��������� �������� el � ���� stk.
{
	zveno *qDelet;

	qDelet = new (zveno);
	qDelet->valueInt = el;
	qDelet->next = stk;
	stk = qDelet;
}

void Stack::pop()
//�������� �������� �� �����, ��������� ���������� stk.
//�������� ��������������� ���� ���������� �������� 
//���������� � �������� klad.
{
	zveno *qDelet;

	if (stk == NULL)
		printf("���� ����!\n");
	else
	{
		klad = stk->valueInt;
		qDelet = stk;
		stk = stk->next;
		delete qDelet;
	}
}
