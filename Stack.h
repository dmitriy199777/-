#pragma once
#include "AbstractClass.h"

class Stack : public AbstractClass
{
private:
	zveno *stk;
	int klad;
public:
	Stack();
	~Stack();
	void POSTROENIE();
	void VYVOD();
	void push(int);
	void pop();
};

