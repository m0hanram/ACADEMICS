#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unsigned int numberoffives(unsigned int n);

int min(int cur, int sum, int r);

int main()
{
    int r;
    cout << "Please enter the value: ";
    cin >> r;
    int x = min(1, 0, r);
    cout << "The minimum number is " << x << endl;
}

unsigned int numberoffives(unsigned int n)
{
    if((n%5)==0)
    {
        return 1 + numberoffives(n/5); 
    }
    else
    {
        return 0;
    } 
}


int min(int cur, int sum, int r)
{
    if (sum >= r)
    {
        return cur - 1;
    }
    else
    {
        sum = numberoffives(cur) + sum;
        return min(cur+1,sum,r);
    }
}