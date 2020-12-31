#ifndef PHONE_H_INCLUDED
#define PHONE_H_INCLUDED

#include<iostream>
using namespace std;
class Phone
{
    long long int ph;
    int mins;
    float rate;
public:
    friend istream &operator >>(istream &in,Phone &obj);
    friend ostream &operator <<(ostream &out,Phone &obj);
    bool operator ==(Phone &obj);
};

#endif // PHONE_H_INCLUDED
