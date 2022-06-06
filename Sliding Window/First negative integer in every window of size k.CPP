https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#

**********************************************SOLUTION************************************************************
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) 
{
    int start = 0;
    int end = 0;
    vector<long long> result;
    list<long long> temp;
    //int size = sizeof(A) / sizeof(A[0]);
    while(end < N)
    {
        int window_size = end - start + 1;
        if(window_size < K)
        {
            if(A[end] < 0)
                temp.push_back(A[end]);
            end++;
        }
        else if(window_size > K)
        {
            if(temp.size() != 0)
            {
                if(temp.front() == A[start])
                {
                    temp.pop_front();
                }
            }
            start++;
        }
        else
        {
            if(A[end] < 0)
                temp.push_back(A[end]);
            if(temp.size() == 0)
                result.push_back(0);
            else
                result.push_back(temp.front());
            end++;
        }
    }
    return result;
}
