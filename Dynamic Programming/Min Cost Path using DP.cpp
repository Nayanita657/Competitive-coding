#include <bits/stdc++.h>
using namespace std;

int minCostPath_DP(int **input, int m, int n)
{
    int **output = new int*[m];
    for(int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }
    
    //Fill the last destination cell
    output[m - 1][n - 1] = input[m - 1][n - 1];
    
    //Fill the last row from right to left
    for(int j = n - 2; j >= 0; j--)
    {
        output[m - 1][j] = output[m - 1][j + 1] + input[m - 1][j];
    }
    
    //Fill the last column from buttom to top
    for(int k = m - 2; k >= 0; k--)
    {
        output[k][n - 1] = output[k + 1][n - 1] + input[k][n - 1];
    }
    
    //Fill remaining cells
    for(int i = m - 2; i >= 0; i--)
    {
        for(int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j + 1], output[i + 1][j])) + input[i][j];
        }
    }
    return output[0][0];
}

int main()
{
	int **arr, n, m;
	cin >> n >> m;
	arr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << minCostPath_DP(arr, n, m) << endl;
}