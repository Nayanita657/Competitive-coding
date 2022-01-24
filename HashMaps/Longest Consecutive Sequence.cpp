#include <iostream>
#include <vector>
using namespace std;
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,bool> umap;
    for(int i = 0; i < n; i++)
    {
        umap[arr[i]] = true;
    }
    int final_length = INT_MIN;
    int start_ele;
    int end_ele;
    for(int i = 0; i < n; i++)
    {
        auto itr = umap.find(arr[i]);
        if(itr->second == true)
        {
            int current_ele = arr[i];
            int length = 1;
            int temp_start = current_ele;
            int temp_end = current_ele;
            //looking forward
            while(1)
            {
                current_ele++;
                if(umap.find(current_ele) != umap.end())
                {
                    temp_end = current_ele;
                    auto itr1 = umap.find(current_ele);
                    itr1->second = false;
                    length++;
                }
                else
                {
                    break;
                }
            }
            //lookig backward
            current_ele = temp_start;
            while(1)
            {
                current_ele--;
                if(umap.find(current_ele) != umap.end())
                {
                    temp_start = current_ele;
                    auto itr2 = umap.find(current_ele);
                    itr2->second = false;
                    length++;
                }
                else
                {
                    break;
                }
            }
            if(final_length == length)
            {
                //find the occurence in the array
                for(int i = 0; i < n; i++)
                {
                    if(arr[i] == start_ele)
                    {
                        
                        break;
                    }
                    if(arr[i] == temp_start)
                    {
                        start_ele = temp_start;
                        end_ele = temp_end;
                        break;
                    }
                }
                
            }
            if(final_length < length)
            {
                start_ele = temp_start;
                end_ele = temp_end;
                final_length = length;
            }
        }
    }
    vector<int> v;
    v.push_back(start_ele);
    v.push_back(end_ele);
    return v;
    
}

int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";

    delete[] arr;
}
