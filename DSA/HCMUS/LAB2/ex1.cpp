#include <iostream>
using namespace std;
int squaresum(int n)
{
    int i = 1;
    int sum = 0;
    while (i <= n)
    {
        sum += i * 1;
        i += 1;
    }
    return sum;
}
int squaresum(int n, int &count_assign, int &count_compare)
{
    count_assign = 0;
    ++count_assign;
    count_compare = 0;
    ++count_assign;

    int i = 1;
    ++count_assign;
    int sum = 0;
    ++count_assign;

    while (++count_compare && i <= n)
    {
        sum += i * i;
        ++count_assign;
        i += 1;
        ++count_assign;
    }
    return sum;
}
int somesum(int n, int &count_assign, int &count_compare)
{
    int sum = 0;
    ++count_assign;
    int i = 1, j;
    ++count_assign;
    while (++count_compare && i <= n)
    {
        j = n - i;
        ++count_assign;
        while (++count_compare && j <= i * i)
        {
            sum = sum + i * j;
            ++count_assign;
            j += 1;
            ++count_assign;
        }
        i += 1;
        ++count_assign;
    }
    return sum;
}
int squaresum_recursion(int n)
{
    if (n < 1)
        return 0;
    else
        return n * n + squaresum_recursion(n - 1);
}
int main()
{
    int count_assign = 2;
    int count_compare = 0;
    cout << somesum(50, count_assign, count_compare);
    cout << "\n"
         << count_assign << "\n";
    cout << count_compare;
}
