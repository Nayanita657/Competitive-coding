#include <iostream>
using namespace std;
#include <cmath>
int helper(int n, int *ans)
{
    if (n == 0 || n == 1)
        return 1;
    else
    {
        if(ans[n] != -1)
        {
            return ans[n];
        }
        int x = helper(n - 1, ans);
        int y = helper(n - 2 , ans);
        int d = (int)(pow(10,9)) + 7;
        int temp1 = (int)(((long)(x) * x) % d);
        int temp2 = (int)((2 * (long)(x) * y) % d);
        int result = (temp1 + temp2) % d;
        ans[n] = result;
        return result;
    }
}

int balancedBTs(int n) 
{
    // Write your code here
    int *ans = new int[n + 1];
    for(int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return helper(n , ans);
    
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}