#include <iostream>
#include <list>
using namespace std;

class Graphs
{

    int V;
    list<int> *l;

public:
    Graphs(int v)
    {
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir = true)
    {

        l[i].push_back(j);
        if (undir)
            l[j].push_back(i);
    }

    void printe()
    {

        for (int i = 0; i < V; i++)
        {
            cout << i << "-->"
                 << " ";

            //    for(auto it = l[i].begin();it!=l[i].end();it++)
            //     cout << *it << "- ";

            // Or
            for (auto node : l[i])
                cout << node << " - ";
            cout << endl;
        }
    }
};

int main()
{

    Graphs g(6);

    g.addEdge(0, 5);
    g.addEdge(2, 4);
    g.addEdge(5, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    g.printe();

    return 0;
}
