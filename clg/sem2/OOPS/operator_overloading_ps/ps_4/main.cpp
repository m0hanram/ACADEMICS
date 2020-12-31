#include <iostream>
#include "phone.h"
using namespace std;

int main()
{
   Phone p[10];
   cout<<"\nenther the inputs:";
   for(int i=0;i<10;i++)
   {
        cin>>p[i];
        for(int j=0;j<i;j++)
        {
            if(p[i]==p[j])
            {
                cout<<"not valid enter again";
                cin>>p[i];
            }
        }
   }
        for(int k=0;k<10;k++)
        {
            cout<<p[k];
        }
}
