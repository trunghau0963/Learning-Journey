#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> findString(vector<string> &a){
    vector<string> temp;
    for(int i=0; i<a.size();i++){
        for(int j=0; j<a[i].size();j++){
            if(a[i][j] >= 48 && a[i][j] <= 57){
                temp.emplace_back(a[i]);
                break;
            }
        }
    }
    return temp;
}
int main(){
    vector<string> a {"red","green23","1black","whi23te"};
    cout << "\nOriginal Array : ";
    for(int i=0; i<a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "\nFind strings that contain a number(s) from the said vector: ";
    vector<string>result = findString(a);
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}