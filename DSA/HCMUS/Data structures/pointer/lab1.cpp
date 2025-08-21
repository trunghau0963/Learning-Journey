#include <iostream>
#include <math.h>
using namespace std;
int **allocate_Matrix(int n, int m)
{
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[m];
    }
    return a;
}
void free_Matrix(int **&a, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
    }
    delete[] a;
}
void swap(int *A, int *B)
{
    int temp = *A;
    *A = *B;
    *B = temp;
}
int *sum(int *A, int *B)
{
    int *Total = new int;
    *Total = *A + *B;
    return Total;
}
void inputArray(int *&a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> *(a + i);
    }
}
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(a + i) << " ";
    }
}
int *findMax(int *a, int n)
{
    int max = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    int *findmax = &max;
    return findmax;
}
int *findLongestAscendingSubarray(int *a, int n, int &length)
{
    int cnt = 1, position, temppos = 0, nSub = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            // 4 11 2 3 41 17 28
            cnt++;
            if (cnt > length)
            {
                position = temppos;
                length = cnt;
            }
        }
        else
        {
            temppos = i + 1;
            cnt = 1;
        }
    }
    int *longest = new int[length];
    for (int i = position ; i < position + length; i++)
    {
        longest[nSub++] = a[i];
    }
    return longest;
}
void swapArrays(int *&a, int *&b, int &na, int &nb)
{
    int *temp = a;
    a = b;
    b = temp;
    int tempn = na;
    na = nb;
    nb = tempn;
}
int *concatenate2Arrays(int *a, int *b, int na, int nb, int &nc)
{
    nc = na + nb;
    int *newArray = new int[nc];
    for (int i = 0; i < na; i++)
    {
        newArray[i] = a[i];
    }
    for (int i = 0; i < nb; i++)
    {
        newArray[na++] = b[i];
    }
    return newArray;
}
int *merge2Arrays(int *a, int *b, int na, int nb, int &nc)
{
    int *newArray = concatenate2Arrays(a, b, na, nb, nc);
    for (int i = 0; i < nc - 1; i++)
    {
        for (int j = i + 1; j < nc; j++)
        {
            if (*(newArray + i) > *(newArray + j))
            {
                swap(&newArray[i], &newArray[j]);
            }
        }
    }
    return newArray;
}
void generateMatrix1(int **&a, int &width, int &length)
{
    do
    {
        cout << "\nInput leght and width : \n";
        cin >> length >> width;
        if(length < 0 || width < 0){
            cout << "\nWrong!\n";
        }
    } while (length < 0 || width < 0);
    a = allocate_Matrix(width, length);
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cin >> a[i][j];
        }
    }
}
int **generateMatrix2(int *a, int *b, int na, int nb, int &crow, int &ccol)
{
    crow = na;
    ccol = nb;
    int **c = allocate_Matrix(na, nb);
    for (int i = 0; i < na; i++)
    {
        for (int j = 0; j < nb; j++)
        {
            c[i][j] = a[i] * b[j];
        }
    }
    return c;
}
void printMatrix(int **&a, int &length, int &width)
{
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}
void swapRows(int **a, int length, int width, int ir1, int ir2)
{
    swap(a[ir1], a[ir2]);
}
void swapColumns(int **a, int length, int width, int ic1, int ic2)
{
    for (int i = 0; i < length; i++)
    {
        swap(&a[i][ic1], &a[i][ic2]);
    }
}
int **transposeMatrix(int **a, int length, int width)
{
    // length > width ? length = width : width = length;
    int **temp = allocate_Matrix(width, length);
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            temp[i][j] = a[j][i];
        }
    }
    return temp;
}
// int** concatenate2MatricesH(int** a, int** b,int length, int width, int &lres, int &wres){
    
// }
// int** concatenate2MatricesV(int** a, int** b,int length, int width, int &lres, int &wres){

// }
bool multiple2Matrices(int **&res, int **a, int **b, int &lengthr, int &widthr, int lengtha, int widtha, int lengthb, int widthb)
{
    if (lengtha != widthb)
    {
        return false;
    }
    widthr = widtha;
    lengthr = lengthb;
    res = allocate_Matrix(widthr, lengthr);
    for (int i = 0; i < widthr; i++)
    {
        for (int j = 0; j < lengthr; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < lengtha; k++)
            {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return true;
}
int LinearSearch(int *a, int n, int key)
{
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            i = pos;
        }
    }
    return pos;
}
int SentinelLinearSearch(int *a, int n, int key)
{
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            i = pos;
        }
    }
    return pos;
}
int BinarySearch(int *a, int n, int key)
{
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int m = (l + r) / 2;
        if (a[m] == key)
        {
            return m;
        }
        else if (key > a[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}
int RecursiveBinarySearch(int* a, int left, int right, int key){
    if(left + 1 < right){
        int mid = (left + right)/2;
        if(a[mid] == key){
            return mid;
        }
        else if ( a[mid] < key){
            return RecursiveBinarySearch(a,mid+1,right,key);
        }
        else{
            return RecursiveBinarySearch(a,left,mid-1,key);
        }
    }
    return -1;
}
int main()
{
    // int a = 5, b = 6;
    // int *A = &a, *B = &b;
    // swap(A,B);
    // cout << *A << " " << *B << endl;
    // cout << *sum(A,B) << endl;
    // int n, length = 0;
    // cout << "nhap n : ";
    // cin >> n;
    // int *A = new int[n];
    // inputArray(A,n);
    // printArray(A,n);
    // cout << "\nMax : " << *findMax(A,n);
    // cout << "\nLongest acsending subarray : ";
    // int *subArray = findLongestAscendingSubarray(A,n,length);
    // printArray(subArray,length);
    // int na = 5, nb = 3,nc;
    // int *a = new int[na]{1,2,3,4,5};
    // int *b = new int[nb]{3,4,5};
    // int **arr,**brr, length,width;
    // swapArrays(a,b,na,nb);
    // cout << "\nMang A :\n";
    // printArray(a,na);
    // cout << "\nMang B :\n";
    // printArray(b,nb);
    // cout << "\nMang C :\n";
    // int *c = concatenate2Arrays(a,b,na,nb,nc);
    // printArray(c,nc);
    // cout << "\nMerge ascending : \n";
    // int *merge = merge2Arrays(a,b,na,nb,nc);
    // printArray(merge,nc);
    // // generateMatrix1(arr,length,width);
    // brr = generateMatrix2(a,b,na,nb,length,width);
    // // cout << "\nMang arr :\n";
    // // printMatrix(arr,length,width);
    // cout << "\nMang brr: \n";
    // printMatrix(brr,length,width);
    // swapRows(brr,length,width,1,2);
    // cout << "\nMang brr sau khi swap row: \n";
    // printMatrix(brr,length,width);
    // swapColumns(brr,length,width,1,2);
    // cout << "\nMang brr sau khi swap col: \n";
    // printMatrix(brr,length,width);
    // int **transpose = transposeMatrix(brr,length,width);
    // cout << "After transpose Matrix :" << endl;
    // printMatrix(transpose,width,length);
    int **a, **b, lengtha = 3, widtha = 4, lengthb = 3, widthb = 3;
    cout << "\nArr:\n";
    generateMatrix1(a, widtha, lengtha);
    printMatrix(a, lengtha, widtha);
    cout << "\nBrr:\n";
    generateMatrix1(b, widthb, lengthb);
    printMatrix(b, lengthb, widthb);
    cout << "multiple Matrix :" << endl;
    int **res, lengthr, widthr;
    multiple2Matrices(res, a, b, lengthr, widthr, lengtha, widtha, lengthb, widthb);
    printMatrix(res, lengthr, widthr);
    return 0;
}