#include <iostream>
using namespace std;
struct DNODE
{
    int key;
    DNODE *pNext;
    DNODE *pPrev;
};

struct List
{
    DNODE *pHead;
    DNODE *pTail;
};
DNODE *createNode(int data);
List *createList(DNODE *pNode);
void printList(List *L);
void printListReverse(List *L);
bool addHead(List *&L, int data);
bool addTail(List *&L, int data);
void removeHead(List *&L);
void removeTail(List *&L);
void removeAll(List *&L);
void removeBefore(List *L, int val);
void removeAfter(List *L, int val);
bool addPos(List *&L, int data, int pos);
int countElements(List *L);
void removePos(List *&L, int pos);
bool addBefore(List *L, int data, int val);
bool addAfter(List *L, int data, int val);
List *reverseList(List *L);
void removeDuplicate(List *&L);
bool removeElement(List *&L, int key);
void Menu(List *&L);