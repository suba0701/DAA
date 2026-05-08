
#include<iostream>
using namespace std;
void insertionsort(int A[], int n)
{
   for(int i=1; i<n; i++)
   {
      int v=A[i];
      int j=i-1;
      while(j>=0 && A[j]>v)
      {
         A[j+1]=A[j];
         j=j-1;
      }
      A[j+1]=v;
   }
}
int main()
{
   int n;
   cout<<"Enter no of element:";
   cin>>n;
   int A[n];
   cout<<"Enter element:";
   for(int i=0; i<n; i++)
      cin>>A[i];
   insertionsort(A,n);
   cout<<"Sorted array:";
   for(int i=0; i<n; i++)
      cout<<A[i]<<" ";
   return 0;
}
