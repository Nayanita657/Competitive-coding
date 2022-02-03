#include <bits/stdc++.h>
using namespace std;
#include <string.h>

int LCS(string s, string t)
{
    //base case
    if(s.size() == 0 || t.size() == 0)
    {
        return 0;
    }
    
    //recursive calls
    if(s[0] == t[0])
    {
        return 1 + LCS(s.substr(1) , t.substr(1));
    }
    int a = LCS(s , t.substr(1));
    int b = LCS(s.substr(1) , t);
    int c = LCS(s.substr(1) , t.substr(1));
    return max(a , max(b , c));
}

int main()
{
    string s, t;
    cin>>s>>t;
    cout<<LCS(s,t);
}