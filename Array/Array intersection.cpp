#include <iostream>
#include <algorithm>
using namespace std;
#include <iostream>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>




void intersection(int *arr1, int *arr2, int n, int m) 
{
    int result[1000];
    int index=0;
    
    //creating an vector and copying the element from array to vector
    vector<int> cal_array1(arr1 + 0, arr1 + n);
    //unordered map holds the occurance of the element in the list
    unordered_map<int, int> umap1;
    //pushing element in the unordered list from vector
    for(auto x:cal_array1)
        umap1[x]++;
    
    
    //creating an vector and copying the element from array to vector
    vector<int> cal_array2(arr2 + 0, arr2 + m);
    //unordered map holds the occurance of the element in the list
    unordered_map<int, int> umap2;
    //pushing element in the unordered list from vector
    for(auto x:cal_array2)
        umap2[x]++;
    
    
    for (auto itr = umap1.begin(); itr != umap1.end(); itr++) 
    {
            
        int element = itr->first;
        int frequency_in_map1 = itr->second;
        
        //searching the element in map2
        
        auto tr = umap2.find(element);
        if(tr!=umap2.end())
        {
            int frequency_in_map2 = tr->second;
            int min_frequency = min(frequency_in_map1,frequency_in_map2);
            for(int j=0;j<min_frequency;j++)
            {
                result[index] = element;
                index++;
            }    
        }
            
        
        
    }
    
    
    
    sort(result, result + index);
    
   
    
    for(int k=0;k<index;k++)
    {
        cout<<result[k]<<" ";
    }
   
}


int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int size1, size2;

		cin >> size1;
		int *input1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> input1[i];
		}

		cin >> size2;
		int *input2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> input2[i];
		}

		intersection(input1, input2, size1, size2);
		
		delete[] input1;
		delete[] input2;
		
		cout << endl;
	}

	return 0;
}