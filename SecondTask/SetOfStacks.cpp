#include "SetOfStacks.h"

SetOfStacks::SetOfStacks() {
	stacks = new vector<Stack>();
	size = 0; maximum = 3;
}

SetOfStacks::SetOfStacks(int limit) {
	stacks = new vector<Stack>();
	size = 0; maximum = limit;
}

SetOfStacks::~SetOfStacks() {
	stacks->clear();
	delete stacks;
}

void SetOfStacks::push(int val) {
	if (stacks->empty()) {
		stacks->push_back(Stack());
	}
	Stack& last = stacks->back();
	if (last.getSize() < maximum) {
		last.push(val);
	}
	else {
		Stack newStack;
		newStack.push(val);
		stacks->push_back(newStack);
	}
	size++;
	cout << "\n���������� ������: " << stacks->size() << endl;
	cout << "����� " << size << " �������(�)" << endl;
}

int SetOfStacks::pop() {
	if (stacks->empty()) {
		throw "��� ������ ����!";
	}
	Stack& last = stacks->back();
	int data = last.pop();
	if (last.isEmpty()) {
		stacks->pop_back();
	}
	size--;
	return data;
}

int SetOfStacks::GetNumOfEl() {
	return size;
}
int SetOfStacks::GetNumOfSt() {
	return stacks->size();
}
void SetOfStacks::SetMaximum(int limit) {
	maximum = limit;
}