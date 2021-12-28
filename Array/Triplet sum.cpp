#include <iostream>
#include <algorithm>
using namespace std;

#include "solution.h"

int pairSum(int *arr,int startIndex,int endIndex,int num){
    int numPair=0;
    
    
    while(startIndex<endIndex){
        int currentsum=arr[startIndex]+arr[endIndex];
        
        if(currentsum<num){
            startIndex++;
        }
        else if(currentsum>num){
            endIndex--;
        }
        else{
            
            int elementAtStart=arr[startIndex];
            int elementAtEnd=arr[endIndex];
                
            if(elementAtStart==elementAtEnd){
                
                int totalElements=(endIndex-startIndex)+1;
                numPair+=(totalElements*(totalElements-1))/2;
                return numPair;
            }
            
            int tempstart=startIndex+1;
            int tempend=endIndex-1;
            
            while(tempstart<=tempend && arr[tempstart]==elementAtStart){
                tempstart+=1;
            }
            
            while(tempend>=tempstart && arr[tempend]==elementAtEnd){
                tempend-=1;
            }
            
            int totalElementsFromStart=tempstart-startIndex;
            int totalElementsFromEnd=endIndex-tempend;
            
            numPair+=(totalElementsFromStart*totalElementsFromEnd);
            
            startIndex=tempstart;
            endIndex=tempend;
        }
    }
    return numPair;
}




int tripletSum(int *arr, int n, int num)
{
	sort(arr,arr+n);
    
    int numTriplets=0;
    
    for(int i=0;i<n;i++){
        int pairSumFor=num-arr[i];
        int numPairs=pairSum(arr,(i+1),(n-1),pairSumFor);
        
        numTriplets+=numPairs;
    }
    return numTriplets;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}