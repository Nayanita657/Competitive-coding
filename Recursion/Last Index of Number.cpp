#include<iostream>
using namespace std;

int lastIndex(int input[], int size, int x) 
{
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */
   if(size<1)
   {
       return -1;
   }
    else
    {
        if(input[size-1]==x)
        {
            return size-1;
        }
        else
        {
            int result=lastIndex(input,size-1,x);
            return result;
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
    
    cout << lastIndex(input, n, x) << endl;

}


