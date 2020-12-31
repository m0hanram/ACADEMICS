#include<iostream>
using namespace std;

template <class T>
class Stack
{
    T *a;
    int top;
    int size;
public:
    Stack(int n);
    bool push(T);
    bool pop();
    bool IsEmpty();
    void display();
};

template <class T>
Stack<T>::Stack(int n)
{
    size=n;
    a=new T[size];
    top=-1;
}

template <class T>
bool Stack<T>::push(T element)
{
    if(top>=size)
    {
        cout<<"\nThe stack is full";
        return false;
    }
    else
    {
        cout<<"\nInserting "<<element<<" .";
        a[++top]=element;
        return true;
    }
}

template <class T>
bool Stack<T>::pop()
{
    if(top<=-1)
    {
        cout<<"\nThe stack is empty";
        return false;
    }
    else
    {
        cout<<"\nPoping "<<a[top--]<<" .";
        return true;
    }
}

template <class T>
bool Stack<T>::IsEmpty()
{
    return (top<0);
}

template <class T>
void Stack<T>::display()
{
    cout<<"\nThe elements in the stack are : ";
    for(int i=top;i>=0;i--)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n,choice;
    string cont="yes";
    string data_type;
    cout<<"\nEnter the size of the stack : ";
    cin>>n;
    cout<<"\nEnter your choice of data type ( int,float,char,string ): ";
    cin>>data_type;
    if(data_type == "int")
    {
        Stack<int> q(n);
        int e;
        while(cont=="yes" || cont=="Yes")
        {
            cout<<"\n\t\tMENU :";
            cout<<"\n1]Enter 1 to enter the elements into the stack \n2]Enter 2 to delete a element from the stack \n3] Enter 3 to display the elements from the stack";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<"\nenter the elements";
                        for(int i=0;i<n;i++)
                        {
                            cin>>e;
                            q.push(e);
                        }
                        break;
                case 2: q.pop();
                        break;
                case 3: q.display();
                        break;
                default: cout<<"\nEnter valid choice .";
            }
            cout<<"\nDo you want to continue ? (yes/no)";
            cin>>cont;
        }
    }
    else if(data_type == "float")
    {
        Stack<float> q(n);
        float e;
        while(cont=="yes" || cont=="Yes")
        {
            cout<<"\n\t\tMENU :";
            cout<<"\n1]Enter 1 to enter the elements into the stack \n2]Enter 2 to delete a element from the stack \n3] Enter 3 to display the elements from the stack";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<"\nenter the elements";
                        for(int i=0;i<n;i++)
                        {
                            cin>>e;
                            q.push(e);
                        }
                        break;
                case 2: q.pop();
                        break;
                case 3: q.display();
                        break;
                default: cout<<"\nEnter valid choice .";
            }
            cout<<"\nDo you want to continue ? (yes/no)";
            cin>>cont;
        }
    }
    else if(data_type == "char")
    {
        Stack<char> q(n);
        char e;
        while(cont=="yes" || cont=="Yes")
        {
            cout<<"\n\t\tMENU :";
            cout<<"\n1]Enter 1 to enter the elements into the stack \n2]Enter 2 to delete a element from the stack \n3] Enter 3 to display the elements from the stack";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<"\nenter the elements";
                        for(int i=0;i<n;i++)
                        {
                            cin>>e;
                            q.push(e);
                        }
                        break;
                case 2: q.pop();
                        break;
                case 3: q.display();
                        break;
                default: cout<<"\nEnter valid choice .";
            }
            cout<<"\nDo you want to continue ? (yes/no)";
            cin>>cont;
        }
        }
        else if(data_type == "string")
        {
            Stack<string> q(n);
            string e;
            while(cont=="yes" || cont=="Yes")
        {
            cout<<"\n\t\tMENU :";
            cout<<"\n1]Enter 1 to enter the elements into the stack \n2]Enter 2 to delete a element from the stack \n3] Enter 3 to display the elements from the stack";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<"\nenter the elements";
                        for(int i=0;i<n;i++)
                        {
                            cin>>e;
                            q.push(e);
                        }
                        break;
                case 2: q.pop();
                        break;
                case 3: q.display();
                        break;
                default: cout<<"\nEnter valid choice .";
            }
            cout<<"\nDo you want to continue ? (yes/no)";
            cin>>cont;
        }
    }
}
