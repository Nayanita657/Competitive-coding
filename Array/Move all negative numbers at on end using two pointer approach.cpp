
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rearrange(int *a,int left_ptr,int right_ptr)
{
    while(left_ptr < right_ptr)
    {
        if(a[left_ptr] < 0 && a[right_ptr] < 0)
        {
            left_ptr++;
        }
        else if(a[left_ptr] > 0 && a[right_ptr] > 0)
        {
            right_ptr--;
        }
        else if(a[left_ptr] > 0 && a[right_ptr] < 0)
        {
            //swap
            swap(a[left_ptr],a[right_ptr]);
            left_ptr--;
            right_ptr++;
        }
        else
        {
            left_ptr++;
            right_ptr--;
        }
    }
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
    rearrange(arr, 0,n-1);
    printArray(arr, n);
    return 0;
}
