#include<iostream>
using namespace std;
void shellSort(int a[], int l, int r){
    int interval = 1;
    int n = r - l + 1;
    while (interval < n/3){
        interval = interval*3 +1;   
    }
    while (interval > 0)
    {
        for (int i = interval + l; i < r+1; i++)
        {
            int valueToInsert = a[i];
            int inner = i;
            while (inner > interval - 1 && a[inner - interval] >= valueToInsert && inner > l)
            {
                a[inner] = a[inner-interval];
                inner = inner - interval;
            }
            a[inner] = valueToInsert;
        }
        interval = (interval - 1)/3;     
    }
}
long long shellSortCount(int a[], int l, int r){
    int interval = 1, n = r - l + 1;
    long long comparisons = 0;
    while (++comparisons && interval < n/3){
        interval = interval*3 +1;   
    }
    while (++comparisons && interval > 0)
    {
        for (int i = interval + l;++comparisons && i < r + 1; i++)
        {
            int valueToInsert = a[i];
            int inner = i;
            while ((++comparisons && inner > interval - 1) && (++comparisons &&  a[inner - interval] >= valueToInsert) && (++comparisons && inner > l))
            {
                a[inner] = a[inner-interval];
                inner = inner - interval;
            }
            a[inner] = valueToInsert;
        }
        interval = (interval - 1)/3;     
    }
    return comparisons; 
}
void flashSort(int a[],int l, int r){
    int n = r - l + 1;
    int max = 0,maxVal = a[0], min = 0,minVal = a[0];
    int m = int(0.45*n);
    int *L = new int[m];
    // find max && min
    for (int i = 0; i < m; i++)
    {
        L[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[min]){
            minVal = a[i];
            min = i;
        }
        if (a[i] > a[max]){
            maxVal = a[i];
            max = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int k = (m-1)*(a[i]-minVal)/(maxVal - minVal);
        L[k]++;
    }
    for (int i = 1; i < n; i++)
    {
        L[i] += L[i-1];
    }
    swap(a[max],a[0]);
    //permutation
    int move = 0, j = 0,k = m - 1;
    int flash;
    while (move < (n-1))
    {
        while (j > (L[k]-1))
        {
            j++;
            k = (m-1)*(a[j]-minVal)/(maxVal - minVal);
        }
        flash = a[j];
        if(k < 0) break;
        while (j != L[k])
        {
            k = (m-1)*(flash - minVal)/(maxVal - minVal);
            --L[k];
            swap(flash,a[L[k]]);
            ++move;
        }
    }
    //insertion 
    for (int i = 1; i < n; i++)
    {
        int hold = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > hold)
        {
            a[j + 1] = a[j--];
        }
        a[j+1] = hold;
    }
}
int flashSortCount(int a[],int l, int r){
    int comparisons = 0;
    int n = r - l + 1;
    int max = 0,maxVal = a[0], min = 0,minVal = a[0];
    int m = int(0.45*n);
    int *L = new int[m];
    // find max && min
    for (int i = 0;++comparisons && i < m; i++)
    {
        L[i] = 0;
    }
    for (int i = 1;++comparisons && i < n; i++)
    {
        if (++comparisons && a[i] < a[min]){
            minVal = a[i];
            min = i;
        }
        if (++comparisons && a[i] > a[max]){
            maxVal = a[i];
            max = i;
        }
    }
    for (int i = 0;++comparisons && i < n; i++)
    {
        int k = (m-1)*(a[i]-minVal)/(maxVal - minVal);
        L[k]++;
    }
    for (int i = 1;++comparisons && i < n; i++)
    {
        L[i] += L[i-1];
    }
    swap(a[max],a[0]);
    //permutation
    int move = 0, j = 0,k = m - 1;
    int flash;
    while (++comparisons && move < (n-1))
    {
        while (++comparisons && j > (L[k]-1))
        {
            j++;
            k = (m-1)*(a[j]-minVal)/(maxVal - minVal);
        }
        flash = a[j];
        if(++comparisons && k < 0) break;
        while (++comparisons && j != L[k])
        {
            k = (m-1)*(flash - minVal)/(maxVal - minVal);
            --L[k];
            swap(flash,a[L[k]]);
            ++move;
        }
    }
    //insertion 
    for (int i = 1;++comparisons && i < n; i++)
    {
        int hold = a[i];
        int j = i - 1;
        while ((++comparisons && j >= 0) && (++comparisons && a[j] > hold))
        {
            a[j + 1] = a[j--];
        }
        a[j+1] = hold;
    }
    return comparisons;
}
int main(){
    int a[]{13,14,1,5,16,773,4,1,3,13,83,414,1,51,46,91,6,1,61,234,2,4,124,166161,15,15,21,5,6,16,1};
    int n = sizeof(a)/sizeof(int);
    // cout << "\n" << shellSortCount(a,3,10) << "\n";
    shellSort(a,3,10);
    // flashSort(a,0,n-1);
    for(int x : a){
        cout << x << " ";
    }
    cout << "\n" << flashSortCount(a,0,n-1) << "\n";
    // flashSort(a,0,n-1);
    for(int x : a){
        cout << x << " ";
    }
    return 0;
}