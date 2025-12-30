#include <iostream>
#include "stack1.h"
using namespace std;

void initStack(Stack &S) {
    S.topIndex = -1;
}

void pushItem(Stack &S, DataType value) {
    if (S.topIndex < 19) {
        S.topIndex++;
        S.items[S.topIndex] = value;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

DataType popItem(Stack &S) {
    if (S.topIndex >= 0) {
        DataType temp = S.items[S.topIndex];
        S.topIndex--;
        return temp;
    } else {
        cout << "Stack kosong!" << endl;
        return -1;
    }
}

void showStack(const Stack &S) {
    cout << "[TOP] ";
    for (int i = S.topIndex; i >= 0; i--) {
        cout << S.items[i] << " ";
    }
    cout << endl;
}

void reverseStack(Stack &S) {
    Stack temp;
    initStack(temp);

    while (S.topIndex >= 0) {
        pushItem(temp, popItem(S));
    }
    while (temp.topIndex >= 0) {
        pushItem(S, popItem(temp));
    }
}

void pushAscending(Stack &S, DataType value) {
    Stack temp;
    initStack(temp);

    while (S.topIndex >= 0 && S.items[S.topIndex] > value) {
        pushItem(temp, popItem(S));
    }

    pushItem(S, value);

    while (temp.topIndex >= 0) {
        pushItem(S, popItem(temp));
    }
}
