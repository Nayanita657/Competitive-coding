#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

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

void printPermutations_helper(string input,string temp_output,string output[10000])
{
    if(input.empty())
    {
        //cout<<temp_output<<endl;
        int size = Get_length(output);
        output[size] = temp_output;
    }
    				
    else
    {
        for(int i=0;i<input.length();i++)
        {
            char ch = input.at(i);
            string qleft = input.substr(0,i);
            string qright = input.substr(i+1);
            string new_input = qleft + qright;
            printPermutations_helper(new_input,temp_output + ch,output);
        	
        }
        
    }
    
}

int returnPermutations(string input, string output[])
{
    string temp_output = "";
    printPermutations_helper(input,temp_output,output);
   	int size = Get_length(output);
    return size;
}




int main(){
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
