

#include <iostream>

using namespace std;

int LCS_DP(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int*[m + 1];
    for(int i = 0; i < m + 1; i++)
    {
        output[i] = new int[n + 1];
    }
    //Fill first row 
    for(int j = 0; j < n + 1; j++)
    {
        output[0][j] = 0;
    }
    //Fill first column
    for(int i = 0; i < m + 1; i++)
    {
        output[i][0] = 0;
    }
    //Fill remaining cells
    for(int i = 1; i < m + 1; i++)
    {
        for(int j = 1; j < n + 1; j++)
        {
            //check if first character is equal or not
            if(s[m - i] == t[n - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i][j - 1];
                int c = output[i - 1][j - 1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }
    return output[m][n];
}

int main()
{
    string s, t;
    cin>>s>>t;
    cout<<LCS_DP(s, t);

    return 0;
}
