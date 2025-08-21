#include<iostream>
#include<vector>
using namespace std;
int partition(int a[],int left,int right){
    int i = left + 1;
    int j = right;
    int temp = a[left];
    do
    {
        while ((i<=j) && (a[i] < temp)) i++;
        while ((i<=j) && (a[j] >= temp)) j--;
        if(i<j){
            swap(a[i],a[j]);
            i++;j--;
        }
    } while (i<=j);
    swap(a[left],a[j]);
    return j;
}

void quickSort(int arr[],int left,int right){
    if(left + 1 > right ){
        return;
    }
    else{
        int pivot = partition(arr,left,right);
        quickSort(arr,left,pivot-1);
        quickSort(arr,pivot + 1,right);
    }
}
int main(){
    int arr[] = {1,22,3,31,41,4255,25,62,2,44,2,3};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}