#include <iostream>
using namespace std;

int helper(int input[],int start_index,int end_index,int element)
{
    //base condition
    if(start_index >= end_index)
    {
        return -1;
    }
    
    int mid=(start_index + end_index) / 2;
    
    if(input[mid] == element)
    {
        return mid;
    }
    if(input[mid] < element)
    {
        
        return helper(input,mid+1,end_index,element);
    }
    if(input[mid] > element)
    {
        
        return helper(input,start_index,mid-1,element);
    }
    
}


int binarySearch(int input[], int size, int element) {
    int start_index=0;
    int end_index=size-1;
    return helper(input,start_index,end_index,element);   
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}
