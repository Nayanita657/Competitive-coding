#include <iostream>
using namespace std;
void removemax(int *arr, int size)
{
     int heap_size = size - 1;
    while(heap_size > 0)
    {
        int temp = arr[0];
        arr[0] = arr[heap_size];
        arr[heap_size] = temp;
        
        heap_size--;
        int parent_index = 0;
        int left_child_index = (2 * parent_index) + 1;
        int right_child_index = (2 * parent_index) + 2;
        
        while(left_child_index <= heap_size)
        {
            int max_index = parent_index;
            
            if(arr[max_index] > arr[left_child_index])
                max_index = left_child_index;
                
            if(right_child_index <= heap_size && arr[max_index] > arr[right_child_index])
                max_index = right_child_index;
                
            if(max_index == parent_index)
                break;
            
            int temp = arr[max_index];
            arr[max_index] = arr[parent_index];
            arr[parent_index] = temp;
            parent_index = max_index;
            left_child_index = (2 * parent_index) + 1;
            right_child_index = (2 * parent_index) + 2;
        }
        
        
    }
}

void heapSort(int arr[], int size) 
{
    // Write your code
     int heap_index = 1;
    while(heap_index < size)
    {
        int child_index = heap_index;
        while(child_index > 0)
        {
            int parent_index = (child_index - 1)/2;
            if(arr[parent_index] < arr[child_index])
                break;
            if(arr[child_index] < arr[parent_index])
            {
                int temp = arr[child_index];
                arr[child_index] = arr[parent_index];
                arr[parent_index] = temp;
            }
            child_index = parent_index;
        }
        heap_index++;
    }
    
    removemax(arr,size);
}
int main() {
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> input[i];
    } 

    heapSort(input, size);

    for (int i = 0; i < size; i++) {
        cout << input[i] << " ";
    } 

    delete[] input;
}