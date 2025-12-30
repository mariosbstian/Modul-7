#ifndef STACK1_H
#define STACK1_H

typedef int DataType;

struct Stack {
    DataType items[20];
    int topIndex;
};

void initStack(Stack &S);
void pushItem(Stack &S, DataType value);
DataType popItem(Stack &S);
void showStack(const Stack &S);
void reverseStack(Stack &S);

void pushAscending(Stack &S, DataType value);

#endif
