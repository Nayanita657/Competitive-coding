#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

string Getstring(int Num)
{
    string result;
    switch(Num)
    {
        case 0:
            result= "";
            break;
        case 1:
            result= "";
            break;
        case 2:
            result= "abc";
            break;
        case 3:
            result= "def";
            break;
        case 4:
            result= "ghi";
            break;
        case 5:
            result= "jkl";
            break;
        case 6:
            result= "mno";
            break;
        case 7:
            result= "pqrs";
            break;
        case 8:
            result= "tuv";
            break;
        case 9:
            result= "wxyz";
            break;    
    }
    return result;
}

int keypad(int num, string output[]){
   //base condition
   if(num==0)
   {
       output[0]="";
       return 1;
   }
   else
   {
       int temp1=num/10;
       int temp2=num%10;
       string input_temp1=Getstring(temp1); 
       string input_temp2=Getstring(temp2);
       int count1=keypad(temp1,output);
       int No_of_copy=input_temp2.length()-1;
       int j=count1;
       for(int i=1;i<=No_of_copy;i++)
       {
           for(int k=0;k<count1;k++)
           {
               output[j]=output[k]+input_temp2[i];
               j++;
           }
       }
       for(int i=0;i<count1;i++)
       {
           output[i]=output[i]+input_temp2[0];
       }
       int output_size=input_temp2.length() * count1;
       return output_size;
    
   }
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
