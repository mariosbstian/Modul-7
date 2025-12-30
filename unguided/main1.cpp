#include <iostream>
#include "stack1.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    initStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    showStack(S);

    cout << "Membalik stack" << endl;
    reverseStack(S);
    showStack(S);

    return 0;
}
