#include <iostream>
using namespace std;
int subsetSumToK(int input[], int n, int output[][50], int k) {
    // Write your code here

     if(n == 0){
         
         if(k == 0){
              
             output[0][0] = 0;
            return 1;
         }else{
             return 0;
         }
     }
    
    int o1[1000][50];
    int o2[1000][50];
    
   int ans1 =  subsetSumToK(input + 1 , n - 1 , o1 , k);
    //int ans2 = 0;
  
   int ans2 =  subsetSumToK(input + 1 , n - 1 , o2 , k - input[0]);

    for(int i = 0 ; i < ans2 ; i++){
        
        output[i][0] = o2[i][0] + 1;
        output[i][1] = input[0];
        for(int j = 2; j <= o2[i][0]+1 ; j++){
            
            output[i][j] = o2[i][j-1];
        }
    }
    for(int i = 0 ; i < ans1 ; i++){
        
        for(int j = 0 ; j  <= o1[i][0] ; j++){
            
            output[i + ans2][j] = o1[i][j];
        }
    }
    return ans1 + ans2;
}
int main() {
  int input[20],length, output[10000][50], k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];

  cin >> k;
  
  int size = subsetSumToK(input, length, output, k);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}
