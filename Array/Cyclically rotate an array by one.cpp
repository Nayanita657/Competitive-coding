#include <iostream>
using namespace std;

void rvereseArray(int *input, int start, int end)
{
    while (start < end)
    {
        int temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
}    


void rotate(int *input, int n)
{
    rvereseArray(arr,0,n-1);
    rvereseArray(arr+1,0,n-2);
    
    
}    

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}


		rotate(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}