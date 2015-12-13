//分治法求最大最小值
#include <iostream>
#include <time.h>

using namespace std;

int getMax(int *array, int i, int j);
int getMin(int *array, int i, int j);

int main() {
	srand(time(NULL));

	const int length = 3;
	int arr[length];

	for (int i = 0;i < length;i++) {
		arr[i] = rand();
		cout<<arr[i]<<" ";
	}

	cout<<endl;

	cout<<"最大值："<<getMax(arr,0,length - 1);
	cout<<"最小值："<<getMin(arr,0,length - 1);
	cout<<endl;

	return 0;
}

int getMax(int *array, int i, int j) {
    int firstMax = 0;
    int secondMax = 0;

    if (i == j) {
        return array[j];
    } else if (i == (j - 1)) {
        firstMax = array[i];
        secondMax = array[j];
        return firstMax > secondMax ? firstMax : secondMax;
    } else {
        int mid = (i + j) / 2;
        firstMax = getMax(array, i, mid);
        secondMax = getMax(array, mid + 1, j);
        return firstMax > secondMax ? firstMax : secondMax;
    }
}

int getMin(int *array, int i, int j) {
    int firstMin = 0;
    int secondMin = 0;

    if (i == j) {
        return array[j];
    } else if (i == (j - 1)) {
        firstMin = array[i];
        secondMin = array[j];
        return firstMin < secondMin ? firstMin : secondMin;
    } else {
        int mid = (i + j) / 2;
        firstMin = getMin(array, i, mid);
        secondMin = getMin(array, mid + 1, j);
        return firstMin < secondMin ? firstMin : secondMin;
    }
}