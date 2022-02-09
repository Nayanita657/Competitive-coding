#include <iostream>
#include <cstring>
using namespace std;

int editDistance(string s1, string s2)
{
	//Write your code here
    int m = s1.size();
    int n = s2.size();
    int **output = new int*[m + 1];
    for(int j = 0; j <= m; j++)
    {
        output[j] = new int[n + 1]; 
    }
    for(int i = 0; i<= n; i++)
    {
        output[0][i] = i; //filling the first row with size of string 
    }
    for(int j = 0; j <= m; j++)
    {
        output[j][0] = j; //filling the first column with size of string
    }
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            //checking if the first character of string is equal or not
            if(s1[m - i] == s2[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j] + 1;
                int b = output[i][j - 1] + 1;
                int c = output[i - 1][j - 1] + 1;
                output[i][j] = min(a , min(b , c));
            }
            
        }
    }
    return output[m][n];
    
}

int main()
{
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}