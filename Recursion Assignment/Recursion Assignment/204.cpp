#include <iostream>
#include <time.h> 
#include <ctime> 
#include <string> 
#include <cmath>
using namespace std;
 
 

string decimalToBinary(int x, string binaryReplacement)
{

    if (x <= 1)
        return binaryReplacement + (char)(x + '0');
    else {
        if(x%2)
          return binaryReplacement + '1'+ decimalToBinary(x / 2, binaryReplacement);
       
        else
          return binaryReplacement + '0'+ decimalToBinary(x / 2, binaryReplacement);       
    }
}

string reverse(string x, int i,string newString) {
    if (i == x.length()-1 ) {
        
        return newString + x.at(0);
    } 
    else {
        return newString+x.at(x.length()-1-i)+reverse(x,i+1,newString);
    }
}
 
int main()
{
    int x;
    cin>>x;
    int i = 0;
    string blankString = "";
    string binaryReplacement = "";
    string resultString;
    resultString = decimalToBinary(x, binaryReplacement);
    //cout<<resultString<<endl;
    string resultString2 = reverse(resultString,i,blankString);
    cout<<resultString2<<endl;
    return 0;
}