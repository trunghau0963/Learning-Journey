#include<iostream>
using namespace std;
struct NODE {
    int key;
    NODE* pNext;
};
struct STACK
{
    NODE *pTop;
};
struct QUEUE
{
    NODE *pHead;
    NODE *pTail;
};
STACK InitializeStack(int data);
bool isEmptyStack(STACK s);
bool pushStack(STACK &s, int key);
bool popStack(STACK &s, int &key);
int countStack(STACK s);
QUEUE InitializeQueue(int data);
bool isEmptyQueue(QUEUE q);
bool enQueue(QUEUE &q,int key);
bool deQueue(QUEUE &q, int &key);
int countQueue(QUEUE q);