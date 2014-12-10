#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    map<string,string> phonebook;
    string t1,t2;

    ifstream fin1("phonebook1.txt");
    while (!fin1.eof()) {
        fin1>>t1>>t2;
        phonebook.insert(pair<string,string>(t1,t2));
    }
    fin1.close();

    ifstream fin2("phonebook2.txt");
    while (!fin2.eof()) {
        fin2>>t1>>t2;
        phonebook.insert(pair<string,string>(t1,t2));
    }
    fin2.close();

    ofstream fout("phonebook3.txt");
    map<string,string>::iterator p = phonebook.begin();
    while (p != phonebook.end()) {
        fout<<p->first<<" "<<p->second<<endl;
        p++;
    }

    return 0;
}
