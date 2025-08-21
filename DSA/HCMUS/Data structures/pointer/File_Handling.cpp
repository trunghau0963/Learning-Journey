#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct Examinee
{
    string id;
    float maths, literature, physics, chemistry, biology, history, geography, civic_education, natural_science,social_science, foreign_language;
};
Examinee readExaminee(string line_info){
    Examinee info;
    FILE *file = fopen(line_info,"rt");
    if(fp!=nullptr){
        fscanf
    }
}
// vector<Examinee> readExamineeList(string file_name){

// }
// void writeScores(vector<Examinee> examinee_list, string out_file_name);
int main(){
}