#include <iostream>
using namespace std;

template <class T>
void sort(T a[],int n)
{
    int i,j,k;
    T temp;

    for (i = 0;i < n;i++) {
        k = i;
        for (j = i + 1;j < n;j++) {
            if (a[k] > a[j]) {
                k = j;
            }
        }
        if (k != i) {
            temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
}

int main()
{
    int a[10];
    int i = 0;
    int count1 = 0,count2 = 0;
    
    cin>>count1;
    for (i = 0;i < count1;i++) {
        cin>>a[i];
    }

    double b[10];

    cin>>count2;
    for (i = 0;i < count2;i++) {
        cin>>b[i];
    }

    sort(a,count1);
    sort(b,count2);

    for (i = 0;i < count1;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    for (i = 0;i < count2;i++) {
        cout<<b[i]<<" ";
    }
    cout<<endl;
}





























