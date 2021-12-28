#include <iostream>
using namespace std;


int countZeros(int n) {
    // Write your code here
    if(n<10)
    {
        if(n==0)
            return 1;
        else 
            return 0;
    }
	else
    {
        int rem=n%10;
        int quo=n/10;
        if(rem==0)
        {
            return 1+countZeros(quo);
        }
        else
            return countZeros(quo);
    }
}




int main() {
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
}
