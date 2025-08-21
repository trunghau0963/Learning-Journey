#include <iostream>
#include <math.h>
using namespace std;
struct NODE
{
    int key;
    NODE *pLeft;
    NODE *pRight;
    int height;
};
typedef NODE* Tree; 
NODE* createNode(int data){
    NODE* temp = new NODE{data,nullptr,nullptr,1};
    return temp;
}
int getHeight(NODE* pRoot){
    if(!pRoot) return 0;
    return 1 + max(getHeight(pRoot->pLeft), getHeight(pRoot->pRight));
}
int maxValue(NODE* pRoot){
    if(!pRoot) return INT16_MIN;
    return max(pRoot->key, max(maxValue(pRoot->pLeft), maxValue(pRoot->pRight)));
}
int minValue(NODE* pRoot){
    if(!pRoot) return INT16_MAX;
    return min(pRoot->key, min(minValue(pRoot->pLeft), minValue(pRoot->pRight)));
}
bool isBST(NODE* pRoot){
    if(!pRoot) return false;
    if(pRoot->pLeft && maxValue(pRoot->pLeft) > pRoot->key) return false;
    else if(pRoot->pRight && minValue(pRoot->pRight) < pRoot->key) return false;
    else if(!pRoot->pLeft && !pRoot->pRight) return false;
    return true;
}
bool isAVL(NODE* pRoot){
    if(!pRoot) return false;
    if(!isBST(pRoot)) return false;
    // return getHeight(pRoot->pLeft) > getHeight(pRoot->pRight);
    if(abs(getHeight(pRoot->pLeft) - getHeight(pRoot->pRight)) <= 1 && (isAVL(pRoot->pLeft)) && (isAVL(pRoot->pRight))) return true;
    return false;
}
NODE* leftRotate(NODE* pRoot){
    if(!pRoot) return nullptr;
    NODE* node_X = pRoot->pRight;
    NODE* node_T = node_X->pLeft;

    //rotate
    node_X->pLeft = pRoot;
    pRoot->pRight = node_T;

    //update height
    pRoot->height = max(getHeight(pRoot->pLeft), getHeight(pRoot->pRight)+1);
    node_X->height = max(getHeight(node_X->pLeft), getHeight(node_X->pRight)+1);

    return node_X;
}
NODE* rightRotate(NODE* pRoot){
    if(!pRoot) return nullptr;
    NODE* node_X = pRoot->pLeft;
    NODE* node_T = node_X->pRight;

    //rotate
    node_X->pRight = pRoot;
    pRoot->pLeft = node_T;

    //update height
    pRoot->height = max(getHeight(pRoot->pLeft), getHeight(pRoot->pRight)+1);
    node_X->height = max(getHeight(node_X->pLeft), getHeight(node_X->pRight)+1);

    return node_X;
}
int getBalance(NODE* pRoot){
    if(!pRoot) return 0;
    return getHeight(pRoot->pLeft) - getHeight(pRoot->pRight);
}
void Insert(NODE* &pRoot, int x){
    if(!pRoot) pRoot = createNode(x);
    else if(x < pRoot->key) Insert(pRoot->pLeft, x);
    else if(x > pRoot->key) Insert(pRoot->pRight, x);
    else return;
    pRoot->height = 1 + max(getHeight(pRoot->pLeft), getHeight(pRoot->pRight));
    int balance = getBalance(pRoot);
    if(balance > 1){
        //left left - insert in left 
        if(x < pRoot->pLeft->key) pRoot = rightRotate(pRoot);
        //left right - insert in right
        else if(x > pRoot->pLeft->key){
            pRoot->pLeft = leftRotate(pRoot->pLeft);
            pRoot = rightRotate(pRoot);
        }
    }
    else if(balance < -1){
        //right right
        if(x > pRoot->pRight->key) pRoot = leftRotate(pRoot);
        //right left
        else if(x < pRoot->pRight->key){
            pRoot->pRight = rightRotate(pRoot->pRight);
            pRoot = leftRotate(pRoot);
        }
    }
}
void Remove(NODE* &pRoot, int x){
    if(!pRoot) return;
    else if(x < pRoot->key) Remove(pRoot->pLeft, x);
    else if(x > pRoot->key) Remove(pRoot->pRight, x);
    else{
        // no node child removed
        NODE* x = pRoot;
        if(!pRoot->pLeft && !pRoot->pRight) {
            pRoot = nullptr;
            delete x;
        }
        // 1 node child removed
        else if(!pRoot->pLeft) {
            pRoot = pRoot->pRight;
            delete x;
        }
        else if(!pRoot->pRight) {
            pRoot = pRoot->pLeft;
            delete x;
        }
        // 2 node child removed
        else {
            NODE *pre = pRoot;
            NODE *suc = pRoot->pRight;
            while (suc->pLeft)
            {
                pre = suc;
                suc = suc->pLeft;
            }
            if(pre == pRoot){
                swap(pRoot->key,suc->key);
                pre->pRight = suc->pRight;
            }
            else{
                swap(pRoot->key,suc->key);
                pre->pLeft = suc->pRight;
            }
            delete suc;
        }
    }
    //
    if(!pRoot) return;
    pRoot->height = 1 + max(getHeight(pRoot->pLeft), getHeight(pRoot->pRight));
    int balance = getBalance(pRoot);
    if(balance > 1){
        //left left - remove in left 
        if(getBalance(pRoot->pLeft) >= 0) rightRotate(pRoot);
        else if(getBalance(pRoot->pLeft) < 0){
            pRoot->pLeft = leftRotate(pRoot->pLeft);
            pRoot = rightRotate(pRoot);
        }
    }
    else if(balance < -1){
        //right right
        if(getBalance(pRoot->pRight) <= 0) leftRotate(pRoot);
        //right left
        else if(getBalance(pRoot->pRight) > 0){
            pRoot->pRight = rightRotate(pRoot->pRight);
            pRoot = leftRotate(pRoot);
        }
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