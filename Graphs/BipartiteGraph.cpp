// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfsHelper(int source ,int parent, int* visited , vector<int>adj[] , int color)
    {
        visited[source] = color;
        for(auto nbr : adj[source])
        {
            if(visited[nbr] == 0)
            {
                if(!dfsHelper(nbr ,source , visited , adj , 3-color))return false;
            }
            else if(nbr!= parent && visited[nbr] == color)
             return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	     int* visited = new int[V]{0};
      for(int i =0 ;i<V ; i++)
          if(!visited[i])
              if(!dfsHelper(i, -1 , visited ,  adj , 1)) return false;
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends