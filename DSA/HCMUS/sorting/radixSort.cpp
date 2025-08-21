#include<iostream>
#include<vector>
using namespace std;
int findMax(int arr[],int n){
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max; 
}
void countingSort(int arr[],int n,int base){
    int output[n]{};
    int count[10]{};
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / base) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i-1];
    }
    for (int i = n-1; i >= 0; i--)
    {
        output[count[(arr[i]/base)%10]-1] = arr[i];
        count[(arr[i]/base)%10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}
void radixSort(int arr[],int n){
    int max = findMax(arr,n);
    for (int i = 1; max/i > 0; i*=10)
    {
        countingSort(arr,n,i);
    }
}
// int findMax(vector<int> a){
//     int result = a[0];
//     for(int i = 0; i < a.size();i++)
//         if(a[i]>result) result = a[i];
//     return result;
// }
// void counting(vector<int> &a, int base){
//     vector<int> output (a.size());
//     int count[10] {};
//     for(int i = 0; i<a.size();i++){
//         count[(a[i]/base) % 10]++;
//     }
//     for(int i = 1; i < 10;i++){
//         count[i] += count[i-1];
//     }
//     for (int i = a.size() - 1; i >= 0; i--){
//         output[count[(a[i]/base) % 10] - 1] = a[i];
//         count[(a[i]/base) % 10]--;
//     }
//     a = output;
// }
// void radixSort(vector<int> &a){
//     int max = findMax(a);
//     for(int i = 1; max/i > 0; i *= 10){
//         counting(a,i);
//     }
// }
int main()
{
    int a[]{4233,231,331,139,731};
    int n = sizeof(a)/sizeof(int);
    radixSort(a,n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
// int main(){
//     vector<int> a {121,272,633,1301,53313,91,6311,5331,134};
//     // vector<int> a {1,7,6,0,5,9,6,5,1};
//     for(int x : a){
//         cout << x << " ";
//     }
//     cout << endl;
//     radixSort(a);
//     for(int x : a){
//         cout << x << " ";
//     }
//     return 0;   
// }