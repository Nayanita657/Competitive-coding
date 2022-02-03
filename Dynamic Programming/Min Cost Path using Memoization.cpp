#include <bits/stdc++.h>
using namespace std;

int helper(int **arr,int current_row, int current_column, int final_row, int final_column, int **output)
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
        if(output[current_row][current_column] != -1)
        {
            return output[current_row][current_column];
        }
        int cost1 = helper(arr, current_row + 1, current_column , final_row, final_column, output);
        int cost2 = helper(arr, current_row, current_column + 1, final_row, final_column, output);
        int cost3 = helper(arr, current_row + 1, current_column + 1, final_row, final_column, output);
        int min_cost = min(cost1, min(cost2, cost3));
        int final_min_cost = min_cost + arr[current_row][current_column];
        output[current_row][current_column] = final_min_cost;
        return final_min_cost;
    }
}

int minCostPath_Mem(int **arr, int m, int n)
{
	//Write your code here
	int final_row = m - 1;
	int final_column = n - 1;
	int **output = new int*[m];
	for(int i = 0; i < m; i++)
	{
	    output[i] = new int[n];
	    for(int j = 0; j < n; j++ )
	    {
	        output[i][j] = -1;
	    }
	}
	return helper(arr,0,0,final_row,final_column,output);
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
	cout << minCostPath_Mem(arr, n, m) << endl;
}