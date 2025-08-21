#include<iostream>
using namespace std;
int calculateSum(int n){
    if(n == 0){
        return 0;
    }
    return calculateSum(n-1) + n;
}
int calculateFactorial(int n){
    if(n == 0){
        return 1;
    }
    return calculateFactorial(n-1)*n;
}
long calculatePower(int n,int x){
    if(n == 0){
        return 1;
    }
    return calculatePower(n-1,x)*x;
}
int countTheNumberOfDigits(int n){
    if(n == 0){
        return 0;
    }
    return countTheNumberOfDigits(n/10)+1;
}
bool verifyAllDigitsAreEven(int n){
    if(n == 0){
        return true;
    }
    else if (n%2 != 0){
        return false;
    }
    return verifyAllDigitsAreEven(n/10);
}
// int countTheNumberOfCommonDivisor(int a, int b){
//     if()
// }
int main(){
    cout << verifyAllDigitsAreEven(2222324);
    return 0;
}