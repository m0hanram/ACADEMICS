#include <iostream>
#include <string.h>
#include "meal.h"
Meal::Meal()
{
    calorie=10;
    name=new char[5];
    strcpy(name,"idly");
}
Meal::Meal(int c,char* n)
{
    calorie=c;
    name=new char[strlen(n)+1];
    strcpy(name,n);
}
istream& operator >>(istream &in,Meal &obj)
{
    in.ignore();
    in>>obj.name;
    in>>obj.calorie;
    return in;
}
ostream& operator <<(ostream &out,Meal &obj)
{
    cout<<"\ncalorie:";
    out<<obj.calorie;
    cout<<"/nname:";
    out<<obj.name;
    return out;
}
Meal Meal::operator +(Meal& obj)
{
    return {calorie+obj.calorie,"TOT"};
}
