#include<iostream>
#include<list>
using namespace std;

class Graph
{
public:
    int v;
    list<int> *l;
    int *pre;
    Graph(int);
    void BFS(int );
    void add_Edge(int ,int );
};

Graph::Graph(int v)
{
    this->v = v;
    l = new list<int>[v];
    pre = new int[v];
}

void Graph::add_Edge(int u,int v)
{
    l[u].push_back(v);
    l[v].push_back(u);
}

void Graph::BFS(int s)
{
    list<int> q[v];
    bool visit[v];
    for(int i=0;i<v;i++)
    {
        visit[i]=false;
    }

    q->push_back(s);
    visit[s]=true;
    list<int>::iterator i;
    pre[s] = -1;

    while (!q->empty())
    {
        s = q->front();
        q->pop_front();
        visit[s]=true;

        for ( i = l[s].begin(); i != l[s].end(); i++)
        {
            if (!visit[*i])
            {
                visit[*i] = true;
                q->push_back(*i);
                pre[*i] = s;
            }
            
        }
        
    }
    
}

int main()
{
    int N,M,C,T,U,V,X,Y;
    cout<<"Enter the N,M,C,T";
    cin>>N>>M>>C>>T;
    Graph g(N);
    cout<<"Enter the edges :";
    for(int i=0;i<M;i++)
    {
        cin>>U>>V;
        g.add_Edge(U-1,V-1);
    }
    cout<<"Enter the starting and ending points :";
    cin>>X>>Y;
    if(X==Y)
    {
        cout<<"0"<<endl<<X;
    }
    else
    {
        g.BFS(X-1);
        int i=Y-1,a[100],count=0,temp;
        while (true)
        {
            a[count] = g.pre[i];
            count++;
            if(g.pre[i] == (X-1))
            {
                break;
            }
            temp = g.pre[i];
            i = temp;
        }
        cout<<count + 1<<endl;
        for(int j=count-1;j>=0;j--)
        {
            cout<<a[j]+1<<" ";
        }
        cout<<Y<<endl;
    }
    
}