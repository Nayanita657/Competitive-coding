#include <cstring>
#include <iostream>
using namespace std;
#include <bits/stdc++.h>
int editDistance(string s1, string s2) 
{
	// Write your code here
    if(s1.size() == 0 && s2.size() == 0)
    {
        return 0;
    }
    if(s1.size() == 0 && s2.size() != 0)
    {
        //only deletion is possible from 2nd string
        int no_operation = s2.size();
        return no_operation;
    }
    if(s1.size() != 0 && s2.size() == 0)
    {
        //only insertion is possible from 2nd string
        int no_operation = s1.size();
        return no_operation;
    }
    else
    {
        if(s1[0] == s2[0])
        {
            return editDistance(s1.substr(1) , s2.substr(1));
        }
        else
        {
            //insertion 
            int cost1 = 0;
            int cost2 = 0;
            int cost3 = 0;
            cost1 = 1 + editDistance(s1.substr(1) ,s2);
            //deletion
            cost2 = 1 + editDistance(s1 , s2.substr(1));
            //updation
            cost3 = 1 + editDistance(s1.substr(1) , s2.substr(1));
            
            return min(cost1 , min(cost2 , cost3));
        }
    }
}

int main() {
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}