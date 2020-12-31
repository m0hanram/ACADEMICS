#include<iostream>
using namespace std;

template <class T>
class Queue
{
    T *a;
    int front,rear;
    int size;
public:
    Queue(int);
    bool enqueue(T element);
    bool dequeue();
    void seefront();
    void seerear();
    void display();
};

template <class T>
Queue<T>::Queue(int n)
{
    size=n;
    a=new T[size];
    front=rear=0;
}

template<class T>
bool Queue<T>::enqueue(T element)
{
    if(rear>size)
    {
        cout<<"\nQueue is full";
        return false;
    }
    else
    {
        a[rear++]=element;
        cout<<"\ninserting "<<element<<" .\n";
        return true;
    }
}

template <class T>
bool Queue<T>::dequeue()
{
    if(front==rear)
    {
        cout<<"\nQueue is empty";
        return false;
    }
    else
    {
        cout<<"\ndeleting "<<a[front++]<<" .";
        return true;
    }
}

template <class T>
void Queue<T>::seefront()
{
    if(front==rear)
    {
        cout<<"\nfront = empty";
    }
    else
        cout<<"\nthe front = "<<a[front];
}

template <class T>
void Queue<T>::seerear()
{
    if(rear>=size)
    {
        cout<<"\nrear = empty";
    }
    else
        cout<<"\nthe rear = "<<a[rear];
}

template <class T>
void Queue<T>::display()
{
    cout<<"\nThe elements in the queue are : ";
    for(int i=front;i<size;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n,choice;
    string cont="yes";
    string data_type;
    cout<<"\nEnter the size of the queue : ";
    cin>>n;
    cout<<"\nEnter your choice of data type ( int,float,char,string ): ";
    cin>>data_type;
    if(data_type == "int")
    {
        Queue<int> q(n);
        int e;
        while(cont=="yes" || cont=="Yes")
        {
            cout<<"\n\t\tMENU :";
            cout<<"\n1]Enter 1 to enter the elements into the queue \n2]Enter 2 to delete a element from the queue \n3] Enter 3 to display the elements from the queue";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<"\nenter the elements";
                        for(int i=0;i<n;i++)
                        {
                            cin>>e;
                            q.enqueue(e);
                        }
                        break;
                case 2: q.dequeue();
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
        Queue<float> q(n);
        float e;
        while(cont=="yes" || cont=="Yes")
        {
            cout<<"\n\t\tMENU :";
            cout<<"\n1]Enter 1 to enter the elements into the queue \n2]Enter 2 to delete a element from the queue \n3] Enter 3 to display the elements from the queue";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<"\nenter the elements";
                        for(int i=0;i<n;i++)
                        {
                            cin>>e;
                            q.enqueue(e);
                        }
                        break;
                case 2: q.dequeue();
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
        Queue<char> q(n);
        char e;
        while(cont=="yes" || cont=="Yes")
        {
            cout<<"\n\t\tMENU :";
            cout<<"\n1]Enter 1 to enter the elements into the queue \n2]Enter 2 to delete a element from the queue \n3] Enter 3 to display the elements from the queue";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<"\nenter the elements";
                        for(int i=0;i<n;i++)
                        {
                            cin>>e;
                            q.enqueue(e);
                        }
                        break;
                case 2: q.dequeue();
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
            Queue<string> q(n);
            string e;
            while(cont=="yes" || cont=="Yes")
        {
            cout<<"\n\t\tMENU :";
            cout<<"\n1]Enter 1 to enter the elements into the queue \n2]Enter 2 to delete a element from the queue \n3] Enter 3 to display the elements from the queue";
            cin>>choice;

            switch(choice)
            {
                case 1: cout<<"\nenter the elements";
                        for(int i=0;i<n;i++)
                        {
                            cin>>e;
                            q.enqueue(e);
                        }
                        break;
                case 2: q.dequeue();
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
