#ifndef STACK_H
#define STACK_H
#include <iostream>

using namespace std;

struct Node {
	int value;
	Node* prev;
};

class Stack {
	Node* top;
	int size;
public:
	Stack();
	~Stack() {};

	void push(int val);
	int pop();
	bool isEmpty();

	int* getLast();
	int getSize();
};
#endif 