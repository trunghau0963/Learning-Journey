//Topic : Write a C++ program that returns
// the elements in a vector that are strictly 
//smaller than their adjacent left and right neighbours
//1 2 5 0 3 1 7
#include<iostream>
#include<vector>
using namespace std;
std::vector<int> findStrictlyElementSmaller(vector <int> &a){
    vector <int> temp;
    for(vector <int>::iterator i = a.begin(); i != a.end();i++){
        if(a[*i] < a[*i-1] && a[*i] < a[*i+1]){
            temp.emplace_back(a[*i]);
        }   
    }
    return temp;
}
int main(){
    vector <int> a = {1,2,5,0,3,1,7};
    vector <int> result = findStrictlyElementSmaller(a);
    cout << "\nThe original array : ";
    for(int x : a){
        cout << x << " ";
    }

    cout << "\nVector element are smaller than ajacent left and right neighbours : ";
    for(int x : result){
        cout << x << endl;
    }
    return 0;
}