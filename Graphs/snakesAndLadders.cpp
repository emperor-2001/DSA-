// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

class Graphs
{
    int v;
    list<int> *l;

  public:
    Graphs(int V)
    {
        v = V + 1;
        l = new list<int>[v];
    }
    void addEdge(int x , int y , bool undir = true)
    {
        l[x].push_back(y);
          if(undir)
             l[y].push_back(x);
    }
     int bfs_shortest_path(int source,  int dest = -1)
    {
        queue<int> q1;
        q1.push(source);
        bool *visited = new bool[v]{0};
        int *parent = new int[v]{0};
        int *dist = new int[v]{0};
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

        return dist[30];
       
    }

   
};
class Solution
{
public:
    int minThrow(int N, int arr[])
    {

        Graphs g(30);
        unordered_map<int,int> m1;
        for (int i = 0; i < 2 * N; i++)
        {
            // g.addEdge(arr[i], {arr[i + 1], 0});
            m1[arr[i]] = arr[i+1];
            i++;
        }
        for (int i = 1; i <= 30; i++)
        {
            int x = i + 1;
            while ((x <= i + 6) && (x <= 30))
            {
                
                if(m1.find(i) == m1.end())
                g.addEdge(i, x);

                else
                g.addEdge(i , m1[i]);


                x++;
            }
        }


        // g.printe();
        // g.bfs(1);
        // int dist[32];
        return g.bfs_shortest_path(1);
       
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[2 * N];
        for (int i = 0; i < 2 * N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.minThrow(N, arr) << "\n";
    }
    return 0;
} // } Driver Code Ends