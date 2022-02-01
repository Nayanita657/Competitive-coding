#include <iostream>
using namespace std;
long helper(int n , long *ans)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        if(ans[n] != -1)
        {
            return ans[n];
        }
        long x = 0;
        long y = 0;
        long z = 0;
        //calculation for 1step
        if(n - 1 >= 0)
        {
            x = helper(n -1 , ans);
        }
        //calculation for 2nd step
        if(n - 2 >= 0)
        {
            y = helper(n - 2 , ans);
        }
        //calculation for 3rd step
        if(n - 3 >= 0)
        {
            z = helper(n - 3 , ans);
        }
        long output = x + y + z;
        ans[n] = output;
        return output;
    }
}
long staircase(int n)
{
	//Write your code here
    long *ans = new long[n + 1];
    for(int i = 0; i < n + 1; i++)
    {
		ans[i] = -1;
    }
    return helper(n , ans);
}
int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}
