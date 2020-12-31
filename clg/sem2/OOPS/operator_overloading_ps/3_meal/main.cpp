#include <iostream>
#include "meal.h"
using namespace std;

int main()
{
    Meal breakfast, dinner(20,"chapati"),lunch,total;
    cout<<"\nenter the dish and calorie you had for breakfast:";
    cin>>breakfast;
    cout<<"\nenter the dish and calorie you had for lunch:";
    cin>>dinner;
    total=breakfast+dinner+lunch;
    cout<<total;
}
