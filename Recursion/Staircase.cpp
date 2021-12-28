#include <iostream>
using namespace std;
int staircase(int n){
   
    //base case
    if(n==1)
        return 1;
    if(n==0)
        return 1;
    if(n<0)
        return 0;
    
    int x = staircase(n-1);
    int y = staircase(n-2);
    int z = staircase(n-3);
    int result = x + y + z;
    return result;    
}

int main() {
    int n, output;
    cin >> n;
    output=staircase(n);
    cout<< output <<endl;
}
