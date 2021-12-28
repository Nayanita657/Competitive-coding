#include<iostream>
using namespace std;

int output_size=0;
int input_index=0;
int output_index=0;


int allIndexes(int input[], int size, int x, int output[]) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Save all the indexes in the output array passed and return the size of output array.
     Taking input and printing output is handled automatically.
  */
   if(size==0)
   {
       return output_size;
   }
    else
    {
        
        if(input[input_index]==x)
        {
            output_size++;
            output[output_index]=input_index;
            input_index++;
            output_index++;
            return allIndexes(input,size-1,x,output);
        }
        else
        {
            input_index++;
            return allIndexes(input,size-1,x,output);
        }
    }
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}


