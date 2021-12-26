#include <iostream>
#include <stack>
using namespace std;



void reverseStack(stack<int> &stack1, stack<int> &stack2) 
{

    if(stack1.size() == 1 || stack1.empty())
    {
        return ;
    }
    else
    {
        int item = stack1.top();
        stack1.pop();
        reverseStack(stack1,stack2);
        //move the elements from stack to extra
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        //place the item in the std::stack<
        stack1.push(item);
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        }
        
    }

    
}

int main() {
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty()) {
        cout << input.top() << " ";
        input.pop();
    }
}
