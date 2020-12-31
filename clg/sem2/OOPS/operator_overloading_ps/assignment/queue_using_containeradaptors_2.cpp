#include<iostream>
#include<queue>
using namespace std;
void showq(priority_queue<int,vector<int>,greater<int> > q)
{
    priority_queue<int,vector<int>,greater<int> > g=q;
    while(!g.empty())
    {
        cout<<'\t'<<g.top();
        g.pop();
    }
    cout<<'\n';
}

int main()
{
    priority_queue<int,vector<int>,greater<int> > q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout<<"\nsize : "<<q.size();
    cout<<"\ntop : "<<q.top();
    cout<<"\nthe queue :";
    showq(q);
    return 0;
}
