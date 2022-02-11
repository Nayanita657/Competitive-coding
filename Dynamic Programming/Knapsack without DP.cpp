#include <iostream>
using namespace std;
int helper(int *weights, int *values, int n, int maxWeight, int output)
{
    if(maxWeight <= 0 || n == 0)
    {
        return output;
    }
    else
    {
        int curr_weight = weights[0];
        //including the weight in the knapsack
    	int value1, value2;
        int rem_weight = maxWeight - weights[0];
        if(rem_weight > 0)
        	value1 = helper(weights + 1, values + 1, n - 1, maxWeight - weights[0], output + values[0]);
        if(rem_weight < 0)
            value1 = output;
        if(rem_weight == 0)
            value1 = output + values[0]; 
        //excluding the weight from the knapsack
        value2 = helper(weights + 1, values + 1, n - 1, maxWeight, output);
        
        return max(value1, value2);
    }
}


int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
    return helper(weights, values, n, maxWeight, 0);
}

int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}