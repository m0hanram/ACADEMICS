#include<iostream>
using namespace std;
class Meal
{
    int calorie;
    char* name;
public:
    Meal(int,char*);
    Meal();
    friend istream& operator >>(istream &in,Meal &);
    friend ostream& operator <<(ostream &out, Meal &obj);
    Meal operator +(Meal &obj);
};

