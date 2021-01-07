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

int main()
{
    int n;
    cout<<"\nEnter n : ";
    cin>>n;
    int a[n];
    int k;
    cout<<"\nEnter k : ";
    cin>>k;
    cout<<"\nEnter the sequence : ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergesort(a,0,n-1);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
    for(int i=0;i<n-k;i++)
    {
        sum +=a[i];
    }
    cout<<"\nThe speciality of the sequence is : "<<sum;
}