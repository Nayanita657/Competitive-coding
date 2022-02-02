#include <bits/stdc++.h>
using namespace std;

int helper(int **arr,int current_row, int current_column, int final_row, int final_column)
{
    if(current_row == final_row && current_column == final_column)
    {
        return arr[current_row][current_column];
    }
    if(current_row > final_row || current_column > final_column)
    {
        return INT_MAX;
    }
    else
    {
        int cost1 = helper(arr, current_row + 1, current_column , final_row, final_column);
        int cost2 = helper(arr, current_row, current_column + 1, final_row, final_column);
        int cost3 = helper(arr, current_row + 1, current_column + 1, final_row, final_column);
        int min_cost = min(cost1, min(cost2, cost3));
        int final_min_cost = min_cost + arr[current_row][current_column];
        return final_min_cost;
    }
}
int minCostPath(int **arr, int m, int n)
{
	//Write your code here
	int final_row = m - 1;
	int final_column = n - 1;
	return helper(arr,0,0,final_row,final_column);
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
	cout << minCostPath(arr, n, m) << endl;
}
