https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

**********************************************SOLUTION********************************************************

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string str, int k) 
    {
        // your code here
        int start = 0;
        int end = 0;
        int max_length = INT_MIN;
        unordered_map<char,int> map;
        while(end < str.length())
        {
            map[str[end]]++;
            if(map.size() < k)
            {
                end++;
            }
            else if(map.size() == k)
            {
                int temp = end - start + 1;
                if(max_length < temp)
                    max_length = temp;
                end++;
            }
            else if(map.size() > k)
            {
                while(map.size() > k)
                {
                    //remove the elements of the untill the map.size() becomes k
                    map[str[start]]--;
                    if(map[str[start]] == 0)
                    {
                        map.erase(str[start]);
                    }
                    start++;
                }
                end++;
            }
        }
        if(max_length == INT_MIN)
            return -1;
        else
            return max_length;
     
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends
