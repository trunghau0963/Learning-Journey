#include<iostream>
#include<limits.h>

using namespace std;

struct NODE {
    int key;
    NODE* pLeft;
    NODE* pRight;
    int height;
};
typedef NODE* Tree; 
NODE* createNode(int data)
{
    NODE* root = new NODE;

    root->pLeft = root->pRight = NULL;

    root->key = data;

    root->height = 1;

    return root;
}



int height(NODE* p)
{
    if(p == NULL)
        return 0;
    return p->height;
}

int balance(NODE* root)
{
    if(root == NULL)
        return 0;
    
    return height(root->pLeft) - height(root->pRight);
}

int max(int left, int right)
{
    if(left > right)
        return left;
    return right;
}

void leftRotation(NODE* &p)
{
    if(p == NULL)
        return;

    NODE* right = p->pRight;
    NODE* left_right = right->pLeft;

    right->pLeft = p;
    p->pRight = left_right;

    p->height = max(height(p->pLeft), height(p->pRight)+1);
    right->height = max(height(right->pLeft), height(right->pRight)+1);

    p = right;
}

void rightRotation(NODE* &p)
{
    if(p == NULL)
        return;

    NODE* left = p->pLeft;
    NODE* right_left = left->pRight;

    left->pRight = p;
    p->pLeft = right_left;

    p->height = max(height(p->pLeft), height(p->pRight)+1);
    left->height = max(height(left->pLeft), height(left->pRight)+1);
    
    p = left;
}

void Insert(NODE* &pRoot, int x)
{
    if(pRoot == NULL)
    {
        pRoot = createNode(x);
    }

    if(x > pRoot->key)
        Insert(pRoot->pRight, x);
    else if(x < pRoot->key)
        Insert(pRoot->pLeft, x);
    else    
        return;

    pRoot->height = max(height(pRoot->pLeft), height(pRoot->pRight)) + 1;

    // ll
    if(balance(pRoot) > 1 && x < pRoot->pLeft->key)
        rightRotation(pRoot);
    // l r
    else if(balance(pRoot) > 1 && x > pRoot->pLeft->key)
    {
        leftRotation(pRoot->pLeft);
        rightRotation(pRoot);
    }
    // r r
    else if(balance(pRoot) < -1 && x > pRoot->pRight->key)
        leftRotation(pRoot);
    // r l
    else if(balance(pRoot) < -1 && x < pRoot->pRight->key)
    {
        rightRotation(pRoot->pRight);
        leftRotation(pRoot);
    }

}

NODE* minRightBst(NODE* root)
{
    if(root == NULL)
        return root;
    
    NODE* temp = root;
    while(temp->pLeft != NULL)
    {
        temp = temp->pLeft;
    }
    return temp;
}

void Remove(NODE* &pRoot, int x)
{
    if(pRoot == NULL)
        return;

    if(x > pRoot->key)
        Remove(pRoot->pRight, x);
    else if(x < pRoot->key)
        Remove(pRoot->pLeft, x);
    else{
        if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
        {
            pRoot = NULL;
            delete pRoot;
            return;
        }
        else if(pRoot->pLeft == NULL)
        {
            NODE* temp = pRoot->pRight;
            pRoot = temp;
            return;
        }
        else if(pRoot->pRight == NULL)
        {
            NODE* temp = pRoot->pLeft;
            pRoot = temp;
            return;
        }
        else{
            NODE* temp = minRightBst(pRoot->pRight);
            pRoot->key = temp->key;
            Remove(pRoot->pRight, x);
        }
    }


    pRoot->height = max(height(pRoot->pLeft), height(pRoot->pRight)) + 1;
    
    if(pRoot->pLeft == NULL && pRoot->pRight == NULL)
        return;

    // ll
    if(balance(pRoot) > 1 && balance(pRoot->pLeft) >= 0)
        rightRotation(pRoot);
    // l r
    else if(balance(pRoot) > 1 && balance(pRoot->pLeft) < 0)
    {
        leftRotation(pRoot->pLeft);
        rightRotation(pRoot);
    }
    // r r
    else if(balance(pRoot) < -1 && balance(pRoot->pRight) <= 0)
        leftRotation(pRoot);
    // r l
    else if(balance(pRoot) < -1 && balance(pRoot->pRight) > 0)
    {
        rightRotation(pRoot->pRight);
        leftRotation(pRoot);
    }
}

void Inorder(NODE* root)
{
    if(root == NULL)
        return;
    
    Inorder(root->pLeft);

    cout << root->key << " ";

    Inorder(root->pRight);
}

int maxLeft(NODE* pRoot)
{
    if(pRoot == NULL)
        return INT16_MIN;

    return max(pRoot->key, max(maxLeft(pRoot->pLeft), maxLeft(pRoot->pRight)));
}

int minRight(NODE* pRoot)
{
    if(pRoot == NULL)
        return INT16_MAX;

    return min(pRoot->key, min(minRight(pRoot->pLeft), minRight(pRoot->pRight)));
}

bool isBST(NODE* pRoot)
{
    if(pRoot == NULL)
        return true;

    if(pRoot->pLeft != NULL && maxLeft(pRoot->pLeft) >= pRoot->key)
        return false;

    if(pRoot->pRight != NULL && minRight(pRoot->pRight) <= pRoot->key)
        return false;

    return true & isBST(pRoot->pLeft) & isBST(pRoot->pRight);
}

bool isAVL(NODE* pRoot)
{
    if(pRoot == NULL)
        return true;

    if(isBST(pRoot) == false)
        return false;
    else{  
        if(balance(pRoot) > 1 || balance(pRoot) < -1)
            return false;

        return true & isAVL(pRoot->pLeft) & isAVL(pRoot->pRight);
    }
}
void traversal_NLR_PreOrder(NODE* pRoot){
    if(!pRoot){
        return;
    }
    cout << pRoot->key << " ";
    traversal_NLR_PreOrder(pRoot->pLeft);
    traversal_NLR_PreOrder(pRoot->pRight);
}
void traversal_LNR_InOrder(NODE* pRoot){
    if(!pRoot){
        return;
    }
    traversal_LNR_InOrder(pRoot->pLeft);
    cout << pRoot->key << " ";
    traversal_LNR_InOrder(pRoot->pRight);
}
void traversal_LRN_PostOrder(NODE* pRoot){
    if(!pRoot){
        return;
    }
    traversal_LRN_PostOrder(pRoot->pLeft);
    traversal_LRN_PostOrder(pRoot->pRight);
    cout << pRoot->key << " ";
}
int* createArr(int& n)
{
    cout << "Enter n: ";
    cin >> n;

    int* a = new int[n];

    for(int i = 0; i < n; i++)
    {
        cout << "Enter a[" << i << "] = ";
        cin >> a[i];
    }

    return a;
}
int main()
{
    // NODE * root = new NODE {1, new NODE{2,nullptr,nullptr},new NODE{4,nullptr,nullptr}};
    // Tree t = new NODE {4, new NODE{2, new NODE{1,nullptr,nullptr},new NODE{3,nullptr,nullptr}},new NODE {6,new NODE{5,nullptr,nullptr},new NODE{7,nullptr,nullptr}}};
    Tree t = nullptr;
    int a[16]{3,4,12,41,1,5,152,9,15,25,17,79,65,6,7,8};
    int n = sizeof(a)/sizeof(a[0]);
    for (int i = 0; i < n; i++)
    {
        Insert(t,a[i]);
    }
    traversal_LRN_PostOrder(t);
    cout << endl;
    traversal_LNR_InOrder(t);
    cout << endl;
    traversal_NLR_PreOrder(t);
    cout << "\nkey: " << t->key;
    cout << "\ncheck AVL : " << isBST(t);
    cout << "\nAfter Remove\n";
    Remove(t,41);
    traversal_LNR_InOrder(t);
    cout << "\nkey: " << t->key;
    return 0;
}