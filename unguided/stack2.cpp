#include "stack2.h"

void createStack(Stack &s) {
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}

bool isFull(Stack s) {
    return s.top == MAX - 1;
}

void push(Stack &s, int x) {
    if (!isFull(s)) {
        s.top++;
        s.data[s.top] = x;
    }
}

void pop(Stack &s) {
    if (!isEmpty(s)) {
        s.top--;
    }
}

void pushAscending(Stack &s, int x) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(s) && s.data[s.top] > x) {
        push(temp, s.data[s.top]);
        pop(s);
    }

    push(s, x);

    while (!isEmpty(temp)) {
        push(s, temp.data[temp.top]);
        pop(temp);
    }
}

void printInfo(Stack s) {
    cout << "[TOP] ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.data[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &s) {
    Stack temp;
    createStack(temp);

    while (!isEmpty(s)) {
        push(temp, s.data[s.top]);
        pop(s);
    }

    s = temp;
}
