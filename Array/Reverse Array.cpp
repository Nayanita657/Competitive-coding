#include <bits/stdc++.h>
using namespace std;

void printarray(int *arr,int size)
{
    cout<<"Array elements:\n";
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void reverseArray(int *arr,int start,int end)
{
    while(start<end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int size;
    cout<<"Enter the size of array:\n";
    cin>>size;
    int *arr = new int(size);
    cout<<"Enter the elements of array:\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    
    printarray(arr,size);
    
    reverseArray(arr,0,size-1);
    cout<<"\nAfter reverse:\n";
    
    printarray(arr,size);
    return 0;
    
}