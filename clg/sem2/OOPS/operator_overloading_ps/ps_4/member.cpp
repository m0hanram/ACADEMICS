#include<iostream>
#include "phone.h"
istream& operator >>(istream &in,Phone &obj)
{
    cout<<"\nEnter the phone number:";
    in>>obj.ph;
    cout<<"\nEnter the mins";
    in>>obj.mins;
    cout<<"\nEnter the rate:";
    in>>obj.rate;
}
ostream& operator <<(ostream &out,Phone &obj)
{
    cout<<"\nPhone number:";
    out<<obj.ph<<" ";
    out<<obj.mins<<" ";
    out<<obj.rate<<" ";
}
bool Phone::operator ==(Phone &obj)
    {
        if(ph == obj.ph)
            return true;
        else
            return false;
    }
