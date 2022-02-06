// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << "=" << x << endl
 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   bool dfsHelper(int source , bool* visited ,bool* stale , vector<int> adj[])
   {
       visited[source] = 1;
        for(int i =0 ; i<adj[source].size() ; i++)
        {
           if(!visited[adj[source][i]])
           {
               if(dfsHelper(adj[source][i], visited , stale , adj))
                    return true;
           }
           else if(visited[adj[source][i]] && !stale[adj[source][i]])
           {
               deb(adj[source][i]);
               deb(source);
               return true;
           }
        }
        stale[source] = 1;
        return false;


   }
    
    bool isCyclic(int V, vector<int> adj[]) {
        bool* visited = new bool[V]{0};
        bool* stale = new bool[V]{0};
      for(int i =0 ;i<V ; i++)
          if(!visited[i])
              if(dfsHelper(i,visited ,stale,  adj)) return true;
              
             
      return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends