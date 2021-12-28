#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    // Write your code here
    if(n==0)
    {
        return 0;
    }
    else
    {
        int rem=n%10;
        int quo=n/10;
        return rem+sumOfDigits(quo);
    }

}




int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n) << endl;
}
