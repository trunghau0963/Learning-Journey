#include<iostream>
using namespace std;
void xamLz(int n){
    int i = 1;
    int count = 0, count_assign = 2, count_compare = 0;
    while (++count_compare && i<= n*n)
    {
        int x = 2*n - i; count_assign++;
        int y = i - n; count_assign++;
        if(++count_compare && x>0){
            int j = 1; count_assign++;
            while (++count_compare && j<=x)
            {
                if(++count_compare && y>0){
                    count += i*j; count_assign++;
                }
                j++;count_assign++;
            }
        }
        i++;count_assign++;
    }
    cout << "count : " << count << endl;
    cout << "Asign : " << count_assign << endl;
    cout << "Compare : " << count_compare << endl;
}
int main(){
    xamLz(100);
    return 0;
}