#include <iostream>
#include  "head.h"
using namespace std;

int main()
{
    Ship *s;
    CruiseShip cruise(200,"SHIP1",5);
    CargoShip cargo(30,"SHIP2",10);
    s=&cruise;
    s->display();
}
