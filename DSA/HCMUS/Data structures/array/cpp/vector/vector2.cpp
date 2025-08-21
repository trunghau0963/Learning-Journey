#include<iostream>
#include<vector>
using namespace std;
void input(vector <int> &a){
    int choose;
    do{
        cout << "1.Add\n2.Break\n";
        cin >> choose;
        if(choose == 1){
            int x;
            cout << "Enter your number : ";
            cin >> x;
            a.emplace_back(x);
        }
    }while(choose == 1);
}
void print(vector <int> &a){
    vector <int> ::iterator ptr;
    for(ptr = a.begin(); ptr != a.end(); ++ptr){
        cout << *ptr << " ";
    }
    cout << endl;
}
int binarySearchMaximum(vector <int> &a){
    int m;
    int l = -1, r = a.size();
    while(l+1 < r){
        m = (l+r)/2;
        if(a[m+1]>a[m]){
            l = m ;
        }
        else{
            r = m;
        }
    }
    return a[r];
}
int main(){
//Them phan tu vao vector : pushback() 
    // vector <int> a;
    // a.push_back(10);
    // a.push_back(20);
    // a.push_back(30);
    // cout << a.size() << endl; 
//hoac 
    vector <int> a = {1,2,4,23,31,44,90,130,132,50,30,13};
    //                                       l   r        
  // vector <int> b = a;
    // cout << b.size() << endl;
    // cout << "The eventually number : " << a.back() << endl;
    // cout << "The eventually number : " << a[a.size() - 1] << endl;
    // print(a);
    // print(b);
//modifier
//1.push_back//emplace_back
//2.assign
//     a.assign(a.size(),2);
//     cout << "ASSIGN : a.assign(a.size(),2) : "; print(a);
// //3.pop_back
//     a = {1,3,4,56,12};
//     cout << "pop_back: ";
//     a.pop_back();
//     print(a);
// //4.insert()
//     cout << "INSERT : a.insert(a.begin() + 1,131) : ";
//     a.insert(a.begin() + 1,131);
//     print(a);
// //5.erase()
//     a = {1,3,4,56,12};
//     a.erase(a.begin() + 2);
//     cout << "ERASE : a.erase(a.begin() + 2) : ";
//     print(a);
//     a = {1,3,4,56,12};
//     a.erase(a.begin(),a.begin()+2);
//     cout << "ERASE : a.erase(a.begin(),a.begin() + 2) : ";
//     print(a);
// //6.emplace()// them vi tri bat ky
//     a = {1,3,4,56,12};
//     a.emplace(a.begin()+2,5);
//     cout << "EMPLACE : a.emplace(a.begin()+2,5): ";
//     print(a);
// //7.swap()
//     a = {1,3,4,56,12};
//     vector <int> b= {9,4,2,4,23,131,31,7};
//     cout << "Vector A : ";
//     print(a);
//     cout << "Vector B : ";
//     print(b);
//     a.swap(b);
//     cout << "After swap : a.swap(b); \nVector A : ";
//     print(a);
//     cout << "Vector B : ";
//     print(b);
    // input(a);
    print(a);
    cout << binarySearchMaximum(a);
    cout << endl << a.size() << endl;
    cout << a.max_size() << endl;
    cout << a.capacity() << endl;
}