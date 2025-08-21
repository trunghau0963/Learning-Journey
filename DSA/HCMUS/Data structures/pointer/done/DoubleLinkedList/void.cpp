#include "main.h"
DNODE *createNode(int data)
{
    DNODE *p = new DNODE;
    p->key = data;
    p->pNext = nullptr;
    p->pPrev = nullptr;
    return p;
}
List *createList(DNODE *pNode)
{
    List *l = new List;
    if (pNode == nullptr)
    {
        l->pHead = l->pTail = nullptr;
        return l;
    }
    l->pHead = pNode;
    for (DNODE *p = l->pHead; p != nullptr; p = p->pNext)
    {
        l->pTail = p;
    }
    return l;
}
void printList(List *L)
{
    for (DNODE *p = L->pHead; p != nullptr; p = p->pNext)
    {
        cout << p->key << " ";
    }
    cout << endl;
}
void printListReverse(List *L)
{
    for (DNODE *p = L->pTail; p != nullptr; p = p->pPrev)
    {
        cout << p->key << " ";
    }
    cout << endl;
}
bool addHead(List *&L, int data)
{
    DNODE *p = createNode(data);
    if (L->pHead == nullptr)
    {
        L->pHead = L->pTail = p;
    }
    else
    {
        p->pNext = L->pHead;
        L->pHead->pPrev = p;
        L->pHead = p;
    }
    return p;
}
bool addTail(List *&L, int data)
{
    DNODE *p = createNode(data);
    if (L->pHead == nullptr)
    {
        L->pHead = L->pTail = p;
    }
    else
    {
        p->pPrev = L->pTail;
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
        DNODE *p = L->pHead;
        L->pHead = p->pNext;
        if (p->pNext != nullptr)
        {
            p->pNext->pPrev = nullptr;
            p->pNext = nullptr;
        }
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
        for (DNODE *p = L->pHead; p != nullptr; p = p->pNext)
        {
            if (p->pNext == L->pTail)
            {
                DNODE *temp = L->pTail;
                temp->pPrev = nullptr;
                p->pNext = nullptr;
                delete temp;
                L->pTail = p;
            }
        }
    }
}
void removeAll(List *&L)
{
    if (L->pHead == nullptr)
    {
        return;
    }
    while (L->pHead != nullptr)
    {

        DNODE *p = L->pHead;
        L->pHead = p->pNext;
        if (p->pNext != nullptr)
        {
            p->pNext->pPrev = nullptr;
            p->pNext = nullptr;
        }
        delete p;
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
        for (DNODE *p = L->pTail; p->pPrev != nullptr; p = p->pPrev)
        {
            if (p->key == val)
            {
                DNODE *h = p->pPrev;
                if (h->pPrev == nullptr)
                {
                    removeHead(L);
                    return;
                }
                else
                {
                    p->pPrev = h->pPrev;
                    h->pPrev->pNext = p;
                    h->pNext = h->pPrev = nullptr;
                    delete h;
                }
            }
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
        for (DNODE *p = L->pHead; p->pNext != nullptr; p = p->pNext)
        {
            if (p->key == val)
            {
                DNODE *h = p->pNext;
                if (h->pNext == nullptr)
                {
                    removeTail(L);
                    return;
                }
                else
                {
                    p->pNext = h->pNext;
                    h->pNext->pPrev = p;
                    h->pNext = h->pPrev = nullptr;
                    delete h;
                }
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
        DNODE *temp = L->pHead;
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
            DNODE *h = createNode(data);
            h->pNext = temp->pNext;
            temp->pNext->pPrev = h;
            temp->pNext = h;
            h->pPrev = temp;
            return true;
        }
    }
    return false;
}
int countElements(List *L)
{
    int cnt = 0;
    for (DNODE *p = L->pHead; p != nullptr; p = p->pNext)
    {
        cnt++;
    }
    return cnt;
}
void removePos(List *&L, int pos)
{
    if (pos == 0 || L->pHead == nullptr)
    {
        removeHead(L);
    }
    else
    {
        DNODE *temp = L->pHead;
        int cnt = 1;
        while (cnt != pos && temp != nullptr)
        {
            temp = temp->pNext;
            cnt++;
        }
        if (cnt != pos || pos == countElements(L) - 1)
        {
            removeTail(L);
        }
        else
        {
            DNODE *h = temp->pNext;
            temp->pNext = h->pNext;
            h->pNext->pPrev = temp;
            h->pNext = h->pPrev = nullptr;
            delete h;
        }
    }
}
bool addBefore(List *L, int data, int val)
{
    if (L->pHead == nullptr)
    {
        return false;
    }
    else
    {
        for (DNODE *p = L->pTail; p != nullptr; p = p->pPrev)
        {
            if (p->key == val)
            {
                if (p->pPrev == nullptr)
                {
                    addHead(L, data);
                }
                else
                {
                    DNODE *h = createNode(data);
                    h->pPrev = p->pPrev;
                    p->pPrev->pNext = h;
                    p->pPrev = h;
                    h->pNext = p;
                }
                if (val == data)
                {
                    p = p->pPrev;
                }
            }
        }
    }
    return true;
}
bool addAfter(List *L, int data, int val)
{
    if (L->pHead == nullptr)
    {
        return false;
    }
    else
    {
        for (DNODE *p = L->pHead; p != nullptr; p = p->pNext)
        {
            if (p->key == val)
            {
                if (p->pNext == nullptr)
                {
                    addTail(L, data);
                }
                else
                {
                    DNODE *h = createNode(data);
                    h->pNext = p->pNext;
                    p->pNext->pPrev = h;
                    p->pNext = h;
                    h->pPrev = p;
                }
                if (val == data)
                {
                    p = p->pNext;
                }
            }
        }
    }
    return true;
}
List *reverseList(List *L)
{
    List *NewList = L;
    DNODE *prev = nullptr;
    DNODE *cur = NewList->pHead;
    DNODE *next = NewList->pHead->pNext;
    while (next != nullptr)
    {
        next = cur->pNext;
        cur->pNext = prev;
        cur->pPrev = next;
        prev = cur;
        cur = next;
    }
    NewList->pHead = prev;
    return NewList;
}
void removeDuplicate(List *&L)
{
    int length = countElements(L);
    bool checkList[length]{0};
    bool Duplicate;
    int cntI = 0, cntJ;
    // 2 3 4 1 2 7 3 2
    for (DNODE *i = L->pHead; i != nullptr; i = i->pNext)
    {
        Duplicate = false;
        cntJ = cntI;
        for (DNODE *j = i->pNext; j != nullptr; j = j->pNext)
        {
            cntJ++;
            if (i->key == j->key)
            {
                Duplicate = true;
                checkList[cntJ] = true;
            }
        }
        if (Duplicate == true)
        {
            checkList[cntI] = true;
            Duplicate = false;
        }
        cntI++;
    }
    for (int i = length - 1; i >= 0; i--)
    {
        if (checkList[i])
        {
            removePos(L, i);
            // cout << checkList[i] << " ";
        }
    }
}
bool removeElement(List *&L, int key)
{
    int length = countElements(L);
    bool checkList[length]{0}, check = false;
    int cntI = 0;
    for (DNODE *i = L->pHead; i != nullptr; i = i->pNext)
    {
        if (i->key == key)
        {
            checkList[cntI] = true;
        }
        cntI++;
    }
    for (int i = length - 1; i >= 0; i--)
    {
        if (checkList[i])
        {
            removePos(L, i);
            check = true;
        }
    }
    return check;
}
void Menu(List *&L)
{
    int a, b;
    while (1)
    {
        system("cls");
        cout << "======Menu======\n";
        cout << "1.Add Elements\n";
        cout << "2.Remove Element\n";
        cout << "3.Print all elements of a given List\n";
        cout << "4.Count the number of elements List\n";
        cout << "5.Create a new List by reverse a given List\n";
        cout << "6.Exit\n";
        cout << " == == == == == == == == ==\n";
        cout << "Input : ";
        cin >> a;
        if (a < 1 || a > 6)
        {
            cout << "Wrong!!";
            system("pause");
        }
        else if (a == 1)
        {
            system("cls");
            cout << "==================\n";
            cout << "Enter your selection\n";
            cout << "1.Insert an integer to the head of a given List \n";
            cout << "2.Insert an integer to the tail of a given List\n";
            cout << "3.Insert an integer at a position of a given List\n";
            cout << "4.Insert an integer before a value of a given List\n";
            cout << "5.Insert an integer after a value of a given List\n";
            cout << "6.Exit\n";
            cout << " == == == == == == == == ==\n";
            cout << "Input : ";
            cin >> b;
            if (b < 1 || b > 6)
            {
                cout << "Wrong!!";
                system("pause");
            }
            else if (b == 1)
            {
                system("cls");
                cout << "====Insert an integer to the HEAD of a given List=====\n";
                int x;
                cout << "Input Your Interger : ";
                cin >> x;
                addHead(L, x);
                system("pause");
            }
            else if (b == 2)
            {
                system("cls");
                cout << "====Insert an integer to the TAIL of a given List=====\n";
                int x;
                cout << "Input Your Interger : ";
                cin >> x;
                addTail(L, x);
                system("pause");
            }
            else if (b == 3)
            {
                system("cls");
                cout << "====Insert an integer at a POSITION of a given List=====\n";
                int x, pos;
                cout << "Input Your Interger: ";
                cin >> x;
                cout << "\nInput Your Position : ";
                cin >> pos;
                addPos(L, x, pos);
                system("pause");
            }
            else if (b == 4)
            {
                system("cls");
                cout << "====Insert an integer BEFORE a value of a given List=====\n";
                int x, val;
                cout << "Input Your Interger : ";
                cin >> x;
                cout << "\nInput a value of a given List : ";
                cin >> val;
                addBefore(L,x,val);
                system("pause");
            }
            else if (b == 5)
            {
                system("cls");
                cout << "====Insert an integer AFTER a value of a given List=====\n";
                int x, val;
                cout << "Input Your Interger : ";
                cin >> x;
                cout  << "\nInput a value of a given List : ";
                cin >> val;
                addAfter(L,x,val);
                system("pause");
            }
            else
            {
                continue;
            }
        }
        else if (a == 2)
        {
            system("cls");
            cout << "==================\n";
            cout << "Enter your selection\n";
            cout << "1.Remove the first NODE of a given List\n";
            cout << "2.Remove the last NODE of a given List\n";
            cout << "3.Remove all NODE from a given List \n";
            cout << "4.Remove node before the node has val value in a given List\n";
            cout << "5.Remove node after the node has val value in a given List\n";
            cout << "6.Remove an integer at a position of a given List\n";
            cout << "7.Remove all duplicates from a given List\n";
            cout << "8.Remove all key value from a given List\n";
            cout << "9.Exit\n";
            cout << " == == == == == == == == ==\n";
            cout << "Input : ";
            cin >> b;
            if (b < 1 || b > 9)
            {
                cout << "Wrong!!";
                system("pause");
            }
            if (b == 1)
            {
                system("cls");
                removeHead(L);
                system("pause");
            }
            else if (b == 2)
            {
                system("cls");
                removeTail(L);
                system("pause");
            }
            else if (b == 3)
            {
                system("cls");
                removeAll(L);
                system("pause");
            }
            else if (b == 4)
            {
                system("cls");
                cout << "====Remove node BEFORE the node has val value in a given List=====\n";
                int val;
                cout  << "Input Val value : ";
                cin >> val;
                removeBefore(L, val);
                system("pause");
            }
            else if (b == 5)
            {
                system("cls");
                cout << "====Remove node AFTER the node has val value in a given List=====\n";
                int val;
                cout  << "Input Val value : ";
                cin >> val;
                removeAfter(L, val);
                system("pause");
            }
            else if (b == 6)
            {
                system("cls");
                cout << "==== Remove an integer at a POSITION of a given List=====\n";
                int pos;
                cout  << "Input a position : ";
                cin >> pos;
                removePos(L, pos);
                system("pause");
            }
            else if (b == 7)
            {
                system("cls");
                removeDuplicate(L);
                system("pause");
            }
            else if (b == 8)
            {
                system("cls");
                cout << "====Remove all key value from a given List=====\n";
                int key;
                cout  << "Input a key : ";
                cin >> key;
                removeElement(L, key);
                system("pause");
            }
            else
            {
                continue;
            }
        }
        else if (a == 3)
        {
            system("cls");
            cout << "==================\n";
            cout << "Enter your selection\n";
            cout << "1.Print List\n";
            cout << "2.Print Reverse List \n";
            cout << "Exit\n";
            cout << " == == == == == == == == ==\n";
            cout << "Input : ";
            cin >> b;
            if (b < 1 || b > 3)
            {
                cout << "Wrong!!";
                system("pause");
            }
            if (b == 1)
            {
                system("cls");
                cout << "====Print all elements of a given List=====\n";
                printList(L);
                system("pause");
            }
            else if (b == 2)
            {
                system("cls");
                cout << "====Print REVERSE all elements of a given List=====\n";
                printListReverse(L);
                system("pause");
            }
            else
            {
                continue;
            }
        }
        else if (a == 4)
        {
            system("cls");
            cout << "The number of elements List " << countElements(L) << endl;
            system("pause");
        }
        else if (a == 5)
        {
            system("cls");
            cout  << "====Create a new List by reverse a given List==== ";
            List *Reverse = L;
            reverseList(Reverse);
            printList(Reverse);
            system("pause");
        }
        else
        {
            break;
        }
    }
}
