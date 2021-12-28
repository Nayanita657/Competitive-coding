#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k) {
    // Write your code here
	if(k==0)
        return 1;
    else
    {
        double demo=pow(2,k);
        double result=1/demo;
        //double rounded = (int)(result * 100000.0)/100000.0;
        double final_result= result+geometricSum(k-1);
        return final_result;
    }
}




int main() {
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;   
}
