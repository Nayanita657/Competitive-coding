
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rearrange(int *a,int size)
{
    //int size = nums.size();
    int j=0;
    for(int i=0;i<size;i++)
    {
       if(a[i] < 0)
       {
           if(i != j)
           {
               swap(a[i], a[j]);
           }
           j++;
       }
    }
    
    //return nums;
}

void printArray(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr,n);
    printArray(arr, n);
    return 0;
}