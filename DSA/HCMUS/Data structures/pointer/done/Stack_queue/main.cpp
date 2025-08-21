#include"main.h"

int main(){
    STACK s;
    QUEUE q;
    s = InitializeStack(1);
    pushStack(s,2);
    pushStack(s,3);
    pushStack(s,4);
    pushStack(s,5);
    pushStack(s,6);
    cout << "Number of elements in Stack : " << countStack(s) << endl;
    while (!isEmptyStack(s))
    {
        int x;
        popStack(s,x);
        cout << x << " ";
    }
    cout << endl;
    q = InitializeQueue(1);
    enQueue(q,2);
    enQueue(q,3);
    enQueue(q,4);
    enQueue(q,5);
    enQueue(q,6);
    enQueue(q,7);
    enQueue(q,8);
    cout << "Number of elements in Stack : " << countQueue(q) << endl;
    while (!isEmptyQueue(q))
    {
        int x;
        deQueue(q,x);
        cout << x << " ";
    }
    return 0;
}