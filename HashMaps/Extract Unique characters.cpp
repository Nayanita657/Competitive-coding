#include <unordered_map>
#include <iostream>
#include <string>
using namespace std;


string uniqueChar(string str) 
{
	string output;
    unordered_map<char,int> umap;
    
    for(int i = 0; i < str.length(); i++)
    {
        if(umap.find(str[i]) != umap.end())
        {
           continue;
        }
        else
        {
            char temp = str[i];
            output += temp; 
            umap[str[i]]++;
        }
    }
    return output;
}
int main() 
{
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
