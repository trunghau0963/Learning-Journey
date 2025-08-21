#include <iostream>
using namespace std;
struct NODE
{
    int key;
    NODE *pNext;
};
struct List
{
    NODE *pHead;
    NODE *pTail;
};
NODE *createNode(int data)
{
    NODE *p = new NODE;
    p->key = data;
    p->pNext = nullptr;
    return p;
}
List *createList(NODE *pNode)
{
    List *l = new List;
    l->pHead = pNode;
    for (NODE *p = l->pHead; p != nullptr; p = p->pNext)
    {
        l->pTail = p;
    }
    return l;
}
void printList(List *L)
{
    for (NODE *p = L->pHead; p != nullptr; p = p->pNext)
    {
        cout << p->key << " ";
    }
    cout << endl;
}
bool addHead(List *&L, int data)
{
    NODE *p = createNode(data);
    if (L->pHead == nullptr)
    {
        L->pHead = L->pTail = p;
    }
    else
    {
        p->pNext = L->pHead;
        L->pHead = p;
    }
    return p;
}
bool addTail(List *&L, int data)
{
    NODE *p = createNode(data);
    if (L->pHead == nullptr)
    {
        L->pHead = L->pTail = p;
    }
    else
    {
        L->pTail->pNext = p;
        L->pTail = p;
    }
    return p;
}
void removeHead(List *&L)
{
    if (L->pHead == nullptr)
    {
        return;
    }
    else
    {
        NODE *p = L->pHead;
        L->pHead = L->pHead->pNext;
        delete p;
    }
}
void removeTail(List *&L)
{
    if (L->pHead == nullptr)
    {
        return;
    }
    else
    {
        for (NODE *p = L->pHead; p != nullptr; p = p->pNext)
        {
            if (p->pNext == L->pTail)
            {
                delete L->pTail;
                p->pNext = nullptr;
                L->pTail = p;
            }
        }
    }
}
void removeAll(List *&L)
{
    while (L->pHead != nullptr)
    {
        if (L->pHead == nullptr)
        {
            return;
        }
        else
        {
            NODE *p = L->pHead;
            L->pHead = L->pHead->pNext;
            delete p;
        }
    }
}
void removeBefore(List *L, int val)
{
    if (L->pHead == nullptr)
    {
        return;
    }
    else
    {
        NODE *temp = new NODE;
        for (NODE *p = L->pHead; p != nullptr; p = p->pNext)
        {
            if (p->pNext->key == val)
            {
                temp->pNext = p->pNext;
                p->pNext = nullptr;
                delete p;
                break;
            }
            temp = p;
        }
    }
}
void removeAfter(List *L, int val)
{
    if (L->pHead == nullptr)
    {
        return;
    }
    else
    {
        for (NODE *p = L->pHead; p != nullptr; p = p->pNext)
        {
            if (p->key == val)
            {
                NODE *h = p->pNext;
                p->pNext = p->pNext->pNext;
                p->pNext->pNext = nullptr;
                delete h;
            }
        }
    }
}
bool addPos(List *&L, int data, int pos)
{
    if (pos == 0 || L->pHead == nullptr)
    {
        addHead(L, data);
        return true;
    }
    else
    {
        NODE *temp = L->pHead;
        int cnt = 1;
        while (cnt != pos && temp != nullptr)
        {
            temp = temp->pNext;
            cnt++;
        }
        if (cnt != pos)
        {
            addTail(L, data);
        }
        else
        {
            NODE *h = createNode(data);
            h->pNext = temp->pNext;
            temp->pNext = h;
        }
        return true;
    }
    return false;
}
void removePos(List *&L, int pos)
{
    if (pos == 0 || L->pHead == nullptr)
    {
        removeHead(L);
    }
    else
    {
        NODE *temp = L->pHead;
        int cnt = 1;
        while (cnt != pos && temp != nullptr)
        {
            temp = temp->pNext;
            cnt++;
        }
        if (cnt != pos)
        {
            removeTail(L);
        }
        else
        {
            NODE *h = temp->pNext;
            temp->pNext = h->pNext;
            h->pNext = nullptr;
            delete h;
        }
    }
}
bool addBefore(List *L, int data, int val)
{
    if (L->pHead == nullptr)
    {
        addTail(L, data);
    }
    else
    {
        NODE *temp = L->pHead;
        while (temp->pNext->key != val)
        {
            temp = temp->pNext;
        }
        if (temp->pNext->key != val)
        {
            addTail(L, data);
        }
        else
        {
            NODE *h = createNode(data);
            h->pNext = temp->pNext;
            temp->pNext = h;
        }
        return true;
    }
    return false;
}
bool addAfter(List *L, int data, int val)
{
    if (L->pHead == nullptr)
    {
        addHead(L, data);
    }
    else
    {
        NODE *temp = L->pHead;
        while (temp->pNext != nullptr )
        {
            if(temp->key == val )
            {
                NODE *h = createNode(data);
                h->pNext = temp->pNext;
                temp->pNext = h;
                break;
            }
            temp = temp->pNext;
        }
        return true;
    }
    return false;
}
 int countElements(List* L){
    int cnt = 0;
    for(NODE *p = L->pHead; p != nullptr ; p = p->pNext){
        cnt++;
    }
    return cnt;
 }
List* reverseList(List* L){
    List *NewList = L;
    NODE *prev = nullptr;
    NODE *cur = NewList->pHead;
    NODE *next = NewList->pHead->pNext;
    while(next != nullptr){
        next = cur->pNext;
        cur->pNext = prev;
        prev = cur;
        cur = next;
    }
    NewList->pHead = prev;
    return NewList;
}
void removeDuplicate(List* &L){
    int length = countElements(L);
    bool checkList[length] {0};
    bool Duplicate;
    int cntI = 0,cntJ;
    // 2 3 4 1 2 7 3 2 
    for(NODE* i = L->pHead ;i != nullptr; i = i -> pNext){
        Duplicate = false;
        cntJ = cntI;
        for(NODE*j = i->pNext; j != nullptr; j = j->pNext){
            cntJ++;
            if(i->key == j->key){
                Duplicate = true;
                checkList[cntJ] = true;
            }
        }
        if(Duplicate == true ){
            checkList[cntI] = true;
            Duplicate = false;
        }
        cntI++;
    }
    for(int i = length - 1; i >= 0;i--){
        if(checkList[i]){
            removePos(L,i);
            // cout << i << " ";
        }
    }
}
bool removeElement(List* &L, int key){
    int length = countElements(L);
    bool checkList[length] {0}, check = false;
    int cntI = 0;
    for(NODE* i = L->pHead ;i != nullptr; i = i -> pNext){
        if(i->key == key){
            checkList[cntI] = true;
        }
        cntI++;
    }
    for(int i = length - 1; i >= 0;i--){
        if(checkList[i]){
            removePos(L,i);
            check = true;
        }
    }
    return check;
}
int main()
{
   // 2 3 4 1 2 7 3 2 
    NODE *head = new NODE{2, new NODE{3, new NODE{4, new NODE{1, new NODE{2, new NODE{7, new NODE{ 3, new NODE{2, new NODE {1,new NODE {3,new NODE {9,new NODE{12,nullptr}}}}}}}}}}}};
    List *L = createList(head);
    printList(L);
    addPos(L, 14, 4);
    printList(L);
    removePos(L, 3);
    printList(L);
    addBefore(L, 15, 14);
    printList(L);
    addAfter(L, 20, 14);
    printList(L);
    List *New = reverseList(L);
    printList(New);
    removeDuplicate(L);
    printList(L);
    removeElement(L,9);
    printList(L);
    return 0;
}
