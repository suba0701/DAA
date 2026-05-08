#include<iostream>
using namespace std;
int main()
{
   int n;
   cout<<"Enter no of elements:";
   cin>>n;
   int A[n];
   int temp;
   cout<<"Enter element:";
   for (int i=0; i<n;i++)
   {
      cin>>A[i];
   }
   for(int i=0; i<=n-2; i++)
   {
      bool flag=false;
      for(int j=0; j<=n-2-i; j++)
      {
         if(A[j]>A[j+1])
         {
            temp=A[j];
            A[j]=A[j+1];
            A[j+1]=temp;
            flag=true;
         }
      }
      if(!flag)
      {
         break;
      }
   }
   cout<<"SORTED ARRAY\n";
   for(int i=0; i<n; i++)
   {
      cout<<A[i]<<" ";
   }
   return 0;
}
