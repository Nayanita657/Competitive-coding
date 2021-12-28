#include <iostream>
using namespace std;
int subset(int input[], int n, int output[][20]) 
{
   // base case
    if(n==0)
    {
        output[0][0]=0;
        return 1;
    }
 
    int s=subset(input+1,n-1,output);
 
    for(int i=0;i<s;i++)
    {
        output[i+s][0]=output[i][0]+1; //addimg one with the previous size
        output[i+s][1]=input[0]; //copying itself
        for(int j=1;j<=output[i][0];j++){
            output[i+s][j+1]=output[i][j]; //copying the previous content
        }
 
    }
    return 2*s;
    

}

void printSubsetsOfArray(int input[], int size) 
{
	int output[35000][20];
	
	int length = subset(input, size, output);

    for( int i = 0; i < length; i++) 
    { 
	    for( int j = 1; j <= output[i][0]; j++) 
	    { 
		    cout << output[i][j] << " ";
        }
        cout<<"\n";
    }    
    
}


int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
