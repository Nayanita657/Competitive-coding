#include <iostream>
#include <string>
using namespace std;

#include <stack>
int countBracketReversals(string input) {
	// Write your code here
    int length = input.length();
    if(length % 2 != 0)
        return -1;
    else
    {
        int i = 0;
        stack<char> st;
        int count = 0;
        while(input[i] != '\0')
        {
            if(input[i] == '{') 
            {
                st.push(input[i]);
                i++;
            }
            else
            {
                if(st.empty())
                {
                    st.push(input[i]);
                }
                else if(st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    st.push(input[i]);
                }
                i++;
            }
        }
        while(!st.empty())
        {
            char c1 = st.top();
            st.pop();
            char c2 = st.top();
            st.pop();
            if(c1 == c2)
                count = count + 1;
            else
                count = count + 2;
        }
        return count;
    }
    	
    
}
int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}