#include<iostream>
using namespace std;

int main()
{
    int N,sum=0;
    cout<<"\nEnter the number of vertices :";
    cin>>N;
    int degree[N];
    cout<<"\nEnter the degree of the vertices :";
    for(int i=0;i<N;i++)
    {
        cin>>degree[i];
        sum +=degree[i];
    }
    if((sum%2)==0)
    {
        if((sum/2) == (N-1))
        {
            cout<<"\nYes";
        }
        else
        {
            cout<<"\nNo";
        }
    }
    else
    {
        cout<<"\nNot possible";
    }
}   