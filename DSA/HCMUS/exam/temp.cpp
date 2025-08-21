#include<iostream>
using namespace std;
// void process(int arr[],int n){
//     //9 2 6 7 9 10 8 5
//     //  i   j
//     //0 1 2 3 4  5 6 
//     //9 7 2 6 9 10 8 5 
//     for (int i = 0; i < n; i++)
//     {
//         if(arr[i]%2==0){
//             int keyIdx = i;
//             for (int j = i; j < n; j++)
//             {
//                 if(arr[j]%2!=0){
//                     int tempIdx = j;
//                     while (tempIdx > keyIdx)
//                     {
//                         swap(arr[tempIdx],arr[tempIdx-1]);
//                         tempIdx--;
//                     }
//                     break;
//                 }
//             }
            
//         }
//     }
// }
void process(int arr[],int n){
    for (int i = n-1; i >=0 ; i--)
    {
        int min_even;
        for (int j = i; j >= 0; j--){
            if(arr[j]%2==0){
                min_even = j;
                for (int k = j; k >= 0; k--)
                {
                    if(arr[k]%2==0 && arr[k] < arr[j]){
                        min_even = k;
                    }
                }
                
            }
        }
        swap(arr[i],arr[min_even]);
    }
    
}
int main(){
    int arr[] = {9,2,6,7,10,8,5};
    int n = sizeof(arr)/sizeof(int);
    process(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}