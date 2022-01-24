#include <iostream>
using namespace std;
#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) 
{
	// Write your code here/
   int find_pair = 0;
	unordered_map<int,int> umap;
    for(int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }
    unordered_map<int, int>:: iterator itr1;
    for(itr1 = umap.begin(); itr1!= umap.end(); itr1++)
    {
    	int find_element1 = (itr1->first) + k;
        int find_element2 = (itr1->first) - k;
        int occur_ele1 = itr1->second;
        if(find_element1 == itr1->first && find_element2 == itr1->first)
        {
            int temp = itr1->second;
            temp = (temp * (temp -1))/2;
            find_pair = find_pair + temp;
            
        }
        else
        {
              if(umap.count(find_element1) > 0)
        	  {
            	auto itr2 = umap.find(find_element1);
            	int occur_ele2 = itr2->second;
            	find_pair = find_pair + (occur_ele1 * occur_ele2);
              }
            
        	if(umap.count(find_element2) > 0)
        	{
            	auto itr2 = umap.find(find_element2);
            	int occur_ele2 = itr2->second;
            	find_pair = find_pair + (occur_ele1 * occur_ele2);
           	}
        	itr1->second = 0;
        }  
            
     }
    return find_pair;
    
}


int main() {
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}