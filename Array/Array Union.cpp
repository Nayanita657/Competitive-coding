

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int Find_Union(int *arr1,int size1,int *arr2,int size2)
{
    unordered_map<int,int> umap;
    
    for(int i=0;i<size1;i++)
    {
        umap[arr1[i]]++;
    }
    
    for(int j=0;j<size2;j++)
    {
        umap[arr2[j]]++;
    }
    
    return umap.size();
}

int main()
{
    int no_testcase;
    cout<<"Enter no of test cases:\n";
    cin>>no_testcase;
    
    while(no_testcase--)
    {
        int size1;
        cout<<"Enter size of first array:\n";
        cin>>size1;
    
        int *arr1 = new int(size1);
        cout<<"Enter the 1st array Elements:\n";
        for(int i=0;i<size1;i++)
        {
            cin>>arr1[i];
        }
    
        int size2;
        cout<<"Enter size of 2nd array:\n";
        cin>>size2;
    
        int *arr2 = new int(size2);
        cout<<"Enter the 2nd array Elements:\n";
        for(int i=0;i<size2;i++)
        {
            cin>>arr2[i];
        }
    
        int result = Find_Union(arr1,size1,arr2,size2);
        cout<<"\nNo of common elements between the array->"<<result;
    }
    
    
    return 0;
}
