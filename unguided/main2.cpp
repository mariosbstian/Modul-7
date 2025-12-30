#include "stack2.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack s;
    createStack(s);

    pushAscending(s, 3);
    pushAscending(s, 4);
    pushAscending(s, 8);
    pushAscending(s, 2);
    pushAscending(s, 3);
    pushAscending(s, 9);

    printInfo(s);

    cout << "balik stack" << endl;
    balikStack(s);
    printInfo(s);

    return 0;
}