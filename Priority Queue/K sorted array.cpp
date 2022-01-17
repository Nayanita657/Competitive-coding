
#include <queue>
#include <iostream>
using namespace std;

void kSortedarray(int arr[],int size,int K)
{
    priority_queue<int> pq;
    for(int i = 0; i < K; i++)
    {
        pq.push(arr[i]);
    }
    
    int j = 0;
    for(int i = K; i < size; i++)
    {
        arr[j] = pq.top();
        j++;
        pq.pop();
        pq.push(arr[i]);
    }
    
    while(!pq.empty())
    {
        arr[j] = pq.top();
        j++;
        pq.pop();
    }
    
}

int main()
{
    int arr[] = {10,12,6,7,9};
    int K = 3;
    kSortedarray(arr,5,K);
    for(int i = 0 ; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
