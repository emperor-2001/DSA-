#include <bits/stdc++.h>
#include <list>
using namespace std;

class Graphs
{

    int V;
    list<int> *l;
    int *visited;

public:
    Graphs(int v)
    {

        V = v;
        l = new list<int>[V];
        visited = new int[v];
        memset(visited, -1, sizeof(*visited) * v);
    }

    void addEdge(int i, int j, bool undir = true)
    {

        l[i].push_back(j); // push_front can be better
        if (undir)
            l[j].push_back(i);
    }

    
    
    void bfs_shortest_path(int source, int dist[], int dest = -1)
    {
        queue<int> q1;
        q1.push(source);
        bool *visited = new bool[V]{0};
        int *parent = new int[V]{0};
        visited[source] = true;
        parent[source] = source;
        dist[source] = 0;

        while (!q1.empty())
        {
            int x = q1.front();
            list<int> l1 = l[x];
            q1.pop();
            for (auto it = l1.begin(); it != l1.end(); it++)
            {
                if (!visited[*it])
                {
                    parent[*it] = x;
                    dist[*it] = dist[x] + 1;
                    q1.push(*it);
                    visited[*it] = true;
                }
            }
        }
        if (dest != -1)
        {
            int temp = dest;
            while (temp != source)
            {
                cout << temp << " --> ";
                temp = parent[temp];
            }
            cout << source << endl;
        }
    }
};

int main()
{

    Graphs g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.printe();
    g.bfs(1);
    int arr[7];

    cout << endl;
    g.bfs_shortest_path(1, arr, 6);
    for (int i = 0; i < 7; i++)
        cout << "dis[" << i << "]" << arr[i] << " " << endl;
    ;
    cout << endl;

    return 0;
}
