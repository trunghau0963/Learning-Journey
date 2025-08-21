#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
// bool test(vector <int> &arr){
//     for(int i = 0; i < arr.size(); i++){
//         for(int j = i+1; j < arr.size(); j++){
//             if(arr[i] > arr[j]){
//                 swap(arr[i], arr[j]);
//             }
//         }
//     }
//     for(vector<int>::iterator i = arr.begin(); i != arr.end(); i++){
//         if(arr[*i] + 1 != arr[*i+1]){
//             return false;
//         }
//     }
//     return true;
// }
bool test(vector <int> &arr){
    std::sort(arr.begin(),arr.end());
    for(vector<int>::iterator i = arr.begin(); i != arr.end(); i++){
        if(arr[*i] + 1 != arr[*i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector <int> nums = {1, 2 ,5, 0, 3, 6, 7};
    for(int x : nums){
        cout << x << " " ;
    }
    cout << "Test consecutive numbers in the said vector : " << test(nums);
}