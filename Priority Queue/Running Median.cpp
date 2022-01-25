#include <iostream>
using namespace std;
#include <cstdlib>
#include <queue>
void findMedian(int *arr, int n)
{
    if(n == 0)
    {
        return;
    }
    priority_queue<int> Max_heap;
    priority_queue<int,vector<int>,greater<int>> Min_heap;
    //insertig first element in maxheap
    Max_heap.push(arr[0]);
    cout<<arr[0]<<" ";
    
    //finding median for remaining element
    for(int i = 1; i < n; i++)
    {
    	if(arr[i] > Max_heap.top())
        {
            Min_heap.push(arr[i]);
        }
        else
        {
            Max_heap.push(arr[i]);
        }
        //Balancing size
        int size_MaxHeap = Max_heap.size();
        int size_MinHeap = Min_heap.size();
        if(abs(size_MaxHeap - size_MinHeap) > 1)
        {
            if(size_MaxHeap > size_MinHeap)
            {
                Min_heap.push(Max_heap.top());
                Max_heap.pop();
            }
            else
            {
                Max_heap.push(Min_heap.top());
                Min_heap.pop();
            }
        }
        //checking even or odd for finding median;
        int temp = size_MaxHeap + size_MinHeap;
        if(temp % 2 == 0)
        {
            int median = (Max_heap.top() + Min_heap.top()) / 2;
            cout<<median<<" ";
        }
        else
        {
            if(Max_heap.size() > Min_heap.size())
            {
                int median = Max_heap.top();
                cout<<median<<" ";
            }
            else
            {
                int median = Min_heap.top();
                cout<<median<<" ";
            }
        }
    }
   
    
}

    

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    findMedian(arr,n);

    delete[] arr;
}
