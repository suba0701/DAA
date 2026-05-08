#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int n,i,j,x[n],y[n];
   double min =9999.0;
   cout<<"Enter size:";
   cin>>n;
   for(int i=0; i<n; i++)
   {
      cout<<"Enter x and y points:"<<i+1;
      cin>>x[i];
      cin>>y[i];
   }

   for(int i=0; i<n; i++)
   {
      for(int j=i+1;j<n; j++)
      {
         double d=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
         cout << "Distance between point " << i + 1 << " and point " << j + 1 << ": " << d << endl;
         if(d<min)
         {
            min=d;
         }
      }
   }
   cout<<"MINIMUN DISTANCE IS:"<<min;
}

