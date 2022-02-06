#include <bits/stdc++.h>
using namespace std;
class Graphs
{
public:
    int v;
    list<int> *l;

    Graphs(int V)
    {
        v = V;
        l = new list<int>[v];
    }
    void addEdge(int x, int y, bool undir = true)
    {
        l[x].push_back(y);
        if (undir)
            l[y].push_back(x);
    }
    void bfs(int source)
    {

            bool* visited = new bool[v]{0};
            queue<int> q1;
            q1.push(source);
            visited[q1.front()] = true;


            while (!q1.empty())
            {
            //     int x = q1.front();
            //     cout << x << " ";
            //    visited[q1.front()] = true;
            //     q1.pop();

                for (auto nbr : l[q1.front()])
                    if (!visited[nbr])
                    {
                        q1.push(nbr);
                        visited[nbr] = true;
                    }
               cout << q1.front() << " ";
               q1.pop(); 

            }
        }
    
};

int main()
{
   Graphs g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.addEdge(3,2);
    // g.printe();

    g.bfs(1);

   
}