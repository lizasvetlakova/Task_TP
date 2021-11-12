#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H
#include "Stack.h"
#include <vector>

using namespace std;

class SetOfStacks {
	vector<Stack>* stacks;
	int size;
	int maximum;
public:
	SetOfStacks();
	SetOfStacks(int limit);
	~SetOfStacks();

	void push(int val);
	int pop();

	void SetMaximum(int limit);
	int GetNumOfEl();
	int GetNumOfSt();
};
#endif 
