#ifndef PARTICIPANT_H_INCLUDED
#define PARTICIPANT_H_INCLUDED
#include<iostream>
using namespace std;
class participant
{
    char *name;
public:
    void input_p()
    {
        name= new char[20];
        cout<<"enter the name";
        cin>>name;
    }
    void display_p()
    {
        cout<<"the participant name:"<<name;
    }
};



#endif // PARTICIPANT_H_INCLUDED
