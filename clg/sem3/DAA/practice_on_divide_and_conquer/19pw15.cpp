#include <iostream>
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

int sumofdigit(int n) 
{ 
    if (n == 0)  
       return 0; 
    return (n % 9 == 0) ? 9 : (n % 9); 
} 


int binarysearch(int a[],int left,int right,int x)
{
    if(right>=left)
    {
        int mid = left + (right-left)/2;
        if(a[mid] == x)
        {
            return mid;
        }
        if(x < a[mid])
        {
           return binarysearch(a,left,mid-1,x);
        }
        else
        {
           return binarysearch(a,mid+1,right,x);
        }
    }
    return -1;
}


int main()
{
    int n,k;
    cout<<"enter the value of n";
    cin>>n;
    cout<<"enter value of k";
    cin>>k;
    int a[n];
    int unchangeda[n];
    int b[n];
    int changedposition[n];
    cout<<"enter the array values";
    int temp1[n];
    int temp2[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        unchangeda[i]=a[i];
        b[i]=sumofdigit(a[i]);
    }
    mergesort(a,temp1,0,n-1);
    mergesort(b,temp2,0,n-1);
    cout<<"sorted array a";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"sorted array b";
    for(int i=0;i<n;i++)
    {
        cout<<b[i]<<" ";
    }
    for(int i=0;i<n;i++)
    {
        changedposition[i]=binarysearch(unchangeda,0,n-1,a[i]);
    }
    cout<<"changed positions of a";
    for(int i=0;i<n;i++)
    {
        cout<<changedposition[i]<<" ";
    }
    int min[k],max[k];
    for (int i = 0; i < k; i++)
    {
        min[i]=b[i];
    }
    int j=0;
    for (int i = k-1; i <n; i++)
    {
        max[j]=b[i];
        j++;
    }
    cout<<"the minimum array";
    for(int i=0;i<k;i++)
    {
        cout<<min[i]<<" ";
    }
    cout<<"the maxium array";
    for(int i=0;i<k;i++)
    {
        cout<<max[i]<<" ";
    }
}