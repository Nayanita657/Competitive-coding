
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void sort_array(int *a,int n)
{
     int count_zero =0;
    int count_one = 0;
    int count_two = 0;
    
    for(int i=0;i<n;i++)
    {
        if(a[i] == 0)
        {
            count_zero++;
        }
        else if(a[i] == 1)
        {
            count_one++;
        }
        else
        {
            count_two++;
        }
    }
    
    int index =0;
    
    for(int i=0; i<count_zero ;i++)
    {
        a[index] = 0;
        index++;
    }
    
    for(int i=0;i<count_one;i++)
    {
        a[index] = 1;
        index++;
    }
    
    for(int i=0;i<count_two;i++)
    {
        a[index] = 2;
        index++;
    }
}

void printsortedarray(int *arr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int no_testcase;
    cout<<"Enter no of tets cases:\n";
    cin>>no_testcase;
    
    int size;
    cout<<"Enter size\n";
    cin>>size;
    int *arr = new int(size);
    
    cout<<"Enter elements:\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    
    sort_array(arr,size);
    
    cout<<"Sorted array:\n";
    printsortedarray(arr,size);
    
   
}