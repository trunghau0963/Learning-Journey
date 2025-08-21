#include<iostream>
#include<vector>
using namespace std;
void printVec(vector<int> v)
{
    // for(int i = 0 ; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    // for(int i : v)
    // {
    //     cout << i << " ";
    // }
    // iterator
    for(vector<int>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << *it << " ";
    }
    system("pause");
}
int main()
{
    vector<int> v;
    while(1)
    {
        system("cls");
        int n;
        cout << "\nNhap lua chon : ";
        cout << "\n1.Nhap";
        cout << "\n2.Xuat";
        cout << "\n3.ham assign()";
        cout << "\n4.Xoa phan tu cuoi";
        cout << "\n5.Chen phan tu vao vi tri bat ky";
        cout << "\n6.Dung\n";
        cin >> n;
        if(n == 1)
        {
            system("cls");
            int a;
            cout << "\nNhap so muon them";
            cin >>a;
            v.push_back(a);
        }
        else if(n == 2)
        {
            printVec(v);
        }
        else if(n == 3)
        {
            v.assign(v.size(),16);
        }
        else if(n == 4)
        {
            v.pop_back();
        }
        else if(n == 5)
        {
            int pos,value;
            do
            {
                cout << "\nNhap pos : ";
                cin >> pos;
                if(pos < 0 || pos > v.size())
                {
                    cout << "\nNhap sai vui long nhap lai";
                }
            } while (pos < 0 || pos > v.size());
            cout << "\nNhap so ban muon them : ";
            cin >> value;
            for(vector<int>::iterator it = v.begin(); it != v.end();it++)
            {
                if(*it == pos)
                {
                    v.insert(it,value);
                }
            }
        }
        else
        {
            break;
        }
    }
    cout << v.front();
    return 0;
}

