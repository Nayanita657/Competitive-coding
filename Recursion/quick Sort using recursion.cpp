#include<iostream>
using namespace std;

int partition(int input[],int start_index,int end_index)
{
    int pivot = input[start_index];
    int pivot_index;
    int count=0;
    
    for(int i = start_index + 1; i <= end_index; i++)
    {
        if(pivot > input[i])
        {
            count++;
        }
    }
    
    pivot_index = start_index + count;
    //swapping the pivot element with the element placed at pivot location
    
    int temp = input[pivot_index];
    input[pivot_index] = pivot;
    input[start_index]=temp;
    
    int i=start_index;
    int j=end_index;
    
    while(1)
    {
       if(i == pivot_index || j == pivot_index)
       {
           return pivot_index;
       }
       else
       {
           if (input[i] < pivot) 
            {
                i++;
                //These statements would execute if the condition1 is true
            }
            else if(input[j] >= pivot) 
            {
                j--;
                //These statements would execute if the condition2 is true
            }
            else 
            {
                //swapping the elements
                    int temp = input[i];
                    input[i] = input[j];
                    input[j] = temp;
                    i++;
                    j--; 
                //These statements would execute if all the conditions return false.
            }
        }
    }
}

void helper(int input[],int start_index,int end_index)
{
    if(start_index >= end_index)
        return;
    else
    {
        int pivot_index = partition(input,start_index,end_index);
        
        helper(input, start_index, pivot_index - 1);
        helper(input, pivot_index + 1, end_index);
    }
}

void quickSort(int input[], int size) {
    int start_index = 0;
    int end_index = size-1;
    helper(input, start_index, end_index);
 
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}


