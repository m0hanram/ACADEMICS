#include<iostream>
#include<queue>
using namespace std;
void showq(queue<int> q)
{
    queue<int> g=q;
    while(1)
    {
        cout<<'\t'<<g.front();
        g.pop();
    }
    cout<<'\n';
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"\nq.size() : "<<q.size();
    cout<<"\nq.front() : "<<q.front();
    cout<<"\nq.back() : "<<q.back(); 
    cout <<"The queue q is : ";
    showq(q);

    return 0;
}
