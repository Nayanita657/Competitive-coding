#include <iostream>
using namespace std;
#include <unordered_map>


void printIntersection(int arr1[], int arr2[], int n, int m) {
    // Write your code here
    if(n == 0 || m == 0)
    {
        return;
    }
    unordered_map<int,int> umap1;
    unordered_map<int,int> umap2;
    for(int i = 0; i < n; i++)
    {
        umap1[arr1[i]]++;
    }
    for(int j = 0; j < m; j++)
    {
        umap2[arr2[j]]++;
    }
    unordered_map<int, int>:: iterator itr1;
    unordered_map<int, int>:: iterator itr2;
    for (itr1 = umap1.begin(); itr1 != umap1.end(); itr1++)
    {
        int element1 = itr1->first;
        int occur_map1 = itr1->second;
        if(umap2.count(element1) > 0)
        {
            //find the occuence of that element in umap2
            auto itr2 = umap2.find(element1);
            int occur_map2 = itr2->second;
            int occur = min(occur_map1,occur_map2);
            for(int i = 0; i < occur; i++)
            {
                cout<<element1<<endl;
            }
        }
           
    }
}

int main() {
    int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}