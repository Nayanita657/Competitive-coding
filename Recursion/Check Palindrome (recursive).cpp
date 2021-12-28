#include <iostream>
using namespace std;

#include <cstring>
bool helper(char *input,int start,int end)
{
    if(start>end)
    {
        return true;
    }
    if(input[start]==input[end])
    {
        start=start+1;
        end=end-1;
        return helper(input,start,end);
    } 
    else 
        return false;
}
bool checkPalindrome(char input[]) {
    // Write your code here
    int size=strlen(input);
    int start=0;
    int end=size-1;
    if(helper(input,start,end))
    {
        return true;
    }
    else
        return false;

}




int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
