#include <iostream>
#include <time.h> 
#include <ctime> 
#include <cmath>
using namespace std;

string reverse(string x, int i,string newString) {
    if (i == x.length()-1 ) {
        
        return newString + x.at(0);
    } 
    else {
        return newString+x.at(x.length()-1-i)+reverse(x,i+1,newString);
    }
}

bool isPalindrome (string x, string y, int i){
    if (i == x.length()-1 ) {
        
        return (x.at(i) == y.at(i));
    }
    else if ((x.at(i) != y.at(i))){
        return false;
    }
    else{
        return isPalindrome(x,y,i+1);
    }
}

int main() {
    //Variables for reversing the string
    string x;
    int i = 0;
    string blankString = "";
    string reverseString;
    getline(cin,x);
    //Reversing the string
    reverseString = reverse(x,i,blankString);
    cout<<reverseString<<endl;


    //Variables for checking palindrom 
    bool palindromeCheeck;
    x.erase(remove_if(x.begin(), x.end(), ::isspace),
            x.end());
    reverseString.erase(remove_if(reverseString.begin(), reverseString.end(), ::isspace),
            reverseString.end());
    transform(x.begin(), x.end(), x.begin(), ::tolower);
    transform(reverseString.begin(), reverseString.end(), reverseString.begin(), ::tolower);

    palindromeCheeck = isPalindrome(x,reverseString,i);
    cout<<boolalpha<<palindromeCheeck<<endl;
    return 0;
}
