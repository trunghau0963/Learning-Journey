#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node* pNext;
};
void printList(Node *head){
    for (; head != nullptr; head = head->pNext)
    {
        cout << head->data << " ";
    }
    
}
void swapNode(Node*&a, Node*&b){
    Node *temp = a;
    a = b;
    b = temp;
}
void selectionSort(Node *&head){
    Node* max = head;
    for(Node*i = head; i != nullptr; i = i->pNext){
        for(Node *j = i->pNext; j != nullptr;j = j->pNext){
            if(max->data < j->data){
                max = j;
            }
        }
        Node *temp = i;
        i = max;
        max = temp;
    }
}
int main(){
    Node *head = new Node {14, new Node{43, new Node{914, new Node{13, new Node{52, new Node{57, new Node{94, new Node{113, nullptr}}}}}}}};
    printList(head);
    selectionSort(head);
    cout << endl;
    printList(head);
    return 0;
}