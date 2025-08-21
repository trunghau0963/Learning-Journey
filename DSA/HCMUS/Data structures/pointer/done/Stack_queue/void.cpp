#include"main.h"

STACK InitializeStack(int data){
    STACK s;
    NODE *p = new NODE;
    p->key = data;
    p->pNext = nullptr;
    if(p == nullptr){
        s.pTop = nullptr;
    }
    s.pTop = p;
    return s;
}
bool isEmptyStack(STACK s){
    if(s.pTop == nullptr){
        return true;
    }
    return false;
}
bool pushStack(STACK &s, int key){
    NODE *p = new NODE {key,nullptr};
    if(p == nullptr) return false;
    else if(isEmptyStack(s)) s.pTop = p;
    else{
        p->pNext = s.pTop;
        s.pTop = p;
    }
    return true;
    //fifo
}
bool popStack(STACK &s, int &key){
    if(isEmptyStack(s)) return false;
    else{
        NODE *temp = s.pTop;
        key = temp->key;
        s.pTop = temp->pNext;
        temp->pNext = nullptr;
        delete temp;
    }
    return true;
}
int countStack(STACK s){
    int cnt = 0;
    for(NODE *temp = s.pTop; temp != nullptr; temp = temp->pNext){
        cnt++;
    }
    return cnt;
}

QUEUE InitializeQueue(int data){
    QUEUE q;
    NODE *p = new NODE;
    p->key = data;
    p->pNext = nullptr;
    if(p == nullptr){
        q.pHead = q.pTail = nullptr;
    }
    q.pHead = p;
    for (NODE *p = q.pHead; p != nullptr; p = p->pNext)
    {
        q.pTail = p;
    }
    return q;
}
bool isEmptyQueue(QUEUE q){
    if(q.pHead == nullptr){
        return true;
    }
    return false;
}
bool enQueue(QUEUE &q,int key){
    NODE *p = new NODE{key, nullptr};
    if(p == nullptr) return false;
    else if(isEmptyQueue(q)) q.pHead = q.pTail = p;
    else{
        q.pTail->pNext = p;
        q.pTail = p;
    }
    return true;
}
bool deQueue(QUEUE &q, int &key){
    if(isEmptyQueue(q)) return false;
    else{
        NODE *temp = q.pHead;
        key = temp->key;
        q.pHead = temp->pNext;
        temp->pNext = nullptr;
        delete temp;
    }
    return true;
}
int countQueue(QUEUE q){
    int cnt = 0;
    for(NODE *temp = q.pHead; temp != nullptr; temp = temp->pNext){
        cnt++;
    }
    return cnt;
}