#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    double height;
    string email;
    int age;
};

void display(const Student& student)
{
    cout <<left                     // keep to left
    <<setw(15)<< student.name       // set width of column for output
    <<setw(5) << student.age
    <<setw(10)<< student.height
    <<setw(50)<< student.email
    <<endl;
}

void parseLine( string line, Student& student )
{
    string temp;
    stringstream ss(line);
    getline(ss, student.name, ',');
    getline(ss, temp, ',');
    student.height = stod(temp);    // string to double
    getline(ss, student.email, ',');
    getline(ss, temp, ',');
    student.age = stoi(temp);   // string to int
}

void load(string fileName, vector<Student>& vector_Student)
{
    ifstream ifs(fileName);

    if(ifs)
    {
        string line;
        while(getline(ifs, line))
        {
            Student tempStudent;
            parseLine(line, tempStudent);
            vector_Student.push_back(tempStudent);
        }
        ifs.close();
    }
    else
    {
        cout << "Error opening file." <<endl;
    }
}
void writeToFile(const vector<Student>& vector_student)
{
    ofstream ofs("Out.txt");
    if(ofs)
    {
        for(int i = 0; i < vector_student.size();i++)
        {
            ofs <<left
                <<setw(15)<< vector_student[i].name // can also use "vector_student.at(i).name"
                <<setw(50)<< vector_student[i].email
                <<setw(5) << vector_student[i].age
                <<setw(10)<< vector_student[i].height
                <<endl;
        }
        ofs.close();
    }
    else
    {
        cout << "Error opening file."<<endl;
    }
}
int main() {
    cout << "sam207 FileIO Struct Vector sample" << endl;

    Student student;
    student.age = 21;
    student.name = "Peter";
    student.height = 1.7;
    student.email = "peter@oscorp.com";
    display(student);

    vector<Student> vector_student;
    load("student.txt", vector_student);

    // declare a pointer to a function that will compare two Student structs based on height
    auto compare_function = [](Student s1, Student s2){return s1.height > s2.height;};

    sort(vector_student.begin(), vector_student.end(), compare_function);

    cout << "Shipping Records from the vector (obtained by Iterator)" << endl;
    // vector<Student>::Iterator
    for(auto iter = vector_student.begin(); iter != vector_student.end(); iter++) {
        display(*iter);
    }

    writeToFile(vector_student);

    //If we need to update all elements in a vector we can use the following
    for( Student& stud: vector_student )     // stu is reference to an element
    {
        stud.age = stud.age + 1;    // increment age by 1
    }
    return 0;
}
