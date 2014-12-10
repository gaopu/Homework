#include <iostream>
#include <fstream>

using namespace std;

class Student
{
private:
    string number;
public:
    Student(string number1 = "haha")
    {
        number = number1;
    }
};

int main()
{
    Student stu1("haha"),stu2;

    ofstream fout("STUD.DAT",ios::binary);
    fout.write((char *)&stu1,sizeof(stu1));
    fout.close();

    ifstream fin("STUD.DAT",ios::binary);
    fin.read((char *)&stu2,sizeof(stu2));

    fin.close();

    return 0;
}
