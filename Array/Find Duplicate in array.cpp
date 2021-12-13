#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int findDuplicate(int *arr, int n)
{
   //creating an vector and copying the element from array to vector
    vector<int> cal_array(arr + 0, arr + n);
    //unordered map holds the occurance of the element in the list
    unordered_map<long long, long long> umap;
    //pushing element in the unordered list from vector
    for(auto x:cal_array)
        umap[x]++;
    
    int element;
    for (auto itr = umap.begin(); itr != umap.end(); itr++) 
    {
        if(itr->second == 2)
        {
            element=itr->first;
            break;
        }
    }
    return element;
}


int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}