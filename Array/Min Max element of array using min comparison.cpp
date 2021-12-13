
#include <iostream>

using namespace std;

struct Pair{
    int min;
    int max;
    
};

struct Pair Getmin_max(int *arr,int size)
{
    struct Pair dummy;
    if(size == 1)
    {
        dummy.max = arr[0];
        dummy.min = arr[0];
        return dummy;
    }
    
    if(arr[0] > arr[1])
    {
        dummy.max = arr[0];
        dummy.min = arr[1];
    }
    else
    {
        dummy.min = arr[0];
        dummy.max = arr[1];
    }
    
    for(int i=2;i<size;i++)
    {
        if(arr[i] > dummy.max)
        {
            dummy.max = arr[i];
        }
        else if(arr[i] < dummy.min)
        {
            dummy.min = arr[i];
        }
    }
    return dummy;
}

int main()
{
    int size;
    cout<<"Enter the size:\n";
    cin>>size;
    
    int *arr = new int(size);
    cout<<"Enter the array elements:\n";
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    
    struct Pair minmax = Getmin_max(arr,size);
    
    cout<<"Min element :"<<minmax.min<<"\n";
    cout<<"Max element :"<<minmax.max<<"\n";
    return 0;
}
