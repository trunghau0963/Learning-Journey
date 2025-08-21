#include<iostream>
#include<vector>
using namespace std;
void selection(vector<int> &a){
    for (int  i = 0; i < a.size(); i++)
    {
        int max = i;
        for ( int j = i; j < a.size(); j++)
        {
            if(a[max] < a[j]){
                max = j;
            }
        }
        swap(a[i],a[max]);
    }
}
void heapify(vector<int> &a, int size,int pos){
    int smallest = pos;
    int left = 2*pos + 1;
    int right = 2*pos + 2;
    if((left < size ) && a[left] < a[smallest]) smallest = left;
    if((right < size ) && a[right] < a[smallest]) smallest = right;
    if(smallest!=pos){
        swap(a[pos],a[smallest]);
        heapify(a,size,smallest);
    }
}
void heapSort(vector<int> &a){
    int n = a.size();
    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(a,n,i);
    }
    for (int i = n-1; i >= 0; i--)
    {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}
void merge(vector<int> &a,int left,int mid,int right){
    int i = left;
    int j = mid +1;
    int n = right - left + 1;
    vector<int> temp;
    while ((i<= mid) && (j<=right))
    {
        a[i] > a[j] ? temp.push_back(a[i++]) : temp.push_back(a[j++]);
    }
    while ((i<=mid))
    {
        temp.push_back(a[i++]);
    }
    while (j<=right)
    {
        temp.push_back(a[j++]);
    }
    for (int i = 0; i < n; i++)
    {
        a[left++] = temp[i];
    }
}
void mergeSort(vector<int> &a,int left, int right){
    if(left + 1 >right){
        return;
    }
    else{
        int mid = (left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int getPivot(vector<int> &a,int left,int right){
    int i = left + 1;
    int j = right;
    int temp = a[left];
    do
    {
        while ((i<=j) && a[i] > temp) i++;
        while ((i<=j) && a[j] <= temp) j--;
        if(i<j){
            swap(a[i++],a[j--]);
        }
    } while (i<=j);
    swap(a[left],a[j]);
    return j;
}
void quickSort(vector<int> &a,int left,int right){
    if(left + 1 > right){
        return;
    }
    else{
        int pivot = getPivot(a,left,right);
        quickSort(a,left,pivot - 1);
        quickSort(a,pivot+1,right);
    }
}
int findMax(vector<int> a){
    int max = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        if(max < a[i]){
            max = a[i];
        }
    }
    return max;
}
void countingSort(vector<int> &a){
    vector<int> output;
    vector<int> count[10]{};
    for (int i = 0; i < a.size(); i++)
    {
        /* code */
    }
    
}
int main(){
    vector<int> a{112,31,31,4,413,31,4,4,12,3,1,63,7,4};
    quickSort(a,0,a.size()-1);
    for(int x : a){
        cout << x << " ";
    }
    return 0;
}