// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
     bool dfsHelper(int source , bool* visited ,int parent , vector<int> adj[])
   {
       visited[source] = 1;
        for(auto child : adj[source])
        {
           if(!visited[child])
           {
               if(dfsHelper(child, visited , source , adj))
                    return true;
           }
           else if(parent!= child)
               return true;
        }
        return false;
   }
    
    bool isCycle(int V, vector<int> adj[]) {
        bool* visited = new bool[V]{0};
      for(int i =0 ;i<V ; i++)
          if(!visited[i])
              if(dfsHelper(i,visited ,-1,  adj)) return true;
              
             
      return false;
    }

};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends