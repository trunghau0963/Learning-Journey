//Write a C++ program to create an n x n matrix by taking an integer (n) as input from the user
#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<vector<int>> kha = {{2,3,3,4}
                                ,{3,4,5,6}};
    for(int i = 0; i < kha.size(); i++){
        for(int j = 0; j < kha[i].size(); j++){
            cout << kha[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}