

#include <iostream>

using namespace std;
#include <bits/stdc++.h>

class stackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    
    public:
    stackUsingArray(int size)
    {
        data = new int[size];
        nextIndex = 0;
        capacity = size;
    }
    
    int top()
    {
        if(isEmpty())
        {
            cout<<"Stack empty \n";
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
    
    int size()
    {
        return nextIndex;
    }
    
    bool isEmpty()
    {
        if(nextIndex == 0)
            return true;
        else
            return false;
    }
    
    void push(int element)
    {
        if(nextIndex == capacity)
        {
            cout<<"stack full \n";
            
        }
        else
        {
            data[nextIndex] = element;
            nextIndex++;
        }
        
    }
    
    int pop()
    {
        if(isEmpty())
        {
            cout<<"stack empty \n";
            return INT_MIN;
        }
        else
        {
            nextIndex--;
            return data[nextIndex];
        }
    }
    
    void display()
    {
        for(int i=0; i<nextIndex ; i++)
        {
            cout<<data[i]<<" ";
        }
        cout<<"\n";
    }
};

int main()
{
    stackUsingArray s1(4);
    
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    
    s1.display();
    
    cout<<" top element : "<<s1.top()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    
    return 0;
}

