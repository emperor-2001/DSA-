#include<bits/stdc++.h>

class Graphs
{
    int v;
    list<int>* l;

    Graphs(int V)
    {
        v = V;
        l = new list<int>[v];
    }

    void addEdges(int x,int y, bool undir = true)
    {
        l[x].push_back(y);
          if(undir)
            l[y].push_back(x);
    }
     void dfsHelper(int source , bool* visited ,int& c,unordered_map<int,int>& m1)
   {

       visited[source] = 1;
       m1[source] = 1;
       c++;
       cout << source << " ";
        for(auto node : l[source])
           if(!visited[node])
                dfsHelper(node, visited);

   }
    void dfs (int source, unordered_map<int,int>& m1)
    {

      bool* visited = new bool[v]{0};
      int c = 0;
      dfsHelper(source,visited, c , m1);

    }

};

int main()
{
    int n , x;
    graphs g(n);
    unordered_map<int,int> m1;
    for(int i = 0 ;i< n ;i++)
     m1[i] = 1;

    int a, b;
    for(int i = 0 ; i < x ; i++)
    {
        cin >> a >> b;
        g.addEdge(a,b);
    }
    priority_queue<int> p1;
    for(auto it = m1.begin() ; it!= m1.end() ;it++)
      {
            if(it->second == 1)
            continue;

            else
            pq.push(g.dfs(it->first,m1));
      }

      int h1 = p1.top();
      p1.pop();
      int h2 = p1.top();
      return h1*h2;


}