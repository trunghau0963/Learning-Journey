#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int left, int mid , int right ){
    int i = left;
    int j = mid + 1;
    int n = right - left + 1;
    int temp[n] {};
    int tempIndex = 0;
    while ((i < mid + 1)&& (j < right + 1))
    {
        arr[i] < arr[j] ? temp[tempIndex++] = arr[i++] : temp[tempIndex++] = arr[j++];
    }
    while (i < mid + 1)
    {
        temp[tempIndex++] = arr[i++];
    }
    while (j < right + 1)
    {
        temp[tempIndex++] = arr[j++];
    }
    for (int i = 0; i < n; i++)
    {
        arr[left++] = temp[i];
    }
        
}
void mergeSort(int arr[],int left,int right){
    if(left + 1 > right){
        return;
    }
    else{
        int mid = (left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(){
    int arr[] = {1,22,3,31,41,4255,25,62,2,44,2,3};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for(int x : arr){
        cout << x << " ";
    }
    return 0;
}
//time
//stable
//external sorting!!!!

//not in-place 