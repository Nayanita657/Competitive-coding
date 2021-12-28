#include <iostream>
#include <string>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

void printPermutations_helper(string input,string output){
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    				
    else
    {
        for(int i=0;i<input.length();i++)
        {
            char ch = input.at(i);
            string qleft = input.substr(0,i);
            string qright = input.substr(i+1);
            string new_input = qleft + qright;
            printPermutations_helper(new_input,output + ch);
        	
        }
        
    }
    
}


void printPermutations(string input){
   string output="";
   printPermutations_helper(input,output);
    
}

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}