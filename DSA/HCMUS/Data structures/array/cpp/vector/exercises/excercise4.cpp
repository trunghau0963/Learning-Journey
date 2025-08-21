// Write a C++ program to capitalize the first character of each element of a given string vector. Return the new vector. Go to the editor
// Example:
// Original Vector elements:
// red green black white Pink
// Capitalize the first character of each vector element:
// Red Green Black White Pink
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<std::string> kha = {"red" ,"green","black" ,"white" ,"Pink"};
    for(int i = 0; i < kha.size();i++){
        if(kha[i][0] >= 97 && kha[i][0] <= 122)
        {
            kha[i][0] = (char)toupper(kha[i][0]);
        }
    }

    for(int i = 0; i < kha.size();i++){
        cout << kha[i] << " ";
    }
} 