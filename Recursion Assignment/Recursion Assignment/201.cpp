#include <iostream>
#include <time.h> 
#include <ctime> 
#include <cmath>
using namespace std;

int functionOne(int x) {
    if (x == 1) {
        return 3;
    } 
    else {
        return functionOne(x-1)-2;
    }
}

int functionTwo(int x) {
    if (x == 1) {
        return -1;
    } 
    else {
        return 2*functionTwo(x-1);
    }
}

int main() {
    long long x;
    int result;
    cin >> x;
    result = functionOne(x);
    int result2 =functionTwo(x);
    cout<<result<<endl;
    cout<<result2<<endl;
    return 0;
}
