#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) 
{
    // Write your code here
    unordered_map<int,int> umap;
    int sum = 0;
    int max_length = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
        if(sum == 0)
        {
            max_length = i + 1;
            continue;
        }
        if(umap.find(sum) != umap.end())
        {
            auto itr = umap.find(sum);
            int index = itr->second;
            int temp = i - index;
            if(max_length < temp)
            {
                max_length = temp;
            }
        }
        else
        {
            umap[sum] = i;
        }
    }
    return max_length;
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}