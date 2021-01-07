#include <iostream>
using namespace std;

int mergeSort(int a[],int temp[],int left,int right);
int merge(int a[],int temp[],int mid,int left,int right);

int findInverse(int a[],int n)
{
    int temp[n];
    return mergeSort(a,temp,0,n-1);
}

int mergeSort(int a[],int temp[],int left,int right)
{
    int mid,inverse=0;
    if(right>left)
    {
        mid= (right+left)/2;

        inverse += mergeSort(a,temp,left,mid);
        inverse += mergeSort(a,temp,mid+1,right);
 
        inverse += merge(a,temp,mid+1,left,right);
    }
    return inverse;
}

int merge(int a[],int temp[],int mid,int left,int right)
{
    int inverse=0;
    int i = left;
    int j = mid;
    int k = left;

    while(i<=mid-1 && j<=right)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
            inverse = inverse + (mid-i);    
        }
    } 

    while(i <= mid-1)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while(j <= right)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    for( i = left; i <= right; i++)
    {
        a[i] = temp [i];
    }
    
    return inverse;
}

int main()
{
    int n;
    cout<<"\n Enter the size of array : ";
    cin>>n;
    int a[n];
    cout<<"\n Enter the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int inv = findInverse(a,n);

    cout<<"\n the no. of inverse : "<<inv;
    return 0;
}