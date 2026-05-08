   #include <iostream>
using namespace std;
int main()
{
   int n;
   cout<<"Enter number of vertices:";
   cin>>n;
   int D[n][n];
   cout<<"Enter weight matrix:";
   cout<<"Enter path(9999 for no path):";
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
         cin>>D[i][j];
   }
   for(int k=0;k<n;k++)
   {
      for(int i=0;i<n;i++)
      {
         for(int j=0;j<n;j++)
         {
            if(D[i][k]+D[k][j]<D[i][j])
               D[i][j]=D[i][k]+D[k][j];
         }
      }
   }
   cout<<"Shortest distance matrix:";
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<n;j++)
      {
         cout<<D[i][j]<<" ";
      }
      cout<<endl;
   }
   return 0;
}