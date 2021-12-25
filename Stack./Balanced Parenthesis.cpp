#include <iostream>
#include <string>
using namespace std;

#include <stack>

bool isBalanced(string expression) 
{
    stack<char> st;
    int i=0;
    while(expression[i] != '\0')
    {
        if(expression[i] == '(' )
        {
            char ch = '(';
            st.push(ch);
        }
        if(expression[i] == ')' )
        {
            if(st.empty())
            {
                return false;
            }
            else if(st.top() == '(')
            {
                st.pop();
            }
            
            else
            {
                return false;
            }
        }
        i++;
    }
    if(st.empty())
    	return true;
    else
        return false;
    
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}