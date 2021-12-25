

#include <iostream>

using namespace std;
#include <bits/stdc++.h>


class stackUsingArray{
    int *data;
    int nextIndex;
    int capacity;
    
    public:
    stackUsingArray()
    {
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
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
            //cout<<"stack full \n";
            int *newdata = new int[2 * capacity];
            //copying data from old, N> ;
            for(int i = 0; i < nextIndex ;i++)
            {
                newdata[i] = data[i];
                
            }
            
            capacity = 2 * capacity;
            delete[] data;
            data = newdata;
            data[nextIndex] = element;
            nextIndex++;
            
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
    stackUsingArray s1;
    
    s1.push(65);
    s1.push(66);
    s1.push(67);
    s1.push(68);
    s1.push(69);
    s1.push(79);
    
    s1.display();
    
    cout<<" top element : "<<s1.top()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    cout<<"popped element : "<<s1.pop()<<endl;
    
    return 0;
}

