#include<stdio.h>
int main()
{
      int i,k,n,m,index=0;
      scanf("%d %d",&n,&m);
      int a[n][m];
      for(i=0;i<n;i++)
      {
            for(k=0;k<m;k++)
                scanf("%1d",&a[i][k]);
      }
            for(i=1;i<n;i++)
            {
                  for(k=0;k<m;k++)
                  {
                        if(a[i][k]>a[index][k])
                        {
                              index=i;
                              break;
                        }
                        else if(a[i][k]<a[index][k])
                             break;                 
                  }
            }
      printf("The index value is %d",index+1);
}
