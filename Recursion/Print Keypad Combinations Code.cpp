#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

string Getstring(int Num)
{
    string result;
    switch(Num)
    {
        case 0:
            result= "";
            break;
        case 1:
            result= "";
            break;
        case 2:
            result= "abc";
            break;
        case 3:
            result= "def";
            break;
        case 4:
            result= "ghi";
            break;
        case 5:
            result= "jkl";
            break;
        case 6:
            result= "mno";
            break;
        case 7:
            result= "pqrs";
            break;
        case 8:
            result= "tuv";
            break;
        case 9:
            result= "wxyz";
            break;    
    }
    return result;
}

void helper(int num,string output)
{
    if(num == 0)
    {
        cout<<output<<endl;
    }
    else
    {
        int rem = num%10;
        int new_num = num/10;
        string temp = Getstring(rem);
        int size = temp.length();
        for(int i=0;i<size;i++)
        {
            string new_output = temp[i] + output;
            helper(new_num,new_output);
        }
        
        
    }
}


void printKeypad(int num){
    string output = "";
    helper(num,output);
}



int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
