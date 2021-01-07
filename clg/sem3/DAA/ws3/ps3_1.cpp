#include <iostream>
#include <list>
using namespace std;

class graph
{
public:
    int v;
    list<int> *l;
    graph(int);
    void add_Edge(int ,int );
    void BFS_traversal(int );
    void DFS_traversal(int );
    void dfs(int ,bool *);
    void find_ajd_node(int );
    int *vertices(int *);
    void find_vertex(int );
    void sum_vertices();
    bool find_path(int ,int );
};

graph::graph(int v)
{
    this->v=v;
    l =new list<int>[v];
}

void graph::add_Edge(int a,int b)
{
    l[a].push_back(b);
    l[b].push_back(a);
}

void graph::BFS_traversal(int s)
{
    cout<<"\n The BFS traversal : ";
    list<int> q[v];
    bool visit[v];
    for (int j = 0; j < v; j++)
    {
        visit[j] = false;
    }
    

    q->push_back(s);
    visit[s] = true;

    list<int>::iterator i;
    
    while (!q->empty())
    {
        s = q->front();
        cout<<s<<" ";
        visit[s] = true;
        q->pop_front();

        for (i = l[s].begin(); i != l[s].end() ; i++)
        {
            if(!visit[*i])
            {
                visit[*i] = true;
                q->push_back(*i);
            }
        }
    }
}

void graph::DFS_traversal(int s)
{
    bool *visit;
    visit = new bool[v];
    for (int i = 0; i < v; i++)
    {
        visit[i] = false;
    }

    cout<<"\nThe DFS traversal is : ";
    dfs(s,visit);
}

void graph::dfs(int s,bool *visit)
{
    visit[s] = true;
    cout<<s<<" ";

    list<int>::iterator i;
    for ( i = l[s].begin(); i != l[s].end(); i++)
    {
        if(!visit[*i])
        {
            dfs(*i,visit);
        }
    }
    
}

void graph::find_ajd_node(int s)
{
    cout<<"\n The adjacent node are : ";
    list<int>::iterator i;

    for(i=l[s].begin() ; i != l[s].end() ; i++)
    {
        cout<<*i<<" ";
    }
}

int *graph::vertices(int vert[])
{
    vert = new int[v];
    for (int i = 0; i < v; i++)
    {
        vert[i] = 0;
    }
    
    list<int>::iterator i;

    for( int j=0;j<v;j++)
    {
        for(i=l[j].begin() ; i != l[j].end() ; i++)
        {
            vert[j]++;
        }
    }

    return vert;    
}

void graph::find_vertex(int d)
{
    int *vert;
    vert = vertices(vert);
    cout<<"\n the vertices with degree "<<d<<" is : ";
    for (int i = 0; i < v; i++)
    {
        if(vert[i] == d)
            cout<<i<<" ";
    }
    
}

void graph::sum_vertices()
{
    int *vert;
    int sum=0;
    vert = vertices(vert);
    for (int i = 0; i < v; i++)
    {
        sum += vert[i];
    }
    cout<<"\nThe sum of degree of all vertices is : "<<sum;
}

bool graph::find_path(int a,int b)
{
     if (a == b) 
        return true; 
  
    bool* visited = new bool[v]; 
    for (int i = 0; i < v; i++) 
        visited[i] = false; 
   
    list<int> q; 
  
    visited[a] = true; 
    q.push_back(a); 
  
    list<int>::iterator i; 
  
    while (!q.empty()) 
    { 
        a = q.front(); 
        q.pop_front(); 
        
        for (i = l[a].begin(); i != l[a].end(); ++i) 
        { 
            if (*i == b) 
                return true; 
  
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                q.push_back(*i); 
            } 
        } 
    } 
   
    return false; 
}

int main()
{
    graph g(6);
    int *v;

    g.add_Edge(0 , 1);
    g.add_Edge(0 , 2);
    g.add_Edge(0 , 3); 
    g.add_Edge(1 , 4); 
    g.add_Edge(2 , 3);  
    g.add_Edge(1 , 2); 
    g.add_Edge(4 , 5);
    
    g.find_ajd_node(0);
    g.BFS_traversal(3);
    g.DFS_traversal(0);
    g.find_vertex(2);
    g.sum_vertices();
    if(g.find_path(0,5))
    {
        cout<<"\n Yes there is a path between";
    }
    else
    {
        cout<<"\n No there is no path between";
    }
    
}