#include<iostream>
#include<vector>
#include<string>
using namespace std;
int checkAppear(vector<string> &a){
    int nb = 0,flag = false;
    for(int i=0; i < 2;i++){
        for(int j=0; j < a[i].size();j++){
            if(a[1][nb] == a[0][j]){
                flag = true;
                int start = j;
                for(int l=0; l < a[1].size();l++){
                    if(a[1][nb++] != a[0][start++]){
                        flag = false;
                    }
                }
            }
        }
    }
    if(flag == false){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){
    vector<string> a = {"Python","Pyth"};
    for(int i=0; i<a.size();i++){
        for(int j=0; j<a[i].size();j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << checkAppear(a);
    return 0;
}