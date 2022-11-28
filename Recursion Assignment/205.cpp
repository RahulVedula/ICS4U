#include <iostream>
#include <time.h> 
#include <ctime> 
#include <cmath>
using namespace std;

double average(int *arr, int i, int n) {
    if (i == n - 1) {
        return arr[i];
    }

    if (i == 0)
        return ((arr[i] + average(arr, i + 1, n)) / n);
    else
        return (arr[i] + average(arr, i + 1, n));
}


int main() {
    int x;
    double result;
    int *ArrayPtr;
    int i = 0;
    cin >> x;
    ArrayPtr= new int[x];
    for (int i = x-1;i >= 0;i--){
        cin>>ArrayPtr[i];
    }
    result =average(ArrayPtr,i,x);
    cout<<round(result*10)/10<<endl;
    return 0;
}
