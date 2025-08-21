#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
struct NODE {
  int key;
  NODE *left;
  NODE *right;
};
typedef NODE* Tree;
NODE* createNode(int data){
    NODE* temp = new NODE{data,nullptr,nullptr};
    return temp;
}
void initTree(Tree &t){
    t = nullptr;
}
 void Insert(NODE* &pRoot, int x){
    if(!pRoot){
        NODE *p = createNode(x);
        pRoot = p;
    }
    else{
        if(pRoot->key > x){
            Insert(pRoot->left,x);
        }
        else if(pRoot->key < x){
            Insert(pRoot->right,x);
        }
    }
}
void traversal_NLR_PreOrder(NODE* pRoot){
    if(!pRoot){
        return;
    }
    cout << pRoot->key << " ";
    traversal_NLR_PreOrder(pRoot->left);
    traversal_NLR_PreOrder(pRoot->right);
}
void traversal_NRl(Tree t){
    if(!t){
        return;
    }
    cout << t->key << " ";
    traversal_NRl(t->right);
    traversal_NRl(t->left);
}
void traversal_LRN_PostOrder(NODE* pRoot){
    if(!pRoot){
        return;
    }
    traversal_LRN_PostOrder(pRoot->left);
    traversal_LRN_PostOrder(pRoot->right);
    cout << pRoot->key << " ";
}
void traversal_RLN(Tree t){
    if(!t){
        return;
    }
    traversal_RLN(t->right);
    traversal_RLN(t->left);
    cout << t->key << " ";
}
void traversal_LNR_InOrder(NODE* pRoot){
    if(!pRoot){
        return;
    }
    traversal_LNR_InOrder(pRoot->left);
    cout << pRoot->key << " ";
    traversal_LNR_InOrder(pRoot->right);
}
void traversal_RNL(Tree t){
    if(!t){
        return;
    }
    traversal_RNL(t->right);
    cout << t->key << " ";
    traversal_RNL(t->left);
}
// pair <int, int> findMaxMin(Tree t){
//     if(t->right == nullptr ){
//         return t->key,findMaxMin(t->left);
//     }
//     else if (t->left == nullptr){
//         return findMaxMin(t->right);
//     }
//     return findMaxMin(t->right),findMaxMin(t->left);
// }
int findMax(Tree t){
    if(t->right == nullptr){
        return t->key;
    }
    return findMax(t->right);
}
int findMin(Tree t){
    if(t->left == nullptr){
        return t->key;
    }
    return findMin(t->left);
}
NODE* Search(NODE* pRoot, int key){
    if(!pRoot || pRoot->key == key){
        return pRoot;
    }
    if (pRoot->key < key){
        return Search(pRoot->right,key);
    }
    return Search(pRoot->left,key);
}
NODE* minValueNode(NODE* &node){
    NODE *cur = node;
    while(cur->left){
        cur = cur->left;
    }
    return cur;
}
void Remove(NODE* &pRoot, int x){
    if(!pRoot){
        return;
    }
    if(x < pRoot->key){
        Remove(pRoot->left,x);
    }
    else if(x > pRoot->key){
        Remove(pRoot->right,x);
    }
    else{
        NODE*x = pRoot;
        if(!pRoot->right && !pRoot->left){
            pRoot = nullptr;
            delete x;
        }
        else if(!pRoot->left){
            pRoot = pRoot->right;
            delete x;
        }
        else if(!pRoot->right){
            pRoot = pRoot->left;
            delete x;
        }
        else{
            NODE* pre = pRoot;
            NODE* suc = pRoot->right;
            while (suc->left)
            {
                pre = suc;
                suc = suc->left;
            }
            if(pRoot == pre){
                swap(pRoot->key,suc->key);
                pre->right = suc->right;
                // delete suc;
            }
            else{
                swap(pRoot->key,suc->key);
                pre->left = suc->right;
            }
            delete suc;
        }
    }
}
int Height(NODE* pRoot){
    if(!pRoot){
        return 0;
    }
    return max(Height(pRoot->left),Height(pRoot->right))+1;
}
// void LevelOrder(NODE* pRoot){
//     int height = Height(pRoot);
//     vector<int> q;
//     q.push_back(pRoot->key);
//     NODE* current = pRoot;
//     while (current){
//         cout << q[0] << " ";
//         q.erase(q.begin());
//         if(!current->left) q.push_back(current->left->key);
//         if(!current->right) q.push_back(current->right->key);
//     }
// }
void printLevelOrder(NODE* pRoot,int level){
    if(!pRoot){
        return;
    }
    if(level == 0){
        cout << pRoot->key << " ";
        return;
    }
    else if(level > 0){
        printLevelOrder(pRoot->left,level-1);
        printLevelOrder(pRoot->right,level-1);
    }
}
void LevelOrder(NODE* pRoot){
    int height = Height(pRoot);
    for (int i = 0; i < height; i++){
        printLevelOrder(pRoot,i);
    }
}
 int countNode(NODE* pRoot){
    if(!pRoot){
        return 0;
    }
    return 1 + countNode(pRoot->left) + countNode(pRoot->right);
}
int sumNode(NODE* pRoot){
    if(!pRoot){
        return 0;
    }
    return pRoot->key + sumNode(pRoot->left) + sumNode(pRoot->right);
}
NODE* createTree(int a[], int n){
    if(n == 0){
        return nullptr;
    }
    NODE* newTree;
    initTree(newTree);
    for (int i = 0; i < n; i++)
    {
        Insert(newTree,a[i]);
    }
    return newTree;
}
void removeTree(NODE* &pRoot){
    if(!pRoot){
        return;
    }
    traversal_LNR_InOrder(pRoot->left);
    Remove(pRoot,pRoot->key);
    traversal_LNR_InOrder(pRoot->right);
}
//////////////////////////
int heightNode(NODE* pRoot, int value){
    if(!pRoot || pRoot->key == value){
        return 1;
    }
    return min(heightNode(pRoot->left,value),heightNode(pRoot->right,value)) + 1;
}
int countLeaf(NODE* pRoot){
    if(!pRoot){
        return 0;
    }
    if(!pRoot->left && !pRoot->right){
        return 1;
    }
    return countLeaf(pRoot->left) + countLeaf(pRoot->right);
}
int cntL = 0,cntG = 0;
int countLess(NODE* pRoot, int x){
    // NODE *temp = Search(pRoot,x);
    if(!pRoot){
        return 0;
    }
    if(pRoot->key < x){
        ++cntL;
    }
    countLess(pRoot->left,x);
    countLess(pRoot->right,x);
    return cntL;
}
int countGreater(NODE* pRoot, int x){
    // NODE *temp = Search(pRoot,x);
    if(!pRoot){
        return 0;
    }
    if(pRoot->key > x){
        ++cntG;
    }
    countGreater(pRoot->left,x);
    countGreater(pRoot->right,x);
    return cntG;
}
int maxValue(NODE* pRoot){
    if(!pRoot) return INT16_MIN;
    return max(pRoot->key, max(maxValue(pRoot->left), maxValue(pRoot->right)));
}
int minValue(NODE* pRoot){
    if(!pRoot) return INT16_MAX;
    return min(pRoot->key, min(minValue(pRoot->left), minValue(pRoot->right)));
}
bool isBST(NODE* pRoot){
    if(!pRoot) return false;
    if(pRoot->left && maxValue(pRoot->left) > pRoot->key) return false;
    else if(pRoot->right && minValue(pRoot->right) < pRoot->key) return false;
    else if(!pRoot->left && !pRoot->right) return false;
    return true;
}
void Menu(Tree &t)
{
    int a, b;
    while (1)
    {
        system("cls");
        cout << "======Menu======\n";
        cout << "1.Add Elements\n";
        cout << "2.Remove Element\n";
        cout << "3.Print all elements of a given List\n";
        cout << "4.find Max/min\n";
        cout << "5.Height\n";
        cout << "6.Level Order\n";
        cout << "7.Count Node\n";
        cout << "8.Sum Node\n";
        cout << "9.Calculate the height of a NODE with given value\n";
        cout << "10.Count the number leaves from a given Binary Tree\n";
        cout << "11. Count the number of NODE from a given Binary Search Tree which key value is less than a given value\n";
        cout << "12.Exit\n";
        cout << " == == == == == == == == ==\n";
        cout << "Input : ";
        cin >> a;
        if (a < 1 || a > 12)
        {
            cout << "Wrong!!";
            system("pause");
        }
        else if (a == 1)
        {
            system("cls");
            int n;
            cout << "How many number do you want to add ? : ";
            cin >> n;
            int a[n];
            cout << "plz enter your number : ";
            for (int i = 0; i < n; i++)
            {
                cin >> a[i];
            }
            
            for (int i = 0; i < n; i++)
            {
                Insert(t,a[i]);
            }
            
        }
        else if (a == 2)
        {
            system("cls");
            int x;
            cout << "plz enter the number you want to remove : ";
            cin >> x;
            Remove(t,x);
        }
        else if (a == 3)
        {
            system("cls");
            cout << "======Traversal======\n";
            cout << "1.NLR ( Pre Order )\n";
            cout << "2.LRN (Post Order)\n";
            cout << "3.LNR (InOrder) min -> max\n";
            cout << "4.NRL\n";
            cout << "5.RNL max -> min\n";
            cout << "6.RLN\n";
            cout << "7.Exit\n";
            cout << " == == == == == == == == ==\n";
            cout << "Input : ";
            cin >> b;
            if(b == 1){
                cout << "\nNLR ( Pre Order )\n";
                traversal_NLR_PreOrder(t);
                system("pause");
            }
            else if(b == 2){
                cout << "\nLRN (Post Order)\n";
                traversal_LRN_PostOrder(t);
                system("pause");
            }
            else if(b == 3){
                cout << "\nLNR (InOrder)\n";
                traversal_LNR_InOrder(t);
                system("pause");
            }
            else if(b == 4){
                cout << "\nNRL\n";
                traversal_NRl(t);
                system("pause");
            }
            else if(b == 5){
                cout << "\nRNL\n";
                traversal_RNL(t);
                system("pause");
            }
            else if(b == 6){
                cout << "\nRLN\n";
                traversal_RLN(t);
                system("pause");
            }
            else{
                break;
            }
        }
        else if(a == 4){
            system("cls");
            // pair <int, int> maxmin;
            // maxmin = findMaxMin(t);
            // cout << "max : " << maxmin.first  << endl;
            // cout << "min : " << maxmin.second  << endl;
            cout << "max : " << findMax(t)  << endl;
            cout << "min : " << findMin(t)  << endl;
            system("pause");
        }
        else if(a == 5){
            system("cls");
            cout << "\nHeight of tree : " << Height(t) << endl;
            system("pause");
        }
        else if(a == 6){
            system("cls");
            cout << "\nLevel Order : "; 
            LevelOrder(t);
            system("pause");
        }
        else if(a == 7){
            system("cls");
            cout << "\nCount Node : " << countNode(t) << endl;
            system("pause");
        }
        else if(a == 8){
            system("cls");
            cout << "\nSum Node : " << sumNode(t) << endl;
            system("pause");
        }
        else if(a == 9){
            system("cls");
            int x;
            cout << "\nEnter your value: ";
            cin >> x;
            cout << "\nCalculate the height of a NODE with given value: " << heightNode(t,x) << endl;
            system("pause");
        }
        else if(a == 10){
            system("cls");
            cout << "The number leaves from a given Binary Tree : " << countLeaf(t) << endl;
            system("pause");
        }
        else if(a == 11){
            system("cls");
            int x;
            cout << "\nEnter your value: ";
            cin >> x;
            cout << "\n Count the number of NODE from a given Binary Search Tree which key value is less than a given value: " << countLess(t,x) << endl;
            system("pause");
        }
        else
        {
            break;
        }
    }
}
int main(){
    Tree t; 
    initTree(t);
    // Menu(t);
    int a[28]{70, 20, 80, 10, 8, 6, 9, 40, 30, 50, 25, 35, 75, 78, 72, 71, 73, 76, 79, 90, 87, 100, 85, 81, 95, 120, 55, 60};
    for (int i = 0; i < 28; i++)
    {
        Insert(t,a[i]);
    }
    cout << "\nNLR ( Pre Order )\n";
    traversal_NLR_PreOrder(t);
    cout << "\n Count the number of NODE from a given Binary Search Tree which key value is less than a given value: " << countGreater(t,76) << endl;
    return 0;
}