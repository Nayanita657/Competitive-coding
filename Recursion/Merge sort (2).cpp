#include <iostream>
using namespace std;

void merging(int part1[],int size1,int part2[],int size2,int input[])
{
    int k=0;
    int i=0;
    int j=0;
    while(i<size1 && j<size2)
    {
        if(part1[i]<part2[j])
        {
            input[k]=part1[i];
            k++;
            i++;
        }
        else
        {
            input[k]=part2[j];
            k++;
            j++;
        }
    }
    while(i<size1)
    {
            input[k]=part1[i];
            k++;
            i++;
    }
 	while(j<size2)
    {
            input[k]=part2[j];
            k++;
            j++;
    }
    
}

void mergeSort(int input[], int size){
    if(size<=1)
    {
        return;
    }
	// Write your code here
    int mid=size/2;
    //creating two subarray which will contain list1
    int part1[500];
    int part2[500];
    
    int size1=mid;
    int size2=size-mid;
    
    int i;
    for(i=0;i<size1;i++)
    {
        part1[i]=input[i];
    }
    int k=0;
    for(int j=mid;j<size;j++)
    {
        part2[k]=input[j];
        k++;
    }
    mergeSort(part1,size1);
    mergeSort(part2,size2);
    merging(part1,size1,part2,size2,input);
        
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}