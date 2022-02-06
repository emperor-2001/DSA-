#include<bits/stdc++.h>
using namespace std;

class Graphs {
      


   int v;
   list<int>* l;
   vector<int> visited;
    
    public:

   Graphs(int V) 
   {
      v = V;
      l = new list<int>[v];
      for(int i = 0; i< v ;i++) visited.push_back(0);

   }   
   void addEdge(int x , int y , bool undir= true)
   {
       l[x].push_back(y);
        if(undir)
           l[y].push_back(x);
   }

//    void dfs(int source)
//    {
//     //    static int visited[v] = {0};
//        visited[source] = 1;
//        cout << source << " ";
//          for(auto node : l[source])
//              if(!visited[node])
//                  dfs(node);      
//    }

   //dfs second apaproach (better)
   void dfsHelper(int source , bool* visited )
   {
       visited[source] = 1;
       cout << source << " ";
        for(auto node : l[source])
           if(!visited[node])
                dfsHelper(node, visited);


   }
    void dfs (int source)
    {
      bool* visited = new bool[v]{0};
      dfsHelper(source,visited);
    }

};


int main()
{
    Graphs g(7);
    g.addEdge(1,2);
    g.addEdge(1,0);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,5);
    g.addEdge(0,4);
    g.addEdge(5,6);

    g.dfs(1);
}


