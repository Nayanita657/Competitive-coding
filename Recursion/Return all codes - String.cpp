#include <string.h>
using namespace std;
#include <iostream>


int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}


string get_char(int num)
{
    string result;
    switch(num){
        case 1:
            result="a";
            break;
        case 2:
            result="b";
            break;
        case 3:
            result="c";
            break;
        case 4:
            result="d";
            break;
        case 5:
            result="e";
            break;
        case 6:
            result="f";
            break;
        case 7:
            result="g";
            break;
        case 8:
            result="h";
            break;
        case 9:
            result="i";
            break;
        case 10:
            result="j";
            break;
        case 11:
            result="k";
            break;
        case 12:
            result="l";
            break;
        case 13:
            result="m";
            break;
        case 14:
            result="n";
            break;
        case 15:
            result="o";
            break;
        case 16:
            result="p";
            break;
        case 17:
            result="q";
            break;
        case 18:
            result="r";
            break;
        case 19:
            result="s";
            break;
        case 20:
            result="t";
            break;
        case 21:
            result="u";
            break;
        case 22:
            result="v";
            break;
        case 23:
            result="w";
            break;
        case 24:
            result="x";
            break;
        case 25:
            result="y";
            break;
        case 26:
            result="z";
            break;
            
    }
    return result;
    
}

int Get_length(string output[1000])
{
    int count = 0;
    int i=0;
    while(output[i]!="\0")
    {
        i++;
        count++;
    }
    return count;
}

void helper(string input,string temp_output, string output[1000])
{
    if(input.empty())
    {
        //cout<<temp_output<<endl;
        int size = Get_length(output);
        output[size] = temp_output;
    }
    else
    {
        //taking one part
        
        char ch1 = input[0];
        int val = int(ch1);
        int val1 = val - 48;
        string ch = get_char(val1);
        string new_output = temp_output + ch;
        string new_input = input.substr(1);
        helper(new_input,new_output,output);
        
        
        //taking two char in a single part
        
        if(input.length()>=2)
        {
            //char ch = get_char(input.substr(0,2));
            int myint1 = stoi(input.substr(0,2));
            if(myint1<=26)
            {
                string ch3 = get_char(myint1);
                string newoutput1 = temp_output + ch3;
                string new_input1 = input.substr(2);
                helper(new_input1,newoutput1,output);
                
            }
            
            
        }
        
    }
}

int getCodes(string input, string output[10000]) {
   string temp_output = "";
   helper(input,temp_output,output);
   int size = Get_length(output);
   return size;
}

