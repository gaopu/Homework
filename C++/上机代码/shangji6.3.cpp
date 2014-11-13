#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    String(const char *str = NULL);
    String(const String &other);
    ~ String();
    String & operator =(char *str);
    String & operator =(const String &other);
    bool operator==(String &other);
    bool operator==(char *str);
    friend ostream & operator<<(ostream & os,String & s);
private:
    char *m_data;
    int length;
};

String::String(char const *str) {
    length = (int) strlen(str);
    m_data = new char[length + 1];
    strcpy(m_data, str);
}

String::String(const String &other) {
    length = other.length;
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

String::~String() {
    delete[] m_data;
}

bool String::operator==(char *str) {
    return !strcmp(m_data, str);
}

bool String::operator==(String &other) {
    return !strcmp(m_data, other.m_data);
}

String & String::operator=(char *str) {
    delete [] m_data;

    length = (int) strlen(str);
    m_data = new char[length + 1];
    strcpy(m_data, str);
}

String & String::operator=(const String &other) {
    delete [] m_data;

    length = other.length;
    m_data = new char[length + 1];
    strcpy(m_data, other.m_data);
}

ostream & operator<<(ostream & os, String &s) {
    os<<s.m_data;

    return os;
}

int main()
{
    String a("123"),b("456");
    String c(a);

    cout<<a<<b<<endl;
    cout<<c<<endl;
    cout<<a<<endl;
    b = a;
    cout<<b<<endl;
    if (a == b) {
        cout<<"相等\n";
    } else {
        cout<<"不相等\n";
    }
    return 0;
}
