
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int GetKthsmallest(int *arr, int size, int K)
{
    sort(arr,arr+size);
    
    return arr[K-1];
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
    
    cout<<"Enter K value-\n";
    int K;
    cin>>K;
    
    int result = GetKthsmallest(arr,size,K);
    cout<<result;
}