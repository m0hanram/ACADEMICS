#include <iostream>
#include <cmath>
#include <limits.h>

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

int MinWidth(int colors[], int start, int minWidth, int size)
{
    int width = colors[start + 2] - colors[start];
    if (start + 2 == size)
        return minWidth;
    if (width == 2)
        return 2;
    if (width < minWidth)
        minWidth = width;
    return MinWidth(colors, start + 1, minWidth, size);
}

int main()
{
        int cost, n, index = 0;
        cin >> n;
        cin >> cost;
        int *arr = new int[n];
        while (index < n)
        {
            int val = 0;
            cin >> val;
            arr[index] = val;
            index++;
        }
        mergesort(arr, 0, n-1);

        int minWidth = MinWidth(arr, 0, INT_MAX, n);
        int minimumCost = 2 * cost * (minWidth + (arr[n - 1] - arr[0]));
        cout << minimumCost << endl;
    
}