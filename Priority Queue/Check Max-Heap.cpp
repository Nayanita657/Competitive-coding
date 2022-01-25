#include <iostream>
using namespace std;


bool isMaxHeap(int arr[], int n) {
    bool result = true;
    // Write your code here
    for(int i = 0 ; i < n ; i++)
    {
    	int left_child_index = (2 * i) + 1;
        int right_child_index = (2 * i) + 2;
        //checking with left child if exist
        if(left_child_index > n)
        {
            continue;
        }
        if(left_child_index < n && arr[i] > arr[left_child_index])
        {
            //checking with right child if exist
           if(right_child_index < n)
           {
               if(arr[i] > arr[right_child_index])
               {
                   //map heap property persist till now
               	   result =  true;
                   continue;
               }
               else
               {
                   result = false;
                   return result;
               }
            }
           else
           {
             	continue; 
           }
        }   
            
        if(left_child_index < n && arr[i] < arr[left_child_index])
        {
             return false;
         }
       
	}
    return result;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;
}