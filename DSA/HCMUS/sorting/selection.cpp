#include<iostream>
#include<vector>
using namespace std;
// void selectionSort(vector<int> &a){
//     for (size_t i = 0; i < a.size(); i++)
//     {
//         int min = i;
//         for (size_t j = i; j < a.size(); j++)
//         {
//             if(a[j] <= a[min]){
//                 min = j;
//             }
//         }
//         swap(a[i],a[min]);    
//     }
// }
// void selectionSort(vector<int> &a){
//     int n = a.size() - 1;
//     for (size_t i = 0; i < a.size(); i++)
//     {
//         int max = i;
//         for (size_t j = i; j < a.size(); j++)
//         {
//             if(a[j] >= a[max]){
//                 max = j;
//             }
//         }
//         swap(a[max],a[i]);
//     }
// }
void selectionSort(vector<int> &a){
    for (int i = a.size()-1; i >= 0; i--)
    {
        int min = i;
        for (int j = i ; j >= 0; j--)
        {
            if(a[j] <= a[min]){
                min = j;
            }
        }
        swap(a[i],a[min]);
        
    }
}
int main(){
    vector<int> a = {65,808,710,377,472,435,850,966};
    selectionSort(a);
    for (size_t i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    
    return 0;
}