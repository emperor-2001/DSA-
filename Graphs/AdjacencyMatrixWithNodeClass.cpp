#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{

public:
    string city;
    list<string> nbrs;
    Node(string city)
    {
        this->city = city;
    };
};

class Graphs
{

    unordered_map<string, Node *> m;

public:
    Graphs(vector<string> v)
    {
        for (auto str : v)
            m[str] = new Node(str);
    }

    void addPath(string x, string y, bool undir = false)
    {
        m[x]->nbrs.push_back(y);
        if (undir)
            m[y]->nbrs.push_back(x);
    }

    void print()
    {
        for (auto pair : m)
        {

            Node *citi = pair.second;
            cout << citi->city << "--> ";

            for (auto nbr : citi->nbrs)
                cout << nbr << " ";

            cout << endl;
        }
    }
};

int main()
{
    vector<string> cities = {"Delhi", "Paris", "NewYork", "London"};
    Graphs g(cities);

    g.addPath("Delhi", "London");
    g.addPath("NewYork", "London");
    g.addPath("Delhi", "Paris");
    g.addPath("Paris", "NewYork");

    g.print();
}