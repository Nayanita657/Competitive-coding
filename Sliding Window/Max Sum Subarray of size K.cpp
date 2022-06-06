https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

******************************************************SOLUTION****************************************************

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long long int maximumSumSubarray(int K, vector<int> &Arr , int N)
    {
        // code here 
        long long int max_sum = INT_MIN;
        long long int sum = 0;
        int start = 0;
        int end = 0;
        while(end < Arr.size())
        {
            int window_size = end - start + 1;
            
            if(window_size < K)
            {
                sum = sum + Arr[end];
                end++;
            }
            else if(window_size > K)
            {
                sum = sum - Arr[start];
                start++;
            }
            //when window size is equal
            else
            {
                sum = sum + Arr[end];
                if(max_sum < sum)
                    max_sum = sum;
                end++;
            }
        }
        return max_sum;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends
