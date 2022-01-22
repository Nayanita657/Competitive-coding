#include <iostream>
using namespace std;
#include <unordered_map>

int pairSum(int *arr, int n) {
	
    // Write your code here
    int find_pair = 0;
	unordered_map<int,int> umap;
    for(int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }
    unordered_map<int, int>:: iterator itr1;
    for(itr1 = umap.begin(); itr1!= umap.end(); itr1++)
    {
        int find_element = 0 - (itr1->first);
        if(find_element == itr1->first)
        {
            int temp = itr1->second;
            temp = (temp * (temp -1))/2;
            find_pair = find_pair + temp;
            
        }
        
        else
        {
           int occur_ele1 = itr1->second;
        	if(umap.count(find_element) > 0)
        	{
            	auto itr2 = umap.find(find_element);
            	int occur_ele2 = itr2->second;
            	find_pair = find_pair + (occur_ele1 * occur_ele2);
            	umap.erase(find_element);
        	} 
        }
        
    }
    return find_pair;
}



int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}