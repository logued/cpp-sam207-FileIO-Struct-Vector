#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    double height;
    string email;
    int age;
};

void display(const Student &stud)
{
    cout <<left
    << setw(15)<< stud.name
    <<setw(5) <<stud.age
    <<setw(10)<< stud.height
    <<setw(50)<<stud.email
    <<endl;

}
void parseLine(string line,Student &stud)
{

    string temp;
    stringstream ss(line);
    getline(ss, stud.name, ',');
    getline(ss, temp, ',');
    stud.height = stod(temp);

    getline(ss, stud.email, ',');
    getline(ss, temp, ',');
    stud.age = stoi(temp);

}
void load(string fname)
{
    ifstream fin(fname);

    if(fin)
    {
        string line;
        while(getline(fin, line))
        {
            Student stud;
            parseLine(line, stud);
            display(stud);
        }
        fin.close();
    }
    else
    {
        cout << "Error opening file." <<endl;
    }
}
int main() {

    Student stud;
    stud.age = 21;
    stud.name = "Peter";
    stud.height = 1.7;
    stud.email = "peter@oscorp.com";
    //display(stud);
    cout <<left<< setw(15)<< "Name" <<setw(5) <<"Age"<<setw(10)
         << "Height" <<setw(50) <<"Email"<<endl;

    load("student.txt");
    return 0;
}