#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct Stack {
    int data[MAX];
    int top;
};

void createStack(Stack &s);
bool isEmpty(Stack s);
bool isFull(Stack s);

void push(Stack &s, int x);
void pop(Stack &s);
void pushAscending(Stack &s, int x);
void printInfo(Stack s);
void balikStack(Stack &s);

#endif
