#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include<iostream>
#include<string.h>
using namespace std;
class Ship
{
public:
    char *name;
    int year;
    Ship()
    {
        *name='/0';
        year=0;
    }
    Ship(char* str,int yr)
    {
        name=new char[strlen(str)+1];
        strcpy(name,str);
        year=yr;
    }
    virtual void display()
    {
        cout<<"\nName:"<<name<<"\nYear:"<<year;
    }
};
class CruiseShip:public Ship
{
public:
    int max;
    CruiseShip(int a,char* n,int yr):Ship(n,yr)
    {
        max=a;
    }
    void display()
    {
        cout<<"\nName:"<<name<<"\nMax no. of passengers:"<<max;
    }
};
class CargoShip:public Ship
{
public:
    int capacity;
    CargoShip(int a,char* n,int yr):Ship(n,yr)
    {
        capacity=a;
    }
    void display()
    {
        cout<<"\nName:"<<name<<"\nThe capacity:"<<capacity;
    }
};

#endif // HEAD_H_INCLUDED
