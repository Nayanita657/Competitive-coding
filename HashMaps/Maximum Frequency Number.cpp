#include <iostream>
using namespace std;

#include <unordered_map>
int highestFrequency(int arr[], int n) 
{
    // Write your code here
    unordered_map<int,int> ourmap;
    for(int i = 0; i < n; i++)
    {
        ourmap[arr[i]]++; 
            
  	}
    
    int max_element;
    int max_occurence = 0;
    for(int i = 0; i < n; i++)
    {
        if(ourmap[arr[i]] > max_occurence)			
        {
            max_occurence = ourmap[arr[i]];
            max_element = arr[i];
        }
    }
    return max_element;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << highestFrequency(arr, n);

    delete[] arr;
}