#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include<iostream>
#include"participant.h"
#include"date.h"
using namespace std;
class event
{
    int event_no;
    participant p;
    date d;
public:
    void input_e();
    void display_e();
};
#endif
