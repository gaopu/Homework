#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("test1.txt");
    fout<<"Learing C++ programming is fun!";
    fout.close();

    char str[100];
    ifstream fin("test1.txt");
    fin.getline(str,100);
    cout<<str<<endl;
}
