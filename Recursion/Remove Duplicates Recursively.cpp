#include <iostream>
using namespace std;
#include <cstring>

void removeConsecutiveDuplicates(char *input) {
	int len=strlen(input);
    if(len==0)
    {
        return;
    }
    else
    {
        if(input[0]==input[1])
        {
            for(int i=1;i<=len;i++)
            {
                input[i-1]=input[i];
            }
            return removeConsecutiveDuplicates(input);
        }
        else
        {
            return removeConsecutiveDuplicates(input+1);
        }
    }
}

int main() {
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}