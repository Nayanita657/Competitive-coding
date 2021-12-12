#include <iostream>
#include <algorithm>
using namespace std;

#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

int pairSum(int *arr, int n, int num)
{
	sort(arr,arr + n); //nlogn
	int i = 0;
	int j = n - 1;
	
	//arr to vector ;
	vector<int> cal_array(arr + 0, arr + n);
	
	//creating unordered map
	unordered_map<int, int> umap;
	
	//inserting element in umap from vector
	for(auto x:cal_array)
        umap[x]++;
        
   
    
    int no_of_pair = 0;
	
	while(i < j)
	{
	    int calculated_sum = arr[i] + arr[j];
	    int element1 = arr[i];
	    int element2 = arr[j];
	    
	    if(calculated_sum == num) //valid pair found
	    {
	        //checking if pair is formed with same element
	        if(element1 == element2)
	        {
	            auto tr = umap.find(element1);
	            int frequency = tr->second;
	            
	            int temp = frequency - 1;
	            no_of_pair = no_of_pair + (temp *(temp + 1))/2;
	        }
	        
            //checking if pair is formed with different element
	        if(element1 != element2)
	        {
	            auto tr1 = umap.find(element1);
	            int frequency1 = tr1->second;
	            
	            auto tr2 = umap.find(element2);
	            int frequency2 = tr2->second;
	            
	            int temp = frequency1 * frequency2;
	            no_of_pair = no_of_pair + temp;
	            
	        }
	        
	        // placig the iterator
	        i++;
	        j--;
	        while(arr[i] == element1 && arr[j] == element2)
	        {
	            i++;
	            j--;
	        }
	        
	        
	        
	    }
	    if(calculated_sum < num)
	    {
	        i++;
	    }
	    if(calculated_sum > num)
	    {
	        j--;
	    }
	}
	return no_of_pair;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}