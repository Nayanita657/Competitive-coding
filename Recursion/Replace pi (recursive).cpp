#include <iostream>
using namespace std;

#include<cstring>
void replacePi(char input[]) 
{
    int len=strlen(input);
    if(len<=1){
        return;
    }
    else{
        if(input[0]=='p' && input[1]=='i'){
            for(int i=len-1;i>=2;i--){
                input[i+2]=input[i];
            }
            input[0]='3';
            input[1]='.';
            input[2]='1';
            input[3]='4';
            replacePi(input+4);
        }
        else{
            replacePi(input+1);
        }
    }

}

int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
