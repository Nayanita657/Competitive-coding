#include <iostream>
#include <stack>
using namespace std;
template <typename T>
class queueusingArray{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;
    
    public:
    queueusingArray(int size)
    {
        data = new int[size];
        nextIndex = 0;
        size = 0;
        firstIndex = -1;
    }
    
    int getSize()
    {
        return size;
    }
    
    bool isEmpty()
    {
        if(size == 0)
            return 1;
        else
            return 0;
    }
    
    void enqueue(T element)
    {
        if(size == capacity)
        {
            cout<<"Queue full\n";
            return;
        }
        else
        {
            data[nextIndex] = element;
            nextIndex = (nextIndex + 1) % capacity;
            if(firstIndex == -1)
            {
                firstIndex = 0;
            }
            size++;
        }
    }
    
    T front()
    {
        if(isEmpty())
        {
            cout<<"queue is empty\n";
            return 0;
        }
        return data[firstIndex];
    }
    
    T dequeue()
    {
        if(isEmpty())
        {
            cout<<"queue is empty \n";
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        return ans;
    }
};

int main()
{
    queueusingArray<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    
    cout<<q.front()<<endl;
    cout<<"deleting element :"<<q.dequeue()<<endl;
    
    
    return 0;
}



