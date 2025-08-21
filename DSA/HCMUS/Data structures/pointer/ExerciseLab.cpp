#include<iostream>

using namespace std;

void f(int n, int &assignment, int &comparation)
{
    int i = 1;  
    int count = 0;

    while(++comparation && i <= n*n)
    {
        int x = 2*n - i;   assignment++;
        int y = i - n;  assignment++;

        if(++comparation && x > 0)
        {
            int j = 1;  assignment++;
            while(++comparation && j <= x)
            {
                if(++comparation && y > 0){
                    count += i * j; assignment++;
                }
                j++;    assignment++;
            }
        }
        i++;    assignment++;
    }
    cout << count << endl;
}

int main()
{
    int n = 100;
    int assignment = 2;
    int comparation = 0;

    f(n, assignment, comparation);

    cout << "assign: " << assignment << endl;
    cout << "compare: " << comparation << endl; 
}