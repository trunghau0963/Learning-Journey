#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Examinee
{
    string id;
    float maths, literature, physics, chemistry, biology, history, geography, civic_education
    , natural_science,social_science, foreign_language;
};
Examinee readFile(string file_name){
    // char **a = new char * [15];
    // for (int i = 0; i < 15; i++)
    // {       
    //     a[i] = new char[20];
    // }
    
    // fstream file;
    // file.open(file_name,ios::in);
    // for (int i = 0; i < 15; i++)
    // {
    //     file.getline(a[i],10,',');
    // }
    // for (int i = 0; i < 15; i++)
    // {
    //     cout << a[i] << endl;
    // }
    // file.close();
    // for (int i = 0; i < 15; i++)
    // {       
    //     delete[] a[i];
    // }
    // delete[] a;
    Examinee a;
    fstream in;
    in.open(file_name,ios::in);
    if(in.fail()){
        cout << "Error";
    }
    getline(in,a.id,',');
    return a;
}
// vector<Examinee> readExamineeList(string file_name){

// }
// void writeScores(vector<Examinee> examinee_list, string out_file_name);
int main(){
    Examinee a;
    a = readFile("data.txt");
    cout << a.id;
    return 0;
}