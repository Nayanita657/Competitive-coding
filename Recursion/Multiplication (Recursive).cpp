#include <iostream>
#include "solution.h"
using namespace std;
int multiplyNumbers(int m, int n) {
    // Write your code here
    if(m==1 || n==0)
        return 0;
    else
    {
        int result=m+multiplyNumbers(m,n-1);
        return result;
    }

}
int main() {
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
}
