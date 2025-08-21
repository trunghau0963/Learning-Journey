#include<iostream>
using namespace std;
void PrintBinary(int n)
{
    if(n == 0){
        return;
    }
    PrintBinary(n/2);
    cout << n%2;
}
int main(){
    PrintBinary(6);
    // cout << 14%2;
}