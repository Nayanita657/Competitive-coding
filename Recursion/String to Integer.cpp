#include <iostream>
using namespace std;
#include <math.h>
#include <cstring>



int stringToNumber(char input[]) {
    // Write your code here
    int len=strlen(input);
    if(len==1)
    {
        char a = input[0];
        int ia = a - '0';
        return ia;
    }
    else
        
    {
        char a = input[0];
        int ia = a - '0';
        long temp=ia * pow(10,(len-1));
        return temp + stringToNumber(input+1);
    }

}


int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
