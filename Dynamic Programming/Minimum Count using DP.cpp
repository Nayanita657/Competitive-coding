#include <bits/stdc++.h>
using namespace std;
int helper(int n , int *ans)
{
    if(n == 1 || n == 0)
	{
	    return n;
	}
	else
	{
        if(ans[n] != -1)
        {
            return ans[n];
        }
	    int min_length = INT_MAX;
	    for(int i = 1; i <= sqrt(n) ; i++)
	    {
	        int rem = n - (i * i);
	        int output = helper(rem , ans);
	        min_length = min(min_length , output);
	        
	    }
        
        int final_output = min_length + 1;
        ans[n] = final_output;
	    return final_output;
	}
}

int minCount(int n)
{
	//Write your code here
    int *ans = new int[n + 1];
    for(int i = 0; i < n+1 ; i++)
    {
        ans[i] = -1;
    }
    
    
    return helper(n , ans);
}



int main()
{
	int n;
	cin >> n;
	cout << minCount(n);
}