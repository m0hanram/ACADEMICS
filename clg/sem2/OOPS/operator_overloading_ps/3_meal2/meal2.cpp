#include<iostream>
#include "meal.h"
int main()
{
    Meal meal[21];
    Meal total(0,"total");
    int i;
    for(i=0;i<21;i++)
        cin>>meal[i];
    for(i=0;i<21;i++)
    {
        total=total+meal[i];
    }
    cout<<total;
}
