#include <iostream>
#include <time.h> 
#include <ctime> 
#include <cmath>
using namespace std;

int GCD(int x, int y) {
    if (y == 0) {
        return x;
    } 
    else {
        return GCD(y, x%y);
    }
}

int main() {
    int x,y;
    int result;
    cin >> x;
    cin >> y;
    result = GCD(x,y);
    cout<<result<<endl;
    return 0;
}
