#include<iostream>
using namespace std;

void merge(int a[],int temp[],int left,int mid,int right);

void mergesort(int a[],int temp[],int left,int right)
{
   int mid;
   if(right>left)
   {
       mid=(left+right)/2;

       mergesort(a,temp,left,mid);
       mergesort(a,temp,mid+1,right);

       merge(a,temp,left,mid+1,right);
   }
}

void merge(int a[],int temp[],int left,int mid,int right)
{
    int i=left;
    int j=mid;
    int k=left;

    while(i<=mid-1 && j<=right)
    {
        if(a[i]<=a[j])
        {
            temp[k]=a[i];
            k++;
            i++;
        }
        else
        {
            temp[k]=a[j];
            k++;
            j++;
        }
    }

    while (i<=mid-1)
    {
        temp[k]=a[i];
        k++;
        i++;
    }

    while (j<=mid)
    {
        temp[k]=a[j];
        k++;
        j++;       
    }  

    for(int i=0;i<=right;i++)
    {
        a[i]=temp[i];
    }  
}

int main()
{
    int n;
    cout<<"enter the value of n";
    cin>>n;
    int a[n];
    int temp[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,temp,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}