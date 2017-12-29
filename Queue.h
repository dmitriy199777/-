#pragma once
#include "AbstractClass.h"

class Queue : public AbstractClass
{
private:
	zveno *nach, *konec;
	int klad;
public:
	Queue();
	~Queue();
	void POSTROENIE();
	void VYVOD();
	void push(int);
	void pop();
};

