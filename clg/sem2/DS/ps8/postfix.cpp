#include<iostream>
using namespace std;
class stack
{
    string postfix[10];
    int top;
public:
    stack();
    void push(char a);
    return pop();
    char in_postfix(char infix[10]);
};
stack::stack()
{
    top=-1;
    postfix="";
}
stack::push(char a)
{

}
in_postfix(char infix[10])
{
    int i,n;
    n=strlen(infix);
    for(i=0;i<n;i++)
    {
        if(isalphanum(infix[i]))
        {
           postfix+=infix[i];
        }
        else if(top
    }
}
