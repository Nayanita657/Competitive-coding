#include <iostream>
using namespace std;
// Change in the given string itself. So no need to return or print the changed string.
#include <cstring>


void helper(char input[],char *output,int  &out_index)
{
    int size=strlen(input);
    if(size==1)
    {
        output[out_index]=input[0];
        return;
    }
    else
    {
        if(input[0]==input[1])
        {
            output[out_index]=input[0];
            out_index++;
            output[out_index]='*';
            out_index++;
            return helper(input+1,output,out_index);
        }
        else
        {
            output[out_index]=input[0];
            out_index++;
            return helper(input+1,output,out_index);
        }
    }
}

void pairStar(char input[]) {
    // Write your code here
    int size=strlen(input);
    
    char *output=new char(size);
    int out_index=0;
    
    helper(input,output,out_index);
    int i;
    
    for(i=0;i<=out_index;i++)
    {
        input[i]=output[i];
    }
    input[i]='\0';
        

}


int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
