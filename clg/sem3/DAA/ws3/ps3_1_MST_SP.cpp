#include<iostream>
#include<list>
#include<set>
#include<algorithm>
using namespace std;

typedef struct Node
{
    int dest;
    int weight;
}node;

class Graph
{
public:
    int n;
    list<node> *l;
    Graph();
    Graph(int no_of_nodes);
    void addedge(int src,int dest,int weight);
    void display();
    void viewlist(int src,list<node> l);
};

Graph::Graph()
{
    n=0;
}

Graph::Graph(int no_of_nodes)
{
    n = no_of_nodes;
    l = new list<node>[n];
}

void Graph::addedge(int src,int dest,int weight)
{
    node newnode;
    newnode.dest = dest;
    newnode.weight = weight;
    l[src].push_back(newnode);
}

void Graph::viewlist(int src,list<node> l)
{
    list<node>::iterator i;
    node temp;
    for(i = l.begin();i!=l.end();i++)
    {
        temp = *i;
        cout<<src<<"--("<<temp.dest<<","<<temp.weight<<") ";
    }
    cout<<endl;
}

void Graph::display()
{
    for (int j = 0; j < n; j++)
    {
        list<node> templ = l[j];
        viewlist(j, templ);         
    }
}

set<int> difference(set<int> s1,set<int> s2)
{
    set<int>::iterator i;
    set<int> diff;
    for(i=s1.begin();i!=s1.end();i++)
    {
        if(s2.find(*i) == s2.end())
        {
            diff.insert(*i);
        }
    }
    return diff;
}

Graph MST(Graph g, int s)
{
    int n = g.n;
    set<int> s1,s2,diff;
    Graph Tree(n);
    s1.insert(s);
    for(int u=0;u<n;u++)
    {
        s2.insert(u);
    }
    
    while (s1!=s2)
    {
        int inf = 1000;
        int v_MST1,v_MST2;
        diff = difference(s2,s1);
        for(int u=0;u<n;u++)
        {
            if(s1.find(u) != s1.end())
            {
                list<node>::iterator i;
                for(i = g.l[u].begin() ; i != g.l[u].end() ; i++)
                {
                    if(diff.find(i->dest) != diff.end())
                    {
                        if(inf > i->weight)
                        {
                            inf = i->weight;
                            v_MST2 = u;
                            v_MST1 = i->dest;
                        }
                    }
                }
            }
        }
        s1.insert(v_MST1);
        Tree.addedge(v_MST2,v_MST1,inf);
        Tree.addedge(v_MST1,v_MST2,inf);
    }
    return Tree;    
}

void shortestPath(Graph g,int *distance,int s)
{
    int n=g.n;
    int infinity = 1000;
    for(int u=0;u<n;u++)
    {
        distance[u] = infinity;
    }

    distance[s] = 0;
    list<int> q;

    for(int u=0;u<n;u++)
    {
        q.push_back(u);
    }

    while (!q.empty())
    {
        list<int>::iterator i;
        i = min_element(q.begin(),q.end());
        int u = *i;
        q.remove(u);
        list<node>::iterator j;
        
        for(j=g.l[u].begin();j!=g.l[u].end();j++)
        {
            if((distance[u]+(j->weight)) < distance[j->dest])
            {
                distance[j->dest] = (distance[u]+(j->weight));
            }
        }
    }   
}

int main()
{
    Graph g(7),minimumspanningtree(7);
    int distance[7];
    int s=0;
    g.addedge(0, 1, 1);
    g.addedge(0, 2, 3);
    g.addedge(0, 3, 4);
    g.addedge(0, 5, 5);
    g.addedge(1, 0, 1);
    g.addedge(1, 3, 7);
    g.addedge(1, 4, 2);
    g.addedge(2, 0, 3);
    g.addedge(2, 4, 8);
    g.addedge(3, 0, 4);
    g.addedge(3, 1, 7);
    g.addedge(4, 1, 2);
    g.addedge(4, 2, 8);
    g.addedge(4, 5, 2);
    g.addedge(4, 6, 4);
    g.addedge(5, 0, 5);
    g.addedge(5, 4, 2);
    g.addedge(5, 6, 3);
    g.addedge(6, 4, 4);
    g.addedge(6, 5, 3);

    g.display();
    cout<<endl<<endl;
    minimumspanningtree = MST(g,0);
    minimumspanningtree.display();
    cout<<endl<<endl;
    shortestPath(g,distance,s);

    for(int i=0;i<7;i++)
    {
        if(i != s)
        {
            cout<<s<<"--"<<i<<"  "<<distance[i]<<endl;
        }
    }
}
