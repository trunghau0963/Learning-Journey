#include <iostream>
#include <vector>
using namespace std;
void heapMin(vector<int> &a, int size, int pos)
{
    int smallest = pos;
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    if (left < size && a[left] > a[smallest])
    {
        smallest = left;
    }
    if (right < size && a[right] > a[smallest])
    {
        smallest = right;
    }
    if (smallest != pos)
    {
        swap(a[pos], a[smallest]);
        heapMin(a, size, smallest);
    }
}
void buildHeap(vector<int> &a){
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapMin(a, n, i);
    }
}
void heapSort(vector<int> &a)
{
    int n = a.size();
    buildHeap(a);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapMin(a, i, 0);
    }
}
int main()
{
    vector<int> a{4,1,3,9,7};
    heapSort(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}