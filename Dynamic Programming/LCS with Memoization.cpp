#include <bits/stdc++.h>
using namespace std;
#include <string.h>

int helper(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();
    //base case
    if(s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    
    //recursive calls
    
    if(output[m][n] != -1)
    {
        return output[m][n];
    }
    
    if(s[0] == t[0])
    {
        int ans = 1 + helper(s.substr(1) , t.substr(1), output);
        output[m][n] = ans;
        return ans;
    }                         
    int a = helper(s , t.substr(1), output);
    int b = helper(s.substr(1) , t, output);
    int c = helper(s.substr(1) , t.substr(1), output);
    int ans = max(a , max(b , c));
    output[m][n] = ans;
    return ans;
}

int LCS_Mem(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int*[m + 1];
    for(int i = 0; i < m + 1; i++)
    {
        output[i] = new int[n + 1];
        for(int j = 0; j < n + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    
    return helper(s, t, output);
}

int main()
{
    string s, t;
    cin>>s>>t;
    cout<<LCS_Mem(s,t);
}