
#include<iostream>
using namespace std;
int main()
{
   int i,j,num,*arr;
   cout<<"Enter array size:";
   cin>>num;
   arr=new int[num];
   cout<<"Enter the array element:";
   for(int i=0;i<num;i++)
   {
      cin>>arr[i];
   }
   for(int i =0;i<num-1;i++)
   {
      int min=i;
      for(int j=i+1;j<num;j++)
      {
         if(arr[j] < arr[min])
         {
            min=j;
         }
      }
      if(min!=i)
      {
         int temp=arr[i];
         arr[i]=arr[min];
         arr[min]=temp;
      }
   }
   cout<<"The sorted array:";
   for(int i=0; i<num; i++)
   {
      cout<<arr[i]<<"\t";
   }
}

