#include "Stack.h"

Stack::Stack() {
	top = nullptr;
	size = 0;
}

bool Stack::isEmpty() {
	if (size == 0) return true;
	else return false;
}

void Stack::push(int val) {
	Node* node = new Node;
	node->value = val;
	node->prev = top;
	top = node;
	size++;
}

int Stack::pop() {
	if (isEmpty()) {
		throw "Стек пуст!";
	}
	int v;
	v = top->value;
	Node* tmp = top;
	top = top->prev;
	delete tmp;
	size--;
	return v;
}

int* Stack::getLast() {
	return &top->value;
}
int Stack::getSize() {
	return size;
}
