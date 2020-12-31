#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<iostream>
using namespace std;
class date
{
    int day;
    int month;
    int year;
public:
    void input()
    {
        cout<<"enter input for date";
        cin>>day>>month>>year;
    }
    void display()
    {
        cout<<"date"<<"month"<<"year"<<day<<month<<year;
    }
};

#endif // DATE_H_INCLUDED
