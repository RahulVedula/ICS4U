#include <iostream>
#include <time.h> 
#include <ctime> 
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
  if (b == 0) return a;
  return gcd(b, a % b);
}
 
long long lcm(long long a, long long b)
{
    return (a / gcd(a, b)) * b;
}

long long fractorial (long long x){
    if (x == 0){
        return 1;
    }
    else{

        return lcm(x,fractorial(x-1));
    }
}

int main() {
    int x;
    cin>>x;
    cout<<fractorial(x)<<endl;
    return 0;
}