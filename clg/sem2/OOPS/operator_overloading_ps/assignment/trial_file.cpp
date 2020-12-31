#include<iostream>
using namespace std;

int main()
{
    int a[2];
    int f=0;
    int r=0;
    a[f++]=10;
    a[++r]=20;
    cout<<a[1];
    cout<<a[0];
    return 0;
}
