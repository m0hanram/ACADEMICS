#include <iostream>
using namespace std;

void merge(int a[],int left,int right, int mid);

void mergesort(int a[],int left,int right)
{
    if(left < right)
    {
        int mid=(left+right)/2;
        
        mergesort(a,left,mid);
        mergesort(a,mid+1,right);

        merge(a,left,right,mid);
    }
}

void merge(int a[],int left,int right,int mid)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1],r[n2];
    for (int i = 0; i < n1; i++)
    {
        l[i] = a[left+i];
    }

    for (int j = 0; j < n2; j++)
    {
        r[j] = a[mid+1+j];
    }
    
    int i=0;
    int j=0;
    int k=left;

    while (i<n1 && j<n2)
    {
        if(l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    while (i<n1)
    {
        a[k] = l[i];
        k++;
        i++;
    }

    while (j<n2)
    {
        a[k] = r[j];
        k++;
        j++;
    }
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
    int n;
    cout<<"\nEnter n : ";
    cin>>n;
    int a[n];
    int x;
    cout<<"\nEnter x : ";
    cin>>x;
    cout<<"\nEnter the array : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    cout<<"\nThe array is : ";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    int position;
    position = binarysearch(a,0,n-1,x);
    int nextelement=0;
    int z=0;
    if(position == -1)
    {
        cout<<"\n the element x was not found";
    }
    else
    {
        while (nextelement!=-1)
        {
            nextelement = binarysearch(a,0,n-1,++x);
            z = x;
        }
        cout<<"\n The value of z : "<<z;
    }   
}